#ifndef __FONT_SYSTEN_H
#define __FONT_SYSTEN_H

#include "font_manager.h"


void AddFontLibs(void);

PFontLib GetFontLib(char *name);

int SetDefaultFontLib(char *name);

int InitDefaultFontLib(void);

PFontLib GetFontBitMap(unsigned int dwCode, PFontBitMap pFontBitMap);

#endif /* __FONT_SYSTEN_H */
