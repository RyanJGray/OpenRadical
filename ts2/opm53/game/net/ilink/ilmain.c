// STATUS: NOT STARTED

#include "ilmain.h"

typedef struct {
	u_int *pCurrent;
	u_long128 *pBase;
	u_long128 *pDmaTag;
	u_int pad03;
} sceDmaPacket;

typedef struct {
	u_int *pCurrent;
	u_long128 *pBase;
	u_long128 *pDmaTag;
	u_int *pVifCode;
	u_int numlen;
	u_int pad11;
	u_int pad12;
	u_int pad13;
} sceVif0Packet;

typedef struct {
	u_int *pCurrent;
	u_long128 *pBase;
	u_long128 *pDmaTag;
	u_int *pVifCode;
	u_int numlen;
	u_long *pGifTag;
	u_int pad12;
	u_int pad13;
} sceVif1Packet;

typedef struct {
	unsigned int data;
	unsigned int addr;
	unsigned int size;
	unsigned int mode;
} sceSifDmaData;

enum {
	PACKET_REQUESTCONNECT = -1,
	PACKET_ACCEPTCONNECT = -2,
	PACKET_AREYOUSTILLTHERE = -3,
	PACKET_YESIAMSTILLHERE = -4,
	PACKET_ARE_THERE_SERVERS = -5,
	PACKET_IM_A_SERVER = -6
};

static int pRxBuf = 0;
static int tRxBuf = 0;
static int nRxBuf = 0;
static int MyThID;
static int s_ReceiverThID;
static int sdBc;
static int sdTx[16];
static int sdRx;
static sceILsock_addr s_Connections[16];
static sceILsock_addr_t myeui64[2];
static int s_RxBuf[32][64];
static int s_RxBufSize[32];
static int s_RxBufFrom[32];
static int s_Connected[16];
static int s_RecvStillHere[16];
static float s_FramesSinceLastCheck[16];
static boolean s_AreThereServers;

void th_Receiver() {
	int fromlen;
	sceILsock_addr sender;
	int i;
	int TxData;
	boolean RejectRequest;
	int TxData;
	int ClientID;
	int TxData;
	int TxData;
}

boolean ilinkIsConnected(int ID) {}

void sceSocketPrepare() {
	int i;
	int ret;
	int retry;
	static ThreadParam pt;
	static char stack[8192];
	sceILsock_addr self;
	sceILsock_addr everyone;
}

void ilinkMake() {}

void ilinkInitialise() {
	sceILsock_addr_t MyGUID[2];
}

void ilinkDeinitialise() {
	int i;
}

boolean ilinkConnect() {
	int TxData;
}

void ilinkDoDisconnect(int ID) {}

void ilinkSendImAServer() {
	int TxData;
}

void ilinkAskForServers() {
	int TxData;
}

boolean ilinkAreThereAnyServers() {}

void ilinkTick() {
	static float LastTime = 0.f;
	float CurrentTime;
	float TimeGone;
	int i;
	int TxData;
}

boolean ilinkGetNextPacket(int *pFromID, char *pBuffer, int *pSize) {
	boolean Ret;
}

int ilinkSendPacket(int ToID, char *pBuffer, int Size, boolean Guarantee) {}
