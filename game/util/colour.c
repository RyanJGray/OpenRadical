// STATUS: NOT STARTED

#include "colour.h"

void colourRGBftoHSV(float *rgb, float *hsv) {
	float r;
	float g;
	float b;
	float min;
	float max;
	float delta;
}

void colourHSVtoRGBf(float *hsv, float *rgb) {
	float i;
	float h;
	float f;
	float p;
	float q;
	float t;
}

u32 colourHSVtoRGBA(float *hsv) {
	float rgb[3];
	union {
		u32 rgba;
		u8 abgr[4];
	} c;
}

void colourRGBAtoHSV(u32 rgba, float *hsv) {
	float rgb[3];
}

u32 colourBlend(u32 colour1, u32 colour2, float blend1) {
	union {
		u32 rgba;
		u8 abgr[4];
	} c2;
	float invblend1;
}

u32 rgbJoyAdjust(u32 rgba) {}
