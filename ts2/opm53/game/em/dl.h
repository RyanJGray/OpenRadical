//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_EM_DL_H
#define GAME_EM_DL_H

#include "common.h"
#include "util/matrix.h"

struct fields_s {
	u16 qwc;
	u8 mark;
	u8 id;
};

union word1_u {
	u32 val;
	struct fields_s fields;
};

typedef struct dlDmaTag_s {
	union word1_u word1;
	struct dlDmaTag_s *next;
	u_int p[2];
} dlDmaTag;

extern dlDmaTag *pushgfxtag;
extern u32 ucodestart[6][2];
extern u32 ucode_loadxyzw[6];
extern u32 ucode_loadst[6];
extern u32 ucode_loadrgba[6];
extern u32 ucode_loadnorm[6];

void dlSignal(u32 sigid);
void dlSelectTextureKick(int num);
void dlSelectTextureDB(int num);
void dlSelectTextureKickDB(int num);
void dlSetClipTag(int textured);
int dlSetZB(int mode);
void dlLabel(u32 id);
void dlFBA(u32 destinationAlpha);
void dlSetFrame(u32 noBufferUpdate);
void dlSetFixedRGBA(u32 rgba);
int dlSetBlend(int mode);
void dlSetClip(int left, int top, int right, int bottom);
void dlClearFB(int x1, int y1, int x2, int y2, int rgba);
void dlSetFBMSK(int mask);
void dlFillRectangle(int x1, int y1, int x2, int y2, int rgba);
void dlFillRectangleFloat(float x1, float y1, float x2, float y2, int rgba);
void dlFillRectangleColFloat(float x1, float y1, float x2, float y2, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR);
void dlFillQuad3D(float *pos1, float *pos2, float *pos3, float *pos4, u32 abgr1, u32 abgr2, u32 abgr3, u32 abgr4);
void dlDrawPoint(int x, int y, int rgba);
void dlDrawLine(int x1, int y1, int x2, int y2, int rgba);
void dlDrawLineFloat(float x1, float y1, float x2, float y2, int rgba);
void dlDrawAALine(int x1, int y1, int x2, int y2, int rgba);
void dlDrawTriangleStrip(int *rgbaxy, int numpts, boolean textured);
void dlTextureRectangle(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, int rgba);
void dlTextureRectangleZ(int x1, int y1, int x2, int y2, int u1, int v1, int u2, int v2, int rgba, float cameraZ);
void dlTextureRectangleFloat(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, int rgba);
void dlTextureRectangleFloatZ(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, int rgba, float cameraZ);
void dlTextureRectangleColFloat(float x1, float y1, float x2, float y2, int u1, int v1, int u2, int v2, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR);
void dlTextureQuadFloatZ(float z, float xTL, float yTL, float xTR, float yTR, float xBL, float yBL, float xBR, float yBR, int uTL, int vTL, int uTR, int vTR, int uBL, int vBL, int uBR, int vBR, u32 abgrTL, u32 abgrTR, u32 abgrBL, u32 abgrBR);
void dlTextureQuad3D(int texturenum, float *pos1, float *pos2, float *pos3, float *pos4, u32 abgr1, u32 abgr2, u32 abgr3, u32 abgr4, float u1, float v1, float u2, float v2);
void dlPushDmaTag(dlDmaTag *push);
void dlPopDmaTag();
void dlSetPerspectiveMatrix(mtx *mtx);

#endif // GAME_EM_DL_H
