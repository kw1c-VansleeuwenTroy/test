
#ifndef __HMI_NUC_H
#define __HMI_NUC_H

#define HMI_PRJNAME            "EASY.MPC"

#define HMI_COMPILER_VERSION_MIN      59
#define HMI_COMPILER_VERSION          60
#define HMI_DEFVALUE         -2147483647
#define HMI_DEFCHKBIT            16#FFFF
#define HMI_DEFSCOPE         16#FFFFFFFF
#define HMI_DEFACCESS                  0
#define HMI_DEFFONT                16#FF
#define HMI_DEFFRAME                   0

#define SCHEMEOP_SMALLER            0x00 // <
#define SCHEMEOP_SMALLEQUAL         0x01 // <=
#define SCHEMEOP_EQUAL              0x02 // ==
#define SCHEMEOP_BIGGEREQUAL        0x03 // >=
#define SCHEMEOP_BIGGER             0x04 // >
#define SCHEMEOP_NOTEQUAL           0x05 // !=
#define SCHEMEOP_DEFAULT            0x06 // 


TYPE

  HMI_IMA :   (  HMI_IMA_GARNIX, 
                 // definition von projekteinträgen
                 HMI_IMA_SCREEN,             // screen
                 HMI_IMA_LANGUAGELIST,       // all textlists in specific language
                 HMI_IMA_SERVERLIST,         // serverlist
                 HMI_IMA_SETUPLIST,          // setuplist
                 HMI_IMA_IMAGELIST,          // imageliste
                 HMI_IMA_FONTLIST,           // fontlist
                 HMI_IMA_CHKBITLIST,         // chkbitlist
                 HMI_IMA_KEYPADLIST,         // keyboardlist
                 HMI_IMA_FUNCTIONLIST,       // functionlist
                 HMI_IMA_HIDEDITOR,          // toucheditor
                 HMI_IMA_GUIDEPOSTLIST,      // language guidepost for textlist
                 HMI_IMA_WIN,                // window
                 HMI_IMA_UNITSCHEMA,         // unitschema
                 HMI_IMA_FONTSCHEMA,         // fontschema
                 HMI_IMA_TEXTSCHEMA,         // textschema
                 HMI_IMA_IMAGESCHEMA,        // imageschema
                 HMI_IMA_COLORMAP,           // rgb-table
                 HMI_IMA_V_SERVERNAMETOKEN,  // servernametoken
                 
                 // definition von werten
                 HMI_IMA_DINT_CONSTANT := 30,// konstanter dint wert
                 HMI_IMA_UDINT_CONSTANT,     // konstanter udint wert
                 HMI_IMA_REAL_CONSTANT,      // konstanter real wert
                 HMI_IMA_TIME_CONSTANT,      // konstanter time wert
                 HMI_IMA_DATE_CONSTANT,      // konstanter date wert
                 HMI_IMA_ASCII_CONSTANT,     // konstanter ascii-0-string
                 HMI_IMA_UNI_CONSTANT,       // konstanter uni-0-string
                
                
                 // verweise auf elemente
                 HMI_IMA_V_SERVERLIST := 100, // reference to server (servernumber) 
                 HMI_IMA_V_IMAGELIST,         // reference to image (imagenumber)
    
                 HMI_IMA_V_TEXTLIST00,       // reference to text in textlist 0 (textnumber)
                 HMI_IMA_V_TEXTLIST01,       // reference to text in textlist 1 (textnumber)
                 HMI_IMA_V_TEXTLIST02,       // reference to text in textlist 2 (textnumber)
                 HMI_IMA_V_TEXTLIST03,       // reference to text in textlist 3 (textnumber)
                 HMI_IMA_V_TEXTLIST04,       // reference to text in textlist 4 (textnumber)
                 HMI_IMA_V_TEXTLIST05,       // reference to text in textlist 5 (textnumber)
                 HMI_IMA_V_TEXTLIST06,       // reference to text in textlist 6 (textnumber)
                 HMI_IMA_V_TEXTLIST07,       // reference to text in textlist 7 (textnumber)
                 HMI_IMA_V_TEXTLIST08,       // reference to text in textlist 8 (textnumber)
                 HMI_IMA_V_TEXTLIST09,       // reference to text in textlist 9 (textnumber)
                
                 HMI_IMA_V_SERVERNAME,       // verweis auf servername (servernummer)
                 HMI_IMA_V_SERVERTEXT00,     // verweis auf servertext 00 (servernummer)
                 HMI_IMA_V_SERVERUNITTEXT,   // verweis auf serverunittext (servernummer)
                 HMI_IMA_V_FUNCTIONLIST,     // verweis auf funktionsblock (funktionsblocknummer)
                 HMI_IMA_V_UNIT,             // verweis auf unit (unitnummer)
                 HMI_IMA_V_FONT,             // verweis auf font (fontnummer)
                
                 // verweise auf schema
                 HMI_IMA_V_UNITSCHEMA,       // verweis auf unitschema (schemanummer)
                 HMI_IMA_V_FONTSCHEMA,       // verweis auf fontschema (schemanummer)
                 HMI_IMA_V_TEXTSCHEMA,       // verweis auf textschema (schemanummer)
                 HMI_IMA_V_IMAGESCHEMA,      // verweis auf imageschema (schemanummer)

//                 hIMA_V_ALARMTEXTLIST,    // reference to text in alarmtextlist (textnumber)
                 
                 // verweise auf bildinhalte (zorder) 
                 HMI_IMA_V_RECTANGLE := 200, // verweis auf rectangle (zorder)
                 HMI_IMA_V_LINE,             // verweis auf linie (zorder)
                 HMI_IMA_V_CIRCLE,           // verweis auf circle (zorder)
                 HMI_IMA_V_TEXT,             // verweis auf text (zorder)
                 HMI_IMA_V_IMAGE,            // verweis auf image (zorder)
                 HMI_IMA_V_IO                // verweis auf io oder button (zorder)
                
              )$usint; 

  HMI_VARTYPE:(  HMI_FREE, 
                 HMI_BINARY, 
                 HMI_TIME, 
                 HMI_DATE, 
                 HMI_STRING,       // string
                 HMI_BIT,          // bit datatype
                 HMI_COMPLEX,      // structure, complex
                 HMI_CONSTANT,     // constant type
                 HMI_OBJECT,       // objecttype
                 HMI_COMPONENT,    // komponente von struktur
                 HMI_MERKER,       // merker
                 HMI_ENUM,         // enum
                 HMI_ENUMITEM      // enumitem
              )$usint; 

  HMI_QBEF :  (  HMI_QNOP,                // nothing (0)
                 HMI_QCALL_SCREEN,        // call screen (1)
                 HMI_QRETURN,             // goto previous screen (0)
                 HMI_QSET_SERVER,         // set server (2)
                 HMI_QINC_SERVER,         // inc server (1)
                 HMI_QDEC_SERVER,         // dec server (1)
                 HMI_QADD_SERVER,         // add server (2)
                 HMI_QSUB_SERVER,         // sub server (2)
                 HMI_QTOGGLE_SERVER,      // toggle server (1)
                 HMI_QLED,                // illuminate led (2)
                 HMI_QLANGUAGE,           // switch language (1)
                 HMI_QBEEP,               // beep (2)
                 HMI_QUSER_CALL,          // usercall (2)
                 HMI_QKEY_CODE,           // keycode (1)
                 HMI_QCALL_WINDOW,        // call window (1)
                 HMI_QIF_EQUAL,           // if (2)
                 HMI_QIF_GREAT,           // if (2)
                 HMI_QIF_SMALL,           // if (2)
                 HMI_QIF_ELSE,            // else (0)
                 HMI_QIF_END,             // end (0)
                 HMI_QEDIT_SAVE,          // edit save (0)
                 HMI_QFUNCTION_BLOCK,     // call functionblock (1)
                 HMI_QOPEN_IO             // open editor by using servernumber (1)
                 
//                 HMI_QSCRSAVER_ON,        // turn on screensaver (0)
//                 HMI_QSCRSAVER_OFF,       // turn off screensaver (0)
//                 HMI_QOFFLINE,            // call offlinescreen (0)
//                 HMI_QGET_SERVERID,       // get all serverid's (0)
//                 HMI_QCALL_TOUCHEDITOR,   // open toucheditor (1)
//                 HMI_QCLOSE_IO,           // close activated editor-io (0)
//                 HMI_QOPEN_IO_XY,         // open editor by using xy-position (2)
//                 HMI_QCALL_ROOTSCREEN     // recall rootscreen (0)
                 
              )$uint; 

  HMI_IOTYPE:(   HMI_IOT_DEFAULT,      
                 HMI_IOT_NUMERIC,      // display io as numeric, date, time
                 HMI_IOT_STRING,       // display io as string
                 HMI_IOT_BAR,          // display bar
                 HMI_IOT_NC,           // momentan ungenützt
                 HMI_IOT_CHKBOX,       // checkbox 
                 HMI_IOT_RADIOBUTTON,  // radiobutton
                 HMI_IOT_BUTTON,       // touch-button
                 HMI_IOT_SCHEMA,       // textschema, imageschema
                 HMI_IOT_NUMERIC_HIDE, // display io as numeric, date, time
                 HMI_IOT_STRING_HIDE,  // display io as string
                 HMI_IOT_IPADDRESS,    // display io as ipaddress
                 HMI_IOT_ENUMERATION   // display io as enumeration
             )$usint; 


  HMI_DTF :  (   HMI_DEFAULT,
                 HMI_TRUE,
                 HMI_FALSE
             )$usint; 
          
  HMI_XY : struct
    x           : INT;
    y           : INT;
  end_struct;
  
  HMI_ROOM : struct
    xy1         : HMI_XY;
    xy2         : HMI_XY;
  end_struct;

  HMI_ANYTHING : struct
    ima         : HMI_IMA;
    value       : DINT;
  end_struct;

  HMI_CHKBIT    : struct
    invert      : USINT;
    no          : UINT;
  end_struct;

  HMI_VAR_FLAGS : bsint
              [
               1 datavalid,
               2 leading0,
              ];

  HMI_VARINFO : struct
    station     : usint;
    reftime     : usint;
    access      : usint;
    vartype     : HMI_VARTYPE;
    subtype     : uint;
    limit_hi    : HMI_ANYTHING;
    limit_lo    : HMI_ANYTHING;
    text1       : HMI_ANYTHING;
    unitschema  : HMI_ANYTHING;
    scope       : udint;
    chkbit      : HMI_CHKBIT;
    parabit16   : uint;
    flags       : HMI_VAR_FLAGS;
    
    lasalid     : udint;
    index35     : udint;   
    oldval      : dint;
    escm_index35: udint;
    
//    enumidx     : uint;
//    datavalid  : bool;
  end_struct; 

  HMI_IMAGEINFO : struct
    width       : uint; 
    height      : uint; 
    transparent : uint; 
    state       : uint; 
    datano      : udint; 
    ptr         : ^void;
    index35     : udint;
  end_struct; 

  HMI_FONTINFO  : struct
    size        : udint;
    ptr         : ^void;
    attrib      : UDINT;
    index35     : UDINT;
  end_struct;

  HMI_XUNIT : struct
    digits      : HMI_ANYTHING;
    posdezpt    : HMI_ANYTHING;
    formula     : usint;
    text        : HMI_ANYTHING;
    leading0    : HMI_DTF;         
  end_struct; 

  HMI_PRJINFO : struct
    ima         : HMI_ANYTHING; 
    access      : usint; 
    chkbit      : HMI_CHKBIT; 
    name        : array[0..12] of char; 
  end_struct;

  HMI_SCHEMELINE : struct
    op2         : DINT;
    any         : HMI_ANYTHING;
    operator    : USINT;
  end_struct; 
  
  HMI_SCHEME : struct
    no          : UINT;
    ptr         : ^HMI_SCHEMELINE;
    serverno    : udint;
    index35     : udint;
  end_struct;

  HMI_FCTLINE : struct
    qbef        : HMI_QBEF;
    op1         : HMI_ANYTHING;
    op2         : HMI_ANYTHING;
  end_struct;
  
  HMI_FCTBLOCK : struct
    no          : UINT;
    ptr         : ^HMI_FCTLINE;
    index35     : UDINT;
  end_struct;
  
  HMI_CTRL_CIRCLE : STRUCT
	  room        : HMI_ROOM;
	  color       : USINT;
	  attrib      : UDINT;
	  chkbit      : HMI_CHKBIT;
	  angle       : INT;
	  arc         : INT;
	END_STRUCT;
  
	HMI_CTRL_IMAGE : STRUCT
	  room        : HMI_ROOM;
	  colorback   : USINT;
	  attrib      : UDINT;
	  chkbit      : HMI_CHKBIT;
	  any         : HMI_ANYTHING;
	END_STRUCT;
    
  HMI_GFUNCT : struct
    pos_edge    : HMI_ANYTHING;
    neg_edge    : HMI_ANYTHING;
    triggertype : usint;
  end_struct;
    
  HMI_CTRL_IO : struct
    room        : HMI_ROOM;
    chkbit      : HMI_CHKBIT;
    attrib      : UDINT;
    font        : USINT;
    color_back  : USINT;
    color_text  : USINT;
    server      : HMI_ANYTHING;
    anything1   : HMI_ANYTHING; // offset bei balken oder verweis auf LIST (text, image)
    anything2   : HMI_ANYTHING; // maxwert bei balken oder offset bei LIST (text, image)
    anything3   : HMI_ANYTHING; // minwert bei balken oder maxwert (range) bei LIST (text, image)
    anything4   : HMI_ANYTHING; // image pressed, nur bei button
    
    iotype      : HMI_IOTYPE;
    writeprotect: bool;
    access      : usint;
    enterplus   : usint;
    hotkey      : udint;        // nur BUTTON
    gfunct      : HMI_GFUNCT;   // nur BUTTON
    setval      : dint;         // nur BUTTON
    resetval    : dint;         // nur BUTTON
    act_momntry : bool;         // nur BUTTON
    no_myio     : udint;
    imagealign  : usint;
    selector    : usint;
    frame       : usint;
    
    h_next      : usint;
    v_next      : usint;
  end_struct; 
  
	HMI_CTRL_LINE : STRUCT
	  color       : USINT;
	  attrib      : UDINT;
	  chkbit      : HMI_CHKBIT;
    no          : UINT;
    ptxy        : ^HMI_XY;
	END_STRUCT;

	HMI_CTRL_RECTANGLE : STRUCT
    room        : HMI_ROOM;
	  color       : USINT;
	  attrib      : UDINT;
	  chkbit      : HMI_CHKBIT;
    frame       : USINT;
	END_STRUCT;

  HMI_CTRL_TEXT : STRUCT
    room        : HMI_ROOM;
    colorback   : USINT;
    colortext   : USINT;
    attrib      : UDINT;
    font        : USINT;
    chkbit      : HMI_CHKBIT;
    anything    : HMI_ANYTHING;
    frame       : USINT;
  END_STRUCT;
  
END_TYPE

FUNCTION GLOBAL init_HMI_ROOM VAR_INPUT ptr : ^HMI_ROOM; END_VAR;
FUNCTION GLOBAL free_HMI_ROOM VAR_INPUT ptr : ^HMI_ROOM; END_VAR;
FUNCTION GLOBAL init_HMI_CHKBIT VAR_INPUT ptr : ^HMI_CHKBIT; END_VAR;
FUNCTION GLOBAL free_HMI_CHKBIT VAR_INPUT ptr : ^HMI_CHKBIT; END_VAR;
FUNCTION GLOBAL init_HMI_ANYTHING VAR_INPUT ptr : ^HMI_ANYTHING; END_VAR;
FUNCTION GLOBAL free_HMI_ANYTHING VAR_INPUT ptr : ^HMI_ANYTHING; END_VAR;
FUNCTION GLOBAL init_HMI_VARINFO VAR_INPUT ptr : ^HMI_VARINFO; END_VAR;
FUNCTION GLOBAL free_HMI_VARINFO VAR_INPUT ptr : ^HMI_VARINFO; END_VAR;
FUNCTION GLOBAL init_HMI_XUNIT VAR_INPUT ptr : ^HMI_XUNIT; END_VAR;
FUNCTION GLOBAL free_HMI_XUNIT VAR_INPUT ptr : ^HMI_XUNIT; END_VAR;
FUNCTION GLOBAL init_HMI_PRJINFO VAR_INPUT ptr : ^HMI_PRJINFO; END_VAR;
FUNCTION GLOBAL free_HMI_PRJINFO VAR_INPUT ptr : ^HMI_PRJINFO; END_VAR;
FUNCTION GLOBAL init_HMI_SCHEMELINE VAR_INPUT ptr : ^HMI_SCHEMELINE; END_VAR;
FUNCTION GLOBAL free_HMI_SCHEMELINE VAR_INPUT ptr : ^HMI_SCHEMELINE; END_VAR;
FUNCTION GLOBAL init_HMI_SCHEME VAR_INPUT ptr : ^HMI_SCHEME; END_VAR;
FUNCTION GLOBAL free_HMI_SCHEME VAR_INPUT ptr : ^HMI_SCHEME; END_VAR;
FUNCTION GLOBAL init_HMI_FCTLINE VAR_INPUT ptr : ^HMI_FCTLINE; END_VAR;
FUNCTION GLOBAL free_HMI_FCTLINE VAR_INPUT ptr : ^HMI_FCTLINE; END_VAR;
FUNCTION GLOBAL init_HMI_GFUNCT VAR_INPUT ptr : ^HMI_GFUNCT; END_VAR;
FUNCTION GLOBAL free_HMI_GFUNCT VAR_INPUT ptr : ^HMI_GFUNCT; END_VAR;

FUNCTION GLOBAL init_HMI_CTRL_IO VAR_INPUT pio : ^HMI_CTRL_IO; END_VAR;
FUNCTION GLOBAL free_HMI_CTRL_IO VAR_INPUT pio : ^HMI_CTRL_IO; END_VAR;
FUNCTION GLOBAL init_HMI_CTRL_CIRCLE VAR_INPUT ptr : ^HMI_CTRL_CIRCLE; END_VAR;
FUNCTION GLOBAL free_HMI_CTRL_CIRCLE VAR_INPUT ptr : ^HMI_CTRL_CIRCLE; END_VAR;
FUNCTION GLOBAL init_HMI_CTRL_IMAGE VAR_INPUT ptr : ^HMI_CTRL_IMAGE; END_VAR;
FUNCTION GLOBAL free_HMI_CTRL_IMAGE VAR_INPUT ptr : ^HMI_CTRL_IMAGE; END_VAR;
FUNCTION GLOBAL init_HMI_CTRL_RECTANGLE VAR_INPUT ptr : ^HMI_CTRL_RECTANGLE; END_VAR;
FUNCTION GLOBAL free_HMI_CTRL_RECTANGLE VAR_INPUT ptr : ^HMI_CTRL_RECTANGLE; END_VAR;
FUNCTION GLOBAL init_HMI_CTRL_TEXT VAR_INPUT ptr : ^HMI_CTRL_TEXT; END_VAR;
FUNCTION GLOBAL free_HMI_CTRL_TEXT VAR_INPUT ptr : ^HMI_CTRL_TEXT; END_VAR;

#endif
