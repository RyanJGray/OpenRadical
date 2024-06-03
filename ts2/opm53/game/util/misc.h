//
// The OpenTS2 Project
// 2023
//

#ifndef GAME_UTIL_MISC_H
#define GAME_UTIL_MISC_H

#include "../../types.h"

struct bubblesort_s {
  int value;
  u32 data;
};
typedef bubblesort_s bubblesort_t;

u8* vafmt(u8 *format);
int PowerOf2(int value);
void bubbleSort(bubblesort_t *tab, bubblesort_t **sorted, int num);
void changeFileExt(u8 *outstr, u8 *instr, u8 *newext, u8 *oldext);
void fileNameBase(u8 *outstr, u8 *instr);

#endif // GAME_UTIL_MISC_H
