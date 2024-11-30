//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_OB_OBBOUNDS_H
#define GAME_OB_OBBOUNDS_H

#include "hittest/hittest.h"

typedef struct obbounds_s {
	float mins[3];
	float maxs[3];
	int NumPolys;
	ColPoly *pColPolys;
} obbounds;

#endif // GAME_OB_OBBOUNDS_H
