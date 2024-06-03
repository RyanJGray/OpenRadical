// STATUS: NOT STARTED

#ifndef GAME_VIEW_VIEW_H
#define GAME_VIEW_VIEW_H

extern float view_campos[3];
extern float view_camdir[3];
extern float view_angx;
extern float view_angy;
extern mtx_u *viewmatrix;

void viewTick();

#endif // GAME_VIEW_VIEW_H
