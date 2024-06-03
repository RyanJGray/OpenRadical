// STATUS: NOT STARTED

#ifndef GAME_PROP_CORPSE_H
#define GAME_PROP_CORPSE_H

void corpsePropTick(prop *p);
void propEvictCorpse(prop *p);
void propDeleteCorpse(prop *p);
prop_s* propNewCorpse(prop *original);

#endif // GAME_PROP_CORPSE_H
