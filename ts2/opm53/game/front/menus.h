// STATUS: NOT STARTED

#ifndef GAME_FRONT_MENUS_H
#define GAME_FRONT_MENUS_H

typedef short int s16;
typedef hitbox_s hitbox_t;

// warning: multiple differing types with the same name (#68, fields size not equal)
struct menu_s {
	int numitems;
	s16 baseleft;
	s16 basetop;
	void *spare[2];
};

typedef menu_s menu_t;

// warning: multiple differing types with the same name (#68, fields size not equal)
struct menuitem_s {
	char *text;
	s16 left;
	s16 top;
	u16 id;
	u16 flags;
	void *data;
	u16 next[4];
	void *spare[2];
};

typedef menuitem_s menuitem_t;

// warning: multiple differing types with the same name (#68, descriptor not equal)
struct menulist_s {
	u16 numitems;
	u16 numdisplay;
	s16 baseleft;
	s16 basetop;
	u16 flags;
	u16 selected;
	u8 firstdisplay[4];
};

typedef menulist_s menulist_t;
extern int menujoy;
extern menuitem_t *highlightitem[4];
extern u8 menuitemflash;
extern u32 menuitem_fgcol;
extern u32 menuitem_bgcol;
extern int menuitem_normalfont;
extern int menuitem_bigfont;

void makebox(hitbox_t *box, s16 x, s16 y, s16 w, s16 h, u16 id, u16 flags, void (*draw)(/* parameters unknown */));
void std_drawmenuitemtext(hitbox_t *box);
void draw_slider(int x, int y, int value, int range, boolean enabled);
void draw_menuitem(hitbox_t *box);
void std_menugetmargins(menuitem_t *p, int numitems, s16 baseleft, s16 *x);
void std_menuitemmake(hitbox_t *box, s16 *pos, menuitem_t *mi);
int std_menulistmake(hitbox_t *box, menulist_t *list, int xOffset, int yOffset);
int adv_menumake(hitbox_t *box, menu_t *menu, int xOffset, int yOffset);
int std_menumake(hitbox_t *box, menu_t *menu);
menuitem_t* menuitem(menu_t *menu, u16 id);
menuitem_t* menuitemGetSelect(menu_t *menu);
void menuitemSelect(menu_t *menu, u16 id);
void menuitemHighlight(pagedef_t *page);
menulist_t* isinlist(menu_t *menu, u16 id);
void std_menutick(pagedef_t *page, menu_t *menu);

#endif // GAME_FRONT_MENUS_H
