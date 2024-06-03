// STATUS: NOT STARTED

#ifndef GAME_FX_IMAGEPROC_H
#define GAME_FX_IMAGEPROC_H

struct imageproc_s {
	boolean defocus;
	boolean fisheye;
	boolean viewzb;
	int invert;
	int night;
	int blur;
	int blurmode;
	int whiten;
	int contrast;
	int red;
	int green;
	int blue;
	int depth;
	int sectorLeft;
	int sectorTop;
	int sectorRight;
	int sectorBottom;
	boolean timePortal;
	int timePortalX;
	int timePortalY;
};

typedef imageproc_s imageproc;

struct imageprocPoint_s {
	boolean borderx;
	boolean bordery;
	int xOriginal;
	int yOriginal;
	int xWave;
	int yWave;
	boolean visible;
	boolean test;
	zbtestval zt;
	float heatAmplitude;
	float heatIntensity[16];
};

typedef imageprocPoint_s imageprocPoint;

struct imageprocSector_s {
	int localplayer;
	int xLeft;
	int yTop;
	int xRight;
	int yBottom;
	int texLeft;
	int texTop;
	int texRight;
	int texBottom;
	imageprocPoint *topLeft;
	imageprocPoint *topRight;
	imageprocPoint *bottomLeft;
	imageprocPoint *bottomRight;
};

typedef imageprocSector_s imageprocSector;
extern imageprocPoint ipPoints[9][9];
extern imageprocSector ipSectors[8][8];
extern imageproc imagefx[16];

imageproc* ipGet(int viewnum);
imageproc* ipCurrent();
imageprocSector* ipGetSector(int x, int y);
void ipRestart();
void ipSetCurScreenAsTexture();
void ipSetLastScreenAsTexture();
void ipSetZBAsTexture();
void ipDefocus();
void ipMotionBlur(u8 intensity, int blurmode);
void ipViewZB();
void ipInvertScreen(int red, int green, int blue, int intensity);
void ipFishEye(float xscale, float yscale);
void ipTimePortal();
void ipWhiten(u32 intensity);
void ipContrast(u32 intensity);
void ipColor(u32 red, u32 green, u32 blue);
void ipDepth(int mode);
void imageProcPointTick();
void imageProcAddHeatToPoint(imageprocPoint *point, int player, float z, float intensity, float amplitude);
void imageProcAddHeat(int viewnum, float *screenpos, float newposz, float amount);
void imageProcSectorGfx();
void imageProcInvisibility();
void ipTick();
void imageProcBeforeZBGfx();
void ipGfx();

#endif // GAME_FX_IMAGEPROC_H
