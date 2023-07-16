// STATUS: NOT STARTED

#include "matrix.h"

void matrixRotX(mtx_u *m, float angle) {
	float s;
	float c;
}

void matrixRotY(mtx_u *m, float angle) {
	float s;
	float c;
}

void matrixRotZ(mtx_u *m, float angle) {
	float s;
	float c;
}

void matrixRotZXY(mtx_u *m, float anglex, float angley, float anglez) {
	float cx;
	float cy;
	float cz;
	float sx;
	float sy;
	float sz;
	float sxsy;
	float sxcy;
}

void matrixTransRotY(mtx_u *m, float tx, float ty, float tz, float angle) {
	float s;
	float c;
}

void matrixTransRotZXY(mtx_u *m, float tx, float ty, float tz, float anglex, float angley, float anglez) {
	float cx;
	float cy;
	float cz;
	float sx;
	float sy;
	float sz;
	float sxsy;
	float sxcy;
}

void matrixTrans(mtx_u *m, float transx, float transy, float transz) {}

void matrixSetTrans(mtx_u *m, float transx, float transy, float transz) {}

void matrixScale(mtx_u *m, float scale) {}

void matrixDoScaleX(mtx_u *m, float scalex) {}

void matrixScaleSet(mtx_u *m, float x, float y, float z) {}

void matrixLook(mtx_u *m, float camposx, float camposy, float camposz, float camdirx, float camdiry, float camdirz, float upx, float upy, float upz) {
	float upz;
	float len;
	float right[3];
}

void matrixLookAt(mtx_u *m, float *campos, float *lookat, float *up) {}

void matrixPerspective(mtx_u *m, float aspect, float fovy, float near, float far) {
	float invtan;
	float tmpfov;
	float zdist;
}

void matrixOrtho(mtx_u *m, float x1, float y1, float x2, float y2, float near, float far) {
	float x;
	float y;
	float z;
	float tx;
	float ty;
	float tz;
}

void matrixVecMul(mtx_u *m, float *vec) {
	float newvec[3];
	int i;
}

void matrixVecMulAligned(mtx_u *m, float *vec) {}

void matrixVec3Mul4(mtx_u *m, float *vec, float *newvec) {
	int i;
}

void matrixVec3Mul4Aligned(mtx_u *m, float *vec, float *newvec) {}

void matrixVecRot(mtx_u *m, float *vec) {
	float newvec[3];
	int i;
}

void matrixVecRotAligned(mtx_u *m, float *vec) {}

void matrixVecTrans(mtx_u *m, float *vec) {
	int i;
}

void matrixPrintf(mtx_u *m) {
	int i;
	int j;
}

void matrixToQuaternion(quaternion *q, mtx_u *matrix) {
	float s;
	float trace;
	float tmp[3];
	int i;
	int j;
	int k;
	int next[3];
}

void matrixToQuaternionNew(quaternion *q, mtx_u *matrix) {
	float s;
	float trace;
	float tmp[3];
	int i;
	int j;
	int k;
	int next[3];
	float qu[4];
	quaternion *qsrc;
	quaternion *qdest;
}

void calInbetweenMatrix(mtx_u *mparent, mtx_u *mchild, mtx_u *mOut, float weight) {
	quaternion q1;
	quaternion q2;
	quaternion q3;
}

void matrixroll(mtx_u *newmtx, float *axis, float axialrot) {
	float s;
	float c;
	float t;
	float x;
	float y;
	float z;
}

void matrixLerp(mtx_u *m1, mtx_u *m2, float t, mtx_u *mout) {
	float s;
}

void matrix2Euler(mtx_u *m, float *angle) {
	float sintheta;
	float c;
}
