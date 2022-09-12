
#include "Create.h"

_BOX_SCREEN   *PScr;
unsigned char DataBuffer[MAXBUFSIZE + 128];

void init_CTRLBOX_HEADER(_CTRLBOX_HEADER *p)
{
  p->size = 0;
  p->id   = BOX_CTRL_NC;
}

_CTRLBOX_HEADER *setup_CTRLBOX_HEADER(_CTRLBOX_HEADER *p, unsigned short size, unsigned char id)
{
  p->size = size;
  p->id = id;
  return p;
}

void StartScreen(unsigned short scrno, unsigned short startfunct, unsigned short endfunct, unsigned short colorback)
{
  PScr               = (_BOX_SCREEN*)DataBuffer;
  setup_BIGBOX_HEADER(&PScr->boxhdr, 0);
  PScr->screennumber = scrno;
  PScr->colorback    = colorback;
  PScr->startfunct   = startfunct;        // startfunktionsindex
  PScr->endfunct     = endfunct;          // endfunktionsindex
  PScr->ctrlno       = 0;
}

_BIGBOX_HEADER *EndScreen(void)
{
  return end_BIGBOX_HEADER(&PScr->boxhdr, sizeof(_BOX_SCREEN) - 1);
}

static unsigned long AddScreen(_CTRLBOX_HEADER *pbox)
{
  if((PScr->boxhdr.size + pbox->size) < MAXBUFSIZE)
  {
    _CTRLBOX_HEADER *ph = (_CTRLBOX_HEADER*)&PScr->data[PScr->boxhdr.size];
    
    MemCpy3(ph, pbox, pbox->size);
    PScr->ctrlno ++;
    PScr->boxhdr.size += pbox->size;
    
    return 1;
  }
  
  return 0;
}


static unsigned long AddScreenEx(_CTRLBOX_HEADER *pbox, unsigned char sbit)
{
  _CTRLBOX_HEADER *ph = (_CTRLBOX_HEADER*)&PScr->data[PScr->boxhdr.size];
  
  if(AddScreen(pbox) != 0)
  {
    if(sbit != 0)
    {
      ph->size                     += 1;
      PScr->data[PScr->boxhdr.size] = sbit;
      PScr->boxhdr.size            += 1;
    }
    
    return 1;
  }
  
  return 0;
}

unsigned long AddScreen_CTRL_BUTTON(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char frametype, unsigned char font, unsigned char attrib, unsigned short imgreleased, unsigned short imgpressed, unsigned short txtreleased, unsigned short txtpressed, unsigned short fktno_press, unsigned short fktno_release, unsigned short momstat, unsigned short trigger, unsigned char sbit, short val_release, short val_press)
{
  unsigned char tmp[sizeof(_BOX_CTRL_BUTTON) + 1 + 2 + 2];  // struct + sbit + setvalue + resetvalue
  _BOX_CTRL_BUTTON *p = (_BOX_CTRL_BUTTON*)tmp;
  setup_CTRLBOX_HEADER(&p->boxhdr, sizeof(_BOX_CTRL_BUTTON), BOX_CTRL_BUTTON);
  p->xy[0].x = x0;
  p->xy[0].y = y0;
  p->xy[1].x = x1;
  p->xy[1].y = y1;
  p->frametype = frametype;
  p->attrib = attrib;
  p->font = font;
  p->colorback = colorback;
  p->colortext = colortext;
  p->img[0] = imgreleased;
  p->img[1] = imgpressed;
  p->text[0] = txtreleased;
  p->text[1] = txtpressed;
  p->momstat = momstat;
  p->fktno[0] = fktno_press;
  p->fktno[1] = fktno_release;
  p->trigger  = trigger;
  
  if(p->momstat != VARNO_DEFAULT) 
  {
    if((val_release != 0)||(val_press != 1))
    {
      tmp[_SBITOFF_CTRL_BUTTON] = sbit;
      *(short*)&tmp[_RELEASEVALOFF_CTRL_BUTTON] = val_release;
      *(short*)&tmp[_PRESSVALOFF_CTRL_BUTTON] = val_press;
      p->boxhdr.size += 5;
      return AddScreen(&p->boxhdr);
    }
  }
  
  return AddScreenEx(&p->boxhdr, sbit);
}

unsigned long AddScreen_CTRL_IO(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colortext, unsigned char frametype, unsigned char font, unsigned char attrib, unsigned char iotype, unsigned char digits, unsigned char writeprotected, unsigned char sbit)
{
  _BOX_CTRL_IO p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_IO), BOX_CTRL_IO);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.attrib = attrib;
  p.font = font;
  p.colorback = colorback;
  p.colortext = colortext;
  p.varno = varno;
  p.xdigits = (digits & MASK_DIGITS) | ((writeprotected != 0)? MASK_WRITEPROTECTED : 0);
  p.iotype = iotype;
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_IOBAR(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colorfront, unsigned char frametype, unsigned char state, unsigned char writeprotected, long og, unsigned char ogstate, long ug, unsigned char ugstate, unsigned char sbit)
{
  _BOX_CTRL_IOBAR p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_IOBAR), BOX_CTRL_IOBAR);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.state     = state;
  if(writeprotected == 0)
    p.state |= 0x80;
  if(ugstate)
    p.state |= 0x10;
  if(ogstate)
    p.state |= 0x20;
  p.colorback = colorback;
  p.colorfront = colorfront;
  p.varno = varno;
  p.og = og;
  p.ug = ug;
  
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_IMAGESCM(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned char frametype, unsigned char attrib, unsigned short varno, unsigned short shemeindex, unsigned char sbit)
{
  _BOX_CTRL_IMAGESCM p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_IMAGESCM), BOX_CTRL_IMAGESCM);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.colorback = colorback;
  p.attrib = attrib;
  p.varno = varno;
  p.shemeindex = shemeindex;
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_TEXTSCM(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned short varno, unsigned short shemeindex, unsigned char sbit)
{
  _BOX_CTRL_TEXTSCM p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_TEXTSCM), BOX_CTRL_TEXTSCM);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.attrib = attrib;
  p.font = font;
  p.colorback = colorback;
  p.colortext = colortext;
  p.varno = varno;
  p.shemeindex = shemeindex;
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_POLYLINE(_XY *pxy, unsigned short no, unsigned short color, unsigned char sbit)
{
  unsigned char tmp[300];
  _BOX_CTRL_POLYLINE *p = (_BOX_CTRL_POLYLINE*)tmp;
  unsigned short rest = 0;
  
  unsigned short maxno = (255 - sizeof(_BOX_CTRL_POLYLINE)) / sizeof(_XY);
  if(no > maxno)
  {
    rest = no - maxno;
    no   = maxno;
  }
  
  setup_CTRLBOX_HEADER(&p->boxhdr, sizeof(_BOX_CTRL_POLYLINE) + (no - 1) * sizeof(_XY), BOX_CTRL_POLYLINE);
  p->color = color;
  p->xyno = no;
  MemCpy3(p->xy, pxy, no * sizeof(_XY));
  
  if(AddScreenEx(&p->boxhdr, sbit) != 0)
  {
    if(rest != 0)
    {
      return AddScreen_CTRL_POLYLINE(pxy+no-1, rest+1, color, sbit);
    }
    return 1;
  }
  return 0;
}

unsigned long AddScreen_CTRL_IMAGE(short x0, short y0, short x1, short y1, unsigned char attrib, unsigned short imgno, unsigned char sbit)
{
  _BOX_CTRL_IMAGE p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_IMAGE), BOX_CTRL_IMAGE);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.img     = imgno;
  p.attrib  = attrib;
  
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_TEXT(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colortext, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned short textno, unsigned char sbit)
{
  _BOX_CTRL_TEXT p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_TEXT), BOX_CTRL_TEXT);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.attrib = attrib;
  p.font = font;
  p.colorback = colorback;
  p.colortext = colortext;
  p.text = textno;
  
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_FRAME(short x0, short y0, short x1, short y1, unsigned short color, unsigned char frametype, unsigned char sbit)
{
  _BOX_CTRL_FRAME p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_FRAME), BOX_CTRL_FRAME);
  p.xy[0].x = x0;
  p.xy[0].y = y0;
  p.xy[1].x = x1;
  p.xy[1].y = y1;
  p.frametype = frametype;
  p.colorback = color;
  
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_OSZI(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colorline, unsigned char attrib, unsigned char frametype, unsigned char index, unsigned char sbit)
{
  _BOX_CTRL_OSZI p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_OSZI), BOX_CTRL_OSZI);
  p.xy[0].x   = x0;
  p.xy[0].y   = y0;
  p.xy[1].x   = x1;
  p.xy[1].y   = y1;
  p.frametype = frametype;
  p.colorback = colorback;  
  p.colorline = colorline;
  p.index     = index;
  p.attrib    = attrib;  
  p.mode      = 0;              
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_LIST(short x0, short y0, short x1, short y1, unsigned short varno, unsigned short colorback, unsigned short colorline, unsigned short colorselect, unsigned char font, unsigned char attrib, unsigned char frametype, unsigned char index, unsigned char sbit)
{
  _BOX_CTRL_LIST p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_LIST), BOX_CTRL_LIST);
  p.xy[0].x     = x0;
  p.xy[0].y     = y0;
  p.xy[1].x     = x1;
  p.xy[1].y     = y1;
  p.varno       = varno;
  p.frametype   = frametype;
  p.colorback   = colorback;  
  p.color       = colorline;
  p.colorselect = colorselect;
  p.index       = index;
  p.attrib      = attrib;  
  p.font        = font;
  return AddScreenEx(&p.boxhdr, sbit);
}

unsigned long AddScreen_CTRL_PIXMAP(short x0, short y0, short x1, short y1, unsigned short colorback, unsigned short colorfront, unsigned char index, unsigned char sbit)
{
  _BOX_CTRL_PIXMAP p;
  setup_CTRLBOX_HEADER(&p.boxhdr, sizeof(_BOX_CTRL_PIXMAP), BOX_CTRL_PIXMAP);
  p.xy[0].x     = x0;
  p.xy[0].y     = y0;
  p.xy[1].x     = x1;
  p.xy[1].y     = y1;
  p.colorback   = colorback;
  p.colorfront  = colorfront;
  p.index       = index;
  return AddScreenEx(&p.boxhdr, sbit);
}

