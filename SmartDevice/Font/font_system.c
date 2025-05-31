#include "ascii_font.h"
#include "font_manager.h"

static PFontLib g_ptDefaultFontLib;//默认字库

void AddFontLibs(void)
{
    AddFontLibASCII();

}
PFontLib GetFontLib(char *name)
{
    return __GetFontLib(name);
}

int SetDefaultFontLib(char *name)
{
    g_ptDefaultFontLib = GetFontLib(name);
    if(g_ptDefaultFontLib)
    return 0;
    else
    return -1;
}

int InitDefaultFontLib(void)
{
    if(g_ptDefaultFontLib->FintInit)
    return g_ptDefaultFontLib->FintInit(g_ptDefaultFontLib);
    else
    return 0;
}


int GetFontBitMap(unsigned int dwCode, PFontBitMap pFontBitMap)
{
    return g_ptDefaultFontLib->GetFontBitMap(dwCode,pFontBitMap);
}

