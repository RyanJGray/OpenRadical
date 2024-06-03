// STATUS: NOT STARTED

#ifndef GAME_PROP_REMOTE_H
#define GAME_PROP_REMOTE_H

void remoteGetStandPos(prop *pProp, float Angle, float *Pos);
float remoteGetStandAngle(prop *pProp, float *Pos);
void remotePropFixedGunTick(prop *p);
void remotePropAttachedTick(prop *p);
void remotePropTick(prop *p);
void remoteGunDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
void railBotDamage(prop *p, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed);
float* remoteGetPivoteOffset(prop *pProp);
float* remoteGetBarrelOffset(prop *pProp);
float* remoteGetShootPosOffset(prop *pProp);
void remoteGetPivotePos(prop *Prop, float *Pos);
void remoteGetLensePos(prop *Prop, float *Pos);
void remoteGetShootPos(prop *Prop, float *Pos);
void remoteGetBarrelRotPos(prop *Prop, float *Pos);
prop* remotePropNew(setupremote *sr, float *pos, float roty, int data1, int team);
void remotePropDrawBounds(prop *p);
void propRailBotTick(prop *p);
void propRailBotBossRoomTick(prop *p);

#endif // GAME_PROP_REMOTE_H
