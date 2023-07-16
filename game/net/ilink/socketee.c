// STATUS: NOT STARTED

#include "socketee.h"

typedef struct {
	sceSifClientData cd_sceILsockInit;
	sceSifClientData cd_sceILsockReset;
	sceSifClientData cd_sceILsockOpen;
	sceSifClientData cd_sceILsockClose;
	sceSifClientData cd_sceILsockBind;
	sceSifClientData cd_sceILsockConnect;
	sceSifClientData cd_sceILsockSend;
	sceSifClientData cd_sceILsockRecvFrom;
	sceSifClientData cd_sce1394SbEui64;
} ILINK_SOCKET_SIF_MANAGER;

static int isInit = 0;
static int s_SendSemaID = -1;
static ILINK_SOCKET_SIF_MANAGER sif;
static int BufInit[4];
static int BufOpen[4];
static int BufClose[4];
static int BufBind[8];
static int BufCnct[8];
static int BufSend[128];
static int BufRcvF[128];
static int BufEui[4];

SceILsockErrorCode sceILsockInit(int maxsock, int maxsize) {
	SemaParam s;
	int i;
	int ret;
}

void sceILsockReset() {}

int sceILsockOpen(int domain, int type, int protocol) {
	int ret;
}

SceILsockErrorCode sceILsockClose(int sock) {
	int ret;
}

SceILsockErrorCode sceILsockBind(int sock, sceILsock_addr *name, int namelen) {
	int ret;
}

SceILsockErrorCode sceILsockConnect(int sock, sceILsock_addr *name, int namelen) {
	int ret;
}

int sceILsockSend(int sock, char *buf, int len, int flags) {
	int ret;
}

int sceILsockRecvFrom(int sock, char *buf, int len, int flags, sceILsock_addr *from, int *fromlen) {
	int ret;
	int fromlen2;
}

unsigned int sce1394SbEui64(unsigned int *buf) {
	int ret;
}
