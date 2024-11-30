//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_FRONT_FRONT_H
#define GAME_FRONT_FRONT_H

struct pageinit_s {
	void (*tick)(/* parameters unknown */);
	void (*draw_before)(/* parameters unknown */);
	u16 initfocusid;
	u16 pad;
	void (*draw_after)(/* parameters unknown */);
	void (*construct)(/* parameters unknown */);
};

typedef pageinit_s pageinit_t;

struct frontdef_s {
	int num;
	pagedef_t *pagesArray;
	pagedef_t *pages[3];
	hitbox_t *boxes;
	int flags;
	int buttonhold;
	int numpages;
	pageinit_t *pagetoset;
	int pagetosetnum;
	fix_t mouse_x;
	fix_t mouse_y;
	void (*cursor_drawer)(/* parameters unknown */);
};

typedef frontdef_s frontdef_t;
extern gvdisp disp_off[0];
extern gvdisp disp_none[0];
extern gvdisp disp_onoff[0];
extern gvdisp disp_yesno[0];
extern frontdef_t *front;
extern frontdef_t frontdefs[4];
extern pagedef_t *currentpage;

u8* gvGetStringValue(gamevar *gv);
void gvSetValue(gamevar *gv, int value);
int gvDispIndex(gvdisp *disp, int dispvalue);
void frontGetPageSize(pagedef_t *page, rect_t *size);
hitbox_t* frontGetBox(pagedef_t *page, u16 id);
void frontControlsTick(int j);
void frontMouseTick();
void frontClearPages();
void frontClear();
void frontRestart();
void frontReset();
void frontSet(int playernum);
frontdef_t* frontGet(int playernum);
void frontPageSetup(pagedef_t *page, pageinit_t *init);
void frontTickCore();
void frontTick();
void frontGfxCore();
void frontGfx();
void frontEnd();
/// Adds a new page to the menu system.
/// `front->pagetoset` must be NULL or an assertion will occur.
void frontPageSet(int pagenum, pageinit_t *init);
pagedef_t* frontPageActivate(pageinit_t *init);
pagedef_t* frontPageAdd(pageinit_t *init);
pagedef_t* frontPageGet(pageinit_t *init);
pagedef_t* frontGetTopPage();
void frontPageRemoveInit(pageinit_t *init);
void frontPageRemove(pagedef_t *page);

#endif // GAME_FRONT_FRONT_H
