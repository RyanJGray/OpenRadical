// STATUS: NOT STARTED

#ifndef GAME_FX_ZBTEST_H
#define GAME_FX_ZBTEST_H

typedef struct {
	long unsigned int SBP : 14;
	long unsigned int pad14 : 2;
	long unsigned int SBW : 6;
	long unsigned int pad22 : 2;
	long unsigned int SPSM : 6;
	long unsigned int pad30 : 2;
	long unsigned int DBP : 14;
	long unsigned int pad46 : 2;
	long unsigned int DBW : 6;
	long unsigned int pad54 : 2;
	long unsigned int DPSM : 6;
	long unsigned int pad62 : 2;
} sceGsBitbltbuf;

typedef struct {
	u_int ID;
	u_int IDMSK;
} sceGsSignal;

typedef struct {
	long unsigned int XDR : 2;
	long unsigned int pad02 : 62;
} sceGsTrxdir;

typedef struct {
	long unsigned int SSAX : 11;
	long unsigned int pad11 : 5;
	long unsigned int SSAY : 11;
	long unsigned int pad27 : 5;
	long unsigned int DSAX : 11;
	long unsigned int pad43 : 5;
	long unsigned int DSAY : 11;
	long unsigned int DIR : 2;
	long unsigned int pad61 : 3;
} sceGsTrxpos;

typedef struct {
	long unsigned int RRW : 12;
	long unsigned int pad12 : 20;
	long unsigned int RRH : 12;
	long unsigned int pad44 : 20;
} sceGsTrxreg;

struct zbtestval_s {
	int player;
	void *ref;
	void *ref2;
	u32 offset;
	u32 expect;
	u32 actual;
	int Bias;
};

typedef zbtestval_s zbtestval;
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
void zbtestAddPoint(int player, void *ref, void *ref2, int x, int y, u32 expect, int Bias);
void zbtestDrawGlow(int player, int texture, int type, float x, float y, int sizex, int sizey, u32 col);
void zbtestDrawFlareFx(int player, int type, float *worldpos, u32 alpha);
void zbtestAdvanceAddPtr();
void zbtestMake();
void zbtestCopyZB();
void zbtestDoTest(int Frame);
boolean zbtestIsCorrectFrame();
boolean zbtestIsVisible(zbtestval *zt);
int zbtestGetVisibleBias(int player, void *ref, void *ref2);

#endif // GAME_FX_ZBTEST_H
