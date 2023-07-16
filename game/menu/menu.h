// STATUS: NOT STARTED

#ifndef GAME_MENU_MENU_H
#define GAME_MENU_MENU_H

struct menuitemsize_s {
	int width;
	int height;
};

typedef menuitemsize_s menuitemsize;
typedef void (*menuMsgTicker)(/* parameters unknown */);
extern int menu_stackpos;
extern int debugmenu_stackpos;
extern menu *curmenu;
extern menu *debugcurmenu;
extern int debugmode;
extern u8 *in_message;
extern menuMsgTicker in_message_ticker;
extern menu *menustack[10];
extern menu *debugmenustack[10];

int istext(u8 *text);
u8* gettextfromfunction(u8 *text, menuitem *item);
void menuitemCalcSize(menuitem *item, menuitemsize *size);
int menuitemCalcPos(int type, int off, int size, int start, int end);
void menuitemInit(menuitem *item);
void menuStart(menu *m);
void menuEnd();
void menuTick();
void menuitemGfx(menuitem *item);
void menuGfx();
void menuDefMsgWaitFunc();
void menuStartMessage(u8 *s, menuMsgTicker func);
void menuEndMessage();
void menuTextBoxGfx();

#endif // GAME_MENU_MENU_H
