//
// The OpenRadical Project
// 2024 - A project by Ryan J. Gray
// TS2 OPM53 Tree
//

#include "boss.h"

typedef struct dbufinfo_s {
  boolean gsReadyToSend;
  boolean gsSending;
  boolean gsFinishedSending;
  int cpuStartFrame;
  int cpuCreateFrame;
} dbufinfo;

static dbufinfo dbinfo[2];

static dlDmaTag *dmalists[2] = {
    /* [0] = */ 0x100000,
    /* [1] = */ 0x180000};

int curcpudmabuf = 0;
int curgsdmabuf = 0;
int ucodevtxs = 0;
int ucodetris = 0;
int fxtris = 0;
int bgtris = 0;
int bgcurtris = 0;
int ucodecycles = 0;
int bgroomsdrawn = 0;
int gsstart_sid = -1;
int gsdone_sid = -1;
int bufffree_sid = -1;
int gsavail_sid = -1;
int cpu_tid = -1;
int gs_tid = -1;
int gsdone = 1;
int cpudone = 0;

char **languages[0] = {};

int cur_language = 0;
int dvd = 0;
int timeout_inactive = 99999;
int playrollingdemo = 0;
int displayallfileops = 1;
int restart = 0;
int maxdmalistlen = 0;
int numdmafail = 0;
int lastfrbuf = 0;
static u32 alarm_activated = 0;

static u8 *defaultargs[0] = {};

int bosscammode = 0;
int bosscampropnum = 0;
int numglowsdrawn = 0;
int glowpixels = 0;

u8 scratchbuffer[133120] = {0};

dlDmaTag *gfxtag = NULL;
static u8 membuffer[27904000];
static u8 cpustack[131072];
static u8 gsstack[65536];
int lvend = 0;
sceDmaChan *dmaVif1 = NULL;
sceDmaChan *dmaSpr = NULL;
int myargc = 0;
char **myargv = NULL;
static int parmfound;

resetgameparms bossgameparms;

sceGsDBuff db;

float gsStartTime[5] = {0.f};

int gsStartFrame[5] = {0};

float gsEndTime[5] = {0.f};

u_long128 base_ptr[10] = {VECTOR(0, 0, 0, 0)};

int bossCheckParm(char *check) {
  int i = 1;

  if (1 < myargc) {
    do {
      int comparison = strcasecmp(check, myargv[i]);
      if (comparison == 0) {
        parmfound = i;
        return i;
      }

      i++;
    } while (i < myargc);
  }

  parmfound = 0;
  return 0;
}

boolean bossIsNextParm() {
  boolean hasNextParm = FALSE;

  if ((parmfound > 0) && (parmfound + 1 < myargc)) {
    hasNextParm = *myargv[parmfound + 1] != '-';
  }

  return hasNextParm;
}

char *bossGetNextParm() {
  char *nextParm;

  if (bossIsNextParm() == FALSE) {
    nextParm = NULL;
  } else {
    parmfound++;
    nextParm = myargv[parmfound];
  }

  return nextParm;
}

static void bossMakeAll() {
  bossMake();
  trigMake();
  memMake(membuffer, (int)(membuffer + 0x163de00));
  packfileMake();
  profileMake();
  windowMake();
  joyMake();
  mouseMake();
  soundMake();
  musicMake();
  mcardMake();
  mcseqMake();
  emMake();
  zbtestMake();
  netMake();
  cheatsMake();
  signonMake();
  frontmpgMake();
  mapmakerMake();

  return;
}

static void sjeGsSetDefDBuff(int psm, int w, int h, int zcmp, int zpsm,
                             int zclear, int dither) {}

static void sjeGsSetHalfOffset(int context, int off) {
  sceGsDrawEnv1 *drawEnv;

  if (context == 0) {
    drawEnv = 0x38e250;
  } else {
    drawEnv = 0x38e340;
  }

  sceGsSetHalfOffset(drawEnv, 2048, 2048, off);
}

void sjeGsSwapDBuff(int buff, boolean FromInterupt) {
  if (FromInterupt == 0) {
    FlushCache(0);
  } else {
    iFlushCache(0);
  }

  sceGsSwapDBuff(0x38e1f0, buff);

  return;
}

static void bossMake() { SemaParam s; }

void bossDmaFromSpr(u32 src, u32 dest, u32 len) {
  sceDmaChan *dmaChan;

  dmaChan = dmaSpr;
  dmaSpr->sadr = (void *)(src & 0xfffffff);
  sceDmaSendN(dmaChan, dest, len >> 4);

  return;
}

void bossTurtleCpu() { return; }

void bossTurtleGs() { return; }

void bossMainLoop() {
  u32 *ref;
  int i;
  int e;
  void *addr;
  player *cp;
  int oldzbmode;
}

/// <summary>
/// Presumably dumped the contents of the screen to the host PC's disk.
/// </summary>
void bossScreenDump() { return; }

static void cpuMain() {
  int dmalistlen;
  static int firsttime = 1;

  timeTickStart();
  do {
    if (restart == 0) {
      displayallfileops = 0;
      profileReset();
      memReset();
      memDynamicReset();
      gameReset();
      lvResetBefore();
      lvPreload();
      preloadExec();
      soundPreload();
      bgPreloadTextures();
      preloadPass2Exec();
      displayallfileops = 1;
      lvResetAfter();
      lvLevelSetup();
      gameResetAfter();
      bgSetCanAddLight(0);
      netReadyToStart();
    } else {
      displayallfileops = 1;
      profileRestart();
      memRestart();
      memDynamicRestart();
      gameRestart();
      lvRestartBefore();
      lvRestartAfter();
      lvLevelSetup();
      gameResetAfter();
      bgSetCanAddLight(0);
    }

    timeTickEnd();
    timeTickStart();
    lvend = 0;

    do {
      do {
        ucodevtxs = 0;
        ucodetris = 0;
        fxtris = 0;
        numglowsdrawn = 0;
        glowpixels = 0;
        bgtris = 0;
        bgcurtris = 0;
        bossMainLoop();
        dmalistlen = ((uint)gfxtag & 0xfffffff) -
                         ((uint)dmalists[curcpudmabuf] & 0xfffffff) >>
                     4;

        if (dmalistlen > maxdmalistlen) {
          maxdmalistlen = dmalistlen;
        }

        timeTickEnd();

        firsttime = bufffree_sid;
        dbinfo[curcpudmabuf].gsReadyToSend = 1;
        WaitSema(firsttime);
        dbinfo[curcpudmabuf].cpuStartFrame = framenum;
        timeTickStart();
      } while (lvend == 0);

      do {
        do {
          // Burn cycles while the GS is not ready.
        } while (dbinfo[0].gsReadyToSend != 0);
      } while (
          (((dbinfo[0].gsSending != 0) || (dbinfo[0].gsFinishedSending != 0)) ||
           (dbinfo[1].gsReadyToSend != 0)) ||
          ((dbinfo[1].gsSending != 0 || (dbinfo[1].gsFinishedSending != 0))));
    } while (lvend == 0);

    profileEnd();
    gameEnd();
  } while (true);
}

static void lockupalarm(int id, u16 time, void *arg) {
  alarm_activated = (uint)arg;
  iSignalSema(gsdone_sid, time);
  SYNC(0);
  EI();
  return;
}

static void gsMain() {
  int id;
  int i;
  static int LastFrameSent = -1;
}

static int vblIntHandler(int cause) {}

static int gsIntHandler(int cause) {
  REG_GS_CSR = 1;
  iSignalSema(gsdone_sid);
  SYNC(0);
  EI();
  return;
}

/// <summary>
/// Does... something to the string passed in. Supposedly checks it, but it
/// looks like it does nothing.
///
/// </summary>
/// <remarks>
/// It looks like it just gets used to iterate over the length of the first
/// string in each of the game's language dictionaries while doing nothing.
/// Maybe this did something at some point for development purposes (to check
/// for missed or NULL translations?) and they just partially stripped it out.
/// </remarks>
void checkstring(u8 *s) {
  int len;

  if (s != NULL) {
    for (int i = strlen(s); i > 0; i--) {
      // What does this do? It just loops backwards through the string's length
      // until it's zero?! It doesn't appear to "check" anything.
    }
  }
}

int main(int argc, char **argv) {
  ThreadParam st;
  int s;
  int demo_language;
  int demo_aspect;
  int demo_playmode;
  int demo_to_interactive;
  int demo_to_gameplay;
  int demo_mediatype;
  int demo_mastervolscale;
  int demo_dirsector;
  int i;
  int sonum;
  char *s;
  int i;
  int sonum;
  u32 *pos;
  u32 *end;
}

static void clearvram(u8 r, u8 g, u8 b, u8 a) {
  sceGifPacket gif_pkt;
  sceDmaChan *dmaGIF;

  // Access the GIF DMA channel struct.
  dmaGIF = sceDmaGetChan(2);

  sceGifPkInit(&gif_pkt, 0x38e470);
  sceGifPkReset(&gif_pkt);
  sceGifPkAddGsData(&gif_pkt, 0x1000000000008009);
  sceGifPkAddGsData(&gif_pkt, 0xe);
  sceGifPkAddGsData(&gif_pkt, 1);
  sceGifPkAddGsData(&gif_pkt, 0x1a);
  sceGifPkAddGsData(&gif_pkt, 0x100000);
  sceGifPkAddGsData(&gif_pkt, 0x4c);
  sceGifPkAddGsData(&gif_pkt, 0);
  sceGifPkAddGsData(&gif_pkt, 0x18);
  sceGifPkAddGsData(&gif_pkt, 0x400000004000000);
  sceGifPkAddGsData(&gif_pkt, 0x40);
  sceGifPkAddGsData(&gif_pkt, 0);
  sceGifPkAddGsData(&gif_pkt, 0x47);
  sceGifPkAddGsData(&gif_pkt, 6);
  sceGifPkAddGsData(&gif_pkt, 0);
  sceGifPkAddGsData(&gif_pkt,
                    r | 0x3f80000000000000 | b << 16 | g << 8 | a << 24);
  sceGifPkAddGsData(&gif_pkt, 1);
  sceGifPkAddGsData(&gif_pkt, 0);
  sceGifPkAddGsData(&gif_pkt, 4);
  sceGifPkAddGsData(&gif_pkt, 0x40004000);
  sceGifPkAddGsData(&gif_pkt, 4);
  sceGifPkTerminate(&gif_pkt);
  FlushCache(0);
  int pksize = sceGifPkSize(&gif_pkt);
  sceDmaSendN(dmaGIF, gif_pkt.pBase & 0xfffffff, pksize);
  sceGsSyncPath(0, 0);

  return;
}
