Digger Remastered for AmigaOS 3.x
=================================

A port of Digger Remastered (Andrew Jenner's GPL remake of Windmill
Software's 1983 Digger), in Maksym Sobolyev's SDL 2 version "Digger
Reloaded" (https://github.com/sobomax/digger, master at commit
638125eecc2a36629b886f58d7b75253894cf3d3, 14 October 2026), for AmigaOS 3.2
on a 68040 or 68060 with an FPU and an RTG screen, on GFOpenGPU's SDL 2.

Why this source: digger.org's own Digger Remastered is DOS/Windows only;
sobomax/digger is its maintained GPL descendant with the SDL 2 front end
(the one Debian and Gentoo package).

Status: runs in the AmiCradle lab: the title screen with its high scores
and the monsters' parade, a one-player game (digging, firing, the
monsters), Esc ending the game, and Esc on the title screen and Right
Amiga+Q in a game quitting cleanly to the Workbench. The lab is muted, so
the sound was not heard.


What you need
-------------

- A 68040 or 68060 with an FPU (not an LC040 or EC040), AmigaOS 3.2, an RTG
  card (or the AmiCradle lab), and about 4 MB of free memory.
- GFOpenGPU 0.8 or later: LIBS:GFOpenGPU/SDL2.module (installed by OpenUp).
- Nothing else: the graphics, sounds and levels are in the program.


How to play
-----------

Run Install-Digger (or copy the Digger drawer where you want it), then
double-click Digger, or from a Shell:

    cd Digger
    Digger [/Q] [/F] [/2] [/G:time] ...

Upstream's options are in digger.txt (/Q no sound, /F full screen, /2 two
players on one keyboard, /G gauntlet mode, and more).

- Keys, as on the PC: cursor keys move, F1 fires (player 2: W A S Z and
  Tab); Space pauses; Enter or any key starts from the title screen; N
  changes the game mode (one or two players, gauntlet); F7 music, F9
  sound, + and - on the keypad the speed; K redefines the keys on the
  title screen; Alt+Enter switches between the window and full screen.
- Esc (or F10) ends a game; on the title screen it quits. Right Amiga+Q,
  or the window's close gadget, quits at once.
- The settings (DIGGER.INI), the high scores (DIGGER.SCO) and a log are in
  the drawer's User drawer; an update by Install-Digger keeps it.


Building
--------

GFOpenAmigaGCC 16.2.0-open6 (the os32-gcc16-open6 stove, with the GFOpenGPU
SDK 0.8 and zlib in it):

    make -f amiga/Makefile.amigaos -j4 STOVE=/path/to/os32-gcc16-open6

STOVE defaults to ~/AmiCradle/stoves/os32-gcc16-open6. Output:
build/amigaos/Digger/ (the program, ReadMe, digger.txt, ReadMe-Digger,
COPYING.txt, Licences.txt, an empty User drawer, with GlowIcons),
build/amigaos/Digger.info and build/amigaos/Install-Digger with its icon.
The icons are made from amiga/icons/icons.json and Install-Digger from
amiga/installer.json with amicradle's scripts/port_icons.py and
port_installer.py (see "about" in icons.json).


What was changed
----------------

- amiga/Makefile.amigaos: upstream's GNUmakefile file list as for its
  WebAssembly build: the network play's SIP stack (microsippy, netsim.c,
  netsim_rx.c) is left out and netsim_stubs.c stands in; microsippy's
  usipy_str.c is kept (netsim_friends.c uses it). Linked with the stove's
  libSDL2.a and zlib.
- amiga/amiga_digger.c: a 256 KB stack, the $VER string, PROGDIR:User made
  at the start, and an exit handler that shuts the game's video and sound
  and SDL down (upstream leaves with exit() on the close gadget).
- def.h, scores.c, main.c: DIGGER.INI, DIGGER.SCO and DIGGER.log in
  PROGDIR:User. finish() runs once (it is also the exit handler's).
- sdl_kbd.c: Esc is a second Exit key beside F10; Right Amiga+Q quits.
- No byte-order changes were needed for play: the graphics and levels are
  byte arrays in the program and the high score file is text. Recordings
  (.DRF, F8) were not tried.


Known limits
------------

- No network play (/N): the SIP/UDP stack is not built.
- Full screen (/F, Alt+Enter) was not tried.
- The frame rate on a real 68040 was not measured; the lab's CPU is faster.
- The sound was not heard (muted lab).


Licence
-------

Digger Remastered is under the GNU GPL, version 2 (COPYING.txt); some
files are Beer-Ware, BSD 2-Clause or public domain, as their headers say
(see Licences.txt). The port's own files are GPL 2, Copyright (c) 2026
AmiCradle Team.
