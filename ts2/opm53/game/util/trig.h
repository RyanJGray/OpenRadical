//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_UTIL_TRIG_H
#define GAME_UTIL_TRIG_H

extern float g_SinTable[2048];

float trigClamp360(float angle);
void trigMake();

#endif // GAME_UTIL_TRIG_H
