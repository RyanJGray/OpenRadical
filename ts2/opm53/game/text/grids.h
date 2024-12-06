//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_TEXT_GRIDS_H
#define GAME_TEXT_GRIDS_H

typedef struct letter_extra {
	int leftshape;
	int rightshape;
	int offset;
} letterextra;

extern letterextra futurefontextra[96];
extern int futuregrid[121];
extern letterextra bookfontextra[96];
extern int bookgrid[121];
extern letterextra booklightfontextra[96];
extern int booklightgrid[121];


#endif // GAME_TEXT_GRIDS_H
