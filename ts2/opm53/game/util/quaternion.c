// STATUS: NOT STARTED

#include "quaternion.h"

void rotx2fquat(float angle, float *quat) {
	float hx;
}

void roty2fquat(float angle, float *quat) {
	float hy;
}

void rotz2fquat(float angle, float *quat) {
	float hz;
}

void rot2fquat(float *angle, float *quat) {
	float hx;
	float hy;
	float hz;
	float shx;
	float chx;
	float shy;
	float chy;
	float shz;
	float chz;
	float chxchy;
	float chxshy;
	float shxchy;
	float shxshy;
}

void quaternionToMatrix(mtx_u *m, quaternion *q) {
	float s;
	float xs;
	float ys;
	float zs;
	float wx;
	float wy;
	float wz;
	float xx;
	float xy;
	float xz;
	float yy;
	float yz;
	float zz;
}

void quaternionSlerp(quaternion *q1, quaternion *qIn2, float time, quaternion *qOut) {
	float omega;
	float cos_om;
	float sin_om;
	float sclp;
	float sclq;
	quaternion q2;
	quaternion qdiff;
	quaternion qsum;
	float mag1;
	float mag2;
	quaternion *qdest;
	quaternion *qsrc;
	quaternion *qdest;
	quaternion *qsrc;
	quaternion *qsrc1;
	quaternion *qsrc2;
	quaternion *qsrc1;
	quaternion *qsrc2;
	quaternion *qsrc;
	quaternion *qsrc;
}

void quaternionSlerp2(quaternion *q1, quaternion *qIn2, float time, quaternion *qOut) {
	float omega;
	float cos_om;
	float sin_om;
	float sclp;
	float sclq;
	quaternion q2;
	float mag1;
	float mag2;
	quaternion *qdest;
	quaternion *qsrc;
	quaternion *qdest;
	quaternion *qsrc;
	quaternion *qsrc;
}

void quaternionLerp(quaternion *q1, quaternion *q2, float time, quaternion *qOut) {
	float s;
}

void quaternionMul(quaternion *q0, quaternion *q1, quaternion *q2) {}

void quaternionInvert(quaternion *qOut, quaternion *qIn) {}

void quaternionNormalise(quaternion *q) {
	float mag;
}

void quaternion2AxisAngle(quaternion *q, float *axis, float angle) {
	float sina;
}

void AxisAngle2quaternion(quaternion *q, float *axis, float *angle) {
	float cosa;
	float sina;
}
