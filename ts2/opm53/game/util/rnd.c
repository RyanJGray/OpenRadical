//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "rnd.h"

u64 newrndseedval = 0x21454A53;
int rndcount = 0;

static u32 newrnd2() {
  u64 tempseed =
      ((newrndseedval << 0x3f) >> 0x1f | (newrndseedval << 0x1f) >> 0x20) ^
      (newrndseedval << 0x2c) >> 0x20;
  newrndseedval = (tempseed >> 0x14 & 0xfff) ^ tempseed;

  return (u32)newrndseedval;
}

u32 newrnd() {
  rndcount++;

  return newrnd2();
}

void newrndseed(u32 seed) {
  rndcount = 0;
  newrndseedval = (u64)seed + 1;

  return;
}
