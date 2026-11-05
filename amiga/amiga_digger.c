/* The Amiga port's start and end: PROGDIR:User, and SDL shut down at
 * exit, whichever way the game leaves (upstream's close gadget handler
 * and Right Amiga+Q call exit()).
 * Copyright (c) 2026 AmiCradle Team. GPL 2 or later, like Digger. */
#include <stdlib.h>
#include <sys/stat.h>
#include <SDL.h>

#include "def.h"
#include "main.h"
#include "amiga_port.h"

/* A Shell gives 4 KB of stack; SDL 2 wants more. libnix's startup sets
 * this much up. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) =
    "$VER: Digger 20261014 Amiga (05.11.2026)";

static void amiga_atexit(void)
{
	finish();
	SDL_Quit();
}

void amiga_init(void)
{
	mkdir("PROGDIR:User", 0755);
	atexit(amiga_atexit);
}
