
#include "MiniSrcData.h"

#ifdef __cplusplus
 #define MyExtern extern "C"
#else
 #define MyExtern extern
#endif

#define MAXBUFSIZE 20000

// *********************************************************************
// library *************************************************************
// *********************************************************************
MyExtern void           MemCpy3(void *dst, void *src, unsigned long size);
MyExtern unsigned long  StrLen3(unsigned short *txt);
MyExtern unsigned long  MemCmp3(void *src1, void *src2, unsigned long size);
MyExtern _BIGBOX_HEADER *setup_BIGBOX_HEADER(_BIGBOX_HEADER *p, unsigned long size);
MyExtern _BIGBOX_HEADER *end_BIGBOX_HEADER(_BIGBOX_HEADER *p, unsigned long addsize);
MyExtern unsigned long  make_crc32(unsigned long retcode, void *ptr, unsigned long len);


// *********************************************************************
// public **************************************************************
// *********************************************************************

MyExtern void           StartScreen(unsigned short scrno, unsigned short startfunct, unsigned short endfunct, unsigned short colorback);
MyExtern unsigned long  AddScreen_CTRL_BUTTON(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char frametype, unsigned char font, unsigned char attrib, unsigned short imgreleased, unsigned short imgpressed, unsigned short txtreleased, unsigned short txtpressed, unsigned short fktno_press, unsigned short fktno_release, unsigned short momstat, unsigned short trigger, unsigned char sbit, short val_release, short val_press);
MyExtern unsigned long  AddScreen_CTRL_POLYLINE(_XY *pxy, unsigned short no, unsigned short color, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_IO(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colortext, unsigned char frametype, unsigned char font, unsigned char attrib, unsigned char iotype, unsigned char digits, unsigned char writeprotected, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_IOBAR(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colorfront, unsigned char frametype, unsigned char state, unsigned char writeprotected, long og, unsigned char ogstate, long ug, unsigned char ugstate, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_IMAGE(short x0, short y0, short x1, short y1, unsigned char attrib, unsigned short imgno, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_IMAGESCM(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned char frametype, unsigned char attrib, unsigned short varno, unsigned short shemeindex, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_TEXTSCM(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned short varno, unsigned short shemeindex, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_TEXT(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned short textno, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_FRAME(short x0, short y0, short x1, short y1, unsigned short color, unsigned char frametype, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_OSZI(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colorline, unsigned char attrib, unsigned char frametype, unsigned char index, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_LIST(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colorline, unsigned short colorselect, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned char index, unsigned char sbit);
MyExtern unsigned long  AddScreen_CTRL_PIXMAP(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colorfront, unsigned char index, unsigned char sbit);

MyExtern _BIGBOX_HEADER *EndScreen(void);
