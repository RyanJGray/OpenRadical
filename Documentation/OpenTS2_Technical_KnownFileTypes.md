# OpenTS2 - Known File Types
Details all known file types in _TimeSplitters 2_.

## Pack (P4CK/P8CK) Files
File Name|Description
---|---
`ANIM.PAK`|Animation Data
`CSANIM.PAK`|Cutscene Animation Data
`FRONTEND.PAK`|Frontend Animation Data
`OTHERS.PAK`|Unknown
`RAWS.PAK`|Unknown
`SOUNDS.PAK`|Sound Data

## Multistream flat Sample bank Concatenated (MSC) Files
These files are loaded and handled by the _FRD Stream Driver_ (**v1.1** in the OPM 53 demo).

This is based off of a modified early version of SCEE's _MultiStream_ IOP module.

These files contain the _Multistream flat Sample bank Header_ (`.MSH`) and _Multistream flat Sample bank Body_ (`.MSB`) data files concatenated together.

## Raw Files
_Free Radical Design_ used a generic `.raw` file extension for regular binary data (animations, skeletons, etc).

There is no specific format for all `.raw` files, the game's code is hardcoded to treat certain raw files differently.

