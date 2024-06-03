// STATUS: NOT STARTED

#ifndef GAME_LV_LV_H
#define GAME_LV_LV_H

extern int lvgamenum;
extern int lvlevelnum;
extern int lvnumplayers;

void lvRestartBefore();
void lvResetBefore();
void lvPreload();
void lvRestartAfter();
void lvResetAfter();
void lvEnd();
void lvTickBefore();
void lvTickAfter();
void lvTickView();
void lvTickPlayer();
void lvGfxPlayer();
void lvGfxAfter();

#endif // GAME_LV_LV_H
