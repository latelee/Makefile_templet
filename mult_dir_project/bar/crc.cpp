#include "crc.h"

/////////////////////////////// crc16
/* CRC_CCITT x^16 + x^12 + x^5 + 1 */
const u16 crc_ccitt_table[256] = {
  0x0000, 0x1021, 0x2042, 0x3063, 0x4084,
  0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129,
  0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce,
  0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252,
  0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339,
  0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c,
  0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420,
  0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
  0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee,
  0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672,
  0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695,
  0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
  0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4,
  0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861,
  0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e,
  0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
  0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71,
  0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc,
  0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b,
  0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5,
  0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae,
  0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b,
  0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5,
  0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
  0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b,
  0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9,
  0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e,
  0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3,
  0x5004, 0x4025, 0x7046, 0x6067, 0x83b9,
  0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
  0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3,
  0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
  0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e,
  0xe54f, 0xd52c, 0xc50d, 0x34e2, 0x24c3,
  0x14a0, 0x0481, 0x7466, 0x6447, 0x5424,
  0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8,
  0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3,
  0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676,
  0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e,
  0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
  0x5844, 0x4865, 0x7806, 0x6827, 0x18c0,
  0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c,
  0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb,
  0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16,
  0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 0xfd2e,
  0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b,
  0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64,
  0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
  0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b,
  0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36,
  0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1,
  0x1ef0
};
/* standard crc16 x^16 + x^15 + x^2 + 1 */
const u16 crc16_table[256] = {
  0x0000, 0x8005, 0x800f, 0x000a, 0x801b,
  0x001e, 0x0014, 0x8011, 0x8033, 0x0036,
  0x003c, 0x8039, 0x0028, 0x802d, 0x8027,
  0x0022, 0x8063, 0x0066, 0x006c, 0x8069,
  0x0078, 0x807d, 0x8077, 0x0072, 0x0050,
  0x8055, 0x805f, 0x005a, 0x804b, 0x004e,
  0x0044, 0x8041, 0x80c3, 0x00c6, 0x00cc,
  0x80c9, 0x00d8, 0x80dd, 0x80d7, 0x00d2,
  0x00f0, 0x80f5, 0x80ff, 0x00fa, 0x80eb,
  0x00ee, 0x00e4, 0x80e1, 0x00a0, 0x80a5,
  0x80af, 0x00aa, 0x80bb, 0x00be, 0x00b4,
  0x80b1, 0x8093, 0x0096, 0x009c, 0x8099,
  0x0088, 0x808d, 0x8087, 0x0082, 0x8183,
  0x0186, 0x018c, 0x8189, 0x0198, 0x819d,
  0x8197, 0x0192, 0x01b0, 0x81b5, 0x81bf,
  0x01ba, 0x81ab, 0x01ae, 0x01a4, 0x81a1,
  0x01e0, 0x81e5, 0x81ef, 0x01ea, 0x81fb,
  0x01fe, 0x01f4, 0x81f1, 0x81d3, 0x01d6,
  0x01dc, 0x81d9, 0x01c8, 0x81cd, 0x81c7,
  0x01c2, 0x0140, 0x8145, 0x814f, 0x014a,
  0x815b, 0x015e, 0x0154, 0x8151, 0x8173,
  0x0176, 0x017c, 0x8179, 0x0168, 0x816d,
  0x8167, 0x0162, 0x8123, 0x0126, 0x012c,
  0x8129, 0x0138, 0x813d, 0x8137, 0x0132,
  0x0110, 0x8115, 0x811f, 0x011a, 0x810b,
  0x010e, 0x0104, 0x8101, 0x8303, 0x0306,
  0x030c, 0x8309, 0x0318, 0x831d, 0x8317,
  0x0312, 0x0330, 0x8335, 0x833f, 0x033a,
  0x832b, 0x032e, 0x0324, 0x8321, 0x0360,
  0x8365, 0x836f, 0x036a, 0x837b, 0x037e,
  0x0374, 0x8371, 0x8353, 0x0356, 0x035c,
  0x8359, 0x0348, 0x834d, 0x8347, 0x0342,
  0x03c0, 0x83c5, 0x83cf, 0x03ca, 0x83db,
  0x03de, 0x03d4, 0x83d1, 0x83f3, 0x03f6,
  0x03fc, 0x83f9, 0x03e8, 0x83ed, 0x83e7,
  0x03e2, 0x83a3, 0x03a6, 0x03ac, 0x83a9,
  0x03b8, 0x83bd, 0x83b7, 0x03b2, 0x0390,
  0x8395, 0x839f, 0x039a, 0x838b, 0x038e,
  0x0384, 0x8381, 0x0280, 0x8285, 0x828f,
  0x028a, 0x829b, 0x029e, 0x0294, 0x8291,
  0x82b3, 0x02b6, 0x02bc, 0x82b9, 0x02a8,
  0x82ad, 0x82a7, 0x02a2, 0x82e3, 0x02e6,
  0x02ec, 0x82e9, 0x02f8, 0x82fd, 0x82f7,
  0x02f2, 0x02d0, 0x82d5, 0x82df, 0x02da,
  0x82cb, 0x02ce, 0x02c4, 0x82c1, 0x8243,
  0x0246, 0x024c, 0x8249, 0x0258, 0x825d,
  0x8257, 0x0252, 0x0270, 0x8275, 0x827f,
  0x027a, 0x826b, 0x026e, 0x0264, 0x8261,
  0x0220, 0x8225, 0x822f, 0x022a, 0x823b,
  0x023e, 0x0234, 0x8231, 0x8213, 0x0216,
  0x021c, 0x8219, 0x0208, 0x820d, 0x8207,
  0x0202
};

/* (0xedb88320L) */
/* x^32+x^26+x^23+x^22+x^16+x^12+x^11+x^10+x^8+x^7+x^5+x^4+x^2+x+1. */
static const u32 crc32_table[256] = {
  0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
  0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
  0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
  0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
  0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
  0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
  0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
  0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
  0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
  0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
  0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
  0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
  0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
  0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
  0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
  0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
  0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
  0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
  0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
  0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
  0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
  0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
  0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
  0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
  0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
  0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
  0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
  0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
  0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
  0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
  0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
  0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
  0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
  0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
  0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
  0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
  0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
  0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
  0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
  0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
  0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
  0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
  0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
  0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
  0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
  0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
  0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
  0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
  0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
  0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
  0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
  0x2d02ef8dL
};

#define DO1(buf) crc = crc32_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define DO2(buf)  DO1(buf); DO1(buf);
#define DO4(buf)  DO2(buf); DO2(buf);
#define DO8(buf)  DO4(buf); DO4(buf);

u32 crc32(const u8 *buf, u32 len)
{
    u32 crc = 0xffffffffL;
    while (len >= 8)
    {
        DO8(buf);
        len -= 8;
    }
    if (len)
    {
        do {
            DO1(buf);
        } while (--len);
    }
    return crc ^ 0xffffffffL;
}

u32 crc32_1(u32 crc, const u8 *buf, u32 len)
{
    crc = crc ^ 0xffffffffL;
    while (len >= 8)
    {
        DO8(buf);
        len -= 8;
    }
    if (len)
    {
        do {
            DO1(buf);
        } while (--len);
    }
    return crc ^ 0xffffffffL;
}


static u32 dynamic_crc32_table[256] = {0};

/* make CRC32 table
 * 
 * x^32+x^26+x^23+x^22+x^16+x^12+x^11+x^10+x^8+x^7+x^5+x^4+x^2+x+1
*/
static void make_crc32_table()
{
  uLong c;
  int n, k;
  uLong poly;            /* polynomial exclusive-or pattern */
  /* terms of polynomial defining this crc (except x^32): */
  static const Byte p[] = {0,1,2,4,5,7,8,10,11,12,16,22,23,26};

  /* make exclusive-or pattern from polynomial (0xedb88320L) */
  poly = 0L;
  for (n = 0; n < sizeof(p)/sizeof(Byte); n++)
    poly |= 1L << (31 - p[n]);

  for (n = 0; n < 256; n++)
  {
    c = (uLong)n;
    for (k = 0; k < 8; k++)
      c = c & 1 ? poly ^ (c >> 1) : c >> 1;
    dynamic_crc32_table[n] = c;
  }
}

u32 ssh_crc32(const u8 *buf, u32 len)
{
    u32 i;
    u32 crc;

    crc = 0xffffffffL;
    for (i = 0; i < len; i++)
        crc = dynamic_crc32_table[(crc ^ buf[i]) & 0xff] ^ (crc >> 8);
    return crc ^ 0xffffffffL;
}

#define CRC16 0x8005
#define CRC_CCITT 0x1021
static u16 dynamic_crc16_table[256] = {0};
// make CRC16 tanlr
// argument: 0x8005��CRC_16, x^16 + x^15 + x^2 + 1
// argument: 0x1021��CRC_CCITT, x^16 + x^12 + x^5 + 1
static void make_crc16_table(u16 poly)
{
    u16 i,j;
    u16 data;
    u16 crc;

    for (i = 0; i < 256; i++)
    {
        data = (u16)(i << 8);
        crc = 0;
        for (j = 0; j < 8; j++)
        {
            if ((data ^ crc) & 0x8000)
                crc = (crc << 1) ^ poly;
            else
                crc <<= 1;
            data <<=1;
        }
        dynamic_crc16_table[i] = crc;
    }
}

u16 crc16(const u8 *buf, u32 len)
{
    u32 i;
    u16 crc = 0;

    for (i = 0; i < len; i++)
        crc = crc_ccitt_table[(crc >> 8) ^ buf[i]] ^ (crc << 8);
    return crc;
}

// half byte
u16 crc16_1(const u8 *buf, u32 len)
{
    u16 crc = 0;
    u8 data = 0;
    u16 crc_table[16] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084,
    0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129,
    0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce,
    0xf1ef };

    while (len-- != 0)
    {
        data = ((u8)(crc / 256)) / 16;
        crc <<= 4;
        crc ^= crc_table[data ^ (*buf / 16)];

        data = ((u8)(crc / 256)) / 16;
        crc <<= 4;
        crc ^= crc_table[data ^ (*buf & 0x0f)];
        buf++;
    }

    return crc;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_table()
{
    int i = 1;
    make_crc16_table(CRC16);
    for (i = 1; i < 257; i++)
    {
        printf("0x%04x, ", dynamic_crc16_table[i-1]);
        if (i % 5 == 0)
            printf("\n  ");
    }
}
#if 0
int main(void)
{
    char *p = "hello, world.";
    int crc = 0;
    //crc = crc32(crc, (unsigned char *)p, (u32)strlen(p));
    crc = crc32((unsigned char *)p, (u32)strlen(p));
    printf("crc: %X %d\n", crc, crc);

    make_crc32_table();
    crc = ssh_crc32((unsigned char *)p, (u32)strlen(p));
    printf("crc: %X %d\n", crc, crc);

    // crc16 test
    crc = crc16((unsigned char *)p, (u32)strlen(p));
    printf("crc: %X %d\n", crc, crc);

    crc = crc16_1((unsigned char *)p, (u32)strlen(p));
    printf("crc: %X %d\n", crc, crc);

    printf("\n");
    return 0;
}
#endif