// STATUS: NOT STARTED

#ifndef GAME_ENEMY_ENEMYARCADE_H
#define GAME_ENEMY_ENEMYARCADE_H

void enemyArcadeRestart();
void enemyArcadeReset();
void enemyArcadeSetup();
void enemyAttack(prop *p);
void enemyStorySetWait(chrdata *cd);
int enemyGetExitKneelAnim();
int enemyAimOverride(chrdata *cd);
void enemyAttackNewAnimseq(chrdata *cd, attackphase *ap, int phase);
void enemyStoryTestDestPosSetAnim(prop *p, int anim);
void enemyStoryAttack1(prop *p);
void enemyArcadeUpdateVisTable();
void enemyCheckBestWeapon(prop *p);
void enemyArm(prop *p);
void enemyGetHealth(prop *p);
void enemyGetArmour(prop *p);
prop* selectFavouriteWeaponPickup(prop *p, prop *excludegun);
prop* selectCloseWeaponPickup(prop *p, prop *excludegun);
boolean enemyShouldGetHealth(prop *p);
boolean enemyShouldGetArmour(prop *p);
int enemyAddDroppedGunToList(prop *pickup);
boolean enemyRemoveDroppedGunFromList(prop *pickup);

#endif // GAME_ENEMY_ENEMYARCADE_H
