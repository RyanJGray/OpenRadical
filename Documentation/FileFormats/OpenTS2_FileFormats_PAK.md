# OpenTS2 - File Formats - PAK (P4CK/P8CK)
This document mostly details the structure of the `.PAK` file as used in the US OPM 53 demo, supposedly `P4CK` dates back to TimeSplitters 1 and hasn't changed since then.

`P8CK` is odd and is used in a hybrid approach in the Xbox release - some files are `P4CK` and some are `P8CK`, I don't understand why FRD did this.

## Recommended tools
* [ImHex](https://github.com/WerWolv/ImHex) - an amazing hex editor that allows you to define patterns using a C-like language.

## `P4CK` (PlayStation 2/Xbox)
### Header
|Offset|Datatype|Name|Purpose|
|---|---|---|---|
|`0x0`|`char[4]`|`id`|FourCC magic (`P4CK`).|
|`0x4`|`s32`|`dirofs`|Offset to the directory tree.|
|`0x8`|`s32`|`dirlen`|Total length of the directory tree.|
|`0xC`|`s32`|`reserved`|Reserved - does not exist in the US OPM 53 code and is always 0.|

### Directory Table
|Offset|Datatype|Name|Purpose|
|---|---|---|---|
|`0x0`|`char[48]`|`name`|File name|
|`0x30`|`s32`|`filepos`|Absolute file position in PAK.|
|`0x34`|`s32`|`filelen`|Total length of the file's data.|
|`0x38`|`s32`|`gziplen`|Unused - Total gzipped length of the file's data.|

### Tools
I've built up the following pattern which makes reading the structure of `P4CK` files substantially easier.
```c
struct packHeader_s {
  char id[4];
  s32 dirofs;
  s32 dirlen;
  s32 reserved;
};
struct packFile_s {
  char name[48];
  s32 *filepos : s32;
  s32 filelen;
  s32 gziplen;
};
packHeader_s PackHeader @ 0x00;
packFile_s PackFileTable[PackHeader.dirlen / sizeof(packFile_s)] @ PackHeader.dirofs;
```

This will automatically highlight every entry in the pack file table for you and let you explore each entry.

### Notes
It's worth noting that, while support for gzip compression is included in the engine, FRD makes no use of it in TS2, they would only use it for _TimeSplitters: Future Perfect_.

It's possible that the assets were not sufficiently large to cause them to run out of space on the disk, and thus it was deemed unnecessary.

## `P8CK` (Xbox/GameCube)
### Header
|Offset|Datatype|Name|Purpose|
|---|---|---|---|
|`0x0`|`char[4]`|`id`|FourCC magic (`P8CK`).|
