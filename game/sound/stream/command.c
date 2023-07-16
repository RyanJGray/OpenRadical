//
// The OpenTS2 Project
// 2023
//

#include <kernel.h>
#include <sif.h>
#include <sifcmd.h>
#include <sifrpc.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef long unsigned int u64;

typedef struct {
  int File;
  int StartOffset;
  void *pBuffer;
  int Amount;
  int LoadID;
  void (*pCallBack)(/* parameters unknown */);
} BackLoadInfo;

// warning: multiple differing types with the same name (#1,  not equal)
enum { BACKGROUNDLOAD_STATUS_IDLE = 0, BACKGROUNDLOAD_STATUS_LOADING = 1 };

typedef struct {
  int Status;
  int AmountRead;
  int QueueRead;
  int QueueWrite;
  BackLoadInfo Queue[32];
} BackgroundLoader;

typedef struct {
  int fd;
  u32 filepos;
  u32 filesize;
  u32 bufpos[2];
  u32 bufsize[2];
  u32 bufleft[2];
  u32 sbuf[2];
  int voice[2];
  int DoingLoad;
  int EndLoadID;
  int ReadError;
} streaminfo;

// warning: multiple differing types with the same name (#1,  not equal)
enum { DO_TRANSLEFT = 0, DO_TRANSRIGHT = 1, DO_WAITIRQ = 2 };

static int stream_tid = 928;
static int stream_sid = 944;
static int stream_volumeset = 1380319489;
static int stream_preloadstart = 1951620932;
static int stream_start = 1835099506;
static int stream_stop = 1769096287;
static int stream_stopclose = 7497078;
static int stream_status = 201329200;
int trans_stat = 0;
int ret = 1006764032;
static BackgroundLoader BackgroundLoad;
static streaminfo stream;
static int stream_readbuf[2];
static int stream_curaddr[2];
static u32 stream_volume;
static int rpc_arg[16];

static void BackgroundLoadInitialise() {}

static void StartBackgroundLoad(int LoadID, int File, int StartOffset,
                                void *pBuffer, int Amount,
                                void (*pCallBack)(/* parameters unknown */)) {}

static void BackgroundLoadTick() {
  BackLoadInfo *pInfo;
  // BackLoadInfo *pInfo;
  int AmountToRead;
  int Result;
}

static void BackgroundLoadStop() {}

static void StreamLoadFinishedCallBack(int LoadID, int ReadResult) {}

static void StreamMake(int no_ch, int status) {}

static int StreamInit(int allocsize) {
  struct SemaParam sem;
  struct ThreadParam param;
}

static void StreamQuit() {}

static int StreamOpen(char *filename) {}

static int StreamRead(u8 *pLeft, u8 *pRight, int len, int BackgroundLoad) {
  int LoadID;
  int len1;
}

static void StreamClose() {}

static int StreamPreLoad(int seekpos) {}

static int StreamPreLoadStart() { int ret; }

static int StreamStart() { int ret; }

static int StreamStop() {}

static int StreamStopClose() {}

static void StreamSetVoice(int ch, u32 vnum) {}

static void StreamSetVolume(int no_ch, u32 vol) {}

static void StreamSetVolumeDirect(u32 vol) {}

static u32 StreamGetStatus() {}

static int StreamDmaInt(void *common) {}

static void *StreamSpu2Int() {}

static int StreamPlay(int status) {
  int buf_side;
  int count;
}

static void *dispatch(u32 command, void *dataptr, int size) {
  int ch;
  int data;
  u32 dataU;
}

int stream_loop() {
  sceSifQueueData qd;
  sceSifServeData sd;

  CpuEnableIntr();
  EnableIntr(0x24); // IOP_IRQ_DMA_SPU
  EnableIntr(0x28); // IOP_IRQ_DMA_SPU2
  EnableIntr(9); // IOP_IRQ_SPU
  sceSifInitRpc(0);

  sceSifSetRpcQueue(&qd, GetThreadId());
  sceSifRegisterRpc(&sd, 0x534a4521, dispatch, &rpc_arg, NULL, NULL, &qd);
  
  printf("goto stream cmd loop\n");
  sceSifRpcLoop(&qd);
  
  return 0;
}
