#ifndef _INDY_COMMANDS_H_
#define _INDY_COMMANDS_H_
#include <ultra64.h>

typedef enum INDYCMDTYPE {
    INDY_INIT=0,
    INDY_SIZE=1,
    INDY_END=2,
    INDY_RESCMD=3,
    INDY_RESCMDDATARCVD=4,
    INDY_SENDCHECKFILEEXISTS=5,
    INDY_RECVCHECKFILEEXISTS=6,
    INDY_SENDFILELOAD=7,
    INDY_LOGRECVD=8,
    INDY_SENDDUMP=9,
    INDY_APPCMDRECVD=10,
    INDY_SENDHOSTCMD=11,
    INDY_PROFILE_SEND=12,
    INDY_EXPORTFILE=13,
    INDY_PROFILE_RECV=14,
    INDY_RAMROMLOAD=15,
    INDY_FAULTACKHOST=16
} INDYCMDTYPE;

typedef struct indy_resource_entry_header {
    u32 resourceID;
    s32 type;
    s32 size;
    s32 readsize;
    s32 writesize;
} indy_resource_entry_header;

typedef struct indy_resource_entry_type0 {
    indy_resource_entry_header entry;
} indy_resource_entry_type0;

typedef struct indy_resource_entry_type1 {
    indy_resource_entry_header entry;
} indy_resource_entry_type1;

typedef struct indy_resource_entry_type2 {
    indy_resource_entry_header entry;
} indy_resource_entry_type2;

typedef struct indy_resource_entry_type3 {
    indy_resource_entry_header entry;
    u8 strbuffer[256];
} indy_resource_entry_type3;

typedef struct indy_resource_entry_type4 {
    struct indy_resource_entry_header entry;
    u32 data;
} indy_resource_entry_type4;

typedef struct indy_resource_entry_type5 {
    indy_resource_entry_header entry;
    u8 strbuffer[256];
} indy_resource_entry_type5;

struct indy_resource_entry_type6 {
    struct indy_resource_entry_header entry;
    u32 data1;
    u32 data2;
};

struct indy_resource_entry_type7 {
    struct indy_resource_entry_header entry;
    u8 strbuffer[256];
    u32 size;
};

struct indy_resource_entry_type8 {
    struct indy_resource_entry_header entry;
    u32 data1;
    u32 data2;
    u32 size;
};

typedef struct indy_resource_entry_type9 {
    indy_resource_entry_header entry;
    u8 strbuffer[256];
} indy_resource_entry_type9;

typedef struct indy_resource_entry_typeA {
    struct indy_resource_entry_header entry;
    u32 data;
} indy_resource_entry_typeA;

typedef struct indy_resource_entry_typeB {
    struct indy_resource_entry_header entry;
    u8 strbuffer[1024];
} indy_resource_entry_typeB;

typedef struct indy_resource_entry_typeC {
    struct indy_resource_entry_header entry;
    u32 data;
} indy_resource_entry_typeC;

typedef struct indy_resource_entry_typeD {
    struct indy_resource_entry_header entry;
    u8 strbuffer[256];
    u32 size;
    u8* hwaddress;
} indy_resource_entry_typeD;

typedef struct indy_resource_entry_typeE {
    struct indy_resource_entry_header entry;
    u32 data;
} indy_resource_entry_typeE;

typedef struct indy_resource_entry_typeF {
    struct indy_resource_entry_header entry;
    u8 strbuffer[256];
    u32 size;
    u8* hwaddress;
} indy_resource_entry_typeF;

struct indy_resource_entry_type10 {
    struct indy_resource_entry_header entry;
    u32 data1;
    u32 data2;
    u32 data3;
};



extern s32 indy_ready;

s32 indycmdSendCommand(struct indy_resource_entry_header *cmd,u32 size);

s32 indycmdSendInitPacket(void);
s32 indycmdSendHostCheckFileExists(char *strptr);
s32 indycmdSendLoadFile(u8 *filename,u32 size);
s32 indycmdSendDump(char *string, u32 size, struct indy_resource_entry_header *data);
s32 indycmdSendRamRomLoad(char *strptr,u32 ptarget,u32 filesize);
s32 indycmdSendHostExportFile(char *strptr,u8 *phwaddr,u32 size);
s32 indycmdSendHostCmdPacket(char *strptr);

s32 indycmdRecieveCommand(struct indy_resource_entry_header *resource,u32 size);

s32 indycmdAckHostCheckFileExists(u8 *response1,u8 *response2);
s32 indycmdReceiveFile(u8 *response1,u8 *response2,u32 childsize,u8 *child);
s32 indycmdAckSendDump(u8 *param_1);
s32 indycmdReceiveRamRom(u32 *param_1,u32 *param_2,u32 *param_3);
s32 indycmdAckHostExportFile(u8 *response);
s32 indycmdAckHostCmdPacket(u8 *response);


#endif
