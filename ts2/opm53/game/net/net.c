//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "net.h"
#include "game/game.h"
#include "limits.h"
#include "net/ilink/ilmain.h"
#include "prop/prop.h"

enum {
  PACKET_I_AM_DISCONNECTING = 0,
  PACKET_REQUEST_JOIN_GAME_DATA = 1,
  PACKET_ACCEPT_JOIN_GAME_DATA = 2,
  PACKET_REJECT_JOIN_GAME_DATA = 3,
  PACKET_GAMEPARAMS_DATA = 4,
  PACKET_SIGNON_DATA = 5,
  PACKET_DODISCONNECT_DATA = 6,
  PACKET_REQUESTCURRENTGAMESTATE_DATA = 7,
  PACKET_CURRENTGAMESTATE_DATA = 8,
  PACKET_LEVELQUIT_DATA = 9,
  PACKET_MARKER_INGAME_PACKETS_START_HERE = 10,
  PACKET_CLIENT_GAME_DATA = 11,
  PACKET_SERVER_GAME_DATA = 12,
  PACKET_PLAYERPREFS_DATA = 13,
  PACKET_PROPDAMAGE_DATA = 14,
  PACKET_REQUESTPROPDAMAGE_DATA = 15,
  PACKET_PROPKILLCHR_DATA = 16,
  PACKET_REQUESTPROPKILLCHR_DATA = 17,
  PACKET_PROPPICKUP_DATA = 18,
  PACKET_REQUESTPROPPICKUP_DATA = 19,
  PACKET_PROPDROP_DATA = 20,
  PACKET_MAKEPROPVISIBLE_DATA = 21,
  PACKET_RESPAWN_DATA = 22,
  PACKET_REQUESTRESPAWN_DATA = 23,
  PACKET_ENEMYRESPAWN_DATA = 24,
  PACKET_REQUESTENEMYRESPAWN_DATA = 25,
  PACKET_UPDATESCORE_DATA = 26,
  PACKET_SPAWNKNOCKOUTBAG_DATA = 27,
  PACKET_AICHR_DATA = 28
};

enum {
  NET_STATE_NONE = 0,
  NET_STATE_WAITINGCONNECTION = 1,
  NET_STATE_WAITINGINITDATA = 2,
  NET_STATE_WAITINGGAMESTART = 3,
  NET_STATE_WAITINGCURRENTGAMESTATE = 4,
  NET_STATE_INGAME = 5
};

enum { NETGAME_NONE = 0, NETGAME_SERVER = 1, NETGAME_CLIENT = 2 };

enum { NETGAMETYPE_NONE = 0, NETGAMETYPE_ILINK = 1, NETGAMETYPE_INET = 2 };

static int s_NumClientIDsUsed = 0;
static int s_ForceUsePadNum = -1;
static int s_ForceCreatePropIndex = -1;
static int sf = -1;
static int s = 0;
static int ds = 0;
static float dss = 0.f;
static int r = 0;
static int dr = 0;
static float drs = 0.f;
static int sec = 0;
static int total = 0;
static int wrong = 0;
static int wrongcheck = 0;
boolean UseNetPads = 0;

resetgameparms NetGameParms = {0};

static int s_LastPlayerRecvFrame[16];
static int s_LastPlayerSendFrame[16];
static boolean s_IsNetGame;
static u8 s_PadData[16][6];
static boolean s_PadDataChanged[16];
static u8 s_LastSentPlayerPrefs[4][230];
static int s_MyClientID;
static int s_ClientNetPads[16][4];
static boolean s_ClientIDUsed[16];
static boolean s_GotSignon[16];
static boolean s_SentCurrentGameState[16];
static boolean s_GotGameParams;
static int s_NumLocalPlayers;
static int s_NetGameServerClient;
static int s_NetGameType;
static int s_ClientShouldNotProcess;
static int s_ClientStartID;
static int s_ProcessRequestPropKillChr;
static int s_ProcessRequestPropDamage;
static int s_ProcessRequestRespawn;
static int s_ProcessRequestEnemyRespawn;
static int s_ProcessRequestPickup;
static int s_ProcessRequestEnemyFire;
static int s_ProcessRequestLevelQuit;
static boolean s_DoNetDeinitialse;
static s8 s_EnemyFireData[10][3];
static int s_LastSentScoresFrame[16];
static int s_NetState;

int netGetForceUsePadNum() {}

/**
 * @brief Unsure?
 *
 * @return int the index of the prop to force create
 */
int netGetForceCreatePropIndex() { return s_ForceCreatePropIndex; }

/**
 * @brief Is the current game a network game?
 *
 * @return boolean true if a network game
 * @return boolean false if not a network game
 */
boolean netIsNetGame() { return s_IsNetGame; }

boolean netIsNetGameServer() {}

boolean netIsNetGameClient() {}

boolean netGameServerClient() {}

int netGetNumLocalPlayers() {}

int netGetNumLocalPlayersFrontEnd() {}

void netSetNumLocalPlayers(int NumPlayers) {}

int netGetGPlayerFromLPlayer(int LocalPlayer) {}

int netGetGPlayerFromLPlayerFrontEnd(int LocalPlayer) {}

int netGetMyClientID() {}

int netGetNumPlayersConnected() {
  int Num;
  int i;
  int j;
}

boolean netGotPlayerSignon(int Player) {}

void netRestart() {}

void netReset() {}

void netMake() {}

static void netAddPlayerDataToBuff(u8 **pBuff, int ClientID, int PlayerID) {
  u8 *pBuffer;
  player *pPlayer;
  u8 *pPlayerID;
  int ID;
  chrdata *pData;
  float Data;
  float Data;
  float Data;
  float Angle;
  s16 Data;
  float Angle;
  s16 Data;
  u8 Data;
  u8 Data;
}

static int netRemovePlayerDataFromBuff(u8 **pBuff) {
  u8 PlayerID;
  player *pPlayer;
  chrdata *pData;
  u8 **pBuff;
  u8 Data;
  u8 **pBuff;
  float Data;
  u8 **pBuff;
  float Data;
  u8 **pBuff;
  float Data;
  u8 **pBuff;
  s16 Data;
  u8 **pBuff;
  s16 Data;
  u8 **pBuff;
  u8 Data;
  u8 **pBuff;
  u8 Data;
}

static void netServerDecodeClientGameData(int FromID, u8 *pBuffer) {
  int i;
  u8 NumPlayers;
  u8 Data;
}

static void netClientDecodeServerGameData(u8 *pBuffer) {
  int i;
  u8 NumPlayers;
  u8 Data;
}

void netNonLocalEnemyFire(prop *p) {
  chrdata *pData;
  int Enemy;
  chrgun *cgun;
}

boolean netIsAIChrLocal(prop *p) { int Enemy; }

boolean netSendEnemyFire(prop *p, int hand, int fireMode, int repeatMode) {
  int Enemy;
}

static void netDecodeAIChr(u8 *pBuffer) {
  int Chr;
  chrdata *pData;
  prop *pProp;
  obinst *pInst;
  int Enemy;
  u8 Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  s16 Data;
  u32 Data;
  u32 Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u16 Data;
  u16 Data;
  float Data;
  float Data;
  float Data;
}

static void netSendAIChr(int Chr) {
  u8 Buffer[256];
  u8 *pBuffer;
  chrdata *pData;
  prop *pProp;
  obinst *pInst;
  int Enemy;
  u8 Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  float Angle;
  s16 Data;
  u32 Data;
  u32 Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u32 Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u16 Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
}

static void netPreprocessPlayers() {
  int i;
  u8 Buffer[6];
}

static void netSendServerGameData() {
  int Client;
  int i;
  u8 Buffer[256];
  u8 *pBuffer;
  u8 *pNumPlayers;
  u8 NumPlayersAdd;
  int j;
}

static void netSendClientGameData() {
  int i;
  u8 Buffer[256];
  u8 *pBuffer;
  u8 *pNumPlayers;
  u8 NumPlayersAdd;
}

static void netDecodePlayerPrefsData(u8 *pBuffer) {
  int Player;
  int i;
  u8 Data;
  u8 Data;
}

void netSendPlayerPrefsData(int Player) {
  u8 Buffer[256];
  u8 *pBuffer;
  int PlayerID;
  u8 *pData;
  int i;
  u8 Data;
  u8 Data;
}

static boolean netDecodePropDamage(int FromID, u8 *pBuffer, int PacketType,
                                   int Size) {
  prop *target;
  prop *attacker;
  float amount;
  int bullettype;
  float hitpos[3];
  float *phitpos;
  float bulletnorm[3];
  float *pbulletnorm;
  float bulletspeed;
  bullet Bullet;
  bullet *pBullet;
  int Flags;
  int deathflag;
  int Life;
  u8 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  float Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u16 Data;
}

boolean netSendPropDamage(prop *target, prop *attacker, float amount,
                          int bullettype, float *hitpos, float *bulletnorm,
                          float bulletspeed, bullet *b, int deathflag) {
  u8 Buffer[256];
  u8 *pBuffer;
  u8 Flags;
  u8 Data;
  u16 Data;
  u16 Data;
  float Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u16 Data;
}

static boolean netDecodePropKillChr(int FromID, u8 *pBuffer, int PacketType,
                                    int Size) {
  prop *target;
  prop *attacker;
  int bullettype;
  float hitpos[3];
  float *phitpos;
  float bulletnorm[3];
  float *pbulletnorm;
  float bulletspeed;
  int deathflag;
  int Life;
  u8 Flags;
  int parthit;
  u8 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u16 Data;
}

boolean netSendPropKillChr(prop *target, prop *attacker, int bullettype,
                           float *hitpos, float *bulletnorm, float bulletspeed,
                           int parthit, int deathflag) {
  u8 Buffer[256];
  u8 *pBuffer;
  u8 Flags;
  u8 Data;
  u16 Data;
  u16 Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u8 Data;
  u8 Data;
  u16 Data;
}

static boolean netDecodeRespawn(int FromID, u8 *pBuffer, int PacketType,
                                int Size) {
  player *pPlayer;
  u8 Data;
  u16 Data;
  u16 Data;
  u32 Data;
}

boolean netShouldProcessRespawn(player *p) {}

boolean netSendRespawn(player *p) {
  u8 Buffer[256];
  u8 *pBuffer;
  int Seed;
  u8 Data;
  u16 Data;
  u16 Data;
  u32 Data;
}

static boolean netDecodeEnemyRespawn(int FromID, u8 *pBuffer, int PacketType,
                                     int Size) {
  chrdata *chr;
  u8 Data;
  u16 Data;
  u32 Data;
}

boolean netSendEnemyRespawn(chrdata *chr) {
  u8 Buffer[256];
  u8 *pBuffer;
  int Seed;
  u8 Data;
  u16 Data;
  u32 Data;
}

static boolean netDecodePropPickup(int FromID, u8 *pBuffer, int PacketType,
                                   int Size) {
  int PickupID;
  int ChrID;
  prop *pPickup;
  prop *pChrProp;
  pickupdata Data;
  prop Prop;
  u16 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u32 Data;
  float Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  pickupdata *pData;
}

boolean netShouldProcessPickup(prop *pPickup, prop *pChrProp) {
  pickupdata *pData;
}

boolean netSendPropPickup(prop *pPickup, prop *pChrProp) {
  pickupdata *pData;
  u8 Buffer[256];
  u16 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u32 Data;
  float Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
}

static void netDecodePropDrop(u8 *pBuffer) {
  int Type;
  prop Prop;
  prop *pProp;
  chrdata cd;
  chrdata *pcd;
  chrgun cgun;
  chrgun *pcgun;
  int chrindex;
  obinst Inst;
  prop Attach;
  u8 Data;
  u8 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u8 Data;
  u8 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u8 Data;
  u16 Data;
  u16 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u16 Data;
}

void netSendPropDrop(prop *pProp, prop *pAttach, int AttachMatrix, chrdata *cd,
                     chrgun *cgun, prop *droppedProp, int destpad) {
  u8 Buffer[256];
  u8 *pBuffer;
  u8 Data;
  u8 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u8 Data;
  u8 Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u8 Data;
  u8 Data;
  u16 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u16 Data;
}

/**
 * @brief Decodes a "Make Prop Visible" network message.
 *
 * @param pBuffer the network packet to decode
 */
static void netDecodeMakePropVisible(u8 *pBuffer) {
  // u16 Data; // Unused temporary from inlined packet buffer access logic in
  // net.h.

  prop *pickup = propGetPropPtr((int)*pBuffer);
  s_ClientShouldNotProcess = FALSE;
  propMakeVisible(pickup);
  s_ClientShouldNotProcess = TRUE;

  return;
}

/**
 * @brief Transmits a "Make Prop Visible" network message.
 *
 * @param pProp the prop object to make visible
 */
void netSendMakePropVisible(prop *pProp) {
  u8 Buffer[256];
  u16 Data;

  if ((netIsNetGame() != FALSE) && (s_NetGameServerClient == NETGAME_SERVER)) {
    Data = (u16)propGetPropIndex(pProp);
    Buffer[6] = Data;
    Buffer[7] = (Data >> 8);

    netSendPacket(s_MyClientID, PACKET_MAKEPROPVISIBLE_DATA, (char *)Buffer, 8,
                  TRUE);
  }

  return;
}

/**
 * @brief Decodes a "Spawn Knock Out Bag" network message.
 *
 * @param pBuffer the network packet to decode
 */
static void netDecodeSpawnKnockOutBag(u8 *pBuffer) {
  // u16 Data; // Unused temporary from inlined packet buffer access logic in
  // net.h.

  s_ClientShouldNotProcess = FALSE;
  s_ForceCreatePropIndex = (int)*(pBuffer + 3);
  gmSpawnKnockOutBag((int)*pBuffer, (int)*(pBuffer + 1));
  s_ClientShouldNotProcess = TRUE;
  s_ForceCreatePropIndex = PROP_NULL;

  return;
}

void netSendSpawnKnockOutBag(int ghostbagnum, int padnum, prop *p) {
  u8 Buffer[256];
  u8 Data;
  u16 Data;
  u16 Data;
}

static void netDecodeUpdateScores(u8 *pBuffer) {
  int i;
  chrdata *cd;
  int j;
  u8 Data;
  u32 Data;
  u32 Data;
  u16 Data;
}

static void netUpdateScores() {
  int i;
  u8 Buffer[256];
  u8 *pBuffer;
  chrdata *cd;
  int j;
  u8 Data;
  u32 Data;
  u32 Data;
  u16 Data;
}

static void netDecodeDoDisconnect(u8 *pBuffer) { u8 Data; }

static void netSendDoDisconnect(int ID) {
  u8 Buffer[256];
  u8 Data;
}

static void netSendIAmDisconnecting() {
  u8 Buffer[256];
  u8 *pBuffer;
}

static void netDecodeGameParams(u8 *pBuffer) {
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u8 Data;
}

static void netDecodeSignonData(int FromID, u8 *pBuffer) {
  int ClientID;
  int LocalPlayer;
  int Player;
  char Name[31];
  int SignonNum;
  u8 Data;
  u8 Data;
  u8 Data;
  void *pData;
  void *pData;
}

static void netSendSignonData(int ToID, int ClientID, int LocalPlayer) {
  u8 Buffer[256];
  int Player;
  u8 Data;
  u8 Data;
  u8 Data;
  void *pData;
}

static void netSendGameParams(int ToID) {
  u8 Buffer[256];
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u8 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u32 Data;
  u8 Data;
}

void netServerStartGame() { int i; }

static void netDecodeCurrentGameState(u8 *pBuffer) {
  int ID;
  u8 Data;
  int i;
  u16 Data;
  player *pPlayer;
  boolean Dead;
  u8 Data;
  float Data;
  float Data;
  float Data;
  s16 Data;
  s16 Data;
  u8 Data;
  prop *pProp;
  pickupdata *pData;
  prop *pAttach;
  u32 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u16 Data;
}

static void netDecodeRequestCurrentGameState(int FromID, u8 *pBufferIn) {
  u8 Buffer[256];
  u8 *pBuffer;
  int i;
  u8 *pLastPart;
  player *pPlayer;
  u16 Data;
  u8 Data;
  float Data;
  float Data;
  float Data;
  float Angle;
  s16 Data;
  float Angle;
  s16 Data;
  u8 Data;
  u16 Data;
  prop *pStart;
  prop *pProp;
  pickupdata *pData;
  u16 Data;
  u32 Data;
  u32 Data;
  float Data;
  float Data;
  float Data;
  u16 Data;
  u16 Data;
  u16 Data;
  u16 Data;
}

static void netRequestCurrentGameState() {
  u8 Buffer[256];
  u8 *pBuffer;
}

boolean netGotInitData() { int i; }

void netReadyToStart() {
  int i;
  player *pPlayer;
}

static void netDecodeAcceptJoinGame(u8 *pBuffer) {
  int i;
  int SignonNum[4];
  u8 Data;
  u8 Data;
}

void netSendMySignons() { int i; }

static void netDecodeRejectJoinGame(u8 *pBuffer) {}

static void netDecodeRequestJoinGame(int FromID, u8 *pBuffer) {
  int PlayersWanted;
  int i;
  int j;
  u8 Data;
  u8 Buffer[256];
  u8 *pBuffer;
  boolean Used[16];
  int CurrentPlayer;
  boolean Accept;
  int MaxPlayers;
  u8 Data;
  u8 Data;
}

static void netRequestJoinGame() {
  u8 Buffer[256];
  u8 Data;
}

/**
 * @brief Decodes a "Level Quit" network message.
 *
 */
static void netDecodeLevelQuit() {
  s_ProcessRequestLevelQuit = TRUE;
  gameLevelQuit();
  s_ProcessRequestLevelQuit = FALSE;

  return;
}

/**
 * @brief Transmits a "Level Quit" network message.
 *
 */
static void netSendLevelQuit() {
  u8 Buffer[MAX_PACKET_BYTES];
  u8 *pBuffer = &Buffer;

  netSendPacket(s_MyClientID, PACKET_LEVELQUIT_DATA, *pBuffer, 6, TRUE);

  return;
}

static u32 netGetCheckSum(u8 *pBuffer, int Size) {
  int i;
  u32 Ret;
}

static void netDecodePacketData(int FromID, u8 *pBuffer, int Size) {
  u8 *pOrig;
  int PacketType;
  int CorrectSize;
  u32 Check;
  u32 Check1;
  u8 Data;
  u8 Data;
  u32 Data;
}

static void netDoDisconnect(int ID) {
  int i;
  int Signon;
  int SwapID;
  int SwapIndex;
  int j;
  int k;
  player *pPlayer;
  player *pSwap;
  player tmp;
  player *pPlayer;
}

static boolean netIsConnected(int ID) {}

void netTick() {
  static int LastFrameSent = 0;
  int CurrentFrame;
  int i;
  u8 PadData[6];
}

void netSetClientServer(int ClientServer) { int i; }

static void netInitialiseGameData() {}

void netInitialise() { int i; }

void netDeinitialise() {
  int SignonNum[4];
  int i;
  int j;
}

void netLevelQuit() {}

/**
 * @brief Connect to a server on the network (not implemented?).
 * 
 * @return boolean true if the connection was successful
 * @return boolean false if the connection has not yet completed
 */
boolean netConnect() {
  static float Frame = 0.f;
  static float LastTime = 0.f;
  float CurrentTime = timeGet();
  float CycleTime = CurrentTime - LastTime;
  LastTime = CurrentTime;
  for (; CycleTime < 0.f; CycleTime += 128.f) {
  }

  Frame += CycleTime;
  if (60.f < Frame) {
    Frame = 0.f;
  }

  return (boolean)(s_NetState != NET_STATE_WAITINGCONNECTION);
}

/**
 * @brief Did we get connected to the server?
 * 
 * @return boolean true if we got connected
 * @return boolean false if we didn't get connected
 */
boolean netGotConnection() {
  return (boolean)(s_NetState != NET_STATE_WAITINGCONNECTION);
}

/**
 * @brief Are there any servers available via the network (not implemented?) or i.LINK?
 *
 * @return boolean true if there are servers
 * @return boolean false if there are no servers
 */
boolean netAreThereServers() {
  static float Frame = 0.f;
  static float LastTime = 0.f;
  boolean Ret;

  if ((netIsNetGameClient() == FALSE) || (s_NetGameType != NETGAMETYPE_ILINK)) {
    if (netIsNetGame() != FALSE) {
      float CurrentTime = timeGet();
      float CycleTime;
      // Burns cycles waiting the network search to complete?
      for (CycleTime = CurrentTime - LastTime; CycleTime < 0.f;
           CycleTime += 128.f) {
      }

      Frame += CycleTime;
      LastTime = CurrentTime;

      if (60.f < Frame) {
        Frame = 0.f;
      }
    }

    Ret = FALSE;
  } else {
    Ret = ilinkAreThereAnyServers();
  }

  return Ret;
}

/**
 * @brief Whether or not game code should process a game event.
 *
 * @return boolean true if the event should not be processed
 * @return boolean false if the event should be processed
 */
boolean netShouldNotProcess() {
  boolean Ret;

  if ((netIsNetGame() == FALSE) || (s_NetGameServerClient == NETGAME_SERVER)) {
    s_ClientShouldNotProcess = FALSE;
  } else {
    s_ClientShouldNotProcess = TRUE;
  }

  Ret = s_ClientShouldNotProcess;

  return Ret;
}

int netGetFreeClientID() { int i; }

boolean netIsClientIDUsed(int ID) {}

void netClaimClientID(int ID) {}

void netReleaseClientID(int ID) {}

int netSendPacketTo(int ToID, int PacketType, char *pBufferSend, int Size,
                    boolean Guarantee) {
  u32 Check;
  u8 Data;
  u8 Data;
  u32 Data;
}

/**
 * @brief Transmits a packet across the network.
 *
 * @param FromID
 * @param PacketType
 * @param pBuffer
 * @param Size
 * @param Guarantee
 */
void netSendPacket(int FromID, int PacketType, char *pBuffer, int Size,
                   boolean Guarantee) {
  int ToID;

  if (netIsNetGame() != FALSE) {
  }
}

static boolean netWillSendLocal(prop *pProp) {}

boolean netSendIfLocal(prop *pProp, int PacketTypeServer, int PacketTypeClient,
                       char *pBuffer, int Size, boolean Guarantee) {}

void netPlayerTick() {
  float SavePos[3];
  float Dir[3];
  float MaxDist;
  float Scale;
}
