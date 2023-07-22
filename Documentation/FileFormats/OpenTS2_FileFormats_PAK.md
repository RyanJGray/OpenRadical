# OpenTS2 - File Formats - PAK (P4CK/P8CK)
This document mostly details the structure of the `.PAK` file as used in the US OPM 53 demo, it's possible the `P4CK` format has changed since then (2001).

## Recommended tools
* [ImHex](https://github.com/WerWolv/ImHex) - an amazing hex editor that allows you to define patterns using a C-like language.

## `P4CK` (PlayStation 2/Xbox `.PAK` files)

I've built up the following pattern which makes reading the structure of `P4CK` files substantially easier.
```c
struct packHeader_s {
  char id[4];
  s32 dirofs;
  s32 dirlen;
  s32 pad; // Not in FRD's code, not sure if this was inserted by the compiler.
};
struct packFile_s {
  char name[48];
  s32 filepos;
  s32 filelen;
  s32 gziplen;
};
packHeader_s PackHeader @ 0x00;
packFile_s PackFileTable[PackHeader.dirlen / sizeof(packFile_s)] @ PackHeader.dirofs;
```

This will automatically highlight every entry in the pack file table for you and let you explore each entry.

## Notes
It's worth noting that, while support for gzip compression is included in the engine, FRD makes no use of it in TS2, they would only use it for _TimeSplitters: Future Perfect_.

It's possible that the assets were not sufficiently large to cause them to run out of space on the disk, and thus it was deemed unnecessary.
