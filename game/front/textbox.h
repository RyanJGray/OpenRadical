// STATUS: NOT STARTED

#ifndef GAME_FRONT_TEXTBOX_H
#define GAME_FRONT_TEXTBOX_H

struct textbox_s {
	int left;
	int top;
	int width;
	int height;
	int numlines;
	int editwidth;
	int editpos;
	u8 *chartab;
	boolean done;
	boolean cancelled;
	int col;
	int row;
	u8 *string;
	int maxchars;
	u8 *edittitle;
};

typedef textbox_s textbox_t;
extern textbox_t *textbox;

void stringeditDraw(int playernum, boolean toppage);
void stringeditTick(int playernum);
void stringeditStart(int playernum, u8 *pstring, int maxlen, int numlines, int editwidth, int alignleft, int aligntop);
void stringeditSet(int playernum);

#endif // GAME_FRONT_TEXTBOX_H
