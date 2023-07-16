// STATUS: NOT STARTED

#ifndef GAME_UTIL_CRC_H
#define GAME_UTIL_CRC_H

extern u32 crc_32_tab[0];

u32 crcCalc(u8 *buffer, int length);
int crcCheck(u8 *buffer, int length, u32 crc);

#endif // GAME_UTIL_CRC_H
