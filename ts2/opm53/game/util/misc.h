//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_MISC_H
#define GAME_UTIL_MISC_H

#include "common.h"

struct bubblesort_s {
  int value;
  u32 data;
};
typedef struct bubblesort_s bubblesort_t;

u8* vafmt(u8 *format);
int PowerOf2(int value);
void bubbleSort(bubblesort_t *tab, bubblesort_t **sorted, int num);
void changeFileExt(u8 *outstr, u8 *instr, u8 *newext, u8 *oldext);
void fileNameBase(u8 *outstr, u8 *instr);

#endif // GAME_UTIL_MISC_H
