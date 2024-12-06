//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#ifndef GAME_NET_NET_H
#define GAME_NET_NET_H

#include "chr/chr.h"
#include "common.h"
#include "game/game.h"
#include "player/player.h"
#include "prop/prop.h"

extern boolean UseNetPads;
extern resetgameparms NetGameParms;

int netGetForceUsePadNum();
int netGetForceCreatePropIndex();
boolean netIsNetGame();
boolean netIsNetGameServer();
boolean netIsNetGameClient();
boolean netGameServerClient();
int netGetNumLocalPlayers();
int netGetNumLocalPlayersFrontEnd();
void netSetNumLocalPlayers(int NumPlayers);
int netGetGPlayerFromLPlayer(int LocalPlayer);
int netGetGPlayerFromLPlayerFrontEnd(int LocalPlayer);
int netGetMyClientID();
int netGetNumPlayersConnected();
boolean netGotPlayerSignon(int Player);
void netRestart();
void netReset();
void netMake();
void netNonLocalEnemyFire(prop *p);
boolean netIsAIChrLocal(prop *p);
boolean netSendEnemyFire(prop *p, int hand, int fireMode, int repeatMode);
void netSendPlayerPrefsData(int Player);
boolean netSendPropDamage(prop *target, prop *attacker, float amount, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, bullet *b, int deathflag);
boolean netSendPropKillChr(prop *target, prop *attacker, int bullettype, float *hitpos, float *bulletnorm, float bulletspeed, int parthit, int deathflag);
boolean netShouldProcessRespawn(player *p);
boolean netSendRespawn(player *p);
boolean netSendEnemyRespawn(chrdata *chr);
boolean netShouldProcessPickup(prop *pPickup, prop *pChrProp);
boolean netSendPropPickup(prop *pPickup, prop *pChrProp);
void netSendPropDrop(prop *pProp, prop *pAttach, int AttachMatrix, chrdata *cd, chrgun *cgun, prop *droppedProp, int destpad);
void netSendMakePropVisible(prop *pProp);
void netSendSpawnKnockOutBag(int ghostbagnum, int padnum, prop *p);
void netServerStartGame();
boolean netGotInitData();
void netReadyToStart();
void netSendMySignons();
void netTick();
void netSetClientServer(int ClientServer);
void netInitialise();
void netDeinitialise();
void netLevelQuit();
boolean netConnect();
boolean netGotConnection();
boolean netAreThereServers();
boolean netShouldNotProcess();
int netGetFreeClientID();
boolean netIsClientIDUsed(int ID);
void netClaimClientID(int ID);
void netReleaseClientID(int ID);
int netSendPacketTo(int ToID, int PacketType, char *pBufferSend, int Size, boolean Guarantee);
void netSendPacket(int FromID, int PacketType, char *pBuffer, int Size, boolean Guarantee);
boolean netSendIfLocal(prop *pProp, int PacketTypeServer, int PacketTypeClient, char *pBuffer, int Size, boolean Guarantee);
void netPlayerTick();

#endif // GAME_NET_NET_H
