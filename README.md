# OpenRadical - A project to study and play old TimeSplitters engine games on newer platforms

## Project Planning
Project Stage|Areas of focus
---|---
Stage 1|Audio system/`STREAM.IRX`, pack file parsing + dumping, pack alignment and manifest generation.
Stage 2|Work on an initial demo in the form of a game audio player for the PS2, loading sound files from a pack file.
Stage 3|Write a tool to open, parse and edit TS Engine files.
Stage 4|Focus on REing core engine systems.

## Technical Notes
Source tree was auto-generated from debugging information included with the _US Official PlayStation Magazine Demo 53_ version of _TimeSplitters 2_ (which is from the **5th of October 2001**).

This includes the semi-custom `STREAM.IRX` known as the _FRD Stream Driver_, which is based off of an early version of SCEE's _MultiStream_ library.

I haven't discovered any other builds of _TimeSplitters 2_ which have full debugging information in the main ELF file, but even in the EU retail build of the game, `STREAM.IRX` has full debugging information.

_Free Radical Design_ later updated `STREAM.IRX` to **v5** of _MultiStream_ for the retail releases and later demos, which closely resembles what is available in PS2 SDKs.

There were some substantial changes to the file structures from the 2001 demo to the retail release.

For more information see: [Known file types](Documentation/OpenTS2_Technical_KnownFileTypes.md)

---

**This project is not affiliated with, supported or otherwise endorsed by, Embracer Group, Plaion and the late Free Radical Design. Any trademarks mentioned are the property of their respective owners.**

This project does not (and will never) supply copyrighted game assets, you must supply these yourself from an original game copy that you legally own.

The soundtrack for FRD's games can be bought legally from [Graeme Norgate's Bandcamp](https://graemenorgate.bandcamp.com) in a variety of file formats. Initially, only OGG Vorbis will be supported.

TimeSplitters: Future Perfect is the exception where Graeme seems to only have published the music that he composed, the rest of the music was composed by Christian Marcussen, who seemingly never released their music.

The PS2 version of the game has music of the same audio quality (FRD used WAV ADPCM audio encoding) as on Bandcamp, and as of right now is the only version of the game that can be used as a source for game assets.

You **must** legally own a copy of the game in order to use this project.
