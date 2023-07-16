// STATUS: NOT STARTED

#ifndef GAME_UTIL_SCREENDUMP_H
#define GAME_UTIL_SCREENDUMP_H

typedef struct {
	long unsigned int pad00;
} sceGsFinish;

typedef struct {
	u_int vifcode[4];
	sceGifTag giftag;
	sceGsBitbltbuf bitbltbuf;
	long int bitbltbufaddr;
	sceGsTrxpos trxpos;
	long int trxposaddr;
	sceGsTrxreg trxreg;
	long int trxregaddr;
	sceGsFinish finish;
	long int finishaddr;
	sceGsTrxdir trxdir;
	long int trxdiraddr;
} sceGsStoreImage;

extern u8 *frame1;
extern u8 *frame2;
extern u8 *outfile;
extern sceGsStoreImage gs_simage;

void screenDumpGetFrame1();
void screenDumpGetFrame2();
void screenDumpSave();
void zbDump();

#endif // GAME_UTIL_SCREENDUMP_H
