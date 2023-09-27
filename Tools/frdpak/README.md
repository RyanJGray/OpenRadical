# OpenTS2 - FRD PAK Tool
## Description
A tool to generate and manipulate FRD `.pak` files.

I believe FRD called these "baf" files internally (from log files left in Homefront 2).
I'm not sure what "baf" stands for.

The logs suggest that their "baf" tool would align files for streaming.

This is possibly why all `P8CK` files have a lot of un-initialised memory inside of them which contain portions of the string "ho ho and an", this isn't part of the file as it appears before the file data begins.
