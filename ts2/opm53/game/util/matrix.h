// STATUS: NOT STARTED

#ifndef GAME_UTIL_MATRIX_H
#define GAME_UTIL_MATRIX_H

union mtx_u {
	float f[4][4];
	u32 l[16];
	u16 s[32];
};

void matrixRotX(mtx_u *m, float angle);
void matrixRotY(mtx_u *m, float angle);
void matrixRotZ(mtx_u *m, float angle);
void matrixRotZXY(mtx_u *m, float anglex, float angley, float anglez);
void matrixTransRotY(mtx_u *m, float tx, float ty, float tz, float angle);
void matrixTransRotZXY(mtx_u *m, float tx, float ty, float tz, float anglex, float angley, float anglez);
void matrixTrans(mtx_u *m, float transx, float transy, float transz);
void matrixSetTrans(mtx_u *m, float transx, float transy, float transz);
void matrixScale(mtx_u *m, float scale);
void matrixDoScaleX(mtx_u *m, float scalex);
void matrixScaleSet(mtx_u *m, float x, float y, float z);
void matrixLook(mtx_u *m, float camposx, float camposy, float camposz, float camdirx, float camdiry, float camdirz, float upx, float upy, float upz);
void matrixLookAt(mtx_u *m, float *campos, float *lookat, float *up);
void matrixPerspective(mtx_u *m, float aspect, float fovy, float near, float far);
void matrixOrtho(mtx_u *m, float x1, float y1, float x2, float y2, float near, float far);
void matrixVecMul(mtx_u *m, float *vec);
void matrixVecMulAligned(mtx_u *m, float *vec);
void matrixVec3Mul4(mtx_u *m, float *vec, float *newvec);
void matrixVec3Mul4Aligned(mtx_u *m, float *vec, float *newvec);
void matrixVecRot(mtx_u *m, float *vec);
void matrixVecRotAligned(mtx_u *m, float *vec);
void matrixVecTrans(mtx_u *m, float *vec);
void matrixPrintf(mtx_u *m);
void matrixToQuaternion(quaternion *q, mtx_u *matrix);
void matrixToQuaternionNew(quaternion *q, mtx_u *matrix);
void calInbetweenMatrix(mtx_u *mparent, mtx_u *mchild, mtx_u *mOut, float weight);
void matrixroll(mtx_u *newmtx, float *axis, float axialrot);
void matrixLerp(mtx_u *m1, mtx_u *m2, float t, mtx_u *mout);
void matrix2Euler(mtx_u *m, float *angle);

#endif // GAME_UTIL_MATRIX_H
