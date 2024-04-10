# OpenTS2 - Technical - Known Engine/Game Limitations
This document details known engine or game limitations for certain subsystems and variations of these limitations across platforms.

Subsystem|Name|Description|PS2 Value|PS2 Demo Value|Xbox Value|GC Value|Effect
---|---|---|---|---|---|---|---
`Prop`|`PROP_NUM`|Maximum number of props in the game.|`Unknown`|`812`|`1523`|`Unknown`|Game code will refuse to load any prop ID higher than this value.
`Anim`|`ANIM_ALL_NUM`|Maximum number of animations that can be loaded in the game.|`Unknown`|`167`|`Unknown`|`Unknown`|Game code will refuse to load any new animations when this limit is reached.
`i.LINK`|`ILSOCK_MAX_SOCKETS`|Max number of simultaneous i.LINK sockets.|`Unknown`|`18`|`Unknown`|`Unknown`|Game code will not open more than this number of sockets.
`i.LINK`|`ILSOCK_MAX_SIZE`|Max size in bytes for one i.LINK datagram.|`Unknown`|`256`|`Unknown`|`Unknown`|i.LINK driver will not accept datagrams over this size.
