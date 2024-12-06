//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FX_ZBTEST_H
#define GAME_FX_ZBTEST_H

#include "common.h"

typedef struct zbtestval_s {
  int player;
  void *ref;
  void *ref2;
  u32 offset;
  u32 expect;
  u32 actual;
  int Bias;
} zbtestval;

extern u8 *zbuffer;
extern int extraglow1type;
extern int extraglow2type;

void zbtestPreload();
void zbtestSetExtraGlowTypes(int type1, int type2);
void zbtestRestart();
void zbtestReset();
void zbtestRestartAfter();
void zbtestResetAfter();
void zbtestEnd();
void zbtestGfx();
boolean zbtestStartAddGlow();
void zbtestEndAddGlow();
u32 zbtestGetOffset(int x, int y);
void zbtestAddPoint(int player, void *ref, void *ref2, int x, int y, u32 expect,
                    int Bias);
void zbtestDrawGlow(int player, int texture, int type, float x, float y,
                    int sizex, int sizey, u32 col);
void zbtestDrawFlareFx(int player, int type, float *worldpos, u32 alpha);
void zbtestAdvanceAddPtr();
void zbtestMake();
void zbtestCopyZB();
void zbtestDoTest(int Frame);
boolean zbtestIsCorrectFrame();
boolean zbtestIsVisible(zbtestval *zt);
int zbtestGetVisibleBias(int player, void *ref, void *ref2);

#endif // GAME_FX_ZBTEST_H
