# globally accessible functions and data
# these will be accessible by C code and show up in the .map file

# need to be moved to proper spots in .s 

.global decompress.buildtable
.global decompress.inflate
.global decompress.type0
.global decompress.type1
.global decompress.type2
.global decompress.table
.global decompress.start
.global decompress.entry

