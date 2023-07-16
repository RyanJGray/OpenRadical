// STATUS: NOT STARTED

#ifndef GAME_TEXT_TEXT_H
#define GAME_TEXT_TEXT_H

struct fontsel_s {
	char *filename;
	int fontLoadFlags;
	letter *data;
	int height;
	int fixedwidth;
	int texnum;
};

typedef fontsel_s fontsel;

struct fontStyle_s {
	int fontSel;
	boolean fixedWidth;
	float scalex;
	float scaley;
	letterextra *extra;
	int *grid;
	int nonFixedExtraWidth;
};

typedef fontStyle_s fontStyle;

struct textSettings3D_s {
	float offsetx;
	float offsety;
	float factorx;
	float factory;
	float z;
};

typedef textSettings3D_s textSettings3D;

struct textfx_s {
	u32 rgba;
};

typedef textfx_s textfx;
extern int currentFontStyle;
extern fontsel *fontSelPtr;
extern fontStyle *fontStylePtr;
extern u8 ascii8to7[128];
extern u8 asciicaps[128];
extern int texnum_text_gfx[8];
extern int legacyfontflags;

boolean textShouldLoad(fontsel *fontSel);
void textPreload();
void textRestart();
void textReset();
void textEnd();
void textCalcScreenToWorldRelation(textSettings3D *settings, mtx_u *matrix, float z, float frustrumHalfWidth, float frustrumHalfHeight);
int textSelect(int fontStyle);
int textWidth(u8 *s);
int textHeight(u8 *s);
void textSize(int *width, int *height, u8 *s);
void textPrint(int *x, int *y, u8 *s, u32 colour);
void textNormalFade(int x, int y, u8 *s, u32 colour, int yFadeTopStart, int yFadeTopEnd, int yFadeBottomStart, int yFadeBottomEnd);
void textNormal(int x, int y, u8 *s, u32 colour);
void textOutline(int x, int y, u8 *s, u32 textcolour, u32 bordercolour);
void textOutlineFade(int x, int y, u8 *s, u32 textcolour, u32 bordercolour, int yFadeTopStart, int yFadeTopEnd, int yFadeBottomStart, int yFadeBottomEnd);
void textShadow(int x, int y, u8 *s, u32 textcolour, u32 shadowcolour);
void textRender3D(u8 *s, float *pos, mtx_u *screenMatrix, mtx_u *matrix, textSettings3D *settings, textfx *fx);
void textRender3DScr(u8 *s, int *x, int *y, mtx_u *matrix, textSettings3D *settings, textfx *fx);

#endif // GAME_TEXT_TEXT_H
