//
// The OpenTS2 Project
// 2023
//

#include "misc.h"
#include "../../types.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

u8* vafmt(u8 *format, ...) {
  static u8 string[1024];
  va_list args;

  va_start(args, format);
  vsprintf(&string, format, args);
  va_end(args);

  return &string;
}

int PowerOf2(int value) {
  int count = 0;
  
  if (value != 0) {
    for (value--; value != 0; value = value >> 1) {
      count++;
    }
  }

  return count;
}

// Behold - the forsaken pointer arithmetic!
void bubbleSort(bubblesort_t *tab, bubblesort_t **sorted, int num) {
  int i = 0;
  int j = 0;
  boolean done = FALSE;

  if (num > 0) {
    do {
      sorted += i;
      tab += i;
      i++;
      *sorted = tab;
    } while (i < num);
  }

  i = num - 2;
  if (num > 1) {
    do {
      if (i < 0) {
        return;
      }
      done = TRUE;
      if (i > -1) {
        j = i + 1;
        do {
          tab = *sorted;
          j--;

          if (tab->value < sorted[1]->value) {
            *sorted = sorted[1];
            done = FALSE;
            sorted[1] = tab;
          }  
          sorted++;
        } while (j != 0);
      }
      i--;
    } while (!done);
  }
}

void changeFileExt(u8 *outstr, u8 *instr, u8 *newext, u8 *oldext) {
  int slen;
  int extlen;

  slen = strlen(instr);
  extlen = strlen(oldext);
  strcpy(outstr, instr);
  strcpy(outstr + (slen - extlen), newext);
}

void fileNameBase(u8 *outstr, u8 *instr) {
  u8 *s;
  u8 *s2;

  
}
