#include <stdio.h>
#include "font_manager.h"
#include "font_system.h"
#include "display_device.h"
#include "show_text.h"
#include "encoding.h"


static unsigned int GetPixelColorFromBitMap(PFontBitMap ptFontBitMap, int iX, int iY)
{
    int x, y;
    unsigned char *byte = ptFontBitMap->pucBuffer;

    x = iX -  ptFontBitMap->iLeftUpX;
    y = iY -  ptFontBitMap->iLeftUpY;

    if(y < 8)
    {
        byte += x;
    }
    else
    {
        byte += 8 + x;
    }
    if(y > 8)
    y -= 8;
    return *byte & (1<<y);
}


static void DrawBitMapOnFrameBuffer(PDisplayDevice ptDisplayDev ,PFontBitMap ptFontBitMap)
{
    int x, y;
    unsigned int dwColor;

    for (y  = ptFontBitMap->iLeftUpY; (y < ptFontBitMap->iLeftUpY + ptFontBitMap->iRows) && (y < ptDisplayDev->iYres); y++)
    {
        for (x  = ptFontBitMap->iLeftUpX; (x < ptFontBitMap->iLeftUpX + ptFontBitMap->iWidth) && (x < ptDisplayDev->iXres); x++)
        {
           dwColor =  GetPixelColorFromBitMap(ptFontBitMap, x, y);

           ptDisplayDev->SetPixel(ptDisplayDev, x, y, dwColor);
        }
    }
    
}


int ShowTextInDisplayDevice(PDisplayDevice ptDisplayDev ,int iX, int iY, char *Str)
{
    int len,i = 0;
    unsigned int dwCode;
    FontBitMap tFontBitMap;
   /*根据指定的编码集/编码格式来处理str*/ 
   	tFontBitMap.iCurOriginX = iX;
	tFontBitMap.iCurOriginY = iY;
   while (Str[i])
   {
    len = GetCodeForStr(&Str[i],&dwCode);
    i += len;

    tFontBitMap.pucBuffer = NULL;
    if (GetFontBitMap(dwCode, &tFontBitMap)  == 0)
    {
        DrawBitMapOnFrameBuffer(ptDisplayDev, &tFontBitMap);
    }
    tFontBitMap.iCurOriginX = tFontBitMap.iNextOriginX;
    tFontBitMap.iCurOriginY = tFontBitMap.iNextOriginY;
   }
   ptDisplayDev->Flush(ptDisplayDev);
   return 0;
}
