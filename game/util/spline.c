// STATUS: NOT STARTED

#include "spline.h"

void splineCatmullRomPoint3d(float *point, float scalar, float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4) {
	float q1;
	float q2;
	float q3;
	float q4;
	float scalarSq;
	float scalarCub;
}

void splineCatmullRomGfx(float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4, u32 colSpline, u32 colControl) {
	float x;
	float dx;
	float dx2;
	float y;
	float dy;
	float dy2;
	float z;
	float dz;
	float dz2;
	float t;
	mtx_u geo;
	mtx_u m;
	mtx_u catmullRom;
	int i;
	float pos1[3];
	float pos2[3];
}

void splineCatmullRomPoint2d(float *point, float scalar, float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4) {
	float q1;
	float q2;
	float q3;
	float q4;
	float scalarSq;
	float scalarCub;
}

float splineCatmullRomPoint1d(float scalar, float controlPoint1, float controlPoint2, float controlPoint3, float controlPoint4) {
	float q1;
	float q2;
	float q3;
	float q4;
	float scalarSq;
	float scalarCub;
}
