// STATUS: NOT STARTED

#ifndef GAME_PROP_DAMAGE_H
#define GAME_PROP_DAMAGE_H

struct damageInfo_s {
	float characterDamageStory[3][3];
	float characterDamageArcade[3];
	float backgroundDamage;
	float glassDamage;
	float obDamage;
};

typedef damageInfo_s damageInfo;
extern damageInfo damageInfos[15];

void propKillChrNoBullet(prop *target);
void propKillChr(prop *target, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, int parthit, int deathflag);
float propGetChrDamageAmountFromType(prop *target, int damageType, int bullettype);
void propDamageType(prop *target, prop *attacker, int damageType, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag);
void propDamageAmount(prop *target, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag);
void propExplosionDamage(prop *hitprop, prop *bulletowner, int bullettype, float *pos, float time, float explosionDamageFactor, float explosionDamageDist);
float propDamageGetBackgroundDamage(int damageType);
float propDamageGetGlassDamage(int damageType);
float propDamageGetObDamage(int damageType);
float damageGetPlayerMaxHealth();
float damageGetEnemyMaxHealth();
float damageGetPlayerMaxArmour();
float damageGetEnemyMaxArmour();

#endif // GAME_PROP_DAMAGE_H
