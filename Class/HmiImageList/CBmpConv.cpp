//<NewSigmatekCFileOptimize/>
// +-------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                          |
// +-[      author ] kolott                                                        |
// +-[        date ] 07.03.2018                                                    |
// +-[ description ]---------------------------------------------------------------+
// |                                                                               |
// |                                                                               |
// +-------------------------------------------------------------------------------+

#include "lsl_c_ifssr.h"
#include "RTOS_C_interfaces.h"
#include "CBmpConv.h"

static unsigned long bcMemory(void** pptr, unsigned long size)
{
  void *ph;
  
  if(size == 0)
  {
    if(*pptr != NULL)
    {
      OS_SSR_Free(*pptr);
    }
    
    *pptr = NULL;
    return 1;
  }
  
  if(*pptr != NULL)
  {
    ph = OS_SSR_Realloc(*pptr, size);
    if(ph != NULL)
    {
      *pptr = ph;
      return 1;
    }
    return 0;
  }
  
  ph = OS_SSR_Malloc(size);
  if(ph != NULL)
  {
    *pptr = ph;
    return 1;
  }
  
  return 0;
}

static tcPixel *bcGetRgbTab(unsigned long *ps, unsigned long cnt)
{
  tcPixel *retcode = NULL;
  
  if(bcMemory((void**)&retcode, cnt * sizeof(tcPixel)) != 0)
  {
    tcPixel *pd = retcode;
    tcPixel col;
    while(cnt--)
    {
     #ifdef VIDEO16
      unsigned long col32 = (*ps++) & 0x00FFFFFF;
      col   = (col32 >> (19-11)) & 0xF800;
      col  |= (col32 >> (10- 5)) & 0x07E0;
      col  |= (col32 >> (    3)) & 0x001F;
     #else
      col   = (*ps++) & 0x00FFFFFF;
     #endif
      *pd++ = col;
    }
  }
  
  return retcode;
}

static unsigned long bcRawToBmoCompute(tcBmoData *pd, unsigned long width, unsigned long height, tcPixel *praw)
{
  unsigned long retcode = 0;

  if((pd != NULL) && (praw != NULL))
  {
    pd -= 1;
  
    while(height--)
    {
      unsigned long xx = width;
      tcPixel old = (*praw) ^ 0xFF;
      unsigned long nox = 255;
      while(xx--)
      {
        if((*praw != old) || (nox >= 255))
        {
          retcode++;
          old = *praw;
          nox = 1;
          pd++;
          pd->no    = 1;
          pd->color = *praw;
        }
        else
        {
          nox ++;
          pd->no ++;
        }
        praw ++;
      }
    }
  }
  else
  {
    while(height--)
    {
      unsigned long xx = width;
      tcPixel old = (*praw) ^ 0xFF;
      unsigned long nox = 255;
      while(xx--)
      {
        if((*praw != old) || (nox >= 255))
        {
          retcode++;
          old = *praw;
          nox = 1;
        }
        else
        {
          nox ++;
        }
        praw ++;
      }
    }
  }
  
  return retcode;
}

static tcRaw *bcAllocRaw(unsigned long width, unsigned long height)
{
  tcRaw *praw = NULL;
  if(bcMemory((void**)&praw, sizeof(tcRaw)) != 0)
  {
    praw->width  = width;
    praw->height = height;
    praw->ptr = NULL;
    
    if(bcMemory((void**)&praw->ptr, width * height * sizeof(tcPixel)) != 0)
    {
      return praw;
    }
  }
  bcMemory((void**)&praw, 0);
  return NULL;
}

static tcBmo *bcAllocBmo(unsigned long width, unsigned long height, unsigned long datano)
{
  tcBmo *pbmo = NULL;
  if(bcMemory((void**)&pbmo, sizeof(tcBmo)) != 0)
  {
   #ifdef BmoMit2ByteID
    pbmo->glib_id     = 0x5752;  // wird von glib benötigt
   #endif 
    pbmo->datano      = datano;
    pbmo->width       = (unsigned short)width;
    pbmo->height      = (unsigned short)height;
    pbmo->transparent = 0;
    pbmo->state       = 4; //GLibImg_NO_TRANSPARENT;
    pbmo->ptr         = NULL;
    
    if(bcMemory((void**)&pbmo->ptr, datano * sizeof(tcBmoData)) != 0)
    {
      return pbmo;
    }
  }
  bcFreeBmo(pbmo);
  return NULL;
}

cExtern tcRaw* bcBitmapToRaw(void *bitmap)
{
  register unsigned long yy, xx;
  unsigned char  *data = (unsigned char*)bitmap;
  tcBitMap       *bmp = (tcBitMap*)data;
  unsigned long  line, add, col, x;
  unsigned char  *src, *rgb;
  unsigned short *p16;
  tcPixel        *pd;
  unsigned long  retcode = 0;
  tcRaw          *praw = NULL;
  
  if(bitmap != NULL)
  {
  if(bmp->head.label == 0x4D42) // "BM"
  {
    if((bmp->info.compr == 0) || (bmp->info.compr == 3))
    {
      line = (((bmp->info.width * bmp->info.bitcnt) + 31) / 32) * 4; // bytes per line
      src  = &data[bmp->head.offs];
      yy   = bmp->info.height;
      praw = bcAllocRaw(bmp->info.width, bmp->info.height);
        
      if(praw != NULL)
      {
        if((bmp->info.bitcnt == 24)||(bmp->info.bitcnt == 32))
        {
          retcode = 1;
          add = bmp->info.bitcnt / 8;
        
          while(yy--)
          {
            x   = 0;
            xx  = bmp->info.width;
            rgb = src;
            pd  = &praw->ptr[yy * xx]; 
            while(xx)
            {
               #ifdef VIDEO16
                unsigned short col16 = rgb[2] >> 3;
                col16 <<= 6;
                col16 |= rgb[1] >> 2;
                col16 <<= 5;
                col16 |= rgb[0] >> 3;
                *pd = col16;
               #else
                *pd = 0x00FFFFFF & (*(tcPixel*)rgb); 
               #endif 
              rgb += add;
              xx--;
              x++; 
              pd++;
            }
            src += line;
          }
        }
        else if(bmp->info.bitcnt == 16)
        {
          retcode = 1;
          while(yy--)
          {
            x   = 0;
            xx  = bmp->info.width;
            p16 = (unsigned short*)src;
            pd  = &praw->ptr[yy * xx];
            while(xx--)
            {
             #ifdef VIDEO16
              *pd = (*p16 & 0x1F) | ((*p16 & 0xFFE0) << 1);
             #else
              *pd = ((*p16 & 0x1F) << 3)| (((*p16>>5) & 0x1F) << 11) | (((*p16>>10) & 0x1F) << 19);
             #endif
              p16++;
              x++; 
              pd++;
            }
            
            src += line;
          }
        }
        else
        {
          unsigned char *p08;
          tcPixel *rgbtab = NULL;
          switch(bmp->info.bitcnt)
          {
            case 1 : rgbtab = bcGetRgbTab((unsigned long*)&data[sizeof(tcBitMap)], 2); 
                     break;
            case 4 : rgbtab = bcGetRgbTab((unsigned long*)&data[sizeof(tcBitMap)], 16);  
                     break;
            case 8 : rgbtab = bcGetRgbTab((unsigned long*)&data[sizeof(tcBitMap)], 256); 
                     break;
          }
          
          if(rgbtab != NULL)
          {
            retcode = 1;
            if(bmp->info.bitcnt == 8)
            {
              while(yy--)
              {
                x   = 0;
                xx  = bmp->info.width;
                p08 = (unsigned char*)src;
                pd  = &praw->ptr[(yy * xx) + x];
                while(xx--)
                {
                  *pd = rgbtab[*p08];
                  p08++;
                  x++; 
                  pd++;
                }
            
                src += line;
              }
            }
            else if(bmp->info.bitcnt == 4)
            {
              while(yy--)
              {
                x   = 0;
                xx  = bmp->info.width / 2;
                p08 = (unsigned char*)src;
                pd  = &praw->ptr[yy * bmp->info.width];
                while(xx--)
                {
                  col = *p08++;
                    
                  *pd = rgbtab[col>>4];
                  pd++;
                  x++;

                  *pd = rgbtab[col & 0x0F];
                  pd++;
                  x++;
                }
                  
                if(bmp->info.width & 1)
                {
                  col = *p08;
                  *pd = rgbtab[col>>4];
                }
            
                src += line;
              }
            }
            else if(bmp->info.bitcnt == 1)
            {
              while(yy--)
              {
                x   = 0;
                xx  = bmp->info.width;
                p08 = (unsigned char*)src;
                pd  = &praw->ptr[(yy * xx) + x];
                while(xx != 0)
                {
                  unsigned long bitcnt = (xx > 8)? 8 : xx;
                  xx -= bitcnt;
                  unsigned long bitmsk = 0x80;
                  unsigned long byte   = *p08++;
                  while(bitcnt--)
                  {
                    *pd = rgbtab[(byte & bitmsk)? 1 : 0];
                    bitmsk >>= 1;
                    x++; 
                    pd++;
                  }
                }
                src += line;
              }
            }
            
            bcMemory((void**)&rgbtab, 0);
          }
        }
        if(retcode == 0) // problem ?
        {
          bcFreeRaw(praw);
          praw = NULL;
        }
      }
    }
  }
  }
  
  return praw;
}

cExtern void bcFreeRaw(tcRaw *praw)
{
  if(praw != NULL)
  {
    bcMemory((void**)&praw->ptr, 0);
    bcMemory((void**)&praw, 0);
  }
}

cExtern void bcFreeBmo(tcBmo *pbmo)
{
  if(pbmo != NULL)
  {
    bcMemory((void**)&pbmo->ptr, 0);
    bcMemory((void**)&pbmo, 0);
  }
}

cExtern tcBmo *bcRawToBmo(tcRaw *praw)
{
  if(praw != NULL)
  {
    unsigned long datano = bcRawToBmoCompute(NULL, praw->width, praw->height, praw->ptr);
    tcBmo *pbmo = bcAllocBmo(praw->width, praw->height, datano);
    if(pbmo != NULL)
    {
      bcRawToBmoCompute(pbmo->ptr, praw->width, praw->height, praw->ptr);
      return pbmo;
    }
  }
  
  return NULL;
}

tcRaw *bcRawClone(unsigned long width, unsigned long height, tcRaw *psrc)
{
  tcRaw *praw = NULL;
  if(psrc != NULL)
  {
    praw = bcAllocRaw(width, height);
    if(praw != NULL)
    {
      if((width == psrc->width) && (height == psrc->height))
      {
         tcPixel *pd = praw->ptr;
         tcPixel *ps = psrc->ptr;
         unsigned long nox = width * height;
         while(nox--)
         {
           *pd++ = *ps++;
         }
      }
      else
      {
        for(unsigned long iy=0; iy<height; iy++)
        {
          tcPixel *ph = &praw->ptr[iy*width];
          unsigned long sy = ((iy * psrc->height) / height) * psrc->width;
          for(unsigned long ix=0; ix<width; ix++)
          {
            *ph++ = psrc->ptr[sy + (ix * psrc->width) / width];
          }
        }
      }
    }
  }
  
  return praw;
}

