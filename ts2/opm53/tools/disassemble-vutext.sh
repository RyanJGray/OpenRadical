#!/bin/sh

tools/sce/ee/gcc/bin/ee-objdump -d -j .vutext generated/SLUS_999.99 -w > generated/vutext-disasm.s