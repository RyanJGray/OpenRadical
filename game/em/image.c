// STATUS: NOT STARTED

#include "image.h"

typedef enum {
	IMAGE_UNKNOWN = 0,
	IMAGE_RGB = 1,
	IMAGE_P6 = 2,
	IMAGE_P8 = 3,
	IMAGE_Q6 = 4,
	IMAGE_Q8 = 5,
	IMAGE_M6 = 6,
	IMAGE_M8 = 7
} eImageType;

typedef struct {
	short unsigned int imagic;
	short unsigned int type;
	short unsigned int dim;
	short unsigned int sizeX;
	short unsigned int sizeY;
	short unsigned int sizeZ;
	unsigned char *tmp[5];
	unsigned int rleEnd;
	unsigned int *rowStart;
	unsigned int *rowSize;
} RGB_header;

static u8 *bigbuffer = NULL;
static u8 *downloadbuffer = NULL;

u32 tobw(u32 col) {
	u32 r;
	u32 g;
	u32 b;
	u32 a;
}

void MakeCSM1Palette(rgba_t *src, rgba_t *dest) {
	int i;
	int j;
}

static u8* FindRawData(u8 *pRaw) {
	int i;
}

static void OpenXPM(u8 *fileName, emTexture *desttex, eImageType fileformat) {
	u8 *pRaw;
	u32 i;
	u32 iRange;
	u32 ncols;
	u32 datasize;
	u32 pixelsize;
	u8 cFixpal;
	u8 *src;
	u8 *dest;
	u32 x;
	u32 y;
	u32 BufferSize;
	u32 mipX;
	u32 mipY;
	u32 miploadX;
}

static void RGBGetRow(RGB_header *image, unsigned char *buf, int y, int z) {
	unsigned char *iPtr;
	unsigned char *oPtr;
	unsigned char pixel;
	int count;
}

static void OpenRGB(u8 *fileName, emTexture *desttex) {
	RGB_header rgb;
	u32 *rowStart;
	u32 *rowSize;
	u32 ulTmp;
	int x;
	int y;
	int z;
	int i;
	u8 *data;
}

eImageType GetFormat(char *header) {
	u16 *sp;
}

static eImageType ImageGetDetails(char *filename) {}

void ImageLoad(char *fileName, emTexture *desttex) {
	eImageType fileformat;
}

static eImageType ImageGetDetailsFromMem(u32 addr) {}

void ImageLoadFromMem(u32 addr, emTexture *desttex) {
	eImageType fileformat;
}

void ImageMakePalette(emTexture *texture, u32 *palette) {}
