# OpenTS2

## Project Planning
Project Stage|Areas of focus
---|---
Stage 1|Audio system/`STREAM.IRX`, pack file parsing + dumping, pack alignment and manifest generation.
Stage 2|Work on an initial demo in the form of a game audio player for the PS2, loading sound files from a pack file.

## Technical Notes
Source tree was auto-generated from debugging information included with the _US Official PlayStation Magazine Demo 53_ version of _TimeSplitters 2_ (which is from the **5th of October 2001**).

This includes the semi-custom `STREAM.IRX` known as the _FRD Stream Driver_, which is based off of an early version of SCEE's _MultiStream_ library.

I haven't discovered any other builds of the game which have full debugging information in the main ELF file, but even in the EU retail build of the game, `STREAM.IRX` has full debugging information.

_Free Radical Design_ later updated `STREAM.IRX` to **v5** of _MultiStream_ for the retail releases and later demos, which closely resembles what is available in leaked PS2 SDKs.

There were some substantial changes to the file structures from the 2001 demo to the retail release.

For more information see: [Known file types](Documentation/OpenTS2_Technical_KnownFileTypes.md)
