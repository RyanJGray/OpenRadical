//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_MATRIX_H
#define GAME_UTIL_MATRIX_H

#include "common.h"

typedef union mtx_u {
	float f[4][4];
	u32 l[16];
	u16 s[32];
} mtx;

void matrixRotX(mtx *m, float angle);
void matrixRotY(mtx *m, float angle);
void matrixRotZ(mtx *m, float angle);
void matrixRotZXY(mtx *m, float anglex, float angley, float anglez);
void matrixTransRotY(mtx *m, float tx, float ty, float tz, float angle);
void matrixTransRotZXY(mtx *m, float tx, float ty, float tz, float anglex, float angley, float anglez);
void matrixTrans(mtx *m, float transx, float transy, float transz);
void matrixSetTrans(mtx *m, float transx, float transy, float transz);
void matrixScale(mtx *m, float scale);
void matrixDoScaleX(mtx *m, float scalex);
void matrixScaleSet(mtx *m, float x, float y, float z);
void matrixLook(mtx *m, float camposx, float camposy, float camposz, float camdirx, float camdiry, float camdirz, float upx, float upy, float upz);
void matrixLookAt(mtx *m, float *campos, float *lookat, float *up);
void matrixPerspective(mtx *m, float aspect, float fovy, float near, float far);
void matrixOrtho(mtx *m, float x1, float y1, float x2, float y2, float near, float far);
void matrixVecMul(mtx *m, float *vec);
void matrixVecMulAligned(mtx *m, float *vec);
void matrixVec3Mul4(mtx *m, float *vec, float *newvec);
void matrixVec3Mul4Aligned(mtx *m, float *vec, float *newvec);
void matrixVecRot(mtx *m, float *vec);
void matrixVecRotAligned(mtx *m, float *vec);
void matrixVecTrans(mtx *m, float *vec);
void matrixPrintf(mtx *m);
void calInbetweenMatrix(mtx *mparent, mtx *mchild, mtx *mOut, float weight);
void matrixroll(mtx *newmtx, float *axis, float axialrot);
void matrixLerp(mtx *m1, mtx *m2, float t, mtx *mout);
void matrix2Euler(mtx *m, float *angle);

#endif // GAME_UTIL_MATRIX_H
