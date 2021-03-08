#include "ultra64.h"
#include "game/image.h"
#include "assets/images/image_externs.h"

// bss
//8008C720
s32 ptr_texture_alloc_start;
//8008C724
s32 ptr_texture_alloc_end;
//8008C728
s32 ptr_next_available_space;
//8008C72C
s32 ptr_last_entry_facemapping;
//8008C730
s32 word_CODE_bss_8008C730[0x258];
//8008D090
s32 dword_CODE_bss_8008D090;
//8008D094
s32 dword_CODE_bss_8008D094;


// data
//D:80049170
u32 bytes = 0x6DDD0;
//D:80049174
u32 D_80049174 = 0;

//D:80049178 #1	#bytes in pixel data for image
s32 pixelbytecounts[] = 
{
    4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1
};
//D:800491AC #2	1=alphagrab.  Grabs 1 bit of alpha data for each pixel
s32 pixelalphas[] = 
{
    0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0
};
//D:800491E0 #3	#bits in 'samples', *2	-1=bitmask
s32 pixelsamplebits[] = 
{
    0x100, 0x20, 0x100, 0x20, 0x100, 0x10, 8, 0x100, 0x10, 0x100, 0x10, 0x100, 0x10
};
//D:80049214 #4	bitcount for pixel data
s32 pixelbitcount[] = 
{
     0x20, 0x10, 0x18, 0xF, 0x10, 8, 4, 8, 4, 0x10, 0x10, 0x10, 0x10, 
};
//D:80049248 #5	N64 image types (0=color, 1=YUV, 2=indexed, 3=IA, 4=I)
s32 n64imagetypes[] = 
{
    0, 0, 0, 0, 3, 3, 3, 4, 4, 2, 2, 2, 2
};
//D:8004927C #6	N64 pixel sizes (0=4bit, 1=8bit, 2=16bit, 3=32bit)
s32 n64pixelsizes[] = 
{
    3, 2, 3, 2, 2, 1, 0, 1, 0, 1, 0, 1, 0
};
//D:800492B0 #7	imageflip values for indexed types
s32 imgflipvalues[] = 
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x8000, 0x8000, 0xC000, 0xC000
};
//D:800492e4
s32 D_800492E4[] = 
{
    0, 0, 0, 0, 0, 0, 0
};

//D:80049300
//need way to calculate size at compile time from external data
struct image_entry image_entries[] = {
    {   0,    0,  _image1_size,    0,    0,    0,    0},
    {   0,    0,  _image2_size,    0,    0,    0,    0},
    {   0,    0,  _image3_size,    0,    0,    0,    0},
    {   0,    0,  _image4_size,    0,    0,    0,    0},
    {   0,    0,  _image5_size,    0,    0,    0,    0},
    {   0,    0,  _image6_size,    0,    0,    0,    0},
    {   0,    0,  _image7_size,    0,    0,    0,    0},
    {   0,    0,  _image8_size,    0,    0,    0,    0},
    {   0,    0,  _image9_size,    0,    0,    0,    0},
    {0x11,    0,  _image10_size,    0,    0,    0,    0},
    {0x11,    0,  _image11_size,    0,    0,    0,    0},
    {   0,    0,  _image12_size,    0,    0,    0,    0},
    {   0,    0,  _image13_size,    0,    0,    0,    0},
    {   0,    0,  _image14_size,    0,    0,    0,    0},
    {   0,    0,  _image15_size,    0,    0,    0,    0},
    {   0,    0,  _image16_size,    0,    0,    0,    0},
    {   0,    0,  _image17_size,    0,    0,    0,    0},
    {   0,    0,  _image18_size,    0,    0,    0,    0},
    {   0,    0,  _image19_size,    0,    0,    0,    0},
    {   0,    0,  _image20_size,    0,    0,    0,    0},
    {0x77,    0,  _image21_size,    0,    0,    0,    0},
    {   0,    0,  _image22_size, 0x38, 0xD2,    0,    0},
    {0x77,    0,  _image23_size, 0x38, 0xD2,    0,    0},
    {   0,    0,  _image24_size,    0,    0,    0,    0},
    {   0,    0,  _image25_size,    0,    0,    0,    0},
    {   0,    0,  _image26_size,    0,    0,    0,    0},
    {   0,    0,  _image27_size,    0,    0,    0,    0},
    {   0,    0,  _image28_size,    0,    0,    0,    0},
    {   0,    0,  _image29_size,    0,    0,    0,    0},
    {0xAA,    0,  _image30_size,    0,    0,    0,    0},
    {0xAA,    0,  _image31_size,    0,    0,    0,    0},
    {0xAA,    0,  _image32_size,    0,    0,    0,    0},
    {0xAA,    0,  _image33_size,    0,    0,    0,    0},
    {0x22,    0,  _image34_size,    0,    0,    0,    0},
    {0x22,    0,  _image35_size,    0,    0,    0,    0},
    {0x22,    0,  _image36_size,    0,    0,    0,    0},
    {0x22,    0,  _image37_size,    0,    0,    0,    0},
    {   0,    0,  _image38_size,    0,    0,    0,    0},
    {   0,    0,  _image39_size,    0,    0,    0,    0},
    {   0,    0,  _image40_size,    0,    0,    0,    0},
    {   0,    0,  _image41_size,    0,    0,    0,    0},
    {   0,    0,  _image42_size,    0,    0,    0,    0},
    {   0,    0,  _image43_size,    0,    0,    0,    0},
    {0xAA,    0,  _image44_size,    0,    0,    0,    0},
    {   0,    0,  _image45_size,    0,    0,    0,    0},
    {0xAA,    0,  _image46_size,    0,    0,    0,    0},
    {   0,    0,  _image47_size,    0,    0,    0,    0},
    {   0,    0,  _image48_size,    0,    0,    0,    0},
    {   0,    0,  _image49_size,    0,    0,    0,    0},
    {   0,    0,  _image50_size,    0,    0,    0,    0},
    {0x33,    0,  _image51_size,    0,    0,    0,    0},
    {   0,    0,  _image52_size,    0,    0,    0,    0},
    {   0,    0,  _image53_size,    0,    0,    0,    0},
    {   0,    0,  _image54_size,    0,    0,    0,    0},
    {   0,    0,  _image55_size,    0,    0,    0,    0},
    {   0,    0,  _image56_size,    0,    0,    0,    0},
    {   0,    0,  _image57_size,    0,    0,    0,    0},
    {   0,    0,  _image58_size,    0,    0,    0,    0},
    {   0,    0,  _image59_size,    0,    0,    0,    0},
    {   0,    0,  _image60_size,    0,    0,    0,    0},
    {   0,    0,  _image61_size,    0,    0,    0,    0},
    {   0,    0,  _image62_size,    0,    0,    0,    0},
    {   0,    0,  _image63_size,    0,    0,    0,    0},
    {   0,    0,  _image64_size,    0,    0,    0,    0},
    {   0,    0,  _image65_size,    0,    0,    0,    0},
    {   0,    0,  _image66_size,    0,    0,    0,    0},
    {   0,    0,  _image67_size,    0,    0,    0,    0},
    {   0,    0,  _image68_size,    0,    0,    0,    0},
    {   0,    0,  _image69_size,    0,    0,    0,    0},
    {   0,    0,  _image70_size,    0,    0,    0,    0},
    {   0,    0,  _image71_size,    0,    0,    0,    0},
    {   0,    0,  _image72_size,    0,    0,    0,    0},
    {   0,    0,  _image73_size,    0,    0,    0,    0},
    {   0,    0,  _image74_size,    0,    0,    0,    0},
    {   0,    0,  _image75_size,    0,    0,    0,    0},
    {0xAA,    0,  _image76_size,    0,    0,    0,    0},
    {0xAA,    0,  _image77_size,    0,    0,    0,    0},
    {0xAA,    0,  _image78_size,    0,    0,    0,    0},
    {0x22,    0,  _image79_size,    0,    0,    0,    0},
    {0x22,    0,  _image80_size,    0,    0,    0,    0},
    {0x33,    0,  _image81_size,    0,    0,    0,    0},
    {0x33,    0,  _image82_size,    0,    0,    0,    0},
    {0x33,    0,  _image83_size,    0,    0,    0,    0},
    {0x33,    0,  _image84_size,    0,    0,    0,    0},
    {0x33,    0,  _image85_size,    0,    0,    0,    0},
    {   0,    0,  _image86_size,    0,    0,    0,    0},
    {   0,    0,  _image87_size,    0,    0,    0,    0},
    {   0,    0,  _image88_size,    0,    0,    0,    0},
    {0x11,    0,  _image89_size,    0,    0,    0,    0},
    {0x11,    0,  _image90_size,    0,    0,    0,    0},
    {0x11,    0,  _image91_size,    0,    0,    0,    0},
    {0x11,    0,  _image92_size,    0,    0,    0,    0},
    {0x11,    0,  _image93_size,    0,    0,    0,    0},
    {0x11,    0,  _image94_size,    0,    0,    0,    0},
    {0x11,    0,  _image95_size,    0,    0,    0,    0},
    {0x11,    0,  _image96_size,    0,    0,    0,    0},
    {0x11,    0,  _image97_size,    0,    0,    0,    0},
    {0x11,    0,  _image98_size,    0,    0,    0,    0},
    {0x11,    0,  _image99_size,    0,    0,    0,    0},
    {0x11,    0,  _image100_size,    0,    0,    0,    0},
    {0x11,    0,  _image101_size,    0,    0,    0,    0},
    {0x11,    0,  _image102_size,    0,    0,    0,    0},
    {0x11,    0,  _image103_size,    0,    0,    0,    0},
    {0x11,    0,  _image104_size,    0,    0,    0,    0},
    {0x11,    0,  _image105_size,    0,    0,    0,    0},
    {0x11,    0,  _image106_size,    0,    0,    0,    0},
    {0x11,    0,  _image107_size,    0,    0,    0,    0},
    {0x11,    0,  _image108_size,    0,    0,    0,    0},
    {0x11,    0,  _image109_size,    0,    0,    0,    0},
    {0x11,    0,  _image110_size,    0,    0,    0,    0},
    {0x11,    0,  _image111_size,    0,    0,    0,    0},
    {0x11,    0,  _image112_size,    0,    0,    0,    0},
    {0x11,    0,  _image113_size,    0,    0,    0,    0},
    {0x11,    0,  _image114_size,    0,    0,    0,    0},
    {0x11,    0,  _image115_size,    0,    0,    0,    0},
    {0x11,    0,  _image116_size,    0,    0,    0,    0},
    {0x11,    0,  _image117_size,    0,    0,    0,    0},
    {0x11,    0,  _image118_size,    0,    0,    0,    0},
    {0x11,    0,  _image119_size,    0,    0,    0,    0},
    {0x11,    0,  _image120_size,    0,    0,    0,    0},
    {0x11,    0,  _image121_size,    0,    0,    0,    0},
    {0x11,    0,  _image122_size,    0,    0,    0,    0},
    {0x11,    0,  _image123_size,    0,    0,    0,    0},
    {0x11,    0,  _image124_size,    0,    0,    0,    0},
    {0x11,    0,  _image125_size,    0,    0,    0,    0},
    {0x11,    0,  _image126_size,    0,    0,    0,    0},
    {0x11,    0,  _image127_size,    0,    0,    0,    0},
    {0x11,    0,  _image128_size,    0,    0,    0,    0},
    {0x11,    0,  _image129_size,    0,    0,    0,    0},
    {0x11,    0,  _image130_size,    0,    0,    0,    0},
    {0x11,    0,  _image131_size,    0,    0,    0,    0},
    {0x11,    0,  _image132_size,    0,    0,    0,    0},
    {0x11,    0,  _image133_size,    0,    0,    0,    0},
    {0x11,    0,  _image134_size,    0,    0,    0,    0},
    {0x11,    0,  _image135_size,    0,    0,    0,    0},
    {0x11,    0,  _image136_size,    0,    0,    0,    0},
    {0x11,    0,  _image137_size,    0,    0,    0,    0},
    {0x11,    0,  _image138_size,    0,    0,    0,    0},
    {0x11,    0,  _image139_size,    0,    0,    0,    0},
    {0x11,    0,  _image140_size,    0,    0,    0,    0},
    {0x11,    0,  _image141_size,    0,    0,    0,    0},
    {0x11,    0,  _image142_size,    0,    0,    0,    0},
    {0x11,    0,  _image143_size,    0,    0,    0,    0},
    {0x11,    0,  _image144_size,    0,    0,    0,    0},
    {0x11,    0,  _image145_size,    0,    0,    0,    0},
    {0x11,    0,  _image146_size,    0,    0,    0,    0},
    {0x11,    0,  _image147_size,    0,    0,    0,    0},
    {   0,    0,  _image148_size,    0,    0,    0,    0},
    {0xAA,    0,  _image149_size,    0,    0,    0,    0},
    {0xAA,    0,  _image150_size,    0,    0,    0,    0},
    {0xAA,    0,  _image151_size,    0,    0,    0,    0},
    {0xAA,    0,  _image152_size,    0,    0,    0,    0},
    {0xAA,    0,  _image153_size,    0,    0,    0,    0},
    {0xAA,    0,  _image154_size,    0,    0,    0,    0},
    {0xAA,    0,  _image155_size,    0,    0,    0,    0},
    {0xAA,    0,  _image156_size,    0,    0,    0,    0},
    {   0,    0,  _image157_size,    0,    0,    0,    0},
    {   0,    0,  _image158_size,    0,    0,    0,    0},
    {   0,    0,  _image159_size,    0,    0,    0,    0},
    {   0,    0,  _image160_size,    0,    0,    0,    0},
    {0x33,    0,  _image161_size,    0,    0,    0,    0},
    {0x33,    0,  _image162_size,    0,    0,    0,    0},
    {0x33,    0,  _image163_size,    0,    0,    0,    0},
    {0x33,    0,  _image164_size,    0,    0,    0,    0},
    {0x33,    0,  _image165_size,    0,    0,    0,    0},
    {0x33,    0,  _image166_size,    0,    0,    0,    0},
    {0x33,    0,  _image167_size,    0,    0,    0,    0},
    {0x33,    0,  _image168_size,    0,    0,    0,    0},
    {   0,    0,  _image169_size,    0,    0,    0,    0},
    {0x33,    0,  _image170_size,    0,    0,    0,    0},
    {   0,    0,  _image171_size,    0,    0,    0,    0},
    {   0,    0,  _image172_size,    0,    0,    0,    0},
    {   0,    0,  _image173_size,    0,    0,    0,    0},
    {   0,    0,  _image174_size,    0,    0,    0,    0},
    {   0,    0,  _image175_size,    0,    0,    0,    0},
    {   0,    0,  _image176_size,    0,    0,    0,    0},
    {   0,    0,  _image177_size,    0,    0,    0,    0},
    {0xAA,    0,  _image178_size,    0,    0,    0,    0},
    {0xAA,    0,  _image179_size,    0,    0,    0,    0},
    {0xAA,    0,  _image180_size,    0,    0,    0,    0},
    {0x11,    0,  _image181_size,    0,    0,    0,    0},
    {0x11,    0,  _image182_size,    0,    0,    0,    0},
    {   0,    0,  _image183_size,    0,    0,    0,    0},
    {0x11,    0,  _image184_size,    0,    0,    0,    0},
    {   0,    0,  _image185_size,    0,    0,    0,    0},
    {0x22,    0,  _image186_size,    0,    0,    0,    0},
    {0x77,    0,  _image187_size,    0,    0,    0,    0},
    {0x77,    0,  _image188_size,    0,    0,    0,    0},
    {0x22,    0,  _image189_size,    0,    0,    0,    0},
    {   0,    0,  _image190_size,    0,    0,    0,    0},
    {   0,    0,  _image191_size,    0,    0,    0,    0},
    {   0,    0,  _image192_size,    0,    0,    0,    0},
    {   0,    0,  _image193_size,    0,    0,    0,    0},
    {   0,    0,  _image194_size,    0,    0,    0,    0},
    {0x33,    0,  _image195_size,    0,    0,    0,    0},
    {0x11,    0,  _image196_size,    0,    0,    0,    0},
    {0x77,    0,  _image197_size,    0,    0,    0,    0},
    {0x33,    0,  _image198_size,    0,    0,    0,    0},
    {   0,    0,  _image199_size,    0,    0,    0,    0},
    {0x33,    0,  _image200_size,    0,    0,    0,    0},
    {   0,    0,  _image201_size,    0,    0,    0,    0},
    {0x44,    0,  _image202_size,    0,    0,    0,    0},
    {0x44,    0,  _image203_size,    0,    0,    0,    0},
    {0x44,    0,  _image204_size,    0,    0,    0,    0},
    {0x44,    0,  _image205_size,    0,    0,    0,    0},
    {0x44,    0,  _image206_size,    0,    0,    0,    0},
    {   0,    0,  _image207_size,    0,    0,    0,    0},
    {   0,    0,  _image208_size,    0,    0,    0,    0},
    {   0,    0,  _image209_size,    0,    0,    0,    0},
    {   0,    0,  _image210_size,    0,    0,    0,    0},
    {   0,    0,  _image211_size,    0,    0,    0,    0},
    {   0,    0,  _image212_size,    0,    0,    0,    0},
    {   0,    0,  _image213_size,    0,    0,    0,    0},
    {   0,    0,  _image214_size,    0,    0,    0,    0},
    {0xAA,    0,  _image215_size,    0,    0,    0,    0},
    {   0,    0,  _image216_size,    0,    0,    0,    0},
    {   0,    0,  _image217_size,    0,    0,    0,    0},
    {   0,    0,  _image218_size,    0,    0,    0,    0},
    {   0,    0,  _image219_size,    0,    0,    0,    0},
    {0x22,    0,  _image220_size,    0,    0,    0,    0},
    {0x22,    0,  _image221_size,    0,    0,    0,    0},
    {0x22,    0,  _image222_size,    0,    0,    0,    0},
    {0x22,    0,  _image223_size,    0,    0,    0,    0},
    {0x22,    0,  _image224_size,    0,    0,    0,    0},
    {0x22,    0,  _image225_size,    0,    0,    0,    0},
    {0x22,    0,  _image226_size,    0,    0,    0,    0},
    {   0,    0,  _image227_size,    0,    0,    0,    0},
    {   0,    0,  _image228_size,    0,    0,    0,    0},
    {   0,    0,  _image229_size,    0,    0,    0,    0},
    {0xAA,    0,  _image230_size,    0,    0,    0,    0},
    {   0,    0,  _image231_size,    0,    0,    0,    0},
    {   0,    0,  _image232_size,    0,    0,    0,    0},
    {   0,    0,  _image233_size,    0,    0,    0,    0},
    {   0,    0,  _image234_size,    0,    0,    0,    0},
    {   0,    0,  _image235_size,    0,    0,    0,    0},
    {0xAA,    0,  _image236_size,    0,    0,    0,    0},
    {0xAA,    0,  _image237_size,    0,    0,    0,    0},
    {0xAA,    0,  _image238_size,    0,    0,    0,    0},
    {0xAA,    0,  _image239_size,    0,    0,    0,    0},
    {0xAA,    0,  _image240_size,    0,    0,    0,    0},
    {0xAA,    0,  _image241_size,    0,    0,    0,    0},
    {0xAA,    0,  _image242_size,    0,    0,    0,    0},
    {0x77,    0,  _image243_size,    0,    0,    0,    0},
    {0x77,    0,  _image244_size,    0,    0,    0,    0},
    {0x77,    0,  _image245_size,    0,    0,    0,    0},
    {   0,    0,  _image246_size,    0,    0,    0,    0},
    {   0,    0,  _image247_size,    0,    0,    0,    0},
    {0x33,    0,  _image248_size,    0,    0,    0,    0},
    {0x33,    0,  _image249_size,    0,    0,    0,    0},
    {0x33,    0,  _image250_size,    0,    0,    0,    0},
    {0x33,    0,  _image251_size,    0,    0,    0,    0},
    {0x11,    0,  _image252_size,    0,    0,    0,    0},
    {0x44,    0,  _image253_size,    0,    0,    0,    0},
    {0x44,    0,  _image254_size,    0,    0,    0,    0},
    {0x44,    0,  _image255_size,    0,    0,    0,    0},
    {0x44,    0,  _image256_size,    0,    0,    0,    0},
    {0x44,    0,  _image257_size,    0,    0,    0,    0},
    {0x11,    0,  _image258_size,    0,    0,    0,    0},
    {0x11,    0,  _image259_size,    0,    0,    0,    0},
    {0x11,    0,  _image260_size,    0,    0,    0,    0},
    {0xAA,    0,  _image261_size,    0,    0,    0,    0},
    {0xAA,    0,  _image262_size,    0,    0,    0,    0},
    {0xAA,    0,  _image263_size,    0,    0,    0,    0},
    {0xAA,    0,  _image264_size,    0,    0,    0,    0},
    {0x77,    0,  _image265_size,    0,    0,    0,    0},
    {0xAA,    0,  _image266_size,    0,    0,    0,    0},
    {   0,    0,  _image267_size,    0,    0,    0,    0},
    {   0,    0,  _image268_size,    0,    0,    0,    0},
    {   0,    0,  _image269_size,    0,    0,    0,    0},
    {   0,    0,  _image270_size,    0,    0,    0,    0},
    {   0,    0,  _image271_size,    0,    0,    0,    0},
    {   0,    0,  _image272_size,    0,    0,    0,    0},
    {   0,    0,  _image273_size,    0,    0,    0,    0},
    {   0,    0,  _image274_size,    0,    0,    0,    0},
    {   0,    0,  _image275_size,    0,    0,    0,    0},
    {   0,    0,  _image276_size,    0,    0,    0,    0},
    {   0,    0,  _image277_size,    0,    0,    0,    0},
    {   0,    0,  _image278_size,    0,    0,    0,    0},
    {   0,    0,  _image279_size,    0,    0,    0,    0},
    {0x11,    0,  _image280_size,    0,    0,    0,    0},
    {0x11,    0,  _image281_size,    0,    0,    0,    0},
    {0x11,    0,  _image282_size,    0,    0,    0,    0},
    {0x11,    0,  _image283_size,    0,    0,    0,    0},
    {0x11,    0,  _image284_size,    0,    0,    0,    0},
    {0x11,    0,  _image285_size,    0,    0,    0,    0},
    {0x11,    0,  _image286_size,    0,    0,    0,    0},
    {0x11,    0,  _image287_size,    0,    0,    0,    0},
    {0x11,    0,  _image288_size,    0,    0,    0,    0},
    {0x11,    0,  _image289_size,    0,    0,    0,    0},
    {0x11,    0,  _image290_size,    0,    0,    0,    0},
    {0x11,    0,  _image291_size,    0,    0,    0,    0},
    {0x11,    0,  _image292_size,    0,    0,    0,    0},
    {   0,    0,  _image293_size,    0,    0,    0,    0},
    {0x11,    0,  _image294_size,    0,    0,    0,    0},
    {0x11,    0,  _image295_size,    0,    0,    0,    0},
    {0x11,    0,  _image296_size,    0,    0,    0,    0},
    {0x11,    0,  _image297_size,    0,    0,    0,    0},
    {0x11,    0,  _image298_size,    0,    0,    0,    0},
    {0x11,    0,  _image299_size,    0,    0,    0,    0},
    {0x11,    0,  _image300_size,    0,    0,    0,    0},
    {0x11,    0,  _image301_size,    0,    0,    0,    0},
    {0x11,    0,  _image302_size,    0,    0,    0,    0},
    {0x11,    0,  _image303_size,    0,    0,    0,    0},
    {0x11,    0,  _image304_size,    0,    0,    0,    0},
    {0x77,    0,  _image305_size,    0,    0,    0,    0},
    {0x11,    0,  _image306_size,    0,    0,    0,    0},
    {0x11,    0,  _image307_size,    0,    0,    0,    0},
    {0x11,    0,  _image308_size,    0,    0,    0,    0},
    {0x11,    0,  _image309_size,    0,    0,    0,    0},
    {0x11,    0,  _image310_size,    0,    0,    0,    0},
    {0x11,    0,  _image311_size,    0,    0,    0,    0},
    {0x11,    0,  _image312_size,    0,    0,    0,    0},
    {0x11,    0,  _image313_size,    0,    0,    0,    0},
    {0x11,    0,  _image314_size,    0,    0,    0,    0},
    {0x11,    0,  _image315_size,    0,    0,    0,    0},
    {0x11,    0,  _image316_size,    0,    0,    0,    0},
    {0x11,    0,  _image317_size,    0,    0,    0,    0},
    {0x11,    0,  _image318_size,    0,    0,    0,    0},
    {0x11,    0,  _image319_size,    0,    0,    0,    0},
    {0x11,    0,  _image320_size,    0,    0,    0,    0},
    {0x11,    0,  _image321_size,    0,    0,    0,    0},
    {   0,    0,  _image322_size,    0,    0,    0,    0},
    {   0,    0,  _image323_size,    0,    0,    0,    0},
    {   0,    0,  _image324_size,    0,    0,    0,    0},
    {   0,    0,  _image325_size,    0,    0,    0,    0},
    {   0,    0,  _image326_size,    0,    0,    0,    0},
    {   0,    0,  _image327_size,    0,    0,    0,    0},
    {   0,    0,  _image328_size,    0,    0,    0,    0},
    {   0,    0,  _image329_size,    0,    0,    0,    0},
    {0xAA,    0,  _image330_size,    0,    0,    0,    0},
    {0xAA,    0,  _image331_size,    0,    0,    0,    0},
    {0xAA,    0,  _image332_size,    0,    0,    0,    0},
    {0xAA,    0,  _image333_size,    0,    0,    0,    0},
    {0xAA,    0,  _image334_size,    0,    0,    0,    0},
    {0xAA,    0,  _image335_size,    0,    0,    0,    0},
    {0xAA,    0,  _image336_size,    0,    0,    0,    0},
    {0xAA,    0,  _image337_size,    0,    0,    0,    0},
    {0xAA,    0,  _image338_size,    0,    0,    0,    0},
    {0xAA,    0,  _image339_size,    0,    0,    0,    0},
    {0xAA,    0,  _image340_size,    0,    0,    0,    0},
    {0xAA,    0,  _image341_size,    0,    0,    0,    0},
    {0xAA,    0,  _image342_size,    0,    0,    0,    0},
    {0xAA,    0,  _image343_size,    0,    0,    0,    0},
    {0xAA,    0,  _image344_size,    0,    0,    0,    0},
    {0xAA,    0,  _image345_size,    0,    0,    0,    0},
    {0xAA,    0,  _image346_size,    0,    0,    0,    0},
    {0xAA,    0,  _image347_size,    0,    0,    0,    0},
    {0xAA,    0,  _image348_size,    0,    0,    0,    0},
    {0xAA,    0,  _image349_size,    0,    0,    0,    0},
    {0xAA,    0,  _image350_size,    0,    0,    0,    0},
    {0xAA,    0,  _image351_size,    0,    0,    0,    0},
    {0xAA,    0,  _image352_size,    0,    0,    0,    0},
    {0xAA,    0,  _image353_size,    0,    0,    0,    0},
    {0xAA,    0,  _image354_size,    0,    0,    0,    0},
    {0xAA,    0,  _image355_size,    0,    0,    0,    0},
    {0xAA,    0,  _image356_size,    0,    0,    0,    0},
    {0xAA,    0,  _image357_size,    0,    0,    0,    0},
    {0xAA,    0,  _image358_size,    0,    0,    0,    0},
    {0xAA,    0,  _image359_size,    0,    0,    0,    0},
    {0xAA,    0,  _image360_size,    0,    0,    0,    0},
    {0xAA,    0,  _image361_size,    0,    0,    0,    0},
    {0xAA,    0,  _image362_size,    0,    0,    0,    0},
    {0xAA,    0,  _image363_size,    0,    0,    0,    0},
    {0xAA,    0,  _image364_size,    0,    0,    0,    0},
    {0xAA,    0,  _image365_size,    0,    0,    0,    0},
    {0xAA,    0,  _image366_size,    0,    0,    0,    0},
    {0xAA,    0,  _image367_size,    0,    0,    0,    0},
    {0xAA,    0,  _image368_size,    0,    0,    0,    0},
    {0xAA,    0,  _image369_size,    0,    0,    0,    0},
    {   0,    0,  _image370_size,    0,    0,    0,    0},
    {   0,    0,  _image371_size,    0,    0,    0,    0},
    {0xAA,    0,  _image372_size,    0,    0,    0,    0},
    {0xAA,    0,  _image373_size,    0,    0,    0,    0},
    {0xAA,    0,  _image374_size,    0,    0,    0,    0},
    {0xAA,    0,  _image375_size,    0,    0,    0,    0},
    {0xAA,    0,  _image376_size,    0,    0,    0,    0},
    {0xAA,    0,  _image377_size,    0,    0,    0,    0},
    {0xAA,    0,  _image378_size,    0,    0,    0,    0},
    {0xAA,    0,  _image379_size,    0,    0,    0,    0},
    {0xAA,    0,  _image380_size,    0,    0,    0,    0},
    {0xAA,    0,  _image381_size,    0,    0,    0,    0},
    {0xAA,    0,  _image382_size,    0,    0,    0,    0},
    {0x33,    0,  _image383_size,    0,    0,    0,    0},
    {0x33,    0,  _image384_size,    0,    0,    0,    0},
    {0x33,    0,  _image385_size,    0,    0,    0,    0},
    {0x33,    0,  _image386_size,    0,    0,    0,    0},
    {   0,    0,  _image387_size,    0,    0,    0,    0},
    {   0,    0,  _image388_size,    0,    0,    0,    0},
    {   0,    0,  _image389_size,    0,    0,    0,    0},
    {   0,    0,  _image390_size,    0,    0,    0,    0},
    {   0,    0,  _image391_size,    0,    0,    0,    0},
    {   0,    0,  _image392_size,    0,    0,    0,    0},
    {   0,    0,  _image393_size,    0,    0,    0,    0},
    {   0,    0,  _image394_size,    0,    0,    0,    0},
    {0x33,    0,  _image395_size,    0,    0,    0,    0},
    {0x22,    0,  _image396_size,    0,    0,    0,    0},
    {0x22,    0,  _image397_size,    0,    0,    0,    0},
    {0x22,    0,  _image398_size,    0,    0,    0,    0},
    {0x22,    0,  _image399_size,    0,    0,    0,    0},
    {0x33,    0,  _image400_size,    0,    0,    0,    0},
    {0x33,    0,  _image401_size,    0,    0,    0,    0},
    {0x33,    0,  _image402_size,    0,    0,    0,    0},
    {0x11,    0,  _image403_size,    0,    0,    0,    0},
    {0x11,    0,  _image404_size,    0,    0,    0,    0},
    {0x11,    0,  _image405_size,    0,    0,    0,    0},
    {0x77,    0,  _image406_size,    0,    0,    0,    0},
    {0x11,    0,  _image407_size,    0,    0,    0,    0},
    {0x11,    0,  _image408_size,    0,    0,    0,    0},
    {0x11,    0,  _image409_size,    0,    0,    0,    0},
    {0x11,    0,  _image410_size,    0,    0,    0,    0},
    {0x11,    0,  _image411_size,    0,    0,    0,    0},
    {   0,    0,  _image412_size,    0,    0,    0,    0},
    {   0,    0,  _image413_size,    0,    0,    0,    0},
    {   0,    0,  _image414_size,    0,    0,    0,    0},
    {   0,    0,  _image415_size,    0,    0,    0,    0},
    {   0,    0,  _image416_size,    0,    0,    0,    0},
    {   0,    0,  _image417_size,    0,    0,    0,    0},
    {   0,    0,  _image418_size,    0,    0,    0,    0},
    {   0,    0,  _image419_size,    0,    0,    0,    0},
    {   0,    0,  _image420_size,    0,    0,    0,    0},
    {   0,    0,  _image421_size,    0,    0,    0,    0},
    {   0,    0,  _image422_size,    0,    0,    0,    0},
    {   0,    0,  _image423_size,    0,    0,    0,    0},
    {   0,    0,  _image424_size,    0,    0,    0,    0},
    {   0,    0,  _image425_size,    0,    0,    0,    0},
    {   0,    0,  _image426_size,    0,    0,    0,    0},
    {0xAA,    0,  _image427_size,    0,    0,    0,    0},
    {0xAA,    0,  _image428_size,    0,    0,    0,    0},
    {0x44,    0,  _image429_size,    0,    0,    0,    0},
    {0xAA,    0,  _image430_size,    0,    0,    0,    0},
    {0x33,    0,  _image431_size,    0,    0,    0,    0},
    {   0,    0,  _image432_size,    0,    0,    0,    0},
    {0x11,    0,  _image433_size,    0,    0,    0,    0},
    {0x11,    0,  _image434_size,    0,    0,    0,    0},
    {0x77,    0,  _image435_size,    0,    0,    0,    0},
    {0x11,    0,  _image436_size,    0,    0,    0,    0},
    {0x11,    0,  _image437_size,    0,    0,    0,    0},
    {   0,    0,  _image438_size,    0,    0,    0,    0},
    {   0,    0,  _image439_size,    0,    0,    0,    0},
    {   0,    0,  _image440_size,    0,    0,    0,    0},
    {   0,    0,  _image441_size,    0,    0,    0,    0},
    {   0,    0,  _image442_size,    0,    0,    0,    0},
    {0x77,    0,  _image443_size,    0,    0,    0,    0},
    {   0,    0,  _image444_size,    0,    0,    0,    0},
    {   0,    0,  _image445_size,    0,    0,    0,    0},
    {   0,    0,  _image446_size,    0,    0,    0,    0},
    {   0,    0,  _image447_size,    0,    0,    0,    0},
    {0x44,    0,  _image448_size,    0,    0,    0,    0},
    {0x44,    0,  _image449_size,    0,    0,    0,    0},
    {0x11,    0,  _image450_size,    0,    0,    0,    0},
    {0x11,    0,  _image451_size,    0,    0,    0,    0},
    {0xAA,    0,  _image452_size,    0,    0,    0,    0},
    {0x33,    0,  _image453_size,    0,    0,    0,    0},
    {0x33,    0,  _image454_size,    0,    0,    0,    0},
    {   0,    0,  _image455_size,    0,    0,    0,    0},
    {   0,    0,  _image456_size,    0,    0,    0,    0},
    {   0,    0,  _image457_size,    0,    0,    0,    0},
    {0xAA,    0,  _image458_size,    0,    0,    0,    0},
    {0x33,    0,  _image459_size,    0,    0,    0,    0},
    {0x33,    0,  _image460_size,    0,    0,    0,    0},
    {   0,    0,  _image461_size,    0,    0,    0,    0},
    {0xAA,    0,  _image462_size,    0,    0,    0,    0},
    {   0,    0,  _image463_size,    0,    0,    0,    0},
    {   0,    0,  _image464_size,    0,    0,    0,    0},
    {   0,    0,  _image465_size,    0,    0,    0,    0},
    {0xAA,    0,  _image466_size,    0,    0,    0,    0},
    {0xAA,    0,  _image467_size,    0,    0,    0,    0},
    {0xAA,    0,  _image468_size,    0,    0,    0,    0},
    {0xAA,    0,  _image469_size,    0,    0,    0,    0},
    {0xAA,    0,  _image470_size,    0,    0,    0,    0},
    {   0,    0,  _image471_size,    0,    0,    0,    0},
    {0xAA,    0,  _image472_size,    0,    0,    0,    0},
    {0xAA,    0,  _image473_size,    0,    0,    0,    0},
    {0xAA,    0,  _image474_size,    0,    0,    0,    0},
    {0x33,    0,  _image475_size,    0,    0,    0,    0},
    {0x33,    0,  _image476_size,    0,    0,    0,    0},
    {0x33,    0,  _image477_size,    0,    0,    0,    0},
    {0x33,    0,  _image478_size,    0,    0,    0,    0},
    {0x33,    0,  _image479_size,    0,    0,    0,    0},
    {0x33,    0,  _image480_size,    0,    0,    0,    0},
    {   0,    0,  _image481_size,    0,    0,    0,    0},
    {0x33,    0,  _image482_size,    0,    0,    0,    0},
    {0x33,    0,  _image483_size,    0,    0,    0,    0},
    {0x33,    0,  _image484_size,    0,    0,    0,    0},
    {0x33,    0,  _image485_size,    0,    0,    0,    0},
    {0x33,    0,  _image486_size,    0,    0,    0,    0},
    {0xAA,    0,  _image487_size,    0,    0,    0,    0},
    {0xAA,    0,  _image488_size,    0,    0,    0,    0},
    {0xAA,    0,  _image489_size,    0,    0,    0,    0},
    {   0,    0,  _image490_size,    0,    0,    0,    0},
    {   0,    0,  _image491_size,    0,    0,    0,    0},
    {0x33,    0,  _image492_size,    0,    0,    0,    0},
    {0xAA,    0,  _image493_size,    0,    0,    0,    0},
    {   0,    0,  _image494_size,    0,    0,    0,    0},
    {   0,    0,  _image495_size,    0,    0,    0,    0},
    {   0,    0,  _image496_size,    0,    0,    0,    0},
    {   0,    0,  _image497_size,    0,    0,    0,    0},
    {   0,    0,  _image498_size,    0,    0,    0,    0},
    {   0,    0,  _image499_size,    0,    0,    0,    0},
    {0xAA,    0,  _image500_size,    0,    0,    0,    0},
    {0xAA,    0,  _image501_size,    0,    0,    0,    0},
    {0xAA,    0,  _image502_size,    0,    0,    0,    0},
    {0x33,    0,  _image503_size,    0,    0,    0,    0},
    {0x33,    0,  _image504_size,    0,    0,    0,    0},
    {   0,    0,  _image505_size,    0,    0,    0,    0},
    {0x33,    0,  _image506_size,    0,    0,    0,    0},
    {   0,    0,  _image507_size,    0,    0,    0,    0},
    {0x33,    0,  _image508_size,    0,    0,    0,    0},
    {0x33,    0,  _image509_size,    0,    0,    0,    0},
    {0x33,    0,  _image510_size,    0,    0,    0,    0},
    {0x33,    0,  _image511_size,    0,    0,    0,    0},
    {0x33,    0,  _image512_size,    0,    0,    0,    0},
    {0x33,    0,  _image513_size,    0,    0,    0,    0},
    {   0,    0,  _image514_size,    0,    0,    0,    0},
    {0x33,    0,  _image515_size,    0,    0,    0,    0},
    {0xAA,    0,  _image516_size,    0,    0,    0,    0},
    {0xAA,    0,  _image517_size,    0,    0,    0,    0},
    {0xAA,    0,  _image518_size,    0,    0,    0,    0},
    {0xAA,    0,  _image519_size,    0,    0,    0,    0},
    {0xAA,    0,  _image520_size,    0,    0,    0,    0},
    {   0,    0,  _image521_size,    0,    0,    0,    0},
    {0xAA,    0,  _image522_size,    0,    0,    0,    0},
    {0x33,    0,  _image523_size,    0,    0,    0,    0},
    {0x33,    0,  _image524_size,    0,    0,    0,    0},
    {   0,    0,  _image525_size,    0,    0,    0,    0},
    {0x33,    0,  _image526_size,    0,    0,    0,    0},
    {0xAA,    0,  _image527_size,    0,    0,    0,    0},
    {0xAA,    0,  _image528_size,    0,    0,    0,    0},
    {0xAA,    0,  _image529_size,    0,    0,    0,    0},
    {0xAA,    0,  _image530_size,    0,    0,    0,    0},
    {   0,    0,  _image531_size,    0,    0,    0,    0},
    {   0,    0,  _image532_size,    0,    0,    0,    0},
    {   0,    0,  _image533_size,    0,    0,    0,    0},
    {0x33,    0,  _image534_size,    0,    0,    0,    0},
    {0x33,    0,  _image535_size,    0,    0,    0,    0},
    {0x33,    0,  _image536_size,    0,    0,    0,    0},
    {0x44,    0,  _image537_size,    0,    0,    0,    0},
    {0x77,    0,  _image538_size,    0,    0,    0,    0},
    {0x77,    0,  _image539_size,    0,    0,    0,    0},
    {   0,    0,  _image540_size,    0,    0,    0,    0},
    {   0,    0,  _image541_size,    0,    0,    0,    0},
    {   0,    0,  _image542_size,    0,    0,    0,    0},
    {0xAA,    0,  _image543_size,    0,    0,    0,    0},
    {   0,    0,  _image544_size,    0,    0,    0,    0},
    {   0,    0,  _image545_size,    0,    0,    0,    0},
    {0x33,    0,  _image546_size,    0,    0,    0,    0},
    {0x33,    0,  _image547_size,    0,    0,    0,    0},
    {0x33,    0,  _image548_size,    0,    0,    0,    0},
    {0x33,    0,  _image549_size,    0,    0,    0,    0},
    {0x33,    0,  _image550_size,    0,    0,    0,    0},
    {0x33,    0,  _image551_size,    0,    0,    0,    0},
    {0x33,    0,  _image552_size,    0,    0,    0,    0},
    {0x33,    0,  _image553_size,    0,    0,    0,    0},
    {0x33,    0,  _image554_size,    0,    0,    0,    0},
    {0x33,    0,  _image555_size,    0,    0,    0,    0},
    {0x33,    0,  _image556_size,    0,    0,    0,    0},
    {0x33,    0,  _image557_size,    0,    0,    0,    0},
    {0x33,    0,  _image558_size,    0,    0,    0,    0},
    {0x33,    0,  _image559_size,    0,    0,    0,    0},
    {0x33,    0,  _image560_size,    0,    0,    0,    0},
    {0x33,    0,  _image561_size,    0,    0,    0,    0},
    {0x33,    0,  _image562_size,    0,    0,    0,    0},
    {0x33,    0,  _image563_size,    0,    0,    0,    0},
    {0x33,    0,  _image564_size,    0,    0,    0,    0},
    {0x33,    0,  _image565_size,    0,    0,    0,    0},
    {0x33,    0,  _image566_size,    0,    0,    0,    0},
    {0x33,    0,  _image567_size,    0,    0,    0,    0},
    {0x33,    0,  _image568_size,    0,    0,    0,    0},
    {0x33,    0,  _image569_size,    0,    0,    0,    0},
    {0x33,    0,  _image570_size,    0,    0,    0,    0},
    {0x33,    0,  _image571_size,    0,    0,    0,    0},
    {0x33,    0,  _image572_size,    0,    0,    0,    0},
    {0x33,    0,  _image573_size,    0,    0,    0,    0},
    {0x33,    0,  _image574_size,    0,    0,    0,    0},
    {0x33,    0,  _image575_size,    0,    0,    0,    0},
    {0x33,    0,  _image576_size,    0,    0,    0,    0},
    {0x22,    0,  _image577_size,    0,    0,    0,    0},
    {0x33,    0,  _image578_size,    0,    0,    0,    0},
    {0x33,    0,  _image579_size,    0,    0,    0,    0},
    {0x33,    0,  _image580_size,    0,    0,    0,    0},
    {0x33,    0,  _image581_size,    0,    0,    0,    0},
    {   0,    0,  _image582_size,    0,    0,    0,    0},
    {   0,    0,  _image583_size,    0,    0,    0,    0},
    {   0,    0,  _image584_size,    0,    0,    0,    0},
    {   0,    0,  _image585_size,    0,    0,    0,    0},
    {   0,    0,  _image586_size,    0,    0,    0,    0},
    {   0,    0,  _image587_size,    0,    0,    0,    0},
    {   0,    0,  _image588_size,    0,    0,    0,    0},
    {0x77,    0,  _image589_size,    0,    0,    0,    0},
    {0x77,    0,  _image590_size,    0,    0,    0,    0},
    {0x77,    0,  _image591_size,    0,    0,    0,    0},
    {0x77,    0,  _image592_size,    0,    0,    0,    0},
    {0x77,    0,  _image593_size,    0,    0,    0,    0},
    {0x77,    0,  _image594_size,    0,    0,    0,    0},
    {0x77,    0,  _image595_size,    0,    0,    0,    0},
    {0x77,    0,  _image596_size,    0,    0,    0,    0},
    {   0,    0,  _image597_size,    0,    0,    0,    0},
    {   0,    0,  _image598_size,    0,    0,    0,    0},
    {   0,    0,  _image599_size,    0,    0,    0,    0},
    {   0,    0,  _image600_size,    0,    0,    0,    0},
    {   0,    0,  _image601_size,    0,    0,    0,    0},
    {   0,    0,  _image602_size,    0,    0,    0,    0},
    {   0,    0,  _image603_size,    0,    0,    0,    0},
    {   0,    0,  _image604_size,    0,    0,    0,    0},
    {   0,    0,  _image605_size,    0,    0,    0,    0},
    {   0,    0,  _image606_size,    0,    0,    0,    0},
    {   0,    0,  _image607_size,    0,    0,    0,    0},
    {   0,    0,  _image608_size,    0,    0,    0,    0},
    {   0,    0,  _image609_size,    0,    0,    0,    0},
    {   0,    0,  _image610_size,    0,    0,    0,    0},
    {   0,    0,  _image611_size,    0,    0,    0,    0},
    {   0,    0,  _image612_size,    0,    0,    0,    0},
    {0x33,    0,  _image613_size,    0,    0,    0,    0},
    {0x33,    0,  _image614_size,    0,    0,    0,    0},
    {0x33,    0,  _image615_size,    0,    0,    0,    0},
    {0x33,    0,  _image616_size,    0,    0,    0,    0},
    {0x33,    0,  _image617_size,    0,    0,    0,    0},
    {   0,    0,  _image618_size,    0,    0,    0,    0},
    {   0,    0,  _image619_size,    0,    0,    0,    0},
    {0x22,    0,  _image620_size,    0,    0,    0,    0},
    {0x33,    0,  _image621_size,    0,    0,    0,    0},
    {0x33,    0,  _image622_size,    0,    0,    0,    0},
    {0x33,    0,  _image623_size,    0,    0,    0,    0},
    {   0,    0,  _image624_size,    0,    0,    0,    0},
    {   0,    0,  _image625_size,    0,    0,    0,    0},
    {   0,    0,  _image626_size,    0,    0,    0,    0},
    {   0,    0,  _image627_size,    0,    0,    0,    0},
    {   0,    0,  _image628_size,    0,    0,    0,    0},
    {   0,    0,  _image629_size,    0,    0,    0,    0},
    {   0,    0,  _image630_size,    0,    0,    0,    0},
    {   0,    0,  _image631_size,    0,    0,    0,    0},
    {0x99,    0,  _image632_size,    0,    0,    0,    0},
    {0x99,    0,  _image633_size,    0,    0,    0,    0},
    {   0,    0,  _image634_size,    0,    0,    0,    0},
    {   0,    0,  _image635_size,    0,    0,    0,    0},
    {   0,    0,  _image636_size,    0,    0,    0,    0},
    {   0,    0,  _image637_size,    0,    0,    0,    0},
    {   0,    0,  _image638_size,    0,    0,    0,    0},
    {   0,    0,  _image639_size,    0,    0,    0,    0},
    {   0,    0,  _image640_size,    0,    0,    0,    0},
    {   0,    0,  _image641_size,    0,    0,    0,    0},
    {   0,    0,  _image642_size,    0,    0,    0,    0},
    {   0,    0,  _image643_size,    0,    0,    0,    0},
    {0x33,    0,  _image644_size,    0,    0,    0,    0},
    {0x33,    0,  _image645_size,    0,    0,    0,    0},
    {0x33,    0,  _image646_size,    0,    0,    0,    0},
    {   0,    0,  _image647_size,    0,    0,    0,    0},
    {0x33,    0,  _image648_size,    0,    0,    0,    0},
    {   0,    0,  _image649_size,    0,    0,    0,    0},
    {   0,    0,  _image650_size,    0,    0,    0,    0},
    {   0,    0,  _image651_size,    0,    0,    0,    0},
    {0x33,    0,  _image652_size,    0,    0,    0,    0},
    {0x44,    0,  _image653_size,    0,    0,    0,    0},
    {0x4C,    0,  _image654_size,    0,    0,    0,    0},
    {0x4C,    0,  _image655_size,    0,    0,    0,    0},
    {0x4C,    0,  _image656_size,    0,    0,    0,    0},
    {0x44,    0,  _image657_size,    0,    0,    0,    0},
    {0x44,    0,  _image658_size,    0,    0,    0,    0},
    {0x44,    0,  _image659_size,    0,    0,    0,    0},
    {   0,    0,  _image660_size,    0,    0,    0,    0},
    {   0,    0,  _image661_size,    0,    0,    0,    0},
    {   0,    0,  _image662_size,    0,    0,    0,    0},
    {   0,    0,  _image663_size,    0,    0,    0,    0},
    {   0,    0,  _image664_size,    0,    0,    0,    0},
    {   0,    0,  _image665_size,    0,    0,    0,    0},
    {   0,    0,  _image666_size,    0,    0,    0,    0},
    {   0,    0,  _image667_size,    0,    0,    0,    0},
    {   0,    0,  _image668_size,    0,    0,    0,    0},
    {   0,    0,  _image669_size,    0,    0,    0,    0},
    {   0,    0,  _image670_size,    0,    0,    0,    0},
    {   0,    0,  _image671_size,    0,    0,    0,    0},
    {0x33,    0,  _image672_size,    0,    0,    0,    0},
    {0x33,    0,  _image673_size,    0,    0,    0,    0},
    {0x33,    0,  _image674_size,    0,    0,    0,    0},
    {0x33,    0,  _image675_size,    0,    0,    0,    0},
    {0x11,    0,  _image676_size,    0,    0,    0,    0},
    {0x11,    0,  _image677_size,    0,    0,    0,    0},
    {   0,    0,  _image678_size,    0,    0,    0,    0},
    {0x22,    0,  _image679_size,    0,    0,    0,    0},
    {0x33,    0,  _image680_size,    0,    0,    0,    0},
    {0x33,    0,  _image681_size,    0,    0,    0,    0},
    {0x33,    0,  _image682_size,    0,    0,    0,    0},
    {0x33,    0,  _image683_size,    0,    0,    0,    0},
    {0x33,    0,  _image684_size,    0,    0,    0,    0},
    {0x33,    0,  _image685_size,    0,    0,    0,    0},
    {0x33,    0,  _image686_size,    0,    0,    0,    0},
    {0x33,    0,  _image687_size,    0,    0,    0,    0},
    {0x33,    0,  _image688_size,    0,    0,    0,    0},
    {0x33,    0,  _image689_size,    0,    0,    0,    0},
    {   0,    0,  _image690_size,    0,    0,    0,    0},
    {   0,    0,  _image691_size,    0,    0,    0,    0},
    {   0,    0,  _image692_size,    0,    0,    0,    0},
    {0xAA,    0,  _image693_size,    0,    0,    0,    0},
    {0x44,    0,  _image694_size,    0,    0,    0,    0},
    {   0,    0,  _image695_size,    0,    0,    0,    0},
    {0x99,    0,  _image696_size,    0,    0,    0,    0},
    {0x99,    0,  _image697_size,    0,    0,    0,    0},
    {0x77,    0,  _image698_size,    0,    0,    0,    0},
    {0x99,    0,  _image699_size,    0,    0,    0,    0},
    {0x99,    0,  _image700_size,    0,    0,    0,    0},
    {0x33,    0,  _image701_size,    0,    0,    0,    0},
    {0x33,    0,  _image702_size,    0,    0,    0,    0},
    {0xAA,    0,  _image703_size,    0,    0,    0,    0},
    {0xAA,    0,  _image704_size,    0,    0,    0,    0},
    {0xAA,    0,  _image705_size,    0,    0,    0,    0},
    {0x33,    0,  _image706_size,    0,    0,    0,    0},
    {0x33,    0,  _image707_size,    0,    0,    0,    0},
    {0x33,    0,  _image708_size,    0,    0,    0,    0},
    {0x33,    0,  _image709_size,    0,    0,    0,    0},
    {0x33,    0,  _image710_size,    0,    0,    0,    0},
    {0x33,    0,  _image711_size,    0,    0,    0,    0},
    {0x33,    0,  _image712_size,    0,    0,    0,    0},
    {   0,    0,  _image713_size,    0,    0,    0,    0},
    {   0,    0,  _image714_size,    0,    0,    0,    0},
    {   0,    0,  _image715_size,    0,    0,    0,    0},
    {0x33,    0,  _image716_size,    0,    0,    0,    0},
    {0x33,    0,  _image717_size,    0,    0,    0,    0},
    {0x33,    0,  _image718_size,    0,    0,    0,    0},
    {0x99,    0,  _image719_size,    0,    0,    0,    0},
    {0x99,    0,  _image720_size,    0,    0,    0,    0},
    {0x11,    0,  _image721_size,    0,    0,    0,    0},
    {0x11,    0,  _image722_size,    0,    0,    0,    0},
    {   0,    0,  _image723_size,    0,    0,    0,    0},
    {0x11,    0,  _image724_size,    0,    0,    0,    0},
    {0x11,    0,  _image725_size,    0,    0,    0,    0},
    {0x11,    0,  _image726_size,    0,    0,    0,    0},
    {0xAA,    0,  _image727_size,    0,    0,    0,    0},
    {0xAA,    0,  _image728_size,    0,    0,    0,    0},
    {0xAA,    0,  _image729_size,    0,    0,    0,    0},
    {0xAA,    0,  _image730_size,    0,    0,    0,    0},
    {0xAA,    0,  _image731_size,    0,    0,    0,    0},
    {0xAA,    0,  _image732_size,    0,    0,    0,    0},
    {   0,    0,  _image733_size,    0,    0,    0,    0},
    {   0,    0,  _image734_size,    0,    0,    0,    0},
    {   0,    0,  _image735_size,    0,    0,    0,    0},
    {   0,    0,  _image736_size,    0,    0,    0,    0},
    {   0,    0,  _image737_size,    0,    0,    0,    0},
    {   0,    0,  _image738_size,    0,    0,    0,    0},
    {   0,    0,  _image739_size,    0,    0,    0,    0},
    {   0,    0,  _image740_size,    0,    0,    0,    0},
    {   0,    0,  _image741_size,    0,    0,    0,    0},
    {   0,    0,  _image742_size,    0,    0,    0,    0},
    {   0,    0,  _image743_size,    0,    0,    0,    0},
    {   0,    0,  _image744_size,    0,    0,    0,    0},
    {   0,    0,  _image745_size,    0,    0,    0,    0},
    {   0,    0,  _image746_size,    0,    0,    0,    0},
    {   0,    0,  _image747_size,    0,    0,    0,    0},
    {   0,    0,  _image748_size,    0,    0,    0,    0},
    {   0,    0,  _image749_size,    0,    0,    0,    0},
    {   0,    0,  _image750_size,    0,    0,    0,    0},
    {   0,    0,  _image751_size,    0,    0,    0,    0},
    {   0,    0,  _image752_size,    0,    0,    0,    0},
    {   0,    0,  _image753_size,    0,    0,    0,    0},
    {   0,    0,  _image754_size,    0,    0,    0,    0},
    {   0,    0,  _image755_size,    0,    0,    0,    0},
    {   0,    0,  _image756_size,    0,    0,    0,    0},
    {   0,    0,  _image757_size,    0,    0,    0,    0},
    {   0,    0,  _image758_size,    0,    0,    0,    0},
    {   0,    0,  _image759_size,    0,    0,    0,    0},
    {   0,    0,  _image760_size,    0,    0,    0,    0},
    {0x77,    0,  _image761_size,    0,    0,    0,    0},
    {0x77,    0,  _image762_size,    0,    0,    0,    0},
    {   0,    0,  _image763_size,    0,    0,    0,    0},
    {   0,    0,  _image764_size,    0,    0,    0,    0},
    {   0,    0,  _image765_size,    0,    0,    0,    0},
    {   0,    0,  _image766_size,    0,    0,    0,    0},
    {   0,    0,  _image767_size,    0,    0,    0,    0},
    {   0,    0,  _image768_size,    0,    0,    0,    0},
    {   0,    0,  _image769_size,    0,    0,    0,    0},
    {   0,    0,  _image770_size,    0,    0,    0,    0},
    {   0,    0,  _image771_size,    0,    0,    0,    0},
    {   0,    0,  _image772_size,    0,    0,    0,    0},
    {0xAA,    0,  _image773_size,    0,    0,    0,    0},
    {0xAA,    0,  _image774_size,    0,    0,    0,    0},
    {0xAA,    0,  _image775_size,    0,    0,    0,    0},
    {0x88,    0,  _image776_size,    0,    0,    0,    0},
    {   0,    0,  _image777_size,    0,    0,    0,    0},
    {0x11,    0,  _image778_size,    0,    0,    0,    0},
    {   0,    0,  _image779_size,    0,    0,    0,    0},
    {   0,    0,  _image780_size,    0,    0,    0,    0},
    {   0,    0,  _image781_size,    0,    0,    0,    0},
    {   0,    0,  _image782_size,    0,    0,    0,    0},
    {   0,    0,  _image783_size,    0,    0,    0,    0},
    {0x77,    0,  _image784_size,    0,    0,    0,    0},
    {   0,    0,  _image785_size,    0,    0,    0,    0},
    {   0,    0,  _image786_size,    0,    0,    0,    0},
    {   0,    0,  _image787_size,    0,    0,    0,    0},
    {0xAA,    0,  _image788_size,    0,    0,    0,    0},
    {   0,    0,  _image789_size,    0,    0,    0,    0},
    {   0,    0,  _image790_size,    0,    0,    0,    0},
    {   0,    0,  _image791_size,    0,    0,    0,    0},
    {   0,    0,  _image792_size,    0,    0,    0,    0},
    {   0,    0,  _image793_size,    0,    0,    0,    0},
    {   0,    0,  _image794_size,    0,    0,    0,    0},
    {   0,    0,  _image795_size,    0,    0,    0,    0},
    {   0,    0,  _image796_size,    0,    0,    0,    0},
    {0x33,    0,  _image797_size,    0,    0,    0,    0},
    {0x33,    0,  _image798_size,    0,    0,    0,    0},
    {0x33,    0,  _image799_size,    0,    0,    0,    0},
    {0x33,    0,  _image800_size,    0,    0,    0,    0},
    {0x33,    0,  _image801_size,    0,    0,    0,    0},
    {0x33,    0,  _image802_size,    0,    0,    0,    0},
    {0x33,    0,  _image803_size,    0,    0,    0,    0},
    {0x33,    0,  _image804_size,    0,    0,    0,    0},
    {   0,    0,  _image805_size,    0,    0,    0,    0},
    {0xAA,    0,  _image806_size,    0,    0,    0,    0},
    {   0,    0,  _image807_size,    0,    0,    0,    0},
    {   0,    0,  _image808_size,    0,    0,    0,    0},
    {0x44,    0,  _image809_size,    0,    0,    0,    0},
    {0x44,    0,  _image810_size,    0,    0,    0,    0},
    {0x44,    0,  _image811_size,    0,    0,    0,    0},
    {   0,    0,  _image812_size,    0,    0,    0,    0},
    {   0,    0,  _image813_size,    0,    0,    0,    0},
    {   0,    0,  _image814_size,    0,    0,    0,    0},
    {   0,    0,  _image815_size,    0,    0,    0,    0},
    {   0,    0,  _image816_size,    0,    0,    0,    0},
    {   0,    0,  _image817_size,    0,    0,    0,    0},
    {0x33,    0,  _image818_size,    0,    0,    0,    0},
    {0xAA,    0,  _image819_size,    0,    0,    0,    0},
    {0x33,    0,  _image820_size,    0,    0,    0,    0},
    {0x33,    0,  _image821_size,    0,    0,    0,    0},
    {   0,    0,  _image822_size,    0,    0,    0,    0},
    {   0,    0,  _image823_size,    0,    0,    0,    0},
    {   0,    0,  _image824_size,    0,    0,    0,    0},
    {   0,    0,  _image825_size,    0,    0,    0,    0},
    {   0,    0,  _image826_size,    0,    0,    0,    0},
    {   0,    0,  _image827_size,    0,    0,    0,    0},
    {   0,    0,  _image828_size,    0,    0,    0,    0},
    {   0,    0,  _image829_size,    0,    0,    0,    0},
    {   0,    0,  _image830_size,    0,    0,    0,    0},
    {   0,    0,  _image831_size,    0,    0,    0,    0},
    {   0,    0,  _image832_size,    0,    0,    0,    0},
    {   0,    0,  _image833_size,    0,    0,    0,    0},
    {   0,    0,  _image834_size,    0,    0,    0,    0},
    {   0,    0,  _image835_size,    0,    0,    0,    0},
    {   0,    0,  _image836_size,    0,    0,    0,    0},
    {0xAA,    0,  _image837_size,    0,    0,    0,    0},
    {   0,    0,  _image838_size,    0,    0,    0,    0},
    {   0,    0,  _image839_size,    0,    0,    0,    0},
    {   0,    0,  _image840_size,    0,    0,    0,    0},
    {   0,    0,  _image841_size,    0,    0,    0,    0},
    {   0,    0,  _image842_size,    0,    0,    0,    0},
    {0xAA,    0,  _image843_size,    0,    0,    0,    0},
    {0xAA,    0,  _image844_size,    0,    0,    0,    0},
    {0xAA,    0,  _image845_size,    0,    0,    0,    0},
    {0x33,    0,  _image846_size,    0,    0,    0,    0},
    {0x33,    0,  _image847_size,    0,    0,    0,    0},
    {0x33,    0,  _image848_size,    0,    0,    0,    0},
    {0x33,    0,  _image849_size,    0,    0,    0,    0},
    {   0,    0,  _image850_size,    0,    0,    0,    0},
    {   0,    0,  _image851_size,    0,    0,    0,    0},
    {   0,    0,  _image852_size,    0,    0,    0,    0},
    {   0,    0,  _image853_size,    0,    0,    0,    0},
    {   0,    0,  _image854_size,    0,    0,    0,    0},
    {   0,    0,  _image855_size,    0,    0,    0,    0},
    {   0,    0,  _image856_size,    0,    0,    0,    0},
    {0x44,    0,  _image857_size,    0,    0,    0,    0},
    {0xAA,    0,  _image858_size,    0,    0,    0,    0},
    {0xAA,    0,  _image859_size,    0,    0,    0,    0},
    {0x33,    0,  _image860_size,    0,    0,    0,    0},
    {0x33,    0,  _image861_size,    0,    0,    0,    0},
    {0x33,    0,  _image862_size,    0,    0,    0,    0},
    {0x33,    0,  _image863_size,    0,    0,    0,    0},
    {   0,    0,  _image864_size,    0,    0,    0,    0},
    {0x44,    0,  _image865_size,    0,    0,    0,    0},
    {0x44,    0,  _image866_size,    0,    0,    0,    0},
    {0x22,    0,  _image867_size,    0,    0,    0,    0},
    {0x99,    0,  _image868_size,    0,    0,    0,    0},
    {0x99,    0,  _image869_size,    0,    0,    0,    0},
    {0xAA,    0,  _image870_size,    0,    0,    0,    0},
    {   0,    0,  _image871_size,    0,    0,    0,    0},
    {   0,    0,  _image872_size,    0,    0,    0,    0},
    {   0,    0,  _image873_size,    0,    0,    0,    0},
    {   0,    0,  _image874_size,    0,    0,    0,    0},
    {   0,    0,  _image875_size,    0,    0,    0,    0},
    {   0,    0,  _image876_size,    0,    0,    0,    0},
    {   0,    0,  _image877_size,    0,    0,    0,    0},
    {   0,    0,  _image878_size,    0,    0,    0,    0},
    {   0,    0,  _image879_size,    0,    0,    0,    0},
    {   0,    0,  _image880_size,    0,    0,    0,    0},
    {   0,    0,  _image881_size,    0,    0,    0,    0},
    {   0,    0,  _image882_size,    0,    0,    0,    0},
    {   0,    0,  _image883_size,    0,    0,    0,    0},
    {   0,    0,  _image884_size,    0,    0,    0,    0},
    {   0,    0,  _image885_size,    0,    0,    0,    0},
    {   0,    0,  _image886_size,    0,    0,    0,    0},
    {   0,    0,  _image887_size,    0,    0,    0,    0},
    {   0,    0,  _image888_size,    0,    0,    0,    0},
    {0x33,    0,  _image889_size,    0,    0,    0,    0},
    {0xAA,    0,  _image890_size,    0,    0,    0,    0},
    {0xAA,    0,  _image891_size,    0,    0,    0,    0},
    {0xAA,    0,  _image892_size,    0,    0,    0,    0},
    {0xAA,    0,  _image893_size,    0,    0,    0,    0},
    {0xAA,    0,  _image894_size,    0,    0,    0,    0},
    {0xAA,    0,  _image895_size,    0,    0,    0,    0},
    {   0,    0,  _image896_size,    0,    0,    0,    0},
    {   0,    0,  _image897_size,    0,    0,    0,    0},
    {   0,    0,  _image898_size,    0,    0,    0,    0},
    {   0,    0,  _image899_size,    0,    0,    0,    0},
    {   0,    0,  _image900_size,    0,    0,    0,    0},
    {0x99,    0,  _image901_size,    0,    0,    0,    0},
    {0x99,    0,  _image902_size,    0,    0,    0,    0},
    {0x99,    0,  _image903_size,    0,    0,    0,    0},
    {0x99,    0,  _image904_size,    0,    0,    0,    0},
    {   0,    0,  _image905_size,    0,    0,    0,    0},
    {   0,    0,  _image906_size,    0,    0,    0,    0},
    {   0,    0,  _image907_size,    0,    0,    0,    0},
    {   0,    0,  _image908_size,    0,    0,    0,    0},
    {   0,    0,  _image909_size,    0,    0,    0,    0},
    {0x33,    0,  _image910_size,    0,    0,    0,    0},
    {0x33,    0,  _image911_size,    0,    0,    0,    0},
    {0x33,    0,  _image912_size,    0,    0,    0,    0},
    {0x33,    0,  _image913_size,    0,    0,    0,    0},
    {0x33,    0,  _image914_size,    0,    0,    0,    0},
    {0x33,    0,  _image915_size,    0,    0,    0,    0},
    {0x33,    0,  _image916_size,    0,    0,    0,    0},
    {0x33,    0,  _image917_size,    0,    0,    0,    0},
    {0x33,    0,  _image918_size,    0,    0,    0,    0},
    {0x33,    0,  _image919_size,    0,    0,    0,    0},
    {0xAA,    0,  _image920_size,    0,    0,    0,    0},
    {0x33,    0,  _image921_size,    0,    0,    0,    0},
    {0x33,    0,  _image922_size,    0,    0,    0,    0},
    {0x33,    0,  _image923_size,    0,    0,    0,    0},
    {0x33,    0,  _image924_size,    0,    0,    0,    0},
    {   0,    0,  _image925_size,    0,    0,    0,    0},
    {   0,    0,  _image926_size,    0,    0,    0,    0},
    {   0,    0,  _image927_size,    0,    0,    0,    0},
    {   0,    0,  _image928_size,    0,    0,    0,    0},
    {   0,    0,  _image929_size,    0,    0,    0,    0},
    {   0,    0,  _image930_size,    0,    0,    0,    0},
    {   0,    0,  _image931_size,    0,    0,    0,    0},
    {   0,    0,  _image932_size,    0,    0,    0,    0},
    {   0,    0,  _image933_size,    0,    0,    0,    0},
    {   0,    0,  _image934_size,    0,    0,    0,    0},
    {   0,    0,  _image935_size,    0,    0,    0,    0},
    {   0,    0,  _image936_size,    0,    0,    0,    0},
    {   0,    0,  _image937_size,    0,    0,    0,    0},
    {   0,    0,  _image938_size,    0,    0,    0,    0},
    {   0,    0,  _image939_size,    0,    0,    0,    0},
    {   0,    0,  _image940_size,    0,    0,    0,    0},
    {   0,    0,  _image941_size,    0,    0,    0,    0},
    {   0,    0,  _image942_size,    0,    0,    0,    0},
    {   0,    0,  _image943_size,    0,    0,    0,    0},
    {   0,    0,  _image944_size,    0,    0,    0,    0},
    {   0,    0,  _image945_size,    0,    0,    0,    0},
    {   0,    0,  _image946_size,    0,    0,    0,    0},
    {   0,    0,  _image947_size,    0,    0,    0,    0},
    {   0,    0,  _image948_size,    0,    0,    0,    0},
    {   0,    0,  _image949_size,    0,    0,    0,    0},
    {   0,    0,  _image950_size,    0,    0,    0,    0},
    {   0,    0,  _image951_size,    0,    0,    0,    0},
    {   0,    0,  _image952_size,    0,    0,    0,    0},
    {   0,    0,  _image953_size,    0,    0,    0,    0},
    {   0,    0,  _image954_size,    0,    0,    0,    0},
    {   0,    0,  _image955_size,    0,    0,    0,    0},
    {   0,    0,  _image956_size,    0,    0,    0,    0},
    {   0,    0,  _image957_size,    0,    0,    0,    0},
    {   0,    0,  _image958_size,    0,    0,    0,    0},
    {   0,    0,  _image959_size,    0,    0,    0,    0},
    {0x77,    0,  _image960_size,    0,    0,    0,    0},
    {0x77,    0,  _image961_size,    0,    0,    0,    0},
    {0x11,    0,  _image962_size,    0,    0,    0,    0},
    {0x11,    0,  _image963_size,    0,    0,    0,    0},
    {0x11,    0,  _image964_size,    0,    0,    0,    0},
    {0x11,    0,  _image965_size,    0,    0,    0,    0},
    {0x11,    0,  _image966_size,    0,    0,    0,    0},
    {0x11,    0,  _image967_size,    0,    0,    0,    0},
    {0x11,    0,  _image968_size,    0,    0,    0,    0},
    {0x11,    0,  _image969_size,    0,    0,    0,    0},
    {0x77,    0,  _image970_size,    0,    0,    0,    0},
    {0x77,    0,  _image971_size,    0,    0,    0,    0},
    {0x77,    0,  _image972_size,    0,    0,    0,    0},
    {0x77,    0,  _image973_size,    0,    0,    0,    0},
    {0x77,    0,  _image974_size,    0,    0,    0,    0},
    {0x77,    0,  _image975_size,    0,    0,    0,    0},
    {0x77,    0,  _image976_size,    0,    0,    0,    0},
    {0x77,    0,  _image977_size,    0,    0,    0,    0},
    {0x77,    0,  _image978_size,    0,    0,    0,    0},
    {0x77,    0,  _image979_size,    0,    0,    0,    0},
    {0x77,    0,  _image980_size,    0,    0,    0,    0},
    {0x77,    0,  _image981_size,    0,    0,    0,    0},
    {0x77,    0,  _image982_size,    0,    0,    0,    0},
    {   0,    0,  _image983_size,    0,    0,    0,    0},
    {0xAA,    0,  _image984_size,    0,    0,    0,    0},
    {0xAA,    0,  _image985_size,    0,    0,    0,    0},
    {   0,    0,  _image986_size,    0,    0,    0,    0},
    {   0,    0,  _image987_size,    0,    0,    0,    0},
    {   0,    0,  _image988_size,    0,    0,    0,    0},
    {   0,    0,  _image989_size,    0,    0,    0,    0},
    {   0,    0,  _image990_size,    0,    0,    0,    0},
    {   0,    0,  _image991_size,    0,    0,    0,    0},
    {   0,    0,  _image992_size,    0,    0,    0,    0},
    {   0,    0,  _image993_size,    0,    0,    0,    0},
    {   0,    0,  _image994_size,    0,    0,    0,    0},
    {   0,    0,  _image995_size,    0,    0,    0,    0},
    {   0,    0,  _image996_size,    0,    0,    0,    0},
    {   0,    0,  _image997_size,    0,    0,    0,    0},
    {   0,    0,  _image998_size,    0,    0,    0,    0},
    {   0,    0,  _image999_size,    0,    0,    0,    0},
    {0x33,    0,  _image1000_size,    0,    0,    0,    0},
    {0x33,    0,  _image1001_size,    0,    0,    0,    0},
    {0x33,    0,  _image1002_size,    0,    0,    0,    0},
    {0x33,    0,  _image1003_size,    0,    0,    0,    0},
    {0x33,    0,  _image1004_size,    0,    0,    0,    0},
    {   0,    0,  _image1005_size,    0,    0,    0,    0},
    {   0,    0,  _image1006_size,    0,    0,    0,    0},
    {   0,    0,  _image1007_size,    0,    0,    0,    0},
    {   0,    0,  _image1008_size,    0,    0,    0,    0},
    {   0,    0,  _image1009_size,    0,    0,    0,    0},
    {0x77,    0,  _image1010_size,    0,    0,    0,    0},
    {0x77,    0,  _image1011_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1012_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1013_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1014_size,    0,    0,    0,    0},
    {   0,    0,  _image1015_size,    0,    0,    0,    0},
    {   0,    0,  _image1016_size,    0,    0,    0,    0},
    {0x33,    0,  _image1017_size,    0,    0,    0,    0},
    {0x33,    0,  _image1018_size,    0,    0,    0,    0},
    {0x33,    0,  _image1019_size,    0,    0,    0,    0},
    {0x77,    0,  _image1020_size,    0,    0,    0,    0},
    {   0,    0,  _image1021_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1022_size,    0,    0,    0,    0},
    {0x11,    0,  _image1023_size,    0,    0,    0,    0},
    {0x22,    0,  _image1024_size,    0,    0,    0,    0},
    {0x22,    0,  _image1025_size,    0,    0,    0,    0},
    {   0,    0,  _image1026_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1027_size,    0,    0,    0,    0},
    {   0,    0,  _image1028_size,    0,    0,    0,    0},
    {   0,    0,  _image1029_size,    0,    0,    0,    0},
    {   0,    0,  _image1030_size,    0,    0,    0,    0},
    {   0,    0,  _image1031_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1032_size,    0,    0,    0,    0},
    {   0,    0,  _image1033_size,    0,    0,    0,    0},
    {   0,    0,  _image1034_size,    0,    0,    0,    0},
    {   0,    0,  _image1035_size,    0,    0,    0,    0},
    {   0,    0,  _image1036_size,    0,    0,    0,    0},
    {   0,    0,  _image1037_size,    0,    0,    0,    0},
    {   0,    0,  _image1038_size,    0,    0,    0,    0},
    {   0,    0,  _image1039_size,    0,    0,    0,    0},
    {   0,    0,  _image1040_size,    0,    0,    0,    0},
    {   0,    0,  _image1041_size,    0,    0,    0,    0},
    {   0,    0,  _image1042_size,    0,    0,    0,    0},
    {   0,    0,  _image1043_size,    0,    0,    0,    0},
    {   0,    0,  _image1044_size,    0,    0,    0,    0},
    {   0,    0,  _image1045_size,    0,    0,    0,    0},
    {   0,    0,  _image1046_size,    0,    0,    0,    0},
    {   0,    0,  _image1047_size,    0,    0,    0,    0},
    {   0,    0,  _image1048_size,    0,    0,    0,    0},
    {0x11,    0,  _image1049_size,    0,    0,    0,    0},
    {   0,    0,  _image1050_size,    0,    0,    0,    0},
    {   0,    0,  _image1051_size,    0,    0,    0,    0},
    {   0,    0,  _image1052_size,    0,    0,    0,    0},
    {   0,    0,  _image1053_size,    0,    0,    0,    0},
    {   0,    0,  _image1054_size,    0,    0,    0,    0},
    {   0,    0,  _image1055_size,    0,    0,    0,    0},
    {   0,    0,  _image1056_size,    0,    0,    0,    0},
    {   0,    0,  _image1057_size,    0,    0,    0,    0},
    {   0,    0,  _image1058_size,    0,    0,    0,    0},
    {   0,    0,  _image1059_size,    0,    0,    0,    0},
    {   0,    0,  _image1060_size,    0,    0,    0,    0},
    {   0,    0,  _image1061_size,    0,    0,    0,    0},
    {   0,    0,  _image1062_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1063_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1064_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1065_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1066_size,    0,    0,    0,    0},
    {   0,    0,  _image1067_size,    0,    0,    0,    0},
    {   0,    0,  _image1068_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1069_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1070_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1071_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1072_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1073_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1074_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1075_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1076_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1077_size,    0,    0,    0,    0},
    {0x44,    0,  _image1078_size,    0,    0,    0,    0},
    {   0,    0,  _image1079_size,    0,    0,    0,    0},
    {   0,    0,  _image1080_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1081_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1082_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1083_size,    0,    0,    0,    0},
    {   0,    0,  _image1084_size,    0,    0,    0,    0},
    {   0,    0,  _image1085_size,    0,    0,    0,    0},
    {   0,    0,  _image1086_size,    0,    0,    0,    0},
    {   0,    0,  _image1087_size,    0,    0,    0,    0},
    {   0,    0,  _image1088_size,    0,    0,    0,    0},
    {   0,    0,  _image1089_size,    0,    0,    0,    0},
    {   0,    0,  _image1090_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1091_size,    0,    0,    0,    0},
    {0x33,    0,  _image1092_size,    0,    0,    0,    0},
    {0x33,    0,  _image1093_size,    0,    0,    0,    0},
    {0x33,    0,  _image1094_size,    0,    0,    0,    0},
    {0x33,    0,  _image1095_size,    0,    0,    0,    0},
    {0x33,    0,  _image1096_size,    0,    0,    0,    0},
    {0x33,    0,  _image1097_size,    0,    0,    0,    0},
    {0x33,    0,  _image1098_size,    0,    0,    0,    0},
    {0x33,    0,  _image1099_size,    0,    0,    0,    0},
    {0x33,    0,  _image1100_size,    0,    0,    0,    0},
    {0x33,    0,  _image1101_size,    0,    0,    0,    0},
    {0x33,    0,  _image1102_size,    0,    0,    0,    0},
    {   0,    0,  _image1103_size,    0,    0,    0,    0},
    {   0,    0,  _image1104_size,    0,    0,    0,    0},
    {   0,    0,  _image1105_size,    0,    0,    0,    0},
    {   0,    0,  _image1106_size,    0,    0,    0,    0},
    {   0,    0,  _image1107_size,    0,    0,    0,    0},
    {   0,    0,  _image1108_size,    0,    0,    0,    0},
    {   0,    0,  _image1109_size,    0,    0,    0,    0},
    {   0,    0,  _image1110_size,    0,    0,    0,    0},
    {   0,    0,  _image1111_size,    0,    0,    0,    0},
    {   0,    0,  _image1112_size,    0,    0,    0,    0},
    {   0,    0,  _image1113_size,    0,    0,    0,    0},
    {   0,    0,  _image1114_size,    0,    0,    0,    0},
    {   0,    0,  _image1115_size,    0,    0,    0,    0},
    {   0,    0,  _image1116_size,    0,    0,    0,    0},
    {0x33,    0,  _image1117_size,    0,    0,    0,    0},
    {0x33,    0,  _image1118_size,    0,    0,    0,    0},
    {   0,    0,  _image1119_size,    0,    0,    0,    0},
    {0x77,    0,  _image1120_size,    0,    0,    0,    0},
    {0x77,    0,  _image1121_size,    0,    0,    0,    0},
    {0x77,    0,  _image1122_size,    0,    0,    0,    0},
    {0x77,    0,  _image1123_size,    0,    0,    0,    0},
    {0x77,    0,  _image1124_size,    0,    0,    0,    0},
    {0x77,    0,  _image1125_size,    0,    0,    0,    0},
    {   0,    0,  _image1126_size,    0,    0,    0,    0},
    {   0,    0,  _image1127_size,    0,    0,    0,    0},
    {0x77,    0,  _image1128_size,    0,    0,    0,    0},
    {0x11,    0,  _image1129_size,    0,    0,    0,    0},
    {0x11,    0,  _image1130_size,    0,    0,    0,    0},
    {   0,    0,  _image1131_size,    0,    0,    0,    0},
    {   0,    0,  _image1132_size,    0,    0,    0,    0},
    {   0,    0,  _image1133_size,    0,    0,    0,    0},
    {0x11,    0,  _image1134_size,    0,    0,    0,    0},
    {0x11,    0,  _image1135_size,    0,    0,    0,    0},
    {0x22,    0,  _image1136_size,    0,    0,    0,    0},
    {0x22,    0,  _image1137_size,    0,    0,    0,    0},
    {0x22,    0,  _image1138_size,    0,    0,    0,    0},
    {0x33,    0,  _image1139_size,    0,    0,    0,    0},
    {0x33,    0,  _image1140_size,    0,    0,    0,    0},
    {0x33,    0,  _image1141_size,    0,    0,    0,    0},
    {   0,    0,  _image1142_size,    0,    0,    0,    0},
    {   0,    0,  _image1143_size,    0,    0,    0,    0},
    {   0,    0,  _image1144_size,    0,    0,    0,    0},
    {   0,    0,  _image1145_size,    0,    0,    0,    0},
    {   0,    0,  _image1146_size,    0,    0,    0,    0},
    {0x77,    0,  _image1147_size,    0,    0,    0,    0},
    {   0,    0,  _image1148_size,    0,    0,    0,    0},
    {   0,    0,  _image1149_size,    0,    0,    0,    0},
    {   0,    0,  _image1150_size,    0,    0,    0,    0},
    {0x33,    0,  _image1151_size,    0,    0,    0,    0},
    {0x33,    0,  _image1152_size,    0,    0,    0,    0},
    {0x33,    0,  _image1153_size,    0,    0,    0,    0},
    {   0,    0,  _image1154_size,    0,    0,    0,    0},
    {   0,    0,  _image1155_size,    0,    0,    0,    0},
    {0x77,    0,  _image1156_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1157_size,    0,    0,    0,    0},
    {0x66,    0,  _image1158_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1159_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1160_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1161_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1162_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1163_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1164_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1165_size,    0,    0,    0,    0},
    {   0,    0,  _image1166_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1167_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1168_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1169_size,    0,    0,    0,    0},
    {   0,    0,  _image1170_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1171_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1172_size,    0,    0,    0,    0},
    {   0,    0,  _image1173_size,    0,    0,    0,    0},
    {0x11,    0,  _image1174_size,    0,    0,    0,    0},
    {0x11,    0,  _image1175_size,    0,    0,    0,    0},
    {0x11,    0,  _image1176_size,    0,    0,    0,    0},
    {0x33,    0,  _image1177_size,    0,    0,    0,    0},
    {0x33,    0,  _image1178_size,    0,    0,    0,    0},
    {0x33,    0,  _image1179_size,    0,    0,    0,    0},
    {0x33,    0,  _image1180_size,    0,    0,    0,    0},
    {0x33,    0,  _image1181_size,    0,    0,    0,    0},
    {0x33,    0,  _image1182_size,    0,    0,    0,    0},
    {0x33,    0,  _image1183_size,    0,    0,    0,    0},
    {0x33,    0,  _image1184_size,    0,    0,    0,    0},
    {   0,    0,  _image1185_size,    0,    0,    0,    0},
    {   0,    0,  _image1186_size,    0,    0,    0,    0},
    {   0,    0,  _image1187_size,    0,    0,    0,    0},
    {   0,    0,  _image1188_size,    0,    0,    0,    0},
    {   0,    0,  _image1189_size,    0,    0,    0,    0},
    {   0,    0,  _image1190_size,    0,    0,    0,    0},
    {   0,    0,  _image1191_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1192_size,    0,    0,    0,    0},
    {   0,    0,  _image1193_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1194_size,    0,    0,    0,    0},
    {0x33,    0,  _image1195_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1196_size,    0,    0,    0,    0},
    {   0,    0,  _image1197_size,    0,    0,    0,    0},
    {0x33,    0,  _image1198_size,    0,    0,    0,    0},
    {   0,    0,  _image1199_size,    0,    0,    0,    0},
    {   0,    0,  _image1200_size,    0,    0,    0,    0},
    {   0,    0,  _image1201_size,    0,    0,    0,    0},
    {   0,    0,  _image1202_size,    0,    0,    0,    0},
    {0x33,    0,  _image1203_size,    0,    0,    0,    0},
    {0x22,    0,  _image1204_size,    0,    0,    0,    0},
    {0x22,    0,  _image1205_size,    0,    0,    0,    0},
    {0x22,    0,  _image1206_size,    0,    0,    0,    0},
    {   0,    0,  _image1207_size,    0,    0,    0,    0},
    {   0,    0,  _image1208_size,    0,    0,    0,    0},
    {   0,    0,  _image1209_size,    0,    0,    0,    0},
    {   0,    0,  _image1210_size,    0,    0,    0,    0},
    {   0,    0,  _image1211_size,    0,    0,    0,    0},
    {   0,    0,  _image1212_size,    0,    0,    0,    0},
    {   0,    0,  _image1213_size,    0,    0,    0,    0},
    {   0,    0,  _image1214_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1215_size,    0,    0,    0,    0},
    {0x22,    0,  _image1216_size,    0,    0,    0,    0},
    {0x22,    0,  _image1217_size,    0,    0,    0,    0},
    {   0,    0,  _image1218_size,    0,    0,    0,    0},
    {   0,    0,  _image1219_size,    0,    0,    0,    0},
    {   0,    0,  _image1220_size,    0,    0,    0,    0},
    {0x33,    0,  _image1221_size,    0,    0,    0,    0},
    {   0,    0,  _image1222_size,    0,    0,    0,    0},
    {   0,    0,  _image1223_size,    0,    0,    0,    0},
    {   0,    0,  _image1224_size,    0,    0,    0,    0},
    {   0,    0,  _image1225_size,    0,    0,    0,    0},
    {   0,    0,  _image1226_size,    0,    0,    0,    0},
    {   0,    0,  _image1227_size,    0,    0,    0,    0},
    {   0,    0,  _image1228_size,    0,    0,    0,    0},
    {   0,    0,  _image1229_size,    0,    0,    0,    0},
    {   0,    0,  _image1230_size,    0,    0,    0,    0},
    {0x33,    0,  _image1231_size,    0,    0,    0,    0},
    {0x33,    0,  _image1232_size,    0,    0,    0,    0},
    {0x33,    0,  _image1233_size,    0,    0,    0,    0},
    {0x33,    0,  _image1234_size,    0,    0,    0,    0},
    {0x33,    0,  _image1235_size,    0,    0,    0,    0},
    {0x33,    0,  _image1236_size,    0,    0,    0,    0},
    {0x33,    0,  _image1237_size,    0,    0,    0,    0},
    {0x33,    0,  _image1238_size,    0,    0,    0,    0},
    {0x33,    0,  _image1239_size,    0,    0,    0,    0},
    {0x33,    0,  _image1240_size,    0,    0,    0,    0},
    {0x33,    0,  _image1241_size,    0,    0,    0,    0},
    {0x33,    0,  _image1242_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1243_size,    0,    0,    0,    0},
    {0x33,    0,  _image1244_size,    0,    0,    0,    0},
    {0x33,    0,  _image1245_size,    0,    0,    0,    0},
    {0x33,    0,  _image1246_size,    0,    0,    0,    0},
    {0x33,    0,  _image1247_size,    0,    0,    0,    0},
    {   0,    0,  _image1248_size,    0,    0,    0,    0},
    {0x33,    0,  _image1249_size,    0,    0,    0,    0},
    {   0,    0,  _image1250_size,    0,    0,    0,    0},
    {   0,    0,  _image1251_size,    0,    0,    0,    0},
    {   0,    0,  _image1252_size,    0,    0,    0,    0},
    {   0,    0,  _image1253_size,    0,    0,    0,    0},
    {   0,    0,  _image1254_size,    0,    0,    0,    0},
    {   0,    0,  _image1255_size,    0,    0,    0,    0},
    {   0,    0,  _image1256_size,    0,    0,    0,    0},
    {0x22,    0,  _image1257_size,    0,    0,    0,    0},
    {   0,    0,  _image1258_size,    0,    0,    0,    0},
    {   0,    0,  _image1259_size,    0,    0,    0,    0},
    {   0,    0,  _image1260_size,    0,    0,    0,    0},
    {0x44,    0,  _image1261_size,    0,    0,    0,    0},
    {0x22,    0,  _image1262_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1263_size,    0,    0,    0,    0},
    {0x11,    0,  _image1264_size,    0,    0,    0,    0},
    {0x11,    0,  _image1265_size,    0,    0,    0,    0},
    {0x11,    0,  _image1266_size,    0,    0,    0,    0},
    {0x11,    0,  _image1267_size,    0,    0,    0,    0},
    {0x11,    0,  _image1268_size,    0,    0,    0,    0},
    {   0,    0,  _image1269_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1270_size,    0,    0,    0,    0},
    {   0,    0,  _image1271_size,    0,    0,    0,    0},
    {   0,    0,  _image1272_size,    0,    0,    0,    0},
    {   0,    0,  _image1273_size,    0,    0,    0,    0},
    {   0,    0,  _image1274_size,    0,    0,    0,    0},
    {   0,    0,  _image1275_size,    0,    0,    0,    0},
    {   0,    0,  _image1276_size,    0,    0,    0,    0},
    {   0,    0,  _image1277_size,    0,    0,    0,    0},
    {   0,    0,  _image1278_size,    0,    0,    0,    0},
    {   0,    0,  _image1279_size,    0,    0,    0,    0},
    {   0,    0,  _image1280_size,    0,    0,    0,    0},
    {0x11,    0,  _image1281_size,    0,    0,    0,    0},
    {0x22,    0,  _image1282_size,    0,    0,    0,    0},
    {0x22,    0,  _image1283_size,    0,    0,    0,    0},
    {   0,    0,  _image1284_size,    0,    0,    0,    0},
    {   0,    0,  _image1285_size,    0,    0,    0,    0},
    {0x11,    0,  _image1286_size,    0,    0,    0,    0},
    {0x11,    0,  _image1287_size,    0,    0,    0,    0},
    {0x11,    0,  _image1288_size,    0,    0,    0,    0},
    {0x11,    0,  _image1289_size,    0,    0,    0,    0},
    {0x11,    0,  _image1290_size,    0,    0,    0,    0},
    {0x11,    0,  _image1291_size,    0,    0,    0,    0},
    {0x11,    0,  _image1292_size,    0,    0,    0,    0},
    {0x11,    0,  _image1293_size,    0,    0,    0,    0},
    {0x11,    0,  _image1294_size,    0,    0,    0,    0},
    {0x11,    0,  _image1295_size,    0,    0,    0,    0},
    {0x11,    0,  _image1296_size,    0,    0,    0,    0},
    {0x11,    0,  _image1297_size,    0,    0,    0,    0},
    {0x11,    0,  _image1298_size,    0,    0,    0,    0},
    {0x11,    0,  _image1299_size,    0,    0,    0,    0},
    {0x11,    0,  _image1300_size,    0,    0,    0,    0},
    {0x11,    0,  _image1301_size,    0,    0,    0,    0},
    {0x11,    0,  _image1302_size,    0,    0,    0,    0},
    {0x11,    0,  _image1303_size,    0,    0,    0,    0},
    {0x11,    0,  _image1304_size,    0,    0,    0,    0},
    {0x11,    0,  _image1305_size,    0,    0,    0,    0},
    {0x11,    0,  _image1306_size,    0,    0,    0,    0},
    {0x11,    0,  _image1307_size,    0,    0,    0,    0},
    {0x11,    0,  _image1308_size,    0,    0,    0,    0},
    {0x11,    0,  _image1309_size,    0,    0,    0,    0},
    {0x11,    0,  _image1310_size,    0,    0,    0,    0},
    {0x11,    0,  _image1311_size,    0,    0,    0,    0},
    {0x11,    0,  _image1312_size,    0,    0,    0,    0},
    {0x11,    0,  _image1313_size,    0,    0,    0,    0},
    {0x11,    0,  _image1314_size,    0,    0,    0,    0},
    {0x11,    0,  _image1315_size,    0,    0,    0,    0},
    {0x11,    0,  _image1316_size,    0,    0,    0,    0},
    {0x11,    0,  _image1317_size,    0,    0,    0,    0},
    {0x11,    0,  _image1318_size,    0,    0,    0,    0},
    {0x11,    0,  _image1319_size,    0,    0,    0,    0},
    {0x11,    0,  _image1320_size,    0,    0,    0,    0},
    {0x11,    0,  _image1321_size,    0,    0,    0,    0},
    {0x11,    0,  _image1322_size,    0,    0,    0,    0},
    {0x11,    0,  _image1323_size,    0,    0,    0,    0},
    {0x11,    0,  _image1324_size,    0,    0,    0,    0},
    {0x11,    0,  _image1325_size,    0,    0,    0,    0},
    {0x11,    0,  _image1326_size,    0,    0,    0,    0},
    {0x11,    0,  _image1327_size,    0,    0,    0,    0},
    {0x11,    0,  _image1328_size,    0,    0,    0,    0},
    {0x11,    0,  _image1329_size,    0,    0,    0,    0},
    {0x11,    0,  _image1330_size,    0,    0,    0,    0},
    {0x11,    0,  _image1331_size,    0,    0,    0,    0},
    {0x11,    0,  _image1332_size,    0,    0,    0,    0},
    {0x11,    0,  _image1333_size,    0,    0,    0,    0},
    {0x11,    0,  _image1334_size,    0,    0,    0,    0},
    {0x11,    0,  _image1335_size,    0,    0,    0,    0},
    {0x11,    0,  _image1336_size,    0,    0,    0,    0},
    {0x11,    0,  _image1337_size,    0,    0,    0,    0},
    {0x11,    0,  _image1338_size,    0,    0,    0,    0},
    {0x11,    0,  _image1339_size,    0,    0,    0,    0},
    {0x11,    0,  _image1340_size,    0,    0,    0,    0},
    {0x11,    0,  _image1341_size,    0,    0,    0,    0},
    {0x11,    0,  _image1342_size,    0,    0,    0,    0},
    {0x11,    0,  _image1343_size,    0,    0,    0,    0},
    {0x11,    0,  _image1344_size,    0,    0,    0,    0},
    {0x11,    0,  _image1345_size,    0,    0,    0,    0},
    {0x11,    0,  _image1346_size,    0,    0,    0,    0},
    {0x11,    0,  _image1347_size,    0,    0,    0,    0},
    {0x11,    0,  _image1348_size,    0,    0,    0,    0},
    {0x11,    0,  _image1349_size,    0,    0,    0,    0},
    {0x11,    0,  _image1350_size,    0,    0,    0,    0},
    {0x11,    0,  _image1351_size,    0,    0,    0,    0},
    {0x11,    0,  _image1352_size,    0,    0,    0,    0},
    {0x11,    0,  _image1353_size,    0,    0,    0,    0},
    {0x11,    0,  _image1354_size,    0,    0,    0,    0},
    {0x11,    0,  _image1355_size,    0,    0,    0,    0},
    {0x11,    0,  _image1356_size,    0,    0,    0,    0},
    {   0,    0,  _image1357_size,    0,    0,    0,    0},
    {   0,    0,  _image1358_size,    0,    0,    0,    0},
    {0x11,    0,  _image1359_size,    0,    0,    0,    0},
    {0x11,    0,  _image1360_size,    0,    0,    0,    0},
    {0x11,    0,  _image1361_size,    0,    0,    0,    0},
    {0x11,    0,  _image1362_size,    0,    0,    0,    0},
    {0x11,    0,  _image1363_size,    0,    0,    0,    0},
    {0x11,    0,  _image1364_size,    0,    0,    0,    0},
    {0x11,    0,  _image1365_size,    0,    0,    0,    0},
    {   0,    0,  _image1366_size,    0,    0,    0,    0},
    {   0,    0,  _image1367_size,    0,    0,    0,    0},
    {0x33,    0,  _image1368_size,    0,    0,    0,    0},
    {0x33,    0,  _image1369_size,    0,    0,    0,    0},
    {0x33,    0,  _image1370_size,    0,    0,    0,    0},
    {   0,    0,  _image1371_size,    0,    0,    0,    0},
    {   0,    0,  _image1372_size,    0,    0,    0,    0},
    {   0,    0,  _image1373_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1374_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1375_size,    0,    0,    0,    0},
    {0x33,    0,  _image1376_size,    0,    0,    0,    0},
    {0x33,    0,  _image1377_size,    0,    0,    0,    0},
    {   0,    0,  _image1378_size,    0,    0,    0,    0},
    {   0,    0,  _image1379_size,    0,    0,    0,    0},
    {   0,    0,  _image1380_size,    0,    0,    0,    0},
    {   0,    0,  _image1381_size,    0,    0,    0,    0},
    {   0,    0,  _image1382_size,    0,    0,    0,    0},
    {   0,    0,  _image1383_size,    0,    0,    0,    0},
    {0x44,    0,  _image1384_size,    0,    0,    0,    0},
    {   0,    0,  _image1385_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1386_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1387_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1388_size,    0,    0,    0,    0},
    {   0,    0,  _image1389_size,    0,    0,    0,    0},
    {   0,    0,  _image1390_size,    0,    0,    0,    0},
    {   0,    0,  _image1391_size,    0,    0,    0,    0},
    {   0,    0,  _image1392_size,    0,    0,    0,    0},
    {   0,    0,  _image1393_size,    0,    0,    0,    0},
    {   0,    0,  _image1394_size,    0,    0,    0,    0},
    {   0,    0,  _image1395_size,    0,    0,    0,    0},
    {   0,    0,  _image1396_size,    0,    0,    0,    0},
    {   0,    0,  _image1397_size,    0,    0,    0,    0},
    {   0,    0,  _image1398_size,    0,    0,    0,    0},
    {   0,    0,  _image1399_size,    0,    0,    0,    0},
    {   0,    0,  _image1400_size,    0,    0,    0,    0},
    {   0,    0,  _image1401_size,    0,    0,    0,    0},
    {   0,    0,  _image1402_size,    0,    0,    0,    0},
    {   0,    0,  _image1403_size,    0,    0,    0,    0},
    {   0,    0,  _image1404_size,    0,    0,    0,    0},
    {   0,    0,  _image1405_size,    0,    0,    0,    0},
    {   0,    0,  _image1406_size,    0,    0,    0,    0},
    {   0,    0,  _image1407_size,    0,    0,    0,    0},
    {   0,    0,  _image1408_size,    0,    0,    0,    0},
    {   0,    0,  _image1409_size,    0,    0,    0,    0},
    {   0,    0,  _image1410_size,    0,    0,    0,    0},
    {   0,    0,  _image1411_size,    0,    0,    0,    0},
    {   0,    0,  _image1412_size,    0,    0,    0,    0},
    {   0,    0,  _image1413_size,    0,    0,    0,    0},
    {   0,    0,  _image1414_size,    0,    0,    0,    0},
    {   0,    0,  _image1415_size,    0,    0,    0,    0},
    {   0,    0,  _image1416_size,    0,    0,    0,    0},
    {   0,    0,  _image1417_size,    0,    0,    0,    0},
    {   0,    0,  _image1418_size,    0,    0,    0,    0},
    {0x99,    0,  _image1419_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1420_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1421_size,    0,    0,    0,    0},
    {   0,    0,  _image1422_size,    0,    0,    0,    0},
    {   0,    0,  _image1423_size,    0,    0,    0,    0},
    {   0,    0,  _image1424_size,    0,    0,    0,    0},
    {   0,    0,  _image1425_size,    0,    0,    0,    0},
    {   0,    0,  _image1426_size,    0,    0,    0,    0},
    {0x33,    0,  _image1427_size,    0,    0,    0,    0},
    {   0,    0,  _image1428_size,    0,    0,    0,    0},
    {   0,    0,  _image1429_size,    0,    0,    0,    0},
    {   0,    0,  _image1430_size,    0,    0,    0,    0},
    {0x33,    0,  _image1431_size,    0,    0,    0,    0},
    {0x33,    0,  _image1432_size,    0,    0,    0,    0},
    {0x33,    0,  _image1433_size,    0,    0,    0,    0},
    {0x33,    0,  _image1434_size,    0,    0,    0,    0},
    {0x33,    0,  _image1435_size,    0,    0,    0,    0},
    {0x44,    0,  _image1436_size,    0,    0,    0,    0},
    {0x44,    0,  _image1437_size,    0,    0,    0,    0},
    {   0,    0,  _image1438_size,    0,    0,    0,    0},
    {0x33,    0,  _image1439_size,    0,    0,    0,    0},
    {0x22,    0,  _image1440_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1441_size,    0,    0,    0,    0},
    {   0,    0,  _image1442_size,    0,    0,    0,    0},
    {   0,    0,  _image1443_size,    0,    0,    0,    0},
    {   0,    0,  _image1444_size,    0,    0,    0,    0},
    {   0,    0,  _image1445_size,    0,    0,    0,    0},
    {   0,    0,  _image1446_size,    0,    0,    0,    0},
    {   0,    0,  _image1447_size,    0,    0,    0,    0},
    {   0,    0,  _image1448_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1449_size,    0,    0,    0,    0},
    {0x44,    0,  _image1450_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1451_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1452_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1453_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1454_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1455_size,    0,    0,    0,    0},
    {   0,    0,  _image1456_size,    0,    0,    0,    0},
    {   0,    0,  _image1457_size,    0,    0,    0,    0},
    {   0,    0,  _image1458_size,    0,    0,    0,    0},
    {   0,    0,  _image1459_size,    0,    0,    0,    0},
    {   0,    0,  _image1460_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1461_size,    0,    0,    0,    0},
    {0x33,    0,  _image1462_size,    0,    0,    0,    0},
    {0x33,    0,  _image1463_size,    0,    0,    0,    0},
    {0x33,    0,  _image1464_size,    0,    0,    0,    0},
    {0x33,    0,  _image1465_size,    0,    0,    0,    0},
    {0x33,    0,  _image1466_size,    0,    0,    0,    0},
    {   0,    0,  _image1467_size,    0,    0,    0,    0},
    {0x33,    0,  _image1468_size,    0,    0,    0,    0},
    {0x11,    0,  _image1469_size,    0,    0,    0,    0},
    {0x11,    0,  _image1470_size,    0,    0,    0,    0},
    {0x33,    0,  _image1471_size,    0,    0,    0,    0},
    {   0,    0,  _image1472_size,    0,    0,    0,    0},
    {   0,    0,  _image1473_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1474_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1475_size,    0,    0,    0,    0},
    {0x11,    0,  _image1476_size,    0,    0,    0,    0},
    {0x11,    0,  _image1477_size,    0,    0,    0,    0},
    {0x11,    0,  _image1478_size,    0,    0,    0,    0},
    {0x11,    0,  _image1479_size,    0,    0,    0,    0},
    {0x11,    0,  _image1480_size,    0,    0,    0,    0},
    {   0,    0,  _image1481_size,    0,    0,    0,    0},
    {   0,    0,  _image1482_size,    0,    0,    0,    0},
    {   0,    0,  _image1483_size,    0,    0,    0,    0},
    {   0,    0,  _image1484_size,    0,    0,    0,    0},
    {0x11,    0,  _image1485_size,    0,    0,    0,    0},
    {0x11,    0,  _image1486_size,    0,    0,    0,    0},
    {0x11,    0,  _image1487_size,    0,    0,    0,    0},
    {   0,    0,  _image1488_size,    0,    0,    0,    0},
    {   0,    0,  _image1489_size,    0,    0,    0,    0},
    {   0,    0,  _image1490_size,    0,    0,    0,    0},
    {   0,    0,  _image1491_size,    0,    0,    0,    0},
    {   0,    0,  _image1492_size,    0,    0,    0,    0},
    {   0,    0,  _image1493_size,    0,    0,    0,    0},
    {   0,    0,  _image1494_size,    0,    0,    0,    0},
    {   0,    0,  _image1495_size,    0,    0,    0,    0},
    {   0,    0,  _image1496_size,    0,    0,    0,    0},
    {   0,    0,  _image1497_size,    0,    0,    0,    0},
    {   0,    0,  _image1498_size,    0,    0,    0,    0},
    {   0,    0,  _image1499_size,    0,    0,    0,    0},
    {0x22,    0,  _image1500_size,    0,    0,    0,    0},
    {0x22,    0,  _image1501_size,    0,    0,    0,    0},
    {   0,    0,  _image1502_size,    0,    0,    0,    0},
    {   0,    0,  _image1503_size,    0,    0,    0,    0},
    {   0,    0,  _image1504_size,    0,    0,    0,    0},
    {   0,    0,  _image1505_size,    0,    0,    0,    0},
    {   0,    0,  _image1506_size,    0,    0,    0,    0},
    {   0,    0,  _image1507_size,    0,    0,    0,    0},
    {   0,    0,  _image1508_size,    0,    0,    0,    0},
    {0x55,    0,  _image1509_size,    0,    0,    0,    0},
    {0x55,    0,  _image1510_size,    0,    0,    0,    0},
    {0x55,    0,  _image1511_size,    0,    0,    0,    0},
    {0x55,    0,  _image1512_size,    0,    0,    0,    0},
    {0x55,    0,  _image1513_size,    0,    0,    0,    0},
    {   0,    0,  _image1514_size,    0,    0,    0,    0},
    {   0,    0,  _image1515_size,    0,    0,    0,    0},
    {0x44,    0,  _image1516_size,    0,    0,    0,    0},
    {0x44,    0,  _image1517_size,    0,    0,    0,    0},
    {0x44,    0,  _image1518_size,    0,    0,    0,    0},
    {0x44,    0,  _image1519_size,    0,    0,    0,    0},
    {0x44,    0,  _image1520_size,    0,    0,    0,    0},
    {0x44,    0,  _image1521_size,    0,    0,    0,    0},
    {0x44,    0,  _image1522_size,    0,    0,    0,    0},
    {   0,    0,  _image1523_size,    0,    0,    0,    0},
    {0x22,    0,  _image1524_size,    0,    0,    0,    0},
    {0x22,    0,  _image1525_size,    0,    0,    0,    0},
    {0x22,    0,  _image1526_size,    0,    0,    0,    0},
    {0x22,    0,  _image1527_size,    0,    0,    0,    0},
    {0x22,    0,  _image1528_size,    0,    0,    0,    0},
    {0x22,    0,  _image1529_size,    0,    0,    0,    0},
    {0x22,    0,  _image1530_size,    0,    0,    0,    0},
    {0x22,    0,  _image1531_size,    0,    0,    0,    0},
    {0x22,    0,  _image1532_size,    0,    0,    0,    0},
    {0x22,    0,  _image1533_size,    0,    0,    0,    0},
    {0x22,    0,  _image1534_size,    0,    0,    0,    0},
    {0x22,    0,  _image1535_size,    0,    0,    0,    0},
    {0x22,    0,  _image1536_size,    0,    0,    0,    0},
    {0x22,    0,  _image1537_size,    0,    0,    0,    0},
    {0x22,    0,  _image1538_size,    0,    0,    0,    0},
    {0x22,    0,  _image1539_size,    0,    0,    0,    0},
    {0x22,    0,  _image1540_size,    0,    0,    0,    0},
    {0x22,    0,  _image1541_size,    0,    0,    0,    0},
    {   0,    0,  _image1542_size,    0,    0,    0,    0},
    {   0,    0,  _image1543_size,    0,    0,    0,    0},
    {   0,    0,  _image1544_size,    0,    0,    0,    0},
    {   0,    0,  _image1545_size,    0,    0,    0,    0},
    {   0,    0,  _image1546_size,    0,    0,    0,    0},
    {   0,    0,  _image1547_size,    0,    0,    0,    0},
    {   0,    0,  _image1548_size,    0,    0,    0,    0},
    {   0,    0,  _image1549_size,    0,    0,    0,    0},
    {   0,    0,  _image1550_size,    0,    0,    0,    0},
    {   0,    0,  _image1551_size,    0,    0,    0,    0},
    {   0,    0,  _image1552_size,    0,    0,    0,    0},
    {   0,    0,  _image1553_size,    0,    0,    0,    0},
    {   0,    0,  _image1554_size,    0,    0,    0,    0},
    {   0,    0,  _image1555_size,    0,    0,    0,    0},
    {   0,    0,  _image1556_size,    0,    0,    0,    0},
    {   0,    0,  _image1557_size,    0,    0,    0,    0},
    {   0,    0,  _image1558_size,    0,    0,    0,    0},
    {   0,    0,  _image1559_size,    0,    0,    0,    0},
    {   0,    0,  _image1560_size,    0,    0,    0,    0},
    {   0,    0,  _image1561_size,    0,    0,    0,    0},
    {   0,    0,  _image1562_size,    0,    0,    0,    0},
    {   0,    0,  _image1563_size,    0,    0,    0,    0},
    {   0,    0,  _image1564_size,    0,    0,    0,    0},
    {   0,    0,  _image1565_size,    0,    0,    0,    0},
    {   0,    0,  _image1566_size,    0,    0,    0,    0},
    {   0,    0,  _image1567_size,    0,    0,    0,    0},
    {   0,    0,  _image1568_size,    0,    0,    0,    0},
    {   0,    0,  _image1569_size,    0,    0,    0,    0},
    {   0,    0,  _image1570_size,    0,    0,    0,    0},
    {   0,    0,  _image1571_size,    0,    0,    0,    0},
    {   0,    0,  _image1572_size,    0,    0,    0,    0},
    {   0,    0,  _image1573_size,    0,    0,    0,    0},
    {   0,    0,  _image1574_size,    0,    0,    0,    0},
    {   0,    0,  _image1575_size,    0,    0,    0,    0},
    {   0,    0,  _image1576_size,    0,    0,    0,    0},
    {   0,    0,  _image1577_size,    0,    0,    0,    0},
    {   0,    0,  _image1578_size,    0,    0,    0,    0},
    {   0,    0,  _image1579_size,    0,    0,    0,    0},
    {   0,    0,  _image1580_size,    0,    0,    0,    0},
    {   0,    0,  _image1581_size,    0,    0,    0,    0},
    {   0,    0,  _image1582_size,    0,    0,    0,    0},
    {   0,    0,  _image1583_size,    0,    0,    0,    0},
    {   0,    0,  _image1584_size,    0,    0,    0,    0},
    {   0,    0,  _image1585_size,    0,    0,    0,    0},
    {   0,    0,  _image1586_size,    0,    0,    0,    0},
    {   0,    0,  _image1587_size,    0,    0,    0,    0},
    {   0,    0,  _image1588_size,    0,    0,    0,    0},
    {   0,    0,  _image1589_size,    0,    0,    0,    0},
    {   0,    0,  _image1590_size,    0,    0,    0,    0},
    {   0,    0,  _image1591_size,    0,    0,    0,    0},
    {   0,    0,  _image1592_size,    0,    0,    0,    0},
    {   0,    0,  _image1593_size,    0,    0,    0,    0},
    {   0,    0,  _image1594_size,    0,    0,    0,    0},
    {   0,    0,  _image1595_size,    0,    0,    0,    0},
    {   0,    0,  _image1596_size,    0,    0,    0,    0},
    {   0,    0,  _image1597_size,    0,    0,    0,    0},
    {   0,    0,  _image1598_size,    0,    0,    0,    0},
    {   0,    0,  _image1599_size,    0,    0,    0,    0},
    {   0,    0,  _image1600_size,    0,    0,    0,    0},
    {   0,    0,  _image1601_size,    0,    0,    0,    0},
    {   0,    0,  _image1602_size,    0,    0,    0,    0},
    {   0,    0,  _image1603_size,    0,    0,    0,    0},
    {   0,    0,  _image1604_size,    0,    0,    0,    0},
    {   0,    0,  _image1605_size,    0,    0,    0,    0},
    {   0,    0,  _image1606_size,    0,    0,    0,    0},
    {   0,    0,  _image1607_size,    0,    0,    0,    0},
    {   0,    0,  _image1608_size,    0,    0,    0,    0},
    {   0,    0,  _image1609_size,    0,    0,    0,    0},
    {   0,    0,  _image1610_size,    0,    0,    0,    0},
    {   0,    0,  _image1611_size,    0,    0,    0,    0},
    {   0,    0,  _image1612_size,    0,    0,    0,    0},
    {   0,    0,  _image1613_size,    0,    0,    0,    0},
    {   0,    0,  _image1614_size,    0,    0,    0,    0},
    {   0,    0,  _image1615_size,    0,    0,    0,    0},
    {   0,    0,  _image1616_size,    0,    0,    0,    0},
    {   0,    0,  _image1617_size,    0,    0,    0,    0},
    {   0,    0,  _image1618_size,    0,    0,    0,    0},
    {   0,    0,  _image1619_size,    0,    0,    0,    0},
    {   0,    0,  _image1620_size,    0,    0,    0,    0},
    {   0,    0,  _image1621_size,    0,    0,    0,    0},
    {   0,    0,  _image1622_size,    0,    0,    0,    0},
    {   0,    0,  _image1623_size,    0,    0,    0,    0},
    {   0,    0,  _image1624_size,    0,    0,    0,    0},
    {   0,    0,  _image1625_size,    0,    0,    0,    0},
    {   0,    0,  _image1626_size,    0,    0,    0,    0},
    {   0,    0,  _image1627_size,    0,    0,    0,    0},
    {   0,    0,  _image1628_size,    0,    0,    0,    0},
    {   0,    0,  _image1629_size,    0,    0,    0,    0},
    {   0,    0,  _image1630_size,    0,    0,    0,    0},
    {   0,    0,  _image1631_size,    0,    0,    0,    0},
    {   0,    0,  _image1632_size,    0,    0,    0,    0},
    {   0,    0,  _image1633_size,    0,    0,    0,    0},
    {   0,    0,  _image1634_size,    0,    0,    0,    0},
    {   0,    0,  _image1635_size,    0,    0,    0,    0},
    {   0,    0,  _image1636_size,    0,    0,    0,    0},
    {   0,    0,  _image1637_size,    0,    0,    0,    0},
    {   0,    0,  _image1638_size,    0,    0,    0,    0},
    {   0,    0,  _image1639_size,    0,    0,    0,    0},
    {   0,    0,  _image1640_size,    0,    0,    0,    0},
    {   0,    0,  _image1641_size,    0,    0,    0,    0},
    {   0,    0,  _image1642_size,    0,    0,    0,    0},
    {   0,    0,  _image1643_size,    0,    0,    0,    0},
    {   0,    0,  _image1644_size,    0,    0,    0,    0},
    {   0,    0,  _image1645_size,    0,    0,    0,    0},
    {   0,    0,  _image1646_size,    0,    0,    0,    0},
    {   0,    0,  _image1647_size,    0,    0,    0,    0},
    {   0,    0,  _image1648_size,    0,    0,    0,    0},
    {   0,    0,  _image1649_size,    0,    0,    0,    0},
    {   0,    0,  _image1650_size,    0,    0,    0,    0},
    {   0,    0,  _image1651_size,    0,    0,    0,    0},
    {   0,    0,  _image1652_size,    0,    0,    0,    0},
    {0x33,    0,  _image1653_size,    0,    0,    0,    0},
    {   0,    0,  _image1654_size,    0,    0,    0,    0},
    {   0,    0,  _image1655_size,    0,    0,    0,    0},
    {   0,    0,  _image1656_size,    0,    0,    0,    0},
    {   0,    0,  _image1657_size,    0,    0,    0,    0},
    {   0,    0,  _image1658_size,    0,    0,    0,    0},
    {   0,    0,  _image1659_size,    0,    0,    0,    0},
    {   0,    0,  _image1660_size,    0,    0,    0,    0},
    {   0,    0,  _image1661_size,    0,    0,    0,    0},
    {   0,    0,  _image1662_size,    0,    0,    0,    0},
    {   0,    0,  _image1663_size,    0,    0,    0,    0},
    {   0,    0,  _image1664_size,    0,    0,    0,    0},
    {   0,    0,  _image1665_size,    0,    0,    0,    0},
    {   0,    0,  _image1666_size,    0,    0,    0,    0},
    {0x33,    0,  _image1667_size,    0,    0,    0,    0},
    {0x33,    0,  _image1668_size,    0,    0,    0,    0},
    {0xAA,    0,  _image1669_size,    0,    0,    0,    0},
    {0x33,    0,  _image1670_size,    0,    0,    0,    0},
    {0x33,    0,  _image1671_size,    0,    0,    0,    0},
    {   0,    0,  _image1672_size,    0,    0,    0,    0},
    {   0,    0,  _image1673_size,    0,    0,    0,    0},
    {   0,    0,  _image1674_size,    0,    0,    0,    0},
    {   0,    0,  _image1675_size,    0,    0,    0,    0},
    {   0,    0,  _image1676_size,    0,    0,    0,    0},
    {   0,    0,  _image1677_size,    0,    0,    0,    0},
    {   0,    0,  _image1678_size,    0,    0,    0,    0},
    {   0,    0,  _image1679_size,    0,    0,    0,    0},
    {   0,    0,  _image1680_size,    0,    0,    0,    0},
    {   0,    0,  _image1681_size,    0,    0,    0,    0},
    {   0,    0,  _image1682_size,    0,    0,    0,    0},
    {   0,    0,  _image1683_size,    0,    0,    0,    0},
    {   0,    0,  _image1684_size,    0,    0,    0,    0},
    {   0,    0,  _image1685_size,    0,    0,    0,    0},
    {   0,    0,  _image1686_size,    0,    0,    0,    0},
    {   0,    0,  _image1687_size,    0,    0,    0,    0},
    {   0,    0,  _image1688_size,    0,    0,    0,    0},
    {   0,    0,  _image1689_size,    0,    0,    0,    0},
    {   0,    0,  _image1690_size,    0,    0,    0,    0},
    {   0,    0,  _image1691_size,    0,    0,    0,    0},
    {   0,    0,  _image1692_size,    0,    0,    0,    0},
    {   0,    0,  _image1693_size,    0,    0,    0,    0},
    {   0,    0,  _image1694_size,    0,    0,    0,    0},
    {   0,    0,  _image1695_size,    0,    0,    0,    0},
    {   0,    0,  _image1696_size,    0,    0,    0,    0},
    {   0,    0,  _image1697_size,    0,    0,    0,    0},
    {   0,    0,  _image1698_size,    0,    0,    0,    0},
    {   0,    0,  _image1699_size,    0,    0,    0,    0},
    {   0,    0,  _image1700_size,    0,    0,    0,    0},
    {   0,    0,  _image1701_size,    0,    0,    0,    0},
    {   0,    0,  _image1702_size,    0,    0,    0,    0},
    {   0,    0,  _image1703_size,    0,    0,    0,    0},
    {   0,    0,  _image1704_size,    0,    0,    0,    0},
    {   0,    0,  _image1705_size,    0,    0,    0,    0},
    {   0,    0,  _image1706_size,    0,    0,    0,    0},
    {   0,    0,  _image1707_size,    0,    0,    0,    0},
    {   0,    0,  _image1708_size,    0,    0,    0,    0},
    {   0,    0,  _image1709_size,    0,    0,    0,    0},
    {   0,    0,  _image1710_size,    0,    0,    0,    0},
    {   0,    0,  _image1711_size,    0,    0,    0,    0},
    {   0,    0,  _image1712_size,    0,    0,    0,    0},
    {   0,    0,  _image1713_size,    0,    0,    0,    0},
    {   0,    0,  _image1714_size,    0,    0,    0,    0},
    {   0,    0,  _image1715_size,    0,    0,    0,    0},
    {   0,    0,  _image1716_size,    0,    0,    0,    0},
    {   0,    0,  _image1717_size,    0,    0,    0,    0},
    {   0,    0,  _image1718_size,    0,    0,    0,    0},
    {   0,    0,  _image1719_size,    0,    0,    0,    0},
    {   0,    0,  _image1720_size,    0,    0,    0,    0},
    {   0,    0,  _image1721_size,    0,    0,    0,    0},
    {   0,    0,  _image1722_size,    0,    0,    0,    0},
    {   0,    0,  _image1723_size,    0,    0,    0,    0},
    {   0,    0,  _image1724_size,    0,    0,    0,    0},
    {   0,    0,  _image1725_size,    0,    0,    0,    0},
    {   0,    0,  _image1726_size,    0,    0,    0,    0},
    {   0,    0,  _image1727_size,    0,    0,    0,    0},
    {   0,    0,  _image1728_size,    0,    0,    0,    0},
    {   0,    0,  _image1729_size,    0,    0,    0,    0},
    {0x33,    0,  _image1730_size,    0,    0,    0,    0},
    {0x33,    0,  _image1731_size,    0,    0,    0,    0},
    {0x33,    0,  _image1732_size,    0,    0,    0,    0},
    {0x33,    0,  _image1733_size,    0,    0,    0,    0},
    {   0,    0,  _image1734_size,    0,    0,    0,    0},
    {   0,    0,  _image1735_size,    0,    0,    0,    0},
    {   0,    0,  _image1736_size,    0,    0,    0,    0},
    {   0,    0,  _image1737_size,    0,    0,    0,    0},
    {   0,    0,  _image1738_size,    0,    0,    0,    0},
    {   0,    0,  _image1739_size,    0,    0,    0,    0},
    {   0,    0,  _image1740_size,    0,    0,    0,    0},
    {   0,    0,  _image1741_size,    0,    0,    0,    0},
    {   0,    0,  _image1742_size,    0,    0,    0,    0},
    {   0,    0,  _image1743_size,    0,    0,    0,    0},
    {   0,    0,  _image1744_size,    0,    0,    0,    0},
    {   0,    0,  _image1745_size,    0,    0,    0,    0},
    {   0,    0,  _image1746_size,    0,    0,    0,    0},
    {   0,    0,  _image1747_size,    0,    0,    0,    0},
    {   0,    0,  _image1748_size,    0,    0,    0,    0},
    {   0,    0,  _image1749_size,    0,    0,    0,    0},
    {   0,    0,  _image1750_size,    0,    0,    0,    0},
    {   0,    0,  _image1751_size,    0,    0,    0,    0},
    {   0,    0,  _image1752_size,    0,    0,    0,    0},
    {   0,    0,  _image1753_size,    0,    0,    0,    0},
    {   0,    0,  _image1754_size,    0,    0,    0,    0},
    {   0,    0,  _image1755_size,    0,    0,    0,    0},
    {   0,    0,  _image1756_size,    0,    0,    0,    0},
    {   0,    0,  _image1757_size,    0,    0,    0,    0},
    {   0,    0,  _image1758_size,    0,    0,    0,    0},
    {   0,    0,  _image1759_size,    0,    0,    0,    0},
    {   0,    0,  _image1760_size,    0,    0,    0,    0},
    {   0,    0,  _image1761_size,    0,    0,    0,    0},
    {   0,    0,  _image1762_size,    0,    0,    0,    0},
    {   0,    0,  _image1763_size,    0,    0,    0,    0},
    {   0,    0,  _image1764_size,    0,    0,    0,    0},
    {   0,    0,  _image1765_size,    0,    0,    0,    0},
    {   0,    0,  _image1766_size,    0,    0,    0,    0},
    {   0,    0,  _image1767_size,    0,    0,    0,    0},
    {   0,    0,  _image1768_size,    0,    0,    0,    0},
    {   0,    0,  _image1769_size,    0,    0,    0,    0},
    {   0,    0,  _image1770_size,    0,    0,    0,    0},
    {   0,    0,  _image1771_size,    0,    0,    0,    0},
    {   0,    0,  _image1772_size,    0,    0,    0,    0},
    {   0,    0,  _image1773_size,    0,    0,    0,    0},
    {   0,    0,  _image1774_size,    0,    0,    0,    0},
    {   0,    0,  _image1775_size,    0,    0,    0,    0},
    {   0,    0,  _image1776_size,    0,    0,    0,    0},
    {   0,    0,  _image1777_size,    0,    0,    0,    0},
    {   0,    0,  _image1778_size,    0,    0,    0,    0},
    {   0,    0,  _image1779_size,    0,    0,    0,    0},
    {   0,    0,  _image1780_size,    0,    0,    0,    0},
    {   0,    0,  _image1781_size,    0,    0,    0,    0},
    {   0,    0,  _image1782_size,    0,    0,    0,    0},
    {   0,    0,  _image1783_size,    0,    0,    0,    0},
    {   0,    0,  _image1784_size,    0,    0,    0,    0},
    {   0,    0,  _image1785_size,    0,    0,    0,    0},
    {   0,    0,  _image1786_size,    0,    0,    0,    0},
    {   0,    0,  _image1787_size,    0,    0,    0,    0},
    {   0,    0,  _image1788_size,    0,    0,    0,    0},
    {   0,    0,  _image1789_size,    0,    0,    0,    0},
    {   0,    0,  _image1790_size,    0,    0,    0,    0},
    {   0,    0,  _image1791_size,    0,    0,    0,    0},
    {   0,    0,  _image1792_size,    0,    0,    0,    0},
    {   0,    0,  _image1793_size,    0,    0,    0,    0},
    {   0,    0,  _image1794_size,    0,    0,    0,    0},
    {   0,    0,  _image1795_size,    0,    0,    0,    0},
    {   0,    0,  _image1796_size,    0,    0,    0,    0},
    {   0,    0,  _image1797_size,    0,    0,    0,    0},
    {   0,    0,  _image1798_size,    0,    0,    0,    0},
    {   0,    0,  _image1799_size,    0,    0,    0,    0},
    {   0,    0,  _image1800_size,    0,    0,    0,    0},
    {   0,    0,  _image1801_size,    0,    0,    0,    0},
    {   0,    0,  _image1802_size,    0,    0,    0,    0},
    {   0,    0,  _image1803_size,    0,    0,    0,    0},
    {   0,    0,  _image1804_size,    0,    0,    0,    0},
    {   0,    0,  _image1805_size,    0,    0,    0,    0},
    {   0,    0,  _image1806_size,    0,    0,    0,    0},
    {   0,    0,  _image1807_size,    0,    0,    0,    0},
    {   0,    0,  _image1808_size,    0,    0,    0,    0},
    {   0,    0,  _image1809_size,    0,    0,    0,    0},
    {   0,    0,  _image1810_size,    0,    0,    0,    0},
    {   0,    0,  _image1811_size,    0,    0,    0,    0},
    {   0,    0,  _image1812_size,    0,    0,    0,    0},
    {   0,    0,  _image1813_size,    0,    0,    0,    0},
    {   0,    0,  _image1814_size,    0,    0,    0,    0},
    {   0,    0,  _image1815_size,    0,    0,    0,    0},
    {   0,    0,  _image1816_size,    0,    0,    0,    0},
    {   0,    0,  _image1817_size,    0,    0,    0,    0},
    {   0,    0,  _image1818_size,    0,    0,    0,    0},
    {   0,    0,  _image1819_size,    0,    0,    0,    0},
    {   0,    0,  _image1820_size,    0,    0,    0,    0},
    {   0,    0,  _image1821_size,    0,    0,    0,    0},
    {   0,    0,  _image1822_size,    0,    0,    0,    0},
    {   0,    0,  _image1823_size,    0,    0,    0,    0},
    {   0,    0,  _image1824_size,    0,    0,    0,    0},
    {   0,    0,  _image1825_size,    0,    0,    0,    0},
    {   0,    0,  _image1826_size,    0,    0,    0,    0},
    {   0,    0,  _image1827_size,    0,    0,    0,    0},
    {   0,    0,  _image1828_size,    0,    0,    0,    0},
    {   0,    0,  _image1829_size,    0,    0,    0,    0},
    {   0,    0,  _image1830_size,    0,    0,    0,    0},
    {   0,    0,  _image1831_size,    0,    0,    0,    0},
    {   0,    0,  _image1832_size,    0,    0,    0,    0},
    {   0,    0,  _image1833_size,    0,    0,    0,    0},
    {   0,    0,  _image1834_size,    0,    0,    0,    0},
    {   0,    0,  _image1835_size,    0,    0,    0,    0},
    {   0,    0,  _image1836_size,    0,    0,    0,    0},
    {   0,    0,  _image1837_size,    0,    0,    0,    0},
    {   0,    0,  _image1838_size,    0,    0,    0,    0},
    {   0,    0,  _image1839_size,    0,    0,    0,    0},
    {   0,    0,  _image1840_size,    0,    0,    0,    0},
    {   0,    0,  _image1841_size,    0,    0,    0,    0},
    {   0,    0,  _image1842_size,    0,    0,    0,    0},
    {   0,    0,  _image1843_size,    0,    0,    0,    0},
    {   0,    0,  _image1844_size,    0,    0,    0,    0},
    {   0,    0,  _image1845_size,    0,    0,    0,    0},
    {   0,    0,  _image1846_size,    0,    0,    0,    0},
    {   0,    0,  _image1847_size,    0,    0,    0,    0},
    {   0,    0,  _image1848_size,    0,    0,    0,    0},
    {   0,    0,  _image1849_size,    0,    0,    0,    0},
    {   0,    0,  _image1850_size,    0,    0,    0,    0},
    {   0,    0,  _image1851_size,    0,    0,    0,    0},
    {   0,    0,  _image1852_size,    0,    0,    0,    0},
    {   0,    0,  _image1853_size,    0,    0,    0,    0},
    {   0,    0,  _image1854_size,    0,    0,    0,    0},
    {   0,    0,  _image1855_size,    0,    0,    0,    0},
    {   0,    0,  _image1856_size,    0,    0,    0,    0},
    {   0,    0,  _image1857_size,    0,    0,    0,    0},
    {   0,    0,  _image1858_size,    0,    0,    0,    0},
    {   0,    0,  _image1859_size,    0,    0,    0,    0},
    {   0,    0,  _image1860_size,    0,    0,    0,    0},
    {   0,    0,  _image1861_size,    0,    0,    0,    0},
    {   0,    0,  _image1862_size,    0,    0,    0,    0},
    {   0,    0,  _image1863_size,    0,    0,    0,    0},
    {   0,    0,  _image1864_size,    0,    0,    0,    0},
    {   0,    0,  _image1865_size,    0,    0,    0,    0},
    {   0,    0,  _image1866_size,    0,    0,    0,    0},
    {   0,    0,  _image1867_size,    0,    0,    0,    0},
    {   0,    0,  _image1868_size,    0,    0,    0,    0},
    {   0,    0,  _image1869_size,    0,    0,    0,    0},
    {   0,    0,  _image1870_size,    0,    0,    0,    0},
    {   0,    0,  _image1871_size,    0,    0,    0,    0},
    {   0,    0,  _image1872_size,    0,    0,    0,    0},
    {   0,    0,  _image1873_size,    0,    0,    0,    0},
    {   0,    0,  _image1874_size,    0,    0,    0,    0},
    {   0,    0,  _image1875_size,    0,    0,    0,    0},
    {   0,    0,  _image1876_size,    0,    0,    0,    0},
    {   0,    0,  _image1877_size,    0,    0,    0,    0},
    {   0,    0,  _image1878_size,    0,    0,    0,    0},
    {   0,    0,  _image1879_size,    0,    0,    0,    0},
    {   0,    0,  _image1880_size,    0,    0,    0,    0},
    {   0,    0,  _image1881_size,    0,    0,    0,    0},
    {   0,    0,  _image1882_size,    0,    0,    0,    0},
    {   0,    0,  _image1883_size,    0,    0,    0,    0},
    {   0,    0,  _image1884_size,    0,    0,    0,    0},
    {   0,    0,  _image1885_size,    0,    0,    0,    0},
    {   0,    0,  _image1886_size,    0,    0,    0,    0},
    {   0,    0,  _image1887_size,    0,    0,    0,    0},
    {   0,    0,  _image1888_size,    0,    0,    0,    0},
    {   0,    0,  _image1889_size,    0,    0,    0,    0},
    {   0,    0,  _image1890_size,    0,    0,    0,    0},
    {   0,    0,  _image1891_size,    0,    0,    0,    0},
    {   0,    0,  _image1892_size,    0,    0,    0,    0},
    {   0,    0,  _image1893_size,    0,    0,    0,    0},
    {   0,    0,  _image1894_size,    0,    0,    0,    0},
    {   0,    0,  _image1895_size,    0,    0,    0,    0},
    {   0,    0,  _image1896_size,    0,    0,    0,    0},
    {   0,    0,  _image1897_size,    0,    0,    0,    0},
    {   0,    0,  _image1898_size,    0,    0,    0,    0},
    {   0,    0,  _image1899_size,    0,    0,    0,    0},
    {   0,    0,  _image1900_size,    0,    0,    0,    0},
    {   0,    0,  _image1901_size,    0,    0,    0,    0},
    {   0,    0,  _image1902_size,    0,    0,    0,    0},
    {   0,    0,  _image1903_size,    0,    0,    0,    0},
    {   0,    0,  _image1904_size,    0,    0,    0,    0},
    {   0,    0,  _image1905_size,    0,    0,    0,    0},
    {   0,    0,  _image1906_size,    0,    0,    0,    0},
    {   0,    0,  _image1907_size,    0,    0,    0,    0},
    {   0,    0,  _image1908_size,    0,    0,    0,    0},
    {   0,    0,  _image1909_size,    0,    0,    0,    0},
    {   0,    0,  _image1910_size,    0,    0,    0,    0},
    {   0,    0,  _image1911_size,    0,    0,    0,    0},
    {   0,    0,  _image1912_size,    0,    0,    0,    0},
    {   0,    0,  _image1913_size,    0,    0,    0,    0},
    {   0,    0,  _image1914_size,    0,    0,    0,    0},
    {   0,    0,  _image1915_size,    0,    0,    0,    0},
    {   0,    0,  _image1916_size,    0,    0,    0,    0},
    {   0,    0,  _image1917_size,    0,    0,    0,    0},
    {   0,    0,  _image1918_size,    0,    0,    0,    0},
    {   0,    0,  _image1919_size,    0,    0,    0,    0},
    {   0,    0,  _image1920_size,    0,    0,    0,    0},
    {   0,    0,  _image1921_size,    0,    0,    0,    0},
    {   0,    0,  _image1922_size,    0,    0,    0,    0},
    {   0,    0,  _image1923_size,    0,    0,    0,    0},
    {   0,    0,  _image1924_size,    0,    0,    0,    0},
    {   0,    0,  _image1925_size,    0,    0,    0,    0},
    {   0,    0,  _image1926_size,    0,    0,    0,    0},
    {   0,    0,  _image1927_size,    0,    0,    0,    0},
    {   0,    0,  _image1928_size,    0,    0,    0,    0},
    {   0,    0,  _image1929_size,    0,    0,    0,    0},
    {   0,    0,  _image1930_size,    0,    0,    0,    0},
    {   0,    0,  _image1931_size,    0,    0,    0,    0},
    {   0,    0,  _image1932_size,    0,    0,    0,    0},
    {   0,    0,  _image1933_size,    0,    0,    0,    0},
    {   0,    0,  _image1934_size,    0,    0,    0,    0},
    {   0,    0,  _image1935_size,    0,    0,    0,    0},
    {   0,    0,  _image1936_size,    0,    0,    0,    0},
    {   0,    0,  _image1937_size,    0,    0,    0,    0},
    {   0,    0,  _image1938_size,    0,    0,    0,    0},
    {   0,    0,  _image1939_size,    0,    0,    0,    0},
    {   0,    0,  _image1940_size,    0,    0,    0,    0},
    {   0,    0,  _image1941_size,    0,    0,    0,    0},
    {   0,    0,  _image1942_size,    0,    0,    0,    0},
    {   0,    0,  _image1943_size,    0,    0,    0,    0},
    {   0,    0,  _image1944_size,    0,    0,    0,    0},
    {   0,    0,  _image1945_size,    0,    0,    0,    0},
    {   0,    0,  _image1946_size,    0,    0,    0,    0},
    {   0,    0,  _image1947_size,    0,    0,    0,    0},
    {   0,    0,  _image1948_size,    0,    0,    0,    0},
    {   0,    0,  _image1949_size,    0,    0,    0,    0},
    {   0,    0,  _image1950_size,    0,    0,    0,    0},
    {   0,    0,  _image1951_size,    0,    0,    0,    0},
    {   0,    0,  _image1952_size,    0,    0,    0,    0},
    {   0,    0,  _image1953_size,    0,    0,    0,    0},
    {   0,    0,  _image1954_size,    0,    0,    0,    0},
    {   0,    0,  _image1955_size,    0,    0,    0,    0},
    {   0,    0,  _image1956_size,    0,    0,    0,    0},
    {   0,    0,  _image1957_size,    0,    0,    0,    0},
    {   0,    0,  _image1958_size,    0,    0,    0,    0},
    {   0,    0,  _image1959_size,    0,    0,    0,    0},
    {   0,    0,  _image1960_size,    0,    0,    0,    0},
    {   0,    0,  _image1961_size,    0,    0,    0,    0},
    {   0,    0,  _image1962_size,    0,    0,    0,    0},
    {   0,    0,  _image1963_size,    0,    0,    0,    0},
    {   0,    0,  _image1964_size,    0,    0,    0,    0},
    {   0,    0,  _image1965_size,    0,    0,    0,    0},
    {   0,    0,  _image1966_size,    0,    0,    0,    0},
    {   0,    0,  _image1967_size,    0,    0,    0,    0},
    {   0,    0,  _image1968_size,    0,    0,    0,    0},
    {   0,    0,  _image1969_size,    0,    0,    0,    0},
    {   0,    0,  _image1970_size,    0,    0,    0,    0},
    {   0,    0,  _image1971_size,    0,    0,    0,    0},
    {   0,    0,  _image1972_size,    0,    0,    0,    0},
    {   0,    0,  _image1973_size,    0,    0,    0,    0},
    {   0,    0,  _image1974_size,    0,    0,    0,    0},
    {   0,    0,  _image1975_size,    0,    0,    0,    0},
    {   0,    0,  _image1976_size,    0,    0,    0,    0},
    {   0,    0,  _image1977_size,    0,    0,    0,    0},
    {   0,    0,  _image1978_size,    0,    0,    0,    0},
    {   0,    0,  _image1979_size,    0,    0,    0,    0},
    {   0,    0,  _image1980_size,    0,    0,    0,    0},
    {   0,    0,  _image1981_size,    0,    0,    0,    0},
    {   0,    0,  _image1982_size,    0,    0,    0,    0},
    {   0,    0,  _image1983_size,    0,    0,    0,    0},
    {   0,    0,  _image1984_size,    0,    0,    0,    0},
    {   0,    0,  _image1985_size,    0,    0,    0,    0},
    {   0,    0,  _image1986_size,    0,    0,    0,    0},
    {   0,    0,  _image1987_size,    0,    0,    0,    0},
    {   0,    0,  _image1988_size,    0,    0,    0,    0},
    {   0,    0,  _image1989_size,    0,    0,    0,    0},
    {   0,    0,  _image1990_size,    0,    0,    0,    0},
    {   0,    0,  _image1991_size,    0,    0,    0,    0},
    {   0,    0,  _image1992_size,    0,    0,    0,    0},
    {   0,    0,  _image1993_size,    0,    0,    0,    0},
    {   0,    0,  _image1994_size,    0,    0,    0,    0},
    {   0,    0,  _image1995_size,    0,    0,    0,    0},
    {   0,    0,  _image1996_size,    0,    0,    0,    0},
    {   0,    0,  _image1997_size,    0,    0,    0,    0},
    {   0,    0,  _image1998_size,    0,    0,    0,    0},
    {   0,    0,  _image1999_size,    0,    0,    0,    0},
    {   0,    0,  _image2000_size,    0,    0,    0,    0},
    {   0,    0,  _image2001_size,    0,    0,    0,    0},
    {   0,    0,  _image2002_size,    0,    0,    0,    0},
    {   0,    0,  _image2003_size,    0,    0,    0,    0},
    {   0,    0,  _image2004_size,    0,    0,    0,    0},
    {   0,    0,  _image2005_size,    0,    0,    0,    0},
    {   0,    0,  _image2006_size,    0,    0,    0,    0},
    {   0,    0,  _image2007_size,    0,    0,    0,    0},
    {   0,    0,  _image2008_size,    0,    0,    0,    0},
    {   0,    0,  _image2009_size,    0,    0,    0,    0},
    {   0,    0,  _image2010_size,    0,    0,    0,    0},
    {   0,    0,  _image2011_size,    0,    0,    0,    0},
    {   0,    0,  _image2012_size,    0,    0,    0,    0},
    {   0,    0,  _image2013_size,    0,    0,    0,    0},
    {   0,    0,  _image2014_size,    0,    0,    0,    0},
    {   0,    0,  _image2015_size,    0,    0,    0,    0},
    {   0,    0,  _image2016_size,    0,    0,    0,    0},
    {   0,    0,  _image2017_size,    0,    0,    0,    0},
    {   0,    0,  _image2018_size,    0,    0,    0,    0},
    {   0,    0,  _image2019_size,    0,    0,    0,    0},
    {   0,    0,  _image2020_size,    0,    0,    0,    0},
    {   0,    0,  _image2021_size,    0,    0,    0,    0},
    {   0,    0,  _image2022_size,    0,    0,    0,    0},
    {   0,    0,  _image2023_size,    0,    0,    0,    0},
    {   0,    0,  _image2024_size,    0,    0,    0,    0},
    {   0,    0,  _image2025_size,    0,    0,    0,    0},
    {   0,    0,  _image2026_size,    0,    0,    0,    0},
    {   0,    0,  _image2027_size,    0,    0,    0,    0},
    {   0,    0,  _image2028_size,    0,    0,    0,    0},
    {   0,    0,  _image2029_size,    0,    0,    0,    0},
    {   0,    0,  _image2030_size,    0,    0,    0,    0},
    {   0,    0,  _image2031_size,    0,    0,    0,    0},
    {   0,    0,  _image2032_size,    0,    0,    0,    0},
    {   0,    0,  _image2033_size,    0,    0,    0,    0},
    {   0,    0,  _image2034_size,    0,    0,    0,    0},
    {   0,    0,  _image2035_size,    0,    0,    0,    0},
    {   0,    0,  _image2036_size,    0,    0,    0,    0},
    {   0,    0,  _image2037_size,    0,    0,    0,    0},
    {   0,    0,  _image2038_size,    0,    0,    0,    0},
    {   0,    0,  _image2039_size,    0,    0,    0,    0},
    {   0,    0,  _image2040_size,    0,    0,    0,    0},
    {   0,    0,  _image2041_size,    0,    0,    0,    0},
    {   0,    0,  _image2042_size,    0,    0,    0,    0},
    {   0,    0,  _image2043_size,    0,    0,    0,    0},
    {   0,    0,  _image2044_size,    0,    0,    0,    0},
    {   0,    0,  _image2045_size,    0,    0,    0,    0},
    {   0,    0,  _image2046_size,    0,    0,    0,    0},
    {   0,    0,  _image2047_size,    0,    0,    0,    0},
    {   0,    0,  _image2048_size,    0,    0,    0,    0},
    {   0,    0,  _image2049_size,    0,    0,    0,    0},
    {   0,    0,  _image2050_size,    0,    0,    0,    0},
    {   0,    0,  _image2051_size,    0,    0,    0,    0},
    {   0,    0,  _image2052_size,    0,    0,    0,    0},
    {   0,    0,  _image2053_size,    0,    0,    0,    0},
    {   0,    0,  _image2054_size,    0,    0,    0,    0},
    {   0,    0,  _image2055_size,    0,    0,    0,    0},
    {   0,    0,  _image2056_size,    0,    0,    0,    0},
    {   0,    0,  _image2057_size,    0,    0,    0,    0},
    {   0,    0,  _image2058_size,    0,    0,    0,    0},
    {   0,    0,  _image2059_size,    0,    0,    0,    0},
    {   0,    0,  _image2060_size,    0,    0,    0,    0},
    {   0,    0,  _image2061_size,    0,    0,    0,    0},
    {   0,    0,  _image2062_size,    0,    0,    0,    0},
    {   0,    0,  _image2063_size,    0,    0,    0,    0},
    {   0,    0,  _image2064_size,    0,    0,    0,    0},
    {   0,    0,  _image2065_size,    0,    0,    0,    0},
    {   0,    0,  _image2066_size,    0,    0,    0,    0},
    {   0,    0,  _image2067_size,    0,    0,    0,    0},
    {   0,    0,  _image2068_size,    0,    0,    0,    0},
    {   0,    0,  _image2069_size,    0,    0,    0,    0},
    {   0,    0,  _image2070_size,    0,    0,    0,    0},
    {   0,    0,  _image2071_size,    0,    0,    0,    0},
    {   0,    0,  _image2072_size,    0,    0,    0,    0},
    {   0,    0,  _image2073_size,    0,    0,    0,    0},
    {   0,    0,  _image2074_size,    0,    0,    0,    0},
    {   0,    0,  _image2075_size,    0,    0,    0,    0},
    {   0,    0,  _image2076_size,    0,    0,    0,    0},
    {   0,    0,  _image2077_size,    0,    0,    0,    0},
    {   0,    0,  _image2078_size,    0,    0,    0,    0},
    {   0,    0,  _image2079_size,    0,    0,    0,    0},
    {   0,    0,  _image2080_size,    0,    0,    0,    0},
    {   0,    0,  _image2081_size,    0,    0,    0,    0},
    {   0,    0,  _image2082_size,    0,    0,    0,    0},
    {   0,    0,  _image2083_size,    0,    0,    0,    0},
    {   0,    0,  _image2084_size,    0,    0,    0,    0},
    {   0,    0,  _image2085_size,    0,    0,    0,    0},
    {   0,    0,  _image2086_size,    0,    0,    0,    0},
    {   0,    0,  _image2087_size,    0,    0,    0,    0},
    {   0,    0,  _image2088_size,    0,    0,    0,    0},
    {   0,    0,  _image2089_size,    0,    0,    0,    0},
    {   0,    0,  _image2090_size,    0,    0,    0,    0},
    {   0,    0,  _image2091_size,    0,    0,    0,    0},
    {   0,    0,  _image2092_size,    0,    0,    0,    0},
    {   0,    0,  _image2093_size,    0,    0,    0,    0},
    {   0,    0,  _image2094_size,    0,    0,    0,    0},
    {   0,    0,  _image2095_size,    0,    0,    0,    0},
    {   0,    0,  _image2096_size,    0,    0,    0,    0},
    {   0,    0,  _image2097_size,    0,    0,    0,    0},
    {   0,    0,  _image2098_size,    0,    0,    0,    0},
    {   0,    0,  _image2099_size,    0,    0,    0,    0},
    {   0,    0,  _image2100_size,    0,    0,    0,    0},
    {   0,    0,  _image2101_size,    0,    0,    0,    0},
    {   0,    0,  _image2102_size,    0,    0,    0,    0},
    {   0,    0,  _image2103_size,    0,    0,    0,    0},
    {   0,    0,  _image2104_size,    0,    0,    0,    0},
    {   0,    0,  _image2105_size,    0,    0,    0,    0},
    {   0,    0,  _image2106_size,    0,    0,    0,    0},
    {   0,    0,  _image2107_size,    0,    0,    0,    0},
    {   0,    0,  _image2108_size,    0,    0,    0,    0},
    {   0,    0,  _image2109_size,    0,    0,    0,    0},
    {   0,    0,  _image2110_size,    0,    0,    0,    0},
    {   0,    0,  _image2111_size,    0,    0,    0,    0},
    {   0,    0,  _image2112_size,    0,    0,    0,    0},
    {   0,    0,  _image2113_size,    0,    0,    0,    0},
    {   0,    0,  _image2114_size,    0,    0,    0,    0},
    {   0,    0,  _image2115_size,    0,    0,    0,    0},
    {   0,    0,  _image2116_size,    0,    0,    0,    0},
    {   0,    0,  _image2117_size,    0,    0,    0,    0},
    {   0,    0,  _image2118_size,    0,    0,    0,    0},
    {   0,    0,  _image2119_size,    0,    0,    0,    0},
    {   0,    0,  _image2120_size,    0,    0,    0,    0},
    {   0,    0,  _image2121_size,    0,    0,    0,    0},
    {   0,    0,  _image2122_size,    0,    0,    0,    0},
    {   0,    0,  _image2123_size,    0,    0,    0,    0},
    {   0,    0,  _image2124_size,    0,    0,    0,    0},
    {   0,    0,  _image2125_size,    0,    0,    0,    0},
    {   0,    0,  _image2126_size,    0,    0,    0,    0},
    {   0,    0,  _image2127_size,    0,    0,    0,    0},
    {   0,    0,  _image2128_size,    0,    0,    0,    0},
    {   0,    0,  _image2129_size,    0,    0,    0,    0},
    {   0,    0,  _image2130_size,    0,    0,    0,    0},
    {   0,    0,  _image2131_size,    0,    0,    0,    0},
    {   0,    0,  _image2132_size,    0,    0,    0,    0},
    {   0,    0,  _image2133_size,    0,    0,    0,    0},
    {   0,    0,  _image2134_size,    0,    0,    0,    0},
    {   0,    0,  _image2135_size,    0,    0,    0,    0},
    {   0,    0,  _image2136_size,    0,    0,    0,    0},
    {   0,    0,  _image2137_size,    0,    0,    0,    0},
    {   0,    0,  _image2138_size,    0,    0,    0,    0},
    {   0,    0,  _image2139_size,    0,    0,    0,    0},
    {   0,    0,  _image2140_size,    0,    0,    0,    0},
    {   0,    0,  _image2141_size,    0,    0,    0,    0},
    {   0,    0,  _image2142_size,    0,    0,    0,    0},
    {   0,    0,  _image2143_size,    0,    0,    0,    0},
    {   0,    0,  _image2144_size,    0,    0,    0,    0},
    {   0,    0,  _image2145_size,    0,    0,    0,    0},
    {   0,    0,  _image2146_size,    0,    0,    0,    0},
    {   0,    0,  _image2147_size,    0,    0,    0,    0},
    {   0,    0,  _image2148_size,    0,    0,    0,    0},
    {   0,    0,  _image2149_size,    0,    0,    0,    0},
    {   0,    0,  _image2150_size,    0,    0,    0,    0},
    {   0,    0,  _image2151_size,    0,    0,    0,    0},
    {   0,    0,  _image2152_size,    0,    0,    0,    0},
    {   0,    0,  _image2153_size,    0,    0,    0,    0},
    {   0,    0,  _image2154_size,    0,    0,    0,    0},
    {   0,    0,  _image2155_size,    0,    0,    0,    0},
    {   0,    0,  _image2156_size,    0,    0,    0,    0},
    {   0,    0,  _image2157_size,    0,    0,    0,    0},
    {   0,    0,  _image2158_size,    0,    0,    0,    0},
    {   0,    0,  _image2159_size,    0,    0,    0,    0},
    {   0,    0,  _image2160_size,    0,    0,    0,    0},
    {   0,    0,  _image2161_size,    0,    0,    0,    0},
    {   0,    0,  _image2162_size,    0,    0,    0,    0},
    {   0,    0,  _image2163_size,    0,    0,    0,    0},
    {   0,    0,  _image2164_size,    0,    0,    0,    0},
    {   0,    0,  _image2165_size,    0,    0,    0,    0},
    {   0,    0,  _image2166_size,    0,    0,    0,    0},
    {   0,    0,  _image2167_size,    0,    0,    0,    0},
    {   0,    0,  _image2168_size,    0,    0,    0,    0},
    {   0,    0,  _image2169_size,    0,    0,    0,    0},
    {   0,    0,  _image2170_size,    0,    0,    0,    0},
    {   0,    0,  _image2171_size,    0,    0,    0,    0},
    {   0,    0,  _image2172_size,    0,    0,    0,    0},
    {   0,    0,  _image2173_size,    0,    0,    0,    0},
    {0x11,    0,  _image2174_size,    0,    0,    0,    0},
    {0x11,    0,  _image2175_size,    0,    0,    0,    0},
    {0x11,    0,  _image2176_size,    0,    0,    0,    0},
    {   0,    0,  _image2177_size,    0,    0,    0,    0},
    {   0,    0,  _image2178_size,    0,    0,    0,    0},
    {   0,    0,  _image2179_size,    0,    0,    0,    0},
    {   0,    0,  _image2180_size,    0,    0,    0,    0},
    {   0,    0,  _image2181_size,    0,    0,    0,    0},
    {   0,    0,  _image2182_size,    0,    0,    0,    0},
    {   0,    0,  _image2183_size,    0,    0,    0,    0},
    {   0,    0,  _image2184_size,    0,    0,    0,    0},
    {   0,    0,  _image2185_size,    0,    0,    0,    0},
    {   0,    0,  _image2186_size,    0,    0,    0,    0},
    {   0,    0,  _image2187_size,    0,    0,    0,    0},
    {   0,    0,  _image2188_size,    0,    0,    0,    0},
    {   0,    0,  _image2189_size,    0,    0,    0,    0},
    {   0,    0,  _image2190_size,    0,    0,    0,    0},
    {   0,    0,  _image2191_size,    0,    0,    0,    0},
    {   0,    0,  _image2192_size,    0,    0,    0,    0},
    {   0,    0,  _image2193_size,    0,    0,    0,    0},
    {   0,    0,  _image2194_size,    0,    0,    0,    0},
    {   0,    0,  _image2195_size,    0,    0,    0,    0},
    {   0,    0,  _image2196_size,    0,    0,    0,    0},
    {   0,    0,  _image2197_size,    0,    0,    0,    0},
    {   0,    0,  _image2198_size,    0,    0,    0,    0},
    {   0,    0,  _image2199_size,    0,    0,    0,    0},
    {   0,    0,  _image2200_size,    0,    0,    0,    0},
    {   0,    0,  _image2201_size,    0,    0,    0,    0},
    {   0,    0,  _image2202_size,    0,    0,    0,    0},
    {   0,    0,  _image2203_size,    0,    0,    0,    0},
    {   0,    0,  _image2204_size,    0,    0,    0,    0},
    {   0,    0,  _image2205_size,    0,    0,    0,    0},
    {   0,    0,  _image2206_size,    0,    0,    0,    0},
    {   0,    0,  _image2207_size,    0,    0,    0,    0},
    {   0,    0,  _image2208_size,    0,    0,    0,    0},
    {   0,    0,  _image2209_size,    0,    0,    0,    0},
    {   0,    0,  _image2210_size,    0,    0,    0,    0},
    {   0,    0,  _image2211_size,    0,    0,    0,    0},
    {   0,    0,  _image2212_size,    0,    0,    0,    0},
    {   0,    0,  _image2213_size,    0,    0,    0,    0},
    {   0,    0,  _image2214_size,    0,    0,    0,    0},
    {   0,    0,  _image2215_size,    0,    0,    0,    0},
    {   0,    0,  _image2216_size,    0,    0,    0,    0},
    {   0,    0,  _image2217_size,    0,    0,    0,    0},
    {   0,    0,  _image2218_size,    0,    0,    0,    0},
    {   0,    0,  _image2219_size,    0,    0,    0,    0},
    {   0,    0,  _image2220_size,    0,    0,    0,    0},
    {   0,    0,  _image2221_size,    0,    0,    0,    0},
    {   0,    0,  _image2222_size,    0,    0,    0,    0},
    {   0,    0,  _image2223_size,    0,    0,    0,    0},
    {   0,    0,  _image2224_size,    0,    0,    0,    0},
    {   0,    0,  _image2225_size,    0,    0,    0,    0},
    {   0,    0,  _image2226_size,    0,    0,    0,    0},
    {   0,    0,  _image2227_size,    0,    0,    0,    0},
    {   0,    0,  _image2228_size,    0,    0,    0,    0},
    {   0,    0,  _image2229_size,    0,    0,    0,    0},
    {   0,    0,  _image2230_size,    0,    0,    0,    0},
    {   0,    0,  _image2231_size,    0,    0,    0,    0},
    {   0,    0,  _image2232_size,    0,    0,    0,    0},
    {   0,    0,  _image2233_size,    0,    0,    0,    0},
    {   0,    0,  _image2234_size,    0,    0,    0,    0},
    {   0,    0,  _image2235_size,    0,    0,    0,    0},
    {   0,    0,  _image2236_size,    0,    0,    0,    0},
    {   0,    0,  _image2237_size,    0,    0,    0,    0},
    {   0,    0,  _image2238_size,    0,    0,    0,    0},
    {   0,    0,  _image2239_size,    0,    0,    0,    0},
    {   0,    0,  _image2240_size,    0,    0,    0,    0},
    {   0,    0,  _image2241_size,    0,    0,    0,    0},
    {   0,    0,  _image2242_size,    0,    0,    0,    0},
    {   0,    0,  _image2243_size,    0,    0,    0,    0},
    {   0,    0,  _image2244_size,    0,    0,    0,    0},
    {   0,    0,  _image2245_size,    0,    0,    0,    0},
    {   0,    0,  _image2246_size,    0,    0,    0,    0},
    {   0,    0,  _image2247_size,    0,    0,    0,    0},
    {   0,    0,  _image2248_size,    0,    0,    0,    0},
    {   0,    0,  _image2249_size,    0,    0,    0,    0},
    {   0,    0,  _image2250_size,    0,    0,    0,    0},
    {   0,    0,  _image2251_size,    0,    0,    0,    0},
    {   0,    0,  _image2252_size,    0,    0,    0,    0},
    {   0,    0,  _image2253_size,    0,    0,    0,    0},
    {   0,    0,  _image2254_size,    0,    0,    0,    0},
    {   0,    0,  _image2255_size,    0,    0,    0,    0},
    {   0,    0,  _image2256_size,    0,    0,    0,    0},
    {   0,    0,  _image2257_size,    0,    0,    0,    0},
    {   0,    0,  _image2258_size,    0,    0,    0,    0},
    {   0,    0,  _image2259_size,    0,    0,    0,    0},
    {   0,    0,  _image2260_size,    0,    0,    0,    0},
    {0x33,    0,  _image2261_size,    0,    0,    0,    0},
    {   0,    0,  _image2262_size,    0,    0,    0,    0},
    {   0,    0,  _image2263_size,    0,    0,    0,    0},
    {   0,    0,  _image2264_size,    0,    0,    0,    0},
    {   0,    0,  _image2265_size,    0,    0,    0,    0},
    {   0,    0,  _image2266_size,    0,    0,    0,    0},
    {   0,    0,  _image2267_size,    0,    0,    0,    0},
    {   0,    0,  _image2268_size,    0,    0,    0,    0},
    {   0,    0,  _image2269_size,    0,    0,    0,    0},
    {   0,    0,  _image2270_size,    0,    0,    0,    0},
    {   0,    0,  _image2271_size,    0,    0,    0,    0},
    {   0,    0,  _image2272_size,    0,    0,    0,    0},
    {   0,    0,  _image2273_size,    0,    0,    0,    0},
    {   0,    0,  _image2274_size,    0,    0,    0,    0},
    {   0,    0,  _image2275_size,    0,    0,    0,    0},
    {   0,    0,  _image2276_size,    0,    0,    0,    0},
    {   0,    0,  _image2277_size,    0,    0,    0,    0},
    {0x22,    0,  _image2278_size,    0,    0,    0,    0},
    {   0,    0,  _image2279_size,    0,    0,    0,    0},
    {0x22,    0,  _image2280_size,    0,    0,    0,    0},
    {0x22,    0,  _image2281_size,    0,    0,    0,    0},
    {   0,    0,  _image2282_size,    0,    0,    0,    0},
    {0x22,    0,  _image2283_size,    0,    0,    0,    0},
    {   0,    0,  _image2284_size,    0,    0,    0,    0},
    {   0,    0,  _image2285_size,    0,    0,    0,    0},
    {   0,    0,  _image2286_size,    0,    0,    0,    0},
    {   0,    0,  _image2287_size,    0,    0,    0,    0},
    {   0,    0,  _image2288_size,    0,    0,    0,    0},
    {   0,    0,  _image2289_size,    0,    0,    0,    0},
    {   0,    0,  _image2290_size,    0,    0,    0,    0},
    {   0,    0,  _image2291_size,    0,    0,    0,    0},
    {   0,    0,  _image2292_size,    0,    0,    0,    0},
    {   0,    0,  _image2293_size,    0,    0,    0,    0},
    {   0,    0,  _image2294_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2295_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2296_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2297_size,    0,    0,    0,    0},
    {   0,    0,  _image2298_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2299_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2300_size,    0,    0,    0,    0},
    {0x33,    0,  _image2301_size,    0,    0,    0,    0},
    {0x77,    0,  _image2302_size,    0,    0,    0,    0},
    {0x77,    0,  _image2303_size,    0,    0,    0,    0},
    {0x77,    0,  _image2304_size,    0,    0,    0,    0},
    {0x77,    0,  _image2305_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2306_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2307_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2308_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2309_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2310_size,    0,    0,    0,    0},
    {0x22,    0,  _image2311_size,    0,    0,    0,    0},
    {0x11,    0,  _image2312_size,    0,    0,    0,    0},
    {   0,    0,  _image2313_size,    0,    0,    0,    0},
    {0x77,    0,  _image2314_size,    0,    0,    0,    0},
    {0x77,    0,  _image2315_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2316_size,    0,    0,    0,    0},
    {   0,    0,  _image2317_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2318_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2319_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2320_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2321_size,    0,    0,    0,    0},
    {   0,    0,  _image2322_size,    0,    0,    0,    0},
    {0x33,    0,  _image2323_size,    0,    0,    0,    0},
    {0x33,    0,  _image2324_size,    0,    0,    0,    0},
    {   0,    0,  _image2325_size,    0,    0,    0,    0},
    {   0,    0,  _image2326_size,    0,    0,    0,    0},
    {   0,    0,  _image2327_size,    0,    0,    0,    0},
    {   0,    0,  _image2328_size,    0,    0,    0,    0},
    {   0,    0,  _image2329_size,    0,    0,    0,    0},
    {   0,    0,  _image2330_size,    0,    0,    0,    0},
    {   0,    0,  _image2331_size,    0,    0,    0,    0},
    {   0,    0,  _image2332_size,    0,    0,    0,    0},
    {   0,    0,  _image2333_size,    0,    0,    0,    0},
    {   0,    0,  _image2334_size,    0,    0,    0,    0},
    {   0,    0,  _image2335_size,    0,    0,    0,    0},
    {0x22,    0,  _image2336_size,    0,    0,    0,    0},
    {0x22,    0,  _image2337_size,    0,    0,    0,    0},
    {0x22,    0,  _image2338_size,    0,    0,    0,    0},
    {0x22,    0,  _image2339_size,    0,    0,    0,    0},
    {0x33,    0,  _image2340_size,    0,    0,    0,    0},
    {   0,    0,  _image2341_size,    0,    0,    0,    0},
    {   0,    0,  _image2342_size,    0,    0,    0,    0},
    {0x55,    0,  _image2343_size,    0,    0,    0,    0},
    {0x55,    0,  _image2344_size,    0,    0,    0,    0},
    {   0,    0,  _image2345_size,    0,    0,    0,    0},
    {   0,    0,  _image2346_size,    0,    0,    0,    0},
    {   0,    0,  _image2347_size,    0,    0,    0,    0},
    {   0,    0,  _image2348_size,    0,    0,    0,    0},
    {   0,    0,  _image2349_size,    0,    0,    0,    0},
    {   0,    0,  _image2350_size,    0,    0,    0,    0},
    {   0,    0,  _image2351_size,    0,    0,    0,    0},
    {   0,    0,  _image2352_size,    0,    0,    0,    0},
    {   0,    0,  _image2353_size,    0,    0,    0,    0},
    {   0,    0,  _image2354_size,    0,    0,    0,    0},
    {   0,    0,  _image2355_size,    0,    0,    0,    0},
    {   0,    0,  _image2356_size,    0,    0,    0,    0},
    {   0,    0,  _image2357_size,    0,    0,    0,    0},
    {   0,    0,  _image2358_size,    0,    0,    0,    0},
    {   0,    0,  _image2359_size,    0,    0,    0,    0},
    {   0,    0,  _image2360_size,    0,    0,    0,    0},
    {   0,    0,  _image2361_size,    0,    0,    0,    0},
    {   0,    0,  _image2362_size,    0,    0,    0,    0},
    {   0,    0,  _image2363_size,    0,    0,    0,    0},
    {   0,    0,  _image2364_size,    0,    0,    0,    0},
    {   0,    0,  _image2365_size,    0,    0,    0,    0},
    {   0,    0,  _image2366_size,    0,    0,    0,    0},
    {   0,    0,  _image2367_size,    0,    0,    0,    0},
    {   0,    0,  _image2368_size,    0,    0,    0,    0},
    {   0,    0,  _image2369_size,    0,    0,    0,    0},
    {0x11,    0,  _image2370_size,    0,    0,    0,    0},
    {0x11,    0,  _image2371_size,    0,    0,    0,    0},
    {0x44,    0,  _image2372_size,    0,    0,    0,    0},
    {0x44,    0,  _image2373_size,    0,    0,    0,    0},
    {   0,    0,  _image2374_size,    0,    0,    0,    0},
    {   0,    0,  _image2375_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2376_size,    0,    0,    0,    0},
    {0x11,    0,  _image2377_size,    0,    0,    0,    0},
    {0x33,    0,  _image2378_size,    0,    0,    0,    0},
    {   0,    0,  _image2379_size,    0,    0,    0,    0},
    {0x22,    0,  _image2380_size,    0,    0,    0,    0},
    {0x33,    0,  _image2381_size,    0,    0,    0,    0},
    {0x44,    0,  _image2382_size,    0,    0,    0,    0},
    {   0,    0,  _image2383_size,    0,    0,    0,    0},
    {   0,    0,  _image2384_size,    0,    0,    0,    0},
    {   0,    0,  _image2385_size,    0,    0,    0,    0},
    {0x33,    0,  _image2386_size,    0,    0,    0,    0},
    {   0,    0,  _image2387_size,    0,    0,    0,    0},
    {   0,    0,  _image2388_size,    0,    0,    0,    0},
    {0x44,    0,  _image2389_size,    0,    0,    0,    0},
    {   0,    0,  _image2390_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2391_size,    0,    0,    0,    0},
    {   0,    0,  _image2392_size,    0,    0,    0,    0},
    {0x44,    0,  _image2393_size,    0,    0,    0,    0},
    {   0,    0,  _image2394_size,    0,    0,    0,    0},
    {   0,    0,  _image2395_size,    0,    0,    0,    0},
    {   0,    0,  _image2396_size,    0,    0,    0,    0},
    {0x33,    0,  _image2397_size,    0,    0,    0,    0},
    {   0,    0,  _image2398_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2399_size,    0,    0,    0,    0},
    {0x33,    0,  _image2400_size,    0,    0,    0,    0},
    {0x33,    0,  _image2401_size,    0,    0,    0,    0},
    {0x44,    0,  _image2402_size,    0,    0,    0,    0},
    {0x11,    0,  _image2403_size,    0,    0,    0,    0},
    {   0,    0,  _image2404_size,    0,    0,    0,    0},
    {0x22,    0,  _image2405_size,    0,    0,    0,    0},
    {0x11,    0,  _image2406_size,    0,    0,    0,    0},
    {0x22,    0,  _image2407_size,    0,    0,    0,    0},
    {   0,    0,  _image2408_size,    0,    0,    0,    0},
    {0x11,    0,  _image2409_size,    0,    0,    0,    0},
    {   0,    0,  _image2410_size,    0,    0,    0,    0},
    {0x11,    0,  _image2411_size,    0,    0,    0,    0},
    {   0,    0,  _image2412_size,    0,    0,    0,    0},
    {   0,    0,  _image2413_size,    0,    0,    0,    0},
    {0x11,    0,  _image2414_size,    0,    0,    0,    0},
    {0x44,    0,  _image2415_size,    0,    0,    0,    0},
    {   0,    0,  _image2416_size,    0,    0,    0,    0},
    {   0,    0,  _image2417_size,    0,    0,    0,    0},
    {0xAA,    0,  _image2418_size,    0,    0,    0,    0},
    {   0,    0,  _image2419_size,    0,    0,    0,    0},
    {   0,    0,  _image2420_size,    0,    0,    0,    0},
    {   0,    0,  _image2421_size,    0,    0,    0,    0},
    {   0,    0,  _image2422_size,    0,    0,    0,    0},
    {   0,    0,  _image2423_size,    0,    0,    0,    0},
    {   0,    0,  _image2424_size,    0,    0,    0,    0},
    {   0,    0,  _image2425_size,    0,    0,    0,    0},
    {   0,    0,  _image2426_size,    0,    0,    0,    0},
    {   0,    0,  _image2427_size,    0,    0,    0,    0},
    {   0,    0,  _image2428_size,    0,    0,    0,    0},
    {0x44,    0,  _image2429_size,    0,    0,    0,    0},
    {0x33,    0,  _image2430_size,    0,    0,    0,    0},
    {0x33,    0,  _image2431_size,    0,    0,    0,    0},
    {   0,    0,  _image2432_size,    0,    0,    0,    0},
    {   0,    0,  _image2433_size,    0,    0,    0,    0},
    {   0,    0,  _image2434_size,    0,    0,    0,    0},
    {   0,    0,  _image2435_size,    0,    0,    0,    0},
    {   0,    0,  _image2436_size,    0,    0,    0,    0},
    {   0,    0,  _image2437_size,    0,    0,    0,    0},
    {   0,    0,  _image2438_size,    0,    0,    0,    0},
    {   0,    0,  _image2439_size,    0,    0,    0,    0},
    {   0,    0,  _image2440_size,    0,    0,    0,    0},
    {   0,    0,  _image2441_size,    0,    0,    0,    0},
    {   0,    0,  _image2442_size,    0,    0,    0,    0},
    {   0,    0,  _image2443_size,    0,    0,    0,    0},
    {   0,    0,  _image2444_size,    0,    0,    0,    0},
    {   0,    0,  _image2445_size,    0,    0,    0,    0},
    {   0,    0,  _image2446_size,    0,    0,    0,    0},
    {   0,    0,  _image2447_size,    0,    0,    0,    0},
    {   0,    0,  _image2448_size,    0,    0,    0,    0},
    {   0,    0,  _image2449_size,    0,    0,    0,    0},
    {   0,    0,  _image2450_size,    0,    0,    0,    0},
    {   0,    0,  _image2451_size,    0,    0,    0,    0},
    {   0,    0,  _image2452_size,    0,    0,    0,    0},
    {   0,    0,  _image2453_size,    0,    0,    0,    0},
    {   0,    0,  _image2454_size,    0,    0,    0,    0},
    {   0,    0,  _image2455_size,    0,    0,    0,    0},
    {   0,    0,  _image2456_size,    0,    0,    0,    0},
    {   0,    0,  _image2457_size,    0,    0,    0,    0},
    {   0,    0,  _image2458_size,    0,    0,    0,    0},
    {   0,    0,  _image2459_size,    0,    0,    0,    0},
    {   0,    0,  _image2460_size,    0,    0,    0,    0},
    {   0,    0,  _image2461_size,    0,    0,    0,    0},
    {   0,    0,  _image2462_size,    0,    0,    0,    0},
    {   0,    0,  _image2463_size,    0,    0,    0,    0},
    {   0,    0,  _image2464_size,    0,    0,    0,    0},
    {   0,    0,  _image2465_size,    0,    0,    0,    0},
    {   0,    0,  _image2466_size,    0,    0,    0,    0},
    {   0,    0,  _image2467_size,    0,    0,    0,    0},
    {   0,    0,  _image2468_size,    0,    0,    0,    0},
    {   0,    0,  _image2469_size,    0,    0,    0,    0},
    {   0,    0,  _image2470_size,    0,    0,    0,    0},
    {   0,    0,  _image2471_size,    0,    0,    0,    0},
    {   0,    0,  _image2472_size,    0,    0,    0,    0},
    {   0,    0,  _image2473_size,    0,    0,    0,    0},
    {   0,    0,  _image2474_size,    0,    0,    0,    0},
    {0x11,    0,  _image2475_size,    0,    0,    0,    0},
    {   0,    0,  _image2476_size,    0,    0,    0,    0},
    {   0,    0,  _image2477_size,    0,    0,    0,    0},
    {   0,    0,  _image2478_size,    0,    0,    0,    0},
    {   0,    0,  _image2479_size,    0,    0,    0,    0},
    {   0,    0,  _image2480_size,    0,    0,    0,    0},
    {   0,    0,  _image2481_size,    0,    0,    0,    0},
    {   0,    0,  _image2482_size,    0,    0,    0,    0},
    {   0,    0,  _image2483_size,    0,    0,    0,    0},
    {   0,    0,  _image2484_size,    0,    0,    0,    0},
    {   0,    0,  _image2485_size,    0,    0,    0,    0},
    {   0,    0,  _image2486_size,    0,    0,    0,    0},
    {   0,    0,  _image2487_size,    0,    0,    0,    0},
    {   0,    0,  _image2488_size,    0,    0,    0,    0},
    {   0,    0,  _image2489_size,    0,    0,    0,    0},
    {   0,    0,  _image2490_size,    0,    0,    0,    0},
    {   0,    0,  _image2491_size,    0,    0,    0,    0},
    {   0,    0,  _image2492_size,    0,    0,    0,    0},
    {   0,    0,  _image2493_size,    0,    0,    0,    0},
    {   0,    0,  _image2494_size,    0,    0,    0,    0},
    {   0,    0,  _image2495_size,    0,    0,    0,    0},
    {   0,    0,  _image2496_size,    0,    0,    0,    0},
    {   0,    0,  _image2497_size,    0,    0,    0,    0},
    {   0,    0,  _image2498_size,    0,    0,    0,    0},
    {   0,    0,  _image2499_size,    0,    0,    0,    0},
    {   0,    0,  _image2500_size,    0,    0,    0,    0},
    {   0,    0,  _image2501_size,    0,    0,    0,    0},
    {   0,    0,  _image2502_size,    0,    0,    0,    0},
    {   0,    0,  _image2503_size,    0,    0,    0,    0},
    {   0,    0,  _image2504_size,    0,    0,    0,    0},
    {   0,    0,  _image2505_size,    0,    0,    0,    0},
    {   0,    0,  _image2506_size,    0,    0,    0,    0},
    {   0,    0,  _image2507_size,    0,    0,    0,    0},
    {   0,    0,  _image2508_size,    0,    0,    0,    0},
    {   0,    0,  _image2509_size,    0,    0,    0,    0},
    {   0,    0,  _image2510_size,    0,    0,    0,    0},
    {   0,    0,  _image2511_size,    0,    0,    0,    0},
    {   0,    0,  _image2512_size,    0,    0,    0,    0},
    {   0,    0,  _image2513_size,    0,    0,    0,    0},
    {   0,    0,  _image2514_size,    0,    0,    0,    0},
    {   0,    0,  _image2515_size,    0,    0,    0,    0},
    {   0,    0,  _image2516_size,    0,    0,    0,    0},
    {   0,    0,  _image2517_size,    0,    0,    0,    0},
    {   0,    0,  _image2518_size,    0,    0,    0,    0},
    {   0,    0,  _image2519_size,    0,    0,    0,    0},
    {   0,    0,  _image2520_size,    0,    0,    0,    0},
    {   0,    0,  _image2521_size,    0,    0,    0,    0},
    {   0,    0,  _image2522_size,    0,    0,    0,    0},
    {   0,    0,  _image2523_size,    0,    0,    0,    0},
    {   0,    0,  _image2524_size,    0,    0,    0,    0},
    {   0,    0,  _image2525_size,    0,    0,    0,    0},
    {   0,    0,  _image2526_size,    0,    0,    0,    0},
    {   0,    0,  _image2527_size,    0,    0,    0,    0},
    {   0,    0,  _image2528_size,    0,    0,    0,    0},
    {   0,    0,  _image2529_size,    0,    0,    0,    0},
    {   0,    0,  _image2530_size,    0,    0,    0,    0},
    {   0,    0,  _image2531_size,    0,    0,    0,    0},
    {   0,    0,  _image2532_size,    0,    0,    0,    0},
    {   0,    0,  _image2533_size,    0,    0,    0,    0},
    {   0,    0,  _image2534_size,    0,    0,    0,    0},
    {   0,    0,  _image2535_size,    0,    0,    0,    0},
    {   0,    0,  _image2536_size,    0,    0,    0,    0},
    {   0,    0,  _image2537_size,    0,    0,    0,    0},
    {   0,    0,  _image2538_size,    0,    0,    0,    0},
    {   0,    0,  _image2539_size,    0,    0,    0,    0},
    {   0,    0,  _image2540_size,    0,    0,    0,    0},
    {   0,    0,  _image2541_size,    0,    0,    0,    0},
    {   0,    0,  _image2542_size,    0,    0,    0,    0},
    {   0,    0,  _image2543_size,    0,    0,    0,    0},
    {   0,    0,  _image2544_size,    0,    0,    0,    0},
    {   0,    0,  _image2545_size,    0,    0,    0,    0},
    {   0,    0,  _image2546_size,    0,    0,    0,    0},
    {   0,    0,  _image2547_size,    0,    0,    0,    0},
    {   0,    0,  _image2548_size,    0,    0,    0,    0},
    {   0,    0,  _image2549_size,    0,    0,    0,    0},
    {   0,    0,  _image2550_size,    0,    0,    0,    0},
    {   0,    0,  _image2551_size,    0,    0,    0,    0},
    {   0,    0,  _image2552_size,    0,    0,    0,    0},
    {   0,    0,  _image2553_size,    0,    0,    0,    0},
    {   0,    0,  _image2554_size,    0,    0,    0,    0},
    {   0,    0,  _image2555_size,    0,    0,    0,    0},
    {   0,    0,  _image2556_size,    0,    0,    0,    0},
    {   0,    0,  _image2557_size,    0,    0,    0,    0},
    {   0,    0,  _image2558_size,    0,    0,    0,    0},
    {   0,    0,  _image2559_size,    0,    0,    0,    0},
    {   0,    0,  _image2560_size,    0,    0,    0,    0},
    {   0,    0,  _image2561_size,    0,    0,    0,    0},
    {   0,    0,  _image2562_size,    0,    0,    0,    0},
    {   0,    0,  _image2563_size,    0,    0,    0,    0},
    {   0,    0,  _image2564_size,    0,    0,    0,    0},
    {   0,    0,  _image2565_size,    0,    0,    0,    0},
    {   0,    0,  _image2566_size,    0,    0,    0,    0},
    {   0,    0,  _image2567_size,    0,    0,    0,    0},
    {   0,    0,  _image2568_size,    0,    0,    0,    0},
    {   0,    0,  _image2569_size,    0,    0,    0,    0},
    {   0,    0,  _image2570_size,    0,    0,    0,    0},
    {   0,    0,  _image2571_size,    0,    0,    0,    0},
    {   0,    0,  _image2572_size,    0,    0,    0,    0},
    {   0,    0,  _image2573_size,    0,    0,    0,    0},
    {   0,    0,  _image2574_size,    0,    0,    0,    0},
    {   0,    0,  _image2575_size,    0,    0,    0,    0},
    {   0,    0,  _image2576_size,    0,    0,    0,    0},
    {   0,    0,  _image2577_size,    0,    0,    0,    0},
    {   0,    0,  _image2578_size,    0,    0,    0,    0},
    {   0,    0,  _image2579_size,    0,    0,    0,    0},
    {   0,    0,  _image2580_size,    0,    0,    0,    0},
    {   0,    0,  _image2581_size,    0,    0,    0,    0},
    {   0,    0,  _image2582_size,    0,    0,    0,    0},
    {   0,    0,  _image2583_size,    0,    0,    0,    0},
    {   0,    0,  _image2584_size,    0,    0,    0,    0},
    {   0,    0,  _image2585_size,    0,    0,    0,    0},
    {   0,    0,  _image2586_size,    0,    0,    0,    0},
    {   0,    0,  _image2587_size,    0,    0,    0,    0},
    {   0,    0,  _image2588_size,    0,    0,    0,    0},
    {   0,    0,  _image2589_size,    0,    0,    0,    0},
    {   0,    0,  _image2590_size,    0,    0,    0,    0},
    {   0,    0,  _image2591_size,    0,    0,    0,    0},
    {   0,    0,  _image2592_size,    0,    0,    0,    0},
    {   0,    0,  _image2593_size,    0,    0,    0,    0},
    {   0,    0,  _image2594_size,    0,    0,    0,    0},
    {   0,    0,  _image2595_size,    0,    0,    0,    0},
    {   0,    0,  _image2596_size,    0,    0,    0,    0},
    {   0,    0,  _image2597_size,    0,    0,    0,    0},
    {   0,    0,  _image2598_size,    0,    0,    0,    0},
    {   0,    0,  _image2599_size,    0,    0,    0,    0},
    {   0,    0,  _image2600_size,    0,    0,    0,    0},
    {   0,    0,  _image2601_size,    0,    0,    0,    0},
    {   0,    0,  _image2602_size,    0,    0,    0,    0},
    {   0,    0,  _image2603_size,    0,    0,    0,    0},
    {   0,    0,  _image2604_size,    0,    0,    0,    0},
    {   0,    0,  _image2605_size,    0,    0,    0,    0},
    {   0,    0,  _image2606_size,    0,    0,    0,    0},
    {   0,    0,  _image2607_size,    0,    0,    0,    0},
    {   0,    0,  _image2608_size,    0,    0,    0,    0},
    {   0,    0,  _image2609_size,    0,    0,    0,    0},
    {   0,    0,  _image2610_size,    0,    0,    0,    0},
    {   0,    0,  _image2611_size,    0,    0,    0,    0},
    {   0,    0,  _image2612_size,    0,    0,    0,    0},
    {   0,    0,  _image2613_size,    0,    0,    0,    0},
    {   0,    0,  _image2614_size,    0,    0,    0,    0},
    {   0,    0,  _image2615_size,    0,    0,    0,    0},
    {   0,    0,  _image2616_size,    0,    0,    0,    0},
    {   0,    0,  _image2617_size,    0,    0,    0,    0},
    {   0,    0,  _image2618_size,    0,    0,    0,    0},
    {   0,    0,  _image2619_size,    0,    0,    0,    0},
    {   0,    0,  _image2620_size,    0,    0,    0,    0},
    {   0,    0,  _image2621_size,    0,    0,    0,    0},
    {   0,    0,  _image2622_size,    0,    0,    0,    0},
    {   0,    0,  _image2623_size,    0,    0,    0,    0},
    {   0,    0,  _image2624_size,    0,    0,    0,    0},
    {   0,    0,  _image2625_size,    0,    0,    0,    0},
    {   0,    0,  _image2626_size,    0,    0,    0,    0},
    {   0,    0,  _image2627_size,    0,    0,    0,    0},
    {   0,    0,  _image2628_size,    0,    0,    0,    0},
    {   0,    0,  _image2629_size,    0,    0,    0,    0},
    {   0,    0,  _image2630_size,    0,    0,    0,    0},
    {   0,    0,  _image2631_size,    0,    0,    0,    0},
    {   0,    0,  _image2632_size,    0,    0,    0,    0},
    {   0,    0,  _image2633_size,    0,    0,    0,    0},
    {   0,    0,  _image2634_size,    0,    0,    0,    0},
    {   0,    0,  _image2635_size,    0,    0,    0,    0},
    {   0,    0,  _image2636_size,    0,    0,    0,    0},
    {   0,    0,  _image2637_size,    0,    0,    0,    0},
    {   0,    0,  _image2638_size,    0,    0,    0,    0},
    {   0,    0,  _image2639_size,    0,    0,    0,    0},
    {   0,    0,  _image2640_size,    0,    0,    0,    0},
    {   0,    0,  _image2641_size,    0,    0,    0,    0},
    {   0,    0,  _image2642_size,    0,    0,    0,    0},
    {   0,    0,  _image2643_size,    0,    0,    0,    0},
    {   0,    0,  _image2644_size,    0,    0,    0,    0},
    {   0,    0,  _image2645_size,    0,    0,    0,    0},
    {   0,    0,  _image2646_size,    0,    0,    0,    0},
    {   0,    0,  _image2647_size,    0,    0,    0,    0},
    {   0,    0,  _image2648_size,    0,    0,    0,    0},
    {   0,    0,  _image2649_size,    0,    0,    0,    0},
    {   0,    0,  _image2650_size,    0,    0,    0,    0},
    {   0,    0,  _image2651_size,    0,    0,    0,    0},
    {   0,    0,  _image2652_size,    0,    0,    0,    0},
    {   0,    0,  _image2653_size,    0,    0,    0,    0},
    {   0,    0,  _image2654_size,    0,    0,    0,    0},
    {   0,    0,  _image2655_size,    0,    0,    0,    0},
    {   0,    0,  _image2656_size,    0,    0,    0,    0},
    {   0,    0,  _image2657_size,    0,    0,    0,    0},
    {   0,    0,  _image2658_size,    0,    0,    0,    0},
    {   0,    0,  _image2659_size,    0,    0,    0,    0},
    {   0,    0,  _image2660_size,    0,    0,    0,    0},
    {   0,    0,  _image2661_size,    0,    0,    0,    0},
    {   0,    0,  _image2662_size,    0,    0,    0,    0},
    {   0,    0,  _image2663_size,    0,    0,    0,    0},
    {   0,    0,  _image2664_size,    0,    0,    0,    0},
    {   0,    0,  _image2665_size,    0,    0,    0,    0},
    {   0,    0,  _image2666_size,    0,    0,    0,    0},
    {   0,    0,  _image2667_size,    0,    0,    0,    0},
    {   0,    0,  _image2668_size,    0,    0,    0,    0},
    {   0,    0,  _image2669_size,    0,    0,    0,    0},
    {   0,    0,  _image2670_size,    0,    0,    0,    0},
    {   0,    0,  _image2671_size,    0,    0,    0,    0},
    {   0,    0,  _image2672_size,    0,    0,    0,    0},
    {   0,    0,  _image2673_size,    0,    0,    0,    0},
    {   0,    0,  _image2674_size,    0,    0,    0,    0},
    {   0,    0,  _image2675_size,    0,    0,    0,    0},
    {   0,    0,  _image2676_size,    0,    0,    0,    0},
    {   0,    0,  _image2677_size,    0,    0,    0,    0},
    {   0,    0,  _image2678_size,    0,    0,    0,    0},
    {   0,    0,  _image2679_size,    0,    0,    0,    0},
    {   0,    0,  _image2680_size,    0,    0,    0,    0},
    {   0,    0,  _image2681_size,    0,    0,    0,    0},
    {   0,    0,  _image2682_size,    0,    0,    0,    0},
    {   0,    0,  _image2683_size,    0,    0,    0,    0},
    {   0,    0,  _image2684_size,    0,    0,    0,    0},
    {   0,    0,  _image2685_size,    0,    0,    0,    0},
    {   0,    0,  _image2686_size,    0,    0,    0,    0},
    {   0,    0,  _image2687_size,    0,    0,    0,    0},
    {   0,    0,  _image2688_size,    0,    0,    0,    0},
    {   0,    0,  _image2689_size,    0,    0,    0,    0},
    {   0,    0,  _image2690_size,    0,    0,    0,    0},
    {   0,    0,  _image2691_size,    0,    0,    0,    0},
    {   0,    0,  _image2692_size,    0,    0,    0,    0},
    {   0,    0,  _image2693_size,    0,    0,    0,    0},
    {   0,    0,  _image2694_size,    0,    0,    0,    0},
    {   0,    0,  _image2695_size,    0,    0,    0,    0},
    {   0,    0,  _image2696_size,    0,    0,    0,    0},
    {   0,    0,  _image2697_size,    0,    0,    0,    0},
    {   0,    0,  _image2698_size,    0,    0,    0,    0},
    {   0,    0, 0xFFFF,    0,    0,    0,    0}
};



void nullsub_41(s32 arg0) {
    if (arg0);
}






#ifdef NONMATCHING
void image_related_calls_decompressdata_function(void) {

}
#else
GLOBAL_ASM(
.text
glabel image_related_calls_decompressdata_function
/* 0FB188 7F0C6658 27BDD458 */  addiu $sp, $sp, -0x2ba8
/* 0FB18C 7F0C665C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0FB190 7F0C6660 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0FB194 7F0C6664 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0FB198 7F0C6668 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0FB19C 7F0C666C AFB70044 */  sw    $s7, 0x44($sp)
/* 0FB1A0 7F0C6670 AFB60040 */  sw    $s6, 0x40($sp)
/* 0FB1A4 7F0C6674 AFB40038 */  sw    $s4, 0x38($sp)
/* 0FB1A8 7F0C6678 AFB30034 */  sw    $s3, 0x34($sp)
/* 0FB1AC 7F0C667C AFB20030 */  sw    $s2, 0x30($sp)
/* 0FB1B0 7F0C6680 AFB00028 */  sw    $s0, 0x28($sp)
/* 0FB1B4 7F0C6684 AFA52BAC */  sw    $a1, 0x2bac($sp)
/* 0FB1B8 7F0C6688 AFA62BB0 */  sw    $a2, 0x2bb0($sp)
/* 0FB1BC 7F0C668C AFA72BB4 */  sw    $a3, 0x2bb4($sp)
/* 0FB1C0 7F0C6690 00008825 */  move  $s1, $zero
/* 0FB1C4 7F0C6694 0FC32FC4 */  jal   makeemptyimageatpos
/* 0FB1C8 7F0C6698 0000A825 */   move  $s5, $zero
/* 0FB1CC 7F0C669C 8FA62BB0 */  lw    $a2, 0x2bb0($sp)
/* 0FB1D0 7F0C66A0 8FA72BB4 */  lw    $a3, 0x2bb4($sp)
/* 0FB1D4 7F0C66A4 00004025 */  move  $t0, $zero
/* 0FB1D8 7F0C66A8 50C00006 */  beql  $a2, $zero, .L7F0C66C4
/* 0FB1DC 7F0C66AC 240E0001 */   li    $t6, 1
/* 0FB1E0 7F0C66B0 50E00004 */  beql  $a3, $zero, .L7F0C66C4
/* 0FB1E4 7F0C66B4 240E0001 */   li    $t6, 1
/* 0FB1E8 7F0C66B8 10000004 */  b     .L7F0C66CC
/* 0FB1EC 7F0C66BC AFA72B9C */   sw    $a3, 0x2b9c($sp)
/* 0FB1F0 7F0C66C0 240E0001 */  li    $t6, 1
.L7F0C66C4:
/* 0FB1F4 7F0C66C4 8FA72BB4 */  lw    $a3, 0x2bb4($sp)
/* 0FB1F8 7F0C66C8 AFAE2B9C */  sw    $t6, 0x2b9c($sp)
.L7F0C66CC:
/* 0FB1FC 7F0C66CC 8FBE2BB8 */  lw    $fp, 0x2bb8($sp)
/* 0FB200 7F0C66D0 0007C940 */  sll   $t9, $a3, 5
/* 0FB204 7F0C66D4 00066940 */  sll   $t5, $a2, 5
/* 0FB208 7F0C66D8 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB20C 7F0C66DC 31AE0020 */  andi  $t6, $t5, 0x20
/* 0FB210 7F0C66E0 3C058009 */  lui   $a1, %hi(dword_CODE_bss_8008D090)
/* 0FB214 7F0C66E4 9069000B */  lbu   $t1, 0xb($v1)
/* 0FB218 7F0C66E8 312AFF1F */  andi  $t2, $t1, 0xff1f
/* 0FB21C 7F0C66EC 032A5825 */  or    $t3, $t9, $t2
/* 0FB220 7F0C66F0 A06B000B */  sb    $t3, 0xb($v1)
/* 0FB224 7F0C66F4 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB228 7F0C66F8 906F000C */  lbu   $t7, 0xc($v1)
/* 0FB22C 7F0C66FC 31F8FFDF */  andi  $t8, $t7, 0xffdf
/* 0FB230 7F0C6700 01D84825 */  or    $t1, $t6, $t8
/* 0FB234 7F0C6704 10C00015 */  beqz  $a2, .L7F0C675C
/* 0FB238 7F0C6708 A069000C */   sb    $t1, 0xc($v1)
/* 0FB23C 7F0C670C 8CA5D090 */  lw    $a1, %lo(dword_CODE_bss_8008D090)($a1)
/* 0FB240 7F0C6710 24150001 */  li    $s5, 1
/* 0FB244 7F0C6714 18A00011 */  blez  $a1, .L7F0C675C
/* 0FB248 7F0C6718 00000000 */   nop   
/* 0FB24C 7F0C671C 8FD9000C */  lw    $t9, 0xc($fp)
/* 0FB250 7F0C6720 3C0B8009 */  lui   $t3, %hi(word_CODE_bss_8008C730)
/* 0FB254 7F0C6724 2562C730 */  addiu $v0, $t3, %lo(word_CODE_bss_8008C730)
/* 0FB258 7F0C6728 8F230000 */  lw    $v1, ($t9)
/* 0FB25C 7F0C672C 00056100 */  sll   $t4, $a1, 4
/* 0FB260 7F0C6730 01822021 */  addu  $a0, $t4, $v0
/* 0FB264 7F0C6734 00035502 */  srl   $t2, $v1, 0x14
/* 0FB268 7F0C6738 01401825 */  move  $v1, $t2
/* 0FB26C 7F0C673C 844D0000 */  lh    $t5, ($v0)
.L7F0C6740:
/* 0FB270 7F0C6740 24420010 */  addiu $v0, $v0, 0x10
/* 0FB274 7F0C6744 0044082B */  sltu  $at, $v0, $a0
/* 0FB278 7F0C6748 146D0002 */  bne   $v1, $t5, .L7F0C6754
/* 0FB27C 7F0C674C 00000000 */   nop   
/* 0FB280 7F0C6750 0000A825 */  move  $s5, $zero
.L7F0C6754:
/* 0FB284 7F0C6754 5420FFFA */  bnezl $at, .L7F0C6740
/* 0FB288 7F0C6758 844D0000 */   lh    $t5, ($v0)
.L7F0C675C:
/* 0FB28C 7F0C675C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FB290 7F0C6760 24040008 */   li    $a0, 8
/* 0FB294 7F0C6764 AFA22B94 */  sw    $v0, 0x2b94($sp)
/* 0FB298 7F0C6768 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FB29C 7F0C676C 24040008 */   li    $a0, 8
/* 0FB2A0 7F0C6770 24430001 */  addiu $v1, $v0, 1
/* 0FB2A4 7F0C6774 1860000D */  blez  $v1, .L7F0C67AC
/* 0FB2A8 7F0C6778 AFA32B78 */   sw    $v1, 0x2b78($sp)
/* 0FB2AC 7F0C677C 8FAE2B78 */  lw    $t6, 0x2b78($sp)
/* 0FB2B0 7F0C6780 27A30070 */  addiu $v1, $sp, 0x70
/* 0FB2B4 7F0C6784 000EC040 */  sll   $t8, $t6, 1
/* 0FB2B8 7F0C6788 03038021 */  addu  $s0, $t8, $v1
.L7F0C678C:
/* 0FB2BC 7F0C678C 24040010 */  li    $a0, 16
/* 0FB2C0 7F0C6790 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FB2C4 7F0C6794 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0FB2C8 7F0C6798 8FA3005C */  lw    $v1, 0x5c($sp)
/* 0FB2CC 7F0C679C 24630002 */  addiu $v1, $v1, 2
/* 0FB2D0 7F0C67A0 0070082B */  sltu  $at, $v1, $s0
/* 0FB2D4 7F0C67A4 1420FFF9 */  bnez  $at, .L7F0C678C
/* 0FB2D8 7F0C67A8 A462FFFE */   sh    $v0, -2($v1)
.L7F0C67AC:
/* 0FB2DC 7F0C67AC 8FA92B9C */  lw    $t1, 0x2b9c($sp)
/* 0FB2E0 7F0C67B0 3C178005 */  lui   $s7, %hi(n64imagetypes) 
/* 0FB2E4 7F0C67B4 26F79248 */  addiu $s7, %lo(n64imagetypes) # addiu $s7, $s7, -0x6db8
/* 0FB2E8 7F0C67B8 19200064 */  blez  $t1, .L7F0C694C
/* 0FB2EC 7F0C67BC 00009825 */   move  $s3, $zero
/* 0FB2F0 7F0C67C0 27B42370 */  addiu $s4, $sp, 0x2370
.L7F0C67C4:
/* 0FB2F4 7F0C67C4 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FB2F8 7F0C67C8 24040008 */   li    $a0, 8
/* 0FB2FC 7F0C67CC 0040B025 */  move  $s6, $v0
/* 0FB300 7F0C67D0 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FB304 7F0C67D4 24040008 */   li    $a0, 8
/* 0FB308 7F0C67D8 16600029 */  bnez  $s3, .L7F0C6880
/* 0FB30C 7F0C67DC AFA22B84 */   sw    $v0, 0x2b84($sp)
/* 0FB310 7F0C67E0 8FD9000C */  lw    $t9, 0xc($fp)
/* 0FB314 7F0C67E4 A3360008 */  sb    $s6, 8($t9)
/* 0FB318 7F0C67E8 8FCA000C */  lw    $t2, 0xc($fp)
/* 0FB31C 7F0C67EC A1420009 */  sb    $v0, 9($t2)
/* 0FB320 7F0C67F0 8FAC2B78 */  lw    $t4, 0x2b78($sp)
/* 0FB324 7F0C67F4 8FCD000C */  lw    $t5, 0xc($fp)
/* 0FB328 7F0C67F8 258BFFFF */  addiu $t3, $t4, -1
/* 0FB32C 7F0C67FC A1AB000A */  sb    $t3, 0xa($t5)
/* 0FB330 7F0C6800 8FA42B94 */  lw    $a0, 0x2b94($sp)
/* 0FB334 7F0C6804 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB338 7F0C6808 00047080 */  sll   $t6, $a0, 2
/* 0FB33C 7F0C680C 02EEC021 */  addu  $t8, $s7, $t6
/* 0FB340 7F0C6810 8F090000 */  lw    $t1, ($t8)
/* 0FB344 7F0C6814 906C000B */  lbu   $t4, 0xb($v1)
/* 0FB348 7F0C6818 01C02025 */  move  $a0, $t6
/* 0FB34C 7F0C681C 0009C880 */  sll   $t9, $t1, 2
/* 0FB350 7F0C6820 332A001C */  andi  $t2, $t9, 0x1c
/* 0FB354 7F0C6824 318BFFE3 */  andi  $t3, $t4, 0xffe3
/* 0FB358 7F0C6828 014B6825 */  or    $t5, $t2, $t3
/* 0FB35C 7F0C682C A06D000B */  sb    $t5, 0xb($v1)
/* 0FB360 7F0C6830 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB364 7F0C6834 3C0E8005 */  lui   $t6, %hi(n64pixelsizes)
/* 0FB368 7F0C6838 01C47021 */  addu  $t6, $t6, $a0
/* 0FB36C 7F0C683C 8DD8927C */  lw    $t8, %lo(n64pixelsizes)($t6)
/* 0FB370 7F0C6840 9069000B */  lbu   $t1, 0xb($v1)
/* 0FB374 7F0C6844 3C0A8005 */  lui   $t2, %hi(imgflipvalues)
/* 0FB378 7F0C6848 330F0003 */  andi  $t7, $t8, 3
/* 0FB37C 7F0C684C 3139FFFC */  andi  $t9, $t1, 0xfffc
/* 0FB380 7F0C6850 01F96025 */  or    $t4, $t7, $t9
/* 0FB384 7F0C6854 A06C000B */  sb    $t4, 0xb($v1)
/* 0FB388 7F0C6858 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB38C 7F0C685C 01445021 */  addu  $t2, $t2, $a0
/* 0FB390 7F0C6860 8D4A92B0 */  lw    $t2, %lo(imgflipvalues)($t2)
/* 0FB394 7F0C6864 9069000C */  lbu   $t1, 0xc($v1)
/* 0FB398 7F0C6868 000A6B83 */  sra   $t5, $t2, 0xe
/* 0FB39C 7F0C686C 000DC180 */  sll   $t8, $t5, 6
/* 0FB3A0 7F0C6870 312FFF3F */  andi  $t7, $t1, 0xff3f
/* 0FB3A4 7F0C6874 030FC825 */  or    $t9, $t8, $t7
/* 0FB3A8 7F0C6878 1000000B */  b     .L7F0C68A8
/* 0FB3AC 7F0C687C A079000C */   sb    $t9, 0xc($v1)
.L7F0C6880:
/* 0FB3B0 7F0C6880 12A00009 */  beqz  $s5, .L7F0C68A8
/* 0FB3B4 7F0C6884 3C0C8009 */   lui   $t4, %hi(dword_CODE_bss_8008D090) 
/* 0FB3B8 7F0C6888 8D8CD090 */  lw    $t4, %lo(dword_CODE_bss_8008D090)($t4)
/* 0FB3BC 7F0C688C 3C0D8009 */  lui   $t5, %hi(word_CODE_bss_8008C730) 
/* 0FB3C0 7F0C6890 25ADC730 */  addiu $t5, %lo(word_CODE_bss_8008C730) # addiu $t5, $t5, -0x38d0
/* 0FB3C4 7F0C6894 000C5100 */  sll   $t2, $t4, 4
/* 0FB3C8 7F0C6898 01535821 */  addu  $t3, $t2, $s3
/* 0FB3CC 7F0C689C 016D1821 */  addu  $v1, $t3, $t5
/* 0FB3D0 7F0C68A0 A0760001 */  sb    $s6, 1($v1)
/* 0FB3D4 7F0C68A4 A0620008 */  sb    $v0, 8($v1)
.L7F0C68A8:
/* 0FB3D8 7F0C68A8 02C20019 */  multu $s6, $v0
/* 0FB3DC 7F0C68AC 3C048009 */  lui   $a0, %hi(img_curpos)
/* 0FB3E0 7F0C68B0 02802825 */  move  $a1, $s4
/* 0FB3E4 7F0C68B4 27A60270 */  addiu $a2, $sp, 0x270
/* 0FB3E8 7F0C68B8 00007012 */  mflo  $t6
/* 0FB3EC 7F0C68BC 29C11001 */  slti  $at, $t6, 0x1001
/* 0FB3F0 7F0C68C0 14200003 */  bnez  $at, .L7F0C68D0
/* 0FB3F4 7F0C68C4 00000000 */   nop   
/* 0FB3F8 7F0C68C8 100000B3 */  b     .L7F0C6B98
/* 0FB3FC 7F0C68CC 00001025 */   move  $v0, $zero
.L7F0C68D0:
/* 0FB400 7F0C68D0 0FC339FC */  jal   decompressdata
/* 0FB404 7F0C68D4 8C84D0A0 */   lw    $a0, %lo(img_curpos)($a0)
/* 0FB408 7F0C68D8 8FA92BAC */  lw    $t1, 0x2bac($sp)
/* 0FB40C 7F0C68DC 02802025 */  move  $a0, $s4
/* 0FB410 7F0C68E0 02C02825 */  move  $a1, $s6
/* 0FB414 7F0C68E4 01318021 */  addu  $s0, $t1, $s1
/* 0FB418 7F0C68E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB41C 7F0C68EC 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB420 7F0C68F0 0FC31AF2 */  jal   copy_loaded_image_to_final_mem_location
/* 0FB424 7F0C68F4 8FA72B94 */   lw    $a3, 0x2b94($sp)
/* 0FB428 7F0C68F8 0FC33A25 */  jal   sub_GAME_7F0CE894
/* 0FB42C 7F0C68FC 00409025 */   move  $s2, $v0
/* 0FB430 7F0C6900 0FC32FC4 */  jal   makeemptyimageatpos
/* 0FB434 7F0C6904 00402025 */   move  $a0, $v0
/* 0FB438 7F0C6908 8FB82BB0 */  lw    $t8, 0x2bb0($sp)
/* 0FB43C 7F0C690C 24010001 */  li    $at, 1
/* 0FB440 7F0C6910 8FAF2BB4 */  lw    $t7, 0x2bb4($sp)
/* 0FB444 7F0C6914 57010008 */  bnel  $t8, $at, .L7F0C6938
/* 0FB448 7F0C6918 8FB92B9C */   lw    $t9, 0x2b9c($sp)
/* 0FB44C 7F0C691C 19E00005 */  blez  $t7, .L7F0C6934
/* 0FB450 7F0C6920 02002025 */   move  $a0, $s0
/* 0FB454 7F0C6924 02C02825 */  move  $a1, $s6
/* 0FB458 7F0C6928 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB45C 7F0C692C 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FB460 7F0C6930 8FA72B94 */   lw    $a3, 0x2b94($sp)
.L7F0C6934:
/* 0FB464 7F0C6934 8FB92B9C */  lw    $t9, 0x2b9c($sp)
.L7F0C6938:
/* 0FB468 7F0C6938 26730001 */  addiu $s3, $s3, 1
/* 0FB46C 7F0C693C 02328821 */  addu  $s1, $s1, $s2
/* 0FB470 7F0C6940 1679FFA0 */  bne   $s3, $t9, .L7F0C67C4
/* 0FB474 7F0C6944 00000000 */   nop   
/* 0FB478 7F0C6948 AFB62B88 */  sw    $s6, 0x2b88($sp)
.L7F0C694C:
/* 0FB47C 7F0C694C 8FB62B88 */  lw    $s6, 0x2b88($sp)
/* 0FB480 7F0C6950 12A00010 */  beqz  $s5, .L7F0C6994
/* 0FB484 7F0C6954 00004025 */   move  $t0, $zero
/* 0FB488 7F0C6958 8FCC000C */  lw    $t4, 0xc($fp)
/* 0FB48C 7F0C695C 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D090)
/* 0FB490 7F0C6960 2442D090 */  addiu $v0, %lo(dword_CODE_bss_8008D090) # addiu $v0, $v0, -0x2f70
/* 0FB494 7F0C6964 8C450000 */  lw    $a1, ($v0)
/* 0FB498 7F0C6968 8D8A0000 */  lw    $t2, ($t4)
/* 0FB49C 7F0C696C 3C018009 */  lui   $at, %hi(word_CODE_bss_8008C730)
/* 0FB4A0 7F0C6970 00056900 */  sll   $t5, $a1, 4
/* 0FB4A4 7F0C6974 002D0821 */  addu  $at, $at, $t5
/* 0FB4A8 7F0C6978 000A5D02 */  srl   $t3, $t2, 0x14
/* 0FB4AC 7F0C697C A42BC730 */  sh    $t3, %lo(word_CODE_bss_8008C730)($at)
/* 0FB4B0 7F0C6980 24AE0001 */  addiu $t6, $a1, 1
/* 0FB4B4 7F0C6984 29C10096 */  slti  $at, $t6, 0x96
/* 0FB4B8 7F0C6988 14200002 */  bnez  $at, .L7F0C6994
/* 0FB4BC 7F0C698C AC4E0000 */   sw    $t6, ($v0)
/* 0FB4C0 7F0C6990 AC400000 */  sw    $zero, ($v0)
.L7F0C6994:
/* 0FB4C4 7F0C6994 8FB82BB0 */  lw    $t8, 0x2bb0($sp)
/* 0FB4C8 7F0C6998 8FAF2BB4 */  lw    $t7, 0x2bb4($sp)
/* 0FB4CC 7F0C699C 17000046 */  bnez  $t8, .L7F0C6AB8
/* 0FB4D0 7F0C69A0 29F90002 */   slti  $t9, $t7, 2
/* 0FB4D4 7F0C69A4 3B390001 */  xori  $t9, $t9, 1
/* 0FB4D8 7F0C69A8 1320003A */  beqz  $t9, .L7F0C6A94
/* 0FB4DC 7F0C69AC 8FAE2BB4 */   lw    $t6, 0x2bb4($sp)
/* 0FB4E0 7F0C69B0 8FB72BAC */  lw    $s7, 0x2bac($sp)
/* 0FB4E4 7F0C69B4 02C0A025 */  move  $s4, $s6
/* 0FB4E8 7F0C69B8 8FB52B84 */  lw    $s5, 0x2b84($sp)
/* 0FB4EC 7F0C69BC 24130001 */  li    $s3, 1
/* 0FB4F0 7F0C69C0 1320002C */  beqz  $t9, .L7F0C6A74
/* 0FB4F4 7F0C69C4 02F18021 */   addu  $s0, $s7, $s1
/* 0FB4F8 7F0C69C8 27B60070 */  addiu $s6, $sp, 0x70
.L7F0C69CC:
/* 0FB4FC 7F0C69CC 8FAA2B94 */  lw    $t2, 0x2b94($sp)
/* 0FB500 7F0C69D0 8FAB2B78 */  lw    $t3, 0x2b78($sp)
/* 0FB504 7F0C69D4 02E02025 */  move  $a0, $s7
/* 0FB508 7F0C69D8 02002825 */  move  $a1, $s0
/* 0FB50C 7F0C69DC 02803025 */  move  $a2, $s4
/* 0FB510 7F0C69E0 02A03825 */  move  $a3, $s5
/* 0FB514 7F0C69E4 AFB60014 */  sw    $s6, 0x14($sp)
/* 0FB518 7F0C69E8 AFA82BA4 */  sw    $t0, 0x2ba4($sp)
/* 0FB51C 7F0C69EC AFAA0010 */  sw    $t2, 0x10($sp)
/* 0FB520 7F0C69F0 0FC31B1C */  jal   sub_GAME_7F0C6C70
/* 0FB524 7F0C69F4 AFAB0018 */   sw    $t3, 0x18($sp)
/* 0FB528 7F0C69F8 02226821 */  addu  $t5, $s1, $v0
/* 0FB52C 7F0C69FC 29A10801 */  slti  $at, $t5, 0x801
/* 0FB530 7F0C6A00 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
/* 0FB534 7F0C6A04 14200008 */  bnez  $at, .L7F0C6A28
/* 0FB538 7F0C6A08 00409025 */   move  $s2, $v0
/* 0FB53C 7F0C6A0C 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB540 7F0C6A10 0013C140 */  sll   $t8, $s3, 5
/* 0FB544 7F0C6A14 906F000B */  lbu   $t7, 0xb($v1)
/* 0FB548 7F0C6A18 31ECFF1F */  andi  $t4, $t7, 0xff1f
/* 0FB54C 7F0C6A1C 030CC825 */  or    $t9, $t8, $t4
/* 0FB550 7F0C6A20 10000014 */  b     .L7F0C6A74
/* 0FB554 7F0C6A24 A079000B */   sb    $t9, 0xb($v1)
.L7F0C6A28:
/* 0FB558 7F0C6A28 02E02025 */  move  $a0, $s7
/* 0FB55C 7F0C6A2C 02802825 */  move  $a1, $s4
/* 0FB560 7F0C6A30 02A03025 */  move  $a2, $s5
/* 0FB564 7F0C6A34 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB568 7F0C6A38 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FB56C 7F0C6A3C AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB570 7F0C6A40 8FAD2BB4 */  lw    $t5, 0x2bb4($sp)
/* 0FB574 7F0C6A44 26940001 */  addiu $s4, $s4, 1
/* 0FB578 7F0C6A48 26B50001 */  addiu $s5, $s5, 1
/* 0FB57C 7F0C6A4C 26730001 */  addiu $s3, $s3, 1
/* 0FB580 7F0C6A50 00145043 */  sra   $t2, $s4, 1
/* 0FB584 7F0C6A54 00155843 */  sra   $t3, $s5, 1
/* 0FB588 7F0C6A58 0200B825 */  move  $s7, $s0
/* 0FB58C 7F0C6A5C 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
/* 0FB590 7F0C6A60 02328821 */  addu  $s1, $s1, $s2
/* 0FB594 7F0C6A64 0140A025 */  move  $s4, $t2
/* 0FB598 7F0C6A68 0160A825 */  move  $s5, $t3
/* 0FB59C 7F0C6A6C 166DFFD7 */  bne   $s3, $t5, .L7F0C69CC
/* 0FB5A0 7F0C6A70 02128021 */   addu  $s0, $s0, $s2
.L7F0C6A74:
/* 0FB5A4 7F0C6A74 02E02025 */  move  $a0, $s7
/* 0FB5A8 7F0C6A78 02802825 */  move  $a1, $s4
/* 0FB5AC 7F0C6A7C 02A03025 */  move  $a2, $s5
/* 0FB5B0 7F0C6A80 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB5B4 7F0C6A84 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FB5B8 7F0C6A88 AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB5BC 7F0C6A8C 1000000A */  b     .L7F0C6AB8
/* 0FB5C0 7F0C6A90 8FA82BA4 */   lw    $t0, 0x2ba4($sp)
.L7F0C6A94:
/* 0FB5C4 7F0C6A94 24010001 */  li    $at, 1
/* 0FB5C8 7F0C6A98 15C10007 */  bne   $t6, $at, .L7F0C6AB8
/* 0FB5CC 7F0C6A9C 8FA42BAC */   lw    $a0, 0x2bac($sp)
/* 0FB5D0 7F0C6AA0 02C02825 */  move  $a1, $s6
/* 0FB5D4 7F0C6AA4 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB5D8 7F0C6AA8 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB5DC 7F0C6AAC 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FB5E0 7F0C6AB0 AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB5E4 7F0C6AB4 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
.L7F0C6AB8:
/* 0FB5E8 7F0C6AB8 8FA92B78 */  lw    $t1, 0x2b78($sp)
/* 0FB5EC 7F0C6ABC 8FAF2BAC */  lw    $t7, 0x2bac($sp)
/* 0FB5F0 7F0C6AC0 2401FFF8 */  li    $at, -8
/* 0FB5F4 7F0C6AC4 19200032 */  blez  $t1, .L7F0C6B90
/* 0FB5F8 7F0C6AC8 31240003 */   andi  $a0, $t1, 3
/* 0FB5FC 7F0C6ACC 10800012 */  beqz  $a0, .L7F0C6B18
/* 0FB600 7F0C6AD0 01F18021 */   addu  $s0, $t7, $s1
/* 0FB604 7F0C6AD4 0008C040 */  sll   $t8, $t0, 1
/* 0FB608 7F0C6AD8 27AC0070 */  addiu $t4, $sp, 0x70
/* 0FB60C 7F0C6ADC 030C1821 */  addu  $v1, $t8, $t4
/* 0FB610 7F0C6AE0 00801025 */  move  $v0, $a0
.L7F0C6AE4:
/* 0FB614 7F0C6AE4 94790000 */  lhu   $t9, ($v1)
/* 0FB618 7F0C6AE8 25080001 */  addiu $t0, $t0, 1
/* 0FB61C 7F0C6AEC 26310002 */  addiu $s1, $s1, 2
/* 0FB620 7F0C6AF0 00195203 */  sra   $t2, $t9, 8
/* 0FB624 7F0C6AF4 A20A0000 */  sb    $t2, ($s0)
/* 0FB628 7F0C6AF8 946D0000 */  lhu   $t5, ($v1)
/* 0FB62C 7F0C6AFC 26100002 */  addiu $s0, $s0, 2
/* 0FB630 7F0C6B00 24630002 */  addiu $v1, $v1, 2
/* 0FB634 7F0C6B04 1448FFF7 */  bne   $v0, $t0, .L7F0C6AE4
/* 0FB638 7F0C6B08 A20DFFFF */   sb    $t5, -1($s0)
/* 0FB63C 7F0C6B0C 8FAE2B78 */  lw    $t6, 0x2b78($sp)
/* 0FB640 7F0C6B10 510E0020 */  beql  $t0, $t6, .L7F0C6B94
/* 0FB644 7F0C6B14 26310007 */   addiu $s1, $s1, 7
.L7F0C6B18:
/* 0FB648 7F0C6B18 8FB82B78 */  lw    $t8, 0x2b78($sp)
/* 0FB64C 7F0C6B1C 27A90070 */  addiu $t1, $sp, 0x70
/* 0FB650 7F0C6B20 00087840 */  sll   $t7, $t0, 1
/* 0FB654 7F0C6B24 00186040 */  sll   $t4, $t8, 1
/* 0FB658 7F0C6B28 01891021 */  addu  $v0, $t4, $t1
/* 0FB65C 7F0C6B2C 01E91821 */  addu  $v1, $t7, $t1
.L7F0C6B30:
/* 0FB660 7F0C6B30 94790000 */  lhu   $t9, ($v1)
/* 0FB664 7F0C6B34 24630008 */  addiu $v1, $v1, 8
/* 0FB668 7F0C6B38 26310008 */  addiu $s1, $s1, 8
/* 0FB66C 7F0C6B3C 00195203 */  sra   $t2, $t9, 8
/* 0FB670 7F0C6B40 A20A0000 */  sb    $t2, ($s0)
/* 0FB674 7F0C6B44 946DFFF8 */  lhu   $t5, -8($v1)
/* 0FB678 7F0C6B48 26100008 */  addiu $s0, $s0, 8
/* 0FB67C 7F0C6B4C A20DFFF9 */  sb    $t5, -7($s0)
/* 0FB680 7F0C6B50 946EFFFA */  lhu   $t6, -6($v1)
/* 0FB684 7F0C6B54 000E7A03 */  sra   $t7, $t6, 8
/* 0FB688 7F0C6B58 A20FFFFA */  sb    $t7, -6($s0)
/* 0FB68C 7F0C6B5C 946CFFFA */  lhu   $t4, -6($v1)
/* 0FB690 7F0C6B60 A20CFFFB */  sb    $t4, -5($s0)
/* 0FB694 7F0C6B64 9469FFFC */  lhu   $t1, -4($v1)
/* 0FB698 7F0C6B68 0009CA03 */  sra   $t9, $t1, 8
/* 0FB69C 7F0C6B6C A219FFFC */  sb    $t9, -4($s0)
/* 0FB6A0 7F0C6B70 946BFFFC */  lhu   $t3, -4($v1)
/* 0FB6A4 7F0C6B74 A20BFFFD */  sb    $t3, -3($s0)
/* 0FB6A8 7F0C6B78 946DFFFE */  lhu   $t5, -2($v1)
/* 0FB6AC 7F0C6B7C 000D7203 */  sra   $t6, $t5, 8
/* 0FB6B0 7F0C6B80 A20EFFFE */  sb    $t6, -2($s0)
/* 0FB6B4 7F0C6B84 9478FFFE */  lhu   $t8, -2($v1)
/* 0FB6B8 7F0C6B88 1462FFE9 */  bne   $v1, $v0, .L7F0C6B30
/* 0FB6BC 7F0C6B8C A218FFFF */   sb    $t8, -1($s0)
.L7F0C6B90:
/* 0FB6C0 7F0C6B90 26310007 */  addiu $s1, $s1, 7
.L7F0C6B94:
/* 0FB6C4 7F0C6B94 02211024 */  and   $v0, $s1, $at
.L7F0C6B98:
/* 0FB6C8 7F0C6B98 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0FB6CC 7F0C6B9C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FB6D0 7F0C6BA0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FB6D4 7F0C6BA4 8FB20030 */  lw    $s2, 0x30($sp)
/* 0FB6D8 7F0C6BA8 8FB30034 */  lw    $s3, 0x34($sp)
/* 0FB6DC 7F0C6BAC 8FB40038 */  lw    $s4, 0x38($sp)
/* 0FB6E0 7F0C6BB0 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0FB6E4 7F0C6BB4 8FB60040 */  lw    $s6, 0x40($sp)
/* 0FB6E8 7F0C6BB8 8FB70044 */  lw    $s7, 0x44($sp)
/* 0FB6EC 7F0C6BBC 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0FB6F0 7F0C6BC0 03E00008 */  jr    $ra
/* 0FB6F4 7F0C6BC4 27BD2BA8 */   addiu $sp, $sp, 0x2ba8
)
#endif





#ifdef NONMATCHING
void copy_loaded_image_to_final_mem_location(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_loaded_image_to_final_mem_location
/* 0FB6F8 7F0C6BC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB6FC 7F0C6BCC AFB1000C */  sw    $s1, 0xc($sp)
/* 0FB700 7F0C6BD0 AFB00008 */  sw    $s0, 8($sp)
/* 0FB704 7F0C6BD4 24010009 */  li    $at, 9
/* 0FB708 7F0C6BD8 00A08025 */  move  $s0, $a1
/* 0FB70C 7F0C6BDC 00808825 */  move  $s1, $a0
/* 0FB710 7F0C6BE0 10E10004 */  beq   $a3, $at, .L7F0C6BF4
/* 0FB714 7F0C6BE4 8FA30030 */   lw    $v1, 0x30($sp)
/* 0FB718 7F0C6BE8 2401000B */  li    $at, 11
/* 0FB71C 7F0C6BEC 54E10004 */  bnel  $a3, $at, .L7F0C6C00
/* 0FB720 7F0C6BF0 2401000A */   li    $at, 10
.L7F0C6BF4:
/* 0FB724 7F0C6BF4 10000008 */  b     .L7F0C6C18
/* 0FB728 7F0C6BF8 24020001 */   li    $v0, 1
/* 0FB72C 7F0C6BFC 2401000A */  li    $at, 10
.L7F0C6C00:
/* 0FB730 7F0C6C00 10E10003 */  beq   $a3, $at, .L7F0C6C10
/* 0FB734 7F0C6C04 2401000C */   li    $at, 12
/* 0FB738 7F0C6C08 14E10003 */  bne   $a3, $at, .L7F0C6C18
/* 0FB73C 7F0C6C0C 8FA20010 */   lw    $v0, 0x10($sp)
.L7F0C6C10:
/* 0FB740 7F0C6C10 10000001 */  b     .L7F0C6C18
/* 0FB744 7F0C6C14 24020002 */   li    $v0, 2
.L7F0C6C18:
/* 0FB748 7F0C6C18 18C0000F */  blez  $a2, .L7F0C6C58
/* 0FB74C 7F0C6C1C 00002025 */   move  $a0, $zero
/* 0FB750 7F0C6C20 2407FFF8 */  li    $a3, -8
.L7F0C6C24:
/* 0FB754 7F0C6C24 1A000008 */  blez  $s0, .L7F0C6C48
/* 0FB758 7F0C6C28 00002825 */   move  $a1, $zero
.L7F0C6C2C:
/* 0FB75C 7F0C6C2C 922E0000 */  lbu   $t6, ($s1)
/* 0FB760 7F0C6C30 00A22821 */  addu  $a1, $a1, $v0
/* 0FB764 7F0C6C34 00B0082A */  slt   $at, $a1, $s0
/* 0FB768 7F0C6C38 24630001 */  addiu $v1, $v1, 1
/* 0FB76C 7F0C6C3C 26310001 */  addiu $s1, $s1, 1
/* 0FB770 7F0C6C40 1420FFFA */  bnez  $at, .L7F0C6C2C
/* 0FB774 7F0C6C44 A06EFFFF */   sb    $t6, -1($v1)
.L7F0C6C48:
/* 0FB778 7F0C6C48 24840001 */  addiu $a0, $a0, 1
/* 0FB77C 7F0C6C4C 246F0007 */  addiu $t7, $v1, 7
/* 0FB780 7F0C6C50 1486FFF4 */  bne   $a0, $a2, .L7F0C6C24
/* 0FB784 7F0C6C54 01E71824 */   and   $v1, $t7, $a3
.L7F0C6C58:
/* 0FB788 7F0C6C58 8FB80030 */  lw    $t8, 0x30($sp)
/* 0FB78C 7F0C6C5C 8FB00008 */  lw    $s0, 8($sp)
/* 0FB790 7F0C6C60 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FB794 7F0C6C64 27BD0020 */  addiu $sp, $sp, 0x20
/* 0FB798 7F0C6C68 03E00008 */  jr    $ra
/* 0FB79C 7F0C6C6C 00781023 */   subu  $v0, $v1, $t8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C6C70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C6C70
/* 0FB7A0 7F0C6C70 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 0FB7A4 7F0C6C74 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FB7A8 7F0C6C78 8FB000B8 */  lw    $s0, 0xb8($sp)
/* 0FB7AC 7F0C6C7C 24EF0001 */  addiu $t7, $a3, 1
/* 0FB7B0 7F0C6C80 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0FB7B4 7F0C6C84 AFB50034 */  sw    $s5, 0x34($sp)
/* 0FB7B8 7F0C6C88 24020009 */  li    $v0, 9
/* 0FB7BC 7F0C6C8C 000FC043 */  sra   $t8, $t7, 1
/* 0FB7C0 7F0C6C90 00C0F025 */  move  $fp, $a2
/* 0FB7C4 7F0C6C94 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0FB7C8 7F0C6C98 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0FB7CC 7F0C6C9C AFB60038 */  sw    $s6, 0x38($sp)
/* 0FB7D0 7F0C6CA0 AFB40030 */  sw    $s4, 0x30($sp)
/* 0FB7D4 7F0C6CA4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0FB7D8 7F0C6CA8 AFB20028 */  sw    $s2, 0x28($sp)
/* 0FB7DC 7F0C6CAC AFB10024 */  sw    $s1, 0x24($sp)
/* 0FB7E0 7F0C6CB0 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 0FB7E4 7F0C6CB4 AFA50074 */  sw    $a1, 0x74($sp)
/* 0FB7E8 7F0C6CB8 0080A825 */  move  $s5, $a0
/* 0FB7EC 7F0C6CBC AFB80060 */  sw    $t8, 0x60($sp)
/* 0FB7F0 7F0C6CC0 1202000B */  beq   $s0, $v0, .L7F0C6CF0
/* 0FB7F4 7F0C6CC4 AFB80094 */   sw    $t8, 0x94($sp)
/* 0FB7F8 7F0C6CC8 2401000A */  li    $at, 10
/* 0FB7FC 7F0C6CCC 12010011 */  beq   $s0, $at, .L7F0C6D14
/* 0FB800 7F0C6CD0 27CF0001 */   addiu $t7, $fp, 1
/* 0FB804 7F0C6CD4 2401000B */  li    $at, 11
/* 0FB808 7F0C6CD8 12010005 */  beq   $s0, $at, .L7F0C6CF0
/* 0FB80C 7F0C6CDC 2401000C */   li    $at, 12
/* 0FB810 7F0C6CE0 5201000D */  beql  $s0, $at, .L7F0C6D18
/* 0FB814 7F0C6CE4 000FC043 */   sra   $t8, $t7, 1
/* 0FB818 7F0C6CE8 10000011 */  b     .L7F0C6D30
/* 0FB81C 7F0C6CEC 00000000 */   nop   
.L7F0C6CF0:
/* 0FB820 7F0C6CF0 27D90001 */  addiu $t9, $fp, 1
/* 0FB824 7F0C6CF4 00195043 */  sra   $t2, $t9, 1
/* 0FB828 7F0C6CF8 254B0007 */  addiu $t3, $t2, 7
/* 0FB82C 7F0C6CFC 27CD0007 */  addiu $t5, $fp, 7
/* 0FB830 7F0C6D00 316C0FF8 */  andi  $t4, $t3, 0xff8
/* 0FB834 7F0C6D04 31AE0FF8 */  andi  $t6, $t5, 0xff8
/* 0FB838 7F0C6D08 AFAC0098 */  sw    $t4, 0x98($sp)
/* 0FB83C 7F0C6D0C 10000008 */  b     .L7F0C6D30
/* 0FB840 7F0C6D10 AFAE009C */   sw    $t6, 0x9c($sp)
.L7F0C6D14:
/* 0FB844 7F0C6D14 000FC043 */  sra   $t8, $t7, 1
.L7F0C6D18:
/* 0FB848 7F0C6D18 2719000F */  addiu $t9, $t8, 0xf
/* 0FB84C 7F0C6D1C 27CB000F */  addiu $t3, $fp, 0xf
/* 0FB850 7F0C6D20 332A0FF0 */  andi  $t2, $t9, 0xff0
/* 0FB854 7F0C6D24 316C0FF0 */  andi  $t4, $t3, 0xff0
/* 0FB858 7F0C6D28 AFAA0098 */  sw    $t2, 0x98($sp)
/* 0FB85C 7F0C6D2C AFAC009C */  sw    $t4, 0x9c($sp)
.L7F0C6D30:
/* 0FB860 7F0C6D30 12020009 */  beq   $s0, $v0, .L7F0C6D58
/* 0FB864 7F0C6D34 2401000A */   li    $at, 10
/* 0FB868 7F0C6D38 120100ED */  beq   $s0, $at, .L7F0C70F0
/* 0FB86C 7F0C6D3C 2401000B */   li    $at, 11
/* 0FB870 7F0C6D40 12010086 */  beq   $s0, $at, .L7F0C6F5C
/* 0FB874 7F0C6D44 2401000C */   li    $at, 12
/* 0FB878 7F0C6D48 120101D9 */  beq   $s0, $at, .L7F0C74B0
/* 0FB87C 7F0C6D4C 00001025 */   move  $v0, $zero
/* 0FB880 7F0C6D50 1000028A */  b     .L7F0C777C
/* 0FB884 7F0C6D54 00000000 */   nop   
.L7F0C6D58:
/* 0FB888 7F0C6D58 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FB88C 7F0C6D5C 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0FB890 7F0C6D60 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FB894 7F0C6D64 19A00077 */  blez  $t5, .L7F0C6F44
/* 0FB898 7F0C6D68 000E7840 */   sll   $t7, $t6, 1
/* 0FB89C 7F0C6D6C AFAF0050 */  sw    $t7, 0x50($sp)
/* 0FB8A0 7F0C6D70 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FB8A4 7F0C6D74 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C6D78:
/* 0FB8A8 7F0C6D78 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0FB8AC 7F0C6D7C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FB8B0 7F0C6D80 00008825 */  move  $s1, $zero
/* 0FB8B4 7F0C6D84 272A0001 */  addiu $t2, $t9, 1
/* 0FB8B8 7F0C6D88 0158082A */  slt   $at, $t2, $t8
/* 0FB8BC 7F0C6D8C 10200003 */  beqz  $at, .L7F0C6D9C
/* 0FB8C0 7F0C6D90 8FAB009C */   lw    $t3, 0x9c($sp)
/* 0FB8C4 7F0C6D94 10000002 */  b     .L7F0C6DA0
/* 0FB8C8 7F0C6D98 8FB6009C */   lw    $s6, 0x9c($sp)
.L7F0C6D9C:
/* 0FB8CC 7F0C6D9C 0000B025 */  move  $s6, $zero
.L7F0C6DA0:
/* 0FB8D0 7F0C6DA0 1960005C */  blez  $t3, .L7F0C6F14
/* 0FB8D4 7F0C6DA4 02A09025 */   move  $s2, $s5
/* 0FB8D8 7F0C6DA8 02D5A021 */  addu  $s4, $s6, $s5
/* 0FB8DC 7F0C6DAC 26220001 */  addiu $v0, $s1, 1
.L7F0C6DB0:
/* 0FB8E0 7F0C6DB0 005E082A */  slt   $at, $v0, $fp
/* 0FB8E4 7F0C6DB4 10200003 */  beqz  $at, .L7F0C6DC4
/* 0FB8E8 7F0C6DB8 02602025 */   move  $a0, $s3
/* 0FB8EC 7F0C6DBC 10000002 */  b     .L7F0C6DC8
/* 0FB8F0 7F0C6DC0 00401825 */   move  $v1, $v0
.L7F0C6DC4:
/* 0FB8F4 7F0C6DC4 02201825 */  move  $v1, $s1
.L7F0C6DC8:
/* 0FB8F8 7F0C6DC8 924C0000 */  lbu   $t4, ($s2)
/* 0FB8FC 7F0C6DCC 02A37821 */  addu  $t7, $s5, $v1
/* 0FB900 7F0C6DD0 91F90000 */  lbu   $t9, ($t7)
/* 0FB904 7F0C6DD4 000C6840 */  sll   $t5, $t4, 1
/* 0FB908 7F0C6DD8 026D7021 */  addu  $t6, $s3, $t5
/* 0FB90C 7F0C6DDC 85D00000 */  lh    $s0, ($t6)
/* 0FB910 7F0C6DE0 02C37021 */  addu  $t6, $s6, $v1
/* 0FB914 7F0C6DE4 928B0000 */  lbu   $t3, ($s4)
/* 0FB918 7F0C6DE8 01D57821 */  addu  $t7, $t6, $s5
/* 0FB91C 7F0C6DEC 0019C040 */  sll   $t8, $t9, 1
/* 0FB920 7F0C6DF0 91F90000 */  lbu   $t9, ($t7)
/* 0FB924 7F0C6DF4 02785021 */  addu  $t2, $s3, $t8
/* 0FB928 7F0C6DF8 85480000 */  lh    $t0, ($t2)
/* 0FB92C 7F0C6DFC 000B6040 */  sll   $t4, $t3, 1
/* 0FB930 7F0C6E00 026C6821 */  addu  $t5, $s3, $t4
/* 0FB934 7F0C6E04 0019C040 */  sll   $t8, $t9, 1
/* 0FB938 7F0C6E08 85A90000 */  lh    $t1, ($t5)
/* 0FB93C 7F0C6E0C 02785021 */  addu  $t2, $s3, $t8
/* 0FB940 7F0C6E10 85420000 */  lh    $v0, ($t2)
/* 0FB944 7F0C6E14 00105AC3 */  sra   $t3, $s0, 0xb
/* 0FB948 7F0C6E18 316C001F */  andi  $t4, $t3, 0x1f
/* 0FB94C 7F0C6E1C 00086AC3 */  sra   $t5, $t0, 0xb
/* 0FB950 7F0C6E20 31AE001F */  andi  $t6, $t5, 0x1f
/* 0FB954 7F0C6E24 0009CAC3 */  sra   $t9, $t1, 0xb
/* 0FB958 7F0C6E28 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB95C 7F0C6E2C 018E7821 */  addu  $t7, $t4, $t6
/* 0FB960 7F0C6E30 00025AC3 */  sra   $t3, $v0, 0xb
/* 0FB964 7F0C6E34 316D001F */  andi  $t5, $t3, 0x1f
/* 0FB968 7F0C6E38 01F85021 */  addu  $t2, $t7, $t8
/* 0FB96C 7F0C6E3C 014D3021 */  addu  $a2, $t2, $t5
/* 0FB970 7F0C6E40 0010C983 */  sra   $t9, $s0, 6
/* 0FB974 7F0C6E44 332F001F */  andi  $t7, $t9, 0x1f
/* 0FB978 7F0C6E48 00066083 */  sra   $t4, $a2, 2
/* 0FB97C 7F0C6E4C 0008C183 */  sra   $t8, $t0, 6
/* 0FB980 7F0C6E50 330B001F */  andi  $t3, $t8, 0x1f
/* 0FB984 7F0C6E54 3186001F */  andi  $a2, $t4, 0x1f
/* 0FB988 7F0C6E58 00096983 */  sra   $t5, $t1, 6
/* 0FB98C 7F0C6E5C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FB990 7F0C6E60 01EB5021 */  addu  $t2, $t7, $t3
/* 0FB994 7F0C6E64 0002C983 */  sra   $t9, $v0, 6
/* 0FB998 7F0C6E68 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB99C 7F0C6E6C 014C7021 */  addu  $t6, $t2, $t4
/* 0FB9A0 7F0C6E70 01D83821 */  addu  $a3, $t6, $t8
/* 0FB9A4 7F0C6E74 00106843 */  sra   $t5, $s0, 1
/* 0FB9A8 7F0C6E78 31AA001F */  andi  $t2, $t5, 0x1f
/* 0FB9AC 7F0C6E7C 00077883 */  sra   $t7, $a3, 2
/* 0FB9B0 7F0C6E80 00086043 */  sra   $t4, $t0, 1
/* 0FB9B4 7F0C6E84 3199001F */  andi  $t9, $t4, 0x1f
/* 0FB9B8 7F0C6E88 31E7001F */  andi  $a3, $t7, 0x1f
/* 0FB9BC 7F0C6E8C 0009C043 */  sra   $t8, $t1, 1
/* 0FB9C0 7F0C6E90 330F001F */  andi  $t7, $t8, 0x1f
/* 0FB9C4 7F0C6E94 01597021 */  addu  $t6, $t2, $t9
/* 0FB9C8 7F0C6E98 00026843 */  sra   $t5, $v0, 1
/* 0FB9CC 7F0C6E9C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FB9D0 7F0C6EA0 01CF5821 */  addu  $t3, $t6, $t7
/* 0FB9D4 7F0C6EA4 016C5021 */  addu  $t2, $t3, $t4
/* 0FB9D8 7F0C6EA8 000AC883 */  sra   $t9, $t2, 2
/* 0FB9DC 7F0C6EAC 320E0001 */  andi  $t6, $s0, 1
/* 0FB9E0 7F0C6EB0 310F0001 */  andi  $t7, $t0, 1
/* 0FB9E4 7F0C6EB4 01CF6821 */  addu  $t5, $t6, $t7
/* 0FB9E8 7F0C6EB8 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB9EC 7F0C6EBC 312B0001 */  andi  $t3, $t1, 1
/* 0FB9F0 7F0C6EC0 01AB6021 */  addu  $t4, $t5, $t3
/* 0FB9F4 7F0C6EC4 304A0001 */  andi  $t2, $v0, 1
/* 0FB9F8 7F0C6EC8 018AC821 */  addu  $t9, $t4, $t2
/* 0FB9FC 7F0C6ECC AFB80010 */  sw    $t8, 0x10($sp)
/* 0FBA00 7F0C6ED0 27380002 */  addiu $t8, $t9, 2
/* 0FBA04 7F0C6ED4 00187083 */  sra   $t6, $t8, 2
/* 0FBA08 7F0C6ED8 31CF0001 */  andi  $t7, $t6, 1
/* 0FBA0C 7F0C6EDC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FBA10 7F0C6EE0 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBA14 7F0C6EE4 02E02825 */   move  $a1, $s7
/* 0FBA18 7F0C6EE8 8FAD0074 */  lw    $t5, 0x74($sp)
/* 0FBA1C 7F0C6EEC 00115843 */  sra   $t3, $s1, 1
/* 0FBA20 7F0C6EF0 26310002 */  addiu $s1, $s1, 2
/* 0FBA24 7F0C6EF4 01AB6021 */  addu  $t4, $t5, $t3
/* 0FBA28 7F0C6EF8 A1820000 */  sb    $v0, ($t4)
/* 0FBA2C 7F0C6EFC 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBA30 7F0C6F00 26520002 */  addiu $s2, $s2, 2
/* 0FBA34 7F0C6F04 26940002 */  addiu $s4, $s4, 2
/* 0FBA38 7F0C6F08 022A082A */  slt   $at, $s1, $t2
/* 0FBA3C 7F0C6F0C 5420FFA8 */  bnezl $at, .L7F0C6DB0
/* 0FBA40 7F0C6F10 26220001 */   addiu $v0, $s1, 1
.L7F0C6F14:
/* 0FBA44 7F0C6F14 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 0FBA48 7F0C6F18 8FAC00B4 */  lw    $t4, 0xb4($sp)
/* 0FBA4C 7F0C6F1C 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FBA50 7F0C6F20 8FB80098 */  lw    $t8, 0x98($sp)
/* 0FBA54 7F0C6F24 8FAF0050 */  lw    $t7, 0x50($sp)
/* 0FBA58 7F0C6F28 25AB0002 */  addiu $t3, $t5, 2
/* 0FBA5C 7F0C6F2C 016C082A */  slt   $at, $t3, $t4
/* 0FBA60 7F0C6F30 03387021 */  addu  $t6, $t9, $t8
/* 0FBA64 7F0C6F34 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FBA68 7F0C6F38 AFAE0074 */  sw    $t6, 0x74($sp)
/* 0FBA6C 7F0C6F3C 1420FF8E */  bnez  $at, .L7F0C6D78
/* 0FBA70 7F0C6F40 02AFA821 */   addu  $s5, $s5, $t7
.L7F0C6F44:
/* 0FBA74 7F0C6F44 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0FBA78 7F0C6F48 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBA7C 7F0C6F4C 01590019 */  multu $t2, $t9
/* 0FBA80 7F0C6F50 00001012 */  mflo  $v0
/* 0FBA84 7F0C6F54 1000020A */  b     .L7F0C7780
/* 0FBA88 7F0C6F58 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C6F5C:
/* 0FBA8C 7F0C6F5C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FBA90 7F0C6F60 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0FBA94 7F0C6F64 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBA98 7F0C6F68 1B00005B */  blez  $t8, .L7F0C70D8
/* 0FBA9C 7F0C6F6C 000E7840 */   sll   $t7, $t6, 1
/* 0FBAA0 7F0C6F70 AFAF0050 */  sw    $t7, 0x50($sp)
/* 0FBAA4 7F0C6F74 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBAA8 7F0C6F78 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C6F7C:
/* 0FBAAC 7F0C6F7C 8FAB00A0 */  lw    $t3, 0xa0($sp)
/* 0FBAB0 7F0C6F80 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBAB4 7F0C6F84 00008825 */  move  $s1, $zero
/* 0FBAB8 7F0C6F88 256C0001 */  addiu $t4, $t3, 1
/* 0FBABC 7F0C6F8C 018D082A */  slt   $at, $t4, $t5
/* 0FBAC0 7F0C6F90 10200003 */  beqz  $at, .L7F0C6FA0
/* 0FBAC4 7F0C6F94 8FAA009C */   lw    $t2, 0x9c($sp)
/* 0FBAC8 7F0C6F98 10000002 */  b     .L7F0C6FA4
/* 0FBACC 7F0C6F9C 8FB6009C */   lw    $s6, 0x9c($sp)
.L7F0C6FA0:
/* 0FBAD0 7F0C6FA0 0000B025 */  move  $s6, $zero
.L7F0C6FA4:
/* 0FBAD4 7F0C6FA4 19400040 */  blez  $t2, .L7F0C70A8
/* 0FBAD8 7F0C6FA8 02A09025 */   move  $s2, $s5
/* 0FBADC 7F0C6FAC 02D5A021 */  addu  $s4, $s6, $s5
/* 0FBAE0 7F0C6FB0 26220001 */  addiu $v0, $s1, 1
.L7F0C6FB4:
/* 0FBAE4 7F0C6FB4 005E082A */  slt   $at, $v0, $fp
/* 0FBAE8 7F0C6FB8 10200003 */  beqz  $at, .L7F0C6FC8
/* 0FBAEC 7F0C6FBC 02602025 */   move  $a0, $s3
/* 0FBAF0 7F0C6FC0 10000002 */  b     .L7F0C6FCC
/* 0FBAF4 7F0C6FC4 00401825 */   move  $v1, $v0
.L7F0C6FC8:
/* 0FBAF8 7F0C6FC8 02201825 */  move  $v1, $s1
.L7F0C6FCC:
/* 0FBAFC 7F0C6FCC 92590000 */  lbu   $t9, ($s2)
/* 0FBB00 7F0C6FD0 02A37821 */  addu  $t7, $s5, $v1
/* 0FBB04 7F0C6FD4 91EB0000 */  lbu   $t3, ($t7)
/* 0FBB08 7F0C6FD8 0019C040 */  sll   $t8, $t9, 1
/* 0FBB0C 7F0C6FDC 02787021 */  addu  $t6, $s3, $t8
/* 0FBB10 7F0C6FE0 85D00000 */  lh    $s0, ($t6)
/* 0FBB14 7F0C6FE4 928A0000 */  lbu   $t2, ($s4)
/* 0FBB18 7F0C6FE8 02C37021 */  addu  $t6, $s6, $v1
/* 0FBB1C 7F0C6FEC 01D57821 */  addu  $t7, $t6, $s5
/* 0FBB20 7F0C6FF0 000B6840 */  sll   $t5, $t3, 1
/* 0FBB24 7F0C6FF4 91EB0000 */  lbu   $t3, ($t7)
/* 0FBB28 7F0C6FF8 026D6021 */  addu  $t4, $s3, $t5
/* 0FBB2C 7F0C6FFC 000AC840 */  sll   $t9, $t2, 1
/* 0FBB30 7F0C7000 85880000 */  lh    $t0, ($t4)
/* 0FBB34 7F0C7004 0279C021 */  addu  $t8, $s3, $t9
/* 0FBB38 7F0C7008 87090000 */  lh    $t1, ($t8)
/* 0FBB3C 7F0C700C 000B6840 */  sll   $t5, $t3, 1
/* 0FBB40 7F0C7010 026D6021 */  addu  $t4, $s3, $t5
/* 0FBB44 7F0C7014 85820000 */  lh    $v0, ($t4)
/* 0FBB48 7F0C7018 00105203 */  sra   $t2, $s0, 8
/* 0FBB4C 7F0C701C 0008C203 */  sra   $t8, $t0, 8
/* 0FBB50 7F0C7020 330E00FF */  andi  $t6, $t8, 0xff
/* 0FBB54 7F0C7024 315900FF */  andi  $t9, $t2, 0xff
/* 0FBB58 7F0C7028 00095A03 */  sra   $t3, $t1, 8
/* 0FBB5C 7F0C702C 316D00FF */  andi  $t5, $t3, 0xff
/* 0FBB60 7F0C7030 032E7821 */  addu  $t7, $t9, $t6
/* 0FBB64 7F0C7034 01ED6021 */  addu  $t4, $t7, $t5
/* 0FBB68 7F0C7038 00025203 */  sra   $t2, $v0, 8
/* 0FBB6C 7F0C703C 315800FF */  andi  $t8, $t2, 0xff
/* 0FBB70 7F0C7040 01983021 */  addu  $a2, $t4, $t8
/* 0FBB74 7F0C7044 320B00FF */  andi  $t3, $s0, 0xff
/* 0FBB78 7F0C7048 310F00FF */  andi  $t7, $t0, 0xff
/* 0FBB7C 7F0C704C 016F6821 */  addu  $t5, $t3, $t7
/* 0FBB80 7F0C7050 312A00FF */  andi  $t2, $t1, 0xff
/* 0FBB84 7F0C7054 01AA6021 */  addu  $t4, $t5, $t2
/* 0FBB88 7F0C7058 305800FF */  andi  $t8, $v0, 0xff
/* 0FBB8C 7F0C705C 01983821 */  addu  $a3, $t4, $t8
/* 0FBB90 7F0C7060 0006C883 */  sra   $t9, $a2, 2
/* 0FBB94 7F0C7064 332600FF */  andi  $a2, $t9, 0xff
/* 0FBB98 7F0C7068 24E70001 */  addiu $a3, $a3, 1
/* 0FBB9C 7F0C706C 0007C883 */  sra   $t9, $a3, 2
/* 0FBBA0 7F0C7070 332700FF */  andi  $a3, $t9, 0xff
/* 0FBBA4 7F0C7074 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FBBA8 7F0C7078 02E02825 */   move  $a1, $s7
/* 0FBBAC 7F0C707C 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0FBBB0 7F0C7080 00117843 */  sra   $t7, $s1, 1
/* 0FBBB4 7F0C7084 26310002 */  addiu $s1, $s1, 2
/* 0FBBB8 7F0C7088 016F6821 */  addu  $t5, $t3, $t7
/* 0FBBBC 7F0C708C A1A20000 */  sb    $v0, ($t5)
/* 0FBBC0 7F0C7090 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBBC4 7F0C7094 26520002 */  addiu $s2, $s2, 2
/* 0FBBC8 7F0C7098 26940002 */  addiu $s4, $s4, 2
/* 0FBBCC 7F0C709C 022A082A */  slt   $at, $s1, $t2
/* 0FBBD0 7F0C70A0 5420FFC4 */  bnezl $at, .L7F0C6FB4
/* 0FBBD4 7F0C70A4 26220001 */   addiu $v0, $s1, 1
.L7F0C70A8:
/* 0FBBD8 7F0C70A8 8FAB00A0 */  lw    $t3, 0xa0($sp)
/* 0FBBDC 7F0C70AC 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBBE0 7F0C70B0 8FAC0074 */  lw    $t4, 0x74($sp)
/* 0FBBE4 7F0C70B4 8FB80098 */  lw    $t8, 0x98($sp)
/* 0FBBE8 7F0C70B8 8FAE0050 */  lw    $t6, 0x50($sp)
/* 0FBBEC 7F0C70BC 256F0002 */  addiu $t7, $t3, 2
/* 0FBBF0 7F0C70C0 01ED082A */  slt   $at, $t7, $t5
/* 0FBBF4 7F0C70C4 0198C821 */  addu  $t9, $t4, $t8
/* 0FBBF8 7F0C70C8 AFAF00A0 */  sw    $t7, 0xa0($sp)
/* 0FBBFC 7F0C70CC AFB90074 */  sw    $t9, 0x74($sp)
/* 0FBC00 7F0C70D0 1420FFAA */  bnez  $at, .L7F0C6F7C
/* 0FBC04 7F0C70D4 02AEA821 */   addu  $s5, $s5, $t6
.L7F0C70D8:
/* 0FBC08 7F0C70D8 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0FBC0C 7F0C70DC 8FAC0098 */  lw    $t4, 0x98($sp)
/* 0FBC10 7F0C70E0 014C0019 */  multu $t2, $t4
/* 0FBC14 7F0C70E4 00001012 */  mflo  $v0
/* 0FBC18 7F0C70E8 100001A5 */  b     .L7F0C7780
/* 0FBC1C 7F0C70EC 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C70F0:
/* 0FBC20 7F0C70F0 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FBC24 7F0C70F4 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBC28 7F0C70F8 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBC2C 7F0C70FC 1B0000E5 */  blez  $t8, .L7F0C7494
/* 0FBC30 7F0C7100 00197043 */   sra   $t6, $t9, 1
/* 0FBC34 7F0C7104 AFAE004C */  sw    $t6, 0x4c($sp)
/* 0FBC38 7F0C7108 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBC3C 7F0C710C 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C7110:
/* 0FBC40 7F0C7110 8FAF00A0 */  lw    $t7, 0xa0($sp)
/* 0FBC44 7F0C7114 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 0FBC48 7F0C7118 00008825 */  move  $s1, $zero
/* 0FBC4C 7F0C711C 25ED0001 */  addiu $t5, $t7, 1
/* 0FBC50 7F0C7120 01AB082A */  slt   $at, $t5, $t3
/* 0FBC54 7F0C7124 10200005 */  beqz  $at, .L7F0C713C
/* 0FBC58 7F0C7128 8FAC009C */   lw    $t4, 0x9c($sp)
/* 0FBC5C 7F0C712C 8FB6009C */  lw    $s6, 0x9c($sp)
/* 0FBC60 7F0C7130 00165043 */  sra   $t2, $s6, 1
/* 0FBC64 7F0C7134 10000002 */  b     .L7F0C7140
/* 0FBC68 7F0C7138 0140B025 */   move  $s6, $t2
.L7F0C713C:
/* 0FBC6C 7F0C713C 0000B025 */  move  $s6, $zero
.L7F0C7140:
/* 0FBC70 7F0C7140 198000C8 */  blez  $t4, .L7F0C7464
/* 0FBC74 7F0C7144 02B6A021 */   addu  $s4, $s5, $s6
/* 0FBC78 7F0C7148 00112843 */  sra   $a1, $s1, 1
.L7F0C714C:
/* 0FBC7C 7F0C714C 00B5C021 */  addu  $t8, $a1, $s5
/* 0FBC80 7F0C7150 93020000 */  lbu   $v0, ($t8)
/* 0FBC84 7F0C7154 262D0001 */  addiu $t5, $s1, 1
/* 0FBC88 7F0C7158 01BE202A */  slt   $a0, $t5, $fp
/* 0FBC8C 7F0C715C 0002C903 */  sra   $t9, $v0, 4
/* 0FBC90 7F0C7160 332E000F */  andi  $t6, $t9, 0xf
/* 0FBC94 7F0C7164 000E7840 */  sll   $t7, $t6, 1
/* 0FBC98 7F0C7168 026F5821 */  addu  $t3, $s3, $t7
/* 0FBC9C 7F0C716C 10800003 */  beqz  $a0, .L7F0C717C
/* 0FBCA0 7F0C7170 85700000 */   lh    $s0, ($t3)
/* 0FBCA4 7F0C7174 10000002 */  b     .L7F0C7180
/* 0FBCA8 7F0C7178 00001825 */   move  $v1, $zero
.L7F0C717C:
/* 0FBCAC 7F0C717C 24030004 */  li    $v1, 4
.L7F0C7180:
/* 0FBCB0 7F0C7180 00B67021 */  addu  $t6, $a1, $s6
/* 0FBCB4 7F0C7184 01D57821 */  addu  $t7, $t6, $s5
/* 0FBCB8 7F0C7188 91EB0000 */  lbu   $t3, ($t7)
/* 0FBCBC 7F0C718C 00625007 */  srav  $t2, $v0, $v1
/* 0FBCC0 7F0C7190 314C000F */  andi  $t4, $t2, 0xf
/* 0FBCC4 7F0C7194 000CC040 */  sll   $t8, $t4, 1
/* 0FBCC8 7F0C7198 000B6903 */  sra   $t5, $t3, 4
/* 0FBCCC 7F0C719C 31AA000F */  andi  $t2, $t5, 0xf
/* 0FBCD0 7F0C71A0 0278C821 */  addu  $t9, $s3, $t8
/* 0FBCD4 7F0C71A4 000A6040 */  sll   $t4, $t2, 1
/* 0FBCD8 7F0C71A8 026CC021 */  addu  $t8, $s3, $t4
/* 0FBCDC 7F0C71AC 87280000 */  lh    $t0, ($t9)
/* 0FBCE0 7F0C71B0 10800003 */  beqz  $a0, .L7F0C71C0
/* 0FBCE4 7F0C71B4 87090000 */   lh    $t1, ($t8)
/* 0FBCE8 7F0C71B8 10000002 */  b     .L7F0C71C4
/* 0FBCEC 7F0C71BC 00001825 */   move  $v1, $zero
.L7F0C71C0:
/* 0FBCF0 7F0C71C0 24030004 */  li    $v1, 4
.L7F0C71C4:
/* 0FBCF4 7F0C71C4 0285C821 */  addu  $t9, $s4, $a1
/* 0FBCF8 7F0C71C8 932E0000 */  lbu   $t6, ($t9)
/* 0FBCFC 7F0C71CC 001062C3 */  sra   $t4, $s0, 0xb
/* 0FBD00 7F0C71D0 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBD04 7F0C71D4 006E7807 */  srav  $t7, $t6, $v1
/* 0FBD08 7F0C71D8 31EB000F */  andi  $t3, $t7, 0xf
/* 0FBD0C 7F0C71DC 000B6840 */  sll   $t5, $t3, 1
/* 0FBD10 7F0C71E0 026D5021 */  addu  $t2, $s3, $t5
/* 0FBD14 7F0C71E4 85420000 */  lh    $v0, ($t2)
/* 0FBD18 7F0C71E8 0008CAC3 */  sra   $t9, $t0, 0xb
/* 0FBD1C 7F0C71EC 332E001F */  andi  $t6, $t9, 0x1f
/* 0FBD20 7F0C71F0 00095AC3 */  sra   $t3, $t1, 0xb
/* 0FBD24 7F0C71F4 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBD28 7F0C71F8 030E7821 */  addu  $t7, $t8, $t6
/* 0FBD2C 7F0C71FC 000262C3 */  sra   $t4, $v0, 0xb
/* 0FBD30 7F0C7200 3199001F */  andi  $t9, $t4, 0x1f
/* 0FBD34 7F0C7204 01ED5021 */  addu  $t2, $t7, $t5
/* 0FBD38 7F0C7208 01593021 */  addu  $a2, $t2, $t9
/* 0FBD3C 7F0C720C 00105983 */  sra   $t3, $s0, 6
/* 0FBD40 7F0C7210 316F001F */  andi  $t7, $t3, 0x1f
/* 0FBD44 7F0C7214 0006C083 */  sra   $t8, $a2, 2
/* 0FBD48 7F0C7218 00086983 */  sra   $t5, $t0, 6
/* 0FBD4C 7F0C721C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FBD50 7F0C7220 3306001F */  andi  $a2, $t8, 0x1f
/* 0FBD54 7F0C7224 0009C983 */  sra   $t9, $t1, 6
/* 0FBD58 7F0C7228 3338001F */  andi  $t8, $t9, 0x1f
/* 0FBD5C 7F0C722C 01EC5021 */  addu  $t2, $t7, $t4
/* 0FBD60 7F0C7230 00025983 */  sra   $t3, $v0, 6
/* 0FBD64 7F0C7234 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBD68 7F0C7238 01587021 */  addu  $t6, $t2, $t8
/* 0FBD6C 7F0C723C 01CD3821 */  addu  $a3, $t6, $t5
/* 0FBD70 7F0C7240 0010C843 */  sra   $t9, $s0, 1
/* 0FBD74 7F0C7244 332A001F */  andi  $t2, $t9, 0x1f
/* 0FBD78 7F0C7248 00077883 */  sra   $t7, $a3, 2
/* 0FBD7C 7F0C724C 0008C043 */  sra   $t8, $t0, 1
/* 0FBD80 7F0C7250 330B001F */  andi  $t3, $t8, 0x1f
/* 0FBD84 7F0C7254 31E7001F */  andi  $a3, $t7, 0x1f
/* 0FBD88 7F0C7258 00096843 */  sra   $t5, $t1, 1
/* 0FBD8C 7F0C725C 31AF001F */  andi  $t7, $t5, 0x1f
/* 0FBD90 7F0C7260 014B7021 */  addu  $t6, $t2, $t3
/* 0FBD94 7F0C7264 0002C843 */  sra   $t9, $v0, 1
/* 0FBD98 7F0C7268 3338001F */  andi  $t8, $t9, 0x1f
/* 0FBD9C 7F0C726C 01CF6021 */  addu  $t4, $t6, $t7
/* 0FBDA0 7F0C7270 01985021 */  addu  $t2, $t4, $t8
/* 0FBDA4 7F0C7274 000A5883 */  sra   $t3, $t2, 2
/* 0FBDA8 7F0C7278 310F0001 */  andi  $t7, $t0, 1
/* 0FBDAC 7F0C727C 320E0001 */  andi  $t6, $s0, 1
/* 0FBDB0 7F0C7280 01CFC821 */  addu  $t9, $t6, $t7
/* 0FBDB4 7F0C7284 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBDB8 7F0C7288 312C0001 */  andi  $t4, $t1, 1
/* 0FBDBC 7F0C728C 032CC021 */  addu  $t8, $t9, $t4
/* 0FBDC0 7F0C7290 304A0001 */  andi  $t2, $v0, 1
/* 0FBDC4 7F0C7294 030A5821 */  addu  $t3, $t8, $t2
/* 0FBDC8 7F0C7298 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0FBDCC 7F0C729C 256D0002 */  addiu $t5, $t3, 2
/* 0FBDD0 7F0C72A0 000D7083 */  sra   $t6, $t5, 2
/* 0FBDD4 7F0C72A4 31CF0001 */  andi  $t7, $t6, 1
/* 0FBDD8 7F0C72A8 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FBDDC 7F0C72AC 02E02825 */  move  $a1, $s7
/* 0FBDE0 7F0C72B0 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBDE4 7F0C72B4 02602025 */   move  $a0, $s3
/* 0FBDE8 7F0C72B8 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FBDEC 7F0C72BC 00116083 */  sra   $t4, $s1, 2
/* 0FBDF0 7F0C72C0 26260002 */  addiu $a2, $s1, 2
/* 0FBDF4 7F0C72C4 00025100 */  sll   $t2, $v0, 4
/* 0FBDF8 7F0C72C8 00065843 */  sra   $t3, $a2, 1
/* 0FBDFC 7F0C72CC 032C9021 */  addu  $s2, $t9, $t4
/* 0FBE00 7F0C72D0 A24A0000 */  sb    $t2, ($s2)
/* 0FBE04 7F0C72D4 01756821 */  addu  $t5, $t3, $s5
/* 0FBE08 7F0C72D8 91A40000 */  lbu   $a0, ($t5)
/* 0FBE0C 7F0C72DC 26380003 */  addiu $t8, $s1, 3
/* 0FBE10 7F0C72E0 031E282A */  slt   $a1, $t8, $fp
/* 0FBE14 7F0C72E4 00047103 */  sra   $t6, $a0, 4
/* 0FBE18 7F0C72E8 31CF000F */  andi  $t7, $t6, 0xf
/* 0FBE1C 7F0C72EC 000FC840 */  sll   $t9, $t7, 1
/* 0FBE20 7F0C72F0 02796021 */  addu  $t4, $s3, $t9
/* 0FBE24 7F0C72F4 85900000 */  lh    $s0, ($t4)
/* 0FBE28 7F0C72F8 10A00003 */  beqz  $a1, .L7F0C7308
/* 0FBE2C 7F0C72FC 01603025 */   move  $a2, $t3
/* 0FBE30 7F0C7300 10000002 */  b     .L7F0C730C
/* 0FBE34 7F0C7304 00001825 */   move  $v1, $zero
.L7F0C7308:
/* 0FBE38 7F0C7308 24030004 */  li    $v1, 4
.L7F0C730C:
/* 0FBE3C 7F0C730C 00D67821 */  addu  $t7, $a2, $s6
/* 0FBE40 7F0C7310 01F5C821 */  addu  $t9, $t7, $s5
/* 0FBE44 7F0C7314 932C0000 */  lbu   $t4, ($t9)
/* 0FBE48 7F0C7318 00645007 */  srav  $t2, $a0, $v1
/* 0FBE4C 7F0C731C 314B000F */  andi  $t3, $t2, 0xf
/* 0FBE50 7F0C7320 000B6840 */  sll   $t5, $t3, 1
/* 0FBE54 7F0C7324 000CC103 */  sra   $t8, $t4, 4
/* 0FBE58 7F0C7328 330A000F */  andi  $t2, $t8, 0xf
/* 0FBE5C 7F0C732C 026D7021 */  addu  $t6, $s3, $t5
/* 0FBE60 7F0C7330 000A5840 */  sll   $t3, $t2, 1
/* 0FBE64 7F0C7334 026B6821 */  addu  $t5, $s3, $t3
/* 0FBE68 7F0C7338 85C80000 */  lh    $t0, ($t6)
/* 0FBE6C 7F0C733C 10A00003 */  beqz  $a1, .L7F0C734C
/* 0FBE70 7F0C7340 85A90000 */   lh    $t1, ($t5)
/* 0FBE74 7F0C7344 10000002 */  b     .L7F0C7350
/* 0FBE78 7F0C7348 00001825 */   move  $v1, $zero
.L7F0C734C:
/* 0FBE7C 7F0C734C 24030004 */  li    $v1, 4
.L7F0C7350:
/* 0FBE80 7F0C7350 02867021 */  addu  $t6, $s4, $a2
/* 0FBE84 7F0C7354 91CF0000 */  lbu   $t7, ($t6)
/* 0FBE88 7F0C7358 00105AC3 */  sra   $t3, $s0, 0xb
/* 0FBE8C 7F0C735C 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBE90 7F0C7360 006FC807 */  srav  $t9, $t7, $v1
/* 0FBE94 7F0C7364 332C000F */  andi  $t4, $t9, 0xf
/* 0FBE98 7F0C7368 000CC040 */  sll   $t8, $t4, 1
/* 0FBE9C 7F0C736C 02785021 */  addu  $t2, $s3, $t8
/* 0FBEA0 7F0C7370 85420000 */  lh    $v0, ($t2)
/* 0FBEA4 7F0C7374 000872C3 */  sra   $t6, $t0, 0xb
/* 0FBEA8 7F0C7378 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FBEAC 7F0C737C 000962C3 */  sra   $t4, $t1, 0xb
/* 0FBEB0 7F0C7380 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBEB4 7F0C7384 01AFC821 */  addu  $t9, $t5, $t7
/* 0FBEB8 7F0C7388 00025AC3 */  sra   $t3, $v0, 0xb
/* 0FBEBC 7F0C738C 316E001F */  andi  $t6, $t3, 0x1f
/* 0FBEC0 7F0C7390 03385021 */  addu  $t2, $t9, $t8
/* 0FBEC4 7F0C7394 014E3021 */  addu  $a2, $t2, $t6
/* 0FBEC8 7F0C7398 00106183 */  sra   $t4, $s0, 6
/* 0FBECC 7F0C739C 3199001F */  andi  $t9, $t4, 0x1f
/* 0FBED0 7F0C73A0 00066883 */  sra   $t5, $a2, 2
/* 0FBED4 7F0C73A4 0008C183 */  sra   $t8, $t0, 6
/* 0FBED8 7F0C73A8 330B001F */  andi  $t3, $t8, 0x1f
/* 0FBEDC 7F0C73AC 31A6001F */  andi  $a2, $t5, 0x1f
/* 0FBEE0 7F0C73B0 00097183 */  sra   $t6, $t1, 6
/* 0FBEE4 7F0C73B4 31CD001F */  andi  $t5, $t6, 0x1f
/* 0FBEE8 7F0C73B8 032B5021 */  addu  $t2, $t9, $t3
/* 0FBEEC 7F0C73BC 00026183 */  sra   $t4, $v0, 6
/* 0FBEF0 7F0C73C0 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBEF4 7F0C73C4 014D7821 */  addu  $t7, $t2, $t5
/* 0FBEF8 7F0C73C8 01F83821 */  addu  $a3, $t7, $t8
/* 0FBEFC 7F0C73CC 00107043 */  sra   $t6, $s0, 1
/* 0FBF00 7F0C73D0 31CA001F */  andi  $t2, $t6, 0x1f
/* 0FBF04 7F0C73D4 0007C883 */  sra   $t9, $a3, 2
/* 0FBF08 7F0C73D8 00086843 */  sra   $t5, $t0, 1
/* 0FBF0C 7F0C73DC 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FBF10 7F0C73E0 3327001F */  andi  $a3, $t9, 0x1f
/* 0FBF14 7F0C73E4 0009C043 */  sra   $t8, $t1, 1
/* 0FBF18 7F0C73E8 3319001F */  andi  $t9, $t8, 0x1f
/* 0FBF1C 7F0C73EC 014C7821 */  addu  $t7, $t2, $t4
/* 0FBF20 7F0C73F0 00027043 */  sra   $t6, $v0, 1
/* 0FBF24 7F0C73F4 31CD001F */  andi  $t5, $t6, 0x1f
/* 0FBF28 7F0C73F8 01F95821 */  addu  $t3, $t7, $t9
/* 0FBF2C 7F0C73FC 016D5021 */  addu  $t2, $t3, $t5
/* 0FBF30 7F0C7400 000A6083 */  sra   $t4, $t2, 2
/* 0FBF34 7F0C7404 31190001 */  andi  $t9, $t0, 1
/* 0FBF38 7F0C7408 320F0001 */  andi  $t7, $s0, 1
/* 0FBF3C 7F0C740C 01F97021 */  addu  $t6, $t7, $t9
/* 0FBF40 7F0C7410 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBF44 7F0C7414 312B0001 */  andi  $t3, $t1, 1
/* 0FBF48 7F0C7418 01CB6821 */  addu  $t5, $t6, $t3
/* 0FBF4C 7F0C741C 304A0001 */  andi  $t2, $v0, 1
/* 0FBF50 7F0C7420 01AA6021 */  addu  $t4, $t5, $t2
/* 0FBF54 7F0C7424 AFB80010 */  sw    $t8, 0x10($sp)
/* 0FBF58 7F0C7428 25980002 */  addiu $t8, $t4, 2
/* 0FBF5C 7F0C742C 00187883 */  sra   $t7, $t8, 2
/* 0FBF60 7F0C7430 31F90001 */  andi  $t9, $t7, 1
/* 0FBF64 7F0C7434 AFB90014 */  sw    $t9, 0x14($sp)
/* 0FBF68 7F0C7438 02602025 */  move  $a0, $s3
/* 0FBF6C 7F0C743C 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBF70 7F0C7440 02E02825 */   move  $a1, $s7
/* 0FBF74 7F0C7444 924E0000 */  lbu   $t6, ($s2)
/* 0FBF78 7F0C7448 26310004 */  addiu $s1, $s1, 4
/* 0FBF7C 7F0C744C 01C26825 */  or    $t5, $t6, $v0
/* 0FBF80 7F0C7450 A24D0000 */  sb    $t5, ($s2)
/* 0FBF84 7F0C7454 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBF88 7F0C7458 022A082A */  slt   $at, $s1, $t2
/* 0FBF8C 7F0C745C 5420FF3B */  bnezl $at, .L7F0C714C
/* 0FBF90 7F0C7460 00112843 */   sra   $a1, $s1, 1
.L7F0C7464:
/* 0FBF94 7F0C7464 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0FBF98 7F0C7468 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBF9C 7F0C746C 8FAC0074 */  lw    $t4, 0x74($sp)
/* 0FBFA0 7F0C7470 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FBFA4 7F0C7474 8FB9009C */  lw    $t9, 0x9c($sp)
/* 0FBFA8 7F0C7478 25CB0002 */  addiu $t3, $t6, 2
/* 0FBFAC 7F0C747C 016D082A */  slt   $at, $t3, $t5
/* 0FBFB0 7F0C7480 01987821 */  addu  $t7, $t4, $t8
/* 0FBFB4 7F0C7484 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FBFB8 7F0C7488 AFAF0074 */  sw    $t7, 0x74($sp)
/* 0FBFBC 7F0C748C 1420FF20 */  bnez  $at, .L7F0C7110
/* 0FBFC0 7F0C7490 02B9A821 */   addu  $s5, $s5, $t9
.L7F0C7494:
/* 0FBFC4 7F0C7494 8FAA0098 */  lw    $t2, 0x98($sp)
/* 0FBFC8 7F0C7498 8FB80094 */  lw    $t8, 0x94($sp)
/* 0FBFCC 7F0C749C 000A6043 */  sra   $t4, $t2, 1
/* 0FBFD0 7F0C74A0 01980019 */  multu $t4, $t8
/* 0FBFD4 7F0C74A4 00001012 */  mflo  $v0
/* 0FBFD8 7F0C74A8 100000B5 */  b     .L7F0C7780
/* 0FBFDC 7F0C74AC 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C74B0:
/* 0FBFE0 7F0C74B0 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0FBFE4 7F0C74B4 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBFE8 7F0C74B8 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBFEC 7F0C74BC 19E000A8 */  blez  $t7, .L7F0C7760
/* 0FBFF0 7F0C74C0 00197043 */   sra   $t6, $t9, 1
/* 0FBFF4 7F0C74C4 AFAE004C */  sw    $t6, 0x4c($sp)
/* 0FBFF8 7F0C74C8 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBFFC 7F0C74CC 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C74D0:
/* 0FC000 7F0C74D0 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 0FC004 7F0C74D4 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 0FC008 7F0C74D8 00008825 */  move  $s1, $zero
/* 0FC00C 7F0C74DC 25AA0001 */  addiu $t2, $t5, 1
/* 0FC010 7F0C74E0 014B082A */  slt   $at, $t2, $t3
/* 0FC014 7F0C74E4 10200005 */  beqz  $at, .L7F0C74FC
/* 0FC018 7F0C74E8 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0FC01C 7F0C74EC 8FB6009C */  lw    $s6, 0x9c($sp)
/* 0FC020 7F0C74F0 00166043 */  sra   $t4, $s6, 1
/* 0FC024 7F0C74F4 10000002 */  b     .L7F0C7500
/* 0FC028 7F0C74F8 0180B025 */   move  $s6, $t4
.L7F0C74FC:
/* 0FC02C 7F0C74FC 0000B025 */  move  $s6, $zero
.L7F0C7500:
/* 0FC030 7F0C7500 1B00008B */  blez  $t8, .L7F0C7730
/* 0FC034 7F0C7504 00112843 */   sra   $a1, $s1, 1
.L7F0C7508:
/* 0FC038 7F0C7508 00B57821 */  addu  $t7, $a1, $s5
/* 0FC03C 7F0C750C 91E20000 */  lbu   $v0, ($t7)
/* 0FC040 7F0C7510 262A0001 */  addiu $t2, $s1, 1
/* 0FC044 7F0C7514 015E202A */  slt   $a0, $t2, $fp
/* 0FC048 7F0C7518 0002C903 */  sra   $t9, $v0, 4
/* 0FC04C 7F0C751C 332E000F */  andi  $t6, $t9, 0xf
/* 0FC050 7F0C7520 000E6840 */  sll   $t5, $t6, 1
/* 0FC054 7F0C7524 026D5821 */  addu  $t3, $s3, $t5
/* 0FC058 7F0C7528 00826007 */  srav  $t4, $v0, $a0
/* 0FC05C 7F0C752C 11800003 */  beqz  $t4, .L7F0C753C
/* 0FC060 7F0C7530 85700000 */   lh    $s0, ($t3)
/* 0FC064 7F0C7534 10000002 */  b     .L7F0C7540
/* 0FC068 7F0C7538 00001825 */   move  $v1, $zero
.L7F0C753C:
/* 0FC06C 7F0C753C 24030004 */  li    $v1, 4
.L7F0C7540:
/* 0FC070 7F0C7540 00B67021 */  addu  $t6, $a1, $s6
/* 0FC074 7F0C7544 01D56821 */  addu  $t5, $t6, $s5
/* 0FC078 7F0C7548 91A20000 */  lbu   $v0, ($t5)
/* 0FC07C 7F0C754C 3078000F */  andi  $t8, $v1, 0xf
/* 0FC080 7F0C7550 00187840 */  sll   $t7, $t8, 1
/* 0FC084 7F0C7554 00025903 */  sra   $t3, $v0, 4
/* 0FC088 7F0C7558 316A000F */  andi  $t2, $t3, 0xf
/* 0FC08C 7F0C755C 026FC821 */  addu  $t9, $s3, $t7
/* 0FC090 7F0C7560 000A6040 */  sll   $t4, $t2, 1
/* 0FC094 7F0C7564 026CC021 */  addu  $t8, $s3, $t4
/* 0FC098 7F0C7568 00827807 */  srav  $t7, $v0, $a0
/* 0FC09C 7F0C756C 87280000 */  lh    $t0, ($t9)
/* 0FC0A0 7F0C7570 11E00003 */  beqz  $t7, .L7F0C7580
/* 0FC0A4 7F0C7574 87090000 */   lh    $t1, ($t8)
/* 0FC0A8 7F0C7578 10000002 */  b     .L7F0C7584
/* 0FC0AC 7F0C757C 00001825 */   move  $v1, $zero
.L7F0C7580:
/* 0FC0B0 7F0C7580 24030004 */  li    $v1, 4
.L7F0C7584:
/* 0FC0B4 7F0C7584 3079000F */  andi  $t9, $v1, 0xf
/* 0FC0B8 7F0C7588 00197040 */  sll   $t6, $t9, 1
/* 0FC0BC 7F0C758C 026E6821 */  addu  $t5, $s3, $t6
/* 0FC0C0 7F0C7590 85A20000 */  lh    $v0, ($t5)
/* 0FC0C4 7F0C7594 00105A03 */  sra   $t3, $s0, 8
/* 0FC0C8 7F0C7598 00086203 */  sra   $t4, $t0, 8
/* 0FC0CC 7F0C759C 319800FF */  andi  $t8, $t4, 0xff
/* 0FC0D0 7F0C75A0 316A00FF */  andi  $t2, $t3, 0xff
/* 0FC0D4 7F0C75A4 0009CA03 */  sra   $t9, $t1, 8
/* 0FC0D8 7F0C75A8 332E00FF */  andi  $t6, $t9, 0xff
/* 0FC0DC 7F0C75AC 01587821 */  addu  $t7, $t2, $t8
/* 0FC0E0 7F0C75B0 01EE6821 */  addu  $t5, $t7, $t6
/* 0FC0E4 7F0C75B4 00025A03 */  sra   $t3, $v0, 8
/* 0FC0E8 7F0C75B8 316C00FF */  andi  $t4, $t3, 0xff
/* 0FC0EC 7F0C75BC 01AC3021 */  addu  $a2, $t5, $t4
/* 0FC0F0 7F0C75C0 310F00FF */  andi  $t7, $t0, 0xff
/* 0FC0F4 7F0C75C4 321900FF */  andi  $t9, $s0, 0xff
/* 0FC0F8 7F0C75C8 032F7021 */  addu  $t6, $t9, $t7
/* 0FC0FC 7F0C75CC 312B00FF */  andi  $t3, $t1, 0xff
/* 0FC100 7F0C75D0 01CB6821 */  addu  $t5, $t6, $t3
/* 0FC104 7F0C75D4 304C00FF */  andi  $t4, $v0, 0xff
/* 0FC108 7F0C75D8 01AC3821 */  addu  $a3, $t5, $t4
/* 0FC10C 7F0C75DC 00065083 */  sra   $t2, $a2, 2
/* 0FC110 7F0C75E0 314600FF */  andi  $a2, $t2, 0xff
/* 0FC114 7F0C75E4 24E70001 */  addiu $a3, $a3, 1
/* 0FC118 7F0C75E8 00075083 */  sra   $t2, $a3, 2
/* 0FC11C 7F0C75EC 314700FF */  andi  $a3, $t2, 0xff
/* 0FC120 7F0C75F0 02602025 */  move  $a0, $s3
/* 0FC124 7F0C75F4 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FC128 7F0C75F8 02E02825 */   move  $a1, $s7
/* 0FC12C 7F0C75FC 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FC130 7F0C7600 00117883 */  sra   $t7, $s1, 2
/* 0FC134 7F0C7604 26260002 */  addiu $a2, $s1, 2
/* 0FC138 7F0C7608 00025900 */  sll   $t3, $v0, 4
/* 0FC13C 7F0C760C 00066843 */  sra   $t5, $a2, 1
/* 0FC140 7F0C7610 032F9021 */  addu  $s2, $t9, $t7
/* 0FC144 7F0C7614 A24B0000 */  sb    $t3, ($s2)
/* 0FC148 7F0C7618 01B56021 */  addu  $t4, $t5, $s5
/* 0FC14C 7F0C761C 91840000 */  lbu   $a0, ($t4)
/* 0FC150 7F0C7620 262E0003 */  addiu $t6, $s1, 3
/* 0FC154 7F0C7624 01DE282A */  slt   $a1, $t6, $fp
/* 0FC158 7F0C7628 00045103 */  sra   $t2, $a0, 4
/* 0FC15C 7F0C762C 3158000F */  andi  $t8, $t2, 0xf
/* 0FC160 7F0C7630 0018C840 */  sll   $t9, $t8, 1
/* 0FC164 7F0C7634 02797821 */  addu  $t7, $s3, $t9
/* 0FC168 7F0C7638 00A45807 */  srav  $t3, $a0, $a1
/* 0FC16C 7F0C763C 85F00000 */  lh    $s0, ($t7)
/* 0FC170 7F0C7640 11600003 */  beqz  $t3, .L7F0C7650
/* 0FC174 7F0C7644 01A03025 */   move  $a2, $t5
/* 0FC178 7F0C7648 10000002 */  b     .L7F0C7654
/* 0FC17C 7F0C764C 00001825 */   move  $v1, $zero
.L7F0C7650:
/* 0FC180 7F0C7650 24030004 */  li    $v1, 4
.L7F0C7654:
/* 0FC184 7F0C7654 00D6C021 */  addu  $t8, $a2, $s6
/* 0FC188 7F0C7658 0315C821 */  addu  $t9, $t8, $s5
/* 0FC18C 7F0C765C 93220000 */  lbu   $v0, ($t9)
/* 0FC190 7F0C7660 306D000F */  andi  $t5, $v1, 0xf
/* 0FC194 7F0C7664 000D6040 */  sll   $t4, $t5, 1
/* 0FC198 7F0C7668 00027903 */  sra   $t7, $v0, 4
/* 0FC19C 7F0C766C 31EE000F */  andi  $t6, $t7, 0xf
/* 0FC1A0 7F0C7670 026C5021 */  addu  $t2, $s3, $t4
/* 0FC1A4 7F0C7674 000E5840 */  sll   $t3, $t6, 1
/* 0FC1A8 7F0C7678 026B6821 */  addu  $t5, $s3, $t3
/* 0FC1AC 7F0C767C 00A26007 */  srav  $t4, $v0, $a1
/* 0FC1B0 7F0C7680 85480000 */  lh    $t0, ($t2)
/* 0FC1B4 7F0C7684 11800003 */  beqz  $t4, .L7F0C7694
/* 0FC1B8 7F0C7688 85A90000 */   lh    $t1, ($t5)
/* 0FC1BC 7F0C768C 10000002 */  b     .L7F0C7698
/* 0FC1C0 7F0C7690 00001825 */   move  $v1, $zero
.L7F0C7694:
/* 0FC1C4 7F0C7694 24030004 */  li    $v1, 4
.L7F0C7698:
/* 0FC1C8 7F0C7698 306A000F */  andi  $t2, $v1, 0xf
/* 0FC1CC 7F0C769C 000AC040 */  sll   $t8, $t2, 1
/* 0FC1D0 7F0C76A0 0278C821 */  addu  $t9, $s3, $t8
/* 0FC1D4 7F0C76A4 87220000 */  lh    $v0, ($t9)
/* 0FC1D8 7F0C76A8 00107A03 */  sra   $t7, $s0, 8
/* 0FC1DC 7F0C76AC 00085A03 */  sra   $t3, $t0, 8
/* 0FC1E0 7F0C76B0 316D00FF */  andi  $t5, $t3, 0xff
/* 0FC1E4 7F0C76B4 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FC1E8 7F0C76B8 00095203 */  sra   $t2, $t1, 8
/* 0FC1EC 7F0C76BC 315800FF */  andi  $t8, $t2, 0xff
/* 0FC1F0 7F0C76C0 01CD6021 */  addu  $t4, $t6, $t5
/* 0FC1F4 7F0C76C4 0198C821 */  addu  $t9, $t4, $t8
/* 0FC1F8 7F0C76C8 00027A03 */  sra   $t7, $v0, 8
/* 0FC1FC 7F0C76CC 31EB00FF */  andi  $t3, $t7, 0xff
/* 0FC200 7F0C76D0 032B3021 */  addu  $a2, $t9, $t3
/* 0FC204 7F0C76D4 310C00FF */  andi  $t4, $t0, 0xff
/* 0FC208 7F0C76D8 320A00FF */  andi  $t2, $s0, 0xff
/* 0FC20C 7F0C76DC 014CC021 */  addu  $t8, $t2, $t4
/* 0FC210 7F0C76E0 312F00FF */  andi  $t7, $t1, 0xff
/* 0FC214 7F0C76E4 030FC821 */  addu  $t9, $t8, $t7
/* 0FC218 7F0C76E8 304B00FF */  andi  $t3, $v0, 0xff
/* 0FC21C 7F0C76EC 032B3821 */  addu  $a3, $t9, $t3
/* 0FC220 7F0C76F0 00067083 */  sra   $t6, $a2, 2
/* 0FC224 7F0C76F4 31C600FF */  andi  $a2, $t6, 0xff
/* 0FC228 7F0C76F8 24E70001 */  addiu $a3, $a3, 1
/* 0FC22C 7F0C76FC 00077083 */  sra   $t6, $a3, 2
/* 0FC230 7F0C7700 31C700FF */  andi  $a3, $t6, 0xff
/* 0FC234 7F0C7704 02602025 */  move  $a0, $s3
/* 0FC238 7F0C7708 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FC23C 7F0C770C 02E02825 */   move  $a1, $s7
/* 0FC240 7F0C7710 924A0000 */  lbu   $t2, ($s2)
/* 0FC244 7F0C7714 26310004 */  addiu $s1, $s1, 4
/* 0FC248 7F0C7718 0142C025 */  or    $t8, $t2, $v0
/* 0FC24C 7F0C771C A2580000 */  sb    $t8, ($s2)
/* 0FC250 7F0C7720 8FAF009C */  lw    $t7, 0x9c($sp)
/* 0FC254 7F0C7724 022F082A */  slt   $at, $s1, $t7
/* 0FC258 7F0C7728 5420FF77 */  bnezl $at, .L7F0C7508
/* 0FC25C 7F0C772C 00112843 */   sra   $a1, $s1, 1
.L7F0C7730:
/* 0FC260 7F0C7730 8FAA00A0 */  lw    $t2, 0xa0($sp)
/* 0FC264 7F0C7734 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FC268 7F0C7738 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FC26C 7F0C773C 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0FC270 7F0C7740 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0FC274 7F0C7744 254C0002 */  addiu $t4, $t2, 2
/* 0FC278 7F0C7748 0198082A */  slt   $at, $t4, $t8
/* 0FC27C 7F0C774C 032B7021 */  addu  $t6, $t9, $t3
/* 0FC280 7F0C7750 AFAC00A0 */  sw    $t4, 0xa0($sp)
/* 0FC284 7F0C7754 AFAE0074 */  sw    $t6, 0x74($sp)
/* 0FC288 7F0C7758 1420FF5D */  bnez  $at, .L7F0C74D0
/* 0FC28C 7F0C775C 02ADA821 */   addu  $s5, $s5, $t5
.L7F0C7760:
/* 0FC290 7F0C7760 8FAF0098 */  lw    $t7, 0x98($sp)
/* 0FC294 7F0C7764 8FAB0094 */  lw    $t3, 0x94($sp)
/* 0FC298 7F0C7768 000FC843 */  sra   $t9, $t7, 1
/* 0FC29C 7F0C776C 032B0019 */  multu $t9, $t3
/* 0FC2A0 7F0C7770 00001012 */  mflo  $v0
/* 0FC2A4 7F0C7774 10000002 */  b     .L7F0C7780
/* 0FC2A8 7F0C7778 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C777C:
/* 0FC2AC 7F0C777C 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F0C7780:
/* 0FC2B0 7F0C7780 8FB00020 */  lw    $s0, 0x20($sp)
/* 0FC2B4 7F0C7784 8FB10024 */  lw    $s1, 0x24($sp)
/* 0FC2B8 7F0C7788 8FB20028 */  lw    $s2, 0x28($sp)
/* 0FC2BC 7F0C778C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0FC2C0 7F0C7790 8FB40030 */  lw    $s4, 0x30($sp)
/* 0FC2C4 7F0C7794 8FB50034 */  lw    $s5, 0x34($sp)
/* 0FC2C8 7F0C7798 8FB60038 */  lw    $s6, 0x38($sp)
/* 0FC2CC 7F0C779C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0FC2D0 7F0C77A0 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0FC2D4 7F0C77A4 03E00008 */  jr    $ra
/* 0FC2D8 7F0C77A8 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C77AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C77AC
/* 0FC2DC 7F0C77AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC2E0 7F0C77B0 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FC2E4 7F0C77B4 AFB10008 */  sw    $s1, 8($sp)
/* 0FC2E8 7F0C77B8 AFB00004 */  sw    $s0, 4($sp)
/* 0FC2EC 7F0C77BC 00C08025 */  move  $s0, $a2
/* 0FC2F0 7F0C77C0 00E08825 */  move  $s1, $a3
/* 0FC2F4 7F0C77C4 00809025 */  move  $s2, $a0
/* 0FC2F8 7F0C77C8 AFB40014 */  sw    $s4, 0x14($sp)
/* 0FC2FC 7F0C77CC AFB30010 */  sw    $s3, 0x10($sp)
/* 0FC300 7F0C77D0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0FC304 7F0C77D4 18A0003F */  blez  $a1, .L7F0C78D4
/* 0FC308 7F0C77D8 00001825 */   move  $v1, $zero
/* 0FC30C 7F0C77DC 30A60003 */  andi  $a2, $a1, 3
/* 0FC310 7F0C77E0 10C00018 */  beqz  $a2, .L7F0C7844
/* 0FC314 7F0C77E4 8FA90028 */   lw    $t1, 0x28($sp)
/* 0FC318 7F0C77E8 00007840 */  sll   $t7, $zero, 1
/* 0FC31C 7F0C77EC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC320 7F0C77F0 024F1021 */  addu  $v0, $s2, $t7
/* 0FC324 7F0C77F4 0010C2C0 */  sll   $t8, $s0, 0xb
/* 0FC328 7F0C77F8 0007C980 */  sll   $t9, $a3, 6
/* 0FC32C 7F0C77FC 03197025 */  or    $t6, $t8, $t9
/* 0FC330 7F0C7800 00097840 */  sll   $t7, $t1, 1
/* 0FC334 7F0C7804 01CFC025 */  or    $t8, $t6, $t7
/* 0FC338 7F0C7808 030A2825 */  or    $a1, $t8, $t2
/* 0FC33C 7F0C780C 30B9FFFF */  andi  $t9, $a1, 0xffff
/* 0FC340 7F0C7810 03202825 */  move  $a1, $t9
/* 0FC344 7F0C7814 00C02025 */  move  $a0, $a2
.L7F0C7818:
/* 0FC348 7F0C7818 944E0000 */  lhu   $t6, ($v0)
/* 0FC34C 7F0C781C 54AE0004 */  bnel  $a1, $t6, .L7F0C7830
/* 0FC350 7F0C7820 24630001 */   addiu $v1, $v1, 1
/* 0FC354 7F0C7824 100000E5 */  b     .L7F0C7BBC
/* 0FC358 7F0C7828 00601025 */   move  $v0, $v1
/* 0FC35C 7F0C782C 24630001 */  addiu $v1, $v1, 1
.L7F0C7830:
/* 0FC360 7F0C7830 1483FFF9 */  bne   $a0, $v1, .L7F0C7818
/* 0FC364 7F0C7834 24420002 */   addiu $v0, $v0, 2
/* 0FC368 7F0C7838 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC36C 7F0C783C 506F0026 */  beql  $v1, $t7, .L7F0C78D8
/* 0FC370 7F0C7840 8FA6001C */   lw    $a2, 0x1c($sp)
.L7F0C7844:
/* 0FC374 7F0C7844 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC378 7F0C7848 0003C040 */  sll   $t8, $v1, 1
/* 0FC37C 7F0C784C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC380 7F0C7850 02581021 */  addu  $v0, $s2, $t8
/* 0FC384 7F0C7854 0010CAC0 */  sll   $t9, $s0, 0xb
/* 0FC388 7F0C7858 00117180 */  sll   $t6, $s1, 6
/* 0FC38C 7F0C785C 032E7825 */  or    $t7, $t9, $t6
/* 0FC390 7F0C7860 0009C040 */  sll   $t8, $t1, 1
/* 0FC394 7F0C7864 01F8C825 */  or    $t9, $t7, $t8
/* 0FC398 7F0C7868 032A2825 */  or    $a1, $t9, $t2
/* 0FC39C 7F0C786C 30AEFFFF */  andi  $t6, $a1, 0xffff
/* 0FC3A0 7F0C7870 01C02825 */  move  $a1, $t6
.L7F0C7874:
/* 0FC3A4 7F0C7874 944F0000 */  lhu   $t7, ($v0)
/* 0FC3A8 7F0C7878 54AF0004 */  bnel  $a1, $t7, .L7F0C788C
/* 0FC3AC 7F0C787C 94580002 */   lhu   $t8, 2($v0)
/* 0FC3B0 7F0C7880 100000CE */  b     .L7F0C7BBC
/* 0FC3B4 7F0C7884 00601025 */   move  $v0, $v1
/* 0FC3B8 7F0C7888 94580002 */  lhu   $t8, 2($v0)
.L7F0C788C:
/* 0FC3BC 7F0C788C 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC3C0 7F0C7890 54B80004 */  bnel  $a1, $t8, .L7F0C78A4
/* 0FC3C4 7F0C7894 94590004 */   lhu   $t9, 4($v0)
/* 0FC3C8 7F0C7898 100000C8 */  b     .L7F0C7BBC
/* 0FC3CC 7F0C789C 24620001 */   addiu $v0, $v1, 1
/* 0FC3D0 7F0C78A0 94590004 */  lhu   $t9, 4($v0)
.L7F0C78A4:
/* 0FC3D4 7F0C78A4 54B90004 */  bnel  $a1, $t9, .L7F0C78B8
/* 0FC3D8 7F0C78A8 944E0006 */   lhu   $t6, 6($v0)
/* 0FC3DC 7F0C78AC 100000C3 */  b     .L7F0C7BBC
/* 0FC3E0 7F0C78B0 24620002 */   addiu $v0, $v1, 2
/* 0FC3E4 7F0C78B4 944E0006 */  lhu   $t6, 6($v0)
.L7F0C78B8:
/* 0FC3E8 7F0C78B8 54AE0004 */  bnel  $a1, $t6, .L7F0C78CC
/* 0FC3EC 7F0C78BC 24630004 */   addiu $v1, $v1, 4
/* 0FC3F0 7F0C78C0 100000BE */  b     .L7F0C7BBC
/* 0FC3F4 7F0C78C4 24620003 */   addiu $v0, $v1, 3
/* 0FC3F8 7F0C78C8 24630004 */  addiu $v1, $v1, 4
.L7F0C78CC:
/* 0FC3FC 7F0C78CC 146FFFE9 */  bne   $v1, $t7, .L7F0C7874
/* 0FC400 7F0C78D0 24420008 */   addiu $v0, $v0, 8
.L7F0C78D4:
/* 0FC404 7F0C78D4 8FA6001C */  lw    $a2, 0x1c($sp)
.L7F0C78D8:
/* 0FC408 7F0C78D8 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC40C 7F0C78DC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC410 7F0C78E0 24C6FFFF */  addiu $a2, $a2, -1
/* 0FC414 7F0C78E4 28C10002 */  slti  $at, $a2, 2
/* 0FC418 7F0C78E8 00002825 */  move  $a1, $zero
/* 0FC41C 7F0C78EC 1420003A */  bnez  $at, .L7F0C79D8
/* 0FC420 7F0C78F0 00C03825 */   move  $a3, $a2
/* 0FC424 7F0C78F4 02100019 */  multu $s0, $s0
/* 0FC428 7F0C78F8 0000C012 */  mflo  $t8
/* 0FC42C 7F0C78FC 00000000 */  nop   
/* 0FC430 7F0C7900 00000000 */  nop   
/* 0FC434 7F0C7904 02310019 */  multu $s1, $s1
/* 0FC438 7F0C7908 0000C812 */  mflo  $t9
/* 0FC43C 7F0C790C 03197021 */  addu  $t6, $t8, $t9
/* 0FC440 7F0C7910 000AC900 */  sll   $t9, $t2, 4
/* 0FC444 7F0C7914 01290019 */  multu $t1, $t1
/* 0FC448 7F0C7918 032AC823 */  subu  $t9, $t9, $t2
/* 0FC44C 7F0C791C 0019C980 */  sll   $t9, $t9, 6
/* 0FC450 7F0C7920 032AC821 */  addu  $t9, $t9, $t2
/* 0FC454 7F0C7924 00007812 */  mflo  $t7
/* 0FC458 7F0C7928 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC45C 7F0C792C 03194021 */  addu  $t0, $t8, $t9
/* 0FC460 7F0C7930 00E55821 */  addu  $t3, $a3, $a1
.L7F0C7934:
/* 0FC464 7F0C7934 000B2043 */  sra   $a0, $t3, 1
/* 0FC468 7F0C7938 00047840 */  sll   $t7, $a0, 1
/* 0FC46C 7F0C793C 024FC021 */  addu  $t8, $s2, $t7
/* 0FC470 7F0C7940 97030000 */  lhu   $v1, ($t8)
/* 0FC474 7F0C7944 000362C3 */  sra   $t4, $v1, 0xb
/* 0FC478 7F0C7948 3199001F */  andi  $t9, $t4, 0x1f
/* 0FC47C 7F0C794C 03390019 */  multu $t9, $t9
/* 0FC480 7F0C7950 00036983 */  sra   $t5, $v1, 6
/* 0FC484 7F0C7954 31AE001F */  andi  $t6, $t5, 0x1f
/* 0FC488 7F0C7958 00039843 */  sra   $s3, $v1, 1
/* 0FC48C 7F0C795C 326F001F */  andi  $t7, $s3, 0x1f
/* 0FC490 7F0C7960 0000C012 */  mflo  $t8
/* 0FC494 7F0C7964 00000000 */  nop   
/* 0FC498 7F0C7968 00000000 */  nop   
/* 0FC49C 7F0C796C 01CE0019 */  multu $t6, $t6
/* 0FC4A0 7F0C7970 0000C812 */  mflo  $t9
/* 0FC4A4 7F0C7974 03197021 */  addu  $t6, $t8, $t9
/* 0FC4A8 7F0C7978 30790001 */  andi  $t9, $v1, 1
/* 0FC4AC 7F0C797C 01EF0019 */  multu $t7, $t7
/* 0FC4B0 7F0C7980 00007812 */  mflo  $t7
/* 0FC4B4 7F0C7984 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC4B8 7F0C7988 00197100 */  sll   $t6, $t9, 4
/* 0FC4BC 7F0C798C 01D97023 */  subu  $t6, $t6, $t9
/* 0FC4C0 7F0C7990 000E7180 */  sll   $t6, $t6, 6
/* 0FC4C4 7F0C7994 01D97021 */  addu  $t6, $t6, $t9
/* 0FC4C8 7F0C7998 030EA021 */  addu  $s4, $t8, $t6
/* 0FC4CC 7F0C799C 0288082A */  slt   $at, $s4, $t0
/* 0FC4D0 7F0C79A0 50200004 */  beql  $at, $zero, .L7F0C79B4
/* 0FC4D4 7F0C79A4 0114082A */   slt   $at, $t0, $s4
/* 0FC4D8 7F0C79A8 10000007 */  b     .L7F0C79C8
/* 0FC4DC 7F0C79AC 00802825 */   move  $a1, $a0
/* 0FC4E0 7F0C79B0 0114082A */  slt   $at, $t0, $s4
.L7F0C79B4:
/* 0FC4E4 7F0C79B4 10200003 */  beqz  $at, .L7F0C79C4
/* 0FC4E8 7F0C79B8 00803825 */   move  $a3, $a0
/* 0FC4EC 7F0C79BC 10000002 */  b     .L7F0C79C8
/* 0FC4F0 7F0C79C0 00803825 */   move  $a3, $a0
.L7F0C79C4:
/* 0FC4F4 7F0C79C4 00802825 */  move  $a1, $a0
.L7F0C79C8:
/* 0FC4F8 7F0C79C8 00E57823 */  subu  $t7, $a3, $a1
/* 0FC4FC 7F0C79CC 29E10002 */  slti  $at, $t7, 2
/* 0FC500 7F0C79D0 5020FFD8 */  beql  $at, $zero, .L7F0C7934
/* 0FC504 7F0C79D4 00E55821 */   addu  $t3, $a3, $a1
.L7F0C79D8:
/* 0FC508 7F0C79D8 24E5FFFC */  addiu $a1, $a3, -4
/* 0FC50C 7F0C79DC 04A10002 */  bgez  $a1, .L7F0C79E8
/* 0FC510 7F0C79E0 8FB9001C */   lw    $t9, 0x1c($sp)
/* 0FC514 7F0C79E4 00002825 */  move  $a1, $zero
.L7F0C79E8:
/* 0FC518 7F0C79E8 24E70004 */  addiu $a3, $a3, 4
/* 0FC51C 7F0C79EC 00F9082A */  slt   $at, $a3, $t9
/* 0FC520 7F0C79F0 14200002 */  bnez  $at, .L7F0C79FC
/* 0FC524 7F0C79F4 3C14000F */   lui   $s4, (0x000F423F >> 16) # lui $s4, 0xf
/* 0FC528 7F0C79F8 00C03825 */  move  $a3, $a2
.L7F0C79FC:
/* 0FC52C 7F0C79FC 3694423F */  ori   $s4, (0x000F423F & 0xFFFF) # ori $s4, $s4, 0x423f
/* 0FC530 7F0C7A00 00E5082A */  slt   $at, $a3, $a1
/* 0FC534 7F0C7A04 00004025 */  move  $t0, $zero
/* 0FC538 7F0C7A08 02803025 */  move  $a2, $s4
/* 0FC53C 7F0C7A0C 1420006A */  bnez  $at, .L7F0C7BB8
/* 0FC540 7F0C7A10 00A02025 */   move  $a0, $a1
/* 0FC544 7F0C7A14 00E51023 */  subu  $v0, $a3, $a1
/* 0FC548 7F0C7A18 24420001 */  addiu $v0, $v0, 1
/* 0FC54C 7F0C7A1C 30580001 */  andi  $t8, $v0, 1
/* 0FC550 7F0C7A20 13000023 */  beqz  $t8, .L7F0C7AB0
/* 0FC554 7F0C7A24 00057040 */   sll   $t6, $a1, 1
/* 0FC558 7F0C7A28 024E7821 */  addu  $t7, $s2, $t6
/* 0FC55C 7F0C7A2C 95E20000 */  lhu   $v0, ($t7)
/* 0FC560 7F0C7A30 24A40001 */  addiu $a0, $a1, 1
/* 0FC564 7F0C7A34 240303C1 */  li    $v1, 961
/* 0FC568 7F0C7A38 30590001 */  andi  $t9, $v0, 1
/* 0FC56C 7F0C7A3C 15590003 */  bne   $t2, $t9, .L7F0C7A4C
/* 0FC570 7F0C7A40 0002C2C3 */   sra   $t8, $v0, 0xb
/* 0FC574 7F0C7A44 10000001 */  b     .L7F0C7A4C
/* 0FC578 7F0C7A48 00001825 */   move  $v1, $zero
.L7F0C7A4C:
/* 0FC57C 7F0C7A4C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC580 7F0C7A50 01D05823 */  subu  $t3, $t6, $s0
/* 0FC584 7F0C7A54 016B0019 */  multu $t3, $t3
/* 0FC588 7F0C7A58 00027983 */  sra   $t7, $v0, 6
/* 0FC58C 7F0C7A5C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC590 7F0C7A60 03316023 */  subu  $t4, $t9, $s1
/* 0FC594 7F0C7A64 0002C043 */  sra   $t8, $v0, 1
/* 0FC598 7F0C7A68 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC59C 7F0C7A6C 01C96823 */  subu  $t5, $t6, $t1
/* 0FC5A0 7F0C7A70 00007812 */  mflo  $t7
/* 0FC5A4 7F0C7A74 006FC821 */  addu  $t9, $v1, $t7
/* 0FC5A8 7F0C7A78 00000000 */  nop   
/* 0FC5AC 7F0C7A7C 018C0019 */  multu $t4, $t4
/* 0FC5B0 7F0C7A80 0000C012 */  mflo  $t8
/* 0FC5B4 7F0C7A84 03387021 */  addu  $t6, $t9, $t8
/* 0FC5B8 7F0C7A88 24F90001 */  addiu $t9, $a3, 1
/* 0FC5BC 7F0C7A8C 01AD0019 */  multu $t5, $t5
/* 0FC5C0 7F0C7A90 00007812 */  mflo  $t7
/* 0FC5C4 7F0C7A94 01CF9821 */  addu  $s3, $t6, $t7
/* 0FC5C8 7F0C7A98 0274082A */  slt   $at, $s3, $s4
/* 0FC5CC 7F0C7A9C 10200003 */  beqz  $at, .L7F0C7AAC
/* 0FC5D0 7F0C7AA0 00000000 */   nop   
/* 0FC5D4 7F0C7AA4 00A04025 */  move  $t0, $a1
/* 0FC5D8 7F0C7AA8 02603025 */  move  $a2, $s3
.L7F0C7AAC:
/* 0FC5DC 7F0C7AAC 13240042 */  beq   $t9, $a0, .L7F0C7BB8
.L7F0C7AB0:
/* 0FC5E0 7F0C7AB0 0004C040 */   sll   $t8, $a0, 1
/* 0FC5E4 7F0C7AB4 02582821 */  addu  $a1, $s2, $t8
.L7F0C7AB8:
/* 0FC5E8 7F0C7AB8 94A20000 */  lhu   $v0, ($a1)
/* 0FC5EC 7F0C7ABC 240303C1 */  li    $v1, 961
/* 0FC5F0 7F0C7AC0 304E0001 */  andi  $t6, $v0, 1
/* 0FC5F4 7F0C7AC4 154E0003 */  bne   $t2, $t6, .L7F0C7AD4
/* 0FC5F8 7F0C7AC8 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC5FC 7F0C7ACC 10000001 */  b     .L7F0C7AD4
/* 0FC600 7F0C7AD0 00001825 */   move  $v1, $zero
.L7F0C7AD4:
/* 0FC604 7F0C7AD4 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC608 7F0C7AD8 03306023 */  subu  $t4, $t9, $s0
/* 0FC60C 7F0C7ADC 018C0019 */  multu $t4, $t4
/* 0FC610 7F0C7AE0 0002C183 */  sra   $t8, $v0, 6
/* 0FC614 7F0C7AE4 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC618 7F0C7AE8 01D16823 */  subu  $t5, $t6, $s1
/* 0FC61C 7F0C7AEC 00027843 */  sra   $t7, $v0, 1
/* 0FC620 7F0C7AF0 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC624 7F0C7AF4 03299023 */  subu  $s2, $t9, $t1
/* 0FC628 7F0C7AF8 0000C012 */  mflo  $t8
/* 0FC62C 7F0C7AFC 00787021 */  addu  $t6, $v1, $t8
/* 0FC630 7F0C7B00 240303C1 */  li    $v1, 961
/* 0FC634 7F0C7B04 01AD0019 */  multu $t5, $t5
/* 0FC638 7F0C7B08 00007812 */  mflo  $t7
/* 0FC63C 7F0C7B0C 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC640 7F0C7B10 00000000 */  nop   
/* 0FC644 7F0C7B14 02520019 */  multu $s2, $s2
/* 0FC648 7F0C7B18 0000C012 */  mflo  $t8
/* 0FC64C 7F0C7B1C 03389821 */  addu  $s3, $t9, $t8
/* 0FC650 7F0C7B20 0266082A */  slt   $at, $s3, $a2
/* 0FC654 7F0C7B24 50200004 */  beql  $at, $zero, .L7F0C7B38
/* 0FC658 7F0C7B28 94A20002 */   lhu   $v0, 2($a1)
/* 0FC65C 7F0C7B2C 00804025 */  move  $t0, $a0
/* 0FC660 7F0C7B30 02603025 */  move  $a2, $s3
/* 0FC664 7F0C7B34 94A20002 */  lhu   $v0, 2($a1)
.L7F0C7B38:
/* 0FC668 7F0C7B38 304E0001 */  andi  $t6, $v0, 1
/* 0FC66C 7F0C7B3C 154E0003 */  bne   $t2, $t6, .L7F0C7B4C
/* 0FC670 7F0C7B40 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC674 7F0C7B44 10000001 */  b     .L7F0C7B4C
/* 0FC678 7F0C7B48 00001825 */   move  $v1, $zero
.L7F0C7B4C:
/* 0FC67C 7F0C7B4C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC680 7F0C7B50 03305823 */  subu  $t3, $t9, $s0
/* 0FC684 7F0C7B54 016B0019 */  multu $t3, $t3
/* 0FC688 7F0C7B58 0002C183 */  sra   $t8, $v0, 6
/* 0FC68C 7F0C7B5C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC690 7F0C7B60 01D16023 */  subu  $t4, $t6, $s1
/* 0FC694 7F0C7B64 00027843 */  sra   $t7, $v0, 1
/* 0FC698 7F0C7B68 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC69C 7F0C7B6C 03296823 */  subu  $t5, $t9, $t1
/* 0FC6A0 7F0C7B70 0000C012 */  mflo  $t8
/* 0FC6A4 7F0C7B74 00787021 */  addu  $t6, $v1, $t8
/* 0FC6A8 7F0C7B78 00000000 */  nop   
/* 0FC6AC 7F0C7B7C 018C0019 */  multu $t4, $t4
/* 0FC6B0 7F0C7B80 00007812 */  mflo  $t7
/* 0FC6B4 7F0C7B84 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC6B8 7F0C7B88 24EE0001 */  addiu $t6, $a3, 1
/* 0FC6BC 7F0C7B8C 01AD0019 */  multu $t5, $t5
/* 0FC6C0 7F0C7B90 0000C012 */  mflo  $t8
/* 0FC6C4 7F0C7B94 03389021 */  addu  $s2, $t9, $t8
/* 0FC6C8 7F0C7B98 0246082A */  slt   $at, $s2, $a2
/* 0FC6CC 7F0C7B9C 50200004 */  beql  $at, $zero, .L7F0C7BB0
/* 0FC6D0 7F0C7BA0 24840002 */   addiu $a0, $a0, 2
/* 0FC6D4 7F0C7BA4 24880001 */  addiu $t0, $a0, 1
/* 0FC6D8 7F0C7BA8 02403025 */  move  $a2, $s2
/* 0FC6DC 7F0C7BAC 24840002 */  addiu $a0, $a0, 2
.L7F0C7BB0:
/* 0FC6E0 7F0C7BB0 15C4FFC1 */  bne   $t6, $a0, .L7F0C7AB8
/* 0FC6E4 7F0C7BB4 24A50004 */   addiu $a1, $a1, 4
.L7F0C7BB8:
/* 0FC6E8 7F0C7BB8 01001025 */  move  $v0, $t0
.L7F0C7BBC:
/* 0FC6EC 7F0C7BBC 8FB00004 */  lw    $s0, 4($sp)
/* 0FC6F0 7F0C7BC0 8FB10008 */  lw    $s1, 8($sp)
/* 0FC6F4 7F0C7BC4 8FB2000C */  lw    $s2, 0xc($sp)
/* 0FC6F8 7F0C7BC8 8FB30010 */  lw    $s3, 0x10($sp)
/* 0FC6FC 7F0C7BCC 8FB40014 */  lw    $s4, 0x14($sp)
/* 0FC700 7F0C7BD0 03E00008 */  jr    $ra
/* 0FC704 7F0C7BD4 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C7BD8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C7BD8
/* 0FC708 7F0C7BD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0FC70C 7F0C7BDC AFB1000C */  sw    $s1, 0xc($sp)
/* 0FC710 7F0C7BE0 AFB00008 */  sw    $s0, 8($sp)
/* 0FC714 7F0C7BE4 18A00030 */  blez  $a1, .L7F0C7CA8
/* 0FC718 7F0C7BE8 00001825 */   move  $v1, $zero
/* 0FC71C 7F0C7BEC 30AA0003 */  andi  $t2, $a1, 3
/* 0FC720 7F0C7BF0 11400010 */  beqz  $t2, .L7F0C7C34
/* 0FC724 7F0C7BF4 01404025 */   move  $t0, $t2
/* 0FC728 7F0C7BF8 00067A00 */  sll   $t7, $a2, 8
/* 0FC72C 7F0C7BFC 01E74825 */  or    $t1, $t7, $a3
/* 0FC730 7F0C7C00 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC734 7F0C7C04 00007040 */  sll   $t6, $zero, 1
/* 0FC738 7F0C7C08 008E1021 */  addu  $v0, $a0, $t6
/* 0FC73C 7F0C7C0C 03004825 */  move  $t1, $t8
.L7F0C7C10:
/* 0FC740 7F0C7C10 94590000 */  lhu   $t9, ($v0)
/* 0FC744 7F0C7C14 55390004 */  bnel  $t1, $t9, .L7F0C7C28
/* 0FC748 7F0C7C18 24630001 */   addiu $v1, $v1, 1
/* 0FC74C 7F0C7C1C 10000073 */  b     .L7F0C7DEC
/* 0FC750 7F0C7C20 00601025 */   move  $v0, $v1
/* 0FC754 7F0C7C24 24630001 */  addiu $v1, $v1, 1
.L7F0C7C28:
/* 0FC758 7F0C7C28 1503FFF9 */  bne   $t0, $v1, .L7F0C7C10
/* 0FC75C 7F0C7C2C 24420002 */   addiu $v0, $v0, 2
/* 0FC760 7F0C7C30 1065001D */  beq   $v1, $a1, .L7F0C7CA8
.L7F0C7C34:
/* 0FC764 7F0C7C34 00067A00 */   sll   $t7, $a2, 8
/* 0FC768 7F0C7C38 01E74825 */  or    $t1, $t7, $a3
/* 0FC76C 7F0C7C3C 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC770 7F0C7C40 00037040 */  sll   $t6, $v1, 1
/* 0FC774 7F0C7C44 008E1021 */  addu  $v0, $a0, $t6
/* 0FC778 7F0C7C48 03004825 */  move  $t1, $t8
.L7F0C7C4C:
/* 0FC77C 7F0C7C4C 94590000 */  lhu   $t9, ($v0)
/* 0FC780 7F0C7C50 55390004 */  bnel  $t1, $t9, .L7F0C7C64
/* 0FC784 7F0C7C54 944E0002 */   lhu   $t6, 2($v0)
/* 0FC788 7F0C7C58 10000064 */  b     .L7F0C7DEC
/* 0FC78C 7F0C7C5C 00601025 */   move  $v0, $v1
/* 0FC790 7F0C7C60 944E0002 */  lhu   $t6, 2($v0)
.L7F0C7C64:
/* 0FC794 7F0C7C64 552E0004 */  bnel  $t1, $t6, .L7F0C7C78
/* 0FC798 7F0C7C68 944F0004 */   lhu   $t7, 4($v0)
/* 0FC79C 7F0C7C6C 1000005F */  b     .L7F0C7DEC
/* 0FC7A0 7F0C7C70 24620001 */   addiu $v0, $v1, 1
/* 0FC7A4 7F0C7C74 944F0004 */  lhu   $t7, 4($v0)
.L7F0C7C78:
/* 0FC7A8 7F0C7C78 552F0004 */  bnel  $t1, $t7, .L7F0C7C8C
/* 0FC7AC 7F0C7C7C 94580006 */   lhu   $t8, 6($v0)
/* 0FC7B0 7F0C7C80 1000005A */  b     .L7F0C7DEC
/* 0FC7B4 7F0C7C84 24620002 */   addiu $v0, $v1, 2
/* 0FC7B8 7F0C7C88 94580006 */  lhu   $t8, 6($v0)
.L7F0C7C8C:
/* 0FC7BC 7F0C7C8C 55380004 */  bnel  $t1, $t8, .L7F0C7CA0
/* 0FC7C0 7F0C7C90 24630004 */   addiu $v1, $v1, 4
/* 0FC7C4 7F0C7C94 10000055 */  b     .L7F0C7DEC
/* 0FC7C8 7F0C7C98 24620003 */   addiu $v0, $v1, 3
/* 0FC7CC 7F0C7C9C 24630004 */  addiu $v1, $v1, 4
.L7F0C7CA0:
/* 0FC7D0 7F0C7CA0 1465FFEA */  bne   $v1, $a1, .L7F0C7C4C
/* 0FC7D4 7F0C7CA4 24420008 */   addiu $v0, $v0, 8
.L7F0C7CA8:
/* 0FC7D8 7F0C7CA8 24A8FFFF */  addiu $t0, $a1, -1
/* 0FC7DC 7F0C7CAC 29010002 */  slti  $at, $t0, 2
/* 0FC7E0 7F0C7CB0 00001025 */  move  $v0, $zero
/* 0FC7E4 7F0C7CB4 14200027 */  bnez  $at, .L7F0C7D54
/* 0FC7E8 7F0C7CB8 01001825 */   move  $v1, $t0
/* 0FC7EC 7F0C7CBC 00C60019 */  multu $a2, $a2
/* 0FC7F0 7F0C7CC0 0000C812 */  mflo  $t9
/* 0FC7F4 7F0C7CC4 00000000 */  nop   
/* 0FC7F8 7F0C7CC8 00000000 */  nop   
/* 0FC7FC 7F0C7CCC 00E70019 */  multu $a3, $a3
/* 0FC800 7F0C7CD0 00007012 */  mflo  $t6
/* 0FC804 7F0C7CD4 032E4821 */  addu  $t1, $t9, $t6
/* 0FC808 7F0C7CD8 00000000 */  nop   
/* 0FC80C 7F0C7CDC 00625821 */  addu  $t3, $v1, $v0
.L7F0C7CE0:
/* 0FC810 7F0C7CE0 000B5043 */  sra   $t2, $t3, 1
/* 0FC814 7F0C7CE4 000AC040 */  sll   $t8, $t2, 1
/* 0FC818 7F0C7CE8 0098C821 */  addu  $t9, $a0, $t8
/* 0FC81C 7F0C7CEC 972C0000 */  lhu   $t4, ($t9)
/* 0FC820 7F0C7CF0 000C6A03 */  sra   $t5, $t4, 8
/* 0FC824 7F0C7CF4 31AE00FF */  andi  $t6, $t5, 0xff
/* 0FC828 7F0C7CF8 01CE0019 */  multu $t6, $t6
/* 0FC82C 7F0C7CFC 319000FF */  andi  $s0, $t4, 0xff
/* 0FC830 7F0C7D00 00007812 */  mflo  $t7
/* 0FC834 7F0C7D04 00000000 */  nop   
/* 0FC838 7F0C7D08 00000000 */  nop   
/* 0FC83C 7F0C7D0C 02100019 */  multu $s0, $s0
/* 0FC840 7F0C7D10 0000C012 */  mflo  $t8
/* 0FC844 7F0C7D14 01F88821 */  addu  $s1, $t7, $t8
/* 0FC848 7F0C7D18 0229082A */  slt   $at, $s1, $t1
/* 0FC84C 7F0C7D1C 50200004 */  beql  $at, $zero, .L7F0C7D30
/* 0FC850 7F0C7D20 0131082A */   slt   $at, $t1, $s1
/* 0FC854 7F0C7D24 10000007 */  b     .L7F0C7D44
/* 0FC858 7F0C7D28 01401025 */   move  $v0, $t2
/* 0FC85C 7F0C7D2C 0131082A */  slt   $at, $t1, $s1
.L7F0C7D30:
/* 0FC860 7F0C7D30 10200003 */  beqz  $at, .L7F0C7D40
/* 0FC864 7F0C7D34 01401825 */   move  $v1, $t2
/* 0FC868 7F0C7D38 10000002 */  b     .L7F0C7D44
/* 0FC86C 7F0C7D3C 01401825 */   move  $v1, $t2
.L7F0C7D40:
/* 0FC870 7F0C7D40 01401025 */  move  $v0, $t2
.L7F0C7D44:
/* 0FC874 7F0C7D44 0062C823 */  subu  $t9, $v1, $v0
/* 0FC878 7F0C7D48 2B210002 */  slti  $at, $t9, 2
/* 0FC87C 7F0C7D4C 5020FFE4 */  beql  $at, $zero, .L7F0C7CE0
/* 0FC880 7F0C7D50 00625821 */   addu  $t3, $v1, $v0
.L7F0C7D54:
/* 0FC884 7F0C7D54 2462FFFC */  addiu $v0, $v1, -4
/* 0FC888 7F0C7D58 04410002 */  bgez  $v0, .L7F0C7D64
/* 0FC88C 7F0C7D5C 24630004 */   addiu $v1, $v1, 4
/* 0FC890 7F0C7D60 00001025 */  move  $v0, $zero
.L7F0C7D64:
/* 0FC894 7F0C7D64 0065082A */  slt   $at, $v1, $a1
/* 0FC898 7F0C7D68 14200002 */  bnez  $at, .L7F0C7D74
/* 0FC89C 7F0C7D6C 00002825 */   move  $a1, $zero
/* 0FC8A0 7F0C7D70 01001825 */  move  $v1, $t0
.L7F0C7D74:
/* 0FC8A4 7F0C7D74 3C08000F */  lui   $t0, (0x000F423F >> 16) # lui $t0, 0xf
/* 0FC8A8 7F0C7D78 0062082A */  slt   $at, $v1, $v0
/* 0FC8AC 7F0C7D7C 3508423F */  ori   $t0, (0x000F423F & 0xFFFF) # ori $t0, $t0, 0x423f
/* 0FC8B0 7F0C7D80 14200019 */  bnez  $at, .L7F0C7DE8
/* 0FC8B4 7F0C7D84 00405025 */   move  $t2, $v0
/* 0FC8B8 7F0C7D88 00027040 */  sll   $t6, $v0, 1
/* 0FC8BC 7F0C7D8C 008E1021 */  addu  $v0, $a0, $t6
/* 0FC8C0 7F0C7D90 246B0001 */  addiu $t3, $v1, 1
.L7F0C7D94:
/* 0FC8C4 7F0C7D94 944C0000 */  lhu   $t4, ($v0)
/* 0FC8C8 7F0C7D98 000C7A03 */  sra   $t7, $t4, 8
/* 0FC8CC 7F0C7D9C 31F800FF */  andi  $t8, $t7, 0xff
/* 0FC8D0 7F0C7DA0 03061823 */  subu  $v1, $t8, $a2
/* 0FC8D4 7F0C7DA4 00630019 */  multu $v1, $v1
/* 0FC8D8 7F0C7DA8 319900FF */  andi  $t9, $t4, 0xff
/* 0FC8DC 7F0C7DAC 03272023 */  subu  $a0, $t9, $a3
/* 0FC8E0 7F0C7DB0 00007012 */  mflo  $t6
/* 0FC8E4 7F0C7DB4 00000000 */  nop   
/* 0FC8E8 7F0C7DB8 00000000 */  nop   
/* 0FC8EC 7F0C7DBC 00840019 */  multu $a0, $a0
/* 0FC8F0 7F0C7DC0 00007812 */  mflo  $t7
/* 0FC8F4 7F0C7DC4 01CF4821 */  addu  $t1, $t6, $t7
/* 0FC8F8 7F0C7DC8 0128082A */  slt   $at, $t1, $t0
/* 0FC8FC 7F0C7DCC 50200004 */  beql  $at, $zero, .L7F0C7DE0
/* 0FC900 7F0C7DD0 254A0001 */   addiu $t2, $t2, 1
/* 0FC904 7F0C7DD4 01402825 */  move  $a1, $t2
/* 0FC908 7F0C7DD8 01204025 */  move  $t0, $t1
/* 0FC90C 7F0C7DDC 254A0001 */  addiu $t2, $t2, 1
.L7F0C7DE0:
/* 0FC910 7F0C7DE0 156AFFEC */  bne   $t3, $t2, .L7F0C7D94
/* 0FC914 7F0C7DE4 24420002 */   addiu $v0, $v0, 2
.L7F0C7DE8:
/* 0FC918 7F0C7DE8 00A01025 */  move  $v0, $a1
.L7F0C7DEC:
/* 0FC91C 7F0C7DEC 8FB00008 */  lw    $s0, 8($sp)
/* 0FC920 7F0C7DF0 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FC924 7F0C7DF4 03E00008 */  jr    $ra
/* 0FC928 7F0C7DF8 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
void process_huffman_compressed_images(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BD30*/
glabel jpt_8005BD30
.word huffman_type0_1
.word huffman_type0_1
.word huffman_type2
.word huffman_type3
.word huffman_type4
.word huffman_type5
.word huffman_type6
.word huffman_type7
.word huffman_type8
.word huffman_type9
.text
glabel process_huffman_compressed_images
/* 0FC92C 7F0C7DFC 27BDCF58 */  addiu $sp, $sp, -0x30a8
/* 0FC930 7F0C7E00 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0FC934 7F0C7E04 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0FC938 7F0C7E08 AFB70044 */  sw    $s7, 0x44($sp)
/* 0FC93C 7F0C7E0C AFB60040 */  sw    $s6, 0x40($sp)
/* 0FC940 7F0C7E10 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0FC944 7F0C7E14 AFB40038 */  sw    $s4, 0x38($sp)
/* 0FC948 7F0C7E18 AFB30034 */  sw    $s3, 0x34($sp)
/* 0FC94C 7F0C7E1C AFB20030 */  sw    $s2, 0x30($sp)
/* 0FC950 7F0C7E20 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0FC954 7F0C7E24 AFB00028 */  sw    $s0, 0x28($sp)
/* 0FC958 7F0C7E28 AFA530AC */  sw    $a1, 0x30ac($sp)
/* 0FC95C 7F0C7E2C AFA630B0 */  sw    $a2, 0x30b0($sp)
/* 0FC960 7F0C7E30 AFA730B4 */  sw    $a3, 0x30b4($sp)
/* 0FC964 7F0C7E34 AFA00088 */  sw    $zero, 0x88($sp)
/* 0FC968 7F0C7E38 0FC32FC4 */  jal   makeemptyimageatpos
/* 0FC96C 7F0C7E3C AFA00070 */   sw    $zero, 0x70($sp)
/* 0FC970 7F0C7E40 8FA930B0 */  lw    $t1, 0x30b0($sp)
/* 0FC974 7F0C7E44 8FAA30B4 */  lw    $t2, 0x30b4($sp)
/* 0FC978 7F0C7E48 240E0001 */  li    $t6, 1
/* 0FC97C 7F0C7E4C 11200005 */  beqz  $t1, .L7F0C7E64
/* 0FC980 7F0C7E50 3C088009 */   lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FC984 7F0C7E54 51400004 */  beql  $t2, $zero, .L7F0C7E68
/* 0FC988 7F0C7E58 8FAA30B4 */   lw    $t2, 0x30b4($sp)
/* 0FC98C 7F0C7E5C 10000003 */  b     .L7F0C7E6C
/* 0FC990 7F0C7E60 AFAA009C */   sw    $t2, 0x9c($sp)
.L7F0C7E64:
/* 0FC994 7F0C7E64 8FAA30B4 */  lw    $t2, 0x30b4($sp)
.L7F0C7E68:
/* 0FC998 7F0C7E68 AFAE009C */  sw    $t6, 0x9c($sp)
.L7F0C7E6C:
/* 0FC99C 7F0C7E6C 8FA730B8 */  lw    $a3, 0x30b8($sp)
/* 0FC9A0 7F0C7E70 000AC940 */  sll   $t9, $t2, 5
/* 0FC9A4 7F0C7E74 00097940 */  sll   $t7, $t1, 5
/* 0FC9A8 7F0C7E78 8CE3000C */  lw    $v1, 0xc($a3)
/* 0FC9AC 7F0C7E7C 31F80020 */  andi  $t8, $t7, 0x20
/* 0FC9B0 7F0C7E80 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FC9B4 7F0C7E84 906B000B */  lbu   $t3, 0xb($v1)
/* 0FC9B8 7F0C7E88 316CFF1F */  andi  $t4, $t3, 0xff1f
/* 0FC9BC 7F0C7E8C 032C6825 */  or    $t5, $t9, $t4
/* 0FC9C0 7F0C7E90 A06D000B */  sb    $t5, 0xb($v1)
/* 0FC9C4 7F0C7E94 8CE3000C */  lw    $v1, 0xc($a3)
/* 0FC9C8 7F0C7E98 906B000C */  lbu   $t3, 0xc($v1)
/* 0FC9CC 7F0C7E9C 3179FFDF */  andi  $t9, $t3, 0xffdf
/* 0FC9D0 7F0C7EA0 03196025 */  or    $t4, $t8, $t9
/* 0FC9D4 7F0C7EA4 11200017 */  beqz  $t1, .L7F0C7F04
/* 0FC9D8 7F0C7EA8 A06C000C */   sb    $t4, 0xc($v1)
/* 0FC9DC 7F0C7EAC 8D050000 */  lw    $a1, ($t0)
/* 0FC9E0 7F0C7EB0 24060001 */  li    $a2, 1
/* 0FC9E4 7F0C7EB4 AFA60070 */  sw    $a2, 0x70($sp)
/* 0FC9E8 7F0C7EB8 58A00013 */  blezl $a1, .L7F0C7F08
/* 0FC9EC 7F0C7EBC 8FB9009C */   lw    $t9, 0x9c($sp)
/* 0FC9F0 7F0C7EC0 8CED000C */  lw    $t5, 0xc($a3)
/* 0FC9F4 7F0C7EC4 3C0F8009 */  lui   $t7, %hi(word_CODE_bss_8008C730)
/* 0FC9F8 7F0C7EC8 25E2C730 */  addiu $v0, $t7, %lo(word_CODE_bss_8008C730)
/* 0FC9FC 7F0C7ECC 8DA30000 */  lw    $v1, ($t5)
/* 0FCA00 7F0C7ED0 00055900 */  sll   $t3, $a1, 4
/* 0FCA04 7F0C7ED4 01622021 */  addu  $a0, $t3, $v0
/* 0FCA08 7F0C7ED8 00037502 */  srl   $t6, $v1, 0x14
/* 0FCA0C 7F0C7EDC 01C01825 */  move  $v1, $t6
/* 0FCA10 7F0C7EE0 84580000 */  lh    $t8, ($v0)
.L7F0C7EE4:
/* 0FCA14 7F0C7EE4 24420010 */  addiu $v0, $v0, 0x10
/* 0FCA18 7F0C7EE8 0044082B */  sltu  $at, $v0, $a0
/* 0FCA1C 7F0C7EEC 14780002 */  bne   $v1, $t8, .L7F0C7EF8
/* 0FCA20 7F0C7EF0 00000000 */   nop   
/* 0FCA24 7F0C7EF4 00003025 */  move  $a2, $zero
.L7F0C7EF8:
/* 0FCA28 7F0C7EF8 5420FFFA */  bnezl $at, .L7F0C7EE4
/* 0FCA2C 7F0C7EFC 84580000 */   lh    $t8, ($v0)
/* 0FCA30 7F0C7F00 AFA60070 */  sw    $a2, 0x70($sp)
.L7F0C7F04:
/* 0FCA34 7F0C7F04 8FB9009C */  lw    $t9, 0x9c($sp)
.L7F0C7F08:
/* 0FCA38 7F0C7F08 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FCA3C 7F0C7F0C 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FCA40 7F0C7F10 8FA60070 */  lw    $a2, 0x70($sp)
/* 0FCA44 7F0C7F14 1B2001BA */  blez  $t9, .L7F0C8600
/* 0FCA48 7F0C7F18 AFA000A0 */   sw    $zero, 0xa0($sp)
/* 0FCA4C 7F0C7F1C AFA60070 */  sw    $a2, 0x70($sp)
/* 0FCA50 7F0C7F20 27BE10A8 */  addiu $fp, $sp, 0x10a8
.L7F0C7F24:
/* 0FCA54 7F0C7F24 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCA58 7F0C7F28 24040004 */   li    $a0, 4
/* 0FCA5C 7F0C7F2C AFA20080 */  sw    $v0, 0x80($sp)
/* 0FCA60 7F0C7F30 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCA64 7F0C7F34 24040008 */   li    $a0, 8
/* 0FCA68 7F0C7F38 0040B025 */  move  $s6, $v0
/* 0FCA6C 7F0C7F3C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCA70 7F0C7F40 24040008 */   li    $a0, 8
/* 0FCA74 7F0C7F44 0040B825 */  move  $s7, $v0
/* 0FCA78 7F0C7F48 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCA7C 7F0C7F4C 24040004 */   li    $a0, 4
/* 0FCA80 7F0C7F50 8FA500A0 */  lw    $a1, 0xa0($sp)
/* 0FCA84 7F0C7F54 8FA430B8 */  lw    $a0, 0x30b8($sp)
/* 0FCA88 7F0C7F58 8FAB0070 */  lw    $t3, 0x70($sp)
/* 0FCA8C 7F0C7F5C 14A00026 */  bnez  $a1, .L7F0C7FF8
/* 0FCA90 7F0C7F60 00000000 */   nop   
/* 0FCA94 7F0C7F64 8C8C000C */  lw    $t4, 0xc($a0)
/* 0FCA98 7F0C7F68 3C0B8005 */  lui   $t3, %hi(n64imagetypes)
/* 0FCA9C 7F0C7F6C A1960008 */  sb    $s6, 8($t4)
/* 0FCAA0 7F0C7F70 8C8D000C */  lw    $t5, 0xc($a0)
/* 0FCAA4 7F0C7F74 A1B70009 */  sb    $s7, 9($t5)
/* 0FCAA8 7F0C7F78 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCAAC 7F0C7F7C 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCAB0 7F0C7F80 00147080 */  sll   $t6, $s4, 2
/* 0FCAB4 7F0C7F84 016E5821 */  addu  $t3, $t3, $t6
/* 0FCAB8 7F0C7F88 8D6F9248 */  lw    $t7, %lo(n64imagetypes)($t3)
/* 0FCABC 7F0C7F8C 906C000B */  lbu   $t4, 0xb($v1)
/* 0FCAC0 7F0C7F90 01C0A025 */  move  $s4, $t6
/* 0FCAC4 7F0C7F94 000FC080 */  sll   $t8, $t7, 2
/* 0FCAC8 7F0C7F98 3319001C */  andi  $t9, $t8, 0x1c
/* 0FCACC 7F0C7F9C 318DFFE3 */  andi  $t5, $t4, 0xffe3
/* 0FCAD0 7F0C7FA0 032D7025 */  or    $t6, $t9, $t5
/* 0FCAD4 7F0C7FA4 A06E000B */  sb    $t6, 0xb($v1)
/* 0FCAD8 7F0C7FA8 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCADC 7F0C7FAC 3C0B8005 */  lui   $t3, %hi(n64pixelsizes)
/* 0FCAE0 7F0C7FB0 01745821 */  addu  $t3, $t3, $s4
/* 0FCAE4 7F0C7FB4 8D6F927C */  lw    $t7, %lo(n64pixelsizes)($t3)
/* 0FCAE8 7F0C7FB8 906C000B */  lbu   $t4, 0xb($v1)
/* 0FCAEC 7F0C7FBC 3C0E8005 */  lui   $t6, %hi(imgflipvalues)
/* 0FCAF0 7F0C7FC0 31F80003 */  andi  $t8, $t7, 3
/* 0FCAF4 7F0C7FC4 3199FFFC */  andi  $t9, $t4, 0xfffc
/* 0FCAF8 7F0C7FC8 03196825 */  or    $t5, $t8, $t9
/* 0FCAFC 7F0C7FCC A06D000B */  sb    $t5, 0xb($v1)
/* 0FCB00 7F0C7FD0 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCB04 7F0C7FD4 01D47021 */  addu  $t6, $t6, $s4
/* 0FCB08 7F0C7FD8 8DCE92B0 */  lw    $t6, %lo(imgflipvalues)($t6)
/* 0FCB0C 7F0C7FDC 9079000C */  lbu   $t9, 0xc($v1)
/* 0FCB10 7F0C7FE0 000E7B83 */  sra   $t7, $t6, 0xe
/* 0FCB14 7F0C7FE4 000FC180 */  sll   $t8, $t7, 6
/* 0FCB18 7F0C7FE8 332DFF3F */  andi  $t5, $t9, 0xff3f
/* 0FCB1C 7F0C7FEC 030D7025 */  or    $t6, $t8, $t5
/* 0FCB20 7F0C7FF0 1000000B */  b     .L7F0C8020
/* 0FCB24 7F0C7FF4 A06E000C */   sb    $t6, 0xc($v1)
.L7F0C7FF8:
/* 0FCB28 7F0C7FF8 11600009 */  beqz  $t3, .L7F0C8020
/* 0FCB2C 7F0C7FFC 3C0F8009 */   lui   $t7, %hi(dword_CODE_bss_8008D090) 
/* 0FCB30 7F0C8000 8DEFD090 */  lw    $t7, %lo(dword_CODE_bss_8008D090)($t7)
/* 0FCB34 7F0C8004 3C188009 */  lui   $t8, %hi(word_CODE_bss_8008C730) 
/* 0FCB38 7F0C8008 2718C730 */  addiu $t8, %lo(word_CODE_bss_8008C730) # addiu $t8, $t8, -0x38d0
/* 0FCB3C 7F0C800C 000F6100 */  sll   $t4, $t7, 4
/* 0FCB40 7F0C8010 0185C821 */  addu  $t9, $t4, $a1
/* 0FCB44 7F0C8014 03381821 */  addu  $v1, $t9, $t8
/* 0FCB48 7F0C8018 A0760001 */  sb    $s6, 1($v1)
/* 0FCB4C 7F0C801C A0770008 */  sb    $s7, 8($v1)
.L7F0C8020:
/* 0FCB50 7F0C8020 02D70019 */  multu $s6, $s7
/* 0FCB54 7F0C8024 00026880 */  sll   $t5, $v0, 2
/* 0FCB58 7F0C8028 0000A812 */  mflo  $s5
/* 0FCB5C 7F0C802C 2AA12001 */  slti  $at, $s5, 0x2001
/* 0FCB60 7F0C8030 54200004 */  bnezl $at, .L7F0C8044
/* 0FCB64 7F0C8034 2C41000A */   sltiu $at, $v0, 0xa
/* 0FCB68 7F0C8038 100001BA */  b     .L7F0C8724
/* 0FCB6C 7F0C803C 00001025 */   move  $v0, $zero
/* 0FCB70 7F0C8040 2C41000A */  sltiu $at, $v0, 0xa
.L7F0C8044:
/* 0FCB74 7F0C8044 1020013B */  beqz  $at, .L7F0C8534
/* 0FCB78 7F0C8048 3C018006 */   lui   $at, %hi(jpt_8005BD30)
/* 0FCB7C 7F0C804C 002D0821 */  addu  $at, $at, $t5
/* 0FCB80 7F0C8050 8C2DBD30 */  lw    $t5, %lo(jpt_8005BD30)($at)
/* 0FCB84 7F0C8054 01A00008 */  jr    $t5
/* 0FCB88 7F0C8058 00000000 */   nop   
huffman_type0_1:
/* 0FCB8C 7F0C805C 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCB90 7F0C8060 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCB94 7F0C8064 02C02825 */  move  $a1, $s6
/* 0FCB98 7F0C8068 02E03025 */  move  $a2, $s7
/* 0FCB9C 7F0C806C 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCBA0 7F0C8070 02002025 */  move  $a0, $s0
/* 0FCBA4 7F0C8074 0FC326A7 */  jal   image_compression0_expand
/* 0FCBA8 7F0C8078 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FCBAC 7F0C807C 10000137 */  b     .L7F0C855C
/* 0FCBB0 7F0C8080 00408825 */   move  $s1, $v0
huffman_type2:
/* 0FCBB4 7F0C8084 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCBB8 7F0C8088 3C0C8005 */  lui   $t4, %hi(pixelbytecounts)
/* 0FCBBC 7F0C808C 3C068005 */  lui   $a2, %hi(pixelsamplebits)
/* 0FCBC0 7F0C8090 00147880 */  sll   $t7, $s4, 2
/* 0FCBC4 7F0C8094 018F6021 */  addu  $t4, $t4, $t7
/* 0FCBC8 7F0C8098 8D8C9178 */  lw    $t4, %lo(pixelbytecounts)($t4)
/* 0FCBCC 7F0C809C 00CF3021 */  addu  $a2, $a2, $t7
/* 0FCBD0 7F0C80A0 8CC691E0 */  lw    $a2, %lo(pixelsamplebits)($a2)
/* 0FCBD4 7F0C80A4 01960019 */  multu $t4, $s6
/* 0FCBD8 7F0C80A8 01E0A025 */  move  $s4, $t7
/* 0FCBDC 7F0C80AC 03C02025 */  move  $a0, $fp
/* 0FCBE0 7F0C80B0 0000C812 */  mflo  $t9
/* 0FCBE4 7F0C80B4 00000000 */  nop   
/* 0FCBE8 7F0C80B8 00000000 */  nop   
/* 0FCBEC 7F0C80BC 03370019 */  multu $t9, $s7
/* 0FCBF0 7F0C80C0 00002812 */  mflo  $a1
/* 0FCBF4 7F0C80C4 0FC32474 */  jal   generate_sample_table
/* 0FCBF8 7F0C80C8 00000000 */   nop   
/* 0FCBFC 7F0C80CC 3C188005 */  lui   $t8, %hi(pixelbytecounts+52)
/* 0FCC00 7F0C80D0 0314C021 */  addu  $t8, $t8, $s4
/* 0FCC04 7F0C80D4 8F1891AC */  lw    $t8, %lo(pixelbytecounts+52)($t8)
/* 0FCC08 7F0C80D8 00156880 */  sll   $t5, $s5, 2
/* 0FCC0C 7F0C80DC 01B56823 */  subu  $t5, $t5, $s5
/* 0FCC10 7F0C80E0 13000003 */  beqz  $t8, .L7F0C80F0
/* 0FCC14 7F0C80E4 03CD2021 */   addu  $a0, $fp, $t5
/* 0FCC18 7F0C80E8 0FC32692 */  jal   image_get_alpha_values
/* 0FCC1C 7F0C80EC 02A02825 */   move  $a1, $s5
.L7F0C80F0:
/* 0FCC20 7F0C80F0 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCC24 7F0C80F4 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCC28 7F0C80F8 8FAF0080 */  lw    $t7, 0x80($sp)
/* 0FCC2C 7F0C80FC 03C02025 */  move  $a0, $fp
/* 0FCC30 7F0C8100 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCC34 7F0C8104 02003825 */  move  $a3, $s0
/* 0FCC38 7F0C8108 02C02825 */  move  $a1, $s6
/* 0FCC3C 7F0C810C 02E03025 */  move  $a2, $s7
/* 0FCC40 7F0C8110 0FC32769 */  jal   generate_link_final_image
/* 0FCC44 7F0C8114 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FCC48 7F0C8118 10000110 */  b     .L7F0C855C
/* 0FCC4C 7F0C811C 00408825 */   move  $s1, $v0
huffman_type3:
/* 0FCC50 7F0C8120 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCC54 7F0C8124 3C198005 */  lui   $t9, %hi(pixelbytecounts) 
/* 0FCC58 7F0C8128 27399178 */  addiu $t9, %lo(pixelbytecounts) # addiu $t9, $t9, -0x6e88
/* 0FCC5C 7F0C812C 00146080 */  sll   $t4, $s4, 2
/* 0FCC60 7F0C8130 01999821 */  addu  $s3, $t4, $t9
/* 0FCC64 7F0C8134 8E780000 */  lw    $t8, ($s3)
/* 0FCC68 7F0C8138 0180A025 */  move  $s4, $t4
/* 0FCC6C 7F0C813C 00008825 */  move  $s1, $zero
/* 0FCC70 7F0C8140 1B000010 */  blez  $t8, .L7F0C8184
/* 0FCC74 7F0C8144 3C0D8005 */   lui   $t5, %hi(pixelsamplebits) 
/* 0FCC78 7F0C8148 25AD91E0 */  addiu $t5, %lo(pixelsamplebits) # addiu $t5, $t5, -0x6e20
/* 0FCC7C 7F0C814C 018D9021 */  addu  $s2, $t4, $t5
/* 0FCC80 7F0C8150 03C08025 */  move  $s0, $fp
/* 0FCC84 7F0C8154 02002025 */  move  $a0, $s0
.L7F0C8158:
/* 0FCC88 7F0C8158 02A02825 */  move  $a1, $s5
/* 0FCC8C 7F0C815C 0FC32474 */  jal   generate_sample_table
/* 0FCC90 7F0C8160 8E460000 */   lw    $a2, ($s2)
/* 0FCC94 7F0C8164 02D70019 */  multu $s6, $s7
/* 0FCC98 7F0C8168 8E6B0000 */  lw    $t3, ($s3)
/* 0FCC9C 7F0C816C 26310001 */  addiu $s1, $s1, 1
/* 0FCCA0 7F0C8170 022B082A */  slt   $at, $s1, $t3
/* 0FCCA4 7F0C8174 00007012 */  mflo  $t6
/* 0FCCA8 7F0C8178 020E8021 */  addu  $s0, $s0, $t6
/* 0FCCAC 7F0C817C 5420FFF6 */  bnezl $at, .L7F0C8158
/* 0FCCB0 7F0C8180 02002025 */   move  $a0, $s0
.L7F0C8184:
/* 0FCCB4 7F0C8184 3C0F8005 */  lui   $t7, %hi(pixelbytecounts+52)
/* 0FCCB8 7F0C8188 01F47821 */  addu  $t7, $t7, $s4
/* 0FCCBC 7F0C818C 8DEF91AC */  lw    $t7, %lo(pixelbytecounts+52)($t7)
/* 0FCCC0 7F0C8190 00156080 */  sll   $t4, $s5, 2
/* 0FCCC4 7F0C8194 01956023 */  subu  $t4, $t4, $s5
/* 0FCCC8 7F0C8198 11E00003 */  beqz  $t7, .L7F0C81A8
/* 0FCCCC 7F0C819C 03CC2021 */   addu  $a0, $fp, $t4
/* 0FCCD0 7F0C81A0 0FC32692 */  jal   image_get_alpha_values
/* 0FCCD4 7F0C81A4 02A02825 */   move  $a1, $s5
.L7F0C81A8:
/* 0FCCD8 7F0C81A8 8FB930AC */  lw    $t9, 0x30ac($sp)
/* 0FCCDC 7F0C81AC 8FB80088 */  lw    $t8, 0x88($sp)
/* 0FCCE0 7F0C81B0 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0FCCE4 7F0C81B4 03C02025 */  move  $a0, $fp
/* 0FCCE8 7F0C81B8 03388021 */  addu  $s0, $t9, $t8
/* 0FCCEC 7F0C81BC 02003825 */  move  $a3, $s0
/* 0FCCF0 7F0C81C0 02C02825 */  move  $a1, $s6
/* 0FCCF4 7F0C81C4 02E03025 */  move  $a2, $s7
/* 0FCCF8 7F0C81C8 0FC32769 */  jal   generate_link_final_image
/* 0FCCFC 7F0C81CC AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FCD00 7F0C81D0 100000E2 */  b     .L7F0C855C
/* 0FCD04 7F0C81D4 00408825 */   move  $s1, $v0
huffman_type4:
/* 0FCD08 7F0C81D8 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCD0C 7F0C81DC 3C0B8005 */  lui   $t3, %hi(pixelbytecounts)
/* 0FCD10 7F0C81E0 03C02025 */  move  $a0, $fp
/* 0FCD14 7F0C81E4 00147080 */  sll   $t6, $s4, 2
/* 0FCD18 7F0C81E8 016E5821 */  addu  $t3, $t3, $t6
/* 0FCD1C 7F0C81EC 8D6B9178 */  lw    $t3, %lo(pixelbytecounts)($t3)
/* 0FCD20 7F0C81F0 01C0A025 */  move  $s4, $t6
/* 0FCD24 7F0C81F4 01760019 */  multu $t3, $s6
/* 0FCD28 7F0C81F8 00007812 */  mflo  $t7
/* 0FCD2C 7F0C81FC 00000000 */  nop   
/* 0FCD30 7F0C8200 00000000 */  nop   
/* 0FCD34 7F0C8204 01F70019 */  multu $t7, $s7
/* 0FCD38 7F0C8208 00002812 */  mflo  $a1
/* 0FCD3C 7F0C820C 0FC325AF */  jal   type4_7_9_getsamples
/* 0FCD40 7F0C8210 00000000 */   nop   
/* 0FCD44 7F0C8214 3C0C8005 */  lui   $t4, %hi(pixelbytecounts+52)
/* 0FCD48 7F0C8218 01946021 */  addu  $t4, $t4, $s4
/* 0FCD4C 7F0C821C 8D8C91AC */  lw    $t4, %lo(pixelbytecounts+52)($t4)
/* 0FCD50 7F0C8220 0015C880 */  sll   $t9, $s5, 2
/* 0FCD54 7F0C8224 0335C823 */  subu  $t9, $t9, $s5
/* 0FCD58 7F0C8228 11800003 */  beqz  $t4, .L7F0C8238
/* 0FCD5C 7F0C822C 03D92021 */   addu  $a0, $fp, $t9
/* 0FCD60 7F0C8230 0FC32692 */  jal   image_get_alpha_values
/* 0FCD64 7F0C8234 02A02825 */   move  $a1, $s5
.L7F0C8238:
/* 0FCD68 7F0C8238 8FB830AC */  lw    $t8, 0x30ac($sp)
/* 0FCD6C 7F0C823C 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FCD70 7F0C8240 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0FCD74 7F0C8244 03C02025 */  move  $a0, $fp
/* 0FCD78 7F0C8248 030D8021 */  addu  $s0, $t8, $t5
/* 0FCD7C 7F0C824C 02003825 */  move  $a3, $s0
/* 0FCD80 7F0C8250 02C02825 */  move  $a1, $s6
/* 0FCD84 7F0C8254 02E03025 */  move  $a2, $s7
/* 0FCD88 7F0C8258 0FC32769 */  jal   generate_link_final_image
/* 0FCD8C 7F0C825C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FCD90 7F0C8260 100000BE */  b     .L7F0C855C
/* 0FCD94 7F0C8264 00408825 */   move  $s1, $v0
huffman_type5:
/* 0FCD98 7F0C8268 8FAB0080 */  lw    $t3, 0x80($sp)
/* 0FCD9C 7F0C826C 3C058005 */  lui   $a1, %hi(pixelsamplebits+52)
/* 0FCDA0 7F0C8270 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCDA4 7F0C8274 000B7880 */  sll   $t7, $t3, 2
/* 0FCDA8 7F0C8278 00AF2821 */  addu  $a1, $a1, $t7
/* 0FCDAC 7F0C827C 0FC32648 */  jal   type5_6_7_getsamples
/* 0FCDB0 7F0C8280 8CA59214 */   lw    $a1, %lo(pixelsamplebits+52)($a1)
/* 0FCDB4 7F0C8284 8FAC30AC */  lw    $t4, 0x30ac($sp)
/* 0FCDB8 7F0C8288 8FB90088 */  lw    $t9, 0x88($sp)
/* 0FCDBC 7F0C828C 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FCDC0 7F0C8290 02C02025 */  move  $a0, $s6
/* 0FCDC4 7F0C8294 01998021 */  addu  $s0, $t4, $t9
/* 0FCDC8 7F0C8298 02003025 */  move  $a2, $s0
/* 0FCDCC 7F0C829C 02E02825 */  move  $a1, $s7
/* 0FCDD0 7F0C82A0 27A700A8 */  addiu $a3, $sp, 0xa8
/* 0FCDD4 7F0C82A4 AFA20010 */  sw    $v0, 0x10($sp)
/* 0FCDD8 7F0C82A8 0FC32A24 */  jal   type5_generate_link_final_image
/* 0FCDDC 7F0C82AC AFB80014 */   sw    $t8, 0x14($sp)
/* 0FCDE0 7F0C82B0 100000AA */  b     .L7F0C855C
/* 0FCDE4 7F0C82B4 00408825 */   move  $s1, $v0
huffman_type6:
/* 0FCDE8 7F0C82B8 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0FCDEC 7F0C82BC 3C058005 */  lui   $a1, %hi(pixelsamplebits+52)
/* 0FCDF0 7F0C82C0 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCDF4 7F0C82C4 000D7080 */  sll   $t6, $t5, 2
/* 0FCDF8 7F0C82C8 00AE2821 */  addu  $a1, $a1, $t6
/* 0FCDFC 7F0C82CC 0FC32648 */  jal   type5_6_7_getsamples
/* 0FCE00 7F0C82D0 8CA59214 */   lw    $a1, %lo(pixelsamplebits+52)($a1)
/* 0FCE04 7F0C82D4 00408825 */  move  $s1, $v0
/* 0FCE08 7F0C82D8 03C02025 */  move  $a0, $fp
/* 0FCE0C 7F0C82DC 02A02825 */  move  $a1, $s5
/* 0FCE10 7F0C82E0 0FC32474 */  jal   generate_sample_table
/* 0FCE14 7F0C82E4 00403025 */   move  $a2, $v0
/* 0FCE18 7F0C82E8 8FAB30AC */  lw    $t3, 0x30ac($sp)
/* 0FCE1C 7F0C82EC 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0FCE20 7F0C82F0 8FB90080 */  lw    $t9, 0x80($sp)
/* 0FCE24 7F0C82F4 27AC00A8 */  addiu $t4, $sp, 0xa8
/* 0FCE28 7F0C82F8 016F8021 */  addu  $s0, $t3, $t7
/* 0FCE2C 7F0C82FC 02003825 */  move  $a3, $s0
/* 0FCE30 7F0C8300 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0FCE34 7F0C8304 03C02025 */  move  $a0, $fp
/* 0FCE38 7F0C8308 02C02825 */  move  $a1, $s6
/* 0FCE3C 7F0C830C 02E03025 */  move  $a2, $s7
/* 0FCE40 7F0C8310 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FCE44 7F0C8314 0FC32B16 */  jal   type6_7_generate_link_final_image
/* 0FCE48 7F0C8318 AFB90018 */   sw    $t9, 0x18($sp)
/* 0FCE4C 7F0C831C 1000008F */  b     .L7F0C855C
/* 0FCE50 7F0C8320 00408825 */   move  $s1, $v0
huffman_type7:
/* 0FCE54 7F0C8324 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FCE58 7F0C8328 3C058005 */  lui   $a1, %hi(pixelsamplebits+52)
/* 0FCE5C 7F0C832C 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCE60 7F0C8330 00186880 */  sll   $t5, $t8, 2
/* 0FCE64 7F0C8334 00AD2821 */  addu  $a1, $a1, $t5
/* 0FCE68 7F0C8338 0FC32648 */  jal   type5_6_7_getsamples
/* 0FCE6C 7F0C833C 8CA59214 */   lw    $a1, %lo(pixelsamplebits+52)($a1)
/* 0FCE70 7F0C8340 00408825 */  move  $s1, $v0
/* 0FCE74 7F0C8344 03C02025 */  move  $a0, $fp
/* 0FCE78 7F0C8348 0FC325AF */  jal   type4_7_9_getsamples
/* 0FCE7C 7F0C834C 02A02825 */   move  $a1, $s5
/* 0FCE80 7F0C8350 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCE84 7F0C8354 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCE88 7F0C8358 8FAC0080 */  lw    $t4, 0x80($sp)
/* 0FCE8C 7F0C835C 27AF00A8 */  addiu $t7, $sp, 0xa8
/* 0FCE90 7F0C8360 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCE94 7F0C8364 02003825 */  move  $a3, $s0
/* 0FCE98 7F0C8368 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FCE9C 7F0C836C 03C02025 */  move  $a0, $fp
/* 0FCEA0 7F0C8370 02C02825 */  move  $a1, $s6
/* 0FCEA4 7F0C8374 02E03025 */  move  $a2, $s7
/* 0FCEA8 7F0C8378 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FCEAC 7F0C837C 0FC32B16 */  jal   type6_7_generate_link_final_image
/* 0FCEB0 7F0C8380 AFAC0018 */   sw    $t4, 0x18($sp)
/* 0FCEB4 7F0C8384 10000075 */  b     .L7F0C855C
/* 0FCEB8 7F0C8388 00408825 */   move  $s1, $v0
huffman_type8:
/* 0FCEBC 7F0C838C 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCEC0 7F0C8390 24040003 */  li    $a0, 3
/* 0FCEC4 7F0C8394 0014C880 */  sll   $t9, $s4, 2
/* 0FCEC8 7F0C8398 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCECC 7F0C839C 0320A025 */   move  $s4, $t9
/* 0FCED0 7F0C83A0 3C188005 */  lui   $t8, %hi(pixelbytecounts) 
/* 0FCED4 7F0C83A4 27189178 */  addiu $t8, %lo(pixelbytecounts) # addiu $t8, $t8, -0x6e88
/* 0FCED8 7F0C83A8 02989821 */  addu  $s3, $s4, $t8
/* 0FCEDC 7F0C83AC 8E6D0000 */  lw    $t5, ($s3)
/* 0FCEE0 7F0C83B0 3C0B8005 */  lui   $t3, %hi(pixelsamplebits) 
/* 0FCEE4 7F0C83B4 256B91E0 */  addiu $t3, %lo(pixelsamplebits) # addiu $t3, $t3, -0x6e20
/* 0FCEE8 7F0C83B8 01B60019 */  multu $t5, $s6
/* 0FCEEC 7F0C83BC 028B9021 */  addu  $s2, $s4, $t3
/* 0FCEF0 7F0C83C0 00408025 */  move  $s0, $v0
/* 0FCEF4 7F0C83C4 8E460000 */  lw    $a2, ($s2)
/* 0FCEF8 7F0C83C8 03C02025 */  move  $a0, $fp
/* 0FCEFC 7F0C83CC 00007012 */  mflo  $t6
/* 0FCF00 7F0C83D0 00000000 */  nop   
/* 0FCF04 7F0C83D4 00000000 */  nop   
/* 0FCF08 7F0C83D8 01D70019 */  multu $t6, $s7
/* 0FCF0C 7F0C83DC 00002812 */  mflo  $a1
/* 0FCF10 7F0C83E0 0FC32474 */  jal   generate_sample_table
/* 0FCF14 7F0C83E4 00000000 */   nop   
/* 0FCF18 7F0C83E8 8E6F0000 */  lw    $t7, ($s3)
/* 0FCF1C 7F0C83EC 8E4C0000 */  lw    $t4, ($s2)
/* 0FCF20 7F0C83F0 03C02025 */  move  $a0, $fp
/* 0FCF24 7F0C83F4 01F70019 */  multu $t7, $s7
/* 0FCF28 7F0C83F8 02C02825 */  move  $a1, $s6
/* 0FCF2C 7F0C83FC 02003825 */  move  $a3, $s0
/* 0FCF30 7F0C8400 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0FCF34 7F0C8404 00003012 */  mflo  $a2
/* 0FCF38 7F0C8408 0FC32DF8 */  jal   type8_9_doohick
/* 0FCF3C 7F0C840C 00000000 */   nop   
/* 0FCF40 7F0C8410 3C198005 */  lui   $t9, %hi(pixelbytecounts+52)
/* 0FCF44 7F0C8414 0334C821 */  addu  $t9, $t9, $s4
/* 0FCF48 7F0C8418 8F3991AC */  lw    $t9, %lo(pixelbytecounts+52)($t9)
/* 0FCF4C 7F0C841C 0015C080 */  sll   $t8, $s5, 2
/* 0FCF50 7F0C8420 0315C023 */  subu  $t8, $t8, $s5
/* 0FCF54 7F0C8424 13200003 */  beqz  $t9, .L7F0C8434
/* 0FCF58 7F0C8428 03D82021 */   addu  $a0, $fp, $t8
/* 0FCF5C 7F0C842C 0FC32692 */  jal   image_get_alpha_values
/* 0FCF60 7F0C8430 02A02825 */   move  $a1, $s5
.L7F0C8434:
/* 0FCF64 7F0C8434 8FAD30AC */  lw    $t5, 0x30ac($sp)
/* 0FCF68 7F0C8438 8FAE0088 */  lw    $t6, 0x88($sp)
/* 0FCF6C 7F0C843C 8FAB0080 */  lw    $t3, 0x80($sp)
/* 0FCF70 7F0C8440 03C02025 */  move  $a0, $fp
/* 0FCF74 7F0C8444 01AE8021 */  addu  $s0, $t5, $t6
/* 0FCF78 7F0C8448 02003825 */  move  $a3, $s0
/* 0FCF7C 7F0C844C 02C02825 */  move  $a1, $s6
/* 0FCF80 7F0C8450 02E03025 */  move  $a2, $s7
/* 0FCF84 7F0C8454 0FC32769 */  jal   generate_link_final_image
/* 0FCF88 7F0C8458 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FCF8C 7F0C845C 1000003F */  b     .L7F0C855C
/* 0FCF90 7F0C8460 00408825 */   move  $s1, $v0
huffman_type9:
/* 0FCF94 7F0C8464 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCF98 7F0C8468 24040003 */  li    $a0, 3
/* 0FCF9C 7F0C846C 00147880 */  sll   $t7, $s4, 2
/* 0FCFA0 7F0C8470 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FCFA4 7F0C8474 01E0A025 */   move  $s4, $t7
/* 0FCFA8 7F0C8478 3C0C8005 */  lui   $t4, %hi(pixelbytecounts) 
/* 0FCFAC 7F0C847C 258C9178 */  addiu $t4, %lo(pixelbytecounts) # addiu $t4, $t4, -0x6e88
/* 0FCFB0 7F0C8480 028C9821 */  addu  $s3, $s4, $t4
/* 0FCFB4 7F0C8484 8E790000 */  lw    $t9, ($s3)
/* 0FCFB8 7F0C8488 00408025 */  move  $s0, $v0
/* 0FCFBC 7F0C848C 03C02025 */  move  $a0, $fp
/* 0FCFC0 7F0C8490 03360019 */  multu $t9, $s6
/* 0FCFC4 7F0C8494 0000C012 */  mflo  $t8
/* 0FCFC8 7F0C8498 00000000 */  nop   
/* 0FCFCC 7F0C849C 00000000 */  nop   
/* 0FCFD0 7F0C84A0 03170019 */  multu $t8, $s7
/* 0FCFD4 7F0C84A4 00002812 */  mflo  $a1
/* 0FCFD8 7F0C84A8 0FC325AF */  jal   type4_7_9_getsamples
/* 0FCFDC 7F0C84AC 00000000 */   nop   
/* 0FCFE0 7F0C84B0 8E6D0000 */  lw    $t5, ($s3)
/* 0FCFE4 7F0C84B4 3C0E8005 */  lui   $t6, %hi(pixelsamplebits)
/* 0FCFE8 7F0C84B8 01D47021 */  addu  $t6, $t6, $s4
/* 0FCFEC 7F0C84BC 01B70019 */  multu $t5, $s7
/* 0FCFF0 7F0C84C0 8DCE91E0 */  lw    $t6, %lo(pixelsamplebits)($t6)
/* 0FCFF4 7F0C84C4 03C02025 */  move  $a0, $fp
/* 0FCFF8 7F0C84C8 02C02825 */  move  $a1, $s6
/* 0FCFFC 7F0C84CC 02003825 */  move  $a3, $s0
/* 0FD000 7F0C84D0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0FD004 7F0C84D4 00003012 */  mflo  $a2
/* 0FD008 7F0C84D8 0FC32DF8 */  jal   type8_9_doohick
/* 0FD00C 7F0C84DC 00000000 */   nop   
/* 0FD010 7F0C84E0 3C0B8005 */  lui   $t3, %hi(pixelbytecounts+52)
/* 0FD014 7F0C84E4 01745821 */  addu  $t3, $t3, $s4
/* 0FD018 7F0C84E8 8D6B91AC */  lw    $t3, %lo(pixelbytecounts+52)($t3)
/* 0FD01C 7F0C84EC 00157880 */  sll   $t7, $s5, 2
/* 0FD020 7F0C84F0 01F57823 */  subu  $t7, $t7, $s5
/* 0FD024 7F0C84F4 11600003 */  beqz  $t3, .L7F0C8504
/* 0FD028 7F0C84F8 03CF2021 */   addu  $a0, $fp, $t7
/* 0FD02C 7F0C84FC 0FC32692 */  jal   image_get_alpha_values
/* 0FD030 7F0C8500 02A02825 */   move  $a1, $s5
.L7F0C8504:
/* 0FD034 7F0C8504 8FAC30AC */  lw    $t4, 0x30ac($sp)
/* 0FD038 7F0C8508 8FB90088 */  lw    $t9, 0x88($sp)
/* 0FD03C 7F0C850C 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FD040 7F0C8510 03C02025 */  move  $a0, $fp
/* 0FD044 7F0C8514 01998021 */  addu  $s0, $t4, $t9
/* 0FD048 7F0C8518 02003825 */  move  $a3, $s0
/* 0FD04C 7F0C851C 02C02825 */  move  $a1, $s6
/* 0FD050 7F0C8520 02E03025 */  move  $a2, $s7
/* 0FD054 7F0C8524 0FC32769 */  jal   generate_link_final_image
/* 0FD058 7F0C8528 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FD05C 7F0C852C 1000000B */  b     .L7F0C855C
/* 0FD060 7F0C8530 00408825 */   move  $s1, $v0
def_7F0C8054:
.L7F0C8534:
/* 0FD064 7F0C8534 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008D090) 
/* 0FD068 7F0C8538 8DADD090 */  lw    $t5, %lo(dword_CODE_bss_8008D090)($t5)
/* 0FD06C 7F0C853C 3C0F8009 */  lui   $t7, %hi(word_CODE_bss_8008C730) 
/* 0FD070 7F0C8540 25EFC730 */  addiu $t7, %lo(word_CODE_bss_8008C730) # addiu $t7, $t7, -0x38d0
/* 0FD074 7F0C8544 000D7100 */  sll   $t6, $t5, 4
/* 0FD078 7F0C8548 01CF1821 */  addu  $v1, $t6, $t7
/* 0FD07C 7F0C854C A0760001 */  sb    $s6, 1($v1)
/* 0FD080 7F0C8550 A0770008 */  sb    $s7, 8($v1)
.L7F0C8554:
/* 0FD084 7F0C8554 1000FFFF */  b     .L7F0C8554
/* 0FD088 7F0C8558 00000000 */   nop   
.L7F0C855C:
/* 0FD08C 7F0C855C 8FAC30B0 */  lw    $t4, 0x30b0($sp)
/* 0FD090 7F0C8560 24010001 */  li    $at, 1
/* 0FD094 7F0C8564 8FB930B4 */  lw    $t9, 0x30b4($sp)
/* 0FD098 7F0C8568 15810007 */  bne   $t4, $at, .L7F0C8588
/* 0FD09C 7F0C856C 00000000 */   nop   
/* 0FD0A0 7F0C8570 1B200005 */  blez  $t9, .L7F0C8588
/* 0FD0A4 7F0C8574 02002025 */   move  $a0, $s0
/* 0FD0A8 7F0C8578 02C02825 */  move  $a1, $s6
/* 0FD0AC 7F0C857C 02E03025 */  move  $a2, $s7
/* 0FD0B0 7F0C8580 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FD0B4 7F0C8584 8FA70080 */   lw    $a3, 0x80($sp)
.L7F0C8588:
/* 0FD0B8 7F0C8588 3C028009 */  lui   $v0, %hi(img_bitcount)
/* 0FD0BC 7F0C858C 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FD0C0 7F0C8590 2442D0A8 */  addiu $v0, %lo(img_bitcount) # addiu $v0, $v0, -0x2f58
/* 0FD0C4 7F0C8594 8C4B0000 */  lw    $t3, ($v0)
/* 0FD0C8 7F0C8598 26310007 */  addiu $s1, $s1, 7
/* 0FD0CC 7F0C859C 2401FFF8 */  li    $at, -8
/* 0FD0D0 7F0C85A0 0221C024 */  and   $t8, $s1, $at
/* 0FD0D4 7F0C85A4 01B87021 */  addu  $t6, $t5, $t8
/* 0FD0D8 7F0C85A8 15600007 */  bnez  $t3, .L7F0C85C8
/* 0FD0DC 7F0C85AC AFAE0088 */   sw    $t6, 0x88($sp)
/* 0FD0E0 7F0C85B0 3C0F8009 */  lui   $t7, %hi(img_curpos) 
/* 0FD0E4 7F0C85B4 8DEFD0A0 */  lw    $t7, %lo(img_curpos)($t7)
/* 0FD0E8 7F0C85B8 3C018009 */  lui   $at, %hi(img_curpos)
/* 0FD0EC 7F0C85BC 25EC0001 */  addiu $t4, $t7, 1
/* 0FD0F0 7F0C85C0 10000002 */  b     .L7F0C85CC
/* 0FD0F4 7F0C85C4 AC2CD0A0 */   sw    $t4, %lo(img_curpos)($at)
.L7F0C85C8:
/* 0FD0F8 7F0C85C8 AC400000 */  sw    $zero, ($v0)
.L7F0C85CC:
/* 0FD0FC 7F0C85CC 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0FD100 7F0C85D0 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0FD104 7F0C85D4 27380001 */  addiu $t8, $t9, 1
/* 0FD108 7F0C85D8 170DFE52 */  bne   $t8, $t5, .L7F0C7F24
/* 0FD10C 7F0C85DC AFB800A0 */   sw    $t8, 0xa0($sp)
/* 0FD110 7F0C85E0 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FD114 7F0C85E4 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FD118 7F0C85E8 AFB60098 */  sw    $s6, 0x98($sp)
/* 0FD11C 7F0C85EC AFB70094 */  sw    $s7, 0x94($sp)
/* 0FD120 7F0C85F0 8FAA30B4 */  lw    $t2, 0x30b4($sp)
/* 0FD124 7F0C85F4 8FA930B0 */  lw    $t1, 0x30b0($sp)
/* 0FD128 7F0C85F8 8FA730B8 */  lw    $a3, 0x30b8($sp)
/* 0FD12C 7F0C85FC 8FA60070 */  lw    $a2, 0x70($sp)
.L7F0C8600:
/* 0FD130 7F0C8600 8FB60098 */  lw    $s6, 0x98($sp)
/* 0FD134 7F0C8604 10C0000E */  beqz  $a2, .L7F0C8640
/* 0FD138 7F0C8608 8FB70094 */   lw    $s7, 0x94($sp)
/* 0FD13C 7F0C860C 8CEE000C */  lw    $t6, 0xc($a3)
/* 0FD140 7F0C8610 8D050000 */  lw    $a1, ($t0)
/* 0FD144 7F0C8614 3C018009 */  lui   $at, %hi(word_CODE_bss_8008C730)
/* 0FD148 7F0C8618 8DCB0000 */  lw    $t3, ($t6)
/* 0FD14C 7F0C861C 00056100 */  sll   $t4, $a1, 4
/* 0FD150 7F0C8620 002C0821 */  addu  $at, $at, $t4
/* 0FD154 7F0C8624 000B7D02 */  srl   $t7, $t3, 0x14
/* 0FD158 7F0C8628 A42FC730 */  sh    $t7, %lo(word_CODE_bss_8008C730)($at)
/* 0FD15C 7F0C862C 24B90001 */  addiu $t9, $a1, 1
/* 0FD160 7F0C8630 2B210096 */  slti  $at, $t9, 0x96
/* 0FD164 7F0C8634 14200002 */  bnez  $at, .L7F0C8640
/* 0FD168 7F0C8638 AD190000 */   sw    $t9, ($t0)
/* 0FD16C 7F0C863C AD000000 */  sw    $zero, ($t0)
.L7F0C8640:
/* 0FD170 7F0C8640 15200037 */  bnez  $t1, .L7F0C8720
/* 0FD174 7F0C8644 29410002 */   slti  $at, $t2, 2
/* 0FD178 7F0C8648 1420002E */  bnez  $at, .L7F0C8704
/* 0FD17C 7F0C864C 8FB430AC */   lw    $s4, 0x30ac($sp)
/* 0FD180 7F0C8650 8FAB30B4 */  lw    $t3, 0x30b4($sp)
/* 0FD184 7F0C8654 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FD188 7F0C8658 240E0001 */  li    $t6, 1
/* 0FD18C 7F0C865C 29610002 */  slti  $at, $t3, 2
/* 0FD190 7F0C8660 02C09025 */  move  $s2, $s6
/* 0FD194 7F0C8664 02E09825 */  move  $s3, $s7
/* 0FD198 7F0C8668 AFAE00A0 */  sw    $t6, 0xa0($sp)
/* 0FD19C 7F0C866C 1420001E */  bnez  $at, .L7F0C86E8
/* 0FD1A0 7F0C8670 028D8021 */   addu  $s0, $s4, $t5
.L7F0C8674:
/* 0FD1A4 7F0C8674 8FAF0080 */  lw    $t7, 0x80($sp)
/* 0FD1A8 7F0C8678 02802025 */  move  $a0, $s4
/* 0FD1AC 7F0C867C 02002825 */  move  $a1, $s0
/* 0FD1B0 7F0C8680 02403025 */  move  $a2, $s2
/* 0FD1B4 7F0C8684 02603825 */  move  $a3, $s3
/* 0FD1B8 7F0C8688 0FC321D5 */  jal   image_decompresion_related
/* 0FD1BC 7F0C868C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FD1C0 7F0C8690 00408825 */  move  $s1, $v0
/* 0FD1C4 7F0C8694 02802025 */  move  $a0, $s4
/* 0FD1C8 7F0C8698 02402825 */  move  $a1, $s2
/* 0FD1CC 7F0C869C 02603025 */  move  $a2, $s3
/* 0FD1D0 7F0C86A0 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FD1D4 7F0C86A4 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FD1D8 7F0C86A8 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0FD1DC 7F0C86AC 8FAC0088 */  lw    $t4, 0x88($sp)
/* 0FD1E0 7F0C86B0 8FAF30B4 */  lw    $t7, 0x30b4($sp)
/* 0FD1E4 7F0C86B4 26520001 */  addiu $s2, $s2, 1
/* 0FD1E8 7F0C86B8 26730001 */  addiu $s3, $s3, 1
/* 0FD1EC 7F0C86BC 0012C043 */  sra   $t8, $s2, 1
/* 0FD1F0 7F0C86C0 00136843 */  sra   $t5, $s3, 1
/* 0FD1F4 7F0C86C4 0200A025 */  move  $s4, $s0
/* 0FD1F8 7F0C86C8 25CB0001 */  addiu $t3, $t6, 1
/* 0FD1FC 7F0C86CC 0191C821 */  addu  $t9, $t4, $s1
/* 0FD200 7F0C86D0 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FD204 7F0C86D4 AFB90088 */  sw    $t9, 0x88($sp)
/* 0FD208 7F0C86D8 03009025 */  move  $s2, $t8
/* 0FD20C 7F0C86DC 01A09825 */  move  $s3, $t5
/* 0FD210 7F0C86E0 156FFFE4 */  bne   $t3, $t7, .L7F0C8674
/* 0FD214 7F0C86E4 02118021 */   addu  $s0, $s0, $s1
.L7F0C86E8:
/* 0FD218 7F0C86E8 02802025 */  move  $a0, $s4
/* 0FD21C 7F0C86EC 02402825 */  move  $a1, $s2
/* 0FD220 7F0C86F0 02603025 */  move  $a2, $s3
/* 0FD224 7F0C86F4 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FD228 7F0C86F8 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FD22C 7F0C86FC 10000009 */  b     .L7F0C8724
/* 0FD230 7F0C8700 8FA20088 */   lw    $v0, 0x88($sp)
.L7F0C8704:
/* 0FD234 7F0C8704 24010001 */  li    $at, 1
/* 0FD238 7F0C8708 15410005 */  bne   $t2, $at, .L7F0C8720
/* 0FD23C 7F0C870C 8FA430AC */   lw    $a0, 0x30ac($sp)
/* 0FD240 7F0C8710 02C02825 */  move  $a1, $s6
/* 0FD244 7F0C8714 02E03025 */  move  $a2, $s7
/* 0FD248 7F0C8718 0FC32D9F */  jal   sub_GAME_7F0CB67C
/* 0FD24C 7F0C871C 8FA70080 */   lw    $a3, 0x80($sp)
.L7F0C8720:
/* 0FD250 7F0C8720 8FA20088 */  lw    $v0, 0x88($sp)
.L7F0C8724:
/* 0FD254 7F0C8724 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0FD258 7F0C8728 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FD25C 7F0C872C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FD260 7F0C8730 8FB20030 */  lw    $s2, 0x30($sp)
/* 0FD264 7F0C8734 8FB30034 */  lw    $s3, 0x34($sp)
/* 0FD268 7F0C8738 8FB40038 */  lw    $s4, 0x38($sp)
/* 0FD26C 7F0C873C 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0FD270 7F0C8740 8FB60040 */  lw    $s6, 0x40($sp)
/* 0FD274 7F0C8744 8FB70044 */  lw    $s7, 0x44($sp)
/* 0FD278 7F0C8748 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0FD27C 7F0C874C 03E00008 */  jr    $ra
/* 0FD280 7F0C8750 27BD30A8 */   addiu $sp, $sp, 0x30a8
)
#endif





#ifdef NONMATCHING
void image_decompresion_related(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BD58*/
glabel jpt_8005BD58
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87F0
.word .L7F0C8814
.word .L7F0C8838
.word .L7F0C8814
.word .L7F0C8838

/*D:8005BD7C*/
glabel jpt_8005BD7C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C8BE0
.word .L7F0C8D1C
.word .L7F0C8F00
.word .L7F0C8E34
.word .L7F0C9090
.text
glabel image_decompresion_related
/* 0FD284 7F0C8754 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0FD288 7F0C8758 8FA200C8 */  lw    $v0, 0xc8($sp)
/* 0FD28C 7F0C875C 24F90001 */  addiu $t9, $a3, 1
/* 0FD290 7F0C8760 AFB70020 */  sw    $s7, 0x20($sp)
/* 0FD294 7F0C8764 AFB6001C */  sw    $s6, 0x1c($sp)
/* 0FD298 7F0C8768 AFB50018 */  sw    $s5, 0x18($sp)
/* 0FD29C 7F0C876C AFB40014 */  sw    $s4, 0x14($sp)
/* 0FD2A0 7F0C8770 AFB10008 */  sw    $s1, 8($sp)
/* 0FD2A4 7F0C8774 AFB00004 */  sw    $s0, 4($sp)
/* 0FD2A8 7F0C8778 00196043 */  sra   $t4, $t9, 1
/* 0FD2AC 7F0C877C 2C410009 */  sltiu $at, $v0, 9
/* 0FD2B0 7F0C8780 00C0A825 */  move  $s5, $a2
/* 0FD2B4 7F0C8784 00E0B825 */  move  $s7, $a3
/* 0FD2B8 7F0C8788 AFBE0024 */  sw    $fp, 0x24($sp)
/* 0FD2BC 7F0C878C AFB30010 */  sw    $s3, 0x10($sp)
/* 0FD2C0 7F0C8790 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FD2C4 7F0C8794 00A04825 */  move  $t1, $a1
/* 0FD2C8 7F0C8798 00A0B025 */  move  $s6, $a1
/* 0FD2CC 7F0C879C 00A08825 */  move  $s1, $a1
/* 0FD2D0 7F0C87A0 00801825 */  move  $v1, $a0
/* 0FD2D4 7F0C87A4 0080A025 */  move  $s4, $a0
/* 0FD2D8 7F0C87A8 00808025 */  move  $s0, $a0
/* 0FD2DC 7F0C87AC 1020002A */  beqz  $at, .L7F0C8858
/* 0FD2E0 7F0C87B0 AFAC004C */   sw    $t4, 0x4c($sp)
/* 0FD2E4 7F0C87B4 0002C080 */  sll   $t8, $v0, 2
/* 0FD2E8 7F0C87B8 3C018006 */  lui   $at, %hi(jpt_8005BD58)
/* 0FD2EC 7F0C87BC 00380821 */  addu  $at, $at, $t8
/* 0FD2F0 7F0C87C0 8C38BD58 */  lw    $t8, %lo(jpt_8005BD58)($at)
/* 0FD2F4 7F0C87C4 03000008 */  jr    $t8
/* 0FD2F8 7F0C87C8 00000000 */   nop   
.L7F0C87CC:
/* 0FD2FC 7F0C87CC 26AE0001 */  addiu $t6, $s5, 1
/* 0FD300 7F0C87D0 000EC843 */  sra   $t9, $t6, 1
/* 0FD304 7F0C87D4 272F0003 */  addiu $t7, $t9, 3
/* 0FD308 7F0C87D8 26B20003 */  addiu $s2, $s5, 3
/* 0FD30C 7F0C87DC 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FD310 7F0C87E0 324E0FFC */  andi  $t6, $s2, 0xffc
/* 0FD314 7F0C87E4 AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0FD318 7F0C87E8 1000001B */  b     .L7F0C8858
/* 0FD31C 7F0C87EC AFAE00AC */   sw    $t6, 0xac($sp)
.L7F0C87F0:
/* 0FD320 7F0C87F0 26B90001 */  addiu $t9, $s5, 1
/* 0FD324 7F0C87F4 00197843 */  sra   $t7, $t9, 1
/* 0FD328 7F0C87F8 25F80003 */  addiu $t8, $t7, 3
/* 0FD32C 7F0C87FC 26B20003 */  addiu $s2, $s5, 3
/* 0FD330 7F0C8800 330E0FFC */  andi  $t6, $t8, 0xffc
/* 0FD334 7F0C8804 32590FFC */  andi  $t9, $s2, 0xffc
/* 0FD338 7F0C8808 AFAE00A8 */  sw    $t6, 0xa8($sp)
/* 0FD33C 7F0C880C 10000012 */  b     .L7F0C8858
/* 0FD340 7F0C8810 AFB900AC */   sw    $t9, 0xac($sp)
.L7F0C8814:
/* 0FD344 7F0C8814 26AF0001 */  addiu $t7, $s5, 1
/* 0FD348 7F0C8818 000FC043 */  sra   $t8, $t7, 1
/* 0FD34C 7F0C881C 270E0007 */  addiu $t6, $t8, 7
/* 0FD350 7F0C8820 26B20007 */  addiu $s2, $s5, 7
/* 0FD354 7F0C8824 31D90FF8 */  andi  $t9, $t6, 0xff8
/* 0FD358 7F0C8828 324F0FF8 */  andi  $t7, $s2, 0xff8
/* 0FD35C 7F0C882C AFB900A8 */  sw    $t9, 0xa8($sp)
/* 0FD360 7F0C8830 10000009 */  b     .L7F0C8858
/* 0FD364 7F0C8834 AFAF00AC */   sw    $t7, 0xac($sp)
.L7F0C8838:
/* 0FD368 7F0C8838 26B80001 */  addiu $t8, $s5, 1
/* 0FD36C 7F0C883C 00187043 */  sra   $t6, $t8, 1
/* 0FD370 7F0C8840 25D9000F */  addiu $t9, $t6, 0xf
/* 0FD374 7F0C8844 26B2000F */  addiu $s2, $s5, 0xf
/* 0FD378 7F0C8848 332F0FF0 */  andi  $t7, $t9, 0xff0
/* 0FD37C 7F0C884C 32580FF0 */  andi  $t8, $s2, 0xff0
/* 0FD380 7F0C8850 AFAF00A8 */  sw    $t7, 0xa8($sp)
/* 0FD384 7F0C8854 AFB800AC */  sw    $t8, 0xac($sp)
def_7F0C87C4:
.L7F0C8858:
/* 0FD388 7F0C8858 2C410009 */  sltiu $at, $v0, 9
/* 0FD38C 7F0C885C 10200250 */  beqz  $at, .L7F0C91A0
/* 0FD390 7F0C8860 8FB200AC */   lw    $s2, 0xac($sp)
/* 0FD394 7F0C8864 00027080 */  sll   $t6, $v0, 2
/* 0FD398 7F0C8868 3C018006 */  lui   $at, %hi(jpt_8005BD7C)
/* 0FD39C 7F0C886C 002E0821 */  addu  $at, $at, $t6
/* 0FD3A0 7F0C8870 8C2EBD7C */  lw    $t6, %lo(jpt_8005BD7C)($at)
/* 0FD3A4 7F0C8874 01C00008 */  jr    $t6
/* 0FD3A8 7F0C8878 00000000 */   nop   
.L7F0C887C:
/* 0FD3AC 7F0C887C 1AE00064 */  blez  $s7, .L7F0C8A10
/* 0FD3B0 7F0C8880 0000F025 */   move  $fp, $zero
/* 0FD3B4 7F0C8884 8FA400A8 */  lw    $a0, 0xa8($sp)
/* 0FD3B8 7F0C8888 02402825 */  move  $a1, $s2
/* 0FD3BC 7F0C888C 000578C0 */  sll   $t7, $a1, 3
/* 0FD3C0 7F0C8890 0004C880 */  sll   $t9, $a0, 2
/* 0FD3C4 7F0C8894 03202025 */  move  $a0, $t9
/* 0FD3C8 7F0C8898 01E02825 */  move  $a1, $t7
.L7F0C889C:
/* 0FD3CC 7F0C889C 27D80001 */  addiu $t8, $fp, 1
/* 0FD3D0 7F0C88A0 0317082A */  slt   $at, $t8, $s7
/* 0FD3D4 7F0C88A4 10200003 */  beqz  $at, .L7F0C88B4
/* 0FD3D8 7F0C88A8 00004025 */   move  $t0, $zero
/* 0FD3DC 7F0C88AC 10000002 */  b     .L7F0C88B8
/* 0FD3E0 7F0C88B0 02409825 */   move  $s3, $s2
.L7F0C88B4:
/* 0FD3E4 7F0C88B4 00009825 */  move  $s3, $zero
.L7F0C88B8:
/* 0FD3E8 7F0C88B8 1A400051 */  blez  $s2, .L7F0C8A00
/* 0FD3EC 7F0C88BC 27DE0002 */   addiu $fp, $fp, 2
/* 0FD3F0 7F0C88C0 00137080 */  sll   $t6, $s3, 2
/* 0FD3F4 7F0C88C4 006E6821 */  addu  $t5, $v1, $t6
/* 0FD3F8 7F0C88C8 01A08025 */  move  $s0, $t5
/* 0FD3FC 7F0C88CC 00603025 */  move  $a2, $v1
.L7F0C88D0:
/* 0FD400 7F0C88D0 25020001 */  addiu $v0, $t0, 1
/* 0FD404 7F0C88D4 0055082A */  slt   $at, $v0, $s5
/* 0FD408 7F0C88D8 10200003 */  beqz  $at, .L7F0C88E8
/* 0FD40C 7F0C88DC 01003825 */   move  $a3, $t0
/* 0FD410 7F0C88E0 10000001 */  b     .L7F0C88E8
/* 0FD414 7F0C88E4 00403825 */   move  $a3, $v0
.L7F0C88E8:
/* 0FD418 7F0C88E8 00075880 */  sll   $t3, $a3, 2
/* 0FD41C 7F0C88EC 006BC821 */  addu  $t9, $v1, $t3
/* 0FD420 7F0C88F0 8F2A0000 */  lw    $t2, ($t9)
/* 0FD424 7F0C88F4 8CC20000 */  lw    $v0, ($a2)
/* 0FD428 7F0C88F8 01AB7821 */  addu  $t7, $t5, $t3
/* 0FD42C 7F0C88FC 8E0C0000 */  lw    $t4, ($s0)
/* 0FD430 7F0C8900 8DF10000 */  lw    $s1, ($t7)
/* 0FD434 7F0C8904 000ACE02 */  srl   $t9, $t2, 0x18
/* 0FD438 7F0C8908 332F00FF */  andi  $t7, $t9, 0xff
/* 0FD43C 7F0C890C 0002C602 */  srl   $t8, $v0, 0x18
/* 0FD440 7F0C8910 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD444 7F0C8914 01CFC021 */  addu  $t8, $t6, $t7
/* 0FD448 7F0C8918 000CCE02 */  srl   $t9, $t4, 0x18
/* 0FD44C 7F0C891C 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD450 7F0C8920 030E7821 */  addu  $t7, $t8, $t6
/* 0FD454 7F0C8924 0011CE02 */  srl   $t9, $s1, 0x18
/* 0FD458 7F0C8928 333800FF */  andi  $t8, $t9, 0xff
/* 0FD45C 7F0C892C 01F87021 */  addu  $t6, $t7, $t8
/* 0FD460 7F0C8930 000E7882 */  srl   $t7, $t6, 2
/* 0FD464 7F0C8934 000FC600 */  sll   $t8, $t7, 0x18
/* 0FD468 7F0C8938 00027402 */  srl   $t6, $v0, 0x10
/* 0FD46C 7F0C893C 31D900FF */  andi  $t9, $t6, 0xff
/* 0FD470 7F0C8940 000A7C02 */  srl   $t7, $t2, 0x10
/* 0FD474 7F0C8944 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD478 7F0C8948 032E7821 */  addu  $t7, $t9, $t6
/* 0FD47C 7F0C894C 000CCC02 */  srl   $t9, $t4, 0x10
/* 0FD480 7F0C8950 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD484 7F0C8954 01EEC821 */  addu  $t9, $t7, $t6
/* 0FD488 7F0C8958 00117C02 */  srl   $t7, $s1, 0x10
/* 0FD48C 7F0C895C 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD490 7F0C8960 032E7821 */  addu  $t7, $t9, $t6
/* 0FD494 7F0C8964 000FC882 */  srl   $t9, $t7, 2
/* 0FD498 7F0C8968 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD49C 7F0C896C 000E7C00 */  sll   $t7, $t6, 0x10
/* 0FD4A0 7F0C8970 030FC825 */  or    $t9, $t8, $t7
/* 0FD4A4 7F0C8974 00027202 */  srl   $t6, $v0, 8
/* 0FD4A8 7F0C8978 31D800FF */  andi  $t8, $t6, 0xff
/* 0FD4AC 7F0C897C 000A7A02 */  srl   $t7, $t2, 8
/* 0FD4B0 7F0C8980 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD4B4 7F0C8984 030E7821 */  addu  $t7, $t8, $t6
/* 0FD4B8 7F0C8988 000CC202 */  srl   $t8, $t4, 8
/* 0FD4BC 7F0C898C 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD4C0 7F0C8990 01EEC021 */  addu  $t8, $t7, $t6
/* 0FD4C4 7F0C8994 00117A02 */  srl   $t7, $s1, 8
/* 0FD4C8 7F0C8998 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD4CC 7F0C899C 030E7821 */  addu  $t7, $t8, $t6
/* 0FD4D0 7F0C89A0 000FC082 */  srl   $t8, $t7, 2
/* 0FD4D4 7F0C89A4 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD4D8 7F0C89A8 000E7A00 */  sll   $t7, $t6, 8
/* 0FD4DC 7F0C89AC 032FC025 */  or    $t8, $t9, $t7
/* 0FD4E0 7F0C89B0 315900FF */  andi  $t9, $t2, 0xff
/* 0FD4E4 7F0C89B4 304E00FF */  andi  $t6, $v0, 0xff
/* 0FD4E8 7F0C89B8 01D97821 */  addu  $t7, $t6, $t9
/* 0FD4EC 7F0C89BC 318E00FF */  andi  $t6, $t4, 0xff
/* 0FD4F0 7F0C89C0 01EEC821 */  addu  $t9, $t7, $t6
/* 0FD4F4 7F0C89C4 322F00FF */  andi  $t7, $s1, 0xff
/* 0FD4F8 7F0C89C8 032F7021 */  addu  $t6, $t9, $t7
/* 0FD4FC 7F0C89CC 25D90001 */  addiu $t9, $t6, 1
/* 0FD500 7F0C89D0 00197882 */  srl   $t7, $t9, 2
/* 0FD504 7F0C89D4 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD508 7F0C89D8 00087843 */  sra   $t7, $t0, 1
/* 0FD50C 7F0C89DC 030EC825 */  or    $t9, $t8, $t6
/* 0FD510 7F0C89E0 25080002 */  addiu $t0, $t0, 2
/* 0FD514 7F0C89E4 000FC080 */  sll   $t8, $t7, 2
/* 0FD518 7F0C89E8 0112082A */  slt   $at, $t0, $s2
/* 0FD51C 7F0C89EC 01387021 */  addu  $t6, $t1, $t8
/* 0FD520 7F0C89F0 24C60008 */  addiu $a2, $a2, 8
/* 0FD524 7F0C89F4 26100008 */  addiu $s0, $s0, 8
/* 0FD528 7F0C89F8 1420FFB5 */  bnez  $at, .L7F0C88D0
/* 0FD52C 7F0C89FC ADD90000 */   sw    $t9, ($t6)
.L7F0C8A00:
/* 0FD530 7F0C8A00 03D7082A */  slt   $at, $fp, $s7
/* 0FD534 7F0C8A04 01244821 */  addu  $t1, $t1, $a0
/* 0FD538 7F0C8A08 1420FFA4 */  bnez  $at, .L7F0C889C
/* 0FD53C 7F0C8A0C 00651821 */   addu  $v1, $v1, $a1
.L7F0C8A10:
/* 0FD540 7F0C8A10 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0FD544 7F0C8A14 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FD548 7F0C8A18 01F80019 */  multu $t7, $t8
/* 0FD54C 7F0C8A1C 00001012 */  mflo  $v0
/* 0FD550 7F0C8A20 0002C880 */  sll   $t9, $v0, 2
/* 0FD554 7F0C8A24 100001DF */  b     .L7F0C91A4
/* 0FD558 7F0C8A28 03201025 */   move  $v0, $t9
.L7F0C8A2C:
/* 0FD55C 7F0C8A2C 1AE00065 */  blez  $s7, .L7F0C8BC4
/* 0FD560 7F0C8A30 0000F025 */   move  $fp, $zero
/* 0FD564 7F0C8A34 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD568 7F0C8A38 0012C880 */  sll   $t9, $s2, 2
/* 0FD56C 7F0C8A3C AFB90034 */  sw    $t9, 0x34($sp)
/* 0FD570 7F0C8A40 000E7840 */  sll   $t7, $t6, 1
/* 0FD574 7F0C8A44 AFAF0038 */  sw    $t7, 0x38($sp)
.L7F0C8A48:
/* 0FD578 7F0C8A48 27CE0001 */  addiu $t6, $fp, 1
/* 0FD57C 7F0C8A4C 01D7082A */  slt   $at, $t6, $s7
/* 0FD580 7F0C8A50 10200003 */  beqz  $at, .L7F0C8A60
/* 0FD584 7F0C8A54 00004025 */   move  $t0, $zero
/* 0FD588 7F0C8A58 10000002 */  b     .L7F0C8A64
/* 0FD58C 7F0C8A5C 02409825 */   move  $s3, $s2
.L7F0C8A60:
/* 0FD590 7F0C8A60 00009825 */  move  $s3, $zero
.L7F0C8A64:
/* 0FD594 7F0C8A64 1A400051 */  blez  $s2, .L7F0C8BAC
/* 0FD598 7F0C8A68 27DE0002 */   addiu $fp, $fp, 2
/* 0FD59C 7F0C8A6C 00137840 */  sll   $t7, $s3, 1
/* 0FD5A0 7F0C8A70 028F8821 */  addu  $s1, $s4, $t7
/* 0FD5A4 7F0C8A74 02208025 */  move  $s0, $s1
/* 0FD5A8 7F0C8A78 02806825 */  move  $t5, $s4
.L7F0C8A7C:
/* 0FD5AC 7F0C8A7C 25020001 */  addiu $v0, $t0, 1
/* 0FD5B0 7F0C8A80 0055082A */  slt   $at, $v0, $s5
/* 0FD5B4 7F0C8A84 10200003 */  beqz  $at, .L7F0C8A94
/* 0FD5B8 7F0C8A88 01003825 */   move  $a3, $t0
/* 0FD5BC 7F0C8A8C 10000001 */  b     .L7F0C8A94
/* 0FD5C0 7F0C8A90 00403825 */   move  $a3, $v0
.L7F0C8A94:
/* 0FD5C4 7F0C8A94 00073040 */  sll   $a2, $a3, 1
/* 0FD5C8 7F0C8A98 0286C021 */  addu  $t8, $s4, $a2
/* 0FD5CC 7F0C8A9C 970A0000 */  lhu   $t2, ($t8)
/* 0FD5D0 7F0C8AA0 95A90000 */  lhu   $t1, ($t5)
/* 0FD5D4 7F0C8AA4 0226C821 */  addu  $t9, $s1, $a2
/* 0FD5D8 7F0C8AA8 960B0000 */  lhu   $t3, ($s0)
/* 0FD5DC 7F0C8AAC 972C0000 */  lhu   $t4, ($t9)
/* 0FD5E0 7F0C8AB0 000AC2C3 */  sra   $t8, $t2, 0xb
/* 0FD5E4 7F0C8AB4 3319001F */  andi  $t9, $t8, 0x1f
/* 0FD5E8 7F0C8AB8 000972C3 */  sra   $t6, $t1, 0xb
/* 0FD5EC 7F0C8ABC 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD5F0 7F0C8AC0 01F97021 */  addu  $t6, $t7, $t9
/* 0FD5F4 7F0C8AC4 000BC2C3 */  sra   $t8, $t3, 0xb
/* 0FD5F8 7F0C8AC8 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD5FC 7F0C8ACC 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD600 7F0C8AD0 000CC2C3 */  sra   $t8, $t4, 0xb
/* 0FD604 7F0C8AD4 330E001F */  andi  $t6, $t8, 0x1f
/* 0FD608 7F0C8AD8 032E7821 */  addu  $t7, $t9, $t6
/* 0FD60C 7F0C8ADC 000FC883 */  sra   $t9, $t7, 2
/* 0FD610 7F0C8AE0 001972C0 */  sll   $t6, $t9, 0xb
/* 0FD614 7F0C8AE4 00097983 */  sra   $t7, $t1, 6
/* 0FD618 7F0C8AE8 31F8001F */  andi  $t8, $t7, 0x1f
/* 0FD61C 7F0C8AEC 000AC983 */  sra   $t9, $t2, 6
/* 0FD620 7F0C8AF0 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD624 7F0C8AF4 030FC821 */  addu  $t9, $t8, $t7
/* 0FD628 7F0C8AF8 000BC183 */  sra   $t8, $t3, 6
/* 0FD62C 7F0C8AFC 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD630 7F0C8B00 032FC021 */  addu  $t8, $t9, $t7
/* 0FD634 7F0C8B04 000CC983 */  sra   $t9, $t4, 6
/* 0FD638 7F0C8B08 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD63C 7F0C8B0C 030FC821 */  addu  $t9, $t8, $t7
/* 0FD640 7F0C8B10 0019C083 */  sra   $t8, $t9, 2
/* 0FD644 7F0C8B14 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD648 7F0C8B18 000FC980 */  sll   $t9, $t7, 6
/* 0FD64C 7F0C8B1C 01D9C025 */  or    $t8, $t6, $t9
/* 0FD650 7F0C8B20 00097843 */  sra   $t7, $t1, 1
/* 0FD654 7F0C8B24 31EE001F */  andi  $t6, $t7, 0x1f
/* 0FD658 7F0C8B28 000AC843 */  sra   $t9, $t2, 1
/* 0FD65C 7F0C8B2C 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD660 7F0C8B30 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD664 7F0C8B34 000B7043 */  sra   $t6, $t3, 1
/* 0FD668 7F0C8B38 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD66C 7F0C8B3C 032F7021 */  addu  $t6, $t9, $t7
/* 0FD670 7F0C8B40 000CC843 */  sra   $t9, $t4, 1
/* 0FD674 7F0C8B44 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD678 7F0C8B48 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD67C 7F0C8B4C 00197083 */  sra   $t6, $t9, 2
/* 0FD680 7F0C8B50 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD684 7F0C8B54 000FC840 */  sll   $t9, $t7, 1
/* 0FD688 7F0C8B58 03197025 */  or    $t6, $t8, $t9
/* 0FD68C 7F0C8B5C 31580001 */  andi  $t8, $t2, 1
/* 0FD690 7F0C8B60 312F0001 */  andi  $t7, $t1, 1
/* 0FD694 7F0C8B64 01F8C821 */  addu  $t9, $t7, $t8
/* 0FD698 7F0C8B68 316F0001 */  andi  $t7, $t3, 1
/* 0FD69C 7F0C8B6C 032FC021 */  addu  $t8, $t9, $t7
/* 0FD6A0 7F0C8B70 31990001 */  andi  $t9, $t4, 1
/* 0FD6A4 7F0C8B74 03197821 */  addu  $t7, $t8, $t9
/* 0FD6A8 7F0C8B78 25F80002 */  addiu $t8, $t7, 2
/* 0FD6AC 7F0C8B7C 0018C883 */  sra   $t9, $t8, 2
/* 0FD6B0 7F0C8B80 332F0001 */  andi  $t7, $t9, 1
/* 0FD6B4 7F0C8B84 0008C843 */  sra   $t9, $t0, 1
/* 0FD6B8 7F0C8B88 01CFC025 */  or    $t8, $t6, $t7
/* 0FD6BC 7F0C8B8C 25080002 */  addiu $t0, $t0, 2
/* 0FD6C0 7F0C8B90 00197040 */  sll   $t6, $t9, 1
/* 0FD6C4 7F0C8B94 0112082A */  slt   $at, $t0, $s2
/* 0FD6C8 7F0C8B98 02CE7821 */  addu  $t7, $s6, $t6
/* 0FD6CC 7F0C8B9C 25AD0004 */  addiu $t5, $t5, 4
/* 0FD6D0 7F0C8BA0 26100004 */  addiu $s0, $s0, 4
/* 0FD6D4 7F0C8BA4 1420FFB5 */  bnez  $at, .L7F0C8A7C
/* 0FD6D8 7F0C8BA8 A5F80000 */   sh    $t8, ($t7)
.L7F0C8BAC:
/* 0FD6DC 7F0C8BAC 8FB90038 */  lw    $t9, 0x38($sp)
/* 0FD6E0 7F0C8BB0 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0FD6E4 7F0C8BB4 03D7082A */  slt   $at, $fp, $s7
/* 0FD6E8 7F0C8BB8 02D9B021 */  addu  $s6, $s6, $t9
/* 0FD6EC 7F0C8BBC 1420FFA2 */  bnez  $at, .L7F0C8A48
/* 0FD6F0 7F0C8BC0 028EA021 */   addu  $s4, $s4, $t6
.L7F0C8BC4:
/* 0FD6F4 7F0C8BC4 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FD6F8 7F0C8BC8 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FD6FC 7F0C8BCC 030F0019 */  multu $t8, $t7
/* 0FD700 7F0C8BD0 00001012 */  mflo  $v0
/* 0FD704 7F0C8BD4 0002C840 */  sll   $t9, $v0, 1
/* 0FD708 7F0C8BD8 10000172 */  b     .L7F0C91A4
/* 0FD70C 7F0C8BDC 03201025 */   move  $v0, $t9
.L7F0C8BE0:
/* 0FD710 7F0C8BE0 1AE00047 */  blez  $s7, .L7F0C8D00
/* 0FD714 7F0C8BE4 0000F025 */   move  $fp, $zero
/* 0FD718 7F0C8BE8 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD71C 7F0C8BEC 0012C880 */  sll   $t9, $s2, 2
/* 0FD720 7F0C8BF0 AFB90034 */  sw    $t9, 0x34($sp)
/* 0FD724 7F0C8BF4 000EC040 */  sll   $t8, $t6, 1
/* 0FD728 7F0C8BF8 AFB80038 */  sw    $t8, 0x38($sp)
.L7F0C8BFC:
/* 0FD72C 7F0C8BFC 27CE0001 */  addiu $t6, $fp, 1
/* 0FD730 7F0C8C00 01D7082A */  slt   $at, $t6, $s7
/* 0FD734 7F0C8C04 10200003 */  beqz  $at, .L7F0C8C14
/* 0FD738 7F0C8C08 00004025 */   move  $t0, $zero
/* 0FD73C 7F0C8C0C 10000002 */  b     .L7F0C8C18
/* 0FD740 7F0C8C10 02409825 */   move  $s3, $s2
.L7F0C8C14:
/* 0FD744 7F0C8C14 00009825 */  move  $s3, $zero
.L7F0C8C18:
/* 0FD748 7F0C8C18 1A400033 */  blez  $s2, .L7F0C8CE8
/* 0FD74C 7F0C8C1C 27DE0002 */   addiu $fp, $fp, 2
/* 0FD750 7F0C8C20 0013C040 */  sll   $t8, $s3, 1
/* 0FD754 7F0C8C24 02988821 */  addu  $s1, $s4, $t8
/* 0FD758 7F0C8C28 02208025 */  move  $s0, $s1
/* 0FD75C 7F0C8C2C 02806825 */  move  $t5, $s4
.L7F0C8C30:
/* 0FD760 7F0C8C30 25020001 */  addiu $v0, $t0, 1
/* 0FD764 7F0C8C34 0055082A */  slt   $at, $v0, $s5
/* 0FD768 7F0C8C38 10200003 */  beqz  $at, .L7F0C8C48
/* 0FD76C 7F0C8C3C 01003825 */   move  $a3, $t0
/* 0FD770 7F0C8C40 10000001 */  b     .L7F0C8C48
/* 0FD774 7F0C8C44 00403825 */   move  $a3, $v0
.L7F0C8C48:
/* 0FD778 7F0C8C48 00073040 */  sll   $a2, $a3, 1
/* 0FD77C 7F0C8C4C 02867821 */  addu  $t7, $s4, $a2
/* 0FD780 7F0C8C50 95EA0000 */  lhu   $t2, ($t7)
/* 0FD784 7F0C8C54 95A90000 */  lhu   $t1, ($t5)
/* 0FD788 7F0C8C58 0226C821 */  addu  $t9, $s1, $a2
/* 0FD78C 7F0C8C5C 960B0000 */  lhu   $t3, ($s0)
/* 0FD790 7F0C8C60 972C0000 */  lhu   $t4, ($t9)
/* 0FD794 7F0C8C64 000A7A03 */  sra   $t7, $t2, 8
/* 0FD798 7F0C8C68 31F900FF */  andi  $t9, $t7, 0xff
/* 0FD79C 7F0C8C6C 00097203 */  sra   $t6, $t1, 8
/* 0FD7A0 7F0C8C70 31D800FF */  andi  $t8, $t6, 0xff
/* 0FD7A4 7F0C8C74 03197021 */  addu  $t6, $t8, $t9
/* 0FD7A8 7F0C8C78 000B7A03 */  sra   $t7, $t3, 8
/* 0FD7AC 7F0C8C7C 31F800FF */  andi  $t8, $t7, 0xff
/* 0FD7B0 7F0C8C80 01D8C821 */  addu  $t9, $t6, $t8
/* 0FD7B4 7F0C8C84 000C7A03 */  sra   $t7, $t4, 8
/* 0FD7B8 7F0C8C88 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD7BC 7F0C8C8C 032EC021 */  addu  $t8, $t9, $t6
/* 0FD7C0 7F0C8C90 0018C883 */  sra   $t9, $t8, 2
/* 0FD7C4 7F0C8C94 00197200 */  sll   $t6, $t9, 8
/* 0FD7C8 7F0C8C98 314F00FF */  andi  $t7, $t2, 0xff
/* 0FD7CC 7F0C8C9C 313800FF */  andi  $t8, $t1, 0xff
/* 0FD7D0 7F0C8CA0 030FC821 */  addu  $t9, $t8, $t7
/* 0FD7D4 7F0C8CA4 317800FF */  andi  $t8, $t3, 0xff
/* 0FD7D8 7F0C8CA8 03387821 */  addu  $t7, $t9, $t8
/* 0FD7DC 7F0C8CAC 319900FF */  andi  $t9, $t4, 0xff
/* 0FD7E0 7F0C8CB0 01F9C021 */  addu  $t8, $t7, $t9
/* 0FD7E4 7F0C8CB4 270F0001 */  addiu $t7, $t8, 1
/* 0FD7E8 7F0C8CB8 000FC883 */  sra   $t9, $t7, 2
/* 0FD7EC 7F0C8CBC 333800FF */  andi  $t8, $t9, 0xff
/* 0FD7F0 7F0C8CC0 0008C843 */  sra   $t9, $t0, 1
/* 0FD7F4 7F0C8CC4 01D87825 */  or    $t7, $t6, $t8
/* 0FD7F8 7F0C8CC8 25080002 */  addiu $t0, $t0, 2
/* 0FD7FC 7F0C8CCC 00197040 */  sll   $t6, $t9, 1
/* 0FD800 7F0C8CD0 0112082A */  slt   $at, $t0, $s2
/* 0FD804 7F0C8CD4 02CEC021 */  addu  $t8, $s6, $t6
/* 0FD808 7F0C8CD8 25AD0004 */  addiu $t5, $t5, 4
/* 0FD80C 7F0C8CDC 26100004 */  addiu $s0, $s0, 4
/* 0FD810 7F0C8CE0 1420FFD3 */  bnez  $at, .L7F0C8C30
/* 0FD814 7F0C8CE4 A70F0000 */   sh    $t7, ($t8)
.L7F0C8CE8:
/* 0FD818 7F0C8CE8 8FB90038 */  lw    $t9, 0x38($sp)
/* 0FD81C 7F0C8CEC 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0FD820 7F0C8CF0 03D7082A */  slt   $at, $fp, $s7
/* 0FD824 7F0C8CF4 02D9B021 */  addu  $s6, $s6, $t9
/* 0FD828 7F0C8CF8 1420FFC0 */  bnez  $at, .L7F0C8BFC
/* 0FD82C 7F0C8CFC 028EA021 */   addu  $s4, $s4, $t6
.L7F0C8D00:
/* 0FD830 7F0C8D00 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0FD834 7F0C8D04 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FD838 7F0C8D08 01F80019 */  multu $t7, $t8
/* 0FD83C 7F0C8D0C 00001012 */  mflo  $v0
/* 0FD840 7F0C8D10 0002C840 */  sll   $t9, $v0, 1
/* 0FD844 7F0C8D14 10000123 */  b     .L7F0C91A4
/* 0FD848 7F0C8D18 03201025 */   move  $v0, $t9
.L7F0C8D1C:
/* 0FD84C 7F0C8D1C 1AE0003F */  blez  $s7, .L7F0C8E1C
/* 0FD850 7F0C8D20 0000F025 */   move  $fp, $zero
/* 0FD854 7F0C8D24 0012A040 */  sll   $s4, $s2, 1
.L7F0C8D28:
/* 0FD858 7F0C8D28 27CE0001 */  addiu $t6, $fp, 1
/* 0FD85C 7F0C8D2C 01D7082A */  slt   $at, $t6, $s7
/* 0FD860 7F0C8D30 10200003 */  beqz  $at, .L7F0C8D40
/* 0FD864 7F0C8D34 00004025 */   move  $t0, $zero
/* 0FD868 7F0C8D38 10000002 */  b     .L7F0C8D44
/* 0FD86C 7F0C8D3C 02409825 */   move  $s3, $s2
.L7F0C8D40:
/* 0FD870 7F0C8D40 00009825 */  move  $s3, $zero
.L7F0C8D44:
/* 0FD874 7F0C8D44 1A400030 */  blez  $s2, .L7F0C8E08
/* 0FD878 7F0C8D48 27DE0002 */   addiu $fp, $fp, 2
/* 0FD87C 7F0C8D4C 02006025 */  move  $t4, $s0
/* 0FD880 7F0C8D50 02706821 */  addu  $t5, $s3, $s0
.L7F0C8D54:
/* 0FD884 7F0C8D54 25020001 */  addiu $v0, $t0, 1
/* 0FD888 7F0C8D58 0055082A */  slt   $at, $v0, $s5
/* 0FD88C 7F0C8D5C 10200003 */  beqz  $at, .L7F0C8D6C
/* 0FD890 7F0C8D60 01003825 */   move  $a3, $t0
/* 0FD894 7F0C8D64 10000001 */  b     .L7F0C8D6C
/* 0FD898 7F0C8D68 00403825 */   move  $a3, $v0
.L7F0C8D6C:
/* 0FD89C 7F0C8D6C 02077821 */  addu  $t7, $s0, $a3
/* 0FD8A0 7F0C8D70 91E90000 */  lbu   $t1, ($t7)
/* 0FD8A4 7F0C8D74 0267C021 */  addu  $t8, $s3, $a3
/* 0FD8A8 7F0C8D78 918B0000 */  lbu   $t3, ($t4)
/* 0FD8AC 7F0C8D7C 0310C821 */  addu  $t9, $t8, $s0
/* 0FD8B0 7F0C8D80 91AA0000 */  lbu   $t2, ($t5)
/* 0FD8B4 7F0C8D84 93260000 */  lbu   $a2, ($t9)
/* 0FD8B8 7F0C8D88 0009C103 */  sra   $t8, $t1, 4
/* 0FD8BC 7F0C8D8C 3319000F */  andi  $t9, $t8, 0xf
/* 0FD8C0 7F0C8D90 000B7103 */  sra   $t6, $t3, 4
/* 0FD8C4 7F0C8D94 31CF000F */  andi  $t7, $t6, 0xf
/* 0FD8C8 7F0C8D98 01F97021 */  addu  $t6, $t7, $t9
/* 0FD8CC 7F0C8D9C 000AC103 */  sra   $t8, $t2, 4
/* 0FD8D0 7F0C8DA0 330F000F */  andi  $t7, $t8, 0xf
/* 0FD8D4 7F0C8DA4 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD8D8 7F0C8DA8 0006C103 */  sra   $t8, $a2, 4
/* 0FD8DC 7F0C8DAC 330E000F */  andi  $t6, $t8, 0xf
/* 0FD8E0 7F0C8DB0 032E7821 */  addu  $t7, $t9, $t6
/* 0FD8E4 7F0C8DB4 000FC080 */  sll   $t8, $t7, 2
/* 0FD8E8 7F0C8DB8 331900F0 */  andi  $t9, $t8, 0xf0
/* 0FD8EC 7F0C8DBC 312F000F */  andi  $t7, $t1, 0xf
/* 0FD8F0 7F0C8DC0 316E000F */  andi  $t6, $t3, 0xf
/* 0FD8F4 7F0C8DC4 01CFC021 */  addu  $t8, $t6, $t7
/* 0FD8F8 7F0C8DC8 314E000F */  andi  $t6, $t2, 0xf
/* 0FD8FC 7F0C8DCC 030E7821 */  addu  $t7, $t8, $t6
/* 0FD900 7F0C8DD0 30D8000F */  andi  $t8, $a2, 0xf
/* 0FD904 7F0C8DD4 01F87021 */  addu  $t6, $t7, $t8
/* 0FD908 7F0C8DD8 25CF0001 */  addiu $t7, $t6, 1
/* 0FD90C 7F0C8DDC 000FC083 */  sra   $t8, $t7, 2
/* 0FD910 7F0C8DE0 330E000F */  andi  $t6, $t8, 0xf
/* 0FD914 7F0C8DE4 0008C043 */  sra   $t8, $t0, 1
/* 0FD918 7F0C8DE8 25080002 */  addiu $t0, $t0, 2
/* 0FD91C 7F0C8DEC 032E7825 */  or    $t7, $t9, $t6
/* 0FD920 7F0C8DF0 0112082A */  slt   $at, $t0, $s2
/* 0FD924 7F0C8DF4 0238C821 */  addu  $t9, $s1, $t8
/* 0FD928 7F0C8DF8 258C0002 */  addiu $t4, $t4, 2
/* 0FD92C 7F0C8DFC 25AD0002 */  addiu $t5, $t5, 2
/* 0FD930 7F0C8E00 1420FFD4 */  bnez  $at, .L7F0C8D54
/* 0FD934 7F0C8E04 A32F0000 */   sb    $t7, ($t9)
.L7F0C8E08:
/* 0FD938 7F0C8E08 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD93C 7F0C8E0C 03D7082A */  slt   $at, $fp, $s7
/* 0FD940 7F0C8E10 02148021 */  addu  $s0, $s0, $s4
/* 0FD944 7F0C8E14 1420FFC4 */  bnez  $at, .L7F0C8D28
/* 0FD948 7F0C8E18 022E8821 */   addu  $s1, $s1, $t6
.L7F0C8E1C:
/* 0FD94C 7F0C8E1C 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FD950 7F0C8E20 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FD954 7F0C8E24 030F0019 */  multu $t8, $t7
/* 0FD958 7F0C8E28 00001012 */  mflo  $v0
/* 0FD95C 7F0C8E2C 100000DE */  b     .L7F0C91A8
/* 0FD960 7F0C8E30 8FB00004 */   lw    $s0, 4($sp)
.L7F0C8E34:
/* 0FD964 7F0C8E34 1AE0002C */  blez  $s7, .L7F0C8EE8
/* 0FD968 7F0C8E38 0000F025 */   move  $fp, $zero
/* 0FD96C 7F0C8E3C 0012A040 */  sll   $s4, $s2, 1
.L7F0C8E40:
/* 0FD970 7F0C8E40 27D90001 */  addiu $t9, $fp, 1
/* 0FD974 7F0C8E44 0337082A */  slt   $at, $t9, $s7
/* 0FD978 7F0C8E48 10200003 */  beqz  $at, .L7F0C8E58
/* 0FD97C 7F0C8E4C 00004025 */   move  $t0, $zero
/* 0FD980 7F0C8E50 10000002 */  b     .L7F0C8E5C
/* 0FD984 7F0C8E54 02409825 */   move  $s3, $s2
.L7F0C8E58:
/* 0FD988 7F0C8E58 00009825 */  move  $s3, $zero
.L7F0C8E5C:
/* 0FD98C 7F0C8E5C 1A40001D */  blez  $s2, .L7F0C8ED4
/* 0FD990 7F0C8E60 27DE0002 */   addiu $fp, $fp, 2
/* 0FD994 7F0C8E64 02006025 */  move  $t4, $s0
/* 0FD998 7F0C8E68 02706821 */  addu  $t5, $s3, $s0
.L7F0C8E6C:
/* 0FD99C 7F0C8E6C 25020001 */  addiu $v0, $t0, 1
/* 0FD9A0 7F0C8E70 0055082A */  slt   $at, $v0, $s5
/* 0FD9A4 7F0C8E74 10200003 */  beqz  $at, .L7F0C8E84
/* 0FD9A8 7F0C8E78 01003825 */   move  $a3, $t0
/* 0FD9AC 7F0C8E7C 10000001 */  b     .L7F0C8E84
/* 0FD9B0 7F0C8E80 00403825 */   move  $a3, $v0
.L7F0C8E84:
/* 0FD9B4 7F0C8E84 02077021 */  addu  $t6, $s0, $a3
/* 0FD9B8 7F0C8E88 918B0000 */  lbu   $t3, ($t4)
/* 0FD9BC 7F0C8E8C 91C90000 */  lbu   $t1, ($t6)
/* 0FD9C0 7F0C8E90 0267C021 */  addu  $t8, $s3, $a3
/* 0FD9C4 7F0C8E94 91AA0000 */  lbu   $t2, ($t5)
/* 0FD9C8 7F0C8E98 03107821 */  addu  $t7, $t8, $s0
/* 0FD9CC 7F0C8E9C 91E60000 */  lbu   $a2, ($t7)
/* 0FD9D0 7F0C8EA0 0169C821 */  addu  $t9, $t3, $t1
/* 0FD9D4 7F0C8EA4 032A7021 */  addu  $t6, $t9, $t2
/* 0FD9D8 7F0C8EA8 01C6C021 */  addu  $t8, $t6, $a2
/* 0FD9DC 7F0C8EAC 270F0001 */  addiu $t7, $t8, 1
/* 0FD9E0 7F0C8EB0 0008C043 */  sra   $t8, $t0, 1
/* 0FD9E4 7F0C8EB4 25080002 */  addiu $t0, $t0, 2
/* 0FD9E8 7F0C8EB8 000F7083 */  sra   $t6, $t7, 2
/* 0FD9EC 7F0C8EBC 0112082A */  slt   $at, $t0, $s2
/* 0FD9F0 7F0C8EC0 02387821 */  addu  $t7, $s1, $t8
/* 0FD9F4 7F0C8EC4 258C0002 */  addiu $t4, $t4, 2
/* 0FD9F8 7F0C8EC8 25AD0002 */  addiu $t5, $t5, 2
/* 0FD9FC 7F0C8ECC 1420FFE7 */  bnez  $at, .L7F0C8E6C
/* 0FDA00 7F0C8ED0 A1EE0000 */   sb    $t6, ($t7)
.L7F0C8ED4:
/* 0FDA04 7F0C8ED4 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FDA08 7F0C8ED8 03D7082A */  slt   $at, $fp, $s7
/* 0FDA0C 7F0C8EDC 02148021 */  addu  $s0, $s0, $s4
/* 0FDA10 7F0C8EE0 1420FFD7 */  bnez  $at, .L7F0C8E40
/* 0FDA14 7F0C8EE4 02398821 */   addu  $s1, $s1, $t9
.L7F0C8EE8:
/* 0FDA18 7F0C8EE8 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FDA1C 7F0C8EEC 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FDA20 7F0C8EF0 030E0019 */  multu $t8, $t6
/* 0FDA24 7F0C8EF4 00001012 */  mflo  $v0
/* 0FDA28 7F0C8EF8 100000AB */  b     .L7F0C91A8
/* 0FDA2C 7F0C8EFC 8FB00004 */   lw    $s0, 4($sp)
.L7F0C8F00:
/* 0FDA30 7F0C8F00 1AE0005D */  blez  $s7, .L7F0C9078
/* 0FDA34 7F0C8F04 0000F025 */   move  $fp, $zero
/* 0FDA38 7F0C8F08 8FB400A8 */  lw    $s4, 0xa8($sp)
/* 0FDA3C 7F0C8F0C 00147843 */  sra   $t7, $s4, 1
/* 0FDA40 7F0C8F10 01E0A025 */  move  $s4, $t7
.L7F0C8F14:
/* 0FDA44 7F0C8F14 1A400053 */  blez  $s2, .L7F0C9064
/* 0FDA48 7F0C8F18 00004025 */   move  $t0, $zero
/* 0FDA4C 7F0C8F1C 27C70001 */  addiu $a3, $fp, 1
.L7F0C8F20:
/* 0FDA50 7F0C8F20 00086843 */  sra   $t5, $t0, 1
/* 0FDA54 7F0C8F24 01B01021 */  addu  $v0, $t5, $s0
/* 0FDA58 7F0C8F28 00F7082A */  slt   $at, $a3, $s7
/* 0FDA5C 7F0C8F2C 10200003 */  beqz  $at, .L7F0C8F3C
/* 0FDA60 7F0C8F30 904B0000 */   lbu   $t3, ($v0)
/* 0FDA64 7F0C8F34 10000002 */  b     .L7F0C8F40
/* 0FDA68 7F0C8F38 00129843 */   sra   $s3, $s2, 1
.L7F0C8F3C:
/* 0FDA6C 7F0C8F3C 00009825 */  move  $s3, $zero
.L7F0C8F40:
/* 0FDA70 7F0C8F40 026DC821 */  addu  $t9, $s3, $t5
/* 0FDA74 7F0C8F44 0330C021 */  addu  $t8, $t9, $s0
/* 0FDA78 7F0C8F48 00F7082A */  slt   $at, $a3, $s7
/* 0FDA7C 7F0C8F4C 93090000 */  lbu   $t1, ($t8)
/* 0FDA80 7F0C8F50 10200003 */  beqz  $at, .L7F0C8F60
/* 0FDA84 7F0C8F54 904A0001 */   lbu   $t2, 1($v0)
/* 0FDA88 7F0C8F58 10000002 */  b     .L7F0C8F64
/* 0FDA8C 7F0C8F5C 00129843 */   sra   $s3, $s2, 1
.L7F0C8F60:
/* 0FDA90 7F0C8F60 00009825 */  move  $s3, $zero
.L7F0C8F64:
/* 0FDA94 7F0C8F64 026D7021 */  addu  $t6, $s3, $t5
/* 0FDA98 7F0C8F68 01D07821 */  addu  $t7, $t6, $s0
/* 0FDA9C 7F0C8F6C 91E60001 */  lbu   $a2, 1($t7)
/* 0FDAA0 7F0C8F70 000B7043 */  sra   $t6, $t3, 1
/* 0FDAA4 7F0C8F74 31CF0007 */  andi  $t7, $t6, 7
/* 0FDAA8 7F0C8F78 000BC943 */  sra   $t9, $t3, 5
/* 0FDAAC 7F0C8F7C 33380007 */  andi  $t8, $t9, 7
/* 0FDAB0 7F0C8F80 030FC821 */  addu  $t9, $t8, $t7
/* 0FDAB4 7F0C8F84 00097143 */  sra   $t6, $t1, 5
/* 0FDAB8 7F0C8F88 31D80007 */  andi  $t8, $t6, 7
/* 0FDABC 7F0C8F8C 03387821 */  addu  $t7, $t9, $t8
/* 0FDAC0 7F0C8F90 00097043 */  sra   $t6, $t1, 1
/* 0FDAC4 7F0C8F94 31D90007 */  andi  $t9, $t6, 7
/* 0FDAC8 7F0C8F98 01F9C021 */  addu  $t8, $t7, $t9
/* 0FDACC 7F0C8F9C 001870C0 */  sll   $t6, $t8, 3
/* 0FDAD0 7F0C8FA0 31CF00E0 */  andi  $t7, $t6, 0xe0
/* 0FDAD4 7F0C8FA4 000AC943 */  sra   $t9, $t2, 5
/* 0FDAD8 7F0C8FA8 33380007 */  andi  $t8, $t9, 7
/* 0FDADC 7F0C8FAC 000A7043 */  sra   $t6, $t2, 1
/* 0FDAE0 7F0C8FB0 31D90007 */  andi  $t9, $t6, 7
/* 0FDAE4 7F0C8FB4 03197021 */  addu  $t6, $t8, $t9
/* 0FDAE8 7F0C8FB8 0006C143 */  sra   $t8, $a2, 5
/* 0FDAEC 7F0C8FBC 33190007 */  andi  $t9, $t8, 7
/* 0FDAF0 7F0C8FC0 01D9C021 */  addu  $t8, $t6, $t9
/* 0FDAF4 7F0C8FC4 00067043 */  sra   $t6, $a2, 1
/* 0FDAF8 7F0C8FC8 31D90007 */  andi  $t9, $t6, 7
/* 0FDAFC 7F0C8FCC 03197021 */  addu  $t6, $t8, $t9
/* 0FDB00 7F0C8FD0 000EC043 */  sra   $t8, $t6, 1
/* 0FDB04 7F0C8FD4 3319000E */  andi  $t9, $t8, 0xe
/* 0FDB08 7F0C8FD8 01F97025 */  or    $t6, $t7, $t9
/* 0FDB0C 7F0C8FDC 000BC103 */  sra   $t8, $t3, 4
/* 0FDB10 7F0C8FE0 330F0001 */  andi  $t7, $t8, 1
/* 0FDB14 7F0C8FE4 31790001 */  andi  $t9, $t3, 1
/* 0FDB18 7F0C8FE8 01F9C021 */  addu  $t8, $t7, $t9
/* 0FDB1C 7F0C8FEC 00097903 */  sra   $t7, $t1, 4
/* 0FDB20 7F0C8FF0 31F90001 */  andi  $t9, $t7, 1
/* 0FDB24 7F0C8FF4 03197821 */  addu  $t7, $t8, $t9
/* 0FDB28 7F0C8FF8 31380001 */  andi  $t8, $t1, 1
/* 0FDB2C 7F0C8FFC 01F8C821 */  addu  $t9, $t7, $t8
/* 0FDB30 7F0C9000 272F0001 */  addiu $t7, $t9, 1
/* 0FDB34 7F0C9004 000FC080 */  sll   $t8, $t7, 2
/* 0FDB38 7F0C9008 33190010 */  andi  $t9, $t8, 0x10
/* 0FDB3C 7F0C900C 000A7903 */  sra   $t7, $t2, 4
/* 0FDB40 7F0C9010 31F80001 */  andi  $t8, $t7, 1
/* 0FDB44 7F0C9014 314F0001 */  andi  $t7, $t2, 1
/* 0FDB48 7F0C9018 030FC021 */  addu  $t8, $t8, $t7
/* 0FDB4C 7F0C901C AFAE0028 */  sw    $t6, 0x28($sp)
/* 0FDB50 7F0C9020 00067903 */  sra   $t7, $a2, 4
/* 0FDB54 7F0C9024 31EE0001 */  andi  $t6, $t7, 1
/* 0FDB58 7F0C9028 030E7021 */  addu  $t6, $t8, $t6
/* 0FDB5C 7F0C902C 30D80001 */  andi  $t8, $a2, 1
/* 0FDB60 7F0C9030 01D87821 */  addu  $t7, $t6, $t8
/* 0FDB64 7F0C9034 25EE0001 */  addiu $t6, $t7, 1
/* 0FDB68 7F0C9038 000EC083 */  sra   $t8, $t6, 2
/* 0FDB6C 7F0C903C 330F0001 */  andi  $t7, $t8, 1
/* 0FDB70 7F0C9040 8FB80028 */  lw    $t8, 0x28($sp)
/* 0FDB74 7F0C9044 032F7025 */  or    $t6, $t9, $t7
/* 0FDB78 7F0C9048 00087883 */  sra   $t7, $t0, 2
/* 0FDB7C 7F0C904C 25080004 */  addiu $t0, $t0, 4
/* 0FDB80 7F0C9050 030EC825 */  or    $t9, $t8, $t6
/* 0FDB84 7F0C9054 0112082A */  slt   $at, $t0, $s2
/* 0FDB88 7F0C9058 022FC021 */  addu  $t8, $s1, $t7
/* 0FDB8C 7F0C905C 1420FFB0 */  bnez  $at, .L7F0C8F20
/* 0FDB90 7F0C9060 A3190000 */   sb    $t9, ($t8)
.L7F0C9064:
/* 0FDB94 7F0C9064 27DE0002 */  addiu $fp, $fp, 2
/* 0FDB98 7F0C9068 03D7082A */  slt   $at, $fp, $s7
/* 0FDB9C 7F0C906C 02348821 */  addu  $s1, $s1, $s4
/* 0FDBA0 7F0C9070 1420FFA8 */  bnez  $at, .L7F0C8F14
/* 0FDBA4 7F0C9074 02128021 */   addu  $s0, $s0, $s2
.L7F0C9078:
/* 0FDBA8 7F0C9078 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FDBAC 7F0C907C 000E7843 */  sra   $t7, $t6, 1
/* 0FDBB0 7F0C9080 01EC0019 */  multu $t7, $t4
/* 0FDBB4 7F0C9084 00001012 */  mflo  $v0
/* 0FDBB8 7F0C9088 10000047 */  b     .L7F0C91A8
/* 0FDBBC 7F0C908C 8FB00004 */   lw    $s0, 4($sp)
.L7F0C9090:
/* 0FDBC0 7F0C9090 1AE0003D */  blez  $s7, .L7F0C9188
/* 0FDBC4 7F0C9094 0000F025 */   move  $fp, $zero
/* 0FDBC8 7F0C9098 8FB400A8 */  lw    $s4, 0xa8($sp)
/* 0FDBCC 7F0C909C 0014C843 */  sra   $t9, $s4, 1
/* 0FDBD0 7F0C90A0 0320A025 */  move  $s4, $t9
.L7F0C90A4:
/* 0FDBD4 7F0C90A4 1A400033 */  blez  $s2, .L7F0C9174
/* 0FDBD8 7F0C90A8 00004025 */   move  $t0, $zero
/* 0FDBDC 7F0C90AC 27C70001 */  addiu $a3, $fp, 1
.L7F0C90B0:
/* 0FDBE0 7F0C90B0 00086843 */  sra   $t5, $t0, 1
/* 0FDBE4 7F0C90B4 01B01021 */  addu  $v0, $t5, $s0
/* 0FDBE8 7F0C90B8 00F7082A */  slt   $at, $a3, $s7
/* 0FDBEC 7F0C90BC 10200003 */  beqz  $at, .L7F0C90CC
/* 0FDBF0 7F0C90C0 904B0000 */   lbu   $t3, ($v0)
/* 0FDBF4 7F0C90C4 10000002 */  b     .L7F0C90D0
/* 0FDBF8 7F0C90C8 00129843 */   sra   $s3, $s2, 1
.L7F0C90CC:
/* 0FDBFC 7F0C90CC 00009825 */  move  $s3, $zero
.L7F0C90D0:
/* 0FDC00 7F0C90D0 026DC021 */  addu  $t8, $s3, $t5
/* 0FDC04 7F0C90D4 03107021 */  addu  $t6, $t8, $s0
/* 0FDC08 7F0C90D8 00F7082A */  slt   $at, $a3, $s7
/* 0FDC0C 7F0C90DC 91C90000 */  lbu   $t1, ($t6)
/* 0FDC10 7F0C90E0 10200003 */  beqz  $at, .L7F0C90F0
/* 0FDC14 7F0C90E4 904A0001 */   lbu   $t2, 1($v0)
/* 0FDC18 7F0C90E8 10000002 */  b     .L7F0C90F4
/* 0FDC1C 7F0C90EC 00129843 */   sra   $s3, $s2, 1
.L7F0C90F0:
/* 0FDC20 7F0C90F0 00009825 */  move  $s3, $zero
.L7F0C90F4:
/* 0FDC24 7F0C90F4 026D7821 */  addu  $t7, $s3, $t5
/* 0FDC28 7F0C90F8 01F0C821 */  addu  $t9, $t7, $s0
/* 0FDC2C 7F0C90FC 000BC103 */  sra   $t8, $t3, 4
/* 0FDC30 7F0C9100 330E000F */  andi  $t6, $t8, 0xf
/* 0FDC34 7F0C9104 93260001 */  lbu   $a2, 1($t9)
/* 0FDC38 7F0C9108 316F000F */  andi  $t7, $t3, 0xf
/* 0FDC3C 7F0C910C 01CFC821 */  addu  $t9, $t6, $t7
/* 0FDC40 7F0C9110 0009C103 */  sra   $t8, $t1, 4
/* 0FDC44 7F0C9114 330E000F */  andi  $t6, $t8, 0xf
/* 0FDC48 7F0C9118 032E7821 */  addu  $t7, $t9, $t6
/* 0FDC4C 7F0C911C 3138000F */  andi  $t8, $t1, 0xf
/* 0FDC50 7F0C9120 01F8C821 */  addu  $t9, $t7, $t8
/* 0FDC54 7F0C9124 00197080 */  sll   $t6, $t9, 2
/* 0FDC58 7F0C9128 31CF00F0 */  andi  $t7, $t6, 0xf0
/* 0FDC5C 7F0C912C 000AC103 */  sra   $t8, $t2, 4
/* 0FDC60 7F0C9130 3319000F */  andi  $t9, $t8, 0xf
/* 0FDC64 7F0C9134 314E000F */  andi  $t6, $t2, 0xf
/* 0FDC68 7F0C9138 032EC021 */  addu  $t8, $t9, $t6
/* 0FDC6C 7F0C913C 0006C903 */  sra   $t9, $a2, 4
/* 0FDC70 7F0C9140 332E000F */  andi  $t6, $t9, 0xf
/* 0FDC74 7F0C9144 030EC821 */  addu  $t9, $t8, $t6
/* 0FDC78 7F0C9148 30D8000F */  andi  $t8, $a2, 0xf
/* 0FDC7C 7F0C914C 03387021 */  addu  $t6, $t9, $t8
/* 0FDC80 7F0C9150 000EC883 */  sra   $t9, $t6, 2
/* 0FDC84 7F0C9154 3338000F */  andi  $t8, $t9, 0xf
/* 0FDC88 7F0C9158 0008C883 */  sra   $t9, $t0, 2
/* 0FDC8C 7F0C915C 25080004 */  addiu $t0, $t0, 4
/* 0FDC90 7F0C9160 01F87025 */  or    $t6, $t7, $t8
/* 0FDC94 7F0C9164 0112082A */  slt   $at, $t0, $s2
/* 0FDC98 7F0C9168 02397821 */  addu  $t7, $s1, $t9
/* 0FDC9C 7F0C916C 1420FFD0 */  bnez  $at, .L7F0C90B0
/* 0FDCA0 7F0C9170 A1EE0000 */   sb    $t6, ($t7)
.L7F0C9174:
/* 0FDCA4 7F0C9174 27DE0002 */  addiu $fp, $fp, 2
/* 0FDCA8 7F0C9178 03D7082A */  slt   $at, $fp, $s7
/* 0FDCAC 7F0C917C 02348821 */  addu  $s1, $s1, $s4
/* 0FDCB0 7F0C9180 1420FFC8 */  bnez  $at, .L7F0C90A4
/* 0FDCB4 7F0C9184 02128021 */   addu  $s0, $s0, $s2
.L7F0C9188:
/* 0FDCB8 7F0C9188 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FDCBC 7F0C918C 0018C843 */  sra   $t9, $t8, 1
/* 0FDCC0 7F0C9190 032C0019 */  multu $t9, $t4
/* 0FDCC4 7F0C9194 00001012 */  mflo  $v0
/* 0FDCC8 7F0C9198 10000003 */  b     .L7F0C91A8
/* 0FDCCC 7F0C919C 8FB00004 */   lw    $s0, 4($sp)
def_7F0C8874:
.L7F0C91A0:
/* 0FDCD0 7F0C91A0 00001025 */  move  $v0, $zero
.L7F0C91A4:
/* 0FDCD4 7F0C91A4 8FB00004 */  lw    $s0, 4($sp)
.L7F0C91A8:
/* 0FDCD8 7F0C91A8 8FB10008 */  lw    $s1, 8($sp)
/* 0FDCDC 7F0C91AC 8FB2000C */  lw    $s2, 0xc($sp)
/* 0FDCE0 7F0C91B0 8FB30010 */  lw    $s3, 0x10($sp)
/* 0FDCE4 7F0C91B4 8FB40014 */  lw    $s4, 0x14($sp)
/* 0FDCE8 7F0C91B8 8FB50018 */  lw    $s5, 0x18($sp)
/* 0FDCEC 7F0C91BC 8FB6001C */  lw    $s6, 0x1c($sp)
/* 0FDCF0 7F0C91C0 8FB70020 */  lw    $s7, 0x20($sp)
/* 0FDCF4 7F0C91C4 8FBE0024 */  lw    $fp, 0x24($sp)
/* 0FDCF8 7F0C91C8 03E00008 */  jr    $ra
/* 0FDCFC 7F0C91CC 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void generate_sample_table(void) {

}
#else
GLOBAL_ASM(
.text
glabel generate_sample_table
/* 0FDD00 7F0C91D0 27BDCF88 */  addiu $sp, $sp, -0x3078
/* 0FDD04 7F0C91D4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0FDD08 7F0C91D8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0FDD0C 7F0C91DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FDD10 7F0C91E0 00C0A025 */  move  $s4, $a2
/* 0FDD14 7F0C91E4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FDD18 7F0C91E8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FDD1C 7F0C91EC AFB00018 */  sw    $s0, 0x18($sp)
/* 0FDD20 7F0C91F0 AFA43078 */  sw    $a0, 0x3078($sp)
/* 0FDD24 7F0C91F4 AFA5307C */  sw    $a1, 0x307c($sp)
/* 0FDD28 7F0C91F8 0000F825 */  move  $ra, $zero
/* 0FDD2C 7F0C91FC 18C0000A */  blez  $a2, .L7F0C9228
/* 0FDD30 7F0C9200 00008825 */   move  $s1, $zero
/* 0FDD34 7F0C9204 27B02078 */  addiu $s0, $sp, 0x2078
.L7F0C9208:
/* 0FDD38 7F0C9208 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0FDD3C 7F0C920C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FDD40 7F0C9210 24040008 */   li    $a0, 8
/* 0FDD44 7F0C9214 26310001 */  addiu $s1, $s1, 1
/* 0FDD48 7F0C9218 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0FDD4C 7F0C921C 26100002 */  addiu $s0, $s0, 2
/* 0FDD50 7F0C9220 1634FFF9 */  bne   $s1, $s4, .L7F0C9208
/* 0FDD54 7F0C9224 A602FFFE */   sh    $v0, -2($s0)
.L7F0C9228:
/* 0FDD58 7F0C9228 27A20078 */  addiu $v0, $sp, 0x78
/* 0FDD5C 7F0C922C 27A42078 */  addiu $a0, $sp, 0x2078
/* 0FDD60 7F0C9230 2403FFFF */  li    $v1, -1
.L7F0C9234:
/* 0FDD64 7F0C9234 24420004 */  addiu $v0, $v0, 4
/* 0FDD68 7F0C9238 0044082B */  sltu  $at, $v0, $a0
/* 0FDD6C 7F0C923C A443FFFC */  sh    $v1, -4($v0)
/* 0FDD70 7F0C9240 1420FFFC */  bnez  $at, .L7F0C9234
/* 0FDD74 7F0C9244 A443FFFE */   sh    $v1, -2($v0)
/* 0FDD78 7F0C9248 2408270F */  li    $t0, 9999
/* 0FDD7C 7F0C924C 2406270F */  li    $a2, 9999
/* 0FDD80 7F0C9250 1A800049 */  blez  $s4, .L7F0C9378
/* 0FDD84 7F0C9254 00008825 */   move  $s1, $zero
/* 0FDD88 7F0C9258 32820001 */  andi  $v0, $s4, 1
/* 0FDD8C 7F0C925C 10400013 */  beqz  $v0, .L7F0C92AC
/* 0FDD90 7F0C9260 27AF2078 */   addiu $t7, $sp, 0x2078
/* 0FDD94 7F0C9264 97A22078 */  lhu   $v0, 0x2078($sp)
/* 0FDD98 7F0C9268 2841270F */  slti  $at, $v0, 0x270f
/* 0FDD9C 7F0C926C 50200005 */  beql  $at, $zero, .L7F0C9284
/* 0FDDA0 7F0C9270 2841270F */   slti  $at, $v0, 0x270f
/* 0FDDA4 7F0C9274 3046FFFF */  andi  $a2, $v0, 0xffff
/* 0FDDA8 7F0C9278 10000006 */  b     .L7F0C9294
/* 0FDDAC 7F0C927C AFA00060 */   sw    $zero, 0x60($sp)
/* 0FDDB0 7F0C9280 2841270F */  slti  $at, $v0, 0x270f
.L7F0C9284:
/* 0FDDB4 7F0C9284 50200004 */  beql  $at, $zero, .L7F0C9298
/* 0FDDB8 7F0C9288 8FA70060 */   lw    $a3, 0x60($sp)
/* 0FDDBC 7F0C928C 97A62078 */  lhu   $a2, 0x2078($sp)
/* 0FDDC0 7F0C9290 AFA00060 */  sw    $zero, 0x60($sp)
.L7F0C9294:
/* 0FDDC4 7F0C9294 8FA70060 */  lw    $a3, 0x60($sp)
.L7F0C9298:
/* 0FDDC8 7F0C9298 8FA90064 */  lw    $t1, 0x64($sp)
/* 0FDDCC 7F0C929C 24110001 */  li    $s1, 1
/* 0FDDD0 7F0C92A0 AFA70060 */  sw    $a3, 0x60($sp)
/* 0FDDD4 7F0C92A4 12340031 */  beq   $s1, $s4, .L7F0C936C
/* 0FDDD8 7F0C92A8 AFA90064 */   sw    $t1, 0x64($sp)
.L7F0C92AC:
/* 0FDDDC 7F0C92AC 00117040 */  sll   $t6, $s1, 1
/* 0FDDE0 7F0C92B0 01CF8021 */  addu  $s0, $t6, $t7
/* 0FDDE4 7F0C92B4 8FA70060 */  lw    $a3, 0x60($sp)
/* 0FDDE8 7F0C92B8 8FA90064 */  lw    $t1, 0x64($sp)
.L7F0C92BC:
/* 0FDDEC 7F0C92BC 96030000 */  lhu   $v1, ($s0)
/* 0FDDF0 7F0C92C0 01002825 */  move  $a1, $t0
/* 0FDDF4 7F0C92C4 00C02025 */  move  $a0, $a2
/* 0FDDF8 7F0C92C8 0068082A */  slt   $at, $v1, $t0
/* 0FDDFC 7F0C92CC 1020000C */  beqz  $at, .L7F0C9300
/* 0FDE00 7F0C92D0 00601025 */   move  $v0, $v1
/* 0FDE04 7F0C92D4 0085082A */  slt   $at, $a0, $a1
/* 0FDE08 7F0C92D8 50200006 */  beql  $at, $zero, .L7F0C92F4
/* 0FDE0C 7F0C92DC 3066FFFF */   andi  $a2, $v1, 0xffff
/* 0FDE10 7F0C92E0 3068FFFF */  andi  $t0, $v1, 0xffff
/* 0FDE14 7F0C92E4 01002825 */  move  $a1, $t0
/* 0FDE18 7F0C92E8 1000000B */  b     .L7F0C9318
/* 0FDE1C 7F0C92EC 02204825 */   move  $t1, $s1
/* 0FDE20 7F0C92F0 3066FFFF */  andi  $a2, $v1, 0xffff
.L7F0C92F4:
/* 0FDE24 7F0C92F4 00C02025 */  move  $a0, $a2
/* 0FDE28 7F0C92F8 10000007 */  b     .L7F0C9318
/* 0FDE2C 7F0C92FC 02203825 */   move  $a3, $s1
.L7F0C9300:
/* 0FDE30 7F0C9300 0044082A */  slt   $at, $v0, $a0
/* 0FDE34 7F0C9304 50200005 */  beql  $at, $zero, .L7F0C931C
/* 0FDE38 7F0C9308 96030002 */   lhu   $v1, 2($s0)
/* 0FDE3C 7F0C930C 3066FFFF */  andi  $a2, $v1, 0xffff
/* 0FDE40 7F0C9310 00C02025 */  move  $a0, $a2
/* 0FDE44 7F0C9314 02203825 */  move  $a3, $s1
.L7F0C9318:
/* 0FDE48 7F0C9318 96030002 */  lhu   $v1, 2($s0)
.L7F0C931C:
/* 0FDE4C 7F0C931C 0065082A */  slt   $at, $v1, $a1
/* 0FDE50 7F0C9320 1020000A */  beqz  $at, .L7F0C934C
/* 0FDE54 7F0C9324 00601025 */   move  $v0, $v1
/* 0FDE58 7F0C9328 0085082A */  slt   $at, $a0, $a1
/* 0FDE5C 7F0C932C 50200005 */  beql  $at, $zero, .L7F0C9344
/* 0FDE60 7F0C9330 3066FFFF */   andi  $a2, $v1, 0xffff
/* 0FDE64 7F0C9334 3068FFFF */  andi  $t0, $v1, 0xffff
/* 0FDE68 7F0C9338 10000009 */  b     .L7F0C9360
/* 0FDE6C 7F0C933C 26290001 */   addiu $t1, $s1, 1
/* 0FDE70 7F0C9340 3066FFFF */  andi  $a2, $v1, 0xffff
.L7F0C9344:
/* 0FDE74 7F0C9344 10000006 */  b     .L7F0C9360
/* 0FDE78 7F0C9348 26270001 */   addiu $a3, $s1, 1
.L7F0C934C:
/* 0FDE7C 7F0C934C 0044082A */  slt   $at, $v0, $a0
/* 0FDE80 7F0C9350 50200004 */  beql  $at, $zero, .L7F0C9364
/* 0FDE84 7F0C9354 26310002 */   addiu $s1, $s1, 2
/* 0FDE88 7F0C9358 3066FFFF */  andi  $a2, $v1, 0xffff
/* 0FDE8C 7F0C935C 26270001 */  addiu $a3, $s1, 1
.L7F0C9360:
/* 0FDE90 7F0C9360 26310002 */  addiu $s1, $s1, 2
.L7F0C9364:
/* 0FDE94 7F0C9364 1634FFD5 */  bne   $s1, $s4, .L7F0C92BC
/* 0FDE98 7F0C9368 26100004 */   addiu $s0, $s0, 4
.L7F0C936C:
/* 0FDE9C 7F0C936C 00008825 */  move  $s1, $zero
/* 0FDEA0 7F0C9370 AFA70060 */  sw    $a3, 0x60($sp)
/* 0FDEA4 7F0C9374 AFA90064 */  sw    $t1, 0x64($sp)
.L7F0C9378:
/* 0FDEA8 7F0C9378 8FA70060 */  lw    $a3, 0x60($sp)
/* 0FDEAC 7F0C937C 8FA90064 */  lw    $t1, 0x64($sp)
/* 0FDEB0 7F0C9380 27B30078 */  addiu $s3, $sp, 0x78
/* 0FDEB4 7F0C9384 240D270F */  li    $t5, 9999
/* 0FDEB8 7F0C9388 240C270F */  li    $t4, 9999
/* 0FDEBC 7F0C938C 27AB2078 */  addiu $t3, $sp, 0x2078
/* 0FDEC0 7F0C9390 0007C040 */  sll   $t8, $a3, 1
.L7F0C9394:
/* 0FDEC4 7F0C9394 0009C840 */  sll   $t9, $t1, 1
/* 0FDEC8 7F0C9398 01791021 */  addu  $v0, $t3, $t9
/* 0FDECC 7F0C939C 01782821 */  addu  $a1, $t3, $t8
/* 0FDED0 7F0C93A0 94AE0000 */  lhu   $t6, ($a1)
/* 0FDED4 7F0C93A4 944F0000 */  lhu   $t7, ($v0)
/* 0FDED8 7F0C93A8 0009C080 */  sll   $t8, $t1, 2
/* 0FDEDC 7F0C93AC 0007C880 */  sll   $t9, $a3, 2
/* 0FDEE0 7F0C93B0 01CF5021 */  addu  $t2, $t6, $t7
/* 0FDEE4 7F0C93B4 02792021 */  addu  $a0, $s3, $t9
/* 0FDEE8 7F0C93B8 02781821 */  addu  $v1, $s3, $t8
/* 0FDEEC 7F0C93BC 2408270F */  li    $t0, 9999
/* 0FDEF0 7F0C93C0 15400002 */  bnez  $t2, .L7F0C93CC
/* 0FDEF4 7F0C93C4 2406270F */   li    $a2, 9999
/* 0FDEF8 7F0C93C8 240A0001 */  li    $t2, 1
.L7F0C93CC:
/* 0FDEFC 7F0C93CC 846E0000 */  lh    $t6, ($v1)
/* 0FDF00 7F0C93D0 A44C0000 */  sh    $t4, ($v0)
/* 0FDF04 7F0C93D4 A4AC0000 */  sh    $t4, ($a1)
/* 0FDF08 7F0C93D8 05C30014 */  bgezl $t6, .L7F0C942C
/* 0FDF0C 7F0C93DC 84980000 */   lh    $t8, ($a0)
/* 0FDF10 7F0C93E0 846F0002 */  lh    $t7, 2($v1)
/* 0FDF14 7F0C93E4 25382710 */  addiu $t8, $t1, 0x2710
/* 0FDF18 7F0C93E8 05E30010 */  bgezl $t7, .L7F0C942C
/* 0FDF1C 7F0C93EC 84980000 */   lh    $t8, ($a0)
/* 0FDF20 7F0C93F0 A4780000 */  sh    $t8, ($v1)
/* 0FDF24 7F0C93F4 84990000 */  lh    $t9, ($a0)
/* 0FDF28 7F0C93F8 01209025 */  move  $s2, $t1
/* 0FDF2C 7F0C93FC A44A0000 */  sh    $t2, ($v0)
/* 0FDF30 7F0C9400 07210007 */  bgez  $t9, .L7F0C9420
/* 0FDF34 7F0C9404 00000000 */   nop   
/* 0FDF38 7F0C9408 848E0002 */  lh    $t6, 2($a0)
/* 0FDF3C 7F0C940C 24EF2710 */  addiu $t7, $a3, 0x2710
/* 0FDF40 7F0C9410 05C10003 */  bgez  $t6, .L7F0C9420
/* 0FDF44 7F0C9414 00000000 */   nop   
/* 0FDF48 7F0C9418 10000037 */  b     .L7F0C94F8
/* 0FDF4C 7F0C941C A46F0002 */   sh    $t7, 2($v1)
.L7F0C9420:
/* 0FDF50 7F0C9420 10000035 */  b     .L7F0C94F8
/* 0FDF54 7F0C9424 A4670002 */   sh    $a3, 2($v1)
/* 0FDF58 7F0C9428 84980000 */  lh    $t8, ($a0)
.L7F0C942C:
/* 0FDF5C 7F0C942C 87AE0078 */  lh    $t6, 0x78($sp)
/* 0FDF60 7F0C9430 07010013 */  bgez  $t8, .L7F0C9480
/* 0FDF64 7F0C9434 00000000 */   nop   
/* 0FDF68 7F0C9438 84990002 */  lh    $t9, 2($a0)
/* 0FDF6C 7F0C943C 07210010 */  bgez  $t9, .L7F0C9480
/* 0FDF70 7F0C9440 00000000 */   nop   
/* 0FDF74 7F0C9444 24EE2710 */  addiu $t6, $a3, 0x2710
/* 0FDF78 7F0C9448 A48E0000 */  sh    $t6, ($a0)
/* 0FDF7C 7F0C944C 846F0000 */  lh    $t7, ($v1)
/* 0FDF80 7F0C9450 00E09025 */  move  $s2, $a3
/* 0FDF84 7F0C9454 A4AA0000 */  sh    $t2, ($a1)
/* 0FDF88 7F0C9458 05E10007 */  bgez  $t7, .L7F0C9478
/* 0FDF8C 7F0C945C 00000000 */   nop   
/* 0FDF90 7F0C9460 84780002 */  lh    $t8, 2($v1)
/* 0FDF94 7F0C9464 25392710 */  addiu $t9, $t1, 0x2710
/* 0FDF98 7F0C9468 07010003 */  bgez  $t8, .L7F0C9478
/* 0FDF9C 7F0C946C 00000000 */   nop   
/* 0FDFA0 7F0C9470 10000021 */  b     .L7F0C94F8
/* 0FDFA4 7F0C9474 A4990002 */   sh    $t9, 2($a0)
.L7F0C9478:
/* 0FDFA8 7F0C9478 1000001F */  b     .L7F0C94F8
/* 0FDFAC 7F0C947C A4890002 */   sh    $t1, 2($a0)
.L7F0C9480:
/* 0FDFB0 7F0C9480 05C10009 */  bgez  $t6, .L7F0C94A8
/* 0FDFB4 7F0C9484 00009025 */   move  $s2, $zero
/* 0FDFB8 7F0C9488 00007880 */  sll   $t7, $zero, 2
/* 0FDFBC 7F0C948C 026F1021 */  addu  $v0, $s3, $t7
/* 0FDFC0 7F0C9490 84580002 */  lh    $t8, 2($v0)
/* 0FDFC4 7F0C9494 97B92078 */  lhu   $t9, 0x2078($sp)
/* 0FDFC8 7F0C9498 07010003 */  bgez  $t8, .L7F0C94A8
/* 0FDFCC 7F0C949C 2B21270F */   slti  $at, $t9, 0x270f
/* 0FDFD0 7F0C94A0 50200011 */  beql  $at, $zero, .L7F0C94E8
/* 0FDFD4 7F0C94A4 0012C040 */   sll   $t8, $s2, 1
.L7F0C94A8:
/* 0FDFD8 7F0C94A8 26520001 */  addiu $s2, $s2, 1
.L7F0C94AC:
/* 0FDFDC 7F0C94AC 00127080 */  sll   $t6, $s2, 2
/* 0FDFE0 7F0C94B0 026E1021 */  addu  $v0, $s3, $t6
/* 0FDFE4 7F0C94B4 844F0000 */  lh    $t7, ($v0)
/* 0FDFE8 7F0C94B8 05E3FFFC */  bgezl $t7, .L7F0C94AC
/* 0FDFEC 7F0C94BC 26520001 */   addiu $s2, $s2, 1
/* 0FDFF0 7F0C94C0 84580002 */  lh    $t8, 2($v0)
/* 0FDFF4 7F0C94C4 0703FFF9 */  bgezl $t8, .L7F0C94AC
/* 0FDFF8 7F0C94C8 26520001 */   addiu $s2, $s2, 1
/* 0FDFFC 7F0C94CC 0012C840 */  sll   $t9, $s2, 1
/* 0FE000 7F0C94D0 01797021 */  addu  $t6, $t3, $t9
/* 0FE004 7F0C94D4 95CF0000 */  lhu   $t7, ($t6)
/* 0FE008 7F0C94D8 29E1270F */  slti  $at, $t7, 0x270f
/* 0FE00C 7F0C94DC 5420FFF3 */  bnezl $at, .L7F0C94AC
/* 0FE010 7F0C94E0 26520001 */   addiu $s2, $s2, 1
/* 0FE014 7F0C94E4 0012C040 */  sll   $t8, $s2, 1
.L7F0C94E8:
/* 0FE018 7F0C94E8 0178C821 */  addu  $t9, $t3, $t8
/* 0FE01C 7F0C94EC A72A0000 */  sh    $t2, ($t9)
/* 0FE020 7F0C94F0 A4490000 */  sh    $t1, ($v0)
/* 0FE024 7F0C94F4 A4470002 */  sh    $a3, 2($v0)
.L7F0C94F8:
/* 0FE028 7F0C94F8 1A800040 */  blez  $s4, .L7F0C95FC
/* 0FE02C 7F0C94FC 32820001 */   andi  $v0, $s4, 1
/* 0FE030 7F0C9500 50400010 */  beql  $v0, $zero, .L7F0C9544
/* 0FE034 7F0C9504 00117040 */   sll   $t6, $s1, 1
/* 0FE038 7F0C9508 97A22078 */  lhu   $v0, 0x2078($sp)
/* 0FE03C 7F0C950C 24110001 */  li    $s1, 1
/* 0FE040 7F0C9510 2841270F */  slti  $at, $v0, 0x270f
/* 0FE044 7F0C9514 50200005 */  beql  $at, $zero, .L7F0C952C
/* 0FE048 7F0C9518 2841270F */   slti  $at, $v0, 0x270f
/* 0FE04C 7F0C951C 3046FFFF */  andi  $a2, $v0, 0xffff
/* 0FE050 7F0C9520 10000006 */  b     .L7F0C953C
/* 0FE054 7F0C9524 00003825 */   move  $a3, $zero
/* 0FE058 7F0C9528 2841270F */  slti  $at, $v0, 0x270f
.L7F0C952C:
/* 0FE05C 7F0C952C 10200003 */  beqz  $at, .L7F0C953C
/* 0FE060 7F0C9530 00000000 */   nop   
/* 0FE064 7F0C9534 97A62078 */  lhu   $a2, 0x2078($sp)
/* 0FE068 7F0C9538 00003825 */  move  $a3, $zero
.L7F0C953C:
/* 0FE06C 7F0C953C 1234002E */  beq   $s1, $s4, .L7F0C95F8
/* 0FE070 7F0C9540 00117040 */   sll   $t6, $s1, 1
.L7F0C9544:
/* 0FE074 7F0C9544 016E8021 */  addu  $s0, $t3, $t6
.L7F0C9548:
/* 0FE078 7F0C9548 96030000 */  lhu   $v1, ($s0)
/* 0FE07C 7F0C954C 01002825 */  move  $a1, $t0
/* 0FE080 7F0C9550 00C02025 */  move  $a0, $a2
/* 0FE084 7F0C9554 0068082A */  slt   $at, $v1, $t0
/* 0FE088 7F0C9558 1020000C */  beqz  $at, .L7F0C958C
/* 0FE08C 7F0C955C 00601025 */   move  $v0, $v1
/* 0FE090 7F0C9560 0085082A */  slt   $at, $a0, $a1
/* 0FE094 7F0C9564 50200006 */  beql  $at, $zero, .L7F0C9580
/* 0FE098 7F0C9568 3066FFFF */   andi  $a2, $v1, 0xffff
/* 0FE09C 7F0C956C 3068FFFF */  andi  $t0, $v1, 0xffff
/* 0FE0A0 7F0C9570 01002825 */  move  $a1, $t0
/* 0FE0A4 7F0C9574 1000000B */  b     .L7F0C95A4
/* 0FE0A8 7F0C9578 02204825 */   move  $t1, $s1
/* 0FE0AC 7F0C957C 3066FFFF */  andi  $a2, $v1, 0xffff
.L7F0C9580:
/* 0FE0B0 7F0C9580 00C02025 */  move  $a0, $a2
/* 0FE0B4 7F0C9584 10000007 */  b     .L7F0C95A4
/* 0FE0B8 7F0C9588 02203825 */   move  $a3, $s1
.L7F0C958C:
/* 0FE0BC 7F0C958C 0044082A */  slt   $at, $v0, $a0
/* 0FE0C0 7F0C9590 50200005 */  beql  $at, $zero, .L7F0C95A8
/* 0FE0C4 7F0C9594 96030002 */   lhu   $v1, 2($s0)
/* 0FE0C8 7F0C9598 3066FFFF */  andi  $a2, $v1, 0xffff
/* 0FE0CC 7F0C959C 00C02025 */  move  $a0, $a2
/* 0FE0D0 7F0C95A0 02203825 */  move  $a3, $s1
.L7F0C95A4:
/* 0FE0D4 7F0C95A4 96030002 */  lhu   $v1, 2($s0)
.L7F0C95A8:
/* 0FE0D8 7F0C95A8 0065082A */  slt   $at, $v1, $a1
/* 0FE0DC 7F0C95AC 1020000A */  beqz  $at, .L7F0C95D8
/* 0FE0E0 7F0C95B0 00601025 */   move  $v0, $v1
/* 0FE0E4 7F0C95B4 0085082A */  slt   $at, $a0, $a1
/* 0FE0E8 7F0C95B8 50200005 */  beql  $at, $zero, .L7F0C95D0
/* 0FE0EC 7F0C95BC 3066FFFF */   andi  $a2, $v1, 0xffff
/* 0FE0F0 7F0C95C0 3068FFFF */  andi  $t0, $v1, 0xffff
/* 0FE0F4 7F0C95C4 10000009 */  b     .L7F0C95EC
/* 0FE0F8 7F0C95C8 26290001 */   addiu $t1, $s1, 1
/* 0FE0FC 7F0C95CC 3066FFFF */  andi  $a2, $v1, 0xffff
.L7F0C95D0:
/* 0FE100 7F0C95D0 10000006 */  b     .L7F0C95EC
/* 0FE104 7F0C95D4 26270001 */   addiu $a3, $s1, 1
.L7F0C95D8:
/* 0FE108 7F0C95D8 0044082A */  slt   $at, $v0, $a0
/* 0FE10C 7F0C95DC 50200004 */  beql  $at, $zero, .L7F0C95F0
/* 0FE110 7F0C95E0 26310002 */   addiu $s1, $s1, 2
/* 0FE114 7F0C95E4 3066FFFF */  andi  $a2, $v1, 0xffff
/* 0FE118 7F0C95E8 26270001 */  addiu $a3, $s1, 1
.L7F0C95EC:
/* 0FE11C 7F0C95EC 26310002 */  addiu $s1, $s1, 2
.L7F0C95F0:
/* 0FE120 7F0C95F0 1634FFD5 */  bne   $s1, $s4, .L7F0C9548
/* 0FE124 7F0C95F4 26100004 */   addiu $s0, $s0, 4
.L7F0C95F8:
/* 0FE128 7F0C95F8 00008825 */  move  $s1, $zero
.L7F0C95FC:
/* 0FE12C 7F0C95FC 51A80004 */  beql  $t5, $t0, .L7F0C9610
/* 0FE130 7F0C9600 241F0001 */   li    $ra, 1
/* 0FE134 7F0C9604 15A60002 */  bne   $t5, $a2, .L7F0C9610
/* 0FE138 7F0C9608 00000000 */   nop   
/* 0FE13C 7F0C960C 241F0001 */  li    $ra, 1
.L7F0C9610:
/* 0FE140 7F0C9610 53E0FF60 */  beql  $ra, $zero, .L7F0C9394
/* 0FE144 7F0C9614 0007C040 */   sll   $t8, $a3, 1
/* 0FE148 7F0C9618 8FAF307C */  lw    $t7, 0x307c($sp)
/* 0FE14C 7F0C961C AFB20070 */  sw    $s2, 0x70($sp)
/* 0FE150 7F0C9620 27B30078 */  addiu $s3, $sp, 0x78
/* 0FE154 7F0C9624 19E0001D */  blez  $t7, .L7F0C969C
/* 0FE158 7F0C9628 8FA23078 */   lw    $v0, 0x3078($sp)
/* 0FE15C 7F0C962C 2A412710 */  slti  $at, $s2, 0x2710
.L7F0C9630:
/* 0FE160 7F0C9630 1020000C */  beqz  $at, .L7F0C9664
/* 0FE164 7F0C9634 02408025 */   move  $s0, $s2
.L7F0C9638:
/* 0FE168 7F0C9638 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE16C 7F0C963C 24040001 */   li    $a0, 1
/* 0FE170 7F0C9640 0010C080 */  sll   $t8, $s0, 2
/* 0FE174 7F0C9644 0278C821 */  addu  $t9, $s3, $t8
/* 0FE178 7F0C9648 00027040 */  sll   $t6, $v0, 1
/* 0FE17C 7F0C964C 032E7821 */  addu  $t7, $t9, $t6
/* 0FE180 7F0C9650 85F00000 */  lh    $s0, ($t7)
/* 0FE184 7F0C9654 2A012710 */  slti  $at, $s0, 0x2710
/* 0FE188 7F0C9658 1420FFF7 */  bnez  $at, .L7F0C9638
/* 0FE18C 7F0C965C 00000000 */   nop   
/* 0FE190 7F0C9660 8FA23078 */  lw    $v0, 0x3078($sp)
.L7F0C9664:
/* 0FE194 7F0C9664 2A810101 */  slti  $at, $s4, 0x101
/* 0FE198 7F0C9668 10200005 */  beqz  $at, .L7F0C9680
/* 0FE19C 7F0C966C 260ED8F0 */   addiu $t6, $s0, -0x2710
/* 0FE1A0 7F0C9670 2618D8F0 */  addiu $t8, $s0, -0x2710
/* 0FE1A4 7F0C9674 0051C821 */  addu  $t9, $v0, $s1
/* 0FE1A8 7F0C9678 10000004 */  b     .L7F0C968C
/* 0FE1AC 7F0C967C A3380000 */   sb    $t8, ($t9)
.L7F0C9680:
/* 0FE1B0 7F0C9680 00117840 */  sll   $t7, $s1, 1
/* 0FE1B4 7F0C9684 004FC021 */  addu  $t8, $v0, $t7
/* 0FE1B8 7F0C9688 A70E0000 */  sh    $t6, ($t8)
.L7F0C968C:
/* 0FE1BC 7F0C968C 8FB9307C */  lw    $t9, 0x307c($sp)
/* 0FE1C0 7F0C9690 26310001 */  addiu $s1, $s1, 1
/* 0FE1C4 7F0C9694 5639FFE6 */  bnel  $s1, $t9, .L7F0C9630
/* 0FE1C8 7F0C9698 2A412710 */   slti  $at, $s2, 0x2710
.L7F0C969C:
/* 0FE1CC 7F0C969C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0FE1D0 7F0C96A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FE1D4 7F0C96A4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FE1D8 7F0C96A8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FE1DC 7F0C96AC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FE1E0 7F0C96B0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FE1E4 7F0C96B4 03E00008 */  jr    $ra
/* 0FE1E8 7F0C96B8 27BD3078 */   addiu $sp, $sp, 0x3078
)
#endif





#ifdef NONMATCHING
void type4_7_9_getsamples(void) {

}
#else
GLOBAL_ASM(
.text
glabel type4_7_9_getsamples
/* 0FE1EC 7F0C96BC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FE1F0 7F0C96C0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0FE1F4 7F0C96C4 00809025 */  move  $s2, $a0
/* 0FE1F8 7F0C96C8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0FE1FC 7F0C96CC AFB50028 */  sw    $s5, 0x28($sp)
/* 0FE200 7F0C96D0 AFB40024 */  sw    $s4, 0x24($sp)
/* 0FE204 7F0C96D4 AFB30020 */  sw    $s3, 0x20($sp)
/* 0FE208 7F0C96D8 AFB10018 */  sw    $s1, 0x18($sp)
/* 0FE20C 7F0C96DC AFB00014 */  sw    $s0, 0x14($sp)
/* 0FE210 7F0C96E0 AFA5003C */  sw    $a1, 0x3c($sp)
/* 0FE214 7F0C96E4 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE218 7F0C96E8 24040003 */   li    $a0, 3
/* 0FE21C 7F0C96EC AFA20034 */  sw    $v0, 0x34($sp)
/* 0FE220 7F0C96F0 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE224 7F0C96F4 24040003 */   li    $a0, 3
/* 0FE228 7F0C96F8 AFA20030 */  sw    $v0, 0x30($sp)
/* 0FE22C 7F0C96FC 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE230 7F0C9700 24040004 */   li    $a0, 4
/* 0FE234 7F0C9704 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0FE238 7F0C9708 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0FE23C 7F0C970C 0040A025 */  move  $s4, $v0
/* 0FE240 7F0C9710 0000A825 */  move  $s5, $zero
/* 0FE244 7F0C9714 01CFC021 */  addu  $t8, $t6, $t7
/* 0FE248 7F0C9718 03022021 */  addu  $a0, $t8, $v0
/* 0FE24C 7F0C971C 24830001 */  addiu $v1, $a0, 1
/* 0FE250 7F0C9720 18600005 */  blez  $v1, .L7F0C9738
/* 0FE254 7F0C9724 8FB9003C */   lw    $t9, 0x3c($sp)
.L7F0C9728:
/* 0FE258 7F0C9728 00621823 */  subu  $v1, $v1, $v0
/* 0FE25C 7F0C972C 2463FFFF */  addiu $v1, $v1, -1
/* 0FE260 7F0C9730 1C60FFFD */  bgtz  $v1, .L7F0C9728
/* 0FE264 7F0C9734 26B50001 */   addiu $s5, $s5, 1
.L7F0C9738:
/* 0FE268 7F0C9738 1B200070 */  blez  $t9, .L7F0C98FC
/* 0FE26C 7F0C973C 00008825 */   move  $s1, $zero
.L7F0C9740:
/* 0FE270 7F0C9740 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE274 7F0C9744 24040001 */   li    $a0, 1
/* 0FE278 7F0C9748 1440000F */  bnez  $v0, .L7F0C9788
/* 0FE27C 7F0C974C 2A810009 */   slti  $at, $s4, 9
/* 0FE280 7F0C9750 10200007 */  beqz  $at, .L7F0C9770
/* 0FE284 7F0C9754 02802025 */   move  $a0, $s4
/* 0FE288 7F0C9758 02802025 */  move  $a0, $s4
/* 0FE28C 7F0C975C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE290 7F0C9760 02518021 */   addu  $s0, $s2, $s1
/* 0FE294 7F0C9764 A2020000 */  sb    $v0, ($s0)
/* 0FE298 7F0C9768 10000060 */  b     .L7F0C98EC
/* 0FE29C 7F0C976C 26310001 */   addiu $s1, $s1, 1
.L7F0C9770:
/* 0FE2A0 7F0C9770 00114040 */  sll   $t0, $s1, 1
/* 0FE2A4 7F0C9774 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE2A8 7F0C9778 02488021 */   addu  $s0, $s2, $t0
/* 0FE2AC 7F0C977C A6020000 */  sh    $v0, ($s0)
/* 0FE2B0 7F0C9780 1000005A */  b     .L7F0C98EC
/* 0FE2B4 7F0C9784 26310001 */   addiu $s1, $s1, 1
.L7F0C9788:
/* 0FE2B8 7F0C9788 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE2BC 7F0C978C 8FA40034 */   lw    $a0, 0x34($sp)
/* 0FE2C0 7F0C9790 02229823 */  subu  $s3, $s1, $v0
/* 0FE2C4 7F0C9794 2673FFFF */  addiu $s3, $s3, -1
/* 0FE2C8 7F0C9798 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE2CC 7F0C979C 8FA40030 */   lw    $a0, 0x30($sp)
/* 0FE2D0 7F0C97A0 00552021 */  addu  $a0, $v0, $s5
/* 0FE2D4 7F0C97A4 2A810009 */  slti  $at, $s4, 9
/* 0FE2D8 7F0C97A8 10200027 */  beqz  $at, .L7F0C9848
/* 0FE2DC 7F0C97AC 00803825 */   move  $a3, $a0
/* 0FE2E0 7F0C97B0 02643021 */  addu  $a2, $s3, $a0
/* 0FE2E4 7F0C97B4 0266082A */  slt   $at, $s3, $a2
/* 0FE2E8 7F0C97B8 02601825 */  move  $v1, $s3
/* 0FE2EC 7F0C97BC 1020001D */  beqz  $at, .L7F0C9834
/* 0FE2F0 7F0C97C0 02518021 */   addu  $s0, $s2, $s1
/* 0FE2F4 7F0C97C4 00D32823 */  subu  $a1, $a2, $s3
/* 0FE2F8 7F0C97C8 30A90003 */  andi  $t1, $a1, 3
/* 0FE2FC 7F0C97CC 1120000A */  beqz  $t1, .L7F0C97F8
/* 0FE300 7F0C97D0 01332021 */   addu  $a0, $t1, $s3
/* 0FE304 7F0C97D4 02431021 */  addu  $v0, $s2, $v1
.L7F0C97D8:
/* 0FE308 7F0C97D8 904A0000 */  lbu   $t2, ($v0)
/* 0FE30C 7F0C97DC 24630001 */  addiu $v1, $v1, 1
/* 0FE310 7F0C97E0 26310001 */  addiu $s1, $s1, 1
/* 0FE314 7F0C97E4 26100001 */  addiu $s0, $s0, 1
/* 0FE318 7F0C97E8 24420001 */  addiu $v0, $v0, 1
/* 0FE31C 7F0C97EC 1483FFFA */  bne   $a0, $v1, .L7F0C97D8
/* 0FE320 7F0C97F0 A20AFFFF */   sb    $t2, -1($s0)
/* 0FE324 7F0C97F4 1066000F */  beq   $v1, $a2, .L7F0C9834
.L7F0C97F8:
/* 0FE328 7F0C97F8 02672021 */   addu  $a0, $s3, $a3
/* 0FE32C 7F0C97FC 02431021 */  addu  $v0, $s2, $v1
.L7F0C9800:
/* 0FE330 7F0C9800 904B0000 */  lbu   $t3, ($v0)
/* 0FE334 7F0C9804 24630004 */  addiu $v1, $v1, 4
/* 0FE338 7F0C9808 26310004 */  addiu $s1, $s1, 4
/* 0FE33C 7F0C980C A20B0000 */  sb    $t3, ($s0)
/* 0FE340 7F0C9810 904C0001 */  lbu   $t4, 1($v0)
/* 0FE344 7F0C9814 26100004 */  addiu $s0, $s0, 4
/* 0FE348 7F0C9818 24420004 */  addiu $v0, $v0, 4
/* 0FE34C 7F0C981C A20CFFFD */  sb    $t4, -3($s0)
/* 0FE350 7F0C9820 904DFFFE */  lbu   $t5, -2($v0)
/* 0FE354 7F0C9824 A20DFFFE */  sb    $t5, -2($s0)
/* 0FE358 7F0C9828 904EFFFF */  lbu   $t6, -1($v0)
/* 0FE35C 7F0C982C 1464FFF4 */  bne   $v1, $a0, .L7F0C9800
/* 0FE360 7F0C9830 A20EFFFF */   sb    $t6, -1($s0)
.L7F0C9834:
/* 0FE364 7F0C9834 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE368 7F0C9838 02802025 */   move  $a0, $s4
/* 0FE36C 7F0C983C A2020000 */  sb    $v0, ($s0)
/* 0FE370 7F0C9840 1000002A */  b     .L7F0C98EC
/* 0FE374 7F0C9844 26310001 */   addiu $s1, $s1, 1
.L7F0C9848:
/* 0FE378 7F0C9848 02643021 */  addu  $a2, $s3, $a0
/* 0FE37C 7F0C984C 0266082A */  slt   $at, $s3, $a2
/* 0FE380 7F0C9850 00117840 */  sll   $t7, $s1, 1
/* 0FE384 7F0C9854 024F8021 */  addu  $s0, $s2, $t7
/* 0FE388 7F0C9858 10200020 */  beqz  $at, .L7F0C98DC
/* 0FE38C 7F0C985C 02601825 */   move  $v1, $s3
/* 0FE390 7F0C9860 00D32823 */  subu  $a1, $a2, $s3
/* 0FE394 7F0C9864 30B80003 */  andi  $t8, $a1, 3
/* 0FE398 7F0C9868 1300000B */  beqz  $t8, .L7F0C9898
/* 0FE39C 7F0C986C 03132021 */   addu  $a0, $t8, $s3
/* 0FE3A0 7F0C9870 0003C840 */  sll   $t9, $v1, 1
/* 0FE3A4 7F0C9874 02591021 */  addu  $v0, $s2, $t9
.L7F0C9878:
/* 0FE3A8 7F0C9878 94480000 */  lhu   $t0, ($v0)
/* 0FE3AC 7F0C987C 24630001 */  addiu $v1, $v1, 1
/* 0FE3B0 7F0C9880 26310001 */  addiu $s1, $s1, 1
/* 0FE3B4 7F0C9884 26100002 */  addiu $s0, $s0, 2
/* 0FE3B8 7F0C9888 24420002 */  addiu $v0, $v0, 2
/* 0FE3BC 7F0C988C 1483FFFA */  bne   $a0, $v1, .L7F0C9878
/* 0FE3C0 7F0C9890 A608FFFE */   sh    $t0, -2($s0)
/* 0FE3C4 7F0C9894 10660011 */  beq   $v1, $a2, .L7F0C98DC
.L7F0C9898:
/* 0FE3C8 7F0C9898 02672021 */   addu  $a0, $s3, $a3
/* 0FE3CC 7F0C989C 00044840 */  sll   $t1, $a0, 1
/* 0FE3D0 7F0C98A0 00035040 */  sll   $t2, $v1, 1
/* 0FE3D4 7F0C98A4 024A1021 */  addu  $v0, $s2, $t2
/* 0FE3D8 7F0C98A8 01322821 */  addu  $a1, $t1, $s2
.L7F0C98AC:
/* 0FE3DC 7F0C98AC 944B0000 */  lhu   $t3, ($v0)
/* 0FE3E0 7F0C98B0 24420008 */  addiu $v0, $v0, 8
/* 0FE3E4 7F0C98B4 26310004 */  addiu $s1, $s1, 4
/* 0FE3E8 7F0C98B8 A60B0000 */  sh    $t3, ($s0)
/* 0FE3EC 7F0C98BC 944CFFFA */  lhu   $t4, -6($v0)
/* 0FE3F0 7F0C98C0 26100008 */  addiu $s0, $s0, 8
/* 0FE3F4 7F0C98C4 A60CFFFA */  sh    $t4, -6($s0)
/* 0FE3F8 7F0C98C8 944DFFFC */  lhu   $t5, -4($v0)
/* 0FE3FC 7F0C98CC A60DFFFC */  sh    $t5, -4($s0)
/* 0FE400 7F0C98D0 944EFFFE */  lhu   $t6, -2($v0)
/* 0FE404 7F0C98D4 1445FFF5 */  bne   $v0, $a1, .L7F0C98AC
/* 0FE408 7F0C98D8 A60EFFFE */   sh    $t6, -2($s0)
.L7F0C98DC:
/* 0FE40C 7F0C98DC 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE410 7F0C98E0 02802025 */   move  $a0, $s4
/* 0FE414 7F0C98E4 A6020000 */  sh    $v0, ($s0)
/* 0FE418 7F0C98E8 26310001 */  addiu $s1, $s1, 1
.L7F0C98EC:
/* 0FE41C 7F0C98EC 8FAF003C */  lw    $t7, 0x3c($sp)
/* 0FE420 7F0C98F0 022F082A */  slt   $at, $s1, $t7
/* 0FE424 7F0C98F4 1420FF92 */  bnez  $at, .L7F0C9740
/* 0FE428 7F0C98F8 00000000 */   nop   
.L7F0C98FC:
/* 0FE42C 7F0C98FC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0FE430 7F0C9900 8FB00014 */  lw    $s0, 0x14($sp)
/* 0FE434 7F0C9904 8FB10018 */  lw    $s1, 0x18($sp)
/* 0FE438 7F0C9908 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0FE43C 7F0C990C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0FE440 7F0C9910 8FB40024 */  lw    $s4, 0x24($sp)
/* 0FE444 7F0C9914 8FB50028 */  lw    $s5, 0x28($sp)
/* 0FE448 7F0C9918 03E00008 */  jr    $ra
/* 0FE44C 7F0C991C 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void type5_6_7_getsamples(void) {

}
#else
GLOBAL_ASM(
.text
glabel type5_6_7_getsamples
/* 0FE450 7F0C9920 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0FE454 7F0C9924 AFB30020 */  sw    $s3, 0x20($sp)
/* 0FE458 7F0C9928 00809825 */  move  $s3, $a0
/* 0FE45C 7F0C992C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0FE460 7F0C9930 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0FE464 7F0C9934 00A09025 */  move  $s2, $a1
/* 0FE468 7F0C9938 AFB50028 */  sw    $s5, 0x28($sp)
/* 0FE46C 7F0C993C AFB40024 */  sw    $s4, 0x24($sp)
/* 0FE470 7F0C9940 AFB10018 */  sw    $s1, 0x18($sp)
/* 0FE474 7F0C9944 AFB00014 */  sw    $s0, 0x14($sp)
/* 0FE478 7F0C9948 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE47C 7F0C994C 2404000B */   li    $a0, 11
/* 0FE480 7F0C9950 2A410011 */  slti  $at, $s2, 0x11
/* 0FE484 7F0C9954 1020000C */  beqz  $at, .L7F0C9988
/* 0FE488 7F0C9958 0040A825 */   move  $s5, $v0
/* 0FE48C 7F0C995C 18400027 */  blez  $v0, .L7F0C99FC
/* 0FE490 7F0C9960 00008025 */   move  $s0, $zero
/* 0FE494 7F0C9964 02608825 */  move  $s1, $s3
.L7F0C9968:
/* 0FE498 7F0C9968 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE49C 7F0C996C 02402025 */   move  $a0, $s2
/* 0FE4A0 7F0C9970 26100001 */  addiu $s0, $s0, 1
/* 0FE4A4 7F0C9974 26310002 */  addiu $s1, $s1, 2
/* 0FE4A8 7F0C9978 1615FFFB */  bne   $s0, $s5, .L7F0C9968
/* 0FE4AC 7F0C997C A622FFFE */   sh    $v0, -2($s1)
/* 0FE4B0 7F0C9980 1000001F */  b     .L7F0C9A00
/* 0FE4B4 7F0C9984 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F0C9988:
/* 0FE4B8 7F0C9988 2A410019 */  slti  $at, $s2, 0x19
/* 0FE4BC 7F0C998C 1020000C */  beqz  $at, .L7F0C99C0
/* 0FE4C0 7F0C9990 00000000 */   nop   
/* 0FE4C4 7F0C9994 18400019 */  blez  $v0, .L7F0C99FC
/* 0FE4C8 7F0C9998 00008025 */   move  $s0, $zero
/* 0FE4CC 7F0C999C 02608825 */  move  $s1, $s3
.L7F0C99A0:
/* 0FE4D0 7F0C99A0 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE4D4 7F0C99A4 02402025 */   move  $a0, $s2
/* 0FE4D8 7F0C99A8 26100001 */  addiu $s0, $s0, 1
/* 0FE4DC 7F0C99AC 26310004 */  addiu $s1, $s1, 4
/* 0FE4E0 7F0C99B0 1615FFFB */  bne   $s0, $s5, .L7F0C99A0
/* 0FE4E4 7F0C99B4 AE22FFFC */   sw    $v0, -4($s1)
/* 0FE4E8 7F0C99B8 10000011 */  b     .L7F0C9A00
/* 0FE4EC 7F0C99BC 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F0C99C0:
/* 0FE4F0 7F0C99C0 1840000E */  blez  $v0, .L7F0C99FC
/* 0FE4F4 7F0C99C4 00008025 */   move  $s0, $zero
/* 0FE4F8 7F0C99C8 2654FFE8 */  addiu $s4, $s2, -0x18
/* 0FE4FC 7F0C99CC 02608825 */  move  $s1, $s3
.L7F0C99D0:
/* 0FE500 7F0C99D0 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE504 7F0C99D4 24040018 */   li    $a0, 24
/* 0FE508 7F0C99D8 00409025 */  move  $s2, $v0
/* 0FE50C 7F0C99DC 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE510 7F0C99E0 02802025 */   move  $a0, $s4
/* 0FE514 7F0C99E4 00127200 */  sll   $t6, $s2, 8
/* 0FE518 7F0C99E8 26100001 */  addiu $s0, $s0, 1
/* 0FE51C 7F0C99EC 004E7825 */  or    $t7, $v0, $t6
/* 0FE520 7F0C99F0 26310004 */  addiu $s1, $s1, 4
/* 0FE524 7F0C99F4 1615FFF6 */  bne   $s0, $s5, .L7F0C99D0
/* 0FE528 7F0C99F8 AE2FFFFC */   sw    $t7, -4($s1)
.L7F0C99FC:
/* 0FE52C 7F0C99FC 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F0C9A00:
/* 0FE530 7F0C9A00 02A01025 */  move  $v0, $s5
/* 0FE534 7F0C9A04 8FB50028 */  lw    $s5, 0x28($sp)
/* 0FE538 7F0C9A08 8FB00014 */  lw    $s0, 0x14($sp)
/* 0FE53C 7F0C9A0C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0FE540 7F0C9A10 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0FE544 7F0C9A14 8FB30020 */  lw    $s3, 0x20($sp)
/* 0FE548 7F0C9A18 8FB40024 */  lw    $s4, 0x24($sp)
/* 0FE54C 7F0C9A1C 03E00008 */  jr    $ra
/* 0FE550 7F0C9A20 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C9A24(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C9A24
/* 0FE554 7F0C9A24 2484FFFF */  addiu $a0, $a0, -1
/* 0FE558 7F0C9A28 18800005 */  blez  $a0, .L7F0C9A40
/* 0FE55C 7F0C9A2C 00001825 */   move  $v1, $zero
.L7F0C9A30:
/* 0FE560 7F0C9A30 00047043 */  sra   $t6, $a0, 1
/* 0FE564 7F0C9A34 01C02025 */  move  $a0, $t6
/* 0FE568 7F0C9A38 1DC0FFFD */  bgtz  $t6, .L7F0C9A30
/* 0FE56C 7F0C9A3C 24630001 */   addiu $v1, $v1, 1
.L7F0C9A40:
/* 0FE570 7F0C9A40 03E00008 */  jr    $ra
/* 0FE574 7F0C9A44 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void image_get_alpha_values(void) {

}
#else
GLOBAL_ASM(
.text
glabel image_get_alpha_values
/* 0FE578 7F0C9A48 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FE57C 7F0C9A4C AFB20020 */  sw    $s2, 0x20($sp)
/* 0FE580 7F0C9A50 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FE584 7F0C9A54 00A09025 */  move  $s2, $a1
/* 0FE588 7F0C9A58 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0FE58C 7F0C9A5C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FE590 7F0C9A60 18A00008 */  blez  $a1, .L7F0C9A84
/* 0FE594 7F0C9A64 00008025 */   move  $s0, $zero
/* 0FE598 7F0C9A68 00808825 */  move  $s1, $a0
.L7F0C9A6C:
/* 0FE59C 7F0C9A6C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE5A0 7F0C9A70 24040001 */   li    $a0, 1
/* 0FE5A4 7F0C9A74 26100001 */  addiu $s0, $s0, 1
/* 0FE5A8 7F0C9A78 26310001 */  addiu $s1, $s1, 1
/* 0FE5AC 7F0C9A7C 1612FFFB */  bne   $s0, $s2, .L7F0C9A6C
/* 0FE5B0 7F0C9A80 A222FFFF */   sb    $v0, -1($s1)
.L7F0C9A84:
/* 0FE5B4 7F0C9A84 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0FE5B8 7F0C9A88 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FE5BC 7F0C9A8C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FE5C0 7F0C9A90 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FE5C4 7F0C9A94 03E00008 */  jr    $ra
/* 0FE5C8 7F0C9A98 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void image_compression0_expand(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BDA0*/
glabel jpt_8005BDA0
.word .L7F0C9B0C
.word .L7F0C9BEC
.word .L7F0C9B84
.word .L7F0C9C4C
.word .L7F0C9BEC
.word .L7F0C9CB4
.word .L7F0C9D10
.word .L7F0C9CB4
.word .L7F0C9D10
.text
glabel image_compression0_expand
/* 0FE5CC 7F0C9A9C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FE5D0 7F0C9AA0 AFB50028 */  sw    $s5, 0x28($sp)
/* 0FE5D4 7F0C9AA4 2495000F */  addiu $s5, $a0, 0xf
/* 0FE5D8 7F0C9AA8 2401FFF0 */  li    $at, -16
/* 0FE5DC 7F0C9AAC 02A17024 */  and   $t6, $s5, $at
/* 0FE5E0 7F0C9AB0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0FE5E4 7F0C9AB4 2401FFF8 */  li    $at, -8
/* 0FE5E8 7F0C9AB8 24820007 */  addiu $v0, $a0, 7
/* 0FE5EC 7F0C9ABC 00419824 */  and   $s3, $v0, $at
/* 0FE5F0 7F0C9AC0 AFB70030 */  sw    $s7, 0x30($sp)
/* 0FE5F4 7F0C9AC4 AFB6002C */  sw    $s6, 0x2c($sp)
/* 0FE5F8 7F0C9AC8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0FE5FC 7F0C9ACC 2CE10009 */  sltiu $at, $a3, 9
/* 0FE600 7F0C9AD0 00A09025 */  move  $s2, $a1
/* 0FE604 7F0C9AD4 00C0B825 */  move  $s7, $a2
/* 0FE608 7F0C9AD8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0FE60C 7F0C9ADC AFB40024 */  sw    $s4, 0x24($sp)
/* 0FE610 7F0C9AE0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0FE614 7F0C9AE4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0FE618 7F0C9AE8 01C0A825 */  move  $s5, $t6
/* 0FE61C 7F0C9AEC 102000A1 */  beqz  $at, .L7F0C9D74
/* 0FE620 7F0C9AF0 0260B025 */   move  $s6, $s3
/* 0FE624 7F0C9AF4 0007C080 */  sll   $t8, $a3, 2
/* 0FE628 7F0C9AF8 3C018006 */  lui   $at, %hi(jpt_8005BDA0)
/* 0FE62C 7F0C9AFC 00380821 */  addu  $at, $at, $t8
/* 0FE630 7F0C9B00 8C38BDA0 */  lw    $t8, %lo(jpt_8005BDA0)($at)
/* 0FE634 7F0C9B04 03000008 */  jr    $t8
/* 0FE638 7F0C9B08 00000000 */   nop   
.L7F0C9B0C:
/* 0FE63C 7F0C9B0C 1AE00016 */  blez  $s7, .L7F0C9B68
/* 0FE640 7F0C9B10 0000A025 */   move  $s4, $zero
/* 0FE644 7F0C9B14 26530003 */  addiu $s3, $s2, 3
/* 0FE648 7F0C9B18 32790FFC */  andi  $t9, $s3, 0xffc
/* 0FE64C 7F0C9B1C 00199880 */  sll   $s3, $t9, 2
.L7F0C9B20:
/* 0FE650 7F0C9B20 1A40000E */  blez  $s2, .L7F0C9B5C
/* 0FE654 7F0C9B24 00008025 */   move  $s0, $zero
/* 0FE658 7F0C9B28 02A08825 */  move  $s1, $s5
.L7F0C9B2C:
/* 0FE65C 7F0C9B2C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE660 7F0C9B30 24040010 */   li    $a0, 16
/* 0FE664 7F0C9B34 00024C00 */  sll   $t1, $v0, 0x10
/* 0FE668 7F0C9B38 AE290000 */  sw    $t1, ($s1)
/* 0FE66C 7F0C9B3C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE670 7F0C9B40 24040010 */   li    $a0, 16
/* 0FE674 7F0C9B44 8E2A0000 */  lw    $t2, ($s1)
/* 0FE678 7F0C9B48 26100001 */  addiu $s0, $s0, 1
/* 0FE67C 7F0C9B4C 26310004 */  addiu $s1, $s1, 4
/* 0FE680 7F0C9B50 01425825 */  or    $t3, $t2, $v0
/* 0FE684 7F0C9B54 1612FFF5 */  bne   $s0, $s2, .L7F0C9B2C
/* 0FE688 7F0C9B58 AE2BFFFC */   sw    $t3, -4($s1)
.L7F0C9B5C:
/* 0FE68C 7F0C9B5C 26940001 */  addiu $s4, $s4, 1
/* 0FE690 7F0C9B60 1697FFEF */  bne   $s4, $s7, .L7F0C9B20
/* 0FE694 7F0C9B64 02B3A821 */   addu  $s5, $s5, $s3
.L7F0C9B68:
/* 0FE698 7F0C9B68 264C0003 */  addiu $t4, $s2, 3
/* 0FE69C 7F0C9B6C 318D0FFC */  andi  $t5, $t4, 0xffc
/* 0FE6A0 7F0C9B70 01B70019 */  multu $t5, $s7
/* 0FE6A4 7F0C9B74 00001012 */  mflo  $v0
/* 0FE6A8 7F0C9B78 00027080 */  sll   $t6, $v0, 2
/* 0FE6AC 7F0C9B7C 1000007E */  b     .L7F0C9D78
/* 0FE6B0 7F0C9B80 01C01025 */   move  $v0, $t6
.L7F0C9B84:
/* 0FE6B4 7F0C9B84 1AE00012 */  blez  $s7, .L7F0C9BD0
/* 0FE6B8 7F0C9B88 0000A025 */   move  $s4, $zero
/* 0FE6BC 7F0C9B8C 26530003 */  addiu $s3, $s2, 3
/* 0FE6C0 7F0C9B90 326F0FFC */  andi  $t7, $s3, 0xffc
/* 0FE6C4 7F0C9B94 000F9880 */  sll   $s3, $t7, 2
.L7F0C9B98:
/* 0FE6C8 7F0C9B98 1A40000A */  blez  $s2, .L7F0C9BC4
/* 0FE6CC 7F0C9B9C 00008025 */   move  $s0, $zero
/* 0FE6D0 7F0C9BA0 02A08825 */  move  $s1, $s5
.L7F0C9BA4:
/* 0FE6D4 7F0C9BA4 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE6D8 7F0C9BA8 24040018 */   li    $a0, 24
/* 0FE6DC 7F0C9BAC 0002CA00 */  sll   $t9, $v0, 8
/* 0FE6E0 7F0C9BB0 26100001 */  addiu $s0, $s0, 1
/* 0FE6E4 7F0C9BB4 372800FF */  ori   $t0, $t9, 0xff
/* 0FE6E8 7F0C9BB8 26310004 */  addiu $s1, $s1, 4
/* 0FE6EC 7F0C9BBC 1612FFF9 */  bne   $s0, $s2, .L7F0C9BA4
/* 0FE6F0 7F0C9BC0 AE28FFFC */   sw    $t0, -4($s1)
.L7F0C9BC4:
/* 0FE6F4 7F0C9BC4 26940001 */  addiu $s4, $s4, 1
/* 0FE6F8 7F0C9BC8 1697FFF3 */  bne   $s4, $s7, .L7F0C9B98
/* 0FE6FC 7F0C9BCC 02B3A821 */   addu  $s5, $s5, $s3
.L7F0C9BD0:
/* 0FE700 7F0C9BD0 26490003 */  addiu $t1, $s2, 3
/* 0FE704 7F0C9BD4 312A0FFC */  andi  $t2, $t1, 0xffc
/* 0FE708 7F0C9BD8 01570019 */  multu $t2, $s7
/* 0FE70C 7F0C9BDC 00001012 */  mflo  $v0
/* 0FE710 7F0C9BE0 00025880 */  sll   $t3, $v0, 2
/* 0FE714 7F0C9BE4 10000064 */  b     .L7F0C9D78
/* 0FE718 7F0C9BE8 01601025 */   move  $v0, $t3
.L7F0C9BEC:
/* 0FE71C 7F0C9BEC 1AE00010 */  blez  $s7, .L7F0C9C30
/* 0FE720 7F0C9BF0 0000A025 */   move  $s4, $zero
/* 0FE724 7F0C9BF4 26530003 */  addiu $s3, $s2, 3
/* 0FE728 7F0C9BF8 326C0FFC */  andi  $t4, $s3, 0xffc
/* 0FE72C 7F0C9BFC 000C9840 */  sll   $s3, $t4, 1
.L7F0C9C00:
/* 0FE730 7F0C9C00 1A400008 */  blez  $s2, .L7F0C9C24
/* 0FE734 7F0C9C04 00008025 */   move  $s0, $zero
/* 0FE738 7F0C9C08 02C08825 */  move  $s1, $s6
.L7F0C9C0C:
/* 0FE73C 7F0C9C0C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE740 7F0C9C10 24040010 */   li    $a0, 16
/* 0FE744 7F0C9C14 26100001 */  addiu $s0, $s0, 1
/* 0FE748 7F0C9C18 26310002 */  addiu $s1, $s1, 2
/* 0FE74C 7F0C9C1C 1612FFFB */  bne   $s0, $s2, .L7F0C9C0C
/* 0FE750 7F0C9C20 A622FFFE */   sh    $v0, -2($s1)
.L7F0C9C24:
/* 0FE754 7F0C9C24 26940001 */  addiu $s4, $s4, 1
/* 0FE758 7F0C9C28 1697FFF5 */  bne   $s4, $s7, .L7F0C9C00
/* 0FE75C 7F0C9C2C 02D3B021 */   addu  $s6, $s6, $s3
.L7F0C9C30:
/* 0FE760 7F0C9C30 264E0003 */  addiu $t6, $s2, 3
/* 0FE764 7F0C9C34 31CF0FFC */  andi  $t7, $t6, 0xffc
/* 0FE768 7F0C9C38 01F70019 */  multu $t7, $s7
/* 0FE76C 7F0C9C3C 00001012 */  mflo  $v0
/* 0FE770 7F0C9C40 0002C040 */  sll   $t8, $v0, 1
/* 0FE774 7F0C9C44 1000004C */  b     .L7F0C9D78
/* 0FE778 7F0C9C48 03001025 */   move  $v0, $t8
.L7F0C9C4C:
/* 0FE77C 7F0C9C4C 1AE00012 */  blez  $s7, .L7F0C9C98
/* 0FE780 7F0C9C50 0000A025 */   move  $s4, $zero
/* 0FE784 7F0C9C54 26530003 */  addiu $s3, $s2, 3
/* 0FE788 7F0C9C58 32790FFC */  andi  $t9, $s3, 0xffc
/* 0FE78C 7F0C9C5C 00199840 */  sll   $s3, $t9, 1
.L7F0C9C60:
/* 0FE790 7F0C9C60 1A40000A */  blez  $s2, .L7F0C9C8C
/* 0FE794 7F0C9C64 00008025 */   move  $s0, $zero
/* 0FE798 7F0C9C68 02C08825 */  move  $s1, $s6
.L7F0C9C6C:
/* 0FE79C 7F0C9C6C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE7A0 7F0C9C70 2404000F */   li    $a0, 15
/* 0FE7A4 7F0C9C74 00024840 */  sll   $t1, $v0, 1
/* 0FE7A8 7F0C9C78 26100001 */  addiu $s0, $s0, 1
/* 0FE7AC 7F0C9C7C 352A0001 */  ori   $t2, $t1, 1
/* 0FE7B0 7F0C9C80 26310002 */  addiu $s1, $s1, 2
/* 0FE7B4 7F0C9C84 1612FFF9 */  bne   $s0, $s2, .L7F0C9C6C
/* 0FE7B8 7F0C9C88 A62AFFFE */   sh    $t2, -2($s1)
.L7F0C9C8C:
/* 0FE7BC 7F0C9C8C 26940001 */  addiu $s4, $s4, 1
/* 0FE7C0 7F0C9C90 1697FFF3 */  bne   $s4, $s7, .L7F0C9C60
/* 0FE7C4 7F0C9C94 02D3B021 */   addu  $s6, $s6, $s3
.L7F0C9C98:
/* 0FE7C8 7F0C9C98 264B0003 */  addiu $t3, $s2, 3
/* 0FE7CC 7F0C9C9C 316C0FFC */  andi  $t4, $t3, 0xffc
/* 0FE7D0 7F0C9CA0 01970019 */  multu $t4, $s7
/* 0FE7D4 7F0C9CA4 00001012 */  mflo  $v0
/* 0FE7D8 7F0C9CA8 00026840 */  sll   $t5, $v0, 1
/* 0FE7DC 7F0C9CAC 10000032 */  b     .L7F0C9D78
/* 0FE7E0 7F0C9CB0 01A01025 */   move  $v0, $t5
.L7F0C9CB4:
/* 0FE7E4 7F0C9CB4 1AE00010 */  blez  $s7, .L7F0C9CF8
/* 0FE7E8 7F0C9CB8 0000A025 */   move  $s4, $zero
/* 0FE7EC 7F0C9CBC 26550007 */  addiu $s5, $s2, 7
/* 0FE7F0 7F0C9CC0 32AE0FF8 */  andi  $t6, $s5, 0xff8
/* 0FE7F4 7F0C9CC4 01C0A825 */  move  $s5, $t6
.L7F0C9CC8:
/* 0FE7F8 7F0C9CC8 1A400008 */  blez  $s2, .L7F0C9CEC
/* 0FE7FC 7F0C9CCC 00008025 */   move  $s0, $zero
/* 0FE800 7F0C9CD0 02608825 */  move  $s1, $s3
.L7F0C9CD4:
/* 0FE804 7F0C9CD4 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE808 7F0C9CD8 24040008 */   li    $a0, 8
/* 0FE80C 7F0C9CDC 26100001 */  addiu $s0, $s0, 1
/* 0FE810 7F0C9CE0 26310001 */  addiu $s1, $s1, 1
/* 0FE814 7F0C9CE4 1612FFFB */  bne   $s0, $s2, .L7F0C9CD4
/* 0FE818 7F0C9CE8 A222FFFF */   sb    $v0, -1($s1)
.L7F0C9CEC:
/* 0FE81C 7F0C9CEC 26940001 */  addiu $s4, $s4, 1
/* 0FE820 7F0C9CF0 1697FFF5 */  bne   $s4, $s7, .L7F0C9CC8
/* 0FE824 7F0C9CF4 02759821 */   addu  $s3, $s3, $s5
.L7F0C9CF8:
/* 0FE828 7F0C9CF8 264F0007 */  addiu $t7, $s2, 7
/* 0FE82C 7F0C9CFC 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 0FE830 7F0C9D00 03170019 */  multu $t8, $s7
/* 0FE834 7F0C9D04 00001012 */  mflo  $v0
/* 0FE838 7F0C9D08 1000001C */  b     .L7F0C9D7C
/* 0FE83C 7F0C9D0C 8FBF0034 */   lw    $ra, 0x34($sp)
.L7F0C9D10:
/* 0FE840 7F0C9D10 1AE00011 */  blez  $s7, .L7F0C9D58
/* 0FE844 7F0C9D14 0000A025 */   move  $s4, $zero
/* 0FE848 7F0C9D18 2651000F */  addiu $s1, $s2, 0xf
/* 0FE84C 7F0C9D1C 32390FF0 */  andi  $t9, $s1, 0xff0
/* 0FE850 7F0C9D20 00198843 */  sra   $s1, $t9, 1
.L7F0C9D24:
/* 0FE854 7F0C9D24 1A400009 */  blez  $s2, .L7F0C9D4C
/* 0FE858 7F0C9D28 00008025 */   move  $s0, $zero
.L7F0C9D2C:
/* 0FE85C 7F0C9D2C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FE860 7F0C9D30 24040008 */   li    $a0, 8
/* 0FE864 7F0C9D34 00104843 */  sra   $t1, $s0, 1
/* 0FE868 7F0C9D38 26100002 */  addiu $s0, $s0, 2
/* 0FE86C 7F0C9D3C 0212082A */  slt   $at, $s0, $s2
/* 0FE870 7F0C9D40 02695021 */  addu  $t2, $s3, $t1
/* 0FE874 7F0C9D44 1420FFF9 */  bnez  $at, .L7F0C9D2C
/* 0FE878 7F0C9D48 A1420000 */   sb    $v0, ($t2)
.L7F0C9D4C:
/* 0FE87C 7F0C9D4C 26940001 */  addiu $s4, $s4, 1
/* 0FE880 7F0C9D50 1697FFF4 */  bne   $s4, $s7, .L7F0C9D24
/* 0FE884 7F0C9D54 02719821 */   addu  $s3, $s3, $s1
.L7F0C9D58:
/* 0FE888 7F0C9D58 264B000F */  addiu $t3, $s2, 0xf
/* 0FE88C 7F0C9D5C 316C0FF0 */  andi  $t4, $t3, 0xff0
/* 0FE890 7F0C9D60 000C6843 */  sra   $t5, $t4, 1
/* 0FE894 7F0C9D64 01B70019 */  multu $t5, $s7
/* 0FE898 7F0C9D68 00001012 */  mflo  $v0
/* 0FE89C 7F0C9D6C 10000003 */  b     .L7F0C9D7C
/* 0FE8A0 7F0C9D70 8FBF0034 */   lw    $ra, 0x34($sp)
def_7F0C9B04:
.L7F0C9D74:
/* 0FE8A4 7F0C9D74 00001025 */  move  $v0, $zero
.L7F0C9D78:
/* 0FE8A8 7F0C9D78 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F0C9D7C:
/* 0FE8AC 7F0C9D7C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0FE8B0 7F0C9D80 8FB10018 */  lw    $s1, 0x18($sp)
/* 0FE8B4 7F0C9D84 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0FE8B8 7F0C9D88 8FB30020 */  lw    $s3, 0x20($sp)
/* 0FE8BC 7F0C9D8C 8FB40024 */  lw    $s4, 0x24($sp)
/* 0FE8C0 7F0C9D90 8FB50028 */  lw    $s5, 0x28($sp)
/* 0FE8C4 7F0C9D94 8FB6002C */  lw    $s6, 0x2c($sp)
/* 0FE8C8 7F0C9D98 8FB70030 */  lw    $s7, 0x30($sp)
/* 0FE8CC 7F0C9D9C 03E00008 */  jr    $ra
/* 0FE8D0 7F0C9DA0 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void generate_link_final_image(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BDC4*/
glabel jpt_8005BDC4
.word .L7F0C9DF8
.word .L7F0CA138
.word .L7F0C9FAC
.word .L7F0CA400
.word .L7F0CA2EC
.word .L7F0CA58C
.word .L7F0CA738
.word .L7F0CA68C
.word .L7F0CA7F0
.text
glabel generate_link_final_image
/* 0FE8D4 7F0C9DA4 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0FE8D8 7F0C9DA8 8FAE0078 */  lw    $t6, 0x78($sp)
/* 0FE8DC 7F0C9DAC AFB20010 */  sw    $s2, 0x10($sp)
/* 0FE8E0 7F0C9DB0 AFB1000C */  sw    $s1, 0xc($sp)
/* 0FE8E4 7F0C9DB4 AFB00008 */  sw    $s0, 8($sp)
/* 0FE8E8 7F0C9DB8 2DC10009 */  sltiu $at, $t6, 9
/* 0FE8EC 7F0C9DBC 00A08025 */  move  $s0, $a1
/* 0FE8F0 7F0C9DC0 00808825 */  move  $s1, $a0
/* 0FE8F4 7F0C9DC4 00C09025 */  move  $s2, $a2
/* 0FE8F8 7F0C9DC8 AFB30014 */  sw    $s3, 0x14($sp)
/* 0FE8FC 7F0C9DCC 00E05025 */  move  $t2, $a3
/* 0FE900 7F0C9DD0 00E04825 */  move  $t1, $a3
/* 0FE904 7F0C9DD4 00E01825 */  move  $v1, $a3
/* 0FE908 7F0C9DD8 102002A6 */  beqz  $at, .L7F0CA874
/* 0FE90C 7F0C9DDC 00004025 */   move  $t0, $zero
/* 0FE910 7F0C9DE0 000E7080 */  sll   $t6, $t6, 2
/* 0FE914 7F0C9DE4 3C018006 */  lui   $at, %hi(jpt_8005BDC4)
/* 0FE918 7F0C9DE8 002E0821 */  addu  $at, $at, $t6
/* 0FE91C 7F0C9DEC 8C2EBDC4 */  lw    $t6, %lo(jpt_8005BDC4)($at)
/* 0FE920 7F0C9DF0 01C00008 */  jr    $t6
/* 0FE924 7F0C9DF4 00000000 */   nop   
.L7F0C9DF8:
/* 0FE928 7F0C9DF8 1A400065 */  blez  $s2, .L7F0C9F90
/* 0FE92C 7F0C9DFC 00003825 */   move  $a3, $zero
/* 0FE930 7F0C9E00 260F0003 */  addiu $t7, $s0, 3
/* 0FE934 7F0C9E04 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FE938 7F0C9E08 0018C880 */  sll   $t9, $t8, 2
/* 0FE93C 7F0C9E0C AFB9001C */  sw    $t9, 0x1c($sp)
.L7F0C9E10:
/* 0FE940 7F0C9E10 1A00005B */  blez  $s0, .L7F0C9F80
/* 0FE944 7F0C9E14 00002825 */   move  $a1, $zero
/* 0FE948 7F0C9E18 02120019 */  multu $s0, $s2
/* 0FE94C 7F0C9E1C 02286021 */  addu  $t4, $s1, $t0
/* 0FE950 7F0C9E20 32060003 */  andi  $a2, $s0, 3
/* 0FE954 7F0C9E24 0000C880 */  sll   $t9, $zero, 2
/* 0FE958 7F0C9E28 01594821 */  addu  $t1, $t2, $t9
/* 0FE95C 7F0C9E2C 00C06825 */  move  $t5, $a2
/* 0FE960 7F0C9E30 02281021 */  addu  $v0, $s1, $t0
/* 0FE964 7F0C9E34 00005812 */  mflo  $t3
/* 0FE968 7F0C9E38 000B7080 */  sll   $t6, $t3, 2
/* 0FE96C 7F0C9E3C 01CB7023 */  subu  $t6, $t6, $t3
/* 0FE970 7F0C9E40 01C87821 */  addu  $t7, $t6, $t0
/* 0FE974 7F0C9E44 000BC040 */  sll   $t8, $t3, 1
/* 0FE978 7F0C9E48 01989821 */  addu  $s3, $t4, $t8
/* 0FE97C 7F0C9E4C 01F12021 */  addu  $a0, $t7, $s1
/* 0FE980 7F0C9E50 10C00015 */  beqz  $a2, .L7F0C9EA8
/* 0FE984 7F0C9E54 018B1821 */   addu  $v1, $t4, $t3
.L7F0C9E58:
/* 0FE988 7F0C9E58 904F0000 */  lbu   $t7, ($v0)
/* 0FE98C 7F0C9E5C 908E0000 */  lbu   $t6, ($a0)
/* 0FE990 7F0C9E60 24A50001 */  addiu $a1, $a1, 1
/* 0FE994 7F0C9E64 000FC600 */  sll   $t8, $t7, 0x18
/* 0FE998 7F0C9E68 906F0000 */  lbu   $t7, ($v1)
/* 0FE99C 7F0C9E6C 01D8C825 */  or    $t9, $t6, $t8
/* 0FE9A0 7F0C9E70 25080001 */  addiu $t0, $t0, 1
/* 0FE9A4 7F0C9E74 000F7400 */  sll   $t6, $t7, 0x10
/* 0FE9A8 7F0C9E78 926F0000 */  lbu   $t7, ($s3)
/* 0FE9AC 7F0C9E7C 032EC025 */  or    $t8, $t9, $t6
/* 0FE9B0 7F0C9E80 24420001 */  addiu $v0, $v0, 1
/* 0FE9B4 7F0C9E84 000FCA00 */  sll   $t9, $t7, 8
/* 0FE9B8 7F0C9E88 03197025 */  or    $t6, $t8, $t9
/* 0FE9BC 7F0C9E8C AD2E0000 */  sw    $t6, ($t1)
/* 0FE9C0 7F0C9E90 24840001 */  addiu $a0, $a0, 1
/* 0FE9C4 7F0C9E94 24630001 */  addiu $v1, $v1, 1
/* 0FE9C8 7F0C9E98 26730001 */  addiu $s3, $s3, 1
/* 0FE9CC 7F0C9E9C 15A5FFEE */  bne   $t5, $a1, .L7F0C9E58
/* 0FE9D0 7F0C9EA0 25290004 */   addiu $t1, $t1, 4
/* 0FE9D4 7F0C9EA4 10B00036 */  beq   $a1, $s0, .L7F0C9F80
.L7F0C9EA8:
/* 0FE9D8 7F0C9EA8 00057880 */   sll   $t7, $a1, 2
/* 0FE9DC 7F0C9EAC 014F4821 */  addu  $t1, $t2, $t7
.L7F0C9EB0:
/* 0FE9E0 7F0C9EB0 90590000 */  lbu   $t9, ($v0)
/* 0FE9E4 7F0C9EB4 90980000 */  lbu   $t8, ($a0)
/* 0FE9E8 7F0C9EB8 24A50004 */  addiu $a1, $a1, 4
/* 0FE9EC 7F0C9EBC 00197600 */  sll   $t6, $t9, 0x18
/* 0FE9F0 7F0C9EC0 90790000 */  lbu   $t9, ($v1)
/* 0FE9F4 7F0C9EC4 030E7825 */  or    $t7, $t8, $t6
/* 0FE9F8 7F0C9EC8 25080004 */  addiu $t0, $t0, 4
/* 0FE9FC 7F0C9ECC 0019C400 */  sll   $t8, $t9, 0x10
/* 0FEA00 7F0C9ED0 92790000 */  lbu   $t9, ($s3)
/* 0FEA04 7F0C9ED4 01F87025 */  or    $t6, $t7, $t8
/* 0FEA08 7F0C9ED8 24420004 */  addiu $v0, $v0, 4
/* 0FEA0C 7F0C9EDC 00197A00 */  sll   $t7, $t9, 8
/* 0FEA10 7F0C9EE0 01CFC025 */  or    $t8, $t6, $t7
/* 0FEA14 7F0C9EE4 AD380000 */  sw    $t8, ($t1)
/* 0FEA18 7F0C9EE8 904EFFFD */  lbu   $t6, -3($v0)
/* 0FEA1C 7F0C9EEC 90990001 */  lbu   $t9, 1($a0)
/* 0FEA20 7F0C9EF0 24840004 */  addiu $a0, $a0, 4
/* 0FEA24 7F0C9EF4 000E7E00 */  sll   $t7, $t6, 0x18
/* 0FEA28 7F0C9EF8 906E0001 */  lbu   $t6, 1($v1)
/* 0FEA2C 7F0C9EFC 032FC025 */  or    $t8, $t9, $t7
/* 0FEA30 7F0C9F00 24630004 */  addiu $v1, $v1, 4
/* 0FEA34 7F0C9F04 000ECC00 */  sll   $t9, $t6, 0x10
/* 0FEA38 7F0C9F08 926E0001 */  lbu   $t6, 1($s3)
/* 0FEA3C 7F0C9F0C 03197825 */  or    $t7, $t8, $t9
/* 0FEA40 7F0C9F10 26730004 */  addiu $s3, $s3, 4
/* 0FEA44 7F0C9F14 000EC200 */  sll   $t8, $t6, 8
/* 0FEA48 7F0C9F18 01F8C825 */  or    $t9, $t7, $t8
/* 0FEA4C 7F0C9F1C AD390004 */  sw    $t9, 4($t1)
/* 0FEA50 7F0C9F20 904FFFFE */  lbu   $t7, -2($v0)
/* 0FEA54 7F0C9F24 908EFFFE */  lbu   $t6, -2($a0)
/* 0FEA58 7F0C9F28 25290010 */  addiu $t1, $t1, 0x10
/* 0FEA5C 7F0C9F2C 000FC600 */  sll   $t8, $t7, 0x18
/* 0FEA60 7F0C9F30 906FFFFE */  lbu   $t7, -2($v1)
/* 0FEA64 7F0C9F34 01D8C825 */  or    $t9, $t6, $t8
/* 0FEA68 7F0C9F38 000F7400 */  sll   $t6, $t7, 0x10
/* 0FEA6C 7F0C9F3C 926FFFFE */  lbu   $t7, -2($s3)
/* 0FEA70 7F0C9F40 032EC025 */  or    $t8, $t9, $t6
/* 0FEA74 7F0C9F44 000FCA00 */  sll   $t9, $t7, 8
/* 0FEA78 7F0C9F48 03197025 */  or    $t6, $t8, $t9
/* 0FEA7C 7F0C9F4C AD2EFFF8 */  sw    $t6, -8($t1)
/* 0FEA80 7F0C9F50 9058FFFF */  lbu   $t8, -1($v0)
/* 0FEA84 7F0C9F54 908FFFFF */  lbu   $t7, -1($a0)
/* 0FEA88 7F0C9F58 0018CE00 */  sll   $t9, $t8, 0x18
/* 0FEA8C 7F0C9F5C 9078FFFF */  lbu   $t8, -1($v1)
/* 0FEA90 7F0C9F60 01F97025 */  or    $t6, $t7, $t9
/* 0FEA94 7F0C9F64 00187C00 */  sll   $t7, $t8, 0x10
/* 0FEA98 7F0C9F68 9278FFFF */  lbu   $t8, -1($s3)
/* 0FEA9C 7F0C9F6C 01CFC825 */  or    $t9, $t6, $t7
/* 0FEAA0 7F0C9F70 00187200 */  sll   $t6, $t8, 8
/* 0FEAA4 7F0C9F74 032E7825 */  or    $t7, $t9, $t6
/* 0FEAA8 7F0C9F78 14B0FFCD */  bne   $a1, $s0, .L7F0C9EB0
/* 0FEAAC 7F0C9F7C AD2FFFFC */   sw    $t7, -4($t1)
.L7F0C9F80:
/* 0FEAB0 7F0C9F80 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0FEAB4 7F0C9F84 24E70001 */  addiu $a3, $a3, 1
/* 0FEAB8 7F0C9F88 14F2FFA1 */  bne   $a3, $s2, .L7F0C9E10
/* 0FEABC 7F0C9F8C 01585021 */   addu  $t2, $t2, $t8
.L7F0C9F90:
/* 0FEAC0 7F0C9F90 26190003 */  addiu $t9, $s0, 3
/* 0FEAC4 7F0C9F94 332E0FFC */  andi  $t6, $t9, 0xffc
/* 0FEAC8 7F0C9F98 01D20019 */  multu $t6, $s2
/* 0FEACC 7F0C9F9C 00001012 */  mflo  $v0
/* 0FEAD0 7F0C9FA0 00027880 */  sll   $t7, $v0, 2
/* 0FEAD4 7F0C9FA4 10000234 */  b     .L7F0CA878
/* 0FEAD8 7F0C9FA8 01E01025 */   move  $v0, $t7
.L7F0C9FAC:
/* 0FEADC 7F0C9FAC 1A40005B */  blez  $s2, .L7F0CA11C
/* 0FEAE0 7F0C9FB0 00003825 */   move  $a3, $zero
/* 0FEAE4 7F0C9FB4 26180003 */  addiu $t8, $s0, 3
/* 0FEAE8 7F0C9FB8 33190FFC */  andi  $t9, $t8, 0xffc
/* 0FEAEC 7F0C9FBC 00197080 */  sll   $t6, $t9, 2
/* 0FEAF0 7F0C9FC0 AFAE001C */  sw    $t6, 0x1c($sp)
.L7F0C9FC4:
/* 0FEAF4 7F0C9FC4 1A000051 */  blez  $s0, .L7F0CA10C
/* 0FEAF8 7F0C9FC8 00002825 */   move  $a1, $zero
/* 0FEAFC 7F0C9FCC 02120019 */  multu $s0, $s2
/* 0FEB00 7F0C9FD0 02287821 */  addu  $t7, $s1, $t0
/* 0FEB04 7F0C9FD4 32060003 */  andi  $a2, $s0, 3
/* 0FEB08 7F0C9FD8 00007080 */  sll   $t6, $zero, 2
/* 0FEB0C 7F0C9FDC 014E4821 */  addu  $t1, $t2, $t6
/* 0FEB10 7F0C9FE0 00C02025 */  move  $a0, $a2
/* 0FEB14 7F0C9FE4 02281021 */  addu  $v0, $s1, $t0
/* 0FEB18 7F0C9FE8 00005812 */  mflo  $t3
/* 0FEB1C 7F0C9FEC 000BC040 */  sll   $t8, $t3, 1
/* 0FEB20 7F0C9FF0 0308C821 */  addu  $t9, $t8, $t0
/* 0FEB24 7F0C9FF4 03316021 */  addu  $t4, $t9, $s1
/* 0FEB28 7F0C9FF8 10C00013 */  beqz  $a2, .L7F0CA048
/* 0FEB2C 7F0C9FFC 01EB1821 */   addu  $v1, $t7, $t3
.L7F0CA000:
/* 0FEB30 7F0CA000 90590000 */  lbu   $t9, ($v0)
/* 0FEB34 7F0CA004 918F0000 */  lbu   $t7, ($t4)
/* 0FEB38 7F0CA008 24A50001 */  addiu $a1, $a1, 1
/* 0FEB3C 7F0CA00C 00197600 */  sll   $t6, $t9, 0x18
/* 0FEB40 7F0CA010 90790000 */  lbu   $t9, ($v1)
/* 0FEB44 7F0CA014 000FC200 */  sll   $t8, $t7, 8
/* 0FEB48 7F0CA018 030E7825 */  or    $t7, $t8, $t6
/* 0FEB4C 7F0CA01C 0019C400 */  sll   $t8, $t9, 0x10
/* 0FEB50 7F0CA020 01F87025 */  or    $t6, $t7, $t8
/* 0FEB54 7F0CA024 35D900FF */  ori   $t9, $t6, 0xff
/* 0FEB58 7F0CA028 AD390000 */  sw    $t9, ($t1)
/* 0FEB5C 7F0CA02C 25080001 */  addiu $t0, $t0, 1
/* 0FEB60 7F0CA030 24420001 */  addiu $v0, $v0, 1
/* 0FEB64 7F0CA034 24630001 */  addiu $v1, $v1, 1
/* 0FEB68 7F0CA038 258C0001 */  addiu $t4, $t4, 1
/* 0FEB6C 7F0CA03C 1485FFF0 */  bne   $a0, $a1, .L7F0CA000
/* 0FEB70 7F0CA040 25290004 */   addiu $t1, $t1, 4
/* 0FEB74 7F0CA044 10B00031 */  beq   $a1, $s0, .L7F0CA10C
.L7F0CA048:
/* 0FEB78 7F0CA048 00057880 */   sll   $t7, $a1, 2
/* 0FEB7C 7F0CA04C 014F4821 */  addu  $t1, $t2, $t7
.L7F0CA050:
/* 0FEB80 7F0CA050 90590000 */  lbu   $t9, ($v0)
/* 0FEB84 7F0CA054 91980000 */  lbu   $t8, ($t4)
/* 0FEB88 7F0CA058 24A50004 */  addiu $a1, $a1, 4
/* 0FEB8C 7F0CA05C 00197E00 */  sll   $t7, $t9, 0x18
/* 0FEB90 7F0CA060 90790000 */  lbu   $t9, ($v1)
/* 0FEB94 7F0CA064 00187200 */  sll   $t6, $t8, 8
/* 0FEB98 7F0CA068 01CFC025 */  or    $t8, $t6, $t7
/* 0FEB9C 7F0CA06C 00197400 */  sll   $t6, $t9, 0x10
/* 0FEBA0 7F0CA070 030E7825 */  or    $t7, $t8, $t6
/* 0FEBA4 7F0CA074 35F900FF */  ori   $t9, $t7, 0xff
/* 0FEBA8 7F0CA078 AD390000 */  sw    $t9, ($t1)
/* 0FEBAC 7F0CA07C 904F0001 */  lbu   $t7, 1($v0)
/* 0FEBB0 7F0CA080 91980001 */  lbu   $t8, 1($t4)
/* 0FEBB4 7F0CA084 25080004 */  addiu $t0, $t0, 4
/* 0FEBB8 7F0CA088 000FCE00 */  sll   $t9, $t7, 0x18
/* 0FEBBC 7F0CA08C 906F0001 */  lbu   $t7, 1($v1)
/* 0FEBC0 7F0CA090 00187200 */  sll   $t6, $t8, 8
/* 0FEBC4 7F0CA094 01D9C025 */  or    $t8, $t6, $t9
/* 0FEBC8 7F0CA098 000F7400 */  sll   $t6, $t7, 0x10
/* 0FEBCC 7F0CA09C 030EC825 */  or    $t9, $t8, $t6
/* 0FEBD0 7F0CA0A0 372F00FF */  ori   $t7, $t9, 0xff
/* 0FEBD4 7F0CA0A4 AD2F0004 */  sw    $t7, 4($t1)
/* 0FEBD8 7F0CA0A8 90590002 */  lbu   $t9, 2($v0)
/* 0FEBDC 7F0CA0AC 91980002 */  lbu   $t8, 2($t4)
/* 0FEBE0 7F0CA0B0 24420004 */  addiu $v0, $v0, 4
/* 0FEBE4 7F0CA0B4 00197E00 */  sll   $t7, $t9, 0x18
/* 0FEBE8 7F0CA0B8 90790002 */  lbu   $t9, 2($v1)
/* 0FEBEC 7F0CA0BC 00187200 */  sll   $t6, $t8, 8
/* 0FEBF0 7F0CA0C0 01CFC025 */  or    $t8, $t6, $t7
/* 0FEBF4 7F0CA0C4 00197400 */  sll   $t6, $t9, 0x10
/* 0FEBF8 7F0CA0C8 030E7825 */  or    $t7, $t8, $t6
/* 0FEBFC 7F0CA0CC 35F900FF */  ori   $t9, $t7, 0xff
/* 0FEC00 7F0CA0D0 AD390008 */  sw    $t9, 8($t1)
/* 0FEC04 7F0CA0D4 904FFFFF */  lbu   $t7, -1($v0)
/* 0FEC08 7F0CA0D8 91980003 */  lbu   $t8, 3($t4)
/* 0FEC0C 7F0CA0DC 24630004 */  addiu $v1, $v1, 4
/* 0FEC10 7F0CA0E0 000FCE00 */  sll   $t9, $t7, 0x18
/* 0FEC14 7F0CA0E4 906FFFFF */  lbu   $t7, -1($v1)
/* 0FEC18 7F0CA0E8 00187200 */  sll   $t6, $t8, 8
/* 0FEC1C 7F0CA0EC 01D9C025 */  or    $t8, $t6, $t9
/* 0FEC20 7F0CA0F0 000F7400 */  sll   $t6, $t7, 0x10
/* 0FEC24 7F0CA0F4 030EC825 */  or    $t9, $t8, $t6
/* 0FEC28 7F0CA0F8 372F00FF */  ori   $t7, $t9, 0xff
/* 0FEC2C 7F0CA0FC AD2F000C */  sw    $t7, 0xc($t1)
/* 0FEC30 7F0CA100 258C0004 */  addiu $t4, $t4, 4
/* 0FEC34 7F0CA104 14B0FFD2 */  bne   $a1, $s0, .L7F0CA050
/* 0FEC38 7F0CA108 25290010 */   addiu $t1, $t1, 0x10
.L7F0CA10C:
/* 0FEC3C 7F0CA10C 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0FEC40 7F0CA110 24E70001 */  addiu $a3, $a3, 1
/* 0FEC44 7F0CA114 14F2FFAB */  bne   $a3, $s2, .L7F0C9FC4
/* 0FEC48 7F0CA118 01585021 */   addu  $t2, $t2, $t8
.L7F0CA11C:
/* 0FEC4C 7F0CA11C 260E0003 */  addiu $t6, $s0, 3
/* 0FEC50 7F0CA120 31D90FFC */  andi  $t9, $t6, 0xffc
/* 0FEC54 7F0CA124 03320019 */  multu $t9, $s2
/* 0FEC58 7F0CA128 00001012 */  mflo  $v0
/* 0FEC5C 7F0CA12C 00027880 */  sll   $t7, $v0, 2
/* 0FEC60 7F0CA130 100001D1 */  b     .L7F0CA878
/* 0FEC64 7F0CA134 01E01025 */   move  $v0, $t7
.L7F0CA138:
/* 0FEC68 7F0CA138 1A400065 */  blez  $s2, .L7F0CA2D0
/* 0FEC6C 7F0CA13C 00003825 */   move  $a3, $zero
/* 0FEC70 7F0CA140 26180003 */  addiu $t8, $s0, 3
/* 0FEC74 7F0CA144 330E0FFC */  andi  $t6, $t8, 0xffc
/* 0FEC78 7F0CA148 000EC840 */  sll   $t9, $t6, 1
/* 0FEC7C 7F0CA14C AFB9001C */  sw    $t9, 0x1c($sp)
.L7F0CA150:
/* 0FEC80 7F0CA150 1A00005B */  blez  $s0, .L7F0CA2C0
/* 0FEC84 7F0CA154 00002825 */   move  $a1, $zero
/* 0FEC88 7F0CA158 02120019 */  multu $s0, $s2
/* 0FEC8C 7F0CA15C 02286021 */  addu  $t4, $s1, $t0
/* 0FEC90 7F0CA160 32060003 */  andi  $a2, $s0, 3
/* 0FEC94 7F0CA164 0000C840 */  sll   $t9, $zero, 1
/* 0FEC98 7F0CA168 01395021 */  addu  $t2, $t1, $t9
/* 0FEC9C 7F0CA16C 00C06825 */  move  $t5, $a2
/* 0FECA0 7F0CA170 02281021 */  addu  $v0, $s1, $t0
/* 0FECA4 7F0CA174 00005812 */  mflo  $t3
/* 0FECA8 7F0CA178 000B7880 */  sll   $t7, $t3, 2
/* 0FECAC 7F0CA17C 01EB7823 */  subu  $t7, $t7, $t3
/* 0FECB0 7F0CA180 01E8C021 */  addu  $t8, $t7, $t0
/* 0FECB4 7F0CA184 000B7040 */  sll   $t6, $t3, 1
/* 0FECB8 7F0CA188 018E9821 */  addu  $s3, $t4, $t6
/* 0FECBC 7F0CA18C 03112021 */  addu  $a0, $t8, $s1
/* 0FECC0 7F0CA190 10C00015 */  beqz  $a2, .L7F0CA1E8
/* 0FECC4 7F0CA194 018B1821 */   addu  $v1, $t4, $t3
.L7F0CA198:
/* 0FECC8 7F0CA198 90580000 */  lbu   $t8, ($v0)
/* 0FECCC 7F0CA19C 908F0000 */  lbu   $t7, ($a0)
/* 0FECD0 7F0CA1A0 24A50001 */  addiu $a1, $a1, 1
/* 0FECD4 7F0CA1A4 001872C0 */  sll   $t6, $t8, 0xb
/* 0FECD8 7F0CA1A8 90780000 */  lbu   $t8, ($v1)
/* 0FECDC 7F0CA1AC 01EEC825 */  or    $t9, $t7, $t6
/* 0FECE0 7F0CA1B0 25080001 */  addiu $t0, $t0, 1
/* 0FECE4 7F0CA1B4 00187980 */  sll   $t7, $t8, 6
/* 0FECE8 7F0CA1B8 92780000 */  lbu   $t8, ($s3)
/* 0FECEC 7F0CA1BC 032F7025 */  or    $t6, $t9, $t7
/* 0FECF0 7F0CA1C0 24420001 */  addiu $v0, $v0, 1
/* 0FECF4 7F0CA1C4 0018C840 */  sll   $t9, $t8, 1
/* 0FECF8 7F0CA1C8 01D97825 */  or    $t7, $t6, $t9
/* 0FECFC 7F0CA1CC A54F0000 */  sh    $t7, ($t2)
/* 0FED00 7F0CA1D0 24840001 */  addiu $a0, $a0, 1
/* 0FED04 7F0CA1D4 24630001 */  addiu $v1, $v1, 1
/* 0FED08 7F0CA1D8 26730001 */  addiu $s3, $s3, 1
/* 0FED0C 7F0CA1DC 15A5FFEE */  bne   $t5, $a1, .L7F0CA198
/* 0FED10 7F0CA1E0 254A0002 */   addiu $t2, $t2, 2
/* 0FED14 7F0CA1E4 10B00036 */  beq   $a1, $s0, .L7F0CA2C0
.L7F0CA1E8:
/* 0FED18 7F0CA1E8 0005C040 */   sll   $t8, $a1, 1
/* 0FED1C 7F0CA1EC 01385021 */  addu  $t2, $t1, $t8
.L7F0CA1F0:
/* 0FED20 7F0CA1F0 90590000 */  lbu   $t9, ($v0)
/* 0FED24 7F0CA1F4 908E0000 */  lbu   $t6, ($a0)
/* 0FED28 7F0CA1F8 24A50004 */  addiu $a1, $a1, 4
/* 0FED2C 7F0CA1FC 00197AC0 */  sll   $t7, $t9, 0xb
/* 0FED30 7F0CA200 90790000 */  lbu   $t9, ($v1)
/* 0FED34 7F0CA204 01CFC025 */  or    $t8, $t6, $t7
/* 0FED38 7F0CA208 25080004 */  addiu $t0, $t0, 4
/* 0FED3C 7F0CA20C 00197180 */  sll   $t6, $t9, 6
/* 0FED40 7F0CA210 92790000 */  lbu   $t9, ($s3)
/* 0FED44 7F0CA214 030E7825 */  or    $t7, $t8, $t6
/* 0FED48 7F0CA218 24420004 */  addiu $v0, $v0, 4
/* 0FED4C 7F0CA21C 0019C040 */  sll   $t8, $t9, 1
/* 0FED50 7F0CA220 01F87025 */  or    $t6, $t7, $t8
/* 0FED54 7F0CA224 A54E0000 */  sh    $t6, ($t2)
/* 0FED58 7F0CA228 904FFFFD */  lbu   $t7, -3($v0)
/* 0FED5C 7F0CA22C 90990001 */  lbu   $t9, 1($a0)
/* 0FED60 7F0CA230 24840004 */  addiu $a0, $a0, 4
/* 0FED64 7F0CA234 000FC2C0 */  sll   $t8, $t7, 0xb
/* 0FED68 7F0CA238 906F0001 */  lbu   $t7, 1($v1)
/* 0FED6C 7F0CA23C 03387025 */  or    $t6, $t9, $t8
/* 0FED70 7F0CA240 24630004 */  addiu $v1, $v1, 4
/* 0FED74 7F0CA244 000FC980 */  sll   $t9, $t7, 6
/* 0FED78 7F0CA248 926F0001 */  lbu   $t7, 1($s3)
/* 0FED7C 7F0CA24C 01D9C025 */  or    $t8, $t6, $t9
/* 0FED80 7F0CA250 26730004 */  addiu $s3, $s3, 4
/* 0FED84 7F0CA254 000F7040 */  sll   $t6, $t7, 1
/* 0FED88 7F0CA258 030EC825 */  or    $t9, $t8, $t6
/* 0FED8C 7F0CA25C A5590002 */  sh    $t9, 2($t2)
/* 0FED90 7F0CA260 9058FFFE */  lbu   $t8, -2($v0)
/* 0FED94 7F0CA264 908FFFFE */  lbu   $t7, -2($a0)
/* 0FED98 7F0CA268 254A0008 */  addiu $t2, $t2, 8
/* 0FED9C 7F0CA26C 001872C0 */  sll   $t6, $t8, 0xb
/* 0FEDA0 7F0CA270 9078FFFE */  lbu   $t8, -2($v1)
/* 0FEDA4 7F0CA274 01EEC825 */  or    $t9, $t7, $t6
/* 0FEDA8 7F0CA278 00187980 */  sll   $t7, $t8, 6
/* 0FEDAC 7F0CA27C 9278FFFE */  lbu   $t8, -2($s3)
/* 0FEDB0 7F0CA280 032F7025 */  or    $t6, $t9, $t7
/* 0FEDB4 7F0CA284 0018C840 */  sll   $t9, $t8, 1
/* 0FEDB8 7F0CA288 01D97825 */  or    $t7, $t6, $t9
/* 0FEDBC 7F0CA28C A54FFFFC */  sh    $t7, -4($t2)
/* 0FEDC0 7F0CA290 904EFFFF */  lbu   $t6, -1($v0)
/* 0FEDC4 7F0CA294 9098FFFF */  lbu   $t8, -1($a0)
/* 0FEDC8 7F0CA298 000ECAC0 */  sll   $t9, $t6, 0xb
/* 0FEDCC 7F0CA29C 906EFFFF */  lbu   $t6, -1($v1)
/* 0FEDD0 7F0CA2A0 03197825 */  or    $t7, $t8, $t9
/* 0FEDD4 7F0CA2A4 000EC180 */  sll   $t8, $t6, 6
/* 0FEDD8 7F0CA2A8 926EFFFF */  lbu   $t6, -1($s3)
/* 0FEDDC 7F0CA2AC 01F8C825 */  or    $t9, $t7, $t8
/* 0FEDE0 7F0CA2B0 000E7840 */  sll   $t7, $t6, 1
/* 0FEDE4 7F0CA2B4 032FC025 */  or    $t8, $t9, $t7
/* 0FEDE8 7F0CA2B8 14B0FFCD */  bne   $a1, $s0, .L7F0CA1F0
/* 0FEDEC 7F0CA2BC A558FFFE */   sh    $t8, -2($t2)
.L7F0CA2C0:
/* 0FEDF0 7F0CA2C0 8FAE001C */  lw    $t6, 0x1c($sp)
/* 0FEDF4 7F0CA2C4 24E70001 */  addiu $a3, $a3, 1
/* 0FEDF8 7F0CA2C8 14F2FFA1 */  bne   $a3, $s2, .L7F0CA150
/* 0FEDFC 7F0CA2CC 012E4821 */   addu  $t1, $t1, $t6
.L7F0CA2D0:
/* 0FEE00 7F0CA2D0 26190003 */  addiu $t9, $s0, 3
/* 0FEE04 7F0CA2D4 332F0FFC */  andi  $t7, $t9, 0xffc
/* 0FEE08 7F0CA2D8 01F20019 */  multu $t7, $s2
/* 0FEE0C 7F0CA2DC 00001012 */  mflo  $v0
/* 0FEE10 7F0CA2E0 0002C040 */  sll   $t8, $v0, 1
/* 0FEE14 7F0CA2E4 10000164 */  b     .L7F0CA878
/* 0FEE18 7F0CA2E8 03001025 */   move  $v0, $t8
.L7F0CA2EC:
/* 0FEE1C 7F0CA2EC 1A40003D */  blez  $s2, .L7F0CA3E4
/* 0FEE20 7F0CA2F0 00003825 */   move  $a3, $zero
/* 0FEE24 7F0CA2F4 260E0003 */  addiu $t6, $s0, 3
/* 0FEE28 7F0CA2F8 31D90FFC */  andi  $t9, $t6, 0xffc
/* 0FEE2C 7F0CA2FC 00197840 */  sll   $t7, $t9, 1
/* 0FEE30 7F0CA300 AFAF001C */  sw    $t7, 0x1c($sp)
.L7F0CA304:
/* 0FEE34 7F0CA304 1A000033 */  blez  $s0, .L7F0CA3D4
/* 0FEE38 7F0CA308 00002825 */   move  $a1, $zero
/* 0FEE3C 7F0CA30C 02120019 */  multu $s0, $s2
/* 0FEE40 7F0CA310 32060003 */  andi  $a2, $s0, 3
/* 0FEE44 7F0CA314 0000C840 */  sll   $t9, $zero, 1
/* 0FEE48 7F0CA318 01395021 */  addu  $t2, $t1, $t9
/* 0FEE4C 7F0CA31C 00C01825 */  move  $v1, $a2
/* 0FEE50 7F0CA320 02281021 */  addu  $v0, $s1, $t0
/* 0FEE54 7F0CA324 0000C012 */  mflo  $t8
/* 0FEE58 7F0CA328 01187021 */  addu  $t6, $t0, $t8
/* 0FEE5C 7F0CA32C 10C0000D */  beqz  $a2, .L7F0CA364
/* 0FEE60 7F0CA330 01D15821 */   addu  $t3, $t6, $s1
.L7F0CA334:
/* 0FEE64 7F0CA334 90580000 */  lbu   $t8, ($v0)
/* 0FEE68 7F0CA338 916F0000 */  lbu   $t7, ($t3)
/* 0FEE6C 7F0CA33C 24A50001 */  addiu $a1, $a1, 1
/* 0FEE70 7F0CA340 00187200 */  sll   $t6, $t8, 8
/* 0FEE74 7F0CA344 01EEC825 */  or    $t9, $t7, $t6
/* 0FEE78 7F0CA348 A5590000 */  sh    $t9, ($t2)
/* 0FEE7C 7F0CA34C 25080001 */  addiu $t0, $t0, 1
/* 0FEE80 7F0CA350 24420001 */  addiu $v0, $v0, 1
/* 0FEE84 7F0CA354 256B0001 */  addiu $t3, $t3, 1
/* 0FEE88 7F0CA358 1465FFF6 */  bne   $v1, $a1, .L7F0CA334
/* 0FEE8C 7F0CA35C 254A0002 */   addiu $t2, $t2, 2
/* 0FEE90 7F0CA360 10B0001C */  beq   $a1, $s0, .L7F0CA3D4
.L7F0CA364:
/* 0FEE94 7F0CA364 0005C040 */   sll   $t8, $a1, 1
/* 0FEE98 7F0CA368 01385021 */  addu  $t2, $t1, $t8
.L7F0CA36C:
/* 0FEE9C 7F0CA36C 904E0000 */  lbu   $t6, ($v0)
/* 0FEEA0 7F0CA370 916F0000 */  lbu   $t7, ($t3)
/* 0FEEA4 7F0CA374 24A50004 */  addiu $a1, $a1, 4
/* 0FEEA8 7F0CA378 000ECA00 */  sll   $t9, $t6, 8
/* 0FEEAC 7F0CA37C 01F9C025 */  or    $t8, $t7, $t9
/* 0FEEB0 7F0CA380 A5580000 */  sh    $t8, ($t2)
/* 0FEEB4 7F0CA384 904F0001 */  lbu   $t7, 1($v0)
/* 0FEEB8 7F0CA388 916E0001 */  lbu   $t6, 1($t3)
/* 0FEEBC 7F0CA38C 25080004 */  addiu $t0, $t0, 4
/* 0FEEC0 7F0CA390 000FCA00 */  sll   $t9, $t7, 8
/* 0FEEC4 7F0CA394 01D9C025 */  or    $t8, $t6, $t9
/* 0FEEC8 7F0CA398 A5580002 */  sh    $t8, 2($t2)
/* 0FEECC 7F0CA39C 904E0002 */  lbu   $t6, 2($v0)
/* 0FEED0 7F0CA3A0 916F0002 */  lbu   $t7, 2($t3)
/* 0FEED4 7F0CA3A4 24420004 */  addiu $v0, $v0, 4
/* 0FEED8 7F0CA3A8 000ECA00 */  sll   $t9, $t6, 8
/* 0FEEDC 7F0CA3AC 01F9C025 */  or    $t8, $t7, $t9
/* 0FEEE0 7F0CA3B0 A5580004 */  sh    $t8, 4($t2)
/* 0FEEE4 7F0CA3B4 904FFFFF */  lbu   $t7, -1($v0)
/* 0FEEE8 7F0CA3B8 916E0003 */  lbu   $t6, 3($t3)
/* 0FEEEC 7F0CA3BC 256B0004 */  addiu $t3, $t3, 4
/* 0FEEF0 7F0CA3C0 000FCA00 */  sll   $t9, $t7, 8
/* 0FEEF4 7F0CA3C4 01D9C025 */  or    $t8, $t6, $t9
/* 0FEEF8 7F0CA3C8 A5580006 */  sh    $t8, 6($t2)
/* 0FEEFC 7F0CA3CC 14B0FFE7 */  bne   $a1, $s0, .L7F0CA36C
/* 0FEF00 7F0CA3D0 254A0008 */   addiu $t2, $t2, 8
.L7F0CA3D4:
/* 0FEF04 7F0CA3D4 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FEF08 7F0CA3D8 24E70001 */  addiu $a3, $a3, 1
/* 0FEF0C 7F0CA3DC 14F2FFC9 */  bne   $a3, $s2, .L7F0CA304
/* 0FEF10 7F0CA3E0 012F4821 */   addu  $t1, $t1, $t7
.L7F0CA3E4:
/* 0FEF14 7F0CA3E4 260E0003 */  addiu $t6, $s0, 3
/* 0FEF18 7F0CA3E8 31D90FFC */  andi  $t9, $t6, 0xffc
/* 0FEF1C 7F0CA3EC 03320019 */  multu $t9, $s2
/* 0FEF20 7F0CA3F0 00001012 */  mflo  $v0
/* 0FEF24 7F0CA3F4 0002C040 */  sll   $t8, $v0, 1
/* 0FEF28 7F0CA3F8 1000011F */  b     .L7F0CA878
/* 0FEF2C 7F0CA3FC 03001025 */   move  $v0, $t8
.L7F0CA400:
/* 0FEF30 7F0CA400 1A40005B */  blez  $s2, .L7F0CA570
/* 0FEF34 7F0CA404 00003825 */   move  $a3, $zero
/* 0FEF38 7F0CA408 260F0003 */  addiu $t7, $s0, 3
/* 0FEF3C 7F0CA40C 31EE0FFC */  andi  $t6, $t7, 0xffc
/* 0FEF40 7F0CA410 000EC840 */  sll   $t9, $t6, 1
/* 0FEF44 7F0CA414 AFB9001C */  sw    $t9, 0x1c($sp)
.L7F0CA418:
/* 0FEF48 7F0CA418 1A000051 */  blez  $s0, .L7F0CA560
/* 0FEF4C 7F0CA41C 00002825 */   move  $a1, $zero
/* 0FEF50 7F0CA420 02120019 */  multu $s0, $s2
/* 0FEF54 7F0CA424 0228C021 */  addu  $t8, $s1, $t0
/* 0FEF58 7F0CA428 32060003 */  andi  $a2, $s0, 3
/* 0FEF5C 7F0CA42C 0000C840 */  sll   $t9, $zero, 1
/* 0FEF60 7F0CA430 01395021 */  addu  $t2, $t1, $t9
/* 0FEF64 7F0CA434 00C02025 */  move  $a0, $a2
/* 0FEF68 7F0CA438 02281021 */  addu  $v0, $s1, $t0
/* 0FEF6C 7F0CA43C 00005812 */  mflo  $t3
/* 0FEF70 7F0CA440 000B7840 */  sll   $t7, $t3, 1
/* 0FEF74 7F0CA444 01E87021 */  addu  $t6, $t7, $t0
/* 0FEF78 7F0CA448 01D16021 */  addu  $t4, $t6, $s1
/* 0FEF7C 7F0CA44C 10C00013 */  beqz  $a2, .L7F0CA49C
/* 0FEF80 7F0CA450 030B1821 */   addu  $v1, $t8, $t3
.L7F0CA454:
/* 0FEF84 7F0CA454 904E0000 */  lbu   $t6, ($v0)
/* 0FEF88 7F0CA458 91980000 */  lbu   $t8, ($t4)
/* 0FEF8C 7F0CA45C 24A50001 */  addiu $a1, $a1, 1
/* 0FEF90 7F0CA460 000ECAC0 */  sll   $t9, $t6, 0xb
/* 0FEF94 7F0CA464 906E0000 */  lbu   $t6, ($v1)
/* 0FEF98 7F0CA468 00187840 */  sll   $t7, $t8, 1
/* 0FEF9C 7F0CA46C 01F9C025 */  or    $t8, $t7, $t9
/* 0FEFA0 7F0CA470 000E7980 */  sll   $t7, $t6, 6
/* 0FEFA4 7F0CA474 030FC825 */  or    $t9, $t8, $t7
/* 0FEFA8 7F0CA478 372E0001 */  ori   $t6, $t9, 1
/* 0FEFAC 7F0CA47C A54E0000 */  sh    $t6, ($t2)
/* 0FEFB0 7F0CA480 25080001 */  addiu $t0, $t0, 1
/* 0FEFB4 7F0CA484 24420001 */  addiu $v0, $v0, 1
/* 0FEFB8 7F0CA488 24630001 */  addiu $v1, $v1, 1
/* 0FEFBC 7F0CA48C 258C0001 */  addiu $t4, $t4, 1
/* 0FEFC0 7F0CA490 1485FFF0 */  bne   $a0, $a1, .L7F0CA454
/* 0FEFC4 7F0CA494 254A0002 */   addiu $t2, $t2, 2
/* 0FEFC8 7F0CA498 10B00031 */  beq   $a1, $s0, .L7F0CA560
.L7F0CA49C:
/* 0FEFCC 7F0CA49C 0005C040 */   sll   $t8, $a1, 1
/* 0FEFD0 7F0CA4A0 01385021 */  addu  $t2, $t1, $t8
.L7F0CA4A4:
/* 0FEFD4 7F0CA4A4 904E0000 */  lbu   $t6, ($v0)
/* 0FEFD8 7F0CA4A8 918F0000 */  lbu   $t7, ($t4)
/* 0FEFDC 7F0CA4AC 24A50004 */  addiu $a1, $a1, 4
/* 0FEFE0 7F0CA4B0 000EC2C0 */  sll   $t8, $t6, 0xb
/* 0FEFE4 7F0CA4B4 906E0000 */  lbu   $t6, ($v1)
/* 0FEFE8 7F0CA4B8 000FC840 */  sll   $t9, $t7, 1
/* 0FEFEC 7F0CA4BC 03387825 */  or    $t7, $t9, $t8
/* 0FEFF0 7F0CA4C0 000EC980 */  sll   $t9, $t6, 6
/* 0FEFF4 7F0CA4C4 01F9C025 */  or    $t8, $t7, $t9
/* 0FEFF8 7F0CA4C8 370E0001 */  ori   $t6, $t8, 1
/* 0FEFFC 7F0CA4CC A54E0000 */  sh    $t6, ($t2)
/* 0FF000 7F0CA4D0 90580001 */  lbu   $t8, 1($v0)
/* 0FF004 7F0CA4D4 918F0001 */  lbu   $t7, 1($t4)
/* 0FF008 7F0CA4D8 25080004 */  addiu $t0, $t0, 4
/* 0FF00C 7F0CA4DC 001872C0 */  sll   $t6, $t8, 0xb
/* 0FF010 7F0CA4E0 90780001 */  lbu   $t8, 1($v1)
/* 0FF014 7F0CA4E4 000FC840 */  sll   $t9, $t7, 1
/* 0FF018 7F0CA4E8 032E7825 */  or    $t7, $t9, $t6
/* 0FF01C 7F0CA4EC 0018C980 */  sll   $t9, $t8, 6
/* 0FF020 7F0CA4F0 01F97025 */  or    $t6, $t7, $t9
/* 0FF024 7F0CA4F4 35D80001 */  ori   $t8, $t6, 1
/* 0FF028 7F0CA4F8 A5580002 */  sh    $t8, 2($t2)
/* 0FF02C 7F0CA4FC 904E0002 */  lbu   $t6, 2($v0)
/* 0FF030 7F0CA500 918F0002 */  lbu   $t7, 2($t4)
/* 0FF034 7F0CA504 24420004 */  addiu $v0, $v0, 4
/* 0FF038 7F0CA508 000EC2C0 */  sll   $t8, $t6, 0xb
/* 0FF03C 7F0CA50C 906E0002 */  lbu   $t6, 2($v1)
/* 0FF040 7F0CA510 000FC840 */  sll   $t9, $t7, 1
/* 0FF044 7F0CA514 03387825 */  or    $t7, $t9, $t8
/* 0FF048 7F0CA518 000EC980 */  sll   $t9, $t6, 6
/* 0FF04C 7F0CA51C 01F9C025 */  or    $t8, $t7, $t9
/* 0FF050 7F0CA520 370E0001 */  ori   $t6, $t8, 1
/* 0FF054 7F0CA524 A54E0004 */  sh    $t6, 4($t2)
/* 0FF058 7F0CA528 9058FFFF */  lbu   $t8, -1($v0)
/* 0FF05C 7F0CA52C 918F0003 */  lbu   $t7, 3($t4)
/* 0FF060 7F0CA530 24630004 */  addiu $v1, $v1, 4
/* 0FF064 7F0CA534 001872C0 */  sll   $t6, $t8, 0xb
/* 0FF068 7F0CA538 9078FFFF */  lbu   $t8, -1($v1)
/* 0FF06C 7F0CA53C 000FC840 */  sll   $t9, $t7, 1
/* 0FF070 7F0CA540 032E7825 */  or    $t7, $t9, $t6
/* 0FF074 7F0CA544 0018C980 */  sll   $t9, $t8, 6
/* 0FF078 7F0CA548 01F97025 */  or    $t6, $t7, $t9
/* 0FF07C 7F0CA54C 35D80001 */  ori   $t8, $t6, 1
/* 0FF080 7F0CA550 A5580006 */  sh    $t8, 6($t2)
/* 0FF084 7F0CA554 258C0004 */  addiu $t4, $t4, 4
/* 0FF088 7F0CA558 14B0FFD2 */  bne   $a1, $s0, .L7F0CA4A4
/* 0FF08C 7F0CA55C 254A0008 */   addiu $t2, $t2, 8
.L7F0CA560:
/* 0FF090 7F0CA560 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FF094 7F0CA564 24E70001 */  addiu $a3, $a3, 1
/* 0FF098 7F0CA568 14F2FFAB */  bne   $a3, $s2, .L7F0CA418
/* 0FF09C 7F0CA56C 012F4821 */   addu  $t1, $t1, $t7
.L7F0CA570:
/* 0FF0A0 7F0CA570 26190003 */  addiu $t9, $s0, 3
/* 0FF0A4 7F0CA574 332E0FFC */  andi  $t6, $t9, 0xffc
/* 0FF0A8 7F0CA578 01D20019 */  multu $t6, $s2
/* 0FF0AC 7F0CA57C 00001012 */  mflo  $v0
/* 0FF0B0 7F0CA580 0002C040 */  sll   $t8, $v0, 1
/* 0FF0B4 7F0CA584 100000BC */  b     .L7F0CA878
/* 0FF0B8 7F0CA588 03001025 */   move  $v0, $t8
.L7F0CA58C:
/* 0FF0BC 7F0CA58C 1A400039 */  blez  $s2, .L7F0CA674
/* 0FF0C0 7F0CA590 00003825 */   move  $a3, $zero
/* 0FF0C4 7F0CA594 26040007 */  addiu $a0, $s0, 7
/* 0FF0C8 7F0CA598 308F0FF8 */  andi  $t7, $a0, 0xff8
/* 0FF0CC 7F0CA59C 01E02025 */  move  $a0, $t7
.L7F0CA5A0:
/* 0FF0D0 7F0CA5A0 1A000031 */  blez  $s0, .L7F0CA668
/* 0FF0D4 7F0CA5A4 00002825 */   move  $a1, $zero
/* 0FF0D8 7F0CA5A8 02120019 */  multu $s0, $s2
/* 0FF0DC 7F0CA5AC 32060003 */  andi  $a2, $s0, 3
/* 0FF0E0 7F0CA5B0 00C05025 */  move  $t2, $a2
/* 0FF0E4 7F0CA5B4 02281021 */  addu  $v0, $s1, $t0
/* 0FF0E8 7F0CA5B8 00604821 */  addu  $t1, $v1, $zero
/* 0FF0EC 7F0CA5BC 0000C812 */  mflo  $t9
/* 0FF0F0 7F0CA5C0 01197021 */  addu  $t6, $t0, $t9
/* 0FF0F4 7F0CA5C4 10C0000D */  beqz  $a2, .L7F0CA5FC
/* 0FF0F8 7F0CA5C8 01D15821 */   addu  $t3, $t6, $s1
.L7F0CA5CC:
/* 0FF0FC 7F0CA5CC 904F0000 */  lbu   $t7, ($v0)
/* 0FF100 7F0CA5D0 91780000 */  lbu   $t8, ($t3)
/* 0FF104 7F0CA5D4 24A50001 */  addiu $a1, $a1, 1
/* 0FF108 7F0CA5D8 000FC900 */  sll   $t9, $t7, 4
/* 0FF10C 7F0CA5DC 03197025 */  or    $t6, $t8, $t9
/* 0FF110 7F0CA5E0 A12E0000 */  sb    $t6, ($t1)
/* 0FF114 7F0CA5E4 25080001 */  addiu $t0, $t0, 1
/* 0FF118 7F0CA5E8 24420001 */  addiu $v0, $v0, 1
/* 0FF11C 7F0CA5EC 256B0001 */  addiu $t3, $t3, 1
/* 0FF120 7F0CA5F0 1545FFF6 */  bne   $t2, $a1, .L7F0CA5CC
/* 0FF124 7F0CA5F4 25290001 */   addiu $t1, $t1, 1
/* 0FF128 7F0CA5F8 10B0001B */  beq   $a1, $s0, .L7F0CA668
.L7F0CA5FC:
/* 0FF12C 7F0CA5FC 00654821 */   addu  $t1, $v1, $a1
.L7F0CA600:
/* 0FF130 7F0CA600 90580000 */  lbu   $t8, ($v0)
/* 0FF134 7F0CA604 916F0000 */  lbu   $t7, ($t3)
/* 0FF138 7F0CA608 24A50004 */  addiu $a1, $a1, 4
/* 0FF13C 7F0CA60C 0018C900 */  sll   $t9, $t8, 4
/* 0FF140 7F0CA610 01F97025 */  or    $t6, $t7, $t9
/* 0FF144 7F0CA614 A12E0000 */  sb    $t6, ($t1)
/* 0FF148 7F0CA618 904F0001 */  lbu   $t7, 1($v0)
/* 0FF14C 7F0CA61C 91780001 */  lbu   $t8, 1($t3)
/* 0FF150 7F0CA620 25080004 */  addiu $t0, $t0, 4
/* 0FF154 7F0CA624 000FC900 */  sll   $t9, $t7, 4
/* 0FF158 7F0CA628 03197025 */  or    $t6, $t8, $t9
/* 0FF15C 7F0CA62C A12E0001 */  sb    $t6, 1($t1)
/* 0FF160 7F0CA630 90580002 */  lbu   $t8, 2($v0)
/* 0FF164 7F0CA634 916F0002 */  lbu   $t7, 2($t3)
/* 0FF168 7F0CA638 24420004 */  addiu $v0, $v0, 4
/* 0FF16C 7F0CA63C 0018C900 */  sll   $t9, $t8, 4
/* 0FF170 7F0CA640 01F97025 */  or    $t6, $t7, $t9
/* 0FF174 7F0CA644 A12E0002 */  sb    $t6, 2($t1)
/* 0FF178 7F0CA648 904FFFFF */  lbu   $t7, -1($v0)
/* 0FF17C 7F0CA64C 91780003 */  lbu   $t8, 3($t3)
/* 0FF180 7F0CA650 256B0004 */  addiu $t3, $t3, 4
/* 0FF184 7F0CA654 000FC900 */  sll   $t9, $t7, 4
/* 0FF188 7F0CA658 03197025 */  or    $t6, $t8, $t9
/* 0FF18C 7F0CA65C A12E0003 */  sb    $t6, 3($t1)
/* 0FF190 7F0CA660 14B0FFE7 */  bne   $a1, $s0, .L7F0CA600
/* 0FF194 7F0CA664 25290004 */   addiu $t1, $t1, 4
.L7F0CA668:
/* 0FF198 7F0CA668 24E70001 */  addiu $a3, $a3, 1
/* 0FF19C 7F0CA66C 14F2FFCC */  bne   $a3, $s2, .L7F0CA5A0
/* 0FF1A0 7F0CA670 00641821 */   addu  $v1, $v1, $a0
.L7F0CA674:
/* 0FF1A4 7F0CA674 260F0007 */  addiu $t7, $s0, 7
/* 0FF1A8 7F0CA678 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 0FF1AC 7F0CA67C 03120019 */  multu $t8, $s2
/* 0FF1B0 7F0CA680 00001012 */  mflo  $v0
/* 0FF1B4 7F0CA684 1000007D */  b     .L7F0CA87C
/* 0FF1B8 7F0CA688 8FB00008 */   lw    $s0, 8($sp)
.L7F0CA68C:
/* 0FF1BC 7F0CA68C 1A400024 */  blez  $s2, .L7F0CA720
/* 0FF1C0 7F0CA690 00003825 */   move  $a3, $zero
/* 0FF1C4 7F0CA694 26040007 */  addiu $a0, $s0, 7
/* 0FF1C8 7F0CA698 30990FF8 */  andi  $t9, $a0, 0xff8
/* 0FF1CC 7F0CA69C 03202025 */  move  $a0, $t9
.L7F0CA6A0:
/* 0FF1D0 7F0CA6A0 1A00001C */  blez  $s0, .L7F0CA714
/* 0FF1D4 7F0CA6A4 00002825 */   move  $a1, $zero
/* 0FF1D8 7F0CA6A8 32060003 */  andi  $a2, $s0, 3
/* 0FF1DC 7F0CA6AC 10C0000B */  beqz  $a2, .L7F0CA6DC
/* 0FF1E0 7F0CA6B0 02281021 */   addu  $v0, $s1, $t0
/* 0FF1E4 7F0CA6B4 00C05025 */  move  $t2, $a2
/* 0FF1E8 7F0CA6B8 00604821 */  addu  $t1, $v1, $zero
.L7F0CA6BC:
/* 0FF1EC 7F0CA6BC 904E0000 */  lbu   $t6, ($v0)
/* 0FF1F0 7F0CA6C0 24A50001 */  addiu $a1, $a1, 1
/* 0FF1F4 7F0CA6C4 25080001 */  addiu $t0, $t0, 1
/* 0FF1F8 7F0CA6C8 24420001 */  addiu $v0, $v0, 1
/* 0FF1FC 7F0CA6CC 25290001 */  addiu $t1, $t1, 1
/* 0FF200 7F0CA6D0 1545FFFA */  bne   $t2, $a1, .L7F0CA6BC
/* 0FF204 7F0CA6D4 A12EFFFF */   sb    $t6, -1($t1)
/* 0FF208 7F0CA6D8 10B0000E */  beq   $a1, $s0, .L7F0CA714
.L7F0CA6DC:
/* 0FF20C 7F0CA6DC 00654821 */   addu  $t1, $v1, $a1
.L7F0CA6E0:
/* 0FF210 7F0CA6E0 904F0000 */  lbu   $t7, ($v0)
/* 0FF214 7F0CA6E4 24A50004 */  addiu $a1, $a1, 4
/* 0FF218 7F0CA6E8 25080004 */  addiu $t0, $t0, 4
/* 0FF21C 7F0CA6EC A12F0000 */  sb    $t7, ($t1)
/* 0FF220 7F0CA6F0 90580001 */  lbu   $t8, 1($v0)
/* 0FF224 7F0CA6F4 24420004 */  addiu $v0, $v0, 4
/* 0FF228 7F0CA6F8 25290004 */  addiu $t1, $t1, 4
/* 0FF22C 7F0CA6FC A138FFFD */  sb    $t8, -3($t1)
/* 0FF230 7F0CA700 9059FFFE */  lbu   $t9, -2($v0)
/* 0FF234 7F0CA704 A139FFFE */  sb    $t9, -2($t1)
/* 0FF238 7F0CA708 904EFFFF */  lbu   $t6, -1($v0)
/* 0FF23C 7F0CA70C 14B0FFF4 */  bne   $a1, $s0, .L7F0CA6E0
/* 0FF240 7F0CA710 A12EFFFF */   sb    $t6, -1($t1)
.L7F0CA714:
/* 0FF244 7F0CA714 24E70001 */  addiu $a3, $a3, 1
/* 0FF248 7F0CA718 14F2FFE1 */  bne   $a3, $s2, .L7F0CA6A0
/* 0FF24C 7F0CA71C 00641821 */   addu  $v1, $v1, $a0
.L7F0CA720:
/* 0FF250 7F0CA720 260F0007 */  addiu $t7, $s0, 7
/* 0FF254 7F0CA724 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 0FF258 7F0CA728 03120019 */  multu $t8, $s2
/* 0FF25C 7F0CA72C 00001012 */  mflo  $v0
/* 0FF260 7F0CA730 10000052 */  b     .L7F0CA87C
/* 0FF264 7F0CA734 8FB00008 */   lw    $s0, 8($sp)
.L7F0CA738:
/* 0FF268 7F0CA738 1A400026 */  blez  $s2, .L7F0CA7D4
/* 0FF26C 7F0CA73C 00003825 */   move  $a3, $zero
/* 0FF270 7F0CA740 2606000F */  addiu $a2, $s0, 0xf
/* 0FF274 7F0CA744 30D90FF0 */  andi  $t9, $a2, 0xff0
/* 0FF278 7F0CA748 03203025 */  move  $a2, $t9
/* 0FF27C 7F0CA74C 32090001 */  andi  $t1, $s0, 1
.L7F0CA750:
/* 0FF280 7F0CA750 1A00001B */  blez  $s0, .L7F0CA7C0
/* 0FF284 7F0CA754 00002825 */   move  $a1, $zero
/* 0FF288 7F0CA758 02120019 */  multu $s0, $s2
/* 0FF28C 7F0CA75C 02281021 */  addu  $v0, $s1, $t0
/* 0FF290 7F0CA760 00007012 */  mflo  $t6
/* 0FF294 7F0CA764 000E7880 */  sll   $t7, $t6, 2
/* 0FF298 7F0CA768 01EE7823 */  subu  $t7, $t7, $t6
/* 0FF29C 7F0CA76C 01E8C021 */  addu  $t8, $t7, $t0
/* 0FF2A0 7F0CA770 03112021 */  addu  $a0, $t8, $s1
.L7F0CA774:
/* 0FF2A4 7F0CA774 904E0000 */  lbu   $t6, ($v0)
/* 0FF2A8 7F0CA778 90990001 */  lbu   $t9, 1($a0)
/* 0FF2AC 7F0CA77C 25080002 */  addiu $t0, $t0, 2
/* 0FF2B0 7F0CA780 000E7940 */  sll   $t7, $t6, 5
/* 0FF2B4 7F0CA784 908E0000 */  lbu   $t6, ($a0)
/* 0FF2B8 7F0CA788 032FC025 */  or    $t8, $t9, $t7
/* 0FF2BC 7F0CA78C 24420002 */  addiu $v0, $v0, 2
/* 0FF2C0 7F0CA790 000EC900 */  sll   $t9, $t6, 4
/* 0FF2C4 7F0CA794 904EFFFF */  lbu   $t6, -1($v0)
/* 0FF2C8 7F0CA798 03197825 */  or    $t7, $t8, $t9
/* 0FF2CC 7F0CA79C 24840002 */  addiu $a0, $a0, 2
/* 0FF2D0 7F0CA7A0 000EC040 */  sll   $t8, $t6, 1
/* 0FF2D4 7F0CA7A4 00057043 */  sra   $t6, $a1, 1
/* 0FF2D8 7F0CA7A8 24A50002 */  addiu $a1, $a1, 2
/* 0FF2DC 7F0CA7AC 01F8C825 */  or    $t9, $t7, $t8
/* 0FF2E0 7F0CA7B0 00B0082A */  slt   $at, $a1, $s0
/* 0FF2E4 7F0CA7B4 006E7821 */  addu  $t7, $v1, $t6
/* 0FF2E8 7F0CA7B8 1420FFEE */  bnez  $at, .L7F0CA774
/* 0FF2EC 7F0CA7BC A1F90000 */   sb    $t9, ($t7)
.L7F0CA7C0:
/* 0FF2F0 7F0CA7C0 11200002 */  beqz  $t1, .L7F0CA7CC
/* 0FF2F4 7F0CA7C4 24E70001 */   addiu $a3, $a3, 1
/* 0FF2F8 7F0CA7C8 2508FFFF */  addiu $t0, $t0, -1
.L7F0CA7CC:
/* 0FF2FC 7F0CA7CC 14F2FFE0 */  bne   $a3, $s2, .L7F0CA750
/* 0FF300 7F0CA7D0 00661821 */   addu  $v1, $v1, $a2
.L7F0CA7D4:
/* 0FF304 7F0CA7D4 2618000F */  addiu $t8, $s0, 0xf
/* 0FF308 7F0CA7D8 330E0FF0 */  andi  $t6, $t8, 0xff0
/* 0FF30C 7F0CA7DC 000EC843 */  sra   $t9, $t6, 1
/* 0FF310 7F0CA7E0 03320019 */  multu $t9, $s2
/* 0FF314 7F0CA7E4 00001012 */  mflo  $v0
/* 0FF318 7F0CA7E8 10000024 */  b     .L7F0CA87C
/* 0FF31C 7F0CA7EC 8FB00008 */   lw    $s0, 8($sp)
.L7F0CA7F0:
/* 0FF320 7F0CA7F0 1A400019 */  blez  $s2, .L7F0CA858
/* 0FF324 7F0CA7F4 00003825 */   move  $a3, $zero
/* 0FF328 7F0CA7F8 2604000F */  addiu $a0, $s0, 0xf
/* 0FF32C 7F0CA7FC 308F0FF0 */  andi  $t7, $a0, 0xff0
/* 0FF330 7F0CA800 000F2043 */  sra   $a0, $t7, 1
/* 0FF334 7F0CA804 32090001 */  andi  $t1, $s0, 1
.L7F0CA808:
/* 0FF338 7F0CA808 1A00000E */  blez  $s0, .L7F0CA844
/* 0FF33C 7F0CA80C 00002825 */   move  $a1, $zero
/* 0FF340 7F0CA810 02281021 */  addu  $v0, $s1, $t0
.L7F0CA814:
/* 0FF344 7F0CA814 90590000 */  lbu   $t9, ($v0)
/* 0FF348 7F0CA818 904E0001 */  lbu   $t6, 1($v0)
/* 0FF34C 7F0CA81C 25080002 */  addiu $t0, $t0, 2
/* 0FF350 7F0CA820 00197900 */  sll   $t7, $t9, 4
/* 0FF354 7F0CA824 0005C843 */  sra   $t9, $a1, 1
/* 0FF358 7F0CA828 24A50002 */  addiu $a1, $a1, 2
/* 0FF35C 7F0CA82C 01CFC025 */  or    $t8, $t6, $t7
/* 0FF360 7F0CA830 00B0082A */  slt   $at, $a1, $s0
/* 0FF364 7F0CA834 00797021 */  addu  $t6, $v1, $t9
/* 0FF368 7F0CA838 A1D80000 */  sb    $t8, ($t6)
/* 0FF36C 7F0CA83C 1420FFF5 */  bnez  $at, .L7F0CA814
/* 0FF370 7F0CA840 24420002 */   addiu $v0, $v0, 2
.L7F0CA844:
/* 0FF374 7F0CA844 11200002 */  beqz  $t1, .L7F0CA850
/* 0FF378 7F0CA848 24E70001 */   addiu $a3, $a3, 1
/* 0FF37C 7F0CA84C 2508FFFF */  addiu $t0, $t0, -1
.L7F0CA850:
/* 0FF380 7F0CA850 14F2FFED */  bne   $a3, $s2, .L7F0CA808
/* 0FF384 7F0CA854 00641821 */   addu  $v1, $v1, $a0
.L7F0CA858:
/* 0FF388 7F0CA858 260F000F */  addiu $t7, $s0, 0xf
/* 0FF38C 7F0CA85C 31F90FF0 */  andi  $t9, $t7, 0xff0
/* 0FF390 7F0CA860 0019C043 */  sra   $t8, $t9, 1
/* 0FF394 7F0CA864 03120019 */  multu $t8, $s2
/* 0FF398 7F0CA868 00001012 */  mflo  $v0
/* 0FF39C 7F0CA86C 10000003 */  b     .L7F0CA87C
/* 0FF3A0 7F0CA870 8FB00008 */   lw    $s0, 8($sp)
def_7F0C9DF0:
.L7F0CA874:
/* 0FF3A4 7F0CA874 00001025 */  move  $v0, $zero
.L7F0CA878:
/* 0FF3A8 7F0CA878 8FB00008 */  lw    $s0, 8($sp)
.L7F0CA87C:
/* 0FF3AC 7F0CA87C 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FF3B0 7F0CA880 8FB20010 */  lw    $s2, 0x10($sp)
/* 0FF3B4 7F0CA884 8FB30014 */  lw    $s3, 0x14($sp)
/* 0FF3B8 7F0CA888 03E00008 */  jr    $ra
/* 0FF3BC 7F0CA88C 27BD0068 */   addiu $sp, $sp, 0x68
)
#endif





#ifdef NONMATCHING
void type5_generate_link_final_image(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BDE8*/
glabel jpt_8005BDE8
.word .L7F0CA908
.word .L7F0CA9FC
.word .L7F0CA97C
.word .L7F0CAA78
.word .L7F0CA9FC
.word .L7F0CAAFC
.word .L7F0CAB74
.word .L7F0CAAFC
.word .L7F0CAB74
.text
glabel type5_generate_link_final_image
/* 0FF3C0 7F0CA890 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0FF3C4 7F0CA894 AFB40028 */  sw    $s4, 0x28($sp)
/* 0FF3C8 7F0CA898 0080A025 */  move  $s4, $a0
/* 0FF3CC 7F0CA89C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0FF3D0 7F0CA8A0 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0FF3D4 7F0CA8A4 AFB70034 */  sw    $s7, 0x34($sp)
/* 0FF3D8 7F0CA8A8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FF3DC 7F0CA8AC AFB30024 */  sw    $s3, 0x24($sp)
/* 0FF3E0 7F0CA8B0 00E09825 */  move  $s3, $a3
/* 0FF3E4 7F0CA8B4 AFB60030 */  sw    $s6, 0x30($sp)
/* 0FF3E8 7F0CA8B8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FF3EC 7F0CA8BC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FF3F0 7F0CA8C0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FF3F4 7F0CA8C4 AFA50044 */  sw    $a1, 0x44($sp)
/* 0FF3F8 7F0CA8C8 00C0B825 */  move  $s7, $a2
/* 0FF3FC 7F0CA8CC 00C0F025 */  move  $fp, $a2
/* 0FF400 7F0CA8D0 00C0A825 */  move  $s5, $a2
/* 0FF404 7F0CA8D4 0FC32689 */  jal   sub_GAME_7F0C9A24
/* 0FF408 7F0CA8D8 8FA40050 */   lw    $a0, 0x50($sp)
/* 0FF40C 7F0CA8DC 8FAE0054 */  lw    $t6, 0x54($sp)
/* 0FF410 7F0CA8E0 00409025 */  move  $s2, $v0
/* 0FF414 7F0CA8E4 00001025 */  move  $v0, $zero
/* 0FF418 7F0CA8E8 2DC10009 */  sltiu $at, $t6, 9
/* 0FF41C 7F0CA8EC 102000CE */  beqz  $at, .L7F0CAC28
/* 0FF420 7F0CA8F0 000E7080 */   sll   $t6, $t6, 2
/* 0FF424 7F0CA8F4 3C018006 */  lui   $at, %hi(jpt_8005BDE8)
/* 0FF428 7F0CA8F8 002E0821 */  addu  $at, $at, $t6
/* 0FF42C 7F0CA8FC 8C2EBDE8 */  lw    $t6, %lo(jpt_8005BDE8)($at)
/* 0FF430 7F0CA900 01C00008 */  jr    $t6
/* 0FF434 7F0CA904 00000000 */   nop   
.L7F0CA908:
/* 0FF438 7F0CA908 8FA30044 */  lw    $v1, 0x44($sp)
/* 0FF43C 7F0CA90C 26950003 */  addiu $s5, $s4, 3
/* 0FF440 7F0CA910 32AF0FFC */  andi  $t7, $s5, 0xffc
/* 0FF444 7F0CA914 18600012 */  blez  $v1, .L7F0CA960
/* 0FF448 7F0CA918 0000B025 */   move  $s6, $zero
/* 0FF44C 7F0CA91C 000FA880 */  sll   $s5, $t7, 2
.L7F0CA920:
/* 0FF450 7F0CA920 1A80000C */  blez  $s4, .L7F0CA954
/* 0FF454 7F0CA924 00008025 */   move  $s0, $zero
/* 0FF458 7F0CA928 02E08825 */  move  $s1, $s7
.L7F0CA92C:
/* 0FF45C 7F0CA92C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF460 7F0CA930 02402025 */   move  $a0, $s2
/* 0FF464 7F0CA934 0002C880 */  sll   $t9, $v0, 2
/* 0FF468 7F0CA938 02794021 */  addu  $t0, $s3, $t9
/* 0FF46C 7F0CA93C 8D090000 */  lw    $t1, ($t0)
/* 0FF470 7F0CA940 26100001 */  addiu $s0, $s0, 1
/* 0FF474 7F0CA944 26310004 */  addiu $s1, $s1, 4
/* 0FF478 7F0CA948 1614FFF8 */  bne   $s0, $s4, .L7F0CA92C
/* 0FF47C 7F0CA94C AE29FFFC */   sw    $t1, -4($s1)
/* 0FF480 7F0CA950 8FA30044 */  lw    $v1, 0x44($sp)
.L7F0CA954:
/* 0FF484 7F0CA954 26D60001 */  addiu $s6, $s6, 1
/* 0FF488 7F0CA958 16C3FFF1 */  bne   $s6, $v1, .L7F0CA920
/* 0FF48C 7F0CA95C 02F5B821 */   addu  $s7, $s7, $s5
.L7F0CA960:
/* 0FF490 7F0CA960 268A0003 */  addiu $t2, $s4, 3
/* 0FF494 7F0CA964 314B0FFC */  andi  $t3, $t2, 0xffc
/* 0FF498 7F0CA968 01630019 */  multu $t3, $v1
/* 0FF49C 7F0CA96C 00001012 */  mflo  $v0
/* 0FF4A0 7F0CA970 00026080 */  sll   $t4, $v0, 2
/* 0FF4A4 7F0CA974 100000AC */  b     .L7F0CAC28
/* 0FF4A8 7F0CA978 01801025 */   move  $v0, $t4
.L7F0CA97C:
/* 0FF4AC 7F0CA97C 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FF4B0 7F0CA980 26950003 */  addiu $s5, $s4, 3
/* 0FF4B4 7F0CA984 32AE0FFC */  andi  $t6, $s5, 0xffc
/* 0FF4B8 7F0CA988 19A00014 */  blez  $t5, .L7F0CA9DC
/* 0FF4BC 7F0CA98C 0000B025 */   move  $s6, $zero
/* 0FF4C0 7F0CA990 000EA880 */  sll   $s5, $t6, 2
.L7F0CA994:
/* 0FF4C4 7F0CA994 1A80000C */  blez  $s4, .L7F0CA9C8
/* 0FF4C8 7F0CA998 00008025 */   move  $s0, $zero
/* 0FF4CC 7F0CA99C 02E08825 */  move  $s1, $s7
.L7F0CA9A0:
/* 0FF4D0 7F0CA9A0 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF4D4 7F0CA9A4 02402025 */   move  $a0, $s2
/* 0FF4D8 7F0CA9A8 0002C080 */  sll   $t8, $v0, 2
/* 0FF4DC 7F0CA9AC 0278C821 */  addu  $t9, $s3, $t8
/* 0FF4E0 7F0CA9B0 8F280000 */  lw    $t0, ($t9)
/* 0FF4E4 7F0CA9B4 26100001 */  addiu $s0, $s0, 1
/* 0FF4E8 7F0CA9B8 26310004 */  addiu $s1, $s1, 4
/* 0FF4EC 7F0CA9BC 00084A00 */  sll   $t1, $t0, 8
/* 0FF4F0 7F0CA9C0 1614FFF7 */  bne   $s0, $s4, .L7F0CA9A0
/* 0FF4F4 7F0CA9C4 AE29FFFC */   sw    $t1, -4($s1)
.L7F0CA9C8:
/* 0FF4F8 7F0CA9C8 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0FF4FC 7F0CA9CC 26D60001 */  addiu $s6, $s6, 1
/* 0FF500 7F0CA9D0 02F5B821 */  addu  $s7, $s7, $s5
/* 0FF504 7F0CA9D4 16CAFFEF */  bne   $s6, $t2, .L7F0CA994
/* 0FF508 7F0CA9D8 00000000 */   nop   
.L7F0CA9DC:
/* 0FF50C 7F0CA9DC 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FF510 7F0CA9E0 268B0003 */  addiu $t3, $s4, 3
/* 0FF514 7F0CA9E4 316C0FFC */  andi  $t4, $t3, 0xffc
/* 0FF518 7F0CA9E8 018D0019 */  multu $t4, $t5
/* 0FF51C 7F0CA9EC 00001012 */  mflo  $v0
/* 0FF520 7F0CA9F0 00027080 */  sll   $t6, $v0, 2
/* 0FF524 7F0CA9F4 1000008C */  b     .L7F0CAC28
/* 0FF528 7F0CA9F8 01C01025 */   move  $v0, $t6
.L7F0CA9FC:
/* 0FF52C 7F0CA9FC 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0FF530 7F0CAA00 26950003 */  addiu $s5, $s4, 3
/* 0FF534 7F0CAA04 32B80FFC */  andi  $t8, $s5, 0xffc
/* 0FF538 7F0CAA08 19E00013 */  blez  $t7, .L7F0CAA58
/* 0FF53C 7F0CAA0C 0000B025 */   move  $s6, $zero
/* 0FF540 7F0CAA10 0018A840 */  sll   $s5, $t8, 1
.L7F0CAA14:
/* 0FF544 7F0CAA14 1A80000B */  blez  $s4, .L7F0CAA44
/* 0FF548 7F0CAA18 00008025 */   move  $s0, $zero
/* 0FF54C 7F0CAA1C 03C08825 */  move  $s1, $fp
.L7F0CAA20:
/* 0FF550 7F0CAA20 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF554 7F0CAA24 02402025 */   move  $a0, $s2
/* 0FF558 7F0CAA28 00024040 */  sll   $t0, $v0, 1
/* 0FF55C 7F0CAA2C 02684821 */  addu  $t1, $s3, $t0
/* 0FF560 7F0CAA30 952A0000 */  lhu   $t2, ($t1)
/* 0FF564 7F0CAA34 26100001 */  addiu $s0, $s0, 1
/* 0FF568 7F0CAA38 26310002 */  addiu $s1, $s1, 2
/* 0FF56C 7F0CAA3C 1614FFF8 */  bne   $s0, $s4, .L7F0CAA20
/* 0FF570 7F0CAA40 A62AFFFE */   sh    $t2, -2($s1)
.L7F0CAA44:
/* 0FF574 7F0CAA44 8FAB0044 */  lw    $t3, 0x44($sp)
/* 0FF578 7F0CAA48 26D60001 */  addiu $s6, $s6, 1
/* 0FF57C 7F0CAA4C 03D5F021 */  addu  $fp, $fp, $s5
/* 0FF580 7F0CAA50 16CBFFF0 */  bne   $s6, $t3, .L7F0CAA14
/* 0FF584 7F0CAA54 00000000 */   nop   
.L7F0CAA58:
/* 0FF588 7F0CAA58 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0FF58C 7F0CAA5C 268C0003 */  addiu $t4, $s4, 3
/* 0FF590 7F0CAA60 318D0FFC */  andi  $t5, $t4, 0xffc
/* 0FF594 7F0CAA64 01AE0019 */  multu $t5, $t6
/* 0FF598 7F0CAA68 00001012 */  mflo  $v0
/* 0FF59C 7F0CAA6C 00027840 */  sll   $t7, $v0, 1
/* 0FF5A0 7F0CAA70 1000006D */  b     .L7F0CAC28
/* 0FF5A4 7F0CAA74 01E01025 */   move  $v0, $t7
.L7F0CAA78:
/* 0FF5A8 7F0CAA78 8FB80044 */  lw    $t8, 0x44($sp)
/* 0FF5AC 7F0CAA7C 26950003 */  addiu $s5, $s4, 3
/* 0FF5B0 7F0CAA80 32B90FFC */  andi  $t9, $s5, 0xffc
/* 0FF5B4 7F0CAA84 1B000015 */  blez  $t8, .L7F0CAADC
/* 0FF5B8 7F0CAA88 0000B025 */   move  $s6, $zero
/* 0FF5BC 7F0CAA8C 0019A840 */  sll   $s5, $t9, 1
.L7F0CAA90:
/* 0FF5C0 7F0CAA90 1A80000D */  blez  $s4, .L7F0CAAC8
/* 0FF5C4 7F0CAA94 00008025 */   move  $s0, $zero
/* 0FF5C8 7F0CAA98 03C08825 */  move  $s1, $fp
.L7F0CAA9C:
/* 0FF5CC 7F0CAA9C 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF5D0 7F0CAAA0 02402025 */   move  $a0, $s2
/* 0FF5D4 7F0CAAA4 00024840 */  sll   $t1, $v0, 1
/* 0FF5D8 7F0CAAA8 02695021 */  addu  $t2, $s3, $t1
/* 0FF5DC 7F0CAAAC 954B0000 */  lhu   $t3, ($t2)
/* 0FF5E0 7F0CAAB0 26100001 */  addiu $s0, $s0, 1
/* 0FF5E4 7F0CAAB4 26310002 */  addiu $s1, $s1, 2
/* 0FF5E8 7F0CAAB8 000B6040 */  sll   $t4, $t3, 1
/* 0FF5EC 7F0CAABC 358D0001 */  ori   $t5, $t4, 1
/* 0FF5F0 7F0CAAC0 1614FFF6 */  bne   $s0, $s4, .L7F0CAA9C
/* 0FF5F4 7F0CAAC4 A62DFFFE */   sh    $t5, -2($s1)
.L7F0CAAC8:
/* 0FF5F8 7F0CAAC8 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0FF5FC 7F0CAACC 26D60001 */  addiu $s6, $s6, 1
/* 0FF600 7F0CAAD0 03D5F021 */  addu  $fp, $fp, $s5
/* 0FF604 7F0CAAD4 16CEFFEE */  bne   $s6, $t6, .L7F0CAA90
/* 0FF608 7F0CAAD8 00000000 */   nop   
.L7F0CAADC:
/* 0FF60C 7F0CAADC 8FB90044 */  lw    $t9, 0x44($sp)
/* 0FF610 7F0CAAE0 268F0003 */  addiu $t7, $s4, 3
/* 0FF614 7F0CAAE4 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FF618 7F0CAAE8 03190019 */  multu $t8, $t9
/* 0FF61C 7F0CAAEC 00001012 */  mflo  $v0
/* 0FF620 7F0CAAF0 00024040 */  sll   $t0, $v0, 1
/* 0FF624 7F0CAAF4 1000004C */  b     .L7F0CAC28
/* 0FF628 7F0CAAF8 01001025 */   move  $v0, $t0
.L7F0CAAFC:
/* 0FF62C 7F0CAAFC 8FA90044 */  lw    $t1, 0x44($sp)
/* 0FF630 7F0CAB00 26970007 */  addiu $s7, $s4, 7
/* 0FF634 7F0CAB04 32EA0FF8 */  andi  $t2, $s7, 0xff8
/* 0FF638 7F0CAB08 19200013 */  blez  $t1, .L7F0CAB58
/* 0FF63C 7F0CAB0C 0000B025 */   move  $s6, $zero
/* 0FF640 7F0CAB10 0140B825 */  move  $s7, $t2
.L7F0CAB14:
/* 0FF644 7F0CAB14 1A80000B */  blez  $s4, .L7F0CAB44
/* 0FF648 7F0CAB18 00008025 */   move  $s0, $zero
/* 0FF64C 7F0CAB1C 02A08825 */  move  $s1, $s5
.L7F0CAB20:
/* 0FF650 7F0CAB20 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF654 7F0CAB24 02402025 */   move  $a0, $s2
/* 0FF658 7F0CAB28 00025840 */  sll   $t3, $v0, 1
/* 0FF65C 7F0CAB2C 026B6021 */  addu  $t4, $s3, $t3
/* 0FF660 7F0CAB30 958D0000 */  lhu   $t5, ($t4)
/* 0FF664 7F0CAB34 26100001 */  addiu $s0, $s0, 1
/* 0FF668 7F0CAB38 26310001 */  addiu $s1, $s1, 1
/* 0FF66C 7F0CAB3C 1614FFF8 */  bne   $s0, $s4, .L7F0CAB20
/* 0FF670 7F0CAB40 A22DFFFF */   sb    $t5, -1($s1)
.L7F0CAB44:
/* 0FF674 7F0CAB44 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0FF678 7F0CAB48 26D60001 */  addiu $s6, $s6, 1
/* 0FF67C 7F0CAB4C 02B7A821 */  addu  $s5, $s5, $s7
/* 0FF680 7F0CAB50 16CEFFF0 */  bne   $s6, $t6, .L7F0CAB14
/* 0FF684 7F0CAB54 00000000 */   nop   
.L7F0CAB58:
/* 0FF688 7F0CAB58 8FB90044 */  lw    $t9, 0x44($sp)
/* 0FF68C 7F0CAB5C 268F0007 */  addiu $t7, $s4, 7
/* 0FF690 7F0CAB60 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 0FF694 7F0CAB64 03190019 */  multu $t8, $t9
/* 0FF698 7F0CAB68 00001012 */  mflo  $v0
/* 0FF69C 7F0CAB6C 1000002F */  b     .L7F0CAC2C
/* 0FF6A0 7F0CAB70 8FBF003C */   lw    $ra, 0x3c($sp)
.L7F0CAB74:
/* 0FF6A4 7F0CAB74 8FA80044 */  lw    $t0, 0x44($sp)
/* 0FF6A8 7F0CAB78 2697000F */  addiu $s7, $s4, 0xf
/* 0FF6AC 7F0CAB7C 32E90FF0 */  andi  $t1, $s7, 0xff0
/* 0FF6B0 7F0CAB80 19000021 */  blez  $t0, .L7F0CAC08
/* 0FF6B4 7F0CAB84 0000B025 */   move  $s6, $zero
/* 0FF6B8 7F0CAB88 0009B843 */  sra   $s7, $t1, 1
.L7F0CAB8C:
/* 0FF6BC 7F0CAB8C 1A800019 */  blez  $s4, .L7F0CABF4
/* 0FF6C0 7F0CAB90 00008025 */   move  $s0, $zero
.L7F0CAB94:
/* 0FF6C4 7F0CAB94 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF6C8 7F0CAB98 02402025 */   move  $a0, $s2
/* 0FF6CC 7F0CAB9C 00026040 */  sll   $t4, $v0, 1
/* 0FF6D0 7F0CABA0 026C6821 */  addu  $t5, $s3, $t4
/* 0FF6D4 7F0CABA4 95AE0000 */  lhu   $t6, ($t5)
/* 0FF6D8 7F0CABA8 00105843 */  sra   $t3, $s0, 1
/* 0FF6DC 7F0CABAC 26180001 */  addiu $t8, $s0, 1
/* 0FF6E0 7F0CABB0 02AB8821 */  addu  $s1, $s5, $t3
/* 0FF6E4 7F0CABB4 0314082A */  slt   $at, $t8, $s4
/* 0FF6E8 7F0CABB8 000E7900 */  sll   $t7, $t6, 4
/* 0FF6EC 7F0CABBC 10200009 */  beqz  $at, .L7F0CABE4
/* 0FF6F0 7F0CABC0 A22F0000 */   sb    $t7, ($s1)
/* 0FF6F4 7F0CABC4 0FC32FCB */  jal   sub_GAME_7F0CBF2C
/* 0FF6F8 7F0CABC8 02402025 */   move  $a0, $s2
/* 0FF6FC 7F0CABCC 00024040 */  sll   $t0, $v0, 1
/* 0FF700 7F0CABD0 02684821 */  addu  $t1, $s3, $t0
/* 0FF704 7F0CABD4 912A0001 */  lbu   $t2, 1($t1)
/* 0FF708 7F0CABD8 92390000 */  lbu   $t9, ($s1)
/* 0FF70C 7F0CABDC 032A5825 */  or    $t3, $t9, $t2
/* 0FF710 7F0CABE0 A22B0000 */  sb    $t3, ($s1)
.L7F0CABE4:
/* 0FF714 7F0CABE4 26100002 */  addiu $s0, $s0, 2
/* 0FF718 7F0CABE8 0214082A */  slt   $at, $s0, $s4
/* 0FF71C 7F0CABEC 1420FFE9 */  bnez  $at, .L7F0CAB94
/* 0FF720 7F0CABF0 00000000 */   nop   
.L7F0CABF4:
/* 0FF724 7F0CABF4 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0FF728 7F0CABF8 26D60001 */  addiu $s6, $s6, 1
/* 0FF72C 7F0CABFC 02B7A821 */  addu  $s5, $s5, $s7
/* 0FF730 7F0CAC00 16CCFFE2 */  bne   $s6, $t4, .L7F0CAB8C
/* 0FF734 7F0CAC04 00000000 */   nop   
.L7F0CAC08:
/* 0FF738 7F0CAC08 8FB80044 */  lw    $t8, 0x44($sp)
/* 0FF73C 7F0CAC0C 268D000F */  addiu $t5, $s4, 0xf
/* 0FF740 7F0CAC10 31AE0FF0 */  andi  $t6, $t5, 0xff0
/* 0FF744 7F0CAC14 000E7843 */  sra   $t7, $t6, 1
/* 0FF748 7F0CAC18 01F80019 */  multu $t7, $t8
/* 0FF74C 7F0CAC1C 00001012 */  mflo  $v0
/* 0FF750 7F0CAC20 10000002 */  b     .L7F0CAC2C
/* 0FF754 7F0CAC24 8FBF003C */   lw    $ra, 0x3c($sp)
def_7F0CA900:
.L7F0CAC28:
/* 0FF758 7F0CAC28 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F0CAC2C:
/* 0FF75C 7F0CAC2C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FF760 7F0CAC30 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FF764 7F0CAC34 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FF768 7F0CAC38 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FF76C 7F0CAC3C 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FF770 7F0CAC40 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FF774 7F0CAC44 8FB60030 */  lw    $s6, 0x30($sp)
/* 0FF778 7F0CAC48 8FB70034 */  lw    $s7, 0x34($sp)
/* 0FF77C 7F0CAC4C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0FF780 7F0CAC50 03E00008 */  jr    $ra
/* 0FF784 7F0CAC54 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





#ifdef NONMATCHING
void type6_7_generate_link_final_image(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BE0C*/
glabel jpt_8005BE0C
.word .L7F0CACC4
.word .L7F0CB0AC
.word .L7F0CAE90
.word .L7F0CB26C
.word .L7F0CB0AC
.word .L7F0CB3C4
.word .L7F0CB584
.word .L7F0CB3C4
.word .L7F0CB584
.text
glabel type6_7_generate_link_final_image
/* 0FF788 7F0CAC58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FF78C 7F0CAC5C AFB00004 */  sw    $s0, 4($sp)
/* 0FF790 7F0CAC60 8FB0003C */  lw    $s0, 0x3c($sp)
/* 0FF794 7F0CAC64 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FF798 7F0CAC68 AFB10008 */  sw    $s1, 8($sp)
/* 0FF79C 7F0CAC6C 2A010101 */  slti  $at, $s0, 0x101
/* 0FF7A0 7F0CAC70 00A08825 */  move  $s1, $a1
/* 0FF7A4 7F0CAC74 00C09025 */  move  $s2, $a2
/* 0FF7A8 7F0CAC78 AFA40028 */  sw    $a0, 0x28($sp)
/* 0FF7AC 7F0CAC7C 00E04825 */  move  $t1, $a3
/* 0FF7B0 7F0CAC80 00E05025 */  move  $t2, $a3
/* 0FF7B4 7F0CAC84 10200003 */  beqz  $at, .L7F0CAC94
/* 0FF7B8 7F0CAC88 00E05825 */   move  $t3, $a3
/* 0FF7BC 7F0CAC8C 10000003 */  b     .L7F0CAC9C
/* 0FF7C0 7F0CAC90 8FA50010 */   lw    $a1, 0x10($sp)
.L7F0CAC94:
/* 0FF7C4 7F0CAC94 8FA50028 */  lw    $a1, 0x28($sp)
/* 0FF7C8 7F0CAC98 8FA40014 */  lw    $a0, 0x14($sp)
.L7F0CAC9C:
/* 0FF7CC 7F0CAC9C 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0FF7D0 7F0CACA0 00001025 */  move  $v0, $zero
/* 0FF7D4 7F0CACA4 2DC10009 */  sltiu $at, $t6, 9
/* 0FF7D8 7F0CACA8 1020026F */  beqz  $at, .L7F0CB668
/* 0FF7DC 7F0CACAC 000E7080 */   sll   $t6, $t6, 2
/* 0FF7E0 7F0CACB0 3C018006 */  lui   $at, %hi(jpt_8005BE0C)
/* 0FF7E4 7F0CACB4 002E0821 */  addu  $at, $at, $t6
/* 0FF7E8 7F0CACB8 8C2EBE0C */  lw    $t6, %lo(jpt_8005BE0C)($at)
/* 0FF7EC 7F0CACBC 01C00008 */  jr    $t6
/* 0FF7F0 7F0CACC0 00000000 */   nop   
.L7F0CACC4:
/* 0FF7F4 7F0CACC4 1A40006B */  blez  $s2, .L7F0CAE74
/* 0FF7F8 7F0CACC8 00003825 */   move  $a3, $zero
/* 0FF7FC 7F0CACCC 262C0003 */  addiu $t4, $s1, 3
/* 0FF800 7F0CACD0 318F0FFC */  andi  $t7, $t4, 0xffc
/* 0FF804 7F0CACD4 000F6080 */  sll   $t4, $t7, 2
/* 0FF808 7F0CACD8 00114040 */  sll   $t0, $s1, 1
/* 0FF80C 7F0CACDC 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CACE0:
/* 0FF810 7F0CACE0 1A20005F */  blez  $s1, .L7F0CAE60
/* 0FF814 7F0CACE4 00001025 */   move  $v0, $zero
/* 0FF818 7F0CACE8 32260003 */  andi  $a2, $s1, 3
/* 0FF81C 7F0CACEC 10C00017 */  beqz  $a2, .L7F0CAD4C
/* 0FF820 7F0CACF0 00C05825 */   move  $t3, $a2
/* 0FF824 7F0CACF4 0000C880 */  sll   $t9, $zero, 2
/* 0FF828 7F0CACF8 01395021 */  addu  $t2, $t1, $t9
.L7F0CACFC:
/* 0FF82C 7F0CACFC 2A010101 */  slti  $at, $s0, 0x101
/* 0FF830 7F0CAD00 10200008 */  beqz  $at, .L7F0CAD24
/* 0FF834 7F0CAD04 00027840 */   sll   $t7, $v0, 1
/* 0FF838 7F0CAD08 00827021 */  addu  $t6, $a0, $v0
/* 0FF83C 7F0CAD0C 91CF0000 */  lbu   $t7, ($t6)
/* 0FF840 7F0CAD10 000FC080 */  sll   $t8, $t7, 2
/* 0FF844 7F0CAD14 0078C821 */  addu  $t9, $v1, $t8
/* 0FF848 7F0CAD18 8F2E0000 */  lw    $t6, ($t9)
/* 0FF84C 7F0CAD1C 10000007 */  b     .L7F0CAD3C
/* 0FF850 7F0CAD20 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAD24:
/* 0FF854 7F0CAD24 00AFC021 */  addu  $t8, $a1, $t7
/* 0FF858 7F0CAD28 97190000 */  lhu   $t9, ($t8)
/* 0FF85C 7F0CAD2C 00197080 */  sll   $t6, $t9, 2
/* 0FF860 7F0CAD30 006E7821 */  addu  $t7, $v1, $t6
/* 0FF864 7F0CAD34 8DF80000 */  lw    $t8, ($t7)
/* 0FF868 7F0CAD38 AD580000 */  sw    $t8, ($t2)
.L7F0CAD3C:
/* 0FF86C 7F0CAD3C 24420001 */  addiu $v0, $v0, 1
/* 0FF870 7F0CAD40 1562FFEE */  bne   $t3, $v0, .L7F0CACFC
/* 0FF874 7F0CAD44 254A0004 */   addiu $t2, $t2, 4
/* 0FF878 7F0CAD48 10510045 */  beq   $v0, $s1, .L7F0CAE60
.L7F0CAD4C:
/* 0FF87C 7F0CAD4C 0002C880 */   sll   $t9, $v0, 2
/* 0FF880 7F0CAD50 01395021 */  addu  $t2, $t1, $t9
.L7F0CAD54:
/* 0FF884 7F0CAD54 2A010101 */  slti  $at, $s0, 0x101
/* 0FF888 7F0CAD58 10200008 */  beqz  $at, .L7F0CAD7C
/* 0FF88C 7F0CAD5C 00027840 */   sll   $t7, $v0, 1
/* 0FF890 7F0CAD60 00827021 */  addu  $t6, $a0, $v0
/* 0FF894 7F0CAD64 91CF0000 */  lbu   $t7, ($t6)
/* 0FF898 7F0CAD68 000FC080 */  sll   $t8, $t7, 2
/* 0FF89C 7F0CAD6C 0078C821 */  addu  $t9, $v1, $t8
/* 0FF8A0 7F0CAD70 8F2E0000 */  lw    $t6, ($t9)
/* 0FF8A4 7F0CAD74 10000007 */  b     .L7F0CAD94
/* 0FF8A8 7F0CAD78 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAD7C:
/* 0FF8AC 7F0CAD7C 00AFC021 */  addu  $t8, $a1, $t7
/* 0FF8B0 7F0CAD80 97190000 */  lhu   $t9, ($t8)
/* 0FF8B4 7F0CAD84 00197080 */  sll   $t6, $t9, 2
/* 0FF8B8 7F0CAD88 006E7821 */  addu  $t7, $v1, $t6
/* 0FF8BC 7F0CAD8C 8DF80000 */  lw    $t8, ($t7)
/* 0FF8C0 7F0CAD90 AD580000 */  sw    $t8, ($t2)
.L7F0CAD94:
/* 0FF8C4 7F0CAD94 2A010101 */  slti  $at, $s0, 0x101
/* 0FF8C8 7F0CAD98 10200008 */  beqz  $at, .L7F0CADBC
/* 0FF8CC 7F0CAD9C 00027040 */   sll   $t6, $v0, 1
/* 0FF8D0 7F0CADA0 0082C821 */  addu  $t9, $a0, $v0
/* 0FF8D4 7F0CADA4 932E0001 */  lbu   $t6, 1($t9)
/* 0FF8D8 7F0CADA8 000E7880 */  sll   $t7, $t6, 2
/* 0FF8DC 7F0CADAC 006FC021 */  addu  $t8, $v1, $t7
/* 0FF8E0 7F0CADB0 8F190000 */  lw    $t9, ($t8)
/* 0FF8E4 7F0CADB4 10000007 */  b     .L7F0CADD4
/* 0FF8E8 7F0CADB8 AD590004 */   sw    $t9, 4($t2)
.L7F0CADBC:
/* 0FF8EC 7F0CADBC 00AE7821 */  addu  $t7, $a1, $t6
/* 0FF8F0 7F0CADC0 95F80002 */  lhu   $t8, 2($t7)
/* 0FF8F4 7F0CADC4 0018C880 */  sll   $t9, $t8, 2
/* 0FF8F8 7F0CADC8 00797021 */  addu  $t6, $v1, $t9
/* 0FF8FC 7F0CADCC 8DCF0000 */  lw    $t7, ($t6)
/* 0FF900 7F0CADD0 AD4F0004 */  sw    $t7, 4($t2)
.L7F0CADD4:
/* 0FF904 7F0CADD4 2A010101 */  slti  $at, $s0, 0x101
/* 0FF908 7F0CADD8 10200008 */  beqz  $at, .L7F0CADFC
/* 0FF90C 7F0CADDC 0002C840 */   sll   $t9, $v0, 1
/* 0FF910 7F0CADE0 0082C021 */  addu  $t8, $a0, $v0
/* 0FF914 7F0CADE4 93190002 */  lbu   $t9, 2($t8)
/* 0FF918 7F0CADE8 00197080 */  sll   $t6, $t9, 2
/* 0FF91C 7F0CADEC 006E7821 */  addu  $t7, $v1, $t6
/* 0FF920 7F0CADF0 8DF80000 */  lw    $t8, ($t7)
/* 0FF924 7F0CADF4 10000007 */  b     .L7F0CAE14
/* 0FF928 7F0CADF8 AD580008 */   sw    $t8, 8($t2)
.L7F0CADFC:
/* 0FF92C 7F0CADFC 00B97021 */  addu  $t6, $a1, $t9
/* 0FF930 7F0CAE00 95CF0004 */  lhu   $t7, 4($t6)
/* 0FF934 7F0CAE04 000FC080 */  sll   $t8, $t7, 2
/* 0FF938 7F0CAE08 0078C821 */  addu  $t9, $v1, $t8
/* 0FF93C 7F0CAE0C 8F2E0000 */  lw    $t6, ($t9)
/* 0FF940 7F0CAE10 AD4E0008 */  sw    $t6, 8($t2)
.L7F0CAE14:
/* 0FF944 7F0CAE14 2A010101 */  slti  $at, $s0, 0x101
/* 0FF948 7F0CAE18 10200008 */  beqz  $at, .L7F0CAE3C
/* 0FF94C 7F0CAE1C 0002C040 */   sll   $t8, $v0, 1
/* 0FF950 7F0CAE20 00827821 */  addu  $t7, $a0, $v0
/* 0FF954 7F0CAE24 91F80003 */  lbu   $t8, 3($t7)
/* 0FF958 7F0CAE28 0018C880 */  sll   $t9, $t8, 2
/* 0FF95C 7F0CAE2C 00797021 */  addu  $t6, $v1, $t9
/* 0FF960 7F0CAE30 8DCF0000 */  lw    $t7, ($t6)
/* 0FF964 7F0CAE34 10000007 */  b     .L7F0CAE54
/* 0FF968 7F0CAE38 AD4F000C */   sw    $t7, 0xc($t2)
.L7F0CAE3C:
/* 0FF96C 7F0CAE3C 00B8C821 */  addu  $t9, $a1, $t8
/* 0FF970 7F0CAE40 972E0006 */  lhu   $t6, 6($t9)
/* 0FF974 7F0CAE44 000E7880 */  sll   $t7, $t6, 2
/* 0FF978 7F0CAE48 006FC021 */  addu  $t8, $v1, $t7
/* 0FF97C 7F0CAE4C 8F190000 */  lw    $t9, ($t8)
/* 0FF980 7F0CAE50 AD59000C */  sw    $t9, 0xc($t2)
.L7F0CAE54:
/* 0FF984 7F0CAE54 24420004 */  addiu $v0, $v0, 4
/* 0FF988 7F0CAE58 1451FFBE */  bne   $v0, $s1, .L7F0CAD54
/* 0FF98C 7F0CAE5C 254A0010 */   addiu $t2, $t2, 0x10
.L7F0CAE60:
/* 0FF990 7F0CAE60 24E70001 */  addiu $a3, $a3, 1
/* 0FF994 7F0CAE64 012C4821 */  addu  $t1, $t1, $t4
/* 0FF998 7F0CAE68 00912021 */  addu  $a0, $a0, $s1
/* 0FF99C 7F0CAE6C 14F2FF9C */  bne   $a3, $s2, .L7F0CACE0
/* 0FF9A0 7F0CAE70 00A82821 */   addu  $a1, $a1, $t0
.L7F0CAE74:
/* 0FF9A4 7F0CAE74 262E0003 */  addiu $t6, $s1, 3
/* 0FF9A8 7F0CAE78 31CF0FFC */  andi  $t7, $t6, 0xffc
/* 0FF9AC 7F0CAE7C 01F20019 */  multu $t7, $s2
/* 0FF9B0 7F0CAE80 00001012 */  mflo  $v0
/* 0FF9B4 7F0CAE84 0002C080 */  sll   $t8, $v0, 2
/* 0FF9B8 7F0CAE88 100001F7 */  b     .L7F0CB668
/* 0FF9BC 7F0CAE8C 03001025 */   move  $v0, $t8
.L7F0CAE90:
/* 0FF9C0 7F0CAE90 1A40007F */  blez  $s2, .L7F0CB090
/* 0FF9C4 7F0CAE94 00003825 */   move  $a3, $zero
/* 0FF9C8 7F0CAE98 262C0003 */  addiu $t4, $s1, 3
/* 0FF9CC 7F0CAE9C 31990FFC */  andi  $t9, $t4, 0xffc
/* 0FF9D0 7F0CAEA0 00196080 */  sll   $t4, $t9, 2
/* 0FF9D4 7F0CAEA4 00114040 */  sll   $t0, $s1, 1
/* 0FF9D8 7F0CAEA8 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CAEAC:
/* 0FF9DC 7F0CAEAC 1A200073 */  blez  $s1, .L7F0CB07C
/* 0FF9E0 7F0CAEB0 00001025 */   move  $v0, $zero
/* 0FF9E4 7F0CAEB4 32260003 */  andi  $a2, $s1, 3
/* 0FF9E8 7F0CAEB8 10C0001B */  beqz  $a2, .L7F0CAF28
/* 0FF9EC 7F0CAEBC 00C05825 */   move  $t3, $a2
/* 0FF9F0 7F0CAEC0 00007880 */  sll   $t7, $zero, 2
/* 0FF9F4 7F0CAEC4 012F5021 */  addu  $t2, $t1, $t7
.L7F0CAEC8:
/* 0FF9F8 7F0CAEC8 2A010101 */  slti  $at, $s0, 0x101
/* 0FF9FC 7F0CAECC 1020000A */  beqz  $at, .L7F0CAEF8
/* 0FFA00 7F0CAED0 00027840 */   sll   $t7, $v0, 1
/* 0FFA04 7F0CAED4 0082C021 */  addu  $t8, $a0, $v0
/* 0FFA08 7F0CAED8 93190000 */  lbu   $t9, ($t8)
/* 0FFA0C 7F0CAEDC 00197080 */  sll   $t6, $t9, 2
/* 0FFA10 7F0CAEE0 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA14 7F0CAEE4 8DF80000 */  lw    $t8, ($t7)
/* 0FFA18 7F0CAEE8 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA1C 7F0CAEEC 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA20 7F0CAEF0 10000009 */  b     .L7F0CAF18
/* 0FFA24 7F0CAEF4 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAEF8:
/* 0FFA28 7F0CAEF8 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFA2C 7F0CAEFC 97190000 */  lhu   $t9, ($t8)
/* 0FFA30 7F0CAF00 00197080 */  sll   $t6, $t9, 2
/* 0FFA34 7F0CAF04 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA38 7F0CAF08 8DF80000 */  lw    $t8, ($t7)
/* 0FFA3C 7F0CAF0C 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA40 7F0CAF10 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA44 7F0CAF14 AD4E0000 */  sw    $t6, ($t2)
.L7F0CAF18:
/* 0FFA48 7F0CAF18 24420001 */  addiu $v0, $v0, 1
/* 0FFA4C 7F0CAF1C 1562FFEA */  bne   $t3, $v0, .L7F0CAEC8
/* 0FFA50 7F0CAF20 254A0004 */   addiu $t2, $t2, 4
/* 0FFA54 7F0CAF24 10510055 */  beq   $v0, $s1, .L7F0CB07C
.L7F0CAF28:
/* 0FFA58 7F0CAF28 00027880 */   sll   $t7, $v0, 2
/* 0FFA5C 7F0CAF2C 012F5021 */  addu  $t2, $t1, $t7
.L7F0CAF30:
/* 0FFA60 7F0CAF30 2A010101 */  slti  $at, $s0, 0x101
/* 0FFA64 7F0CAF34 1020000A */  beqz  $at, .L7F0CAF60
/* 0FFA68 7F0CAF38 00027840 */   sll   $t7, $v0, 1
/* 0FFA6C 7F0CAF3C 0082C021 */  addu  $t8, $a0, $v0
/* 0FFA70 7F0CAF40 93190000 */  lbu   $t9, ($t8)
/* 0FFA74 7F0CAF44 00197080 */  sll   $t6, $t9, 2
/* 0FFA78 7F0CAF48 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA7C 7F0CAF4C 8DF80000 */  lw    $t8, ($t7)
/* 0FFA80 7F0CAF50 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA84 7F0CAF54 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA88 7F0CAF58 10000009 */  b     .L7F0CAF80
/* 0FFA8C 7F0CAF5C AD4E0000 */   sw    $t6, ($t2)
.L7F0CAF60:
/* 0FFA90 7F0CAF60 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFA94 7F0CAF64 97190000 */  lhu   $t9, ($t8)
/* 0FFA98 7F0CAF68 00197080 */  sll   $t6, $t9, 2
/* 0FFA9C 7F0CAF6C 006E7821 */  addu  $t7, $v1, $t6
/* 0FFAA0 7F0CAF70 8DF80000 */  lw    $t8, ($t7)
/* 0FFAA4 7F0CAF74 0018CA00 */  sll   $t9, $t8, 8
/* 0FFAA8 7F0CAF78 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFAAC 7F0CAF7C AD4E0000 */  sw    $t6, ($t2)
.L7F0CAF80:
/* 0FFAB0 7F0CAF80 2A010101 */  slti  $at, $s0, 0x101
/* 0FFAB4 7F0CAF84 1020000A */  beqz  $at, .L7F0CAFB0
/* 0FFAB8 7F0CAF88 00027040 */   sll   $t6, $v0, 1
/* 0FFABC 7F0CAF8C 00827821 */  addu  $t7, $a0, $v0
/* 0FFAC0 7F0CAF90 91F80001 */  lbu   $t8, 1($t7)
/* 0FFAC4 7F0CAF94 0018C880 */  sll   $t9, $t8, 2
/* 0FFAC8 7F0CAF98 00797021 */  addu  $t6, $v1, $t9
/* 0FFACC 7F0CAF9C 8DCF0000 */  lw    $t7, ($t6)
/* 0FFAD0 7F0CAFA0 000FC200 */  sll   $t8, $t7, 8
/* 0FFAD4 7F0CAFA4 371900FF */  ori   $t9, $t8, 0xff
/* 0FFAD8 7F0CAFA8 10000009 */  b     .L7F0CAFD0
/* 0FFADC 7F0CAFAC AD590004 */   sw    $t9, 4($t2)
.L7F0CAFB0:
/* 0FFAE0 7F0CAFB0 00AE7821 */  addu  $t7, $a1, $t6
/* 0FFAE4 7F0CAFB4 95F80002 */  lhu   $t8, 2($t7)
/* 0FFAE8 7F0CAFB8 0018C880 */  sll   $t9, $t8, 2
/* 0FFAEC 7F0CAFBC 00797021 */  addu  $t6, $v1, $t9
/* 0FFAF0 7F0CAFC0 8DCF0000 */  lw    $t7, ($t6)
/* 0FFAF4 7F0CAFC4 000FC200 */  sll   $t8, $t7, 8
/* 0FFAF8 7F0CAFC8 371900FF */  ori   $t9, $t8, 0xff
/* 0FFAFC 7F0CAFCC AD590004 */  sw    $t9, 4($t2)
.L7F0CAFD0:
/* 0FFB00 7F0CAFD0 2A010101 */  slti  $at, $s0, 0x101
/* 0FFB04 7F0CAFD4 1020000A */  beqz  $at, .L7F0CB000
/* 0FFB08 7F0CAFD8 0002C840 */   sll   $t9, $v0, 1
/* 0FFB0C 7F0CAFDC 00827021 */  addu  $t6, $a0, $v0
/* 0FFB10 7F0CAFE0 91CF0002 */  lbu   $t7, 2($t6)
/* 0FFB14 7F0CAFE4 000FC080 */  sll   $t8, $t7, 2
/* 0FFB18 7F0CAFE8 0078C821 */  addu  $t9, $v1, $t8
/* 0FFB1C 7F0CAFEC 8F2E0000 */  lw    $t6, ($t9)
/* 0FFB20 7F0CAFF0 000E7A00 */  sll   $t7, $t6, 8
/* 0FFB24 7F0CAFF4 35F800FF */  ori   $t8, $t7, 0xff
/* 0FFB28 7F0CAFF8 10000009 */  b     .L7F0CB020
/* 0FFB2C 7F0CAFFC AD580008 */   sw    $t8, 8($t2)
.L7F0CB000:
/* 0FFB30 7F0CB000 00B97021 */  addu  $t6, $a1, $t9
/* 0FFB34 7F0CB004 95CF0004 */  lhu   $t7, 4($t6)
/* 0FFB38 7F0CB008 000FC080 */  sll   $t8, $t7, 2
/* 0FFB3C 7F0CB00C 0078C821 */  addu  $t9, $v1, $t8
/* 0FFB40 7F0CB010 8F2E0000 */  lw    $t6, ($t9)
/* 0FFB44 7F0CB014 000E7A00 */  sll   $t7, $t6, 8
/* 0FFB48 7F0CB018 35F800FF */  ori   $t8, $t7, 0xff
/* 0FFB4C 7F0CB01C AD580008 */  sw    $t8, 8($t2)
.L7F0CB020:
/* 0FFB50 7F0CB020 2A010101 */  slti  $at, $s0, 0x101
/* 0FFB54 7F0CB024 1020000A */  beqz  $at, .L7F0CB050
/* 0FFB58 7F0CB028 0002C040 */   sll   $t8, $v0, 1
/* 0FFB5C 7F0CB02C 0082C821 */  addu  $t9, $a0, $v0
/* 0FFB60 7F0CB030 932E0003 */  lbu   $t6, 3($t9)
/* 0FFB64 7F0CB034 000E7880 */  sll   $t7, $t6, 2
/* 0FFB68 7F0CB038 006FC021 */  addu  $t8, $v1, $t7
/* 0FFB6C 7F0CB03C 8F190000 */  lw    $t9, ($t8)
/* 0FFB70 7F0CB040 00197200 */  sll   $t6, $t9, 8
/* 0FFB74 7F0CB044 35CF00FF */  ori   $t7, $t6, 0xff
/* 0FFB78 7F0CB048 10000009 */  b     .L7F0CB070
/* 0FFB7C 7F0CB04C AD4F000C */   sw    $t7, 0xc($t2)
.L7F0CB050:
/* 0FFB80 7F0CB050 00B8C821 */  addu  $t9, $a1, $t8
/* 0FFB84 7F0CB054 972E0006 */  lhu   $t6, 6($t9)
/* 0FFB88 7F0CB058 000E7880 */  sll   $t7, $t6, 2
/* 0FFB8C 7F0CB05C 006FC021 */  addu  $t8, $v1, $t7
/* 0FFB90 7F0CB060 8F190000 */  lw    $t9, ($t8)
/* 0FFB94 7F0CB064 00197200 */  sll   $t6, $t9, 8
/* 0FFB98 7F0CB068 35CF00FF */  ori   $t7, $t6, 0xff
/* 0FFB9C 7F0CB06C AD4F000C */  sw    $t7, 0xc($t2)
.L7F0CB070:
/* 0FFBA0 7F0CB070 24420004 */  addiu $v0, $v0, 4
/* 0FFBA4 7F0CB074 1451FFAE */  bne   $v0, $s1, .L7F0CAF30
/* 0FFBA8 7F0CB078 254A0010 */   addiu $t2, $t2, 0x10
.L7F0CB07C:
/* 0FFBAC 7F0CB07C 24E70001 */  addiu $a3, $a3, 1
/* 0FFBB0 7F0CB080 012C4821 */  addu  $t1, $t1, $t4
/* 0FFBB4 7F0CB084 00912021 */  addu  $a0, $a0, $s1
/* 0FFBB8 7F0CB088 14F2FF88 */  bne   $a3, $s2, .L7F0CAEAC
/* 0FFBBC 7F0CB08C 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB090:
/* 0FFBC0 7F0CB090 26380003 */  addiu $t8, $s1, 3
/* 0FFBC4 7F0CB094 33190FFC */  andi  $t9, $t8, 0xffc
/* 0FFBC8 7F0CB098 03320019 */  multu $t9, $s2
/* 0FFBCC 7F0CB09C 00001012 */  mflo  $v0
/* 0FFBD0 7F0CB0A0 00027080 */  sll   $t6, $v0, 2
/* 0FFBD4 7F0CB0A4 10000170 */  b     .L7F0CB668
/* 0FFBD8 7F0CB0A8 01C01025 */   move  $v0, $t6
.L7F0CB0AC:
/* 0FFBDC 7F0CB0AC 1A400068 */  blez  $s2, .L7F0CB250
/* 0FFBE0 7F0CB0B0 00003825 */   move  $a3, $zero
/* 0FFBE4 7F0CB0B4 262D0003 */  addiu $t5, $s1, 3
/* 0FFBE8 7F0CB0B8 31AF0FFC */  andi  $t7, $t5, 0xffc
/* 0FFBEC 7F0CB0BC 000F6840 */  sll   $t5, $t7, 1
/* 0FFBF0 7F0CB0C0 00114040 */  sll   $t0, $s1, 1
/* 0FFBF4 7F0CB0C4 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB0C8:
/* 0FFBF8 7F0CB0C8 1A20005C */  blez  $s1, .L7F0CB23C
/* 0FFBFC 7F0CB0CC 00001025 */   move  $v0, $zero
/* 0FFC00 7F0CB0D0 32260003 */  andi  $a2, $s1, 3
/* 0FFC04 7F0CB0D4 10C00017 */  beqz  $a2, .L7F0CB134
/* 0FFC08 7F0CB0D8 00C06025 */   move  $t4, $a2
/* 0FFC0C 7F0CB0DC 00004840 */  sll   $t1, $zero, 1
/* 0FFC10 7F0CB0E0 01495821 */  addu  $t3, $t2, $t1
.L7F0CB0E4:
/* 0FFC14 7F0CB0E4 2A010101 */  slti  $at, $s0, 0x101
/* 0FFC18 7F0CB0E8 10200008 */  beqz  $at, .L7F0CB10C
/* 0FFC1C 7F0CB0EC 00A97021 */   addu  $t6, $a1, $t1
/* 0FFC20 7F0CB0F0 0082C821 */  addu  $t9, $a0, $v0
/* 0FFC24 7F0CB0F4 932E0000 */  lbu   $t6, ($t9)
/* 0FFC28 7F0CB0F8 000E7840 */  sll   $t7, $t6, 1
/* 0FFC2C 7F0CB0FC 006FC021 */  addu  $t8, $v1, $t7
/* 0FFC30 7F0CB100 97190000 */  lhu   $t9, ($t8)
/* 0FFC34 7F0CB104 10000006 */  b     .L7F0CB120
/* 0FFC38 7F0CB108 A5790000 */   sh    $t9, ($t3)
.L7F0CB10C:
/* 0FFC3C 7F0CB10C 95CF0000 */  lhu   $t7, ($t6)
/* 0FFC40 7F0CB110 000FC040 */  sll   $t8, $t7, 1
/* 0FFC44 7F0CB114 0078C821 */  addu  $t9, $v1, $t8
/* 0FFC48 7F0CB118 972E0000 */  lhu   $t6, ($t9)
/* 0FFC4C 7F0CB11C A56E0000 */  sh    $t6, ($t3)
.L7F0CB120:
/* 0FFC50 7F0CB120 24420001 */  addiu $v0, $v0, 1
/* 0FFC54 7F0CB124 25290002 */  addiu $t1, $t1, 2
/* 0FFC58 7F0CB128 1582FFEE */  bne   $t4, $v0, .L7F0CB0E4
/* 0FFC5C 7F0CB12C 256B0002 */   addiu $t3, $t3, 2
/* 0FFC60 7F0CB130 10510042 */  beq   $v0, $s1, .L7F0CB23C
.L7F0CB134:
/* 0FFC64 7F0CB134 00024840 */   sll   $t1, $v0, 1
/* 0FFC68 7F0CB138 01495821 */  addu  $t3, $t2, $t1
.L7F0CB13C:
/* 0FFC6C 7F0CB13C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFC70 7F0CB140 10200008 */  beqz  $at, .L7F0CB164
/* 0FFC74 7F0CB144 00A9C021 */   addu  $t8, $a1, $t1
/* 0FFC78 7F0CB148 00827821 */  addu  $t7, $a0, $v0
/* 0FFC7C 7F0CB14C 91F80000 */  lbu   $t8, ($t7)
/* 0FFC80 7F0CB150 0018C840 */  sll   $t9, $t8, 1
/* 0FFC84 7F0CB154 00797021 */  addu  $t6, $v1, $t9
/* 0FFC88 7F0CB158 95CF0000 */  lhu   $t7, ($t6)
/* 0FFC8C 7F0CB15C 10000006 */  b     .L7F0CB178
/* 0FFC90 7F0CB160 A56F0000 */   sh    $t7, ($t3)
.L7F0CB164:
/* 0FFC94 7F0CB164 97190000 */  lhu   $t9, ($t8)
/* 0FFC98 7F0CB168 00197040 */  sll   $t6, $t9, 1
/* 0FFC9C 7F0CB16C 006E7821 */  addu  $t7, $v1, $t6
/* 0FFCA0 7F0CB170 95F80000 */  lhu   $t8, ($t7)
/* 0FFCA4 7F0CB174 A5780000 */  sh    $t8, ($t3)
.L7F0CB178:
/* 0FFCA8 7F0CB178 2A010101 */  slti  $at, $s0, 0x101
/* 0FFCAC 7F0CB17C 10200008 */  beqz  $at, .L7F0CB1A0
/* 0FFCB0 7F0CB180 00A97021 */   addu  $t6, $a1, $t1
/* 0FFCB4 7F0CB184 0082C821 */  addu  $t9, $a0, $v0
/* 0FFCB8 7F0CB188 932E0001 */  lbu   $t6, 1($t9)
/* 0FFCBC 7F0CB18C 000E7840 */  sll   $t7, $t6, 1
/* 0FFCC0 7F0CB190 006FC021 */  addu  $t8, $v1, $t7
/* 0FFCC4 7F0CB194 97190000 */  lhu   $t9, ($t8)
/* 0FFCC8 7F0CB198 10000006 */  b     .L7F0CB1B4
/* 0FFCCC 7F0CB19C A5790002 */   sh    $t9, 2($t3)
.L7F0CB1A0:
/* 0FFCD0 7F0CB1A0 95CF0002 */  lhu   $t7, 2($t6)
/* 0FFCD4 7F0CB1A4 000FC040 */  sll   $t8, $t7, 1
/* 0FFCD8 7F0CB1A8 0078C821 */  addu  $t9, $v1, $t8
/* 0FFCDC 7F0CB1AC 972E0000 */  lhu   $t6, ($t9)
/* 0FFCE0 7F0CB1B0 A56E0002 */  sh    $t6, 2($t3)
.L7F0CB1B4:
/* 0FFCE4 7F0CB1B4 2A010101 */  slti  $at, $s0, 0x101
/* 0FFCE8 7F0CB1B8 10200008 */  beqz  $at, .L7F0CB1DC
/* 0FFCEC 7F0CB1BC 00A9C021 */   addu  $t8, $a1, $t1
/* 0FFCF0 7F0CB1C0 00827821 */  addu  $t7, $a0, $v0
/* 0FFCF4 7F0CB1C4 91F80002 */  lbu   $t8, 2($t7)
/* 0FFCF8 7F0CB1C8 0018C840 */  sll   $t9, $t8, 1
/* 0FFCFC 7F0CB1CC 00797021 */  addu  $t6, $v1, $t9
/* 0FFD00 7F0CB1D0 95CF0000 */  lhu   $t7, ($t6)
/* 0FFD04 7F0CB1D4 10000006 */  b     .L7F0CB1F0
/* 0FFD08 7F0CB1D8 A56F0004 */   sh    $t7, 4($t3)
.L7F0CB1DC:
/* 0FFD0C 7F0CB1DC 97190004 */  lhu   $t9, 4($t8)
/* 0FFD10 7F0CB1E0 00197040 */  sll   $t6, $t9, 1
/* 0FFD14 7F0CB1E4 006E7821 */  addu  $t7, $v1, $t6
/* 0FFD18 7F0CB1E8 95F80000 */  lhu   $t8, ($t7)
/* 0FFD1C 7F0CB1EC A5780004 */  sh    $t8, 4($t3)
.L7F0CB1F0:
/* 0FFD20 7F0CB1F0 2A010101 */  slti  $at, $s0, 0x101
/* 0FFD24 7F0CB1F4 10200008 */  beqz  $at, .L7F0CB218
/* 0FFD28 7F0CB1F8 00A97021 */   addu  $t6, $a1, $t1
/* 0FFD2C 7F0CB1FC 0082C821 */  addu  $t9, $a0, $v0
/* 0FFD30 7F0CB200 932E0003 */  lbu   $t6, 3($t9)
/* 0FFD34 7F0CB204 000E7840 */  sll   $t7, $t6, 1
/* 0FFD38 7F0CB208 006FC021 */  addu  $t8, $v1, $t7
/* 0FFD3C 7F0CB20C 97190000 */  lhu   $t9, ($t8)
/* 0FFD40 7F0CB210 10000006 */  b     .L7F0CB22C
/* 0FFD44 7F0CB214 A5790006 */   sh    $t9, 6($t3)
.L7F0CB218:
/* 0FFD48 7F0CB218 95CF0006 */  lhu   $t7, 6($t6)
/* 0FFD4C 7F0CB21C 000FC040 */  sll   $t8, $t7, 1
/* 0FFD50 7F0CB220 0078C821 */  addu  $t9, $v1, $t8
/* 0FFD54 7F0CB224 972E0000 */  lhu   $t6, ($t9)
/* 0FFD58 7F0CB228 A56E0006 */  sh    $t6, 6($t3)
.L7F0CB22C:
/* 0FFD5C 7F0CB22C 24420004 */  addiu $v0, $v0, 4
/* 0FFD60 7F0CB230 25290008 */  addiu $t1, $t1, 8
/* 0FFD64 7F0CB234 1451FFC1 */  bne   $v0, $s1, .L7F0CB13C
/* 0FFD68 7F0CB238 256B0008 */   addiu $t3, $t3, 8
.L7F0CB23C:
/* 0FFD6C 7F0CB23C 24E70001 */  addiu $a3, $a3, 1
/* 0FFD70 7F0CB240 014D5021 */  addu  $t2, $t2, $t5
/* 0FFD74 7F0CB244 00912021 */  addu  $a0, $a0, $s1
/* 0FFD78 7F0CB248 14F2FF9F */  bne   $a3, $s2, .L7F0CB0C8
/* 0FFD7C 7F0CB24C 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB250:
/* 0FFD80 7F0CB250 262F0003 */  addiu $t7, $s1, 3
/* 0FFD84 7F0CB254 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FFD88 7F0CB258 03120019 */  multu $t8, $s2
/* 0FFD8C 7F0CB25C 00001012 */  mflo  $v0
/* 0FFD90 7F0CB260 0002C840 */  sll   $t9, $v0, 1
/* 0FFD94 7F0CB264 10000100 */  b     .L7F0CB668
/* 0FFD98 7F0CB268 03201025 */   move  $v0, $t9
.L7F0CB26C:
/* 0FFD9C 7F0CB26C 1A40004E */  blez  $s2, .L7F0CB3A8
/* 0FFDA0 7F0CB270 00003825 */   move  $a3, $zero
/* 0FFDA4 7F0CB274 262D0003 */  addiu $t5, $s1, 3
/* 0FFDA8 7F0CB278 31AE0FFC */  andi  $t6, $t5, 0xffc
/* 0FFDAC 7F0CB27C 000E6840 */  sll   $t5, $t6, 1
/* 0FFDB0 7F0CB280 00114040 */  sll   $t0, $s1, 1
/* 0FFDB4 7F0CB284 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB288:
/* 0FFDB8 7F0CB288 1A200042 */  blez  $s1, .L7F0CB394
/* 0FFDBC 7F0CB28C 00001025 */   move  $v0, $zero
/* 0FFDC0 7F0CB290 32260001 */  andi  $a2, $s1, 1
/* 0FFDC4 7F0CB294 10C00013 */  beqz  $a2, .L7F0CB2E4
/* 0FFDC8 7F0CB298 2A010101 */   slti  $at, $s0, 0x101
/* 0FFDCC 7F0CB29C 10200009 */  beqz  $at, .L7F0CB2C4
/* 0FFDD0 7F0CB2A0 24020001 */   li    $v0, 1
/* 0FFDD4 7F0CB2A4 90980000 */  lbu   $t8, ($a0)
/* 0FFDD8 7F0CB2A8 0018C840 */  sll   $t9, $t8, 1
/* 0FFDDC 7F0CB2AC 00797021 */  addu  $t6, $v1, $t9
/* 0FFDE0 7F0CB2B0 95CF0000 */  lhu   $t7, ($t6)
/* 0FFDE4 7F0CB2B4 000FC040 */  sll   $t8, $t7, 1
/* 0FFDE8 7F0CB2B8 37190001 */  ori   $t9, $t8, 1
/* 0FFDEC 7F0CB2BC 10000008 */  b     .L7F0CB2E0
/* 0FFDF0 7F0CB2C0 A5590000 */   sh    $t9, ($t2)
.L7F0CB2C4:
/* 0FFDF4 7F0CB2C4 94AE0000 */  lhu   $t6, ($a1)
/* 0FFDF8 7F0CB2C8 000E7840 */  sll   $t7, $t6, 1
/* 0FFDFC 7F0CB2CC 006FC021 */  addu  $t8, $v1, $t7
/* 0FFE00 7F0CB2D0 97190000 */  lhu   $t9, ($t8)
/* 0FFE04 7F0CB2D4 00197040 */  sll   $t6, $t9, 1
/* 0FFE08 7F0CB2D8 35CF0001 */  ori   $t7, $t6, 1
/* 0FFE0C 7F0CB2DC A54F0000 */  sh    $t7, ($t2)
.L7F0CB2E0:
/* 0FFE10 7F0CB2E0 1051002C */  beq   $v0, $s1, .L7F0CB394
.L7F0CB2E4:
/* 0FFE14 7F0CB2E4 00024840 */   sll   $t1, $v0, 1
/* 0FFE18 7F0CB2E8 01495821 */  addu  $t3, $t2, $t1
.L7F0CB2EC:
/* 0FFE1C 7F0CB2EC 2A010101 */  slti  $at, $s0, 0x101
/* 0FFE20 7F0CB2F0 1020000A */  beqz  $at, .L7F0CB31C
/* 0FFE24 7F0CB2F4 00A97821 */   addu  $t7, $a1, $t1
/* 0FFE28 7F0CB2F8 0082C021 */  addu  $t8, $a0, $v0
/* 0FFE2C 7F0CB2FC 93190000 */  lbu   $t9, ($t8)
/* 0FFE30 7F0CB300 00197040 */  sll   $t6, $t9, 1
/* 0FFE34 7F0CB304 006E7821 */  addu  $t7, $v1, $t6
/* 0FFE38 7F0CB308 95F80000 */  lhu   $t8, ($t7)
/* 0FFE3C 7F0CB30C 0018C840 */  sll   $t9, $t8, 1
/* 0FFE40 7F0CB310 372E0001 */  ori   $t6, $t9, 1
/* 0FFE44 7F0CB314 10000008 */  b     .L7F0CB338
/* 0FFE48 7F0CB318 A56E0000 */   sh    $t6, ($t3)
.L7F0CB31C:
/* 0FFE4C 7F0CB31C 95F80000 */  lhu   $t8, ($t7)
/* 0FFE50 7F0CB320 0018C840 */  sll   $t9, $t8, 1
/* 0FFE54 7F0CB324 00797021 */  addu  $t6, $v1, $t9
/* 0FFE58 7F0CB328 95CF0000 */  lhu   $t7, ($t6)
/* 0FFE5C 7F0CB32C 000FC040 */  sll   $t8, $t7, 1
/* 0FFE60 7F0CB330 37190001 */  ori   $t9, $t8, 1
/* 0FFE64 7F0CB334 A5790000 */  sh    $t9, ($t3)
.L7F0CB338:
/* 0FFE68 7F0CB338 2A010101 */  slti  $at, $s0, 0x101
/* 0FFE6C 7F0CB33C 1020000A */  beqz  $at, .L7F0CB368
/* 0FFE70 7F0CB340 00A9C821 */   addu  $t9, $a1, $t1
/* 0FFE74 7F0CB344 00827021 */  addu  $t6, $a0, $v0
/* 0FFE78 7F0CB348 91CF0001 */  lbu   $t7, 1($t6)
/* 0FFE7C 7F0CB34C 000FC040 */  sll   $t8, $t7, 1
/* 0FFE80 7F0CB350 0078C821 */  addu  $t9, $v1, $t8
/* 0FFE84 7F0CB354 972E0000 */  lhu   $t6, ($t9)
/* 0FFE88 7F0CB358 000E7840 */  sll   $t7, $t6, 1
/* 0FFE8C 7F0CB35C 35F80001 */  ori   $t8, $t7, 1
/* 0FFE90 7F0CB360 10000008 */  b     .L7F0CB384
/* 0FFE94 7F0CB364 A5780002 */   sh    $t8, 2($t3)
.L7F0CB368:
/* 0FFE98 7F0CB368 972E0002 */  lhu   $t6, 2($t9)
/* 0FFE9C 7F0CB36C 000E7840 */  sll   $t7, $t6, 1
/* 0FFEA0 7F0CB370 006FC021 */  addu  $t8, $v1, $t7
/* 0FFEA4 7F0CB374 97190000 */  lhu   $t9, ($t8)
/* 0FFEA8 7F0CB378 00197040 */  sll   $t6, $t9, 1
/* 0FFEAC 7F0CB37C 35CF0001 */  ori   $t7, $t6, 1
/* 0FFEB0 7F0CB380 A56F0002 */  sh    $t7, 2($t3)
.L7F0CB384:
/* 0FFEB4 7F0CB384 24420002 */  addiu $v0, $v0, 2
/* 0FFEB8 7F0CB388 25290004 */  addiu $t1, $t1, 4
/* 0FFEBC 7F0CB38C 1451FFD7 */  bne   $v0, $s1, .L7F0CB2EC
/* 0FFEC0 7F0CB390 256B0004 */   addiu $t3, $t3, 4
.L7F0CB394:
/* 0FFEC4 7F0CB394 24E70001 */  addiu $a3, $a3, 1
/* 0FFEC8 7F0CB398 014D5021 */  addu  $t2, $t2, $t5
/* 0FFECC 7F0CB39C 00912021 */  addu  $a0, $a0, $s1
/* 0FFED0 7F0CB3A0 14F2FFB9 */  bne   $a3, $s2, .L7F0CB288
/* 0FFED4 7F0CB3A4 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB3A8:
/* 0FFED8 7F0CB3A8 26380003 */  addiu $t8, $s1, 3
/* 0FFEDC 7F0CB3AC 33190FFC */  andi  $t9, $t8, 0xffc
/* 0FFEE0 7F0CB3B0 03320019 */  multu $t9, $s2
/* 0FFEE4 7F0CB3B4 00001012 */  mflo  $v0
/* 0FFEE8 7F0CB3B8 00027040 */  sll   $t6, $v0, 1
/* 0FFEEC 7F0CB3BC 100000AA */  b     .L7F0CB668
/* 0FFEF0 7F0CB3C0 01C01025 */   move  $v0, $t6
.L7F0CB3C4:
/* 0FFEF4 7F0CB3C4 1A400069 */  blez  $s2, .L7F0CB56C
/* 0FFEF8 7F0CB3C8 00003825 */   move  $a3, $zero
/* 0FFEFC 7F0CB3CC 26290007 */  addiu $t1, $s1, 7
/* 0FFF00 7F0CB3D0 312F0FF8 */  andi  $t7, $t1, 0xff8
/* 0FFF04 7F0CB3D4 01E04825 */  move  $t1, $t7
/* 0FFF08 7F0CB3D8 00114040 */  sll   $t0, $s1, 1
/* 0FFF0C 7F0CB3DC 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB3E0:
/* 0FFF10 7F0CB3E0 1A20005D */  blez  $s1, .L7F0CB558
/* 0FFF14 7F0CB3E4 00001025 */   move  $v0, $zero
/* 0FFF18 7F0CB3E8 32260003 */  andi  $a2, $s1, 3
/* 0FFF1C 7F0CB3EC 10C00016 */  beqz  $a2, .L7F0CB448
/* 0FFF20 7F0CB3F0 00C06025 */   move  $t4, $a2
/* 0FFF24 7F0CB3F4 01605021 */  addu  $t2, $t3, $zero
.L7F0CB3F8:
/* 0FFF28 7F0CB3F8 2A010101 */  slti  $at, $s0, 0x101
/* 0FFF2C 7F0CB3FC 10200008 */  beqz  $at, .L7F0CB420
/* 0FFF30 7F0CB400 0002C840 */   sll   $t9, $v0, 1
/* 0FFF34 7F0CB404 0082C021 */  addu  $t8, $a0, $v0
/* 0FFF38 7F0CB408 93190000 */  lbu   $t9, ($t8)
/* 0FFF3C 7F0CB40C 00197040 */  sll   $t6, $t9, 1
/* 0FFF40 7F0CB410 006E7821 */  addu  $t7, $v1, $t6
/* 0FFF44 7F0CB414 95F80000 */  lhu   $t8, ($t7)
/* 0FFF48 7F0CB418 10000007 */  b     .L7F0CB438
/* 0FFF4C 7F0CB41C A1580000 */   sb    $t8, ($t2)
.L7F0CB420:
/* 0FFF50 7F0CB420 00B97021 */  addu  $t6, $a1, $t9
/* 0FFF54 7F0CB424 95CF0000 */  lhu   $t7, ($t6)
/* 0FFF58 7F0CB428 000FC040 */  sll   $t8, $t7, 1
/* 0FFF5C 7F0CB42C 0078C821 */  addu  $t9, $v1, $t8
/* 0FFF60 7F0CB430 972E0000 */  lhu   $t6, ($t9)
/* 0FFF64 7F0CB434 A14E0000 */  sb    $t6, ($t2)
.L7F0CB438:
/* 0FFF68 7F0CB438 24420001 */  addiu $v0, $v0, 1
/* 0FFF6C 7F0CB43C 1582FFEE */  bne   $t4, $v0, .L7F0CB3F8
/* 0FFF70 7F0CB440 254A0001 */   addiu $t2, $t2, 1
/* 0FFF74 7F0CB444 10510044 */  beq   $v0, $s1, .L7F0CB558
.L7F0CB448:
/* 0FFF78 7F0CB448 01625021 */   addu  $t2, $t3, $v0
.L7F0CB44C:
/* 0FFF7C 7F0CB44C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFF80 7F0CB450 10200008 */  beqz  $at, .L7F0CB474
/* 0FFF84 7F0CB454 0002C040 */   sll   $t8, $v0, 1
/* 0FFF88 7F0CB458 00827821 */  addu  $t7, $a0, $v0
/* 0FFF8C 7F0CB45C 91F80000 */  lbu   $t8, ($t7)
/* 0FFF90 7F0CB460 0018C840 */  sll   $t9, $t8, 1
/* 0FFF94 7F0CB464 00797021 */  addu  $t6, $v1, $t9
/* 0FFF98 7F0CB468 95CF0000 */  lhu   $t7, ($t6)
/* 0FFF9C 7F0CB46C 10000007 */  b     .L7F0CB48C
/* 0FFFA0 7F0CB470 A14F0000 */   sb    $t7, ($t2)
.L7F0CB474:
/* 0FFFA4 7F0CB474 00B8C821 */  addu  $t9, $a1, $t8
/* 0FFFA8 7F0CB478 972E0000 */  lhu   $t6, ($t9)
/* 0FFFAC 7F0CB47C 000E7840 */  sll   $t7, $t6, 1
/* 0FFFB0 7F0CB480 006FC021 */  addu  $t8, $v1, $t7
/* 0FFFB4 7F0CB484 97190000 */  lhu   $t9, ($t8)
/* 0FFFB8 7F0CB488 A1590000 */  sb    $t9, ($t2)
.L7F0CB48C:
/* 0FFFBC 7F0CB48C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFFC0 7F0CB490 10200008 */  beqz  $at, .L7F0CB4B4
/* 0FFFC4 7F0CB494 00027840 */   sll   $t7, $v0, 1
/* 0FFFC8 7F0CB498 00827021 */  addu  $t6, $a0, $v0
/* 0FFFCC 7F0CB49C 91CF0001 */  lbu   $t7, 1($t6)
/* 0FFFD0 7F0CB4A0 000FC040 */  sll   $t8, $t7, 1
/* 0FFFD4 7F0CB4A4 0078C821 */  addu  $t9, $v1, $t8
/* 0FFFD8 7F0CB4A8 972E0000 */  lhu   $t6, ($t9)
/* 0FFFDC 7F0CB4AC 10000007 */  b     .L7F0CB4CC
/* 0FFFE0 7F0CB4B0 A14E0001 */   sb    $t6, 1($t2)
.L7F0CB4B4:
/* 0FFFE4 7F0CB4B4 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFFE8 7F0CB4B8 97190002 */  lhu   $t9, 2($t8)
/* 0FFFEC 7F0CB4BC 00197040 */  sll   $t6, $t9, 1
/* 0FFFF0 7F0CB4C0 006E7821 */  addu  $t7, $v1, $t6
/* 0FFFF4 7F0CB4C4 95F80000 */  lhu   $t8, ($t7)
/* 0FFFF8 7F0CB4C8 A1580001 */  sb    $t8, 1($t2)
.L7F0CB4CC:
/* 0FFFFC 7F0CB4CC 2A010101 */  slti  $at, $s0, 0x101
/* 100000 7F0CB4D0 10200008 */  beqz  $at, .L7F0CB4F4
/* 100004 7F0CB4D4 00027040 */   sll   $t6, $v0, 1
/* 100008 7F0CB4D8 0082C821 */  addu  $t9, $a0, $v0
/* 10000C 7F0CB4DC 932E0002 */  lbu   $t6, 2($t9)
/* 100010 7F0CB4E0 000E7840 */  sll   $t7, $t6, 1
/* 100014 7F0CB4E4 006FC021 */  addu  $t8, $v1, $t7
/* 100018 7F0CB4E8 97190000 */  lhu   $t9, ($t8)
/* 10001C 7F0CB4EC 10000007 */  b     .L7F0CB50C
/* 100020 7F0CB4F0 A1590002 */   sb    $t9, 2($t2)
.L7F0CB4F4:
/* 100024 7F0CB4F4 00AE7821 */  addu  $t7, $a1, $t6
/* 100028 7F0CB4F8 95F80004 */  lhu   $t8, 4($t7)
/* 10002C 7F0CB4FC 0018C840 */  sll   $t9, $t8, 1
/* 100030 7F0CB500 00797021 */  addu  $t6, $v1, $t9
/* 100034 7F0CB504 95CF0000 */  lhu   $t7, ($t6)
/* 100038 7F0CB508 A14F0002 */  sb    $t7, 2($t2)
.L7F0CB50C:
/* 10003C 7F0CB50C 2A010101 */  slti  $at, $s0, 0x101
/* 100040 7F0CB510 10200008 */  beqz  $at, .L7F0CB534
/* 100044 7F0CB514 0002C840 */   sll   $t9, $v0, 1
/* 100048 7F0CB518 0082C021 */  addu  $t8, $a0, $v0
/* 10004C 7F0CB51C 93190003 */  lbu   $t9, 3($t8)
/* 100050 7F0CB520 00197040 */  sll   $t6, $t9, 1
/* 100054 7F0CB524 006E7821 */  addu  $t7, $v1, $t6
/* 100058 7F0CB528 95F80000 */  lhu   $t8, ($t7)
/* 10005C 7F0CB52C 10000007 */  b     .L7F0CB54C
/* 100060 7F0CB530 A1580003 */   sb    $t8, 3($t2)
.L7F0CB534:
/* 100064 7F0CB534 00B97021 */  addu  $t6, $a1, $t9
/* 100068 7F0CB538 95CF0006 */  lhu   $t7, 6($t6)
/* 10006C 7F0CB53C 000FC040 */  sll   $t8, $t7, 1
/* 100070 7F0CB540 0078C821 */  addu  $t9, $v1, $t8
/* 100074 7F0CB544 972E0000 */  lhu   $t6, ($t9)
/* 100078 7F0CB548 A14E0003 */  sb    $t6, 3($t2)
.L7F0CB54C:
/* 10007C 7F0CB54C 24420004 */  addiu $v0, $v0, 4
/* 100080 7F0CB550 1451FFBE */  bne   $v0, $s1, .L7F0CB44C
/* 100084 7F0CB554 254A0004 */   addiu $t2, $t2, 4
.L7F0CB558:
/* 100088 7F0CB558 24E70001 */  addiu $a3, $a3, 1
/* 10008C 7F0CB55C 01695821 */  addu  $t3, $t3, $t1
/* 100090 7F0CB560 00912021 */  addu  $a0, $a0, $s1
/* 100094 7F0CB564 14F2FF9E */  bne   $a3, $s2, .L7F0CB3E0
/* 100098 7F0CB568 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB56C:
/* 10009C 7F0CB56C 262F0007 */  addiu $t7, $s1, 7
/* 1000A0 7F0CB570 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 1000A4 7F0CB574 03120019 */  multu $t8, $s2
/* 1000A8 7F0CB578 00001012 */  mflo  $v0
/* 1000AC 7F0CB57C 1000003B */  b     .L7F0CB66C
/* 1000B0 7F0CB580 8FB00004 */   lw    $s0, 4($sp)
.L7F0CB584:
/* 1000B4 7F0CB584 1A400031 */  blez  $s2, .L7F0CB64C
/* 1000B8 7F0CB588 00003825 */   move  $a3, $zero
/* 1000BC 7F0CB58C 2629000F */  addiu $t1, $s1, 0xf
/* 1000C0 7F0CB590 31390FF0 */  andi  $t9, $t1, 0xff0
/* 1000C4 7F0CB594 00194843 */  sra   $t1, $t9, 1
/* 1000C8 7F0CB598 00114040 */  sll   $t0, $s1, 1
/* 1000CC 7F0CB59C 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB5A0:
/* 1000D0 7F0CB5A0 1A200025 */  blez  $s1, .L7F0CB638
/* 1000D4 7F0CB5A4 00001025 */   move  $v0, $zero
/* 1000D8 7F0CB5A8 2A010101 */  slti  $at, $s0, 0x101
.L7F0CB5AC:
/* 1000DC 7F0CB5AC 10200010 */  beqz  $at, .L7F0CB5F0
/* 1000E0 7F0CB5B0 0002C040 */   sll   $t8, $v0, 1
/* 1000E4 7F0CB5B4 00443021 */  addu  $a2, $v0, $a0
/* 1000E8 7F0CB5B8 90CF0001 */  lbu   $t7, 1($a2)
/* 1000EC 7F0CB5BC 000FC040 */  sll   $t8, $t7, 1
/* 1000F0 7F0CB5C0 90CF0000 */  lbu   $t7, ($a2)
/* 1000F4 7F0CB5C4 0078C821 */  addu  $t9, $v1, $t8
/* 1000F8 7F0CB5C8 972E0000 */  lhu   $t6, ($t9)
/* 1000FC 7F0CB5CC 000FC040 */  sll   $t8, $t7, 1
/* 100100 7F0CB5D0 0078C821 */  addu  $t9, $v1, $t8
/* 100104 7F0CB5D4 972F0000 */  lhu   $t7, ($t9)
/* 100108 7F0CB5D8 000FC100 */  sll   $t8, $t7, 4
/* 10010C 7F0CB5DC 00027843 */  sra   $t7, $v0, 1
/* 100110 7F0CB5E0 01D8C825 */  or    $t9, $t6, $t8
/* 100114 7F0CB5E4 016F7021 */  addu  $t6, $t3, $t7
/* 100118 7F0CB5E8 1000000F */  b     .L7F0CB628
/* 10011C 7F0CB5EC A1D90000 */   sb    $t9, ($t6)
.L7F0CB5F0:
/* 100120 7F0CB5F0 00B83021 */  addu  $a2, $a1, $t8
/* 100124 7F0CB5F4 94CF0002 */  lhu   $t7, 2($a2)
/* 100128 7F0CB5F8 000FC840 */  sll   $t9, $t7, 1
/* 10012C 7F0CB5FC 94CF0000 */  lhu   $t7, ($a2)
/* 100130 7F0CB600 00797021 */  addu  $t6, $v1, $t9
/* 100134 7F0CB604 95D80000 */  lhu   $t8, ($t6)
/* 100138 7F0CB608 000FC840 */  sll   $t9, $t7, 1
/* 10013C 7F0CB60C 00797021 */  addu  $t6, $v1, $t9
/* 100140 7F0CB610 95CF0000 */  lhu   $t7, ($t6)
/* 100144 7F0CB614 000FC900 */  sll   $t9, $t7, 4
/* 100148 7F0CB618 00027843 */  sra   $t7, $v0, 1
/* 10014C 7F0CB61C 03197025 */  or    $t6, $t8, $t9
/* 100150 7F0CB620 016FC021 */  addu  $t8, $t3, $t7
/* 100154 7F0CB624 A30E0000 */  sb    $t6, ($t8)
.L7F0CB628:
/* 100158 7F0CB628 24420002 */  addiu $v0, $v0, 2
/* 10015C 7F0CB62C 0051082A */  slt   $at, $v0, $s1
/* 100160 7F0CB630 5420FFDE */  bnezl $at, .L7F0CB5AC
/* 100164 7F0CB634 2A010101 */   slti  $at, $s0, 0x101
.L7F0CB638:
/* 100168 7F0CB638 24E70001 */  addiu $a3, $a3, 1
/* 10016C 7F0CB63C 01695821 */  addu  $t3, $t3, $t1
/* 100170 7F0CB640 00912021 */  addu  $a0, $a0, $s1
/* 100174 7F0CB644 14F2FFD6 */  bne   $a3, $s2, .L7F0CB5A0
/* 100178 7F0CB648 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB64C:
/* 10017C 7F0CB64C 2639000F */  addiu $t9, $s1, 0xf
/* 100180 7F0CB650 332F0FF0 */  andi  $t7, $t9, 0xff0
/* 100184 7F0CB654 000F7043 */  sra   $t6, $t7, 1
/* 100188 7F0CB658 01D20019 */  multu $t6, $s2
/* 10018C 7F0CB65C 00001012 */  mflo  $v0
/* 100190 7F0CB660 10000002 */  b     .L7F0CB66C
/* 100194 7F0CB664 8FB00004 */   lw    $s0, 4($sp)
def_7F0CACBC:
.L7F0CB668:
/* 100198 7F0CB668 8FB00004 */  lw    $s0, 4($sp)
.L7F0CB66C:
/* 10019C 7F0CB66C 8FB10008 */  lw    $s1, 8($sp)
/* 1001A0 7F0CB670 8FB2000C */  lw    $s2, 0xc($sp)
/* 1001A4 7F0CB674 03E00008 */  jr    $ra
/* 1001A8 7F0CB678 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CB67C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BE30*/
glabel jpt_8005BE30
.word .L7F0CB6A8
.word .L7F0CB6BC
.word .L7F0CB6A8
.word .L7F0CB6BC
.word .L7F0CB6BC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.text
glabel sub_GAME_7F0CB67C
/* 1001AC 7F0CB67C 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 1001B0 7F0CB680 2CE1000D */  sltiu $at, $a3, 0xd
/* 1001B4 7F0CB684 AFA50014 */  sw    $a1, 0x14($sp)
/* 1001B8 7F0CB688 1020001D */  beqz  $at, .L7F0CB700
/* 1001BC 7F0CB68C 00E01825 */   move  $v1, $a3
/* 1001C0 7F0CB690 00077080 */  sll   $t6, $a3, 2
/* 1001C4 7F0CB694 3C018006 */  lui   $at, %hi(jpt_8005BE30)
/* 1001C8 7F0CB698 002E0821 */  addu  $at, $at, $t6
/* 1001CC 7F0CB69C 8C2EBE30 */  lw    $t6, %lo(jpt_8005BE30)($at)
/* 1001D0 7F0CB6A0 01C00008 */  jr    $t6
/* 1001D4 7F0CB6A4 00000000 */   nop   
.L7F0CB6A8:
/* 1001D8 7F0CB6A8 8FA50014 */  lw    $a1, 0x14($sp)
/* 1001DC 7F0CB6AC 24A50003 */  addiu $a1, $a1, 3
/* 1001E0 7F0CB6B0 30AF0FFC */  andi  $t7, $a1, 0xffc
/* 1001E4 7F0CB6B4 10000012 */  b     .L7F0CB700
/* 1001E8 7F0CB6B8 AFAF0004 */   sw    $t7, 4($sp)
.L7F0CB6BC:
/* 1001EC 7F0CB6BC 8FA50014 */  lw    $a1, 0x14($sp)
/* 1001F0 7F0CB6C0 24A50003 */  addiu $a1, $a1, 3
/* 1001F4 7F0CB6C4 30B80FFC */  andi  $t8, $a1, 0xffc
/* 1001F8 7F0CB6C8 0018C843 */  sra   $t9, $t8, 1
/* 1001FC 7F0CB6CC 1000000C */  b     .L7F0CB700
/* 100200 7F0CB6D0 AFB90004 */   sw    $t9, 4($sp)
.L7F0CB6D4:
/* 100204 7F0CB6D4 8FA50014 */  lw    $a1, 0x14($sp)
/* 100208 7F0CB6D8 24A50007 */  addiu $a1, $a1, 7
/* 10020C 7F0CB6DC 30AA0FF8 */  andi  $t2, $a1, 0xff8
/* 100210 7F0CB6E0 000A5883 */  sra   $t3, $t2, 2
/* 100214 7F0CB6E4 10000006 */  b     .L7F0CB700
/* 100218 7F0CB6E8 AFAB0004 */   sw    $t3, 4($sp)
.L7F0CB6EC:
/* 10021C 7F0CB6EC 8FA50014 */  lw    $a1, 0x14($sp)
/* 100220 7F0CB6F0 24A5000F */  addiu $a1, $a1, 0xf
/* 100224 7F0CB6F4 30AC0FF0 */  andi  $t4, $a1, 0xff0
/* 100228 7F0CB6F8 000C68C3 */  sra   $t5, $t4, 3
/* 10022C 7F0CB6FC AFAD0004 */  sw    $t5, 4($sp)
def_7F0CB6A0:
.L7F0CB700:
/* 100230 7F0CB700 8FA50004 */  lw    $a1, 4($sp)
/* 100234 7F0CB704 24010002 */  li    $at, 2
/* 100238 7F0CB708 00057080 */  sll   $t6, $a1, 2
/* 10023C 7F0CB70C 10600002 */  beqz  $v1, .L7F0CB718
/* 100240 7F0CB710 008E1021 */   addu  $v0, $a0, $t6
/* 100244 7F0CB714 1461001B */  bne   $v1, $at, .L7F0CB784
.L7F0CB718:
/* 100248 7F0CB718 28C10002 */   slti  $at, $a2, 2
/* 10024C 7F0CB71C 1420002E */  bnez  $at, .L7F0CB7D8
/* 100250 7F0CB720 24030001 */   li    $v1, 1
/* 100254 7F0CB724 00A04825 */  move  $t1, $a1
/* 100258 7F0CB728 000978C0 */  sll   $t7, $t1, 3
/* 10025C 7F0CB72C 01E04825 */  move  $t1, $t7
.L7F0CB730:
/* 100260 7F0CB730 18A0000E */  blez  $a1, .L7F0CB76C
/* 100264 7F0CB734 00002025 */   move  $a0, $zero
/* 100268 7F0CB738 00404025 */  move  $t0, $v0
.L7F0CB73C:
/* 10026C 7F0CB73C 8D070000 */  lw    $a3, ($t0)
/* 100270 7F0CB740 8D180008 */  lw    $t8, 8($t0)
/* 100274 7F0CB744 8D19000C */  lw    $t9, 0xc($t0)
/* 100278 7F0CB748 AD070008 */  sw    $a3, 8($t0)
/* 10027C 7F0CB74C 8D070004 */  lw    $a3, 4($t0)
/* 100280 7F0CB750 24840004 */  addiu $a0, $a0, 4
/* 100284 7F0CB754 0085082A */  slt   $at, $a0, $a1
/* 100288 7F0CB758 25080010 */  addiu $t0, $t0, 0x10
/* 10028C 7F0CB75C AD18FFF0 */  sw    $t8, -0x10($t0)
/* 100290 7F0CB760 AD19FFF4 */  sw    $t9, -0xc($t0)
/* 100294 7F0CB764 1420FFF5 */  bnez  $at, .L7F0CB73C
/* 100298 7F0CB768 AD07FFFC */   sw    $a3, -4($t0)
.L7F0CB76C:
/* 10029C 7F0CB76C 24630002 */  addiu $v1, $v1, 2
/* 1002A0 7F0CB770 0066082A */  slt   $at, $v1, $a2
/* 1002A4 7F0CB774 1420FFEE */  bnez  $at, .L7F0CB730
/* 1002A8 7F0CB778 00491021 */   addu  $v0, $v0, $t1
/* 1002AC 7F0CB77C 10000016 */  b     .L7F0CB7D8
/* 1002B0 7F0CB780 00000000 */   nop   
.L7F0CB784:
/* 1002B4 7F0CB784 28C10002 */  slti  $at, $a2, 2
/* 1002B8 7F0CB788 14200013 */  bnez  $at, .L7F0CB7D8
/* 1002BC 7F0CB78C 24030001 */   li    $v1, 1
/* 1002C0 7F0CB790 00A04825 */  move  $t1, $a1
/* 1002C4 7F0CB794 000950C0 */  sll   $t2, $t1, 3
/* 1002C8 7F0CB798 01404825 */  move  $t1, $t2
.L7F0CB79C:
/* 1002CC 7F0CB79C 18A0000A */  blez  $a1, .L7F0CB7C8
/* 1002D0 7F0CB7A0 00002025 */   move  $a0, $zero
/* 1002D4 7F0CB7A4 00404025 */  move  $t0, $v0
.L7F0CB7A8:
/* 1002D8 7F0CB7A8 8D070000 */  lw    $a3, ($t0)
/* 1002DC 7F0CB7AC 8D0B0004 */  lw    $t3, 4($t0)
/* 1002E0 7F0CB7B0 24840002 */  addiu $a0, $a0, 2
/* 1002E4 7F0CB7B4 0085082A */  slt   $at, $a0, $a1
/* 1002E8 7F0CB7B8 25080008 */  addiu $t0, $t0, 8
/* 1002EC 7F0CB7BC AD07FFFC */  sw    $a3, -4($t0)
/* 1002F0 7F0CB7C0 1420FFF9 */  bnez  $at, .L7F0CB7A8
/* 1002F4 7F0CB7C4 AD0BFFF8 */   sw    $t3, -8($t0)
.L7F0CB7C8:
/* 1002F8 7F0CB7C8 24630002 */  addiu $v1, $v1, 2
/* 1002FC 7F0CB7CC 0066082A */  slt   $at, $v1, $a2
/* 100300 7F0CB7D0 1420FFF2 */  bnez  $at, .L7F0CB79C
/* 100304 7F0CB7D4 00491021 */   addu  $v0, $v0, $t1
.L7F0CB7D8:
/* 100308 7F0CB7D8 03E00008 */  jr    $ra
/* 10030C 7F0CB7DC 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
void type8_9_doohick(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BE64*/
glabel jpt_8005BE64
.word .L7F0CB8A8
.word .L7F0CB8EC
.word .L7F0CB930
.word .L7F0CB974
.word .L7F0CB9C0
.word .L7F0CBA1C
.word .L7F0CBA78
.text
glabel type8_9_doohick
/* 100310 7F0CB7E0 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 100314 7F0CB7E4 AFB10008 */  sw    $s1, 8($sp)
/* 100318 7F0CB7E8 AFB00004 */  sw    $s0, 4($sp)
/* 10031C 7F0CB7EC 00808025 */  move  $s0, $a0
/* 100320 7F0CB7F0 00E08825 */  move  $s1, $a3
/* 100324 7F0CB7F4 AFB2000C */  sw    $s2, 0xc($sp)
/* 100328 7F0CB7F8 18C000B9 */  blez  $a2, .L7F0CBAE0
/* 10032C 7F0CB7FC 00001025 */   move  $v0, $zero
/* 100330 7F0CB800 8FA90020 */  lw    $t1, 0x20($sp)
.L7F0CB804:
/* 100334 7F0CB804 18A000B3 */  blez  $a1, .L7F0CBAD4
/* 100338 7F0CB808 00001825 */   move  $v1, $zero
/* 10033C 7F0CB80C 00450019 */  multu $v0, $a1
/* 100340 7F0CB810 00095040 */  sll   $t2, $t1, 1
/* 100344 7F0CB814 02209025 */  move  $s2, $s1
/* 100348 7F0CB818 00003812 */  mflo  $a3
/* 10034C 7F0CB81C 00F04021 */  addu  $t0, $a3, $s0
/* 100350 7F0CB820 00000000 */  nop   
.L7F0CB824:
/* 100354 7F0CB824 910E0000 */  lbu   $t6, ($t0)
/* 100358 7F0CB828 2E410007 */  sltiu $at, $s2, 7
/* 10035C 7F0CB82C 18600003 */  blez  $v1, .L7F0CB83C
/* 100360 7F0CB830 01CA2021 */   addu  $a0, $t6, $t2
/* 100364 7F0CB834 10000002 */  b     .L7F0CB840
/* 100368 7F0CB838 910BFFFF */   lbu   $t3, -1($t0)
.L7F0CB83C:
/* 10036C 7F0CB83C 00005825 */  move  $t3, $zero
.L7F0CB840:
/* 100370 7F0CB840 18400008 */  blez  $v0, .L7F0CB864
/* 100374 7F0CB844 00006025 */   move  $t4, $zero
/* 100378 7F0CB848 244FFFFF */  addiu $t7, $v0, -1
/* 10037C 7F0CB84C 01E50019 */  multu $t7, $a1
/* 100380 7F0CB850 0000C012 */  mflo  $t8
/* 100384 7F0CB854 0303C821 */  addu  $t9, $t8, $v1
/* 100388 7F0CB858 03307021 */  addu  $t6, $t9, $s0
/* 10038C 7F0CB85C 10000001 */  b     .L7F0CB864
/* 100390 7F0CB860 91CC0000 */   lbu   $t4, ($t6)
.L7F0CB864:
/* 100394 7F0CB864 18600009 */  blez  $v1, .L7F0CB88C
/* 100398 7F0CB868 00006825 */   move  $t5, $zero
/* 10039C 7F0CB86C 18400007 */  blez  $v0, .L7F0CB88C
/* 1003A0 7F0CB870 244FFFFF */   addiu $t7, $v0, -1
/* 1003A4 7F0CB874 01E50019 */  multu $t7, $a1
/* 1003A8 7F0CB878 0000C012 */  mflo  $t8
/* 1003AC 7F0CB87C 0303C821 */  addu  $t9, $t8, $v1
/* 1003B0 7F0CB880 03307021 */  addu  $t6, $t9, $s0
/* 1003B4 7F0CB884 10000001 */  b     .L7F0CB88C
/* 1003B8 7F0CB888 91CDFFFF */   lbu   $t5, -1($t6)
.L7F0CB88C:
/* 1003BC 7F0CB88C 1020008E */  beqz  $at, .L7F0CBAC8
/* 1003C0 7F0CB890 00127880 */   sll   $t7, $s2, 2
/* 1003C4 7F0CB894 3C018006 */  lui   $at, %hi(jpt_8005BE64)
/* 1003C8 7F0CB898 002F0821 */  addu  $at, $at, $t7
/* 1003CC 7F0CB89C 8C2FBE64 */  lw    $t7, %lo(jpt_8005BE64)($at)
/* 1003D0 7F0CB8A0 01E00008 */  jr    $t7
/* 1003D4 7F0CB8A4 00000000 */   nop   
.L7F0CB8A8:
/* 1003D8 7F0CB8A8 008BC021 */  addu  $t8, $a0, $t3
/* 1003DC 7F0CB8AC 0309001A */  div   $zero, $t8, $t1
/* 1003E0 7F0CB8B0 02077021 */  addu  $t6, $s0, $a3
/* 1003E4 7F0CB8B4 01C37821 */  addu  $t7, $t6, $v1
/* 1003E8 7F0CB8B8 0000C810 */  mfhi  $t9
/* 1003EC 7F0CB8BC A1F90000 */  sb    $t9, ($t7)
/* 1003F0 7F0CB8C0 15200002 */  bnez  $t1, .L7F0CB8CC
/* 1003F4 7F0CB8C4 00000000 */   nop   
/* 1003F8 7F0CB8C8 0007000D */  break 7
.L7F0CB8CC:
/* 1003FC 7F0CB8CC 2401FFFF */  li    $at, -1
/* 100400 7F0CB8D0 15210004 */  bne   $t1, $at, .L7F0CB8E4
/* 100404 7F0CB8D4 3C018000 */   lui   $at, 0x8000
/* 100408 7F0CB8D8 17010002 */  bne   $t8, $at, .L7F0CB8E4
/* 10040C 7F0CB8DC 00000000 */   nop   
/* 100410 7F0CB8E0 0006000D */  break 6
.L7F0CB8E4:
/* 100414 7F0CB8E4 10000079 */  b     .L7F0CBACC
/* 100418 7F0CB8E8 24630001 */   addiu $v1, $v1, 1
.L7F0CB8EC:
/* 10041C 7F0CB8EC 008CC021 */  addu  $t8, $a0, $t4
/* 100420 7F0CB8F0 0309001A */  div   $zero, $t8, $t1
/* 100424 7F0CB8F4 0207C821 */  addu  $t9, $s0, $a3
/* 100428 7F0CB8F8 03237821 */  addu  $t7, $t9, $v1
/* 10042C 7F0CB8FC 00007010 */  mfhi  $t6
/* 100430 7F0CB900 A1EE0000 */  sb    $t6, ($t7)
/* 100434 7F0CB904 15200002 */  bnez  $t1, .L7F0CB910
/* 100438 7F0CB908 00000000 */   nop   
/* 10043C 7F0CB90C 0007000D */  break 7
.L7F0CB910:
/* 100440 7F0CB910 2401FFFF */  li    $at, -1
/* 100444 7F0CB914 15210004 */  bne   $t1, $at, .L7F0CB928
/* 100448 7F0CB918 3C018000 */   lui   $at, 0x8000
/* 10044C 7F0CB91C 17010002 */  bne   $t8, $at, .L7F0CB928
/* 100450 7F0CB920 00000000 */   nop   
/* 100454 7F0CB924 0006000D */  break 6
.L7F0CB928:
/* 100458 7F0CB928 10000068 */  b     .L7F0CBACC
/* 10045C 7F0CB92C 24630001 */   addiu $v1, $v1, 1
.L7F0CB930:
/* 100460 7F0CB930 008DC021 */  addu  $t8, $a0, $t5
/* 100464 7F0CB934 0309001A */  div   $zero, $t8, $t1
/* 100468 7F0CB938 02077021 */  addu  $t6, $s0, $a3
/* 10046C 7F0CB93C 01C37821 */  addu  $t7, $t6, $v1
/* 100470 7F0CB940 0000C810 */  mfhi  $t9
/* 100474 7F0CB944 A1F90000 */  sb    $t9, ($t7)
/* 100478 7F0CB948 15200002 */  bnez  $t1, .L7F0CB954
/* 10047C 7F0CB94C 00000000 */   nop   
/* 100480 7F0CB950 0007000D */  break 7
.L7F0CB954:
/* 100484 7F0CB954 2401FFFF */  li    $at, -1
/* 100488 7F0CB958 15210004 */  bne   $t1, $at, .L7F0CB96C
/* 10048C 7F0CB95C 3C018000 */   lui   $at, 0x8000
/* 100490 7F0CB960 17010002 */  bne   $t8, $at, .L7F0CB96C
/* 100494 7F0CB964 00000000 */   nop   
/* 100498 7F0CB968 0006000D */  break 6
.L7F0CB96C:
/* 10049C 7F0CB96C 10000057 */  b     .L7F0CBACC
/* 1004A0 7F0CB970 24630001 */   addiu $v1, $v1, 1
.L7F0CB974:
/* 1004A4 7F0CB974 016CC021 */  addu  $t8, $t3, $t4
/* 1004A8 7F0CB978 030D7023 */  subu  $t6, $t8, $t5
/* 1004AC 7F0CB97C 01C4C821 */  addu  $t9, $t6, $a0
/* 1004B0 7F0CB980 0329001A */  div   $zero, $t9, $t1
/* 1004B4 7F0CB984 0207C021 */  addu  $t8, $s0, $a3
/* 1004B8 7F0CB988 03037021 */  addu  $t6, $t8, $v1
/* 1004BC 7F0CB98C 00007810 */  mfhi  $t7
/* 1004C0 7F0CB990 A1CF0000 */  sb    $t7, ($t6)
/* 1004C4 7F0CB994 15200002 */  bnez  $t1, .L7F0CB9A0
/* 1004C8 7F0CB998 00000000 */   nop   
/* 1004CC 7F0CB99C 0007000D */  break 7
.L7F0CB9A0:
/* 1004D0 7F0CB9A0 2401FFFF */  li    $at, -1
/* 1004D4 7F0CB9A4 15210004 */  bne   $t1, $at, .L7F0CB9B8
/* 1004D8 7F0CB9A8 3C018000 */   lui   $at, 0x8000
/* 1004DC 7F0CB9AC 17210002 */  bne   $t9, $at, .L7F0CB9B8
/* 1004E0 7F0CB9B0 00000000 */   nop   
/* 1004E4 7F0CB9B4 0006000D */  break 6
.L7F0CB9B8:
/* 1004E8 7F0CB9B8 10000044 */  b     .L7F0CBACC
/* 1004EC 7F0CB9BC 24630001 */   addiu $v1, $v1, 1
.L7F0CB9C0:
/* 1004F0 7F0CB9C0 018DC823 */  subu  $t9, $t4, $t5
/* 1004F4 7F0CB9C4 07210003 */  bgez  $t9, .L7F0CB9D4
/* 1004F8 7F0CB9C8 0019C043 */   sra   $t8, $t9, 1
/* 1004FC 7F0CB9CC 27210001 */  addiu $at, $t9, 1
/* 100500 7F0CB9D0 0001C043 */  sra   $t8, $at, 1
.L7F0CB9D4:
/* 100504 7F0CB9D4 030B7821 */  addu  $t7, $t8, $t3
/* 100508 7F0CB9D8 01E47021 */  addu  $t6, $t7, $a0
/* 10050C 7F0CB9DC 01C9001A */  div   $zero, $t6, $t1
/* 100510 7F0CB9E0 0207C021 */  addu  $t8, $s0, $a3
/* 100514 7F0CB9E4 03037821 */  addu  $t7, $t8, $v1
/* 100518 7F0CB9E8 0000C810 */  mfhi  $t9
/* 10051C 7F0CB9EC A1F90000 */  sb    $t9, ($t7)
/* 100520 7F0CB9F0 15200002 */  bnez  $t1, .L7F0CB9FC
/* 100524 7F0CB9F4 00000000 */   nop   
/* 100528 7F0CB9F8 0007000D */  break 7
.L7F0CB9FC:
/* 10052C 7F0CB9FC 2401FFFF */  li    $at, -1
/* 100530 7F0CBA00 15210004 */  bne   $t1, $at, .L7F0CBA14
/* 100534 7F0CBA04 3C018000 */   lui   $at, 0x8000
/* 100538 7F0CBA08 15C10002 */  bne   $t6, $at, .L7F0CBA14
/* 10053C 7F0CBA0C 00000000 */   nop   
/* 100540 7F0CBA10 0006000D */  break 6
.L7F0CBA14:
/* 100544 7F0CBA14 1000002D */  b     .L7F0CBACC
/* 100548 7F0CBA18 24630001 */   addiu $v1, $v1, 1
.L7F0CBA1C:
/* 10054C 7F0CBA1C 016D7023 */  subu  $t6, $t3, $t5
/* 100550 7F0CBA20 05C10003 */  bgez  $t6, .L7F0CBA30
/* 100554 7F0CBA24 000EC043 */   sra   $t8, $t6, 1
/* 100558 7F0CBA28 25C10001 */  addiu $at, $t6, 1
/* 10055C 7F0CBA2C 0001C043 */  sra   $t8, $at, 1
.L7F0CBA30:
/* 100560 7F0CBA30 030CC821 */  addu  $t9, $t8, $t4
/* 100564 7F0CBA34 03247821 */  addu  $t7, $t9, $a0
/* 100568 7F0CBA38 01E9001A */  div   $zero, $t7, $t1
/* 10056C 7F0CBA3C 0207C021 */  addu  $t8, $s0, $a3
/* 100570 7F0CBA40 0303C821 */  addu  $t9, $t8, $v1
/* 100574 7F0CBA44 00007010 */  mfhi  $t6
/* 100578 7F0CBA48 A32E0000 */  sb    $t6, ($t9)
/* 10057C 7F0CBA4C 15200002 */  bnez  $t1, .L7F0CBA58
/* 100580 7F0CBA50 00000000 */   nop   
/* 100584 7F0CBA54 0007000D */  break 7
.L7F0CBA58:
/* 100588 7F0CBA58 2401FFFF */  li    $at, -1
/* 10058C 7F0CBA5C 15210004 */  bne   $t1, $at, .L7F0CBA70
/* 100590 7F0CBA60 3C018000 */   lui   $at, 0x8000
/* 100594 7F0CBA64 15E10002 */  bne   $t7, $at, .L7F0CBA70
/* 100598 7F0CBA68 00000000 */   nop   
/* 10059C 7F0CBA6C 0006000D */  break 6
.L7F0CBA70:
/* 1005A0 7F0CBA70 10000016 */  b     .L7F0CBACC
/* 1005A4 7F0CBA74 24630001 */   addiu $v1, $v1, 1
.L7F0CBA78:
/* 1005A8 7F0CBA78 016C7821 */  addu  $t7, $t3, $t4
/* 1005AC 7F0CBA7C 05E10003 */  bgez  $t7, .L7F0CBA8C
/* 1005B0 7F0CBA80 000FC043 */   sra   $t8, $t7, 1
/* 1005B4 7F0CBA84 25E10001 */  addiu $at, $t7, 1
/* 1005B8 7F0CBA88 0001C043 */  sra   $t8, $at, 1
.L7F0CBA8C:
/* 1005BC 7F0CBA8C 03047021 */  addu  $t6, $t8, $a0
/* 1005C0 7F0CBA90 01C9001A */  div   $zero, $t6, $t1
/* 1005C4 7F0CBA94 0000C810 */  mfhi  $t9
/* 1005C8 7F0CBA98 02077821 */  addu  $t7, $s0, $a3
/* 1005CC 7F0CBA9C 01E3C021 */  addu  $t8, $t7, $v1
/* 1005D0 7F0CBAA0 A3190000 */  sb    $t9, ($t8)
/* 1005D4 7F0CBAA4 15200002 */  bnez  $t1, .L7F0CBAB0
/* 1005D8 7F0CBAA8 00000000 */   nop   
/* 1005DC 7F0CBAAC 0007000D */  break 7
.L7F0CBAB0:
/* 1005E0 7F0CBAB0 2401FFFF */  li    $at, -1
/* 1005E4 7F0CBAB4 15210004 */  bne   $t1, $at, .L7F0CBAC8
/* 1005E8 7F0CBAB8 3C018000 */   lui   $at, 0x8000
/* 1005EC 7F0CBABC 15C10002 */  bne   $t6, $at, .L7F0CBAC8
/* 1005F0 7F0CBAC0 00000000 */   nop   
/* 1005F4 7F0CBAC4 0006000D */  break 6
def_7F0CB8A0:
.L7F0CBAC8:
/* 1005F8 7F0CBAC8 24630001 */  addiu $v1, $v1, 1
.L7F0CBACC:
/* 1005FC 7F0CBACC 1465FF55 */  bne   $v1, $a1, .L7F0CB824
/* 100600 7F0CBAD0 25080001 */   addiu $t0, $t0, 1
.L7F0CBAD4:
/* 100604 7F0CBAD4 24420001 */  addiu $v0, $v0, 1
/* 100608 7F0CBAD8 1446FF4A */  bne   $v0, $a2, .L7F0CB804
/* 10060C 7F0CBADC 00000000 */   nop   
.L7F0CBAE0:
/* 100610 7F0CBAE0 8FB00004 */  lw    $s0, 4($sp)
/* 100614 7F0CBAE4 8FB10008 */  lw    $s1, 8($sp)
/* 100618 7F0CBAE8 8FB2000C */  lw    $s2, 0xc($sp)
/* 10061C 7F0CBAEC 03E00008 */  jr    $ra
/* 100620 7F0CBAF0 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CBAF4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBAF4
/* 100624 7F0CBAF4 00A61021 */  addu  $v0, $a1, $a2
/* 100628 7F0CBAF8 AC850000 */  sw    $a1, ($a0)
/* 10062C 7F0CBAFC AC820004 */  sw    $v0, 4($a0)
/* 100630 7F0CBB00 AC850008 */  sw    $a1, 8($a0)
/* 100634 7F0CBB04 03E00008 */  jr    $ra
/* 100638 7F0CBB08 AC82000C */   sw    $v0, 0xc($a0)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CBB0C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBB0C
/* 10063C 7F0CBB0C 54A00004 */  bnezl $a1, .L7F0CBB20
/* 100640 7F0CBB10 8CA20004 */   lw    $v0, 4($a1)
/* 100644 7F0CBB14 3C058009 */  lui   $a1, %hi(ptr_texture_alloc_start)
/* 100648 7F0CBB18 24A5C720 */  addiu $a1, %lo(ptr_texture_alloc_start) # addiu $a1, $a1, -0x38e0
/* 10064C 7F0CBB1C 8CA20004 */  lw    $v0, 4($a1)
.L7F0CBB20:
/* 100650 7F0CBB20 8CA3000C */  lw    $v1, 0xc($a1)
/* 100654 7F0CBB24 0062082B */  sltu  $at, $v1, $v0
/* 100658 7F0CBB28 5020000C */  beql  $at, $zero, .L7F0CBB5C
/* 10065C 7F0CBB2C 00001025 */   move  $v0, $zero
/* 100660 7F0CBB30 8C6E0000 */  lw    $t6, ($v1)
.L7F0CBB34:
/* 100664 7F0CBB34 000E7D02 */  srl   $t7, $t6, 0x14
/* 100668 7F0CBB38 548F0004 */  bnel  $a0, $t7, .L7F0CBB4C
/* 10066C 7F0CBB3C 24630010 */   addiu $v1, $v1, 0x10
/* 100670 7F0CBB40 03E00008 */  jr    $ra
/* 100674 7F0CBB44 00601025 */   move  $v0, $v1

/* 100678 7F0CBB48 24630010 */  addiu $v1, $v1, 0x10
.L7F0CBB4C:
/* 10067C 7F0CBB4C 0062082B */  sltu  $at, $v1, $v0
/* 100680 7F0CBB50 5420FFF8 */  bnezl $at, .L7F0CBB34
/* 100684 7F0CBB54 8C6E0000 */   lw    $t6, ($v1)
/* 100688 7F0CBB58 00001025 */  move  $v0, $zero
.L7F0CBB5C:
/* 10068C 7F0CBB5C 03E00008 */  jr    $ra
/* 100690 7F0CBB60 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CBB64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBB64
/* 100694 7F0CBB64 8C8E000C */  lw    $t6, 0xc($a0)
/* 100698 7F0CBB68 8C8F0008 */  lw    $t7, 8($a0)
/* 10069C 7F0CBB6C 03E00008 */  jr    $ra
/* 1006A0 7F0CBB70 01CF1023 */   subu  $v0, $t6, $t7
)
#endif





#ifdef NONMATCHING
void check_load_image_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_load_image_to_buffer
/* 1006A4 7F0CBB74 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1006A8 7F0CBB78 AFBF002C */  sw    $ra, 0x2c($sp)
/* 1006AC 7F0CBB7C AFB50028 */  sw    $s5, 0x28($sp)
/* 1006B0 7F0CBB80 AFB40024 */  sw    $s4, 0x24($sp)
/* 1006B4 7F0CBB84 AFB30020 */  sw    $s3, 0x20($sp)
/* 1006B8 7F0CBB88 AFB2001C */  sw    $s2, 0x1c($sp)
/* 1006BC 7F0CBB8C AFB10018 */  sw    $s1, 0x18($sp)
/* 1006C0 7F0CBB90 AFB00014 */  sw    $s0, 0x14($sp)
/* 1006C4 7F0CBB94 908E0000 */  lbu   $t6, ($a0)
/* 1006C8 7F0CBB98 241200B8 */  li    $s2, 184
/* 1006CC 7F0CBB9C 00A08825 */  move  $s1, $a1
/* 1006D0 7F0CBBA0 124E0014 */  beq   $s2, $t6, .L7F0CBBF4
/* 1006D4 7F0CBBA4 00808025 */   move  $s0, $a0
/* 1006D8 7F0CBBA8 90820000 */  lbu   $v0, ($a0)
/* 1006DC 7F0CBBAC 241500CD */  li    $s5, 205
/* 1006E0 7F0CBBB0 241400AB */  li    $s4, 171
/* 1006E4 7F0CBBB4 241300FD */  li    $s3, 253
.L7F0CBBB8:
/* 1006E8 7F0CBBB8 5662000B */  bnel  $s3, $v0, .L7F0CBBE8
/* 1006EC 7F0CBBBC 92020008 */   lbu   $v0, 8($s0)
/* 1006F0 7F0CBBC0 920F0004 */  lbu   $t7, 4($s0)
/* 1006F4 7F0CBBC4 568F0008 */  bnel  $s4, $t7, .L7F0CBBE8
/* 1006F8 7F0CBBC8 92020008 */   lbu   $v0, 8($s0)
/* 1006FC 7F0CBBCC 92180005 */  lbu   $t8, 5($s0)
/* 100700 7F0CBBD0 26040004 */  addiu $a0, $s0, 4
/* 100704 7F0CBBD4 56B80004 */  bnel  $s5, $t8, .L7F0CBBE8
/* 100708 7F0CBBD8 92020008 */   lbu   $v0, 8($s0)
/* 10070C 7F0CBBDC 0FC32F06 */  jal   load_image_to_buffer
/* 100710 7F0CBBE0 02202825 */   move  $a1, $s1
/* 100714 7F0CBBE4 92020008 */  lbu   $v0, 8($s0)
.L7F0CBBE8:
/* 100718 7F0CBBE8 26100008 */  addiu $s0, $s0, 8
/* 10071C 7F0CBBEC 1642FFF2 */  bne   $s2, $v0, .L7F0CBBB8
/* 100720 7F0CBBF0 00000000 */   nop   
.L7F0CBBF4:
/* 100724 7F0CBBF4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 100728 7F0CBBF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 10072C 7F0CBBFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 100730 7F0CBC00 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100734 7F0CBC04 8FB30020 */  lw    $s3, 0x20($sp)
/* 100738 7F0CBC08 8FB40024 */  lw    $s4, 0x24($sp)
/* 10073C 7F0CBC0C 8FB50028 */  lw    $s5, 0x28($sp)
/* 100740 7F0CBC10 03E00008 */  jr    $ra
/* 100744 7F0CBC14 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void load_image_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_image_to_buffer
/* 100748 7F0CBC18 27BDF008 */  addiu $sp, $sp, -0xff8
/* 10074C 7F0CBC1C AFB00020 */  sw    $s0, 0x20($sp)
/* 100750 7F0CBC20 00A08025 */  move  $s0, $a1
/* 100754 7F0CBC24 AFBF0024 */  sw    $ra, 0x24($sp)
/* 100758 7F0CBC28 14A00003 */  bnez  $a1, .L7F0CBC38
/* 10075C 7F0CBC2C AFA40FF8 */   sw    $a0, 0xff8($sp)
/* 100760 7F0CBC30 3C108009 */  lui   $s0, %hi(ptr_texture_alloc_start)
/* 100764 7F0CBC34 2610C720 */  addiu $s0, %lo(ptr_texture_alloc_start) # addiu $s0, $s0, -0x38e0
.L7F0CBC38:
/* 100768 7F0CBC38 8FAE0FF8 */  lw    $t6, 0xff8($sp)
/* 10076C 7F0CBC3C 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D094)
/* 100770 7F0CBC40 2442D094 */  addiu $v0, %lo(dword_CODE_bss_8008D094) # addiu $v0, $v0, -0x2f6c
/* 100774 7F0CBC44 8DCF0000 */  lw    $t7, ($t6)
/* 100778 7F0CBC48 02002825 */  move  $a1, $s0
/* 10077C 7F0CBC4C 31E4FFFF */  andi  $a0, $t7, 0xffff
/* 100780 7F0CBC50 0FC32EC3 */  jal   sub_GAME_7F0CBB0C
/* 100784 7F0CBC54 AC440000 */   sw    $a0, ($v0)
/* 100788 7F0CBC58 14400074 */  bnez  $v0, .L7F0CBE2C
/* 10078C 7F0CBC5C 00401825 */   move  $v1, $v0
/* 100790 7F0CBC60 27A30067 */  addiu $v1, $sp, 0x67
/* 100794 7F0CBC64 0003C902 */  srl   $t9, $v1, 4
/* 100798 7F0CBC68 00194100 */  sll   $t0, $t9, 4
/* 10079C 7F0CBC6C 0C0034C8 */  jal   osWritebackDCacheAll
/* 1007A0 7F0CBC70 AFA8002C */   sw    $t0, 0x2c($sp)
/* 1007A4 7F0CBC74 8FA4002C */  lw    $a0, 0x2c($sp)
/* 1007A8 7F0CBC78 0C0042C8 */  jal   osInvalDCache
/* 1007AC 7F0CBC7C 24052000 */   li    $a1, 8192
/* 1007B0 7F0CBC80 3C098009 */  lui   $t1, %hi(dword_CODE_bss_8008D094) 
/* 1007B4 7F0CBC84 8D29D094 */  lw    $t1, %lo(dword_CODE_bss_8008D094)($t1)
/* 1007B8 7F0CBC88 3C0B8005 */  lui   $t3, %hi(image_entries) 
/* 1007BC 7F0CBC8C 256B9300 */  addiu $t3, %lo(image_entries) # addiu $t3, $t3, -0x6d00
/* 1007C0 7F0CBC90 000950C0 */  sll   $t2, $t1, 3
/* 1007C4 7F0CBC94 014B1021 */  addu  $v0, $t2, $t3
/* 1007C8 7F0CBC98 8C430000 */  lw    $v1, ($v0)
/* 1007CC 7F0CBC9C 8C470008 */  lw    $a3, 8($v0)
/* 1007D0 7F0CBCA0 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 1007D4 7F0CBCA4 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 1007D8 7F0CBCA8 00616024 */  and   $t4, $v1, $at
/* 1007DC 7F0CBCAC 00E16824 */  and   $t5, $a3, $at
/* 1007E0 7F0CBCB0 01AC3023 */  subu  $a2, $t5, $t4
/* 1007E4 7F0CBCB4 24C6001F */  addiu $a2, $a2, 0x1f
/* 1007E8 7F0CBCB8 2401FFF8 */  li    $at, -8
/* 1007EC 7F0CBCBC 3C0F008F */  lui   $t7, %hi(_imagesSegmentRomStart) # $t7, 0x8f
/* 1007F0 7F0CBCC0 25EF7DF0 */  addiu $t7, %lo(_imagesSegmentRomStart) # addiu $t7, $t7, 0x7df0
/* 1007F4 7F0CBCC4 01817024 */  and   $t6, $t4, $at
/* 1007F8 7F0CBCC8 0006C102 */  srl   $t8, $a2, 4
/* 1007FC 7F0CBCCC 00183100 */  sll   $a2, $t8, 4
/* 100800 7F0CBCD0 01CF2821 */  addu  $a1, $t6, $t7
/* 100804 7F0CBCD4 AFAC003C */  sw    $t4, 0x3c($sp)
/* 100808 7F0CBCD8 0C001707 */  jal   romCopy
/* 10080C 7F0CBCDC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 100810 7F0CBCE0 8FA3003C */  lw    $v1, 0x3c($sp)
/* 100814 7F0CBCE4 8FA8002C */  lw    $t0, 0x2c($sp)
/* 100818 7F0CBCE8 02002025 */  move  $a0, $s0
/* 10081C 7F0CBCEC 30690007 */  andi  $t1, $v1, 7
/* 100820 7F0CBCF0 01095021 */  addu  $t2, $t0, $t1
/* 100824 7F0CBCF4 AFAA0054 */  sw    $t2, 0x54($sp)
/* 100828 7F0CBCF8 91420000 */  lbu   $v0, ($t2)
/* 10082C 7F0CBCFC 254D0001 */  addiu $t5, $t2, 1
/* 100830 7F0CBD00 AFAD0054 */  sw    $t5, 0x54($sp)
/* 100834 7F0CBD04 30460080 */  andi  $a2, $v0, 0x80
/* 100838 7F0CBD08 30450040 */  andi  $a1, $v0, 0x40
/* 10083C 7F0CBD0C 000659C3 */  sra   $t3, $a2, 7
/* 100840 7F0CBD10 00056183 */  sra   $t4, $a1, 6
/* 100844 7F0CBD14 01603025 */  move  $a2, $t3
/* 100848 7F0CBD18 01802825 */  move  $a1, $t4
/* 10084C 7F0CBD1C 1580000A */  bnez  $t4, .L7F0CBD48
/* 100850 7F0CBD20 3047003F */   andi  $a3, $v0, 0x3f
/* 100854 7F0CBD24 AFAC004C */  sw    $t4, 0x4c($sp)
/* 100858 7F0CBD28 AFAB0050 */  sw    $t3, 0x50($sp)
/* 10085C 7F0CBD2C 0FC32ED9 */  jal   sub_GAME_7F0CBB64
/* 100860 7F0CBD30 AFA70048 */   sw    $a3, 0x48($sp)
/* 100864 7F0CBD34 284110CC */  slti  $at, $v0, 0x10cc
/* 100868 7F0CBD38 8FA5004C */  lw    $a1, 0x4c($sp)
/* 10086C 7F0CBD3C 8FA60050 */  lw    $a2, 0x50($sp)
/* 100870 7F0CBD40 1420000C */  bnez  $at, .L7F0CBD74
/* 100874 7F0CBD44 8FA70048 */   lw    $a3, 0x48($sp)
.L7F0CBD48:
/* 100878 7F0CBD48 10A0000F */  beqz  $a1, .L7F0CBD88
/* 10087C 7F0CBD4C 02002025 */   move  $a0, $s0
/* 100880 7F0CBD50 AFA5004C */  sw    $a1, 0x4c($sp)
/* 100884 7F0CBD54 AFA60050 */  sw    $a2, 0x50($sp)
/* 100888 7F0CBD58 0FC32ED9 */  jal   sub_GAME_7F0CBB64
/* 10088C 7F0CBD5C AFA70048 */   sw    $a3, 0x48($sp)
/* 100890 7F0CBD60 28410A28 */  slti  $at, $v0, 0xa28
/* 100894 7F0CBD64 8FA5004C */  lw    $a1, 0x4c($sp)
/* 100898 7F0CBD68 8FA60050 */  lw    $a2, 0x50($sp)
/* 10089C 7F0CBD6C 10200006 */  beqz  $at, .L7F0CBD88
/* 1008A0 7F0CBD70 8FA70048 */   lw    $a3, 0x48($sp)
.L7F0CBD74:
/* 1008A4 7F0CBD74 0C003A2C */  jal   osVirtualToPhysical
/* 1008A8 7F0CBD78 8E040000 */   lw    $a0, ($s0)
/* 1008AC 7F0CBD7C 8FAE0FF8 */  lw    $t6, 0xff8($sp)
/* 1008B0 7F0CBD80 1000002E */  b     .L7F0CBE3C
/* 1008B4 7F0CBD84 ADC20000 */   sw    $v0, ($t6)
.L7F0CBD88:
/* 1008B8 7F0CBD88 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008D094) 
/* 1008BC 7F0CBD8C 8E020008 */  lw    $v0, 8($s0)
/* 1008C0 7F0CBD90 8DEFD094 */  lw    $t7, %lo(dword_CODE_bss_8008D094)($t7)
/* 1008C4 7F0CBD94 3C0B8009 */  lui   $t3, %hi(dword_CODE_bss_8008D094) 
/* 1008C8 7F0CBD98 A44F0000 */  sh    $t7, ($v0)
/* 1008CC 7F0CBD9C 8E180008 */  lw    $t8, 8($s0)
/* 1008D0 7F0CBDA0 8E08000C */  lw    $t0, 0xc($s0)
/* 1008D4 7F0CBDA4 27190008 */  addiu $t9, $t8, 8
/* 1008D8 7F0CBDA8 2509FFF0 */  addiu $t1, $t0, -0x10
/* 1008DC 7F0CBDAC AE190008 */  sw    $t9, 8($s0)
/* 1008E0 7F0CBDB0 AE09000C */  sw    $t1, 0xc($s0)
/* 1008E4 7F0CBDB4 952E0000 */  lhu   $t6, ($t1)
/* 1008E8 7F0CBDB8 8D6CD094 */  lw    $t4, %lo(dword_CODE_bss_8008D094)($t3)
/* 1008EC 7F0CBDBC 01201825 */  move  $v1, $t1
/* 1008F0 7F0CBDC0 31CF000F */  andi  $t7, $t6, 0xf
/* 1008F4 7F0CBDC4 000C6900 */  sll   $t5, $t4, 4
/* 1008F8 7F0CBDC8 01AFC025 */  or    $t8, $t5, $t7
/* 1008FC 7F0CBDCC A5380000 */  sh    $t8, ($t1)
/* 100900 7F0CBDD0 8E190008 */  lw    $t9, 8($s0)
/* 100904 7F0CBDD4 10A00008 */  beqz  $a1, .L7F0CBDF8
/* 100908 7F0CBDD8 AD390004 */   sw    $t9, 4($t1)
/* 10090C 7F0CBDDC 8E050008 */  lw    $a1, 8($s0)
/* 100910 7F0CBDE0 AFA90044 */  sw    $t1, 0x44($sp)
/* 100914 7F0CBDE4 AFB00010 */  sw    $s0, 0x10($sp)
/* 100918 7F0CBDE8 0FC31996 */  jal   image_related_calls_decompressdata_function
/* 10091C 7F0CBDEC 8FA40054 */   lw    $a0, 0x54($sp)
/* 100920 7F0CBDF0 10000007 */  b     .L7F0CBE10
/* 100924 7F0CBDF4 8FA30044 */   lw    $v1, 0x44($sp)
.L7F0CBDF8:
/* 100928 7F0CBDF8 8E050008 */  lw    $a1, 8($s0)
/* 10092C 7F0CBDFC AFA30044 */  sw    $v1, 0x44($sp)
/* 100930 7F0CBE00 AFB00010 */  sw    $s0, 0x10($sp)
/* 100934 7F0CBE04 0FC31F7F */  jal   process_huffman_compressed_images
/* 100938 7F0CBE08 8FA40054 */   lw    $a0, 0x54($sp)
/* 10093C 7F0CBE0C 8FA30044 */  lw    $v1, 0x44($sp)
.L7F0CBE10:
/* 100940 7F0CBE10 8E080008 */  lw    $t0, 8($s0)
/* 100944 7F0CBE14 02002025 */  move  $a0, $s0
/* 100948 7F0CBE18 01024821 */  addu  $t1, $t0, $v0
/* 10094C 7F0CBE1C AE090008 */  sw    $t1, 8($s0)
/* 100950 7F0CBE20 0FC32ED9 */  jal   sub_GAME_7F0CBB64
/* 100954 7F0CBE24 AFA30044 */   sw    $v1, 0x44($sp)
/* 100958 7F0CBE28 8FA30044 */  lw    $v1, 0x44($sp)
.L7F0CBE2C:
/* 10095C 7F0CBE2C 0C003A2C */  jal   osVirtualToPhysical
/* 100960 7F0CBE30 8C640004 */   lw    $a0, 4($v1)
/* 100964 7F0CBE34 8FAB0FF8 */  lw    $t3, 0xff8($sp)
/* 100968 7F0CBE38 AD620000 */  sw    $v0, ($t3)
.L7F0CBE3C:
/* 10096C 7F0CBE3C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 100970 7F0CBE40 8FB00020 */  lw    $s0, 0x20($sp)
/* 100974 7F0CBE44 27BD0FF8 */  addiu $sp, $sp, 0xff8
/* 100978 7F0CBE48 03E00008 */  jr    $ra
/* 10097C 7F0CBE4C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CBE50(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBE50
/* 100980 7F0CBE50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 100984 7F0CBE54 AFBF002C */  sw    $ra, 0x2c($sp)
/* 100988 7F0CBE58 AFB50028 */  sw    $s5, 0x28($sp)
/* 10098C 7F0CBE5C AFB40024 */  sw    $s4, 0x24($sp)
/* 100990 7F0CBE60 AFB30020 */  sw    $s3, 0x20($sp)
/* 100994 7F0CBE64 AFB2001C */  sw    $s2, 0x1c($sp)
/* 100998 7F0CBE68 AFB10018 */  sw    $s1, 0x18($sp)
/* 10099C 7F0CBE6C AFB00014 */  sw    $s0, 0x14($sp)
/* 1009A0 7F0CBE70 84820016 */  lh    $v0, 0x16($a0)
/* 1009A4 7F0CBE74 0080A025 */  move  $s4, $a0
/* 1009A8 7F0CBE78 00A0A825 */  move  $s5, $a1
/* 1009AC 7F0CBE7C 8C930018 */  lw    $s3, 0x18($a0)
/* 1009B0 7F0CBE80 18400010 */  blez  $v0, .L7F0CBEC4
/* 1009B4 7F0CBE84 00009025 */   move  $s2, $zero
/* 1009B8 7F0CBE88 00008025 */  move  $s0, $zero
/* 1009BC 7F0CBE8C 02608825 */  move  $s1, $s3
.L7F0CBE90:
/* 1009C0 7F0CBE90 8E2E0000 */  lw    $t6, ($s1)
/* 1009C4 7F0CBE94 02132021 */  addu  $a0, $s0, $s3
/* 1009C8 7F0CBE98 29C10BB9 */  slti  $at, $t6, 0xbb9
/* 1009CC 7F0CBE9C 50200005 */  beql  $at, $zero, .L7F0CBEB4
/* 1009D0 7F0CBEA0 26520001 */   addiu $s2, $s2, 1
/* 1009D4 7F0CBEA4 0FC32F06 */  jal   load_image_to_buffer
/* 1009D8 7F0CBEA8 02A02825 */   move  $a1, $s5
/* 1009DC 7F0CBEAC 86820016 */  lh    $v0, 0x16($s4)
/* 1009E0 7F0CBEB0 26520001 */  addiu $s2, $s2, 1
.L7F0CBEB4:
/* 1009E4 7F0CBEB4 0242082A */  slt   $at, $s2, $v0
/* 1009E8 7F0CBEB8 2610000C */  addiu $s0, $s0, 0xc
/* 1009EC 7F0CBEBC 1420FFF4 */  bnez  $at, .L7F0CBE90
/* 1009F0 7F0CBEC0 2631000C */   addiu $s1, $s1, 0xc
.L7F0CBEC4:
/* 1009F4 7F0CBEC4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1009F8 7F0CBEC8 8FB00014 */  lw    $s0, 0x14($sp)
/* 1009FC 7F0CBECC 8FB10018 */  lw    $s1, 0x18($sp)
/* 100A00 7F0CBED0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100A04 7F0CBED4 8FB30020 */  lw    $s3, 0x20($sp)
/* 100A08 7F0CBED8 8FB40024 */  lw    $s4, 0x24($sp)
/* 100A0C 7F0CBEDC 8FB50028 */  lw    $s5, 0x28($sp)
/* 100A10 7F0CBEE0 03E00008 */  jr    $ra
/* 100A14 7F0CBEE4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void calls_load_image_to_buffer(uint *image,uint *buffer)
{
    load_image_to_buffer(&image,buffer);
}
#else
GLOBAL_ASM(
.text
glabel calls_load_image_to_buffer
/* 100A18 7F0CBEE8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 100A1C 7F0CBEEC AFBF0014 */  sw    $ra, 0x14($sp)
/* 100A20 7F0CBEF0 AFA4001C */  sw    $a0, 0x1c($sp)
/* 100A24 7F0CBEF4 0FC32F06 */  jal   load_image_to_buffer
/* 100A28 7F0CBEF8 27A4001C */   addiu $a0, $sp, 0x1c
/* 100A2C 7F0CBEFC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 100A30 7F0CBF00 27BD0020 */  addiu $sp, $sp, 0x20
/* 100A34 7F0CBF04 03E00008 */  jr    $ra
/* 100A38 7F0CBF08 00000000 */   nop   
)
#endif


