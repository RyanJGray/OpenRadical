// STATUS: NOT STARTED

#ifndef GAME_UTIL_COLOUR_H
#define GAME_UTIL_COLOUR_H

void colourRGBftoHSV(float *rgb, float *hsv);
void colourHSVtoRGBf(float *hsv, float *rgb);
u32 colourHSVtoRGBA(float *hsv);
void colourRGBAtoHSV(u32 rgba, float *hsv);
u32 colourBlend(u32 colour1, u32 colour2, float blend1);
u32 rgbJoyAdjust(u32 rgba);

#endif // GAME_UTIL_COLOUR_H
