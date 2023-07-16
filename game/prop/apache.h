// STATUS: NOT STARTED

#ifndef GAME_PROP_APACHE_H
#define GAME_PROP_APACHE_H

extern float hoverpos[3];
extern float deathpos[5];
extern float riselocs[4][5];
extern float circlelocs[7][5];
extern float movevec[3];
extern float targetpos[3];
extern float gunrotate[3];
extern float randomvec[3];
extern float *target;
extern int soundhandle;
extern int soundstart;
extern int apachemode;
extern boolean apachelauncheron[4];
extern float accel;
extern float targetangle;
extern float speed;
extern int hangaroundf;
extern int rocketfiretime;
extern int nextrocketfire;
extern int gunfiretime;
extern int explosiontime;
extern int explosioncount;
extern float apachelauncherhealth[4];
extern int apachelaunchersactive;
extern int gunactive;
extern int gunchangetime;

void apachePropNew(prop *p);
void apacheDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void ApacheFireRockets(prop *p, float *playpos);
void ApacheGunTick(prop *p, float *playpos, player *play);
int apacheGetTargetPlayer(prop *p);
void copterPropTick(prop *p);

#endif // GAME_PROP_APACHE_H
