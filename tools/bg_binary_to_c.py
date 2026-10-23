#!/usr/bin/env python3
"""
GoldenEye Background Geometry Binary to C Converter
Parses binary bg files and generates C source files with complete structure mapping
"""

import struct
import sys
import os
from typing import BinaryIO, List, Tuple, Optional
from dataclasses import dataclass

# N64 base address for bg files
N64_BASE_ADDRESS = 0x0F000000

@dataclass
class BGHeader:
    reserved: int
    room_data_table_offset: int
    portal_data_table_offset: int
    global_vis_commands_offset: int
    padding: int

@dataclass
class RoomDataEntry:
    point_table_offset: int
    pri_mapping_offset: int
    sec_mapping_offset: int
    x: float
    y: float
    z: float

@dataclass
class PortalDataEntry:
    portal_offset: int
    connected_room1: int
    connected_room2: int
    control_bytes: int

@dataclass
class Portal4Point:
    num_points: int
    padding: bytes
    points: List[Tuple[float, float, float]]

class BGBinaryParser:
    def __init__(self, binary_path: str, output_path: str = None):
        self.binary_path = binary_path
        # Swap the extension only: str.replace('.c', '.h') also hits a ".c"
        # anywhere in the directory path (e.g. /home/me/.config/ -> .honfig/).
        self.output_path = output_path or os.path.splitext(binary_path)[0] + '.c'
        self.header_path = os.path.splitext(self.output_path)[0] + '.h'
        self.binary_data = b''
        self.header = None
        self.room_entries = []
        self.portal_entries = []
        self.global_vis_commands = []
        self.portals = []
        self.unused_portals = []
        self.point_tables = {}
        self.pri_mappings = {}
        self.sec_mappings = {}
        # Extract base name without extension and without _all_p suffix if present
        base = os.path.splitext(os.path.basename(binary_path))[0]
        self.base_name = base.replace('_all_p', '') if base.endswith('_all_p') else base
        # Track structure offsets for proper ordering
        self.structure_offsets = []  # List of (offset, type, name, data)
        
    def load_binary(self):
        """Load binary file into memory"""
        with open(self.binary_path, 'rb') as f:
            self.binary_data = f.read()
    
    def to_file_offset(self, n64_addr: int) -> int:
        """Convert N64 address to file offset"""
        if n64_addr == 0:
            return 0
        return n64_addr - N64_BASE_ADDRESS
    
    def is_valid_address(self, n64_addr: int) -> bool:
        """Whether a word looks like a pointer into this bg file.

        Used to tell a table row from the data that follows it: a portal
        table can end where the next word is 0x04000000 -- float geometry,
        not an address.
        """
        return N64_BASE_ADDRESS <= n64_addr < N64_BASE_ADDRESS + len(self.binary_data)

    def read_u32(self, offset: int) -> int:
        """Read big-endian u32 at offset"""
        return struct.unpack('>I', self.binary_data[offset:offset+4])[0]
    
    def read_float(self, offset: int) -> float:
        """Read big-endian float at offset"""
        return struct.unpack('>f', self.binary_data[offset:offset+4])[0]
    
    def read_u8(self, offset: int) -> int:
        """Read u8 at offset"""
        return self.binary_data[offset]
    
    def read_u16(self, offset: int) -> int:
        """Read big-endian u16 at offset"""
        return struct.unpack('>H', self.binary_data[offset:offset+2])[0]
    
    def parse_header(self):
        """Parse bg_header structure at offset 0"""
        room_offset_raw = self.read_u32(4)
        portal_offset_raw = self.read_u32(8)
        global_offset_raw = self.read_u32(12)
        
        self.header = BGHeader(
            reserved=self.read_u32(0),
            room_data_table_offset=self.to_file_offset(room_offset_raw),
            portal_data_table_offset=self.to_file_offset(portal_offset_raw),
            global_vis_commands_offset=self.to_file_offset(global_offset_raw),
            padding=self.read_u32(16)
        )
        print(f"Header parsed:")
        print(f"  Room table: 0x{room_offset_raw:08X} -> file offset 0x{self.header.room_data_table_offset:08X}")
        print(f"  Portal table: 0x{portal_offset_raw:08X} -> file offset 0x{self.header.portal_data_table_offset:08X}")
        print(f"  Global vis: 0x{global_offset_raw:08X} -> file offset 0x{self.header.global_vis_commands_offset:08X}")
    
    def parse_room_data_table(self):
        """Parse room_data_table_entry array"""
        offset = self.header.room_data_table_offset
        entry_size = 24  # 3 pointers (12 bytes) + 3 floats (12 bytes)
        null_entry_count = 0
        first_entry = True
        
        while True:
            point_offset_raw = self.read_u32(offset)
            pri_offset_raw = self.read_u32(offset + 4)
            sec_offset_raw = self.read_u32(offset + 8)
            
            x = self.read_float(offset + 12)
            y = self.read_float(offset + 16)
            z = self.read_float(offset + 20)
            
            # Check for null entry - ALL fields must be zero (including pointers)
            is_null_entry = (point_offset_raw == 0 and pri_offset_raw == 0 and 
                           sec_offset_raw == 0 and x == 0.0 and y == 0.0 and z == 0.0)
            
            if is_null_entry:
                null_entry_count += 1
                self.room_entries.append(RoomDataEntry(0, 0, 0, 0.0, 0.0, 0.0))
                
                # Stop only on the second null entry (first is index 0, second is terminator)
                if null_entry_count >= 2:
                    break
                    
                offset += entry_size
                continue
            
            # Convert N64 addresses to file offsets
            point_offset = self.to_file_offset(point_offset_raw)
            pri_offset = self.to_file_offset(pri_offset_raw)
            sec_offset = self.to_file_offset(sec_offset_raw)
            
            entry = RoomDataEntry(point_offset, pri_offset, sec_offset, x, y, z)
            self.room_entries.append(entry)
            
            offset += entry_size
        
        print(f"Parsed {len(self.room_entries)} room entries (including {null_entry_count} null entries)")
    
    def parse_portal_data_table(self):
        """Parse portal_data_table_entry array"""
        offset = self.header.portal_data_table_offset
        entry_size = 8  # 1 pointer (4 bytes) + 2 u8 + 1 u16
        
        while True:
            portal_offset_raw = self.read_u32(offset)
            room1 = self.read_u8(offset + 4)
            room2 = self.read_u8(offset + 5)
            control = self.read_u16(offset + 6)
            
            # A null pointer is a terminator row, but NOT necessarily the last
            # row: Cradle's table is two null rows, and stopping at the first
            # emitted one 8-byte entry too few. Every pointer after it then sat
            # 8 bytes low, so the file was the right size, compiled, and was
            # wrong throughout. Consume null rows and keep going; the table
            # really ends where the pointer is neither null nor a plausible
            # in-range address -- Cradle's next word is 0x04000000, the start
            # of float geometry data.
            if portal_offset_raw == 0 and room1 == 0 and room2 == 0:
                self.portal_entries.append(PortalDataEntry(0, 0, 0, 0))
                offset += entry_size
                nxt = self.read_u32(offset)
                if nxt == 0 or self.is_valid_address(nxt):
                    continue
                break

            # Convert N64 address to file offset
            portal_offset = self.to_file_offset(portal_offset_raw)
            
            entry = PortalDataEntry(portal_offset, room1, room2, control)
            self.portal_entries.append(entry)
            
            offset += entry_size
        
        print(f"Parsed {len(self.portal_entries)} portal entries")
    
    def parse_global_visibility_commands(self):
        """Parse global visibility commands u32 array"""
        offset = self.header.global_vis_commands_offset
        
        while True:
            cmd = self.read_u32(offset)
            self.global_vis_commands.append(cmd)
            
            # Check for termination patterns:
            # Pattern 1: 0x00010000, 0x00000000
            # Pattern 2: 0x00000000, 0x00000000
            if cmd == 0x00000000 and len(self.global_vis_commands) >= 2:
                prev_cmd = self.global_vis_commands[-2]
                if prev_cmd == 0x00010000 or prev_cmd == 0x00000000:
                    break
            
            offset += 4
        
        print(f"Parsed {len(self.global_vis_commands)} visibility commands")
    
    def parse_portal_4_point(self, offset: int) -> Portal4Point:
        """Parse portal structure with variable number of points"""
        num_points = self.read_u8(offset)
        padding = self.binary_data[offset+1:offset+4]
        
        points = []
        point_offset = offset + 4
        # Read only the number of points specified, not always 4
        for i in range(num_points):
            x = self.read_float(point_offset)
            y = self.read_float(point_offset + 4)
            z = self.read_float(point_offset + 8)
            points.append((x, y, z))
            point_offset += 12
        
        return Portal4Point(num_points, padding, points)
    
    def parse_all_portals(self):
        """Parse all portal structures"""
        # Track unique portal offsets to avoid duplicates
        unique_portals = {}  # offset -> (first_idx, portal_data)
        
        for i, entry in enumerate(self.portal_entries):
            if entry.portal_offset != 0:
                if entry.portal_offset not in unique_portals:
                    # First time seeing this offset, parse it
                    portal = self.parse_portal_4_point(entry.portal_offset)
                    unique_portals[entry.portal_offset] = (i, portal)
                    self.portals.append((i, portal))
        
        # Check for unused portals between end of portal_data_table and first point_table
        portal_table_end = self.header.portal_data_table_offset + (len(self.portal_entries) * 8)
        
        # Find the first point table offset
        first_point_table_offset = min([e.point_table_offset for e in self.room_entries if e.point_table_offset > 0], default=len(self.binary_data))
        
        # Scan for unused portals in this range
        current_offset = portal_table_end
        unused_portals = []
        
        while current_offset < first_point_table_offset:
            # Check if this offset is already accounted for
            if current_offset not in unique_portals:
                # Try to parse a portal here
                try:
                    num_points = self.read_u8(current_offset)
                    # Valid portal has 3-8 points typically
                    if 3 <= num_points <= 8:
                        portal = self.parse_portal_4_point(current_offset)
                        # Add as unused portal with negative index
                        unused_idx = -(len(unused_portals) + 1)
                        unused_portals.append((unused_idx, current_offset, portal))
                        # Skip past this portal structure
                        current_offset += 4 + (num_points * 12)
                        continue
                except:
                    pass
            
            current_offset += 4
        
        if unused_portals:
            print(f"Found {len(unused_portals)} unused portal structures")
            self.unused_portals = unused_portals
        else:
            self.unused_portals = []
        
        print(f"Parsed {len(self.portals)} unique portal geometries from {len([e for e in self.portal_entries if e.portal_offset != 0])} portal entries")
    
    def parse_binary_data_array(self, offset: int, name: str) -> List[int]:
        """Parse u32 array with magic header"""
        if offset == 0:
            return None
        
        # Read magic header
        magic = self.read_u32(offset)
        
        # 0x00000000 is a valid empty array (no compression header needed)
        if magic == 0x00000000:
            return [0x00000000]
        
        # Check for valid compression magic header
        if magic & 0xFFFF0000 != 0x11720000:
            print(f"Warning: Invalid magic for {name}: 0x{magic:08X}")
            return None
        
        # Read until we hit another structure or end
        data = []
        current = offset
        max_read = 10000  # Safety limit
        
        while current < len(self.binary_data) and len(data) < max_read:
            value = self.read_u32(current)
            data.append(value)
            current += 4
            
            # Check if we've hit another known structure
            if current in [e.point_table_offset for e in self.room_entries if e.point_table_offset > 0]:
                break
            if current in [e.pri_mapping_offset for e in self.room_entries if e.pri_mapping_offset > 0]:
                break
            if current in [e.sec_mapping_offset for e in self.room_entries if e.sec_mapping_offset > 0]:
                break
        
        return data
    
    def parse_all_data_arrays(self):
        """Parse all point tables and mapping arrays"""
        # Collect all unique offsets
        offsets_to_parse = set()
        
        for i, entry in enumerate(self.room_entries):
            if entry.point_table_offset > 0:
                offsets_to_parse.add(('point', i, entry.point_table_offset))
            if entry.pri_mapping_offset > 0:
                offsets_to_parse.add(('pri', i, entry.pri_mapping_offset))
            # Only add sec_mapping if it's different from pri_mapping
            if entry.sec_mapping_offset > 0 and entry.sec_mapping_offset != entry.pri_mapping_offset:
                offsets_to_parse.add(('sec', i, entry.sec_mapping_offset))
        
        # Parse each unique offset
        for type_name, index, offset in sorted(offsets_to_parse, key=lambda x: x[2]):
            data = self.parse_binary_data_array(offset, f"{type_name}_{index}")
            
            if data:
                if type_name == 'point':
                    self.point_tables[index] = data
                elif type_name == 'pri':
                    self.pri_mappings[index] = data
                elif type_name == 'sec':
                    self.sec_mappings[index] = data
        
        print(f"Parsed {len(self.point_tables)} point tables")
        print(f"Parsed {len(self.pri_mappings)} pri mappings")
        print(f"Parsed {len(self.sec_mappings)} sec mappings")
    
    def format_u32_array(self, data: List[int], name: str, per_line: int = 8) -> str:
        """Format u32 array for C output"""
        if not data:
            return f"u32 {name}[] = {{\n   0x00000000,\n}};\n"
        
        lines = [f"u32 {name}[] = {{"]
        
        for i in range(0, len(data), per_line):
            chunk = data[i:i+per_line]
            hex_vals = ', '.join(f"0x{val:08X}" for val in chunk)
            lines.append(f"   {hex_vals},")
        
        lines.append("};\n")
        return '\n'.join(lines)
    
    def generate_c_file(self):
        """Generate complete C source file with structures in binary order"""
        output = []
        
        # Headers
        output.append(f'#include "bg_all_p.h"')
        output.append(f'#include "{self.base_name}_all_p.h"')
        output.append('')
        
        # Collect all structures with their file offsets
        structures = []
        
        # Header at offset 0
        structures.append((0, 'header', 'struct bg_header header = {0, &room_data_table, &portal_data_table, &global_visibility_commands, 0};'))
        
        # Room data table
        if self.header:
            room_lines = ['struct room_data_table_entry room_data_table[] = {']
            for i, entry in enumerate(self.room_entries):
                if entry.point_table_offset == 0 and entry.pri_mapping_offset == 0 and entry.sec_mapping_offset == 0:
                    # Completely null entry
                    room_lines.append('    {0, 0, 0, 0.000000, 0.000000, 0.000000},')
                else:
                    # Has at least one non-null pointer
                    pt = f"&point_table_binary_{i}" if entry.point_table_offset != 0 and i in self.point_tables else "0"
                    pri = f"&pri_mapping_binary_{i}" if entry.pri_mapping_offset != 0 and i in self.pri_mappings else "0"
                    
                    # Check if sec_mapping points to the same data as pri_mapping
                    if entry.sec_mapping_offset != 0:
                        if entry.sec_mapping_offset == entry.pri_mapping_offset:
                            # Secondary points to same data as primary
                            sec = f"&pri_mapping_binary_{i}" if i in self.pri_mappings else "0"
                        elif i in self.sec_mappings:
                            # Has its own secondary data
                            sec = f"&sec_mapping_binary_{i}"
                        else:
                            sec = "0"
                    else:
                        sec = "0"
                    
                    room_lines.append(f'    {{{pt}, {pri}, {sec}, {entry.x:.6f}, {entry.y:.6f}, {entry.z:.6f}}},')
            room_lines.append('};')
            structures.append((self.header.room_data_table_offset, 'room_table', '\n'.join(room_lines)))
        
        # Create mapping from offset to portal index for reuse
        offset_to_portal_idx = {}
        for idx, portal in self.portals:
            entry = self.portal_entries[idx]
            offset_to_portal_idx[entry.portal_offset] = idx
        
        # Portal data table - reference shared portals
        if self.header:
            portal_lines = ['struct portal_data_table_entry portal_data_table[] = {']
            for i, entry in enumerate(self.portal_entries):
                # Comma on every row but the last. The null row used to omit it
                # unconditionally, which was fine only while a table could hold
                # exactly one; Cradle has two and the pair would not compile.
                last = (i == len(self.portal_entries) - 1)
                if entry.portal_offset == 0:
                    portal_lines.append('    {0, 0, 0, 0}' + ('' if last else ','))
                else:
                    # Find which portal index to reference (the first one at this offset)
                    portal_idx = offset_to_portal_idx.get(entry.portal_offset, i)
                    portal_lines.append(f'    {{&portal_{portal_idx}, 0x{entry.connected_room1:02X}, 0x{entry.connected_room2:02X}, 0x{entry.control_bytes:04X}}},')
            portal_lines.append('};')
            structures.append((self.header.portal_data_table_offset, 'portal_table', '\n'.join(portal_lines)))
        
        # Global visibility commands
        if self.header:
            vis_lines = ['u32 global_visibility_commands[] ={']
            for i in range(0, len(self.global_vis_commands), 2):
                if i + 1 < len(self.global_vis_commands):
                    vis_lines.append(f'    0x{self.global_vis_commands[i]:08X}, 0x{self.global_vis_commands[i+1]:08X},')
                else:
                    vis_lines.append(f'    0x{self.global_vis_commands[i]:08X}')
            vis_lines.append('};')
            structures.append((self.header.global_vis_commands_offset, 'vis_commands', '\n'.join(vis_lines)))
        
        # Portal structures - only unique ones
        for idx, portal in self.portals:
            entry = self.portal_entries[idx]
            pts = portal.points
            num_pts = portal.num_points
            point_str = ', '.join([f'{pt[0]:.6f}, {pt[1]:.6f}, {pt[2]:.6f}' for pt in pts])
            struct_name = f'portal_{num_pts}_point'
            portal_str = f'struct {struct_name} portal_{idx} = {{{num_pts}, 0, 0, 0, {point_str}}};'
            structures.append((entry.portal_offset, f'portal_{idx}', portal_str))
        
        # Unused portal structures (not referenced in portal_data_table)
        for unused_idx, offset, portal in self.unused_portals:
            pts = portal.points
            num_pts = portal.num_points
            point_str = ', '.join([f'{pt[0]:.6f}, {pt[1]:.6f}, {pt[2]:.6f}' for pt in pts])
            struct_name = f'portal_{num_pts}_point'
            portal_str = f'// Unused portal\nstruct {struct_name} portal_unused_{abs(unused_idx)} = {{{num_pts}, 0, 0, 0, {point_str}}};'
            structures.append((offset, f'portal_unused_{abs(unused_idx)}', portal_str))
        
        # Point tables
        for idx in sorted(self.point_tables.keys()):
            entry = self.room_entries[idx]
            structures.append((entry.point_table_offset, f'point_{idx}', 
                             self.format_u32_array(self.point_tables[idx], f'point_table_binary_{idx}')))
        
        # Pri mappings
        for idx in sorted(self.pri_mappings.keys()):
            entry = self.room_entries[idx]
            structures.append((entry.pri_mapping_offset, f'pri_{idx}', 
                             self.format_u32_array(self.pri_mappings[idx], f'pri_mapping_binary_{idx}')))
        
        # Sec mappings
        for idx in sorted(self.sec_mappings.keys()):
            entry = self.room_entries[idx]
            structures.append((entry.sec_mapping_offset, f'sec_{idx}', 
                             self.format_u32_array(self.sec_mappings[idx], f'sec_mapping_binary_{idx}')))
        
        # Sort by offset
        structures.sort(key=lambda x: x[0])
        
        # Generate output in binary order
        for offset, name, content in structures:
            output.append(f'// Offset: 0x{offset:X}')
            output.append(content)
            output.append('')
        
        return '\n'.join(output)
        
    def generate_h_file(self):
        """Generate header file with extern declarations"""
        output = []
        
        guard = f"_{self.base_name.upper()}_ALL_P_H_"
        output.append(f"#ifndef {guard}")
        output.append(f"#define {guard}")
        output.append('')
        output.append('#include "bg_all_p.h"')
        output.append('')
        
        # Extern declarations for point tables
        for idx in sorted(self.point_tables.keys()):
            output.append(f'extern u32 point_table_binary_{idx}[];')
        output.append('')
        
        # Extern declarations for pri mappings
        for idx in sorted(self.pri_mappings.keys()):
            output.append(f'extern u32 pri_mapping_binary_{idx}[];')
        output.append('')
        
        # Extern declarations for sec mappings
        for idx in sorted(self.sec_mappings.keys()):
            output.append(f'extern u32 sec_mapping_binary_{idx}[];')
        output.append('')
        
        # Extern declarations for portals
        for idx, portal in self.portals:
            num_pts = portal.num_points
            struct_name = f'portal_{num_pts}_point'
            output.append(f'extern struct {struct_name} portal_{idx};')
        output.append('')
        
        output.append(f"#endif // {guard}")
        
        return '\n'.join(output)
    
    def parse(self):
        """Main parsing function"""
        print(f"Parsing {self.binary_path}...")
        self.load_binary()
        self.parse_header()
        self.parse_room_data_table()
        self.parse_portal_data_table()
        self.parse_global_visibility_commands()
        self.parse_all_portals()
        self.parse_all_data_arrays()
        print("Parsing complete!")
    
    def generate(self, force: bool = False):
        """Generate output files"""
        # Check if output files exist
        files_exist = []
        if os.path.exists(self.output_path):
            files_exist.append(self.output_path)
        if os.path.exists(self.header_path):
            files_exist.append(self.header_path)
        
        if files_exist and not force:
            print(f"Warning: The following files already exist:")
            for f in files_exist:
                print(f"  {f}")
            response = input("Overwrite? (y/N): ").strip().lower()
            if response != 'y':
                print("Aborted.")
                return
        
        print(f"Generating {self.output_path}...")
        c_content = self.generate_c_file()
        with open(self.output_path, 'w') as f:
            f.write(c_content)
        
        print(f"Generating {self.header_path}...")
        h_content = self.generate_h_file()
        with open(self.header_path, 'w') as f:
            f.write(h_content)
        
        print("Generation complete!")


def main():
    import argparse
    
    parser = argparse.ArgumentParser(
        description='Convert GoldenEye background geometry binary files to C source'
    )
    parser.add_argument('input', help='Input binary file (.bin)')
    parser.add_argument('output', nargs='?', help='Output C file (optional, defaults to input with .c extension)')
    parser.add_argument('--force', '-f', action='store_true', help='Force overwrite without prompting')
    
    args = parser.parse_args()
    
    input_file = args.input
    output_file = args.output
    
    # If no output specified, use input filename with .c extension
    if not output_file:
        output_file = input_file.replace('.bin', '.c')
    
    bg_parser = BGBinaryParser(input_file, output_file)
    bg_parser.parse()
    bg_parser.generate(force=args.force)


if __name__ == "__main__":
    main()