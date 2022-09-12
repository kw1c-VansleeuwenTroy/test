// +-------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                          |
// +-[      author ] kolott                                                        |
// +-[        date ] 05.03.2018                                                    |
// +-[ description ]---------------------------------------------------------------+
// |                                                                               |
// |                                                                               |
// +-------------------------------------------------------------------------------+

#pragma once

#define VIDEO16
#define BmoMit2ByteID // wird von GLib benötigt
  
#ifndef cCompile
  #ifdef _MSC_VER
    #define cCompile
  #endif
  #ifdef _GNUC
    #define cCompile
  #endif
#endif

#ifdef cCompile
  #ifndef cExtern
    #ifdef __cplusplus
      #define cExtern extern "C"
    #else
      #define cExtern extern 
    #endif
  #endif
#endif

#ifdef cCompile  // c-compiler ********************************************************************

  #ifndef NULL
    #define NULL 0
  #endif

  #pragma pack (push, 1)

  #ifdef VIDEO16
   typedef unsigned short tcPixel;
  #else
   typedef unsigned long tcPixel;
  #endif

  typedef struct
  {
    unsigned long width;
    unsigned long height;
    tcPixel       *ptr;
  }
  tcRaw;

  typedef struct 
  {
    unsigned char  no;
    tcPixel        color;
  }
  tcBmoData;

  typedef struct
  {
   #ifdef BmoMit2ByteID
    unsigned short glib_id;  // wird von GLib benötigt
   #endif 
    unsigned long  datano;
    unsigned short width;
    unsigned short height;
    tcPixel        transparent;
    unsigned short state;
    tcBmoData      *ptr;
  }
  tcBmo;

  typedef struct
  { 
    unsigned short label;    // ('BM')
    unsigned long  fsize;    // filesize
    unsigned long  nc;       // (0)
    unsigned long  offs;     // offset of bitpattern (reference filestart)
  } 
  tcBitmapHead;

  typedef struct
  { 
    unsigned long  size;     // length of bitmapheaderinfo
    unsigned long  width;    // Bitmapbreite in Pixel
    unsigned long  height;   // Bitmaphoehe in Pixel
    unsigned short planes;   // (1)
    unsigned short bitcnt;   // (4) Zahl der Bits pro Pixel
    unsigned long  compr;    // (0) Art der komprimierung
    unsigned long  sizeim;   // Bildgroesse in Bytes
    unsigned long  nc[4];
  }
  tcBitmapInfo;

  typedef struct
  { 
    tcBitmapHead   head;
    tcBitmapInfo   info;
  }
  tcBitMap;

  #pragma pack (pop)

  cExtern tcRaw* bcBitmapToRaw(void *bitmap);
  cExtern void   bcFreeRaw(tcRaw *praw);
  cExtern tcRaw* bcRawClone(unsigned long width, unsigned long height, tcRaw *psrc);
  cExtern void   bcFreeBmo(tcBmo *pbmo);
  cExtern tcBmo* bcRawToBmo(tcRaw *praw);
 
#else // ST-compiler *********************************************************************
  
  TYPE
  
  #pragma pack (push, 1)
  
 #ifdef VIDEO16 
  tcPixel : UINT;
 #else
  tcPixel : UDINT;
 #endif 
  
  tcRaw : STRUCT
    width       : udint;
    height      : udint;
    ptr         : ^tcPixel;
  END_STRUCT;
  
  tcBmoData : STRUCT
    no          : USINT; 
    color       : tcPixel;
  END_STRUCT;
  
  tcBmo : STRUCT
   #ifdef BmoMit2ByteID
    glib_id     : uint; // wird von GLib benötigt
   #endif 
    datano      : UDINT;
    width       : UINT;
    height      : UINT;
    transparent : tcPixel;
    state       : UINT;
    ptr         : ^tcBmoData;
  END_STRUCT;

  #pragma pack (pop)

  END_TYPE

  FUNCTION GLOBAL __CDECL bcBitmapToRaw VAR_INPUT bitmap:^void; END_VAR VAR_OUTPUT retcode:^tcRaw; END_VAR;
  FUNCTION GLOBAL __CDECL bcFreeRaw VAR_INPUT praw:^tcRaw; END_VAR;
  FUNCTION GLOBAL __CDECL bcRawClone VAR_INPUT width:UDINT; height:UDINT; praw:^tcRaw; END_VAR VAR_OUTPUT retcode:^tcRaw; END_VAR;
  FUNCTION GLOBAL __CDECL bcFreeBmo VAR_INPUT pbmo:^tcBmo; END_VAR;
  FUNCTION GLOBAL __CDECL bcRawToBmo VAR_INPUT praw:^tcRaw; END_VAR VAR_OUTPUT retcode:^tcBmo; END_VAR;

#endif
