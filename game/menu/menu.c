// STATUS: NOT STARTED

#include "menu.h"

int menu_stackpos = 0;
int debugmenu_stackpos = 0;
menu *curmenu = NULL;
menu *debugcurmenu = NULL;
int debugmode = 0;
u8 *in_message = NULL;
menuMsgTicker in_message_ticker = NULL;

menu *menustack[10] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL
};

menu *debugmenustack[10] = {
	/* [0] = */ NULL,
	/* [1] = */ NULL,
	/* [2] = */ NULL,
	/* [3] = */ NULL,
	/* [4] = */ NULL,
	/* [5] = */ NULL,
	/* [6] = */ NULL,
	/* [7] = */ NULL,
	/* [8] = */ NULL,
	/* [9] = */ NULL
};

static void toggledebug() {
	menu *tmpm;
	int i;
}

static void focusnext() {
	menuitem *first;
	menuitem *next;
	menuitem *item;
	int i;
	int getnext;
}

static void focusprev() {
	menuitem *last;
	menuitem *prev;
	int i;
	int getprev;
}

int istext(u8 *text) {}

u8* gettextfromfunction(u8 *text, menuitem *item) {}

void menuitemCalcSize(menuitem *item, menuitemsize *size) {
	u8 *text;
}

int menuitemCalcPos(int type, int off, int size, int start, int end) {
	int retval;
}

void menuitemInit(menuitem *item) {
	menuitemsize sz1;
	menuitemsize sz2;
	int refpos;
}

void menuStart(menu *m) {
	int i;
}

void menuEnd() {}

void menuTick() {
	void (*callfunction)(/* parameters unknown */);
}

void menuitemGfx(menuitem *item) {
	int x;
	int y;
	int col;
	u8 *text;
}

void menuGfx() {
	int i;
	int minx;
	int miny;
	int miny2;
	int maxx;
	int maxy;
	int x;
	int y;
	int w;
	int h;
	int blend;
	menuitem *item;
	menuitemsize sz;
}

void menuDefMsgWaitFunc() {}

void menuStartMessage(u8 *s, menuMsgTicker func) {}

void menuEndMessage() {}

void menuTextBoxGfx() {
	int x;
	int y;
	int w;
	int h;
}
