// STATUS: NOT STARTED

#ifndef GAME_EM_EM_H
#define GAME_EM_EM_H

struct texinfo_s {
	int id;
	int clampu;
	int clampv;
	int flags;
};

typedef texinfo_s texinfo;

typedef struct {
	u32 width;
	u32 height;
	u32 mask;
	int numfit;
	u8 fit[32];
	int extents;
} texsize_t;

struct texbuffer_s {
	emTexture *textures;
	pageinfo *pages;
	u8 *textypes;
	int nexttexid;
	int firstpage;
	int numpages;
	int max_texid;
	boolean HasUnusedPage;
	int CurrentFillPalettePage;
	int CurrentSwapPalettePage;
	int CurrentSwapPaletteNum;
	int CurrentFillTexturePage[31];
	int CurrentSwapTexturePage[31];
	int CurrentSwapTextureNum[31];
};

typedef texbuffer_s texbuffer;
extern u32 vifdata_notexture[0];
extern texbuffer *thistexbuf;
extern texsize_t tsizes[31];
extern int TotalTextureMem;
extern texbuffer texbuf[1];

void emResetTexBuffer(int num);
void emSelectTexBuffer(int num);
void emRestart();
void emReset();
void emPrintStats();
void emSetupVifLoadPacket(emTexture *texture);
void emLoadTextureMovie(char *filename, texinfo *t, int *idpos);
void emCreateRenderTexture(int Width, int Height, ViewDef *pView, int *pTexNum);
void emProcessRenderTexture(int TexID);
void emLoadTextureAddr(u32 addr, texinfo *t, int *idpos);
void emLoadTextureMem(u8 *pData, texinfo *t, int *idpos);
void emLoadTextureName(char *filename, texinfo *t, int *idpos);
void emLoadTextureNum(int id, texinfo *t, int *idpos);
void emAllocTexture(int pixwidth, int pixheight, int format, int miplevels, texinfo *t, u32 *palette, u8 *data, int *idpos);
void emCheckTextureMain(int id);
void emClearAllTexPages();
u_int getFlags();
void DecodeNextMovie();
void DecodeFirstMovie();
void emMake();
void emTick();

#endif // GAME_EM_EM_H