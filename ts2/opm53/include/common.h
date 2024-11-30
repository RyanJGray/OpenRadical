//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef COMMON_H
#define COMMON_H

#if 1
#include <eetypes.h>

typedef unsigned int boolean;
typedef char s8;
typedef unsigned char u8;
typedef short int s16;
typedef short unsigned int u16;
typedef int s32;
typedef unsigned int u32;
typedef long long int s64;
typedef long long unsigned int u64;
typedef u_long128 u128;
#else
typedef char s8;
typedef std::uint8_t u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;

typedef unsigned char u_char;
#endif

#endif // COMMON_H
