//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_MAPMAKER_MM_MENUS_H
#define GAME_MAPMAKER_MM_MENUS_H

#include "common.h"
#include "front/front.h"
#include "front/front_mpg.h"

typedef struct gvdisp_s {
	int value;
	char *text;
} gvdisp;

// warning: multiple differing types with the same name (type name not equal)
typedef int (*msgfunc_t)(/* parameters unknown */);

extern gamevar gv_gridintensity;
extern gvdisp disp_tilesets[0];
extern gvdisp disp_tunes[0];
extern gamevar gv_tileset;
extern gamevar gv_tune;
extern gamevar gv_wpnset;
extern gunset mmgunset;
extern gvdisp disp_npcstate[0];
extern pageinit_t enemyedit_page;
extern int rolloffset;
extern gvdisp disp_padactstart[0];
extern gvdisp disp_padactpwup[0];
extern gvdisp disp_padactkey[0];
extern gvdisp disp_padacttele[0];
extern menu_t padact_menu;
extern u16 padactcuritem;
extern pageinit_t padact_page;

void M_MakeBox(hitbox_t *box, s16 x, s16 y, s16 w, s16 h, u16 id, u16 flags, void (*draw)(/* parameters unknown */));
int MM_GetTuneNum();
void MM_SetTuneNum(int tunenum);
int MM_GetWeaponSetNum();
int MM_GetGunComboNum(int levelgun);
void MM_SetGunComboNum(int levelgun, int guncombo);
void MM_StartMessage(u8 *text, u32 colour, msgfunc_t msgfunc);
void MM_StartMainMenu();
void enemyedit_pageDraw(pagedef_t *page);
void enemyedit_pageTick(pagedef_t *page);
int rollmenumake(hitbox_t *box, menu_t *menu, u16 curitem, boolean inactive);
void padact_pageDraw(pagedef_t *page);
void padact_pageTick(pagedef_t *page);

#endif // GAME_MAPMAKER_MM_MENUS_H
