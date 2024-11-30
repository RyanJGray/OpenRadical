//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FRONT_FRONT_MPG_H
#define GAME_FRONT_FRONT_MPG_H

#include "common.h"
#include "mapmaker/mm_menus.h"
#include "prop/prop.h"
#include "window/window.h"

typedef struct gamevar_s {
	int value;
	int min;
	int max;
	int flags;
	gvdisp *display;
	void (*onChange)(/* parameters unknown */);
	u8 *suffix;
	int marginright;
	int arrowleftofs;
	int arrowrightofs;
} gamevar;

// warning: multiple differing types with the same name (type name not equal)
typedef boolean (*msgfunc_t)(/* parameters unknown */);
extern gamevar gv_playmusic;
extern gamevar gv_playsound;
extern gamevar gv_musicvolume;
extern gamevar gv_soundvolume;
extern window_t frontendWindow;

int frontmpgGetGunComboNum(int levelgun);
void tlhAdjustChrPosition(prop *p);
void statistics_pageDrawInfo(int left, int right, int col, lifestats_t *lifestats, int gametype, int page, int player);
void frontmpgMake();
void frontmpgPreload();
void frontmpgReset();
void frontmpgEnd();
void frontmpgSetFlags(int flag);

#endif // GAME_FRONT_FRONT_MPG_H
