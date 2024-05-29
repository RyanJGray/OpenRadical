//
// The OpenRadical Project
// A project by Ryan J. Gray - 2024
// TS2 OPM53 Tree
//

#include "image.h"

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

/// <summary>
/// Decodes the magic in an FRD image / texture data file.
/// The file format appears to be based on the PBM image format?
/// </summary>
/// <returns>
/// eImageType - the type of image data that has been detected.
/// </returns>
eImageType GetFormat(char *header) {
	u16 *sp = (u16)header;

	// 0x01da is little-endian, second case is big endian (0xda01).
	if ((*sp == 0x01da) || (*sp == 0xda01)) {
	  return IMAGE_RGB;
	}

	if (*sp == 0x3651) {
	  return IMAGE_Q6;
	}
	if (*sp < 0x3652) {
	  if (*sp == 0x364d) {
	    return IMAGE_M6;
	  }
	  if (*sp == 0x3650) {
	    return IMAGE_P6;
	  }
	}
	else {
	  if (*sp == 0x3850) {
	    return IMAGE_P8;
	  }
	  if (*sp < 0x3851) {
	    if (*sp == 0x384d) {
	      return IMAGE_M8;
	    }
	  }
	  else if (*sp == 0x3851) {
	    return IMAGE_Q8;
	  }
	}

	return IMAGE_UNKNOWN;
}

static eImageType ImageGetDetails(char *filename) {
	bigbuffer = scratchbuffer;
	downloadbuffer = scratchbuffer + 0x10480;
	int maxsize = fileSize(filename);
	fileLoadTo(filename, bigbuffer, maxsize);
	eImageType fileformat = GetFormat(bigbuffer);

	return fileformat;
}

void ImageLoad(char *fileName, emTexture *desttex) {
	eImageType fileformat;

	fileformat = ImageGetDetails(fileName);
	desttex->flags = 0;
	desttex->miplevels = '\x01';

	switch(fileformat) {
	case IMAGE_RGB:
	  OpenRGB(fileName, desttex);
	  return;
	case IMAGE_P6:
	case IMAGE_Q6:
	case IMAGE_Q8:
	case IMAGE_M6:
	case IMAGE_M8:
	  OpenXPM(fileName, desttex, fileformat);
	  return;
	default:
	  exit(1);
	}
}

static eImageType ImageGetDetailsFromMem(u32 addr) {
	downloadbuffer = scratchbuffer + 0x10480;
	bigbuffer = scratchbuffer;
	bcopy(addr, scratchbuffer, 0x10480);
	eImageType fileformat = GetFormat(bigbuffer);

	return fileformat;
}

void ImageLoadFromMem(u32 addr, emTexture *desttex) {
	eImageType fileformat;

	fileformat = ImageGetDetailsFromMem(addr);
	desttex->flags = 0;
	desttex->miplevels = '\x01';

	switch(fileformat) {
	case IMAGE_RGB:
	  OpenRGB("mem", desttex);
	  return;
	case IMAGE_P6:
	case IMAGE_Q6:
	case IMAGE_Q8:
	case IMAGE_M6:
	case IMAGE_M8:
	  OpenXPM("mem", desttex, fileformat);
	  return;
	default:
	  exit(1);
	}
}

void ImageMakePalette(emTexture *texture, u32 *palette) {
	u8* mem = memAlloc(0x480, 1);
	texture->palette = (rgba_t*)((u32)(mem + 0x7f) & 0xffffff80);
	memset(texture->palette, 0x3f, 0x400);

	if (palette != nullptr) {
	  MakeCSM1Palette(palette, texture->palette);
	  return;
	}

	return;
}
