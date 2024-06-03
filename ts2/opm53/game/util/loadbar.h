// STATUS: NOT STARTED

#ifndef GAME_UTIL_LOADBAR_H
#define GAME_UTIL_LOADBAR_H


void loadbarSetActive(boolean Active);
void loadbarSetAmount(float Amount);
void loadbarSetNextAmount(float Amount);
void loadbarSetAmountFileDone(float Amount);
void loadbarSetPos(int x, int y, int Width, int Height);
void loadbarSetStageScalar(int stage, float startscalar);
void loadbarStartStage(int stage);
void loadbarGfx();

#endif // GAME_UTIL_LOADBAR_H
