/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#include "lvgl.h"

#ifndef SIYUAN12
#define SIYUAN12 1
#endif

#if SIYUAN12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa3, 0xc0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x24, 0xa7, 0xca, 0x2b, 0xf4, 0x92, 0x48,

    /* U+0024 "$" */
    0x23, 0xa3, 0xc, 0x30, 0xe1, 0xc, 0x7c, 0x40,

    /* U+0025 "%" */
    0x62, 0x24, 0x89, 0x42, 0x56, 0x6a, 0x42, 0x91,
    0x24, 0x49, 0x21, 0x80,

    /* U+0026 "&" */
    0x38, 0x48, 0x48, 0x50, 0x62, 0xf2, 0x9e, 0x8e,
    0x7b,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x4b, 0x49, 0x24, 0x91, 0x20,

    /* U+0029 ")" */
    0x49, 0x12, 0x49, 0x25, 0x20,

    /* U+002A "*" */
    0x4d, 0x66,

    /* U+002B "+" */
    0x20, 0x8f, 0xc8, 0x20, 0x80,

    /* U+002C "," */
    0xf6, 0x0,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x11, 0x12, 0x22, 0x24, 0x44, 0x48,

    /* U+0030 "0" */
    0x79, 0x28, 0x61, 0x86, 0x18, 0x52, 0x78,

    /* U+0031 "1" */
    0x67, 0x8, 0x42, 0x10, 0x84, 0xf8,

    /* U+0032 "2" */
    0x72, 0x20, 0x82, 0x18, 0x42, 0x18, 0xfc,

    /* U+0033 "3" */
    0x74, 0x42, 0x37, 0x4, 0x31, 0xf0,

    /* U+0034 "4" */
    0x18, 0x62, 0x9a, 0xcb, 0xf0, 0x82, 0x8,

    /* U+0035 "5" */
    0x7d, 0x4, 0x1e, 0xc, 0x10, 0x63, 0x78,

    /* U+0036 "6" */
    0x39, 0x8, 0x2e, 0xc7, 0x1c, 0x59, 0x38,

    /* U+0037 "7" */
    0xfc, 0x21, 0x84, 0x10, 0x82, 0x8, 0x20,

    /* U+0038 "8" */
    0x32, 0x52, 0x93, 0x66, 0x31, 0x70,

    /* U+0039 "9" */
    0x72, 0x68, 0xe3, 0x74, 0x10, 0x62, 0x70,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x3d, 0x80,

    /* U+003C "<" */
    0x0, 0x77, 0x30, 0x70, 0x30,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x3, 0x83, 0x83, 0x3b, 0x0,

    /* U+003F "?" */
    0xe9, 0x13, 0x26, 0x6, 0x60,

    /* U+0040 "@" */
    0x1f, 0xc, 0x64, 0xb, 0x39, 0x9a, 0x64, 0x99,
    0x26, 0x4a, 0x5f, 0x98, 0x3, 0xe0,

    /* U+0041 "A" */
    0x18, 0x70, 0xa1, 0x66, 0x4f, 0x91, 0xe1, 0xc2,

    /* U+0042 "B" */
    0xfa, 0x18, 0x63, 0xfa, 0x18, 0x63, 0xf8,

    /* U+0043 "C" */
    0x3d, 0x18, 0x20, 0x82, 0x8, 0x11, 0x3c,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0x62, 0xf0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0x42, 0x10, 0xf8,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0x42, 0x10, 0x80,

    /* U+0047 "G" */
    0x3c, 0x86, 0x4, 0x8, 0xf0, 0x60, 0xa1, 0x3c,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x84,

    /* U+0049 "I" */
    0xff, 0x80,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x29, 0x70,

    /* U+004B "K" */
    0x8e, 0x6b, 0x28, 0xf3, 0x49, 0xa3, 0x84,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0xf8,

    /* U+004D "M" */
    0xc3, 0xc3, 0xc3, 0xa5, 0xa5, 0xbd, 0x99, 0x99,
    0x81,

    /* U+004E "N" */
    0x87, 0x1e, 0x69, 0xb6, 0x59, 0xe3, 0x84,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0050 "P" */
    0xfa, 0x18, 0x63, 0xfa, 0x8, 0x20, 0x80,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,
    0x30, 0x38,

    /* U+0052 "R" */
    0xfa, 0x18, 0x63, 0xfa, 0x68, 0xa3, 0x84,

    /* U+0053 "S" */
    0x7a, 0x8, 0x38, 0x78, 0x30, 0x61, 0x78,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x73, 0x78,

    /* U+0056 "V" */
    0xc3, 0x8d, 0x12, 0x26, 0xc5, 0xa, 0x1c, 0x18,

    /* U+0057 "W" */
    0xc4, 0x53, 0x14, 0xe5, 0x2b, 0x6a, 0xde, 0xa3,
    0x38, 0xc6, 0x31, 0x80,

    /* U+0058 "X" */
    0x46, 0xc8, 0xa1, 0xc1, 0x5, 0xb, 0x22, 0xc6,

    /* U+0059 "Y" */
    0x44, 0x88, 0xa1, 0x43, 0x82, 0x4, 0x8, 0x10,

    /* U+005A "Z" */
    0xfc, 0x31, 0x84, 0x30, 0x84, 0x30, 0xfc,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x70,

    /* U+005C "\\" */
    0x82, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x20,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0xf0,

    /* U+005E "^" */
    0x23, 0x14, 0xa9, 0xc4,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xb4,

    /* U+0061 "a" */
    0x74, 0x42, 0xf8, 0xc5, 0xe0,

    /* U+0062 "b" */
    0x82, 0x8, 0x3e, 0xce, 0x18, 0x61, 0x8b, 0xe0,

    /* U+0063 "c" */
    0x76, 0x21, 0x8, 0x61, 0xe0,

    /* U+0064 "d" */
    0x4, 0x10, 0x5f, 0x46, 0x18, 0x61, 0xc5, 0xf0,

    /* U+0065 "e" */
    0x39, 0x14, 0x7f, 0x41, 0x83, 0xc0,

    /* U+0066 "f" */
    0x32, 0x11, 0xe4, 0x21, 0x8, 0x42, 0x0,

    /* U+0067 "g" */
    0x7e, 0x28, 0xa2, 0x72, 0x7, 0xa1, 0x85, 0xe0,

    /* U+0068 "h" */
    0x84, 0x21, 0x6c, 0xc6, 0x31, 0x8c, 0x40,

    /* U+0069 "i" */
    0x9f, 0xc0,

    /* U+006A "j" */
    0x20, 0x12, 0x49, 0x24, 0x9c,

    /* U+006B "k" */
    0x84, 0x21, 0x3b, 0x53, 0x9e, 0x9c, 0x40,

    /* U+006C "l" */
    0xaa, 0xaa, 0xb0,

    /* U+006D "m" */
    0xf3, 0x66, 0x62, 0x31, 0x18, 0x8c, 0x46, 0x22,

    /* U+006E "n" */
    0xf6, 0x63, 0x18, 0xc6, 0x20,

    /* U+006F "o" */
    0x7b, 0x38, 0x61, 0x87, 0x37, 0x80,

    /* U+0070 "p" */
    0xfb, 0x38, 0x61, 0x86, 0x2f, 0xa0, 0x82, 0x0,

    /* U+0071 "q" */
    0x7d, 0x18, 0x61, 0x87, 0x17, 0xc1, 0x4, 0x10,

    /* U+0072 "r" */
    0xec, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x78, 0x86, 0x19, 0xe0,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x44, 0x30,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xcd, 0xe0,

    /* U+0076 "v" */
    0xc5, 0x14, 0xda, 0x28, 0xe3, 0x0,

    /* U+0077 "w" */
    0xcc, 0xd3, 0x24, 0xc9, 0xfa, 0x73, 0x8c, 0xc3,
    0x30,

    /* U+0078 "x" */
    0x4d, 0xa3, 0x8c, 0x39, 0x2c, 0xc0,

    /* U+0079 "y" */
    0xc5, 0x14, 0xda, 0x28, 0xa1, 0x4, 0x31, 0x80,

    /* U+007A "z" */
    0xf8, 0x8c, 0x44, 0x63, 0xe0,

    /* U+007B "{" */
    0x69, 0x24, 0xa2, 0x49, 0x30,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc9, 0x24, 0x8a, 0x49, 0x60,

    /* U+007E "~" */
    0x74, 0x70};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 43, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 66, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 99, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 109, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 21, .adv_w = 180, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 136, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 57, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 43, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 48, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 53, .adv_w = 93, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 55, .adv_w = 109, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 60, .adv_w = 57, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 62, .adv_w = 69, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 63, .adv_w = 57, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 75, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 70, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 109, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 109, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 109, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 109, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 57, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 57, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 142, .adv_w = 109, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 147, .adv_w = 109, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 150, .adv_w = 109, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 155, .adv_w = 95, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 187, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 174, .adv_w = 119, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 124, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 109, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 135, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 142, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 59, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 105, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 107, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 159, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 141, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 145, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 124, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 145, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 292, .adv_w = 126, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 117, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 117, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 141, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 172, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 114, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 117, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 369, .adv_w = 75, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 377, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 382, .adv_w = 109, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 386, .adv_w = 108, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 387, .adv_w = 118, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 388, .adv_w = 110, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 99, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 109, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 66, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 111, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 435, .adv_w = 119, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 55, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 56, .box_w = 3, .box_h = 13, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 449, .adv_w = 110, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 57, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 181, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 120, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 118, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 486, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 494, .adv_w = 79, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 92, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 76, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 119, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 105, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 159, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 101, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 104, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 541, .adv_w = 94, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 551, .adv_w = 54, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 553, .adv_w = 68, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 558, .adv_w = 109, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 4}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
    {
        {.range_start = 32, .range_length = 95, .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
    {
        0, 0, 0, 1, 0, 0, 0, 0,
        1, 2, 0, 0, 0, 3, 4, 3,
        5, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 6, 6, 0, 0, 0,
        0, 0, 7, 8, 9, 10, 11, 12,
        13, 0, 0, 14, 15, 16, 0, 0,
        10, 17, 10, 18, 19, 20, 21, 22,
        23, 24, 25, 26, 2, 27, 0, 0,
        0, 0, 28, 29, 30, 0, 31, 32,
        33, 34, 0, 0, 35, 36, 34, 34,
        29, 29, 37, 38, 39, 40, 37, 41,
        42, 43, 44, 45, 2, 0, 0, 0};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
    {
        0, 0, 1, 2, 0, 0, 0, 0,
        2, 0, 3, 4, 0, 5, 6, 7,
        8, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 9, 10, 0, 0, 0,
        11, 0, 12, 0, 13, 0, 0, 0,
        13, 0, 0, 14, 0, 0, 0, 0,
        13, 0, 13, 0, 15, 16, 17, 18,
        19, 20, 21, 22, 0, 23, 3, 0,
        0, 0, 24, 0, 25, 25, 25, 26,
        27, 0, 28, 29, 0, 0, 30, 30,
        25, 30, 25, 30, 31, 32, 33, 34,
        35, 36, 37, 38, 0, 0, 3, 0};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
    {
        0, 0, 0, 0, -26, 0, -26, 0,
        0, 0, 0, -13, 0, -22, -2, 0,
        0, 0, 0, -2, 0, 0, 0, 0,
        -5, 0, 0, 0, 0, 0, -4, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 17, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -23, 0, -32,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -21, -5, -15, -7, 0,
        -21, 0, 0, 0, -3, 0, 0, 0,
        6, 0, 0, -11, 0, -9, -6, 0,
        -4, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -4,
        -4, -11, 0, -4, -2, -7, -15, -4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -5, 0, -2, 0, -3, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -9, -2, -17, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -5,
        -6, 0, -2, 4, 4, 0, 0, 1,
        -4, 0, 0, 0, 0, 0, 0, 0,
        0, -9, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, -6, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -13, 0, -20,
        0, 0, 0, 0, 0, 0, -6, -1,
        -2, 0, 0, -13, -3, -3, 0, 0,
        -3, -1, -9, 4, 0, -2, 0, 0,
        0, 0, 4, -3, -1, -2, -1, -1,
        -2, 0, 0, 0, 0, -7, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -4,
        -3, -5, 0, -2, -1, -1, -3, -1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, -3, -2, -2, -3, 0,
        0, 0, 0, 0, 0, -6, 0, 0,
        0, 0, 0, 0, -7, -2, -5, -3,
        -3, -1, -1, -1, -2, -2, 0, 0,
        0, 0, -4, 0, 0, 0, 0, -7,
        -2, -3, -2, 0, -3, 0, 0, 0,
        0, -7, 0, 0, 0, -3, 0, 0,
        0, -2, 0, -10, 0, -5, 0, -2,
        -1, -4, -4, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -3, 0, -2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -2, 0, 0, 0,
        0, 0, 0, -5, 0, -2, 0, -7,
        -2, 0, 0, 0, 0, 0, -17, 0,
        -17, -14, 0, 0, 0, -8, -2, -30,
        -5, 0, 0, 0, 0, -5, -1, -7,
        0, -7, -3, 0, -5, 0, 0, -4,
        -5, -2, -4, -5, -4, -6, -4, -8,
        0, 0, 0, -6, 0, 0, 0, 0,
        0, 0, 0, -1, 0, 0, 0, -4,
        0, -3, -1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, -5, 0, -5, 0, 0, 0,
        0, 0, 0, -9, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -5, 0, -9,
        0, -8, 0, 0, 0, 0, -2, -2,
        -5, 0, -3, -4, -3, -3, -2, 0,
        -4, 0, 0, 0, -2, 0, 0, 0,
        -2, 0, 0, -8, -3, -5, -4, -4,
        -5, -3, 0, -23, 0, -34, 0, -11,
        0, 0, 0, 0, -8, 0, -6, 0,
        -5, -26, -7, -16, -12, 0, -17, 0,
        -17, 0, -3, -3, -1, 0, 0, 0,
        0, -5, -2, -9, -7, 0, -9, 0,
        0, 0, 0, 0, -25, -7, -25, -15,
        0, 0, 0, -11, 0, -31, -2, -5,
        0, 0, 0, -5, -2, -15, 0, -9,
        -5, 0, -6, 0, 0, 0, -2, 0,
        0, 0, 0, -3, 0, -4, 0, 0,
        0, -2, 0, -7, 0, 0, 0, 0,
        0, -1, 0, -3, -3, -3, 0, 0,
        1, -1, -1, -2, 0, -1, -2, 0,
        -1, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, -2, 0, 0, 0, -3,
        0, 3, 0, 0, 0, 0, 0, 0,
        0, -3, -3, -4, 0, 0, 0, 0,
        -3, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -5, 0, 0, 0, 0,
        0, -1, 0, 0, 0, 0, -24, -15,
        -24, -18, -4, -4, 0, -9, -5, -27,
        -7, 0, 0, 0, 0, -4, -3, -11,
        0, -15, -15, -3, -15, 0, 0, -10,
        -13, -3, -10, -7, -7, -7, -7, -16,
        0, 0, 0, 0, -4, 0, -4, -6,
        0, 0, 0, -3, 0, -11, -2, 0,
        0, -1, 0, -2, -3, 0, 0, -1,
        0, 0, -2, 0, 0, 0, -1, 0,
        0, 0, 0, -2, 0, 0, 0, 0,
        0, 0, -15, -4, -15, -9, 0, 0,
        0, -3, -2, -15, -2, 0, -2, 2,
        0, 0, 0, -4, 0, -6, -3, 0,
        -5, 0, 0, -4, -3, 0, -7, -2,
        -2, -3, -2, -5, 0, 0, 0, 0,
        -7, -2, -7, -5, 0, 0, 0, 0,
        -1, -13, -1, 0, 0, 0, 0, 0,
        0, -1, 0, -3, 0, 0, -2, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -2, 0, -2, 0, -2, 0, -7,
        0, 0, 0, 0, 0, 0, -4, -1,
        -3, -4, -2, 0, 0, 0, 0, 0,
        0, -2, -2, -4, 0, 0, 0, 0,
        0, -4, -2, -4, -3, -2, -4, -3,
        0, 0, 0, 0, -21, -15, -21, -13,
        -6, -6, -2, -3, -3, -21, -4, -3,
        -2, 0, 0, 0, 0, -5, 0, -15,
        -10, 0, -13, 0, 0, -9, -10, -8,
        -7, -3, -5, -7, -3, -11, 0, 0,
        0, 0, 0, -7, 0, 0, 0, 0,
        0, -1, -4, -7, -7, 0, -2, -1,
        -1, 0, -3, -3, 0, -3, -4, -4,
        -3, 0, 0, 0, 0, -3, -4, -3,
        -3, -5, -3, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -17, -5, -11, -5, 0,
        -15, 0, 0, 0, 0, 0, 7, 0,
        15, 0, 0, 0, 0, -4, -2, 0,
        2, 0, 0, 0, 0, -11, 0, 0,
        0, 0, 0, 0, -4, 0, 0, 0,
        0, -5, 0, -4, -1, 0, -5, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, -3, 0, 0, 0, 0, 0, 0,
        0, -5, 0, -4, -2, 1, -2, 0,
        0, 0, -4, 0, 0, 0, 0, -12,
        0, -4, 0, -1, -11, 0, -6, -3,
        0, -1, 0, 0, 0, 0, -1, -4,
        0, -1, -1, -4, -1, -2, 0, 0,
        0, 0, 0, -5, 0, 0, 0, 0,
        0, 0, 0, 0, 0, -4, 0, -3,
        0, 0, -5, 0, 0, -2, -5, 0,
        -2, 0, 0, 0, 0, -2, 0, 1,
        1, 1, 1, 0, 0, 0, 0, -7,
        0, 2, 0, 0, 0, 0, -2, 0,
        0, -4, -4, -5, 0, -4, -2, 0,
        -6, 0, -5, -3, 0, -1, -2, 0,
        0, 0, 0, -2, 0, 0, 0, -2,
        0, 0, 2, 9, 10, 0, -12, -3,
        -12, -2, 0, 0, 5, 0, 0, 0,
        0, 10, 0, 14, 10, 7, 12, 0,
        11, -4, -2, 0, -3, 0, -2, 0,
        -1, 0, 0, 2, 0, -1, 0, -3,
        0, 0, 2, -7, 0, 0, 0, 9,
        0, 0, -8, 0, 0, 0, 0, -6,
        0, 0, 0, 0, -3, 0, 0, -4,
        -3, 0, 0, 0, 9, 0, 0, 0,
        0, -1, -1, 0, 3, -3, 0, 0,
        0, -7, 0, 0, 0, 0, 0, 0,
        -2, 0, 0, 0, 0, -5, 0, -2,
        0, 0, -4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -5,
        2, -12, 2, 0, 2, 2, -4, 0,
        0, 0, 0, -9, 0, 0, 0, 0,
        -3, 0, 0, -2, -5, 0, -2, 0,
        -2, 0, 0, -5, -3, 0, 0, -2,
        0, -2, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -5, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -4,
        0, -3, 0, 0, -7, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, -14, -5, -14, -7, 4, 4,
        0, -3, 0, -13, 0, 0, 0, 0,
        0, 0, 0, -2, 2, -5, -2, 0,
        -2, 0, 0, 0, -1, 0, 0, 4,
        3, 0, 4, -1, 0, 0, 0, -9,
        0, 2, 0, 0, 0, 0, -3, 0,
        0, 0, 0, -5, 0, -2, 0, 0,
        -4, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, -4, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -6,
        0, 1, 2, 2, -6, 0, 0, 0,
        0, -3, 0, 0, 0, 0, -1, 0,
        0, -5, -3, 0, -2, 0, 0, 0,
        -2, -4, 0, 0, 0, -3, 0, 0,
        0, 0, 0, -3, -9, -2, -9, -4,
        0, 0, 0, -3, 0, -9, 0, -4,
        0, -2, 0, 0, -3, -2, 0, -4,
        -1, 0, 0, 0, -2, 0, 0, 0,
        0, 0, 0, 0, 0, -5, 0, 0,
        0, -3, -12, 0, -12, -1, 0, 0,
        0, -1, 0, -7, 0, -5, 0, -2,
        0, -3, -5, 0, 0, -2, -1, 0,
        0, 0, -2, 0, 0, 0, 0, 0,
        0, 0, 0, -4, -3, 0, 0, -5,
        2, -3, -2, 0, 0, 2, 0, 0,
        -2, 0, -1, -7, 0, -3, 0, -2,
        -7, 0, 0, -2, -4, 0, 0, 0,
        0, 0, 0, -5, 0, 0, 0, 0,
        -1, 0, 0, 0, 0, 0, -9, 0,
        -9, -2, 0, 0, 0, 0, 0, -9,
        0, -4, 0, -1, 0, -1, -2, 0,
        0, -4, -1, 0, 0, 0, -2, 0,
        0, 0, 0, 0, 0, -3, 0, -5,
        0, 0, 0, 0, 0, -4, 0, 0,
        0, 0, 0, 0, 0, 0, 0, -5,
        0, 0, 0, 0, -5, 0, 0, -4,
        -2, 0, -1, 0, 0, 0, 0, 0,
        -2, -1, 0, 0, -1, 0};

/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
    {
        .class_pair_values = kern_class_values,
        .left_class_mapping = kern_left_class_mapping,
        .right_class_mapping = kern_right_class_mapping,
        .left_class_cnt = 45,
        .right_class_cnt = 38,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_12;

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t siyuan12 = {
#else
lv_font_t siyuan12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 14,                              /*The maximum line height required by the font*/
    .base_line = 3,                                 /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = &lv_font_montserrat_12,
    .user_data = NULL,
};

#endif /*#if SIYUAN12*/
