#ifndef CRC_H
#define CRC_H

typedef unsigned long u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long uLong;
typedef char Byte;

#ifdef __cplusplus
extern "C" {
#endif

u32 crc32(const u8 *buf, u32 len);
u32 crc32_1(u32 crc, const u8 *buf, u32 len);
u16 crc16(const u8 *buf, u32 len);
u16 crc16_1(const u8 *buf, u32 len);

#ifdef __cplusplus
}
#endif

#endif /* CRC_H */