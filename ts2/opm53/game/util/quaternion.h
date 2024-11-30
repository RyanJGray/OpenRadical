//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_QUATERNION_H
#define GAME_UTIL_QUATERNION_H

#include "util/matrix.h"

struct quaternion_s {
	float x;
	float y;
	float z;
	float w;
};

typedef struct quaternion_s quaternion;

void rotx2fquat(float angle, float *quat);
void roty2fquat(float angle, float *quat);
void rotz2fquat(float angle, float *quat);
void rot2fquat(float *angle, float *quat);
void matrixToQuaternion(quaternion *q, mtx *matrix);
void matrixToQuaternionNew(quaternion *q, mtx *matrix);
void quaternionToMatrix(mtx *m, quaternion *q);
void quaternionSlerp(quaternion *q1, quaternion *qIn2, float time, quaternion *qOut);
void quaternionSlerp2(quaternion *q1, quaternion *qIn2, float time, quaternion *qOut);
void quaternionLerp(quaternion *q1, quaternion *q2, float time, quaternion *qOut);
void quaternionMul(quaternion *q0, quaternion *q1, quaternion *q2);
void quaternionInvert(quaternion *qOut, quaternion *qIn);
void quaternionNormalise(quaternion *q);
void quaternion2AxisAngle(quaternion *q, float *axis, float angle);
void AxisAngle2quaternion(quaternion *q, float *axis, float *angle);

#endif // GAME_UTIL_QUATERNION_H
