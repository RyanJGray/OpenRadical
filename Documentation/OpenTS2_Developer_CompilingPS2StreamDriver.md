# OpenTS2 - Developer - Compiling `STREAM.IRX` (The FRD Stream Driver)
## Instructions
### Prerequisites
You'll need a copy of the official **July 2005 Sony PlayStation 2 SDK (version 3.0.3)** - an ISO can be found online very easily.

You'll also need to be running some sort of Linux distribution.

### Build environment

You can use Wine to install the PS2 SDK just fine - just make sure to copy the files from your Wine directory to `/usr/local/sce` (or create a symbolic link using `sudo ln -s`).

This isn't the exact SDK version that _Free Radical Design_ used for TimeSplitters 2, unfortunately, there have been no leaks (that I'm aware of) of complete PS2 SDKs below version 3.

> In theory it will still compile and execute on a PlayStation 2 regardless, code written for their older SDKs is almost fully compatible with newer SDKs (barring any major bug fixes 
> or logic changes, which are typically well documented).

### Build steps
1. Change directory to `game/sound/stream`.
2. Run `./build.sh`.
3. You should now have your own `STREAM.IRX` in the same directory!
