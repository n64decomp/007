#include "ultra64.h"


char die_blood_image_1[] = {
    0,0x20,   3,   5,   4,   2,0x60,0x21,0x22,   1,0xE0,0xE0,0xE0,0xE0,
    0xE0,0xE0,0xE0,0x60,   3,0x24,   2,0xA0,   2,0xC0,   1,0x22,   0,   3,
       6,   7,   6,   4,0x20,   1,   2,0x23,0x24,   3,   2,0x80,0x21,0xE0,
    0xE0,0xE0,0xE0,0xE0,0xE0,0x60,   5,0x46,   4,0x80,0x24,0xFF,   0,   1,
       3,0xFF,0x80,   3,0x44,   0,0x29,   8,   7,0xFF,   0,   2,   2,0xFF,
       2,0x24,0x25,0x26,   5,   4,   2,0x41,   2,   3,   4,   6,0xFF,   0,
       4,   4,0xFF,0xFF,   0,   5,   2,0xFF,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
       0,0xFF,   0,   3,   3,0xFF,   7,0x48,   6,0x60,0xFF,   0,   2,   3,
    0xFF,   6,   7,0xFF,   0,   2,   4,0xFF,0x60,   5,0x66,   0, 0xB, 0xA,
       9,   8,0x26,0x47,   8,0x27,   5,   4,0x43,   4,   5,   7, 0xB,0xFF,
       0,   3,   8,0xFF,0xFF,   0,   5,   5,0xFF,0xFF,   0,   5,   4,0xFF,
    0xE0,0x80,   1,0x22,   1,0xE0,0x20,   1,0x22,0x21,0xE0,0xE0,   0,0xFF,
       0,   2,   7,0xFF,0x4A,   9,   7,0x60,   8,0x29,0xFF,   0,   2,   6,
    0xFF,0xFF,   0,   4,   3,0xFF,0xFF,   0,   5,   2,0xFF,0xFF,   0,   5,
       2,0xFF,0xFF,   0,   2,   5,0xFF,0x88,   0, 0xC, 0xB, 0xA,0xE9,   7,
    0x65,   6,   8, 0xF, 0xE, 0xD,0xFF,   0,   5,   7,0xFF,0xFF,   0,   6,
       5,0xFF,0xFF,   0,   6,   4,0xFF,0xE0,0x60,   2,0x43,   2,   1,0xE0,
    0x64,   3,0x22,0x21,0xE0,0x80,0xFF,   0,   5,   5,0xFF, 0xB,0x4C, 0xB,
       9,0x40,0xFF,   0,   4,   5,0xFF, 0xA, 0xB, 0xA,0xFF,   0,   3,   7,
    0xFF,0xFF,   0,   5,   5,0xFF,0xFF,   0,   5,   4,0xFF,0xFF,   0,   4,
       5,0xFF,0xAA,   0,0x2D, 0xC,0xAB, 0xA,   9,   7,0x26,   7,   8,0xFF,
     0xB,   3,   3,0xFF,0x12,0x11,0x10,0xFF,   1,   4, 0xA,0xFF,0xFF,   0,
       6,   8,0xFF,0xFF,   0,   7,   5,0xFF,0xFF,   0,   8,   3,0xFF,0xE0,
    0x20,   1,   4,0x45,0x24,   3,0xA0,   2,   8,   7,0x26,   5,0x24,0x23,
    0x22,   1,0x20,0x41,0x42,   1,   0,0xFF,   0,   6,   5,0xFF,0xFF,   2,
       1, 0xA,0xFF, 0xD,0x4E, 0xD,0xFF,   0,   5,   6,0xFF,0x20,0xFF,   0,
       8,   2,0xFF,0x6C,0xFF,   2,   1,   9,0xFF,0xFF,   0,   5,   7,0xFF,
    0xFF,   0,   5,   7,0xFF,0xCC,   0, 0xF,0x2E,0x8D, 0xC, 0xB,   9,0x28,
       9, 0xB,0x34,0x13,0x12,0x11,0xFF,   2,   5,   9,0xFF,0xFF,   1,   6,
       8,0xFF,0xFF,   1,   7,   5,0xFF,0xFF,   0,   9,   2,0xFF,   0,0x41,
    0x80,   3,   5,0x47,0x26,   5,   4,   3,   1,   0,   1,   2, 0xB, 0xC,
     0xA,   9,   8,   7,0x26,0x25,0x24,0xA3,0x64,   3,0xFF,   2,   6,   4,
    0xFF,0xFF,   3,   2,   9,0xFF,0x2F,0x50, 0xF,0xFF,   0,   6,   8,0xFF,
       0,0xFF,   0, 0xA,   2,0xFF,0xFF,   0,   6,   7,0xFF,0x8E,0xFF,   2,
       3,   9,0xFF,0xFF,   3,   1, 0xA,0xFF,0xCE,   0,0x11,0x30,0x4F,0x2E,
     0xC, 0xB,0x2A, 0xB,0x16,0x17,0x16,0x15,0x14,0x13,0xFF,   4,   3, 0xB,
    0xFF,0xFF,   3,   5,   8,0xFF,0xFF,   2,   6,   7,0xFF,0xFF,   2,   7,
       5,0xFF,0xFF,   2,   8,   2,0xFF,0x43,   2,   1,0x40,   5,   7,   8,
    0x29,0x28,0x27,   6,   5,   4,   5, 0xB, 0xE, 0xF, 0xD, 0xB, 0xA,   9,
    0x28,0x27,0x46,0xA5,0x66,0xFF,   5,   3,   5,0xFF, 0xF,0x10,0x31,0x32,
    0x31,0xFF,   1,   6,   9,0xFF,0xFF,   0,   9,   6,0xFF,0xFF,   0,   9,
       6,0xFF,0xF0,0xD0,   1,0x11,0x30,0x4F, 0xE, 0xD, 0xC,0x2B,0xFF, 0xE,
       6,   3,0xFF,0x38,0x17,0x16,0x14,0x13,0x12,0xFF,   6,   1, 0xB,0xFF,
    0xFF,   5,   3,   9,0xFF,0xFF,   4,   5,   7,0xFF,0xFF,   4,   6,   5,
    0xFF,0x44,   3,   2,   1,   0,   2,   5,   8,0x89,0x28,0x47,   8, 0xC,
     0xF,0x30, 0xE, 0xC, 0xA,0x29,0x28,0x67,0xA6,0x27,   8, 0xC,0x10,0x31,
    0xB2,0xFF,   3,   4, 0xB,0xFF,0xFF,   1,   8,   9,0xFF,0xFF,   3,   4,
     0xB,0xFF,0x91,0x30,0xF1,   4,0x2F,0x2E,0x2D, 0xC,0x4A,0x57,0x16,0x14,
    0x13,0x12,0x11,0x10, 0xF, 0xE,0xFF,   7,   2,   8,0xFF,0xFF,   7,   3,
       6,0xFF,0x23,   2,   1,0x20,   1,   4,   6,   7,0x48,0x47,0x26,   7,
       8, 0xB, 0xE,0x2F, 0xE, 0xB, 0xA,   8,0x27,0xA6,0x85,0x26,   7, 0xA,
     0xE, 0xF,0x30,0xB1,0x10,0xFF,   4,   4, 0xC,0xFF,0x70,0x8F,0xD0,   6,
    0x2E,0x2D, 0xC, 0xB,0x2A,0xFF,0x12,   3,   6,0xFF,0x57,0x15,0x14,0x13,
    0x12,0x11,0x10, 0xF, 0xE, 0xD, 0xC, 0xA,   3,   2,   1,0x20,   2,   4,
       6,   7,0x48,0x47,0x26,   7,   8, 0xB, 0xE, 0xF,0x10, 0xF, 0xD, 0xA,
       9,   8,   7,0x26,   5,0x46,0xA5,   6,   7,   9, 0xD, 0xF,0x50,0xB1,
    0x50,0xEF,0x90, 0xF,0x10,   9,0x2C,0x2B, 0xA,   9, 0xA,0x16,0x17,0x16,
    0x15,0x14,0x13,0x11,0x10, 0xF, 0xE,0x2D, 0xC, 0xB, 0xA,   7,   2,   1,
    0x20,   1,   3,   4,   6,0x47,   6,0xFF, 0xF,   8,   5,0xFF,0x66,   7,
     0xA, 0xC, 0xE, 0xF, 0xE, 0xD, 0xA,   8,   7,   6,   5,0x64,   5,0xC4,
       6,   8, 0xB, 0xD, 0xE,0x4F,0xB0,0x2F,0xEE, 0xE,0x6F,0x4E, 0xB,0x4B,
     0xA, 0xB,0x14,0x16,0x17,0x16,0x15,0x13,0x12,0x11,0x10, 0xF, 0xE, 0xD,
    0x2C, 0xB, 0xA,   8,   4,   1,0x20,   1,   2,   4,   5,   6,0x27,0xFF,
    0x12,   6,   4,0xFF,0xFF,0x11,   6,   7,0xFF,0xFF,0x11,   6,   7,0xFF,
    0x46,   8,   9, 0xC, 0xE,0x2F, 0xE, 0xB,   9,   7,   6,   5,0xE4,0x23,
    0x24,   5,   7, 0xB, 0xD,0x4E,0x4F,0x90,0x2F,0x4E,0x6D,0x2E,0x6F,0x4E,
     0xD,0x2A, 0xB,0x12,0x16,0x17,0x16,0x15,0x14,0x13,0x11,0x10, 0xF, 0xE,
    0x2D, 0xC,0x2B, 0xA,   9,   5,   2,0x20,   1,   2,   4,   5,   6,0x27,
    0xFF,0x15,   1,   9,0xFF,0x13,0xFF,0x15,   1, 0xB,0xFF,0xFF,0x14,   5,
       5,0xFF,   6,   7,   8,   9, 0xB, 0xD,0x2F, 0xE, 0xC, 0xA,   8,   6,
       5,   4,0x23,0x84,0x43,   4,   5,   7, 0xB,0x2D,0x4E,0x8F,0x30,0x2F,
    0x2E,0xCD, 0xE,0x4F,0x6E, 0xF, 0xB, 0xF,0x15,0x56,0x15,0x13,0x12,0x11,
    0x10, 0xF, 0xE, 0xD,0x2C,0x2B, 0xA,   9,   6,   2,0x20,   1,   2,   4,
       5,   6,   7, 0xC,0x12,0x13,0x14,0x13,0x27,   8,   9, 0xB, 0xD, 0xE,
     0xF, 0xE, 0xD, 0xB,   9,   7,   5,   4,0x43,0x84,0x43,   4,   6, 0xB,
    0x4D,0x6E,0xEF, 0xE,0xED,0x2E,0x2F,0x6E,0x11,0x14,0x56,0x15,0x14,0x13,
    0x11,0x10, 0xF, 0xE, 0xD,0x2C,0x4B,0x2A,   7,   3,   1,   0,   1,   2,
       4,   5,   6,   8, 0xE,0x12,0x13,0x14,0x13, 0xD,0x28,   9, 0xB, 0xD,
     0xE, 0xF,0x2E, 0xC, 0xA,   8,   5,   4,0x63,0x64,0x43,   4,   7, 0xB,
     0xC,0x4D,0x8E,0xAF,0x2E,0x2D,0x6C,0x2D,0x2E,0x2F,0x6E,0x13,0x56,0x15,
    0x13,0x12,0x10, 0xF, 0xE,0x2D, 0xC,0x6B,0x2A,   8,   4,   1,   0,   1,
       2,   4,   5,   7, 0xA, 0xF,0x12,0x13,0x34,0x13,   9,   8,   9, 0xB,
     0xD,0x6E, 0xD, 0xC, 0xA,   6,   4,   3,0x22,   3,0x84,0x23,   4,   8,
     0xB, 0xC,0xAD,0x8E,0x4F,0x2E,0x2D,0xAC, 0xD,0xEE,0x16,0x15,0x14,0x13,
    0x11,0x10, 0xE,0x2D, 0xC, 0xB,0x2A,0x89,   8,   4,   1,0x20,   1,   3,
       5,   7, 0xB, 0xF,0x11,0x12,0x33,0x12, 0xA,0x28, 0xA, 0xC,0xCD,0xFF,
    0x20,   4,   4,0xFF,0xFF,0x1B,   8,   6,0xFF,0xFF,0x18, 0xC,   5,0xFF,
    0xFF,0x17, 0xF,   2,0xFF,   1,   2,0xC3,   4,   8, 0xA,0x2B,0xCC,0xED,
    0x2C,0x4B,0x2A,0x2B,0x2C,0xCD,0x18,0x13,0x12,0x10, 0xF, 0xD,0x2C, 0xB,
    0x2A,0xA9,   8,   6,   2,   0,   1,   2,   4,   6,   8, 0xC, 0xF,0x11,
    0x32,0x13,0x32,0x29, 0xA,0x2C,0x4D, 0xE, 0xF,0x11,0x12,0x33,0xFF,0x1A,
       9,   8,0xFF,0xFF,0x1A, 0xB,   6,0xFF,   2,0xA3,   4,   6,   8,   9,
     0xA,0x4B,0xEC,0xAD, 0xC,0x4B,0x6A,0x2B, 0xC,0xCD,0x1C, 0xF, 0xD, 0xB,
    0x2A,   9,   8,0xE7,   6,   5,   3,   0,   1,   2,   3,   5,   8, 0xB,
     0xD, 0xF,0x90, 0xF, 0xC,0x6A,0x2B, 0xC, 0xE, 0xF,0x10,0x71,0xFF,0x1D,
       9,   7,0xFF,0xFF,0x1D, 0xC,   2,0xFF,0x61,   2,   3,   4,   6,   7,
    0x28,0xC9,0xAA,0x2B,0x4A,0x29,0x88,0x29, 0xA,0xCB,0x1F, 0xA,   9,0x28,
       7,0x26,0x45,0x66,   5,   4,   3,0x22,   3,   4,   5,   8, 0xB, 0xD,
    0x2E,0x6F, 0xE, 0xD, 0xA,0x69, 0xA, 0xB, 0xD, 0xE,0x2F,0x70,0xFF,0x21,
       5,   9,0xFF,0xFF,0x20,   9,   6,0xFF,0x20,0x21,   2,   3,   5,0x26,
    0x27,0xE8,0x28,0xC9,0x28,0x27,0x26,0x47,   8,0x29,0x2A,0x4B, 0xA,0x22,
       7,0x26,   5,0x84,0x65,0x24,0x63,   4,   6,   9, 0xA, 0xC,0x2D,0x6E,
     0xD, 0xC, 0xA,   9,0x48,   9, 0xA, 0xC, 0xD,0x4E,0x6F,0x10,0xFF,0x22,
       7,   9,0xFF,0x20,   1,   2,0x23,   4,0x25,0x86,0xE7,0x88,0x27,0x26,
    0x65,0x26,   7,0x28,   9,0x6A,   9,0x25,0x24,0x23,0x22,0x23,0x64,0x23,
    0x42,   3,   5,   7,   8,   9, 0xA, 0xB,0x2C, 0xD,0x4C, 0xB,   9,   8,
    0x47,   8,   9, 0xB,0x2C,0x6D,0x2E, 0xF,0x10,0xFF,0x27,   1, 0xD,0xFF,
       0,0x21,0x22,0x23,0x44,0xE5,0x25,0x46,0x47,0x26,0x45,0x84,   5,   6,
       7,   8,0x29, 0xA,0x49,0x29,   1,0x60,0x21,0x42,0xA1,   2,   4,   5,
       6,   7,   8,   9,0x8A,   9,   8,   7,   6,   5,   4,   5,   6,   7,
       8,   9,0x4A,0x4B, 0xC, 0xD,0x2E, 0xD,   2,0x60,0x41,0x62,0xE3,   3,
    0xC4,0x23,0x42,   1,   2,0xFF,0x2B, 0xB,   3,0xFF,0xFF,0x2C,   9,   4,
    0xFF,0xFF,0x2D,   7,   5,0xFF,0xFF,0x2F,   5,   4,0xFF,   7,0x68,0x27,
    0x2B,0x60,0xFF,0x2C, 0xB,   2,0xFF,0xFF,0x2D,   9,   4,0xFF,0xFF,0x2D,
       8,   5,0xFF,0xFF,0x2D,   8,   5,0xFF,   2,0x81,   2,   3,   4,   5,
       6,   7,   8,0x29,0x2A,0x49,   8,   7,   5,0x24,   5,   6,   7,   8,
    0x29,0x6A, 0xB, 0xC, 0xD,0x4E, 0xC,   3,   1,0x40,0x61,0x62,0xE3,0x24,
    0x45,0x24,0x23,0x22,   1,0xFF,0x2C, 0xA,   4,0xFF,0xFF,0x2D,   8,   7,
    0xFF,0xFF,0x2E,   6,   8,0xFF,0xFF,0x2F,   4,   9,0xFF,0x10, 0xF, 0xE,
     0xB,   9,0x28,0x27,0x2C,   0,0xFF,0x2D, 0xB,   2,0xFF,0xFF,0x2E,   8,
       6,0xFF,0xFF,0x2F,   6,   7,0xFF,0xFF,0x30,   3,   9,0xFF,0x10,0xFF,
    0x31,   2,   9,0xFF,0xFF,0x30,   5,   6,0xFF,   3,0x22,0x23,   4,   5,
    0x26,   7,   8,   9,0x8A,0x29,   8,   7,   6,0x45,   7,   8,0x29,0x6A,
    0x2B, 0xC,0x2E,0x2F, 0xE, 0xC,   3,   2,0x61,0x62,0xC3,0x44,0x25,0x86,
    0x25,0x24,0xFF,0x2F,   8,   2,0xFF,0xFF,0x2F,   6,   7,0xFF,0xFF,0x2F,
       5,   9,0xFF,0xFF,0x30,   3, 0xB,0xFF,0x12,0x31,0x10, 0xF, 0xD, 0xB,
     0xA,0x29,   8,0x2F,0xFF,0x30,   4, 0xA,0xFF,0x6F,0x2E, 0xC,0x63,0x24,
    0x25,   6,   7,0x28,0x29,0x48,0x27,   6,   5,0x24,   5,   6,0x27,0x48,
    0x49, 0xA, 0xB, 0xC,0x6D, 0xC,   8,   2,0xA0,0x41,0x82,0x43,0x24,   5,
    0xE6,   9, 0xC, 0xE, 0xF,0x70, 0xF, 0xE, 0xD, 0xC, 0xA,   9,0x48,0x31,
    0x2F,0x4E, 0xD, 0xC,   8,   5,0x84,   5,   6,   7,0x88,0x27,0x26,   5,
    0x44,   5,0x26,0x27,0x68,   9, 0xA, 0xB, 0xC,0x4D,0x2C, 0xA,   6,   2,
    0xC0,0x21,0x62,0x23,   4,   6,0xE8,0x28,   9, 0xB, 0xD, 0xE, 0xF,0x50,
    0x2F, 0xE, 0xD, 0xC, 0xA,   9,0x28,   9,0x33,0x4E,0x2D, 0xC,   9,   6,
    0x24,   3,0x24,   5,   6,   7,0x68,0x27,0x26,0x25,0x44,   5,0x26,0x47,
    0x48,   9, 0xA, 0xB,0x8C, 0xB, 0xA,   8,   5,   1,0xC0,0x21,0x22,0x23,
       5,   7,   9,0x4A,0x49,0x68,   9, 0xA, 0xC, 0xD, 0xE,0x6F,0x2E,0x2D,
     0xB, 0xA,   9,   8,   9, 0xA,0x34,0x6E, 0xC, 0xA,   6,   5,0x44,   5,
       6,   7,   8,0x49,0x28,0x27,0x46,0x25,0x26,0x27,0x68,0x29, 0xA, 0xB,
     0xC,0x6D,0x2C, 0xB, 0xA,   8,   5,   2,0x21,   0,0x61,0x22,   3,   4,
       5,   7,   9, 0xB,0x4C,0x2B,0x2A,0x49,0x2A, 0xB, 0xD, 0xE, 0xF,0x50,
     0xF,0x4E, 0xD, 0xC, 0xB,0x2A, 0xB, 0xD,0x36,0x2E, 0xD, 0xC, 0xA,   6,
    0x64,   5,   7,0x28,   9,0x28,0x47,0xA6,0x67,0x68,   9, 0xA, 0xB,0xCC,
    0x2B, 0xA,   9,   7,   4,   2,0x21,0x20,0x21,0x22,   3,   4,   5,   7,
       9, 0xB,0x2D, 0xC,0x2B,0x2A,0x69,0x2A, 0xC, 0xD, 0xE,0x6F,0x2E,0x2D,
    0x2C, 0xB, 0xA, 0xB, 0xC, 0xE,0x38,0x4D, 0xA,   6,0x44,   5,   6,0x28,
    0x29,0x28,0xA7,0xFF,0x41,   3,   1,0xFF, 0xE, 0xD,   9,0xA8,   9, 0xA,
     0xD, 0xE,0x2D,0x2C,0x6B,0x2A,   9,   7,   5,   3,   2,   1,0x40,0x21,
       2,   3,   4,   5,   7, 0xA, 0xC,0x4D, 0xC, 0xB,0x2A,0x89,0x2A, 0xC,
     0xD, 0xE,0x4F, 0xE,0x2D,0x4C,0x4B, 0xC, 0xD, 0xF,0x3A,0x4D,0xFF,0x41,
       2,   3,0xFF,0x45,   7,   8,0x49,0x28,0x67,   8, 0xC, 0xE,0x2F, 0xE,
     0xD, 0xA,0x68,   9, 0xB, 0xD, 0xF,0x2E, 0xD, 0xC,0x2B,0x6A,0x29,   8,
       6,   4,   2,0x21,0x20,0x21,   2,   3,   4,   5,   7, 0xA, 0xC, 0xD,
    0x2E, 0xC, 0xB,0x2A,0x29,0x48,0x29, 0xA, 0xC, 0xD, 0xE,0x2F, 0xE,0x2D,
    0x2C,0x6B, 0xC, 0xD, 0xE, 0xF,0x3C,0x6D, 0xC, 0xB, 0xA,0x69,0x68,   9,
     0xA, 0xC, 0xE,0x4F, 0xE, 0xD, 0xB,   9,0x28,   9, 0xB, 0xD, 0xE,0x2F,
     0xE, 0xC, 0xB,0x2A,0x89,0x28,   6,   5,   3,   2,0x21,   0,0x21,0x22,
       4,   5,   7, 0xA, 0xC, 0xD,0x2E, 0xD, 0xC, 0xB, 0xA,   9,0xA8,   9,
     0xA, 0xC, 0xD,0x4E, 0xD,0x2C,0x8B,0x2C, 0xD, 0xE, 0xF,0x3F,0x2C,0x2B,
     0xA,0x29,0xA8,   9, 0xA, 0xB,0x2D,0x2E,0x2D, 0xB, 0xA,0x48,   9, 0xB,
     0xD,0x2E, 0xD, 0xC, 0xB,   9,0x68,0x67,0x26,   4,   3,   1,0x80,0x21,
       2,   4,   6,   8, 0xB, 0xC, 0xD, 0xE, 0xD, 0xC, 0xA,   9,   8,0x27,
    0x66,   7,   8, 0xA, 0xC,0x6D, 0xC, 0xB,0xAA, 0xB,0x2C,0x2D,0x41,0x2B,
     0xA,0x29,0x88,0x29, 0xA, 0xB, 0xC,0x6D,0x2C, 0xB,0x69, 0xB, 0xC, 0xD,
     0xE,0x2D, 0xC, 0xA,   9,   8,0xE7,   6,   5,   3,   2,   1,0x60,0x21,
       2,   4,   6,   8, 0xB, 0xC,0x4E, 0xD, 0xB, 0xA,   9,   8,   7,0x86,
       7,   9, 0xB, 0xC,0x4D, 0xC, 0xB,0x2A,0x49,0x2A, 0xB,0x4C, 0xD,0x43,
     0xA,0x49,0x48,0x29,0x2A, 0xB,0x4C, 0xD,0x4C, 0xB, 0xA,0x49, 0xA, 0xC,
    0x6D, 0xC, 0xB,   9,   8,   7,0x46,0x87,   6,   5,   4,   3,   2,0x21,
       0,0x21,   2,   3,   4,   6,   8, 0xA, 0xC,0x8D, 0xB, 0xA,   8,   7,
    0x26,0x25,   6,   7,   8, 0xB, 0xC,0x6D, 0xB,0x2A,0x69,0x2A,0x2B,0x4C,
    0x46,   8,0x67,0x28,0x29,0xEA, 0xA,0x29,   8,0x29,0xCA,   9,   7,   6,
    0x85,   6,0x27,   8,   7,   6,   4,   3,   2,   1,0x60,   1,   2,   3,
       5,   7,   9,0xEA,   9,   8,   7,0x65,   6,   8,0xEA,   9,0x88,   9,
    0xAA,0x49,   6,0xE7,0xE7,0xE7,0x87,   5,0x24,0x23,   4,   5,0xA7,   6,
       4,   2,0x21,0x60,   1,   2,   4,   6,0xE7,0xA7,   6,0xE7,0xE7,0xE7,
       7,0x4B,0xE5,0xE5,0xE5,0xA5,   4,0x23,   4,0xE5,0x45,   3,   2,   1,
    0x40,   1,   2,   4,0xE5,0xE5,0xE5,0xE5,0xE5,0x25,0x4B,0xE5,0xE5,0xE5,
    0xA5,   4,0x23,   4,0xE5,0x45,   3,   2,   1,0x40,   1,   2,   4,0xE5,
    0xE5,0xE5,0xE5,0xE5,0x25,0x4B,0xE5,0xE5,0xE5,0xE5,0xE5,0xE5,0xE5,0xE5,
    0xE5,0xE5,0xE5,0xE5
};

s32 D_8002C50C = 0;

#ifdef NONMATCHING
void insert_imageDL(void) {

}
#else
GLOBAL_ASM(
.text
glabel insert_imageDL
/* 050C00 7F01C0D0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 050C04 7F01C0D4 AFB00018 */  sw    $s0, 0x18($sp)
/* 050C08 7F01C0D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 050C0C 7F01C0DC 3C0EBA00 */  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
/* 050C10 7F01C0E0 35CE1402 */  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
/* 050C14 7F01C0E4 3C0F0030 */  lui   $t7, 0x30
/* 050C18 7F01C0E8 AC8F0004 */  sw    $t7, 4($a0)
/* 050C1C 7F01C0EC AC8E0000 */  sw    $t6, ($a0)
/* 050C20 7F01C0F0 24900008 */  addiu $s0, $a0, 8
/* 050C24 7F01C0F4 AFB00030 */  sw    $s0, 0x30($sp)
/* 050C28 7F01C0F8 0C001107 */  jal   get_video2_settings_txtClipW
/* 050C2C 7F01C0FC 26100008 */   addiu $s0, $s0, 8
/* 050C30 7F01C100 2458FFFF */  addiu $t8, $v0, -1
/* 050C34 7F01C104 8FA90030 */  lw    $t1, 0x30($sp)
/* 050C38 7F01C108 33190FFF */  andi  $t9, $t8, 0xfff
/* 050C3C 7F01C10C 3C01FF10 */  lui   $at, 0xff10
/* 050C40 7F01C110 03214025 */  or    $t0, $t9, $at
/* 050C44 7F01C114 0C000F07 */  jal   get_video_settings2_frameb
/* 050C48 7F01C118 AD280000 */   sw    $t0, ($t1)
/* 050C4C 7F01C11C 0C003A2C */  jal   osVirtualToPhysical
/* 050C50 7F01C120 00402025 */   move  $a0, $v0
/* 050C54 7F01C124 8FAA0030 */  lw    $t2, 0x30($sp)
/* 050C58 7F01C128 02001825 */  move  $v1, $s0
/* 050C5C 7F01C12C 3C0C0001 */  lui   $t4, (0x00010001 >> 16) # lui $t4, 1
/* 050C60 7F01C130 AD420004 */  sw    $v0, 4($t2)
/* 050C64 7F01C134 358C0001 */  ori   $t4, (0x00010001 & 0xFFFF) # ori $t4, $t4, 1
/* 050C68 7F01C138 3C0BF700 */  lui   $t3, 0xf700
/* 050C6C 7F01C13C AC6B0000 */  sw    $t3, ($v1)
/* 050C70 7F01C140 AC6C0004 */  sw    $t4, 4($v1)
/* 050C74 7F01C144 26100008 */  addiu $s0, $s0, 8
/* 050C78 7F01C148 AFB00028 */  sw    $s0, 0x28($sp)
/* 050C7C 7F01C14C 0C001107 */  jal   get_video2_settings_txtClipW
/* 050C80 7F01C150 26100008 */   addiu $s0, $s0, 8
/* 050C84 7F01C154 0C00110B */  jal   get_video2_settings_txtClipH
/* 050C88 7F01C158 A7A20022 */   sh    $v0, 0x22($sp)
/* 050C8C 7F01C15C 87B90022 */  lh    $t9, 0x22($sp)
/* 050C90 7F01C160 244DFFFF */  addiu $t5, $v0, -1
/* 050C94 7F01C164 8FA30028 */  lw    $v1, 0x28($sp)
/* 050C98 7F01C168 31AE03FF */  andi  $t6, $t5, 0x3ff
/* 050C9C 7F01C16C 2728FFFF */  addiu $t0, $t9, -1
/* 050CA0 7F01C170 310903FF */  andi  $t1, $t0, 0x3ff
/* 050CA4 7F01C174 000E7880 */  sll   $t7, $t6, 2
/* 050CA8 7F01C178 3C01F600 */  lui   $at, 0xf600
/* 050CAC 7F01C17C 01E1C025 */  or    $t8, $t7, $at
/* 050CB0 7F01C180 00095380 */  sll   $t2, $t1, 0xe
/* 050CB4 7F01C184 030A5825 */  or    $t3, $t8, $t2
/* 050CB8 7F01C188 AC6B0000 */  sw    $t3, ($v1)
/* 050CBC 7F01C18C AC600004 */  sw    $zero, 4($v1)
/* 050CC0 7F01C190 8FBF001C */  lw    $ra, 0x1c($sp)
/* 050CC4 7F01C194 02001025 */  move  $v0, $s0
/* 050CC8 7F01C198 8FB00018 */  lw    $s0, 0x18($sp)
/* 050CCC 7F01C19C 03E00008 */  jr    $ra
/* 050CD0 7F01C1A0 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01C1A4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01C1A4
/* 050CD4 7F01C1A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 050CD8 7F01C1A8 3C0E0103 */  lui   $t6, (0x01030040 >> 16) # lui $t6, 0x103
/* 050CDC 7F01C1AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 050CE0 7F01C1B0 35CE0040 */  ori   $t6, (0x01030040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 050CE4 7F01C1B4 AC8E0000 */  sw    $t6, ($a0)
/* 050CE8 7F01C1B8 00801825 */  move  $v1, $a0
/* 050CEC 7F01C1BC 24850008 */  addiu $a1, $a0, 8
/* 050CF0 7F01C1C0 3C048007 */  lui   $a0, %hi(matrix_buffer_gunbarrel_0)
/* 050CF4 7F01C1C4 8C84955C */  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
/* 050CF8 7F01C1C8 AFA50020 */  sw    $a1, 0x20($sp)
/* 050CFC 7F01C1CC 0C003A2C */  jal   osVirtualToPhysical
/* 050D00 7F01C1D0 AFA3001C */   sw    $v1, 0x1c($sp)
/* 050D04 7F01C1D4 8FA3001C */  lw    $v1, 0x1c($sp)
/* 050D08 7F01C1D8 8FA80020 */  lw    $t0, 0x20($sp)
/* 050D0C 7F01C1DC 3C0F0102 */  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
/* 050D10 7F01C1E0 35EF0040 */  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 050D14 7F01C1E4 AC620004 */  sw    $v0, 4($v1)
/* 050D18 7F01C1E8 3C188003 */  lui   $t8, %hi(D_8002A7D0) 
/* 050D1C 7F01C1EC AD0F0000 */  sw    $t7, ($t0)
/* 050D20 7F01C1F0 8F18A7D0 */  lw    $t8, %lo(D_8002A7D0)($t8)
/* 050D24 7F01C1F4 3C098007 */  lui   $t1, %hi(matrix_buffer_rarelogo_2) 
/* 050D28 7F01C1F8 8D299564 */  lw    $t1, %lo(matrix_buffer_rarelogo_2)($t1)
/* 050D2C 7F01C1FC 25050008 */  addiu $a1, $t0, 8
/* 050D30 7F01C200 0018C980 */  sll   $t9, $t8, 6
/* 050D34 7F01C204 AFA50020 */  sw    $a1, 0x20($sp)
/* 050D38 7F01C208 AFA80018 */  sw    $t0, 0x18($sp)
/* 050D3C 7F01C20C 0C003A2C */  jal   osVirtualToPhysical
/* 050D40 7F01C210 03292021 */   addu  $a0, $t9, $t1
/* 050D44 7F01C214 8FA30020 */  lw    $v1, 0x20($sp)
/* 050D48 7F01C218 8FA80018 */  lw    $t0, 0x18($sp)
/* 050D4C 7F01C21C 3C0AE700 */  lui   $t2, 0xe700
/* 050D50 7F01C220 24640008 */  addiu $a0, $v1, 8
/* 050D54 7F01C224 AD020004 */  sw    $v0, 4($t0)
/* 050D58 7F01C228 3C0BBA00 */  lui   $t3, (0xBA001402 >> 16) # lui $t3, 0xba00 gDPSetCycleType(2cycle)
/* 050D5C 7F01C22C AC600004 */  sw    $zero, 4($v1)
/* 050D60 7F01C230 AC6A0000 */  sw    $t2, ($v1)
/* 050D64 7F01C234 356B1402 */  ori   $t3, (0xBA001402 & 0xFFFF) # ori $t3, $t3, 0x1402
/* 050D68 7F01C238 24860008 */  addiu $a2, $a0, 8
/* 050D6C 7F01C23C AC8B0000 */  sw    $t3, ($a0)
/* 050D70 7F01C240 AC800004 */  sw    $zero, 4($a0)
/* 050D74 7F01C244 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900 gDPSetRenderMode(AAOpaSurf)
/* 050D78 7F01C248 3C0D0055 */  lui   $t5, (0x00552048 >> 16) # lui $t5, 0x55
/* 050D7C 7F01C24C 35AD2048 */  ori   $t5, (0x00552048 & 0xFFFF) # ori $t5, $t5, 0x2048
/* 050D80 7F01C250 358C031D */  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 050D84 7F01C254 ACCC0000 */  sw    $t4, ($a2)
/* 050D88 7F01C258 ACCD0004 */  sw    $t5, 4($a2)
/* 050D8C 7F01C25C 24C70008 */  addiu $a3, $a2, 8
/* 050D90 7F01C260 3C0EB700 */  lui   $t6, 0xb700
/* 050D94 7F01C264 240F0204 */  li    $t7, 516
/* 050D98 7F01C268 ACEF0004 */  sw    $t7, 4($a3)
/* 050D9C 7F01C26C ACEE0000 */  sw    $t6, ($a3)
/* 050DA0 7F01C270 8FBF0014 */  lw    $ra, 0x14($sp)
/* 050DA4 7F01C274 24E20008 */  addiu $v0, $a3, 8
/* 050DA8 7F01C278 27BD0020 */  addiu $sp, $sp, 0x20
/* 050DAC 7F01C27C 03E00008 */  jr    $ra
/* 050DB0 7F01C280 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void die_blood_image_routine(void) {

}
#else
GLOBAL_ASM(
.text
glabel die_blood_image_routine
/* 050DB4 7F01C284 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 050DB8 7F01C288 AFBF0024 */  sw    $ra, 0x24($sp)
/* 050DBC 7F01C28C AFB10020 */  sw    $s1, 0x20($sp)
/* 050DC0 7F01C290 14800008 */  bnez  $a0, .L7F01C2B4
/* 050DC4 7F01C294 AFB0001C */   sw    $s0, 0x1c($sp)
/* 050DC8 7F01C298 3C118008 */  lui   $s1, %hi(pPlayer)
/* 050DCC 7F01C29C 2631A0B0 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
/* 050DD0 7F01C2A0 8E2F0000 */  lw    $t7, ($s1)
/* 050DD4 7F01C2A4 3C0E8003 */  lui   $t6, %hi(die_blood_image_1) 
/* 050DD8 7F01C2A8 25CEBB30 */  addiu $t6, %lo(die_blood_image_1) # addiu $t6, $t6, -0x44d0
/* 050DDC 7F01C2AC 1000000D */  b     .L7F01C2E4
/* 050DE0 7F01C2B0 ADEE11A8 */   sw    $t6, 0x11a8($t7)
.L7F01C2B4:
/* 050DE4 7F01C2B4 24010001 */  li    $at, 1
/* 050DE8 7F01C2B8 1481000A */  bne   $a0, $at, .L7F01C2E4
/* 050DEC 7F01C2BC 3C118008 */   lui   $s1, %hi(pPlayer)
/* 050DF0 7F01C2C0 2631A0B0 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
/* 050DF4 7F01C2C4 8E300000 */  lw    $s0, ($s1)
/* 050DF8 7F01C2C8 3C188003 */  lui   $t8, %hi(D_8002C50C) 
/* 050DFC 7F01C2CC 2718C50C */  addiu $t8, %lo(D_8002C50C) # addiu $t8, $t8, -0x3af4
/* 050E00 7F01C2D0 8E0211AC */  lw    $v0, 0x11ac($s0)
/* 050E04 7F01C2D4 0058082B */  sltu  $at, $v0, $t8
/* 050E08 7F01C2D8 10200002 */  beqz  $at, .L7F01C2E4
/* 050E0C 7F01C2DC 00000000 */   nop   
/* 050E10 7F01C2E0 AE0211A8 */  sw    $v0, 0x11a8($s0)
.L7F01C2E4:
/* 050E14 7F01C2E4 3C118008 */  lui   $s1, %hi(pPlayer)
/* 050E18 7F01C2E8 2631A0B0 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
/* 050E1C 7F01C2EC 8E300000 */  lw    $s0, ($s1)
/* 050E20 7F01C2F0 24080001 */  li    $t0, 1
/* 050E24 7F01C2F4 24041E00 */  li    $a0, 7680
/* 050E28 7F01C2F8 8E1911B8 */  lw    $t9, 0x11b8($s0)
/* 050E2C 7F01C2FC 01194823 */  subu  $t1, $t0, $t9
/* 050E30 7F01C300 0FC2F5C5 */  jal   sub_GAME_7F0BD714
/* 050E34 7F01C304 AE0911B8 */   sw    $t1, 0x11b8($s0)
/* 050E38 7F01C308 8E300000 */  lw    $s0, ($s1)
/* 050E3C 7F01C30C 24041E00 */  li    $a0, 7680
/* 050E40 7F01C310 8E0A11B8 */  lw    $t2, 0x11b8($s0)
/* 050E44 7F01C314 000A5880 */  sll   $t3, $t2, 2
/* 050E48 7F01C318 020B6021 */  addu  $t4, $s0, $t3
/* 050E4C 7F01C31C 0FC2F5C5 */  jal   sub_GAME_7F0BD714
/* 050E50 7F01C320 AD8211B0 */   sw    $v0, 0x11b0($t4)
/* 050E54 7F01C324 8E2D0000 */  lw    $t5, ($s1)
/* 050E58 7F01C328 AFA20030 */  sw    $v0, 0x30($sp)
/* 050E5C 7F01C32C 27AE0037 */  addiu $t6, $sp, 0x37
/* 050E60 7F01C330 8DA411A8 */  lw    $a0, 0x11a8($t5)
/* 050E64 7F01C334 AFAE0010 */  sw    $t6, 0x10($sp)
/* 050E68 7F01C338 24050050 */  li    $a1, 80
/* 050E6C 7F01C33C 24060060 */  li    $a2, 96
/* 050E70 7F01C340 0FC072B8 */  jal   decrypt_bleeding_animation_data
/* 050E74 7F01C344 00403825 */   move  $a3, $v0
/* 050E78 7F01C348 8E2F0000 */  lw    $t7, ($s1)
/* 050E7C 7F01C34C 24050050 */  li    $a1, 80
/* 050E80 7F01C350 24060060 */  li    $a2, 96
/* 050E84 7F01C354 ADE211AC */  sw    $v0, 0x11ac($t7)
/* 050E88 7F01C358 8E300000 */  lw    $s0, ($s1)
/* 050E8C 7F01C35C 8FA40030 */  lw    $a0, 0x30($sp)
/* 050E90 7F01C360 8E1811B8 */  lw    $t8, 0x11b8($s0)
/* 050E94 7F01C364 00184080 */  sll   $t0, $t8, 2
/* 050E98 7F01C368 0208C821 */  addu  $t9, $s0, $t0
/* 050E9C 7F01C36C 0FC0745B */  jal   sub_GAME_7F01D16C
/* 050EA0 7F01C370 8F2711B0 */   lw    $a3, 0x11b0($t9)
/* 050EA4 7F01C374 8E300000 */  lw    $s0, ($s1)
/* 050EA8 7F01C378 24050050 */  li    $a1, 80
/* 050EAC 7F01C37C 8E0911B8 */  lw    $t1, 0x11b8($s0)
/* 050EB0 7F01C380 00095080 */  sll   $t2, $t1, 2
/* 050EB4 7F01C384 020A5821 */  addu  $t3, $s0, $t2
/* 050EB8 7F01C388 8D6411B0 */  lw    $a0, 0x11b0($t3)
/* 050EBC 7F01C38C 0FC0740B */  jal   sub_GAME_7F01D02C
/* 050EC0 7F01C390 00803025 */   move  $a2, $a0
/* 050EC4 7F01C394 8E300000 */  lw    $s0, ($s1)
/* 050EC8 7F01C398 24050050 */  li    $a1, 80
/* 050ECC 7F01C39C 8E0C11B8 */  lw    $t4, 0x11b8($s0)
/* 050ED0 7F01C3A0 000C6880 */  sll   $t5, $t4, 2
/* 050ED4 7F01C3A4 020D7021 */  addu  $t6, $s0, $t5
/* 050ED8 7F01C3A8 8DC411B0 */  lw    $a0, 0x11b0($t6)
/* 050EDC 7F01C3AC 0FC073BB */  jal   sub_GAME_7F01CEEC
/* 050EE0 7F01C3B0 00803025 */   move  $a2, $a0
/* 050EE4 7F01C3B4 8E300000 */  lw    $s0, ($s1)
/* 050EE8 7F01C3B8 24051E00 */  li    $a1, 7680
/* 050EEC 7F01C3BC 8E0F11B8 */  lw    $t7, 0x11b8($s0)
/* 050EF0 7F01C3C0 000FC080 */  sll   $t8, $t7, 2
/* 050EF4 7F01C3C4 02184021 */  addu  $t0, $s0, $t8
/* 050EF8 7F01C3C8 8D0411B0 */  lw    $a0, 0x11b0($t0)
/* 050EFC 7F01C3CC 0FC07325 */  jal   sub_GAME_7F01CC94
/* 050F00 7F01C3D0 00803025 */   move  $a2, $a0
/* 050F04 7F01C3D4 8E390000 */  lw    $t9, ($s1)
/* 050F08 7F01C3D8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 050F0C 7F01C3DC 3C0A8003 */  lui   $t2, %hi(D_8002C50C) 
/* 050F10 7F01C3E0 8F2911AC */  lw    $t1, 0x11ac($t9)
/* 050F14 7F01C3E4 254AC50C */  addiu $t2, %lo(D_8002C50C) # addiu $t2, $t2, -0x3af4
/* 050F18 7F01C3E8 8FB10020 */  lw    $s1, 0x20($sp)
/* 050F1C 7F01C3EC 8FB0001C */  lw    $s0, 0x1c($sp)
/* 050F20 7F01C3F0 012A102B */  sltu  $v0, $t1, $t2
/* 050F24 7F01C3F4 38420001 */  xori  $v0, $v0, 1
/* 050F28 7F01C3F8 03E00008 */  jr    $ra
/* 050F2C 7F01C3FC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01C400(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01C400
/* 050F30 7F01C400 27BDFF90 */  addiu $sp, $sp, -0x70
/* 050F34 7F01C404 AFBF001C */  sw    $ra, 0x1c($sp)
/* 050F38 7F01C408 AFB00018 */  sw    $s0, 0x18($sp)
/* 050F3C 7F01C40C 3C0EBA00 */  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H
/* 050F40 7F01C410 35CE0E02 */  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
/* 050F44 7F01C414 AC8E0000 */  sw    $t6, ($a0)
/* 050F48 7F01C418 AC800004 */  sw    $zero, 4($a0)
/* 050F4C 7F01C41C 24830008 */  addiu $v1, $a0, 8
/* 050F50 7F01C420 3C0FBA00 */  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
/* 050F54 7F01C424 35EF0C02 */  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
/* 050F58 7F01C428 24182000 */  li    $t8, 8192
/* 050F5C 7F01C42C AC780004 */  sw    $t8, 4($v1)
/* 050F60 7F01C430 AC6F0000 */  sw    $t7, ($v1)
/* 050F64 7F01C434 0FC07069 */  jal   sub_GAME_7F01C1A4
/* 050F68 7F01C438 24640008 */   addiu $a0, $v1, 8
/* 050F6C 7F01C43C 3C19BB00 */  lui   $t9, (0xBB000001 >> 16) # lui $t9, 0xbb00
/* 050F70 7F01C440 37390001 */  ori   $t9, (0xBB000001 & 0xFFFF) # ori $t9, $t9, 1
/* 050F74 7F01C444 AC590000 */  sw    $t9, ($v0)
/* 050F78 7F01C448 3C088000 */  lui   $t0, (0x80008000 >> 16)
/* 050F7C 7F01C44C 3C09B900 */  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900 #gDPSetRenderMode(OpaSurf)
/* 050F80 7F01C450 3C0A0050 */  lui   $t2, (0x00504340 >> 16) # lui $t2, 0x50
/* 050F84 7F01C454 3C0BFC11 */  lui   $t3, (0xFC119623 >> 16) # lui $t3, 0xfc11
/* 050F88 7F01C458 3C0CFF2F */  lui   $t4, (0xFF2FFFFF >> 16) # lui $t4, 0xff2f
/* 050F8C 7F01C45C 3C0DBA00 */  lui   $t5, (0xBA000602 >> 16) # lui $t5, 0xba00
/* 050F90 7F01C460 3C0F9600 */  lui   $t7, (0x960000B4 >> 16) # lui $t7, 0x9600
/* 050F94 7F01C464 3C18BA00 */  lui   $t8, (0xBA001301 >> 16) # lui $t8, 0xba00
/* 050F98 7F01C468 35088000 */  ori   $t0, (0x80008000 & 0xFFFF) # ori $t0, $t0, 0x8000
/* 050F9C 7F01C46C 354A4340 */  ori   $t2, (0x00504340 & 0xFFFF) # ori $t2, $t2, 0x4340
/* 050FA0 7F01C470 3529031D */  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d
/* 050FA4 7F01C474 358CFFFF */  ori   $t4, (0xFF2FFFFF & 0xFFFF) # ori $t4, $t4, 0xffff
/* 050FA8 7F01C478 356B9623 */  ori   $t3, (0xFC119623 & 0xFFFF) # ori $t3, $t3, 0x9623 #setcombine()
/* 050FAC 7F01C47C 35AD0602 */  ori   $t5, (0xBA000602 & 0xFFFF) # ori $t5, $t5, 0x602
/* 050FB0 7F01C480 35EF00B4 */  ori   $t7, (0x960000B4 & 0xFFFF) # ori $t7, $t7, 0xb4
/* 050FB4 7F01C484 3C0EFA00 */  lui   $t6, 0xfa00
/* 050FB8 7F01C488 37181301 */  ori   $t8, (0xBA001301 & 0xFFFF) # ori $t8, $t8, 0x1301
/* 050FBC 7F01C48C 3C19FD90 */  lui   $t9, 0xfd90
/* 050FC0 7F01C490 AC480004 */  sw    $t0, 4($v0)
/* 050FC4 7F01C494 AC490008 */  sw    $t1, 8($v0)
/* 050FC8 7F01C498 AC4A000C */  sw    $t2, 0xc($v0)
/* 050FCC 7F01C49C AC4B0010 */  sw    $t3, 0x10($v0)
/* 050FD0 7F01C4A0 AC4C0014 */  sw    $t4, 0x14($v0)
/* 050FD4 7F01C4A4 AC4D0018 */  sw    $t5, 0x18($v0)
/* 050FD8 7F01C4A8 AC40001C */  sw    $zero, 0x1c($v0)
/* 050FDC 7F01C4AC AC4E0020 */  sw    $t6, 0x20($v0)
/* 050FE0 7F01C4B0 AC4F0024 */  sw    $t7, 0x24($v0)
/* 050FE4 7F01C4B4 AC580028 */  sw    $t8, 0x28($v0)
/* 050FE8 7F01C4B8 AC40002C */  sw    $zero, 0x2c($v0)
/* 050FEC 7F01C4BC AC590030 */  sw    $t9, 0x30($v0)
/* 050FF0 7F01C4C0 3C038008 */  lui   $v1, %hi(pPlayer)
/* 050FF4 7F01C4C4 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 050FF8 7F01C4C8 3C018000 */  lui   $at, 0x8000
/* 050FFC 7F01C4CC 3C190777 */  lui   $t9, (0x0777F156 >> 16) # lui $t9, 0x777
/* 051000 7F01C4D0 8C6811B8 */  lw    $t0, 0x11b8($v1)
/* 051004 7F01C4D4 3C0E0708 */  lui   $t6, (0x07080200 >> 16) # lui $t6, 0x708
/* 051008 7F01C4D8 3C0DF590 */  lui   $t5, 0xf590
/* 05100C 7F01C4DC 00084880 */  sll   $t1, $t0, 2
/* 051010 7F01C4E0 00695021 */  addu  $t2, $v1, $t1
/* 051014 7F01C4E4 8D4B11B0 */  lw    $t3, 0x11b0($t2)
/* 051018 7F01C4E8 3C0A0008 */  lui   $t2, (0x00080200 >> 16) # lui $t2, 8
/* 05101C 7F01C4EC 3C09F580 */  lui   $t1, (0xF5800C00 >> 16) # lui $t1, 0xf580
/* 051020 7F01C4F0 01616021 */  addu  $t4, $t3, $at
/* 051024 7F01C4F4 AC4C0034 */  sw    $t4, 0x34($v0)
/* 051028 7F01C4F8 3C0C0017 */  lui   $t4, (0x0017C13C >> 16) # lui $t4, 0x17
/* 05102C 7F01C4FC 358CC13C */  ori   $t4, (0x0017C13C & 0xFFFF) # ori $t4, $t4, 0xc13c
/* 051030 7F01C500 3C0BF200 */  lui   $t3, 0xf200
/* 051034 7F01C504 35290C00 */  ori   $t1, (0xF5800C00 & 0xFFFF) # ori $t1, $t1, 0xc00
/* 051038 7F01C508 354A0200 */  ori   $t2, (0x00080200 & 0xFFFF) # ori $t2, $t2, 0x200
/* 05103C 7F01C50C AC4D0038 */  sw    $t5, 0x38($v0)
/* 051040 7F01C510 3C08E700 */  lui   $t0, 0xe700
/* 051044 7F01C514 35CE0200 */  ori   $t6, (0x07080200 & 0xFFFF) # ori $t6, $t6, 0x200
/* 051048 7F01C518 3739F156 */  ori   $t9, (0x0777F156 & 0xFFFF) # ori $t9, $t9, 0xf156
/* 05104C 7F01C51C 3C18F300 */  lui   $t8, 0xf300
/* 051050 7F01C520 3C0FE600 */  lui   $t7, 0xe600
/* 051054 7F01C524 AC4F0040 */  sw    $t7, 0x40($v0)
/* 051058 7F01C528 AC580048 */  sw    $t8, 0x48($v0)
/* 05105C 7F01C52C AC59004C */  sw    $t9, 0x4c($v0)
/* 051060 7F01C530 AC4E003C */  sw    $t6, 0x3c($v0)
/* 051064 7F01C534 AC480050 */  sw    $t0, 0x50($v0)
/* 051068 7F01C538 AC4A005C */  sw    $t2, 0x5c($v0)
/* 05106C 7F01C53C AC490058 */  sw    $t1, 0x58($v0)
/* 051070 7F01C540 AC4B0060 */  sw    $t3, 0x60($v0)
/* 051074 7F01C544 AC4C0064 */  sw    $t4, 0x64($v0)
/* 051078 7F01C548 AC400054 */  sw    $zero, 0x54($v0)
/* 05107C 7F01C54C AC400044 */  sw    $zero, 0x44($v0)
/* 051080 7F01C550 244D0068 */  addiu $t5, $v0, 0x68
/* 051084 7F01C554 AFAD0030 */  sw    $t5, 0x30($sp)
/* 051088 7F01C558 0C001107 */  jal   get_video2_settings_txtClipW
/* 05108C 7F01C55C 24500070 */   addiu $s0, $v0, 0x70
/* 051090 7F01C560 0C00110B */  jal   get_video2_settings_txtClipH
/* 051094 7F01C564 A7A20026 */   sh    $v0, 0x26($sp)
/* 051098 7F01C568 87A80026 */  lh    $t0, 0x26($sp)
/* 05109C 7F01C56C 00027080 */  sll   $t6, $v0, 2
/* 0510A0 7F01C570 8FA50030 */  lw    $a1, 0x30($sp)
/* 0510A4 7F01C574 00084880 */  sll   $t1, $t0, 2
/* 0510A8 7F01C578 252AFFFF */  addiu $t2, $t1, -1
/* 0510AC 7F01C57C 25CFFFFF */  addiu $t7, $t6, -1
/* 0510B0 7F01C580 31F80FFF */  andi  $t8, $t7, 0xfff
/* 0510B4 7F01C584 314B0FFF */  andi  $t3, $t2, 0xfff
/* 0510B8 7F01C588 3C01E400 */  lui   $at, 0xe400
/* 0510BC 7F01C58C 0301C825 */  or    $t9, $t8, $at
/* 0510C0 7F01C590 000B6300 */  sll   $t4, $t3, 0xc
/* 0510C4 7F01C594 032C6825 */  or    $t5, $t9, $t4
/* 0510C8 7F01C598 02001825 */  move  $v1, $s0
/* 0510CC 7F01C59C ACAD0000 */  sw    $t5, ($a1)
/* 0510D0 7F01C5A0 ACA00004 */  sw    $zero, 4($a1)
/* 0510D4 7F01C5A4 26100008 */  addiu $s0, $s0, 8
/* 0510D8 7F01C5A8 3C0EB400 */  lui   $t6, 0xb400
/* 0510DC 7F01C5AC AC6E0000 */  sw    $t6, ($v1)
/* 0510E0 7F01C5B0 02002025 */  move  $a0, $s0
/* 0510E4 7F01C5B4 AC600004 */  sw    $zero, 4($v1)
/* 0510E8 7F01C5B8 3C0FB300 */  lui   $t7, 0xb300
/* 0510EC 7F01C5BC AC8F0000 */  sw    $t7, ($a0)
/* 0510F0 7F01C5C0 AFA40028 */  sw    $a0, 0x28($sp)
/* 0510F4 7F01C5C4 0C001107 */  jal   get_video2_settings_txtClipW
/* 0510F8 7F01C5C8 26100008 */   addiu $s0, $s0, 8
/* 0510FC 7F01C5CC 0C00110B */  jal   get_video2_settings_txtClipH
/* 051100 7F01C5D0 A7A20026 */   sh    $v0, 0x26($sp)
/* 051104 7F01C5D4 3C180001 */  lui   $t8, (0x00014000 >> 16) # lui $t8, 1
/* 051108 7F01C5D8 37184000 */  ori   $t8, (0x00014000 & 0xFFFF) # ori $t8, $t8, 0x4000
/* 05110C 7F01C5DC 0302001A */  div   $zero, $t8, $v0
/* 051110 7F01C5E0 00004012 */  mflo  $t0
/* 051114 7F01C5E4 87AA0026 */  lh    $t2, 0x26($sp)
/* 051118 7F01C5E8 3C0B0001 */  lui   $t3, (0x00018000 >> 16) # lui $t3, 1
/* 05111C 7F01C5EC 356B8000 */  ori   $t3, (0x00018000 & 0xFFFF) # ori $t3, $t3, 0x8000
/* 051120 7F01C5F0 016A001A */  div   $zero, $t3, $t2
/* 051124 7F01C5F4 14400002 */  bnez  $v0, .L7F01C600
/* 051128 7F01C5F8 00000000 */   nop   
/* 05112C 7F01C5FC 0007000D */  break 7
.L7F01C600:
/* 051130 7F01C600 2401FFFF */  li    $at, -1
/* 051134 7F01C604 14410004 */  bne   $v0, $at, .L7F01C618
/* 051138 7F01C608 3C018000 */   lui   $at, 0x8000
/* 05113C 7F01C60C 17010002 */  bne   $t8, $at, .L7F01C618
/* 051140 7F01C610 00000000 */   nop   
/* 051144 7F01C614 0006000D */  break 6
.L7F01C618:
/* 051148 7F01C618 0000C812 */  mflo  $t9
/* 05114C 7F01C61C 8FAF0028 */  lw    $t7, 0x28($sp)
/* 051150 7F01C620 332CFFFF */  andi  $t4, $t9, 0xffff
/* 051154 7F01C624 000C6C00 */  sll   $t5, $t4, 0x10
/* 051158 7F01C628 3109FFFF */  andi  $t1, $t0, 0xffff
/* 05115C 7F01C62C 012D7025 */  or    $t6, $t1, $t5
/* 051160 7F01C630 ADEE0004 */  sw    $t6, 4($t7)
/* 051164 7F01C634 8FBF001C */  lw    $ra, 0x1c($sp)
/* 051168 7F01C638 02001025 */  move  $v0, $s0
/* 05116C 7F01C63C 8FB00018 */  lw    $s0, 0x18($sp)
/* 051170 7F01C640 15400002 */  bnez  $t2, .L7F01C64C
/* 051174 7F01C644 00000000 */   nop   
/* 051178 7F01C648 0007000D */  break 7
.L7F01C64C:
/* 05117C 7F01C64C 2401FFFF */  li    $at, -1
/* 051180 7F01C650 15410004 */  bne   $t2, $at, .L7F01C664
/* 051184 7F01C654 3C018000 */   lui   $at, 0x8000
/* 051188 7F01C658 15610002 */  bne   $t3, $at, .L7F01C664
/* 05118C 7F01C65C 00000000 */   nop   
/* 051190 7F01C660 0006000D */  break 6
.L7F01C664:
/* 051194 7F01C664 27BD0070 */  addiu $sp, $sp, 0x70
/* 051198 7F01C668 03E00008 */  jr    $ra
/* 05119C 7F01C66C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01C670(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01C670
/* 0511A0 7F01C670 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0511A4 7F01C674 AFB00014 */  sw    $s0, 0x14($sp)
/* 0511A8 7F01C678 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0511AC 7F01C67C AFB10018 */  sw    $s1, 0x18($sp)
/* 0511B0 7F01C680 24900008 */  addiu $s0, $a0, 8
/* 0511B4 7F01C684 3C0EBA00 */  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H()
/* 0511B8 7F01C688 35CE0E02 */  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
/* 0511BC 7F01C68C 02001825 */  move  $v1, $s0
/* 0511C0 7F01C690 3C0FBA00 */  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
/* 0511C4 7F01C694 AC8E0000 */  sw    $t6, ($a0)
/* 0511C8 7F01C698 AC800004 */  sw    $zero, 4($a0)
/* 0511CC 7F01C69C 35EF0C02 */  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02 #G_SETOTHERMODE_H()
/* 0511D0 7F01C6A0 26100008 */  addiu $s0, $s0, 8
/* 0511D4 7F01C6A4 AC6F0000 */  sw    $t7, ($v1)
/* 0511D8 7F01C6A8 24182000 */  li    $t8, 8192
/* 0511DC 7F01C6AC 02002825 */  move  $a1, $s0
/* 0511E0 7F01C6B0 AC780004 */  sw    $t8, 4($v1)
/* 0511E4 7F01C6B4 26100008 */  addiu $s0, $s0, 8
/* 0511E8 7F01C6B8 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00  #gDPSetCycleType(2Cycle)
/* 0511EC 7F01C6BC 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0511F0 7F01C6C0 02003025 */  move  $a2, $s0
/* 0511F4 7F01C6C4 ACB90000 */  sw    $t9, ($a1)
/* 0511F8 7F01C6C8 ACA00004 */  sw    $zero, 4($a1)
/* 0511FC 7F01C6CC 26100008 */  addiu $s0, $s0, 8
/* 051200 7F01C6D0 3C08B700 */  lui   $t0, 0xb700
/* 051204 7F01C6D4 24090204 */  li    $t1, 516
/* 051208 7F01C6D8 ACC90004 */  sw    $t1, 4($a2)
/* 05120C 7F01C6DC ACC80000 */  sw    $t0, ($a2)
/* 051210 7F01C6E0 02003825 */  move  $a3, $s0
/* 051214 7F01C6E4 26100008 */  addiu $s0, $s0, 8
/* 051218 7F01C6E8 3C0ABB00 */  lui   $t2, (0xBB000001 >> 16) # lui $t2, 0xbb00 
/* 05121C 7F01C6EC 3C0B8000 */  lui   $t3, (0x80008000 >> 16) # lui $t3, 0x8000
/* 051220 7F01C6F0 356B8000 */  ori   $t3, (0x80008000 & 0xFFFF) # ori $t3, $t3, 0x8000
/* 051224 7F01C6F4 354A0001 */  ori   $t2, (0xBB000001 & 0xFFFF) # ori $t2, $t2, 1
/* 051228 7F01C6F8 02001025 */  move  $v0, $s0
/* 05122C 7F01C6FC ACEA0000 */  sw    $t2, ($a3)
/* 051230 7F01C700 ACEB0004 */  sw    $t3, 4($a3)
/* 051234 7F01C704 26100008 */  addiu $s0, $s0, 8
/* 051238 7F01C708 3C0CB900 */  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900 #gDPSetRenderMode()
/* 05123C 7F01C70C 3C0D0050 */  lui   $t5, (0x00504340 >> 16) # lui $t5, 0x50
/* 051240 7F01C710 35AD4340 */  ori   $t5, (0x00504340 & 0xFFFF) # ori $t5, $t5, 0x4340
/* 051244 7F01C714 358C031D */  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
/* 051248 7F01C718 02001825 */  move  $v1, $s0
/* 05124C 7F01C71C AC4C0000 */  sw    $t4, ($v0)
/* 051250 7F01C720 AC4D0004 */  sw    $t5, 4($v0)
/* 051254 7F01C724 3C0FFF2F */  lui   $t7, (0xFF2FFFFF >> 16) # lui $t7, 0xff2f
/* 051258 7F01C728 3C0EFC11 */  lui   $t6, (0xFC119623 >> 16) # lui $t6, 0xfc11 #Setcombine()
/* 05125C 7F01C72C 35CE9623 */  ori   $t6, (0xFC119623 & 0xFFFF) # ori $t6, $t6, 0x9623
/* 051260 7F01C730 35EFFFFF */  ori   $t7, (0xFF2FFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
/* 051264 7F01C734 26100008 */  addiu $s0, $s0, 8
/* 051268 7F01C738 AC6F0004 */  sw    $t7, 4($v1)
/* 05126C 7F01C73C AC6E0000 */  sw    $t6, ($v1)
/* 051270 7F01C740 02002025 */  move  $a0, $s0
/* 051274 7F01C744 26100008 */  addiu $s0, $s0, 8
/* 051278 7F01C748 3C18BA00 */  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00  #G_SETOTHERMODE_H(envmapping)
/* 05127C 7F01C74C 37180602 */  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
/* 051280 7F01C750 02002825 */  move  $a1, $s0
/* 051284 7F01C754 AC980000 */  sw    $t8, ($a0)
/* 051288 7F01C758 AC800004 */  sw    $zero, 4($a0)
/* 05128C 7F01C75C 26100008 */  addiu $s0, $s0, 8
/* 051290 7F01C760 3C089600 */  lui   $t0, (0x960000B4 >> 16) # lui $t0, 0x9600
/* 051294 7F01C764 350800B4 */  ori   $t0, (0x960000B4 & 0xFFFF) # ori $t0, $t0, 0xb4
/* 051298 7F01C768 3C19FA00 */  lui   $t9, 0xfa00
/* 05129C 7F01C76C 02003025 */  move  $a2, $s0
/* 0512A0 7F01C770 ACB90000 */  sw    $t9, ($a1)
/* 0512A4 7F01C774 ACA80004 */  sw    $t0, 4($a1)
/* 0512A8 7F01C778 3C09BA00 */  lui   $t1, (0xBA001301 >> 16) # lui $t1, 0xba00  #G_SETOTHERMODE_H()
/* 0512AC 7F01C77C 35291301 */  ori   $t1, (0xBA001301 & 0xFFFF) # ori $t1, $t1, 0x1301
/* 0512B0 7F01C780 26100008 */  addiu $s0, $s0, 8
/* 0512B4 7F01C784 ACC90000 */  sw    $t1, ($a2)
/* 0512B8 7F01C788 ACC00004 */  sw    $zero, 4($a2)
/* 0512BC 7F01C78C 02001025 */  move  $v0, $s0
/* 0512C0 7F01C790 3C0AFD90 */  lui   $t2, 0xfd90
/* 0512C4 7F01C794 AC4A0000 */  sw    $t2, ($v0)
/* 0512C8 7F01C798 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0512CC 7F01C79C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0512D0 7F01C7A0 3C018000 */  lui   $at, 0x8000
/* 0512D4 7F01C7A4 26100008 */  addiu $s0, $s0, 8
/* 0512D8 7F01C7A8 8C6B11B8 */  lw    $t3, 0x11b8($v1)
/* 0512DC 7F01C7AC 02002025 */  move  $a0, $s0
/* 0512E0 7F01C7B0 26100008 */  addiu $s0, $s0, 8
/* 0512E4 7F01C7B4 000B6080 */  sll   $t4, $t3, 2
/* 0512E8 7F01C7B8 006C6821 */  addu  $t5, $v1, $t4
/* 0512EC 7F01C7BC 8DAE11B0 */  lw    $t6, 0x11b0($t5)
/* 0512F0 7F01C7C0 3C190708 */  lui   $t9, (0x07080200 >> 16) # lui $t9, 0x708
/* 0512F4 7F01C7C4 37390200 */  ori   $t9, (0x07080200 & 0xFFFF) # ori $t9, $t9, 0x200
/* 0512F8 7F01C7C8 01C17821 */  addu  $t7, $t6, $at
/* 0512FC 7F01C7CC AC4F0004 */  sw    $t7, 4($v0)
/* 051300 7F01C7D0 02002825 */  move  $a1, $s0
/* 051304 7F01C7D4 3C18F590 */  lui   $t8, 0xf590
/* 051308 7F01C7D8 AC980000 */  sw    $t8, ($a0)
/* 05130C 7F01C7DC 26100008 */  addiu $s0, $s0, 8
/* 051310 7F01C7E0 AC990004 */  sw    $t9, 4($a0)
/* 051314 7F01C7E4 02003025 */  move  $a2, $s0
/* 051318 7F01C7E8 3C08E600 */  lui   $t0, 0xe600
/* 05131C 7F01C7EC ACA80000 */  sw    $t0, ($a1)
/* 051320 7F01C7F0 26100008 */  addiu $s0, $s0, 8
/* 051324 7F01C7F4 ACA00004 */  sw    $zero, 4($a1)
/* 051328 7F01C7F8 3C0A0777 */  lui   $t2, (0x0777F156 >> 16) # lui $t2, 0x777
/* 05132C 7F01C7FC 354AF156 */  ori   $t2, (0x0777F156 & 0xFFFF) # ori $t2, $t2, 0xf156
/* 051330 7F01C800 02003825 */  move  $a3, $s0
/* 051334 7F01C804 3C09F300 */  lui   $t1, 0xf300
/* 051338 7F01C808 ACC90000 */  sw    $t1, ($a2)
/* 05133C 7F01C80C 26100008 */  addiu $s0, $s0, 8
/* 051340 7F01C810 ACCA0004 */  sw    $t2, 4($a2)
/* 051344 7F01C814 02001025 */  move  $v0, $s0
/* 051348 7F01C818 3C0BE700 */  lui   $t3, 0xe700
/* 05134C 7F01C81C ACEB0000 */  sw    $t3, ($a3)
/* 051350 7F01C820 26100008 */  addiu $s0, $s0, 8
/* 051354 7F01C824 ACE00004 */  sw    $zero, 4($a3)
/* 051358 7F01C828 3C0D0008 */  lui   $t5, (0x00080200 >> 16) # lui $t5, 8
/* 05135C 7F01C82C 3C0CF580 */  lui   $t4, (0xF5800C00 >> 16) # lui $t4, 0xf580 #settilesize()
/* 051360 7F01C830 358C0C00 */  ori   $t4, (0xF5800C00 & 0xFFFF) # ori $t4, $t4, 0xc00
/* 051364 7F01C834 35AD0200 */  ori   $t5, (0x00080200 & 0xFFFF) # ori $t5, $t5, 0x200
/* 051368 7F01C838 02001825 */  move  $v1, $s0
/* 05136C 7F01C83C AC4D0004 */  sw    $t5, 4($v0)
/* 051370 7F01C840 AC4C0000 */  sw    $t4, ($v0)
/* 051374 7F01C844 3C0F0017 */  lui   $t7, (0x0017C13C >> 16) # lui $t7, 0x17
/* 051378 7F01C848 35EFC13C */  ori   $t7, (0x0017C13C & 0xFFFF) # ori $t7, $t7, 0xc13c
/* 05137C 7F01C84C 3C0EF200 */  lui   $t6, 0xf200
/* 051380 7F01C850 AC6E0000 */  sw    $t6, ($v1)
/* 051384 7F01C854 AC6F0004 */  sw    $t7, 4($v1)
/* 051388 7F01C858 26100008 */  addiu $s0, $s0, 8
/* 05138C 7F01C85C AFB00040 */  sw    $s0, 0x40($sp)
/* 051390 7F01C860 0C001127 */  jal   get_video2_settings_width
/* 051394 7F01C864 26100008 */   addiu $s0, $s0, 8
/* 051398 7F01C868 0C001145 */  jal   get_video2_settings_ulx
/* 05139C 7F01C86C A7A20026 */   sh    $v0, 0x26($sp)
/* 0513A0 7F01C870 0C001149 */  jal   get_video2_settings_uly
/* 0513A4 7F01C874 A7A20028 */   sh    $v0, 0x28($sp)
/* 0513A8 7F01C878 00028C00 */  sll   $s1, $v0, 0x10
/* 0513AC 7F01C87C 0011C403 */  sra   $t8, $s1, 0x10
/* 0513B0 7F01C880 0C00112B */  jal   get_video2_settings_height
/* 0513B4 7F01C884 03008825 */   move  $s1, $t8
/* 0513B8 7F01C888 87B90028 */  lh    $t9, 0x28($sp)
/* 0513BC 7F01C88C 87A80026 */  lh    $t0, 0x26($sp)
/* 0513C0 7F01C890 00517021 */  addu  $t6, $v0, $s1
/* 0513C4 7F01C894 000E7880 */  sll   $t7, $t6, 2
/* 0513C8 7F01C898 03284821 */  addu  $t1, $t9, $t0
/* 0513CC 7F01C89C 00095080 */  sll   $t2, $t1, 2
/* 0513D0 7F01C8A0 254BFFFF */  addiu $t3, $t2, -1
/* 0513D4 7F01C8A4 25F8FFFF */  addiu $t8, $t7, -1
/* 0513D8 7F01C8A8 33190FFF */  andi  $t9, $t8, 0xfff
/* 0513DC 7F01C8AC 316C0FFF */  andi  $t4, $t3, 0xfff
/* 0513E0 7F01C8B0 3C01E400 */  lui   $at, 0xe400
/* 0513E4 7F01C8B4 8FAA0040 */  lw    $t2, 0x40($sp)
/* 0513E8 7F01C8B8 03214025 */  or    $t0, $t9, $at
/* 0513EC 7F01C8BC 000C6B00 */  sll   $t5, $t4, 0xc
/* 0513F0 7F01C8C0 010D4825 */  or    $t1, $t0, $t5
/* 0513F4 7F01C8C4 0C001145 */  jal   get_video2_settings_ulx
/* 0513F8 7F01C8C8 AD490000 */   sw    $t1, ($t2)
/* 0513FC 7F01C8CC 00028C00 */  sll   $s1, $v0, 0x10
/* 051400 7F01C8D0 00115C03 */  sra   $t3, $s1, 0x10
/* 051404 7F01C8D4 0C001149 */  jal   get_video2_settings_uly
/* 051408 7F01C8D8 01608825 */   move  $s1, $t3
/* 05140C 7F01C8DC 00117880 */  sll   $t7, $s1, 2
/* 051410 7F01C8E0 8FAD0040 */  lw    $t5, 0x40($sp)
/* 051414 7F01C8E4 31F80FFF */  andi  $t8, $t7, 0xfff
/* 051418 7F01C8E8 00026080 */  sll   $t4, $v0, 2
/* 05141C 7F01C8EC 318E0FFF */  andi  $t6, $t4, 0xfff
/* 051420 7F01C8F0 0018CB00 */  sll   $t9, $t8, 0xc
/* 051424 7F01C8F4 01D94025 */  or    $t0, $t6, $t9
/* 051428 7F01C8F8 02001825 */  move  $v1, $s0
/* 05142C 7F01C8FC ADA80004 */  sw    $t0, 4($t5)
/* 051430 7F01C900 26100008 */  addiu $s0, $s0, 8
/* 051434 7F01C904 3C09B400 */  lui   $t1, 0xb400
/* 051438 7F01C908 AC690000 */  sw    $t1, ($v1)
/* 05143C 7F01C90C 02002025 */  move  $a0, $s0
/* 051440 7F01C910 AC600004 */  sw    $zero, 4($v1)
/* 051444 7F01C914 3C0AB300 */  lui   $t2, 0xb300
/* 051448 7F01C918 AC8A0000 */  sw    $t2, ($a0)
/* 05144C 7F01C91C AFA40038 */  sw    $a0, 0x38($sp)
/* 051450 7F01C920 0C001127 */  jal   get_video2_settings_width
/* 051454 7F01C924 26100008 */   addiu $s0, $s0, 8
/* 051458 7F01C928 00028C00 */  sll   $s1, $v0, 0x10
/* 05145C 7F01C92C 00115C03 */  sra   $t3, $s1, 0x10
/* 051460 7F01C930 0C00112B */  jal   get_video2_settings_height
/* 051464 7F01C934 01608825 */   move  $s1, $t3
/* 051468 7F01C938 3C0C0001 */  lui   $t4, (0x00014000 >> 16) # lui $t4, 1
/* 05146C 7F01C93C 358C4000 */  ori   $t4, (0x00014000 & 0xFFFF) # ori $t4, $t4, 0x4000
/* 051470 7F01C940 0182001A */  div   $zero, $t4, $v0
/* 051474 7F01C944 00007812 */  mflo  $t7
/* 051478 7F01C948 3C0E0001 */  lui   $t6, (0x00018000 >> 16) # lui $t6, 1
/* 05147C 7F01C94C 35CE8000 */  ori   $t6, (0x00018000 & 0xFFFF) # ori $t6, $t6, 0x8000
/* 051480 7F01C950 01D1001A */  div   $zero, $t6, $s1
/* 051484 7F01C954 14400002 */  bnez  $v0, .L7F01C960
/* 051488 7F01C958 00000000 */   nop   
/* 05148C 7F01C95C 0007000D */  break 7
.L7F01C960:
/* 051490 7F01C960 2401FFFF */  li    $at, -1
/* 051494 7F01C964 14410004 */  bne   $v0, $at, .L7F01C978
/* 051498 7F01C968 3C018000 */   lui   $at, 0x8000
/* 05149C 7F01C96C 15810002 */  bne   $t4, $at, .L7F01C978
/* 0514A0 7F01C970 00000000 */   nop   
/* 0514A4 7F01C974 0006000D */  break 6
.L7F01C978:
/* 0514A8 7F01C978 0000C812 */  mflo  $t9
/* 0514AC 7F01C97C 8FAA0038 */  lw    $t2, 0x38($sp)
/* 0514B0 7F01C980 3328FFFF */  andi  $t0, $t9, 0xffff
/* 0514B4 7F01C984 00086C00 */  sll   $t5, $t0, 0x10
/* 0514B8 7F01C988 31F8FFFF */  andi  $t8, $t7, 0xffff
/* 0514BC 7F01C98C 030D4825 */  or    $t1, $t8, $t5
/* 0514C0 7F01C990 02001825 */  move  $v1, $s0
/* 0514C4 7F01C994 26100008 */  addiu $s0, $s0, 8
/* 0514C8 7F01C998 AD490004 */  sw    $t1, 4($t2)
/* 0514CC 7F01C99C 3C0BE700 */  lui   $t3, 0xe700
/* 0514D0 7F01C9A0 02002025 */  move  $a0, $s0
/* 0514D4 7F01C9A4 AC6B0000 */  sw    $t3, ($v1)
/* 0514D8 7F01C9A8 AC600004 */  sw    $zero, 4($v1)
/* 0514DC 7F01C9AC 3C0CBA00 */  lui   $t4, (0xBA000602 >> 16) # lui $t4, 0xba00  #G_SETOTHERMODE_H()
/* 0514E0 7F01C9B0 16200002 */  bnez  $s1, .L7F01C9BC
/* 0514E4 7F01C9B4 00000000 */   nop   
/* 0514E8 7F01C9B8 0007000D */  break 7
.L7F01C9BC:
/* 0514EC 7F01C9BC 2401FFFF */  li    $at, -1
/* 0514F0 7F01C9C0 16210004 */  bne   $s1, $at, .L7F01C9D4
/* 0514F4 7F01C9C4 3C018000 */   lui   $at, 0x8000
/* 0514F8 7F01C9C8 15C10002 */  bne   $t6, $at, .L7F01C9D4
/* 0514FC 7F01C9CC 00000000 */   nop   
/* 051500 7F01C9D0 0006000D */  break 6
.L7F01C9D4:
/* 051504 7F01C9D4 358C0602 */  ori   $t4, (0xBA000602 & 0xFFFF) # ori $t4, $t4, 0x602 #G_SETOTHERMODE_H()
/* 051508 7F01C9D8 26100008 */  addiu $s0, $s0, 8
/* 05150C 7F01C9DC 240F0040 */  li    $t7, 64
/* 051510 7F01C9E0 AC8F0004 */  sw    $t7, 4($a0)
/* 051514 7F01C9E4 AC8C0000 */  sw    $t4, ($a0)
/* 051518 7F01C9E8 02002825 */  move  $a1, $s0
/* 05151C 7F01C9EC 3C0EBA00 */  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H()
/* 051520 7F01C9F0 35CE1301 */  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
/* 051524 7F01C9F4 3C190008 */  lui   $t9, 8
/* 051528 7F01C9F8 ACB90004 */  sw    $t9, 4($a1)
/* 05152C 7F01C9FC ACAE0000 */  sw    $t6, ($a1)
/* 051530 7F01CA00 8FBF001C */  lw    $ra, 0x1c($sp)
/* 051534 7F01CA04 26020008 */  addiu $v0, $s0, 8
/* 051538 7F01CA08 8FB00014 */  lw    $s0, 0x14($sp)
/* 05153C 7F01CA0C 8FB10018 */  lw    $s1, 0x18($sp)
/* 051540 7F01CA10 03E00008 */  jr    $ra
/* 051544 7F01CA14 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01CA18(Gfx *glistp) //BloodRed_Dl_Setup
{
	sub_GAME_7F01C1A4();
	//1 cycle settings
	gDPSetRenderMode(glistp++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
	gDPSetCombineMode(glistp++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(glistp++, 0, 0, 150, 00, 00, 180); //dark red
	gDPSetColorDither(glistp++, G_CD_MAGICSQ);
	
	get_video2_settings_txtClipW();
	//...
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01CA18
/* 051548 7F01CA18 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 05154C 7F01CA1C AFBF0014 */  sw    $ra, 0x14($sp)
/* 051550 7F01CA20 0FC07069 */  jal   sub_GAME_7F01C1A4
/* 051554 7F01CA24 00000000 */   nop   
/* 051558 7F01CA28 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 05155C 7F01CA2C 3C0F0050 */  lui   $t7, (0x00504340 >> 16) # lui $t7, 0x50
/* 051560 7F01CA30 3C18FCFF */  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
/* 051564 7F01CA34 3C19FFFD */  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
/* 051568 7F01CA38 3C099600 */  lui   $t1, (0x960000B4 >> 16) # lui $t1, 0x9600
/* 05156C 7F01CA3C 3C0ABA00 */  lui   $t2, (0xBA000602 >> 16) # lui $t2, 0xba00
/* 051570 7F01CA40 35EF4340 */  ori   $t7, (0x00504340 & 0xFFFF) # ori $t7, $t7, 0x4340
/* 051574 7F01CA44 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 051578 7F01CA48 3739F6FB */  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
/* 05157C 7F01CA4C 3718FFFF */  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
/* 051580 7F01CA50 352900B4 */  ori   $t1, (0x960000B4 & 0xFFFF) # ori $t1, $t1, 0xb4
/* 051584 7F01CA54 3C08FA00 */  lui   $t0, 0xfa00
/* 051588 7F01CA58 354A0602 */  ori   $t2, (0xBA000602 & 0xFFFF) # ori $t2, $t2, 0x602
/* 05158C 7F01CA5C AC4E0000 */  sw    $t6, ($v0)		#$v0 = gfx glist
/* 051590 7F01CA60 AC4F0004 */  sw    $t7, 4($v0)
/* 051594 7F01CA64 AC580008 */  sw    $t8, 8($v0)
/* 051598 7F01CA68 AC59000C */  sw    $t9, 0xc($v0)
/* 05159C 7F01CA6C AC480010 */  sw    $t0, 0x10($v0)
/* 0515A0 7F01CA70 AC490014 */  sw    $t1, 0x14($v0)
/* 0515A4 7F01CA74 AC4A0018 */  sw    $t2, 0x18($v0)
/* 0515A8 7F01CA78 AC40001C */  sw    $zero, 0x1c($v0)
/* 0515AC 7F01CA7C 244B0020 */  addiu $t3, $v0, 0x20
/* 0515B0 7F01CA80 244C0028 */  addiu $t4, $v0, 0x28
/* 0515B4 7F01CA84 AFAC0030 */  sw    $t4, 0x30($sp)
/* 0515B8 7F01CA88 0C001107 */  jal   get_video2_settings_txtClipW
/* 0515BC 7F01CA8C AFAB001C */   sw    $t3, 0x1c($sp)
/* 0515C0 7F01CA90 0C00110B */  jal   get_video2_settings_txtClipH
/* 0515C4 7F01CA94 A7A2001A */   sh    $v0, 0x1a($sp)
/* 0515C8 7F01CA98 87B8001A */  lh    $t8, 0x1a($sp)
/* 0515CC 7F01CA9C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0515D0 7F01CAA0 304D03FF */  andi  $t5, $v0, 0x3ff
/* 0515D4 7F01CAA4 000D7080 */  sll   $t6, $t5, 2
/* 0515D8 7F01CAA8 3C01F600 */  lui   $at, 0xf600
/* 0515DC 7F01CAAC 331903FF */  andi  $t9, $t8, 0x3ff
/* 0515E0 7F01CAB0 00194380 */  sll   $t0, $t9, 0xe
/* 0515E4 7F01CAB4 01C17825 */  or    $t7, $t6, $at
/* 0515E8 7F01CAB8 01E84825 */  or    $t1, $t7, $t0
/* 0515EC 7F01CABC AC690000 */  sw    $t1, ($v1)
/* 0515F0 7F01CAC0 AC600004 */  sw    $zero, 4($v1)
/* 0515F4 7F01CAC4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0515F8 7F01CAC8 8FA20030 */  lw    $v0, 0x30($sp)
/* 0515FC 7F01CACC 27BD0030 */  addiu $sp, $sp, 0x30
/* 051600 7F01CAD0 03E00008 */  jr    $ra
/* 051604 7F01CAD4 00000000 */   nop   
)
#endif








