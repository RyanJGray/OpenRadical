// STATUS: NOT STARTED

#ifndef GAME_FRONT_GUI_H
#define GAME_FRONT_GUI_H

typedef enum {
	btn_circle = 0,
	btn_cross = 1,
	btn_triangle = 2,
	btn_square = 3,
	btn_select = 4,
	btn_start = 5,
	numbuttons = 6
} e_button;

typedef enum {
	dpad_up = 0,
	dpad_down = 1,
	dpad_left = 2,
	dpad_right = 3
} dpad_button;

enum e_icon {
	icon_1 = 0,
	icon_2 = 1,
	icon_3 = 2,
	icon_right = 3,
	icon_left = 4,
	icon_top = 5,
	icon_bottom = 6,
	icon_mag = 7,
	icon_toselect = 8,
	icon_arrow = 9,
	icon_isotile = 10,
	icon_isotile2 = 11,
	icon_l1 = 12,
	icon_l2 = 13,
	icon_spot = 14,
	icon_arrowlamp = 15,
	icon_hand = 16,
	icon_star = 17,
	icon_on = 18,
	icon_off = 19,
	icon_trileft = 20,
	icon_triright = 21,
	icon_male = 22,
	icon_female = 23,
	icon_phase1 = 24,
	icon_phase12 = 35,
	icon_exclamationmark = 36,
	icon_editmodetile = 37,
	icon_editmodeitem = 38,
	icon_editmodelight = 39,
	icon_zoomviewgun = 40,
	icon_zoomviewammo = 41,
	icon_zoomviewbag = 42,
	icon_zoomviewstart = 43,
	icon_zoomviewhealth = 44,
	icon_zoomviewarmour = 45,
	icon_zoomviewkey = 46,
	icon_zoomviewpower = 47,
	icon_zoomviewtele = 48,
	icon_flag = 49,
	icon_arrowlamp2 = 50,
	icon_patrolmode1 = 51,
	icon_patrolmode2 = 52,
	icon_roundcorner = 53,
	icon_editmodepatrol = 54,
	icon_dir_south = 55,
	icon_dir_southwest = 56,
	icon_dir_west = 57,
	icon_dir_northwest = 58,
	icon_dir_north = 59,
	icon_dir_northeast = 60,
	icon_dir_east = 61,
	icon_dir_southeast = 62,
	icon_num = 63
};

extern u8 flashalpha;
extern u8 quickflash;

int miscTextureGetNum(int miscTextureID);
void guiPreload();
void guiRestart();
void guiReset();
void guiFlashAlpha();
void guiAmountBarGfx(float amount, int basex, int basey, int width, int height, u32 fgcol, u32 bgcol, boolean flipped);
void guiDrawButton(int x, int y, e_button bt, boolean on);
void guiDrawBlueDPad(int x1, int y1, u32 upAlpha, u32 downAlpha, u32 leftAlpha, u32 rightAlpha);
void guiDrawBlueDPadButton(int x1, int y1, int x2, int y2, dpad_button bt, u32 alpha);
void guiDrawBlueButton(int x1, int y1, int x2, int y2, e_button bt, u32 alpha);
void guiDrawArrowRight(int x1, int y1, int x2, int y2, u32 rgba);
void guiDrawArrowLeft(int x1, int y1, int x2, int y2, u32 rgba);
void guiDrawArrowUp(int x1, int y1, int x2, int y2, u32 rgba);
void guiDrawArrowDown(int x1, int y1, int x2, int y2, u32 rgba);
void guiDrawCircle(int x1, int y1, int x2, int y2, u32 rgba);
int guiGetIconTexNum(int iconnum);
int guiGetIconWidth(int iconnum);
int guiGetIconHeight(int iconnum);
void guiDrawIcon(float x, float y, e_icon num, u32 colour);
void guiHGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2);
void guiVGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2);
void guiTriGradient(int x1, int y1, int x2, int y2, u32 col, u8 alpha1, u8 alpha2);
void guiDrawFormattedText(u8 *text, int basex, int basey, int basefont, int fgcol, int bgcol);
void guiDrawBox(int x, int y, int x2, int y2, u32 fgcol, u32 bgcol);
void guiDrawRoundBox(int x, int y, int x2, int y2, u32 bgcol, u32 fgcol);
void guiLoadingGfx(float scalar);

#endif // GAME_FRONT_GUI_H
