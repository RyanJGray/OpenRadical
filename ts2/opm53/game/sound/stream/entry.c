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

#include "command.h"

ModuleInfo Module = {"FRD_Stream_Driver", 0x0101};

int start() {
  struct ThreadParam tp;
  int tid;

  tid = sceSifCheckInit();
  if (tid == 0) {
    sceSifInit();
  }
  sceSifInitRpc(0);
  printf("FRD Stream Driver v%d.%d\n", Module.version >> 8,
         Module.version & 0xff);

  tp.attr = TH_C;
  tp.entry = stream_loop;
  tp.initPriority = 0x1e;
  tp.stackSize = 0x800;

  tid = CreateThread(&tp);
  if (tid >= 1) {
    StartThread(tid, 0);
    printf("Exit stream loader thread\n");
  }

  return tid < 1;
}
