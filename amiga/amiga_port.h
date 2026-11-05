/* The Amiga port's own helpers (amiga/).
 * Copyright (c) 2026 AmiCradle Team. GPL 2 or later, like Digger. */
#ifndef AMIGA_PORT_H
#define AMIGA_PORT_H

/* Makes PROGDIR:User (the settings, high scores and log) and has SDL shut
 * down at any exit: the close gadget and Right Amiga+Q leave with exit(). */
void amiga_init(void);

#endif
