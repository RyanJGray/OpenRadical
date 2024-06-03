// STATUS: NOT STARTED

#include "menus.h"

int menujoy = 0;

menuitem_t *highlightitem[4] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL
};

u8 menuitemflash = 0;
u32 menuitem_fgcol = 0;
u32 menuitem_bgcol = 0;
int menuitem_normalfont = 0;
int menuitem_bigfont = 0;

void makebox(hitbox_t *box, s16 x, s16 y, s16 w, s16 h, u16 id, u16 flags, void (*draw)(/* parameters unknown */)) {}

void std_drawmenuitemtext(hitbox_t *box) {
	int x;
	int y;
	u32 colour;
	u32 bgcolour;
	menuitem_t *mi;
	int font;
	int x1;
}

void draw_slider(int x, int y, int value, int range, boolean enabled) {
	int xv;
	int w;
	int h;
}

void draw_menuitem(hitbox_t *box) {
	menuitem_t *mi;
	gamevar *gv;
	u8 *s;
	int x;
	int y;
	int font;
	u32 fgcol;
	u32 bgcol;
	int marginx;
	int w;
	int found;
	int maxw;
	int i;
}

void std_menugetmargins(menuitem_t *p, int numitems, s16 baseleft, s16 *x) {
	int i;
	s16 left;
	s16 right;
	s16 width;
}

void std_menuitemmake(hitbox_t *box, s16 *pos, menuitem_t *mi) {
	int x;
	int y;
	int w;
	int h;
	int font;
}

int std_menulistmake(hitbox_t *box, menulist_t *list, int xOffset, int yOffset) {
	hitbox_t *startbox;
	menuitem_t *mi;
	s16 pos[2];
	int i;
}

int adv_menumake(hitbox_t *box, menu_t *menu, int xOffset, int yOffset) {
	s16 pos[2];
	int i;
	int font;
	menuitem_t *mi;
	hitbox_t *startbox;
}

int std_menumake(hitbox_t *box, menu_t *menu) {
	s16 pos[2];
	int i;
	int font;
	menuitem_t *mi;
	hitbox_t *startbox;
}

menuitem_t* menuitem(menu_t *menu, u16 id) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

menuitem_t* menuitemGetSelect(menu_t *menu) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

void menuitemSelect(menu_t *menu, u16 id) {
	menuitem_t *mi;
}

void menuitemHighlight(pagedef_t *page) {
	hitbox_t *box;
}

menulist_t* isinlist(menu_t *menu, u16 id) {
	int i;
	menuitem_t *mi;
	int j;
	menulist_t *list;
	menuitem_t *item;
}

void std_menutick(pagedef_t *page, menu_t *menu) {
	int i;
	menuitem_t *mi;
	menulist_t *ml;
	menuitem_t *firstitem;
	int index;
	int mod;
}
