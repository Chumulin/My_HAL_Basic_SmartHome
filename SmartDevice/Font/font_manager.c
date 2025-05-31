#include <string.h>
#include "font_manager.h"

static PFontLib g_ptFontLibs;

void FontLibRegister(PFontLib ptFontLib)
{
    ptFontLib->ptNext = g_ptFontLibs;
    g_ptFontLibs = ptFontLib;
}

PFontLib __GetFontLib(char *name)
{
    PFontLib pTmp = g_ptFontLibs;

    while(pTmp)
    {
        if(strcmp(pTmp->name, name) == 0)
        return pTmp;
        else
        pTmp = pTmp->ptNext;
    }
    return NULL;
}




