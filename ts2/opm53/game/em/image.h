// STATUS: NOT STARTED

#ifndef GAME_EM_IMAGE_H
#define GAME_EM_IMAGE_H

#include "common.h"

typedef enum eImageType {
    IMAGE_UNKNOWN=0,
    IMAGE_RGB=1,
    IMAGE_P6=2,
    IMAGE_P8=3,
    IMAGE_Q6=4,
    IMAGE_Q8=5,
    IMAGE_M6=6,
    IMAGE_M8=7
} eImageType;

typedef union {
	struct {
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	} c;
	u32 rgba;
} rgba_t;

typedef struct emTexture_s {
	int flags;
	int TexNum;
	u32 *vifdata;
	u32 clampx;
	u32 clampy;
	u8 *data;
	u32 palpos;
	rgba_t *palette;
	void *pInfo;
	u32 miptbp[7];
	u32 miptbw[7];
	u16 pow2width[7];
	u16 pow2height[7];
	u16 sizeX[7];
	u16 sizeY[7];
	u16 loadsizeX[7];
	s8 size[7];
	u8 SwapFlags;
	u8 texformat;
	u8 miplevels;
} emTexture;

u32 tobw(u32 col);
void MakeCSM1Palette(rgba_t *src, rgba_t *dest);
eImageType GetFormat(char *header);
void ImageLoad(char *fileName, emTexture *desttex);
void ImageLoadFromMem(u32 addr, emTexture *desttex);
void ImageMakePalette(emTexture *texture, u32 *palette);

#endif // GAME_EM_IMAGE_H
