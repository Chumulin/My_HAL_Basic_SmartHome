#ifndef __FONT_MANAGER_H
#define __FONT_MANAGER_H

typedef struct  FontBitMap
{
    int iLeftUpX;
    int iLeftUpY;
    int iWidth;
    int iRows;
    int iCurOriginX;
    int iCurOriginY;
    int iNextOriginX;
    int iNextOriginY;
    unsigned char *pucBuffer;
}FontBitMap, *PFontBitMap;

typedef struct FontLib
{
    char *name;
    int (*FintInit)(struct FontLib *pFontLib);
    void (*GetFontSize)(int *piWidth,int *piHeigh);
    int (*SetFontSize)(int iFontSize);
    int (*GetFontBitMap)(unsigned int dwCode, PFontBitMap ptFontBitMap);
    struct FontLib *ptNext;
}FontLib, *PFontLib;

void FontLibRegister(PFontLib ptFontLib);

PFontLib __GetFontLib(char *name);


#endif /* __FONT_MANAGER_H */
