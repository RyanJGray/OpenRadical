//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_BOSS_BOSS_H
#define GAME_BOSS_BOSS_H

#include <libdma.h>
#include <libgraph.h>

#include "common.h"
#include "em/dl.h"
#include "game/game.h"

enum {
	LANG_ENGLISH = 0,
	LANG_FRENCH = 1,
	LANG_GERMAN = 2,
	LANG_ITALIAN = 3,
	LANG_SPANISH = 4,
	LANG_NUM = 5
};

extern int curcpudmabuf;
extern int curgsdmabuf;
extern int ucodevtxs;
extern int ucodetris;
extern int fxtris;
extern int bgtris;
extern int bgcurtris;
extern int ucodecycles;
extern int bgroomsdrawn;
extern int gsstart_sid;
extern int gsdone_sid;
extern int bufffree_sid;
extern int gsavail_sid;
extern int cpu_tid;
extern int gs_tid;
extern int gsdone;
extern int cpudone;
extern char **languages[LANG_NUM];
extern int cur_language;
extern int dvd;
extern int timeout_inactive;
extern int playrollingdemo;
extern int displayallfileops;
extern int restart;
extern int maxdmalistlen;
extern int numdmafail;
extern int lastfrbuf;
extern int bosscammode;
extern int bosscampropnum;
extern int numglowsdrawn;
extern int glowpixels;
extern u8 scratchbuffer[133120];
extern dlDmaTag *gfxtag;
extern int lvend;
extern sceDmaChan *dmaVif1;
extern sceDmaChan *dmaSpr;
extern int myargc;
extern char **myargv;
extern resetgameparms bossgameparms;
extern sceGsDBuff db;
extern float gsStartTime[5];
extern int gsStartFrame[5];
extern float gsEndTime[5];
extern u_long128 base_ptr[10];

int bossCheckParm(char *check);
boolean bossIsNextParm();
char* bossGetNextParm();
void sjeGsSwapDBuff(int buff, boolean FromInterupt);
void bossDmaFromSpr(u32 src, u32 dest, u32 len);
void bossTurtleCpu();
void bossTurtleGs();
void bossMainLoop();
void bossScreenDump();
void checkstring(u8 *s);
int main(int argc, char **argv);

#endif // GAME_BOSS_BOSS_H
