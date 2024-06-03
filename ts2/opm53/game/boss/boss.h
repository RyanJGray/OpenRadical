// STATUS: NOT STARTED

#ifndef GAME_BOSS_BOSS_H
#define GAME_BOSS_BOSS_H

typedef struct {
	unsigned int DIR : 1;
	unsigned int p0 : 1;
	unsigned int MOD : 2;
	unsigned int ASP : 2;
	unsigned int TTE : 1;
	unsigned int TIE : 1;
	unsigned int STR : 1;
	unsigned int p1 : 7;
	unsigned int TAG : 16;
} tD_CHCR;

typedef _sceDmaTag sceDmaTag;

typedef struct {
	tD_CHCR chcr;
	u_int p0[3];
	void *madr;
	u_int p1[3];
	u_int qwc;
	u_int p2[3];
	sceDmaTag *tadr;
	u_int p3[3];
	void *as0;
	u_int p4[3];
	void *as1;
	u_int p5[3];
	u_int p6[4];
	u_int p7[4];
	void *sadr;
	u_int p8[3];
} sceDmaChan;

typedef struct {
	long unsigned int NLOOP : 15;
	long unsigned int EOP : 1;
	long unsigned int pad16 : 16;
	long unsigned int id : 14;
	long unsigned int PRE : 1;
	long unsigned int PRIM : 11;
	long unsigned int FLG : 2;
	long unsigned int NREG : 4;
	long unsigned int REGS0 : 4;
	long unsigned int REGS1 : 4;
	long unsigned int REGS2 : 4;
	long unsigned int REGS3 : 4;
	long unsigned int REGS4 : 4;
	long unsigned int REGS5 : 4;
	long unsigned int REGS6 : 4;
	long unsigned int REGS7 : 4;
	long unsigned int REGS8 : 4;
	long unsigned int REGS9 : 4;
	long unsigned int REGS10 : 4;
	long unsigned int REGS11 : 4;
	long unsigned int REGS12 : 4;
	long unsigned int REGS13 : 4;
	long unsigned int REGS14 : 4;
	long unsigned int REGS15 : 4;
} sceGifTag;

typedef struct {
	tGS_PMODE pmode;
	tGS_SMODE2 smode2;
	tGS_DISPFB2 dispfb;
	tGS_DISPLAY2 display;
	tGS_BGCOLOR bgcolor;
} sceGsDispEnv;

typedef struct {
	sceGsFrame frame1;
	u_long frame1addr;
	sceGsZbuf zbuf1;
	long int zbuf1addr;
	sceGsXyoffset xyoffset1;
	long int xyoffset1addr;
	sceGsScissor scissor1;
	long int scissor1addr;
	sceGsPrmodecont prmodecont;
	long int prmodecontaddr;
	sceGsColclamp colclamp;
	long int colclampaddr;
	sceGsDthe dthe;
	long int dtheaddr;
	sceGsTest test1;
	long int test1addr;
} sceGsDrawEnv1;

typedef struct {
	sceGsTest testa;
	long int testaaddr;
	sceGsPrim prim;
	long int primaddr;
	sceGsRgbaq rgbaq;
	long int rgbaqaddr;
	sceGsXyz xyz2a;
	long int xyz2aaddr;
	sceGsXyz xyz2b;
	long int xyz2baddr;
	sceGsTest testb;
	long int testbaddr;
} sceGsClear;

typedef struct {
	sceGsDispEnv disp[2];
	sceGifTag giftag0;
	sceGsDrawEnv1 draw0;
	sceGsClear clear0;
	sceGifTag giftag1;
	sceGsDrawEnv1 draw1;
	sceGsClear clear1;
} sceGsDBuff;

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
extern char **languages[0];
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
