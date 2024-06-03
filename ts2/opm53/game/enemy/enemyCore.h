// STATUS: NOT STARTED

#ifndef GAME_ENEMY_ENEMYCORE_H
#define GAME_ENEMY_ENEMYCORE_H


void enemyCoreReset();
void enemyCoreRestart();
void enemyCoreSetup();
void enemyCoreTickBefore();
void enemyCoreTick();
void enemyCoreTickAfter();
void enemyCoreSendMessage(int msg, int chr, int data);
void enemyCoreEnd();
int enemyCoreGetNumDropDefenders(int drop);
int enemyCoreGetNumDropTeamDefenders(int drop, int team);
int enemyCoreGetNumDropAttackers(int drop);
int enemyCoreGetNumDropTeamAttackers(int drop, int team);
int enemyCoreGetDropOwner(int drop);
int enemyCoreGetNumChrsAttackingChr(int c);

#endif // GAME_ENEMY_ENEMYCORE_H
