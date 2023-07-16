// STATUS: NOT STARTED

#ifndef GAME_UTIL_SPLINE_H
#define GAME_UTIL_SPLINE_H

void splineCatmullRomPoint3d(float *point, float scalar, float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4);
void splineCatmullRomGfx(float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4, u32 colSpline, u32 colControl);
void splineCatmullRomPoint2d(float *point, float scalar, float *controlPoint1, float *controlPoint2, float *controlPoint3, float *controlPoint4);
float splineCatmullRomPoint1d(float scalar, float controlPoint1, float controlPoint2, float controlPoint3, float controlPoint4);

#endif // GAME_UTIL_SPLINE_H
