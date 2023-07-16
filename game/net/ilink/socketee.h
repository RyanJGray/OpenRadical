// STATUS: NOT STARTED

#ifndef GAME_NET_ILINK_SOCKETEE_H
#define GAME_NET_ILINK_SOCKETEE_H

typedef _sif_client_data sceSifClientData;
typedef short unsigned int sceILsock_port_t;

struct eui64 {
	sceILsock_addr_t eui64_hi;
	sceILsock_addr_t eui64_lo;
};

struct sceILsock_addr {
	unsigned char sock_len;
	unsigned char sock_family;
	sceILsock_port_t sock_port;
	eui64 sock_addr;
	char sock_zero[4];
};

enum SceILsockErrorCode {
	SCEILSOCKERR_OK = 0,
	SCEILSOCKERR_ERROR = -1,
	SCEILSOCKERR_NOT_INITIALIZED = -2000,
	SCEILSOCKERR_NOT_SUPPORTED = -2001,
	SCEILSOCKERR_NO_MEMORY = -2002,
	SCEILSOCKERR_RESOURCE_UNAVAILABLE = -2003,
	SCEILSOCKERR_INVALID_ID = -2004,
	SCEILSOCKERR_INVALID_REQUEST = -2005,
	SCEILSOCKERR_INVALID_ARGUMENT = -2006,
	SCEILSOCKERR_INVALID_SIZE = -2007,
	SCEILSOCKERR_INVALID_ADDRESS = -2008,
	SCEILSOCKERR_NO_SUCH_NODE = -2021
};


SceILsockErrorCode sceILsockInit(int maxsock, int maxsize);
void sceILsockReset();
int sceILsockOpen(int domain, int type, int protocol);
SceILsockErrorCode sceILsockClose(int sock);
SceILsockErrorCode sceILsockBind(int sock, sceILsock_addr *name, int namelen);
SceILsockErrorCode sceILsockConnect(int sock, sceILsock_addr *name, int namelen);
int sceILsockSend(int sock, char *buf, int len, int flags);
int sceILsockRecvFrom(int sock, char *buf, int len, int flags, sceILsock_addr *from, int *fromlen);
unsigned int sce1394SbEui64(unsigned int *buf);

#endif // GAME_NET_ILINK_SOCKETEE_H
