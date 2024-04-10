# OpenTS2 - Code Structure
Documents the code structure used by _Free Radical Design_ in _TimeSplitters 2_.

## Core game systems
The code for the game's core systems usually follows a very specific convention and flow that makes it relatively straightforward to initialise (and deinitialise) each system.

It's very simple and straightforward to follow.

Function|Description
---|---
`<system>Make`|Handles initialisation of a system. Allocates memory, initialises low-level drivers, etc.
`<system>End`|Handles deinitialisation of a system. De-allocates memory, resets the state, etc.
`<system>Preload`|Prepares all data and files necessary for the system to function.
`<system>Reset`|Resets the system's state completely, wipes the slate clean.
`<system>ResetBefore`|Contains all logic that should run before a reset is completed.
`<system>ResetAfter`|Contains all logic that should run after a reset has been completed.
`<system>Restart`|Gets the system ready for use again, reloads required data, etc.
`<system>RestartBefore`|Contains all logic that should run before a system is restarted.
`<system>RestartAfter`|Contains all logic that should run after a system has been restarted.
