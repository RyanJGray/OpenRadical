// STATUS: NOT STARTED

#ifndef GAME_TEXT_BOOKLIGHTFONT_H
#define GAME_TEXT_BOOKLIGHTFONT_H

struct letter_s {
	u16 l;
	u16 t;
	u16 r;
	u16 b;
	s8 yoffset;
};

typedef letter_s letter;
extern int booklightfontentries;
extern letter booklightfont[103];


#endif // GAME_TEXT_BOOKLIGHTFONT_H
