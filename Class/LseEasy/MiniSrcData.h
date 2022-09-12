// +-------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                          |
// +-[      author ] kolott                                                        |
// +-[        date ] 04.12.2013                                                    |
// +-[ description ]---------------------------------------------------------------+
// |                                                                               |
// |                                                                               |
// +-------------------------------------------------------------------------------+

#define MASK_FRAME                       0x7F
#define MASK_FRAMEINVERT                 0x80

#define VARNO_SPEZIAL                  0xFE00 // index to recognize spezialvarno
// note: numbers from 0xFE01 to 0xFEFF are reserved for extentional (userconfigurated) variables
#define VARNO_ACT_HUMIDITY             0xFFE5 // varno to get humidity
#define VARNO_DISPLAY_ROTATE           0xFFE6 // varno to get/set displayrotation
#define VARNO_DISPLAY_PIXEL_WIDTH      0xFFE7 // varno to get displaywidth in pixel (ab version 1.41)
#define VARNO_DISPLAY_PIXEL_HEIGHT     0xFFE8 // varno to get displayheight in pixel (ab version 1.41)
#define VARNO_USER_PRJ_REVISION        0xFFE9 // varno to get user-project-revisionnumber
#define VARNO_FW_SIGN_VALUE            0xFFEA // varno firmwaresignevalue (crazybits at index 7 in vectortable)
#define VARNO_HW_PLATFORM              0xFFEB // varno hardware plattform (1145, 1203, 1296)
#define VARNO_IRCODECNT                0xFFEC // varno ir-code counter
#define VARNO_IRCODE                   0xFFED // varno ir-code
#define VARNO_TEST_NUM0                0xFFEE // varno testvariable0
#define VARNO_TEST_NUM1                0xFFEF // varno testvariable1
#define VARNO_PRODUCT_NAME             0xFFF0 // varno productname
#define VARNO_BOOTLOADER_VERSION       0xFFF1 // varno bootloaderversion
#define VARNO_CANTXMSG                 0xFFF2 // varno canTxMsgID
#define VARNO_CANRXMSG                 0xFFF3 // varno canRxMsgID
#define VARNO_TABSOLUTE_333            0xFFF4 // varno tabsolute / 333 (absoluter ms-counter / 333)
#define VARNO_EXTENTION_SWVERSION      0xFFF5 // varno firmwareextention (zb. logimover) 
#define VARNO_HWVERSION                0xFFF6 // varno hardware version
#define VARNO_ACT_TEMPERATURE          0xFFF7 // varno akttemperature
#define VARNO_BACKLIGHT_TIMEOFF        0xFFF8 // varno 
#define VARNO_ACTSCRNO                 0xFFF9 // varno act.screennumber
#define VARNO_SWVERSION                0xFFFA // varno firmware version
#define VARNO_CANNODE                  0xFFFB // varno cannodenr
#define VARNO_CANBAUD                  0xFFFC // varno canbaudrate
#define VARNO_BACKLIGHT_DIM            0xFFFD // varno displaycontrast
#define VARNO_EDITOR                   0xFFFE // varno editorvariable
#define VARNO_DEFAULT                  0xFFFF // defaultvariablenumber

#define SCREENNUMBER_SPEZIAL           0xFFE0 // index to recognize spezialscreen
#define SCREENNUMBER_EDITOR_NUMERIC    0xFFF3 // numeric editor
#define SCREENNUMBER_CANSETUP          0xFFF4 // can setup
#define SCREENNUMBER_EDITOR_HEX        0xFFF5 // hex editor
#define SCREENNUMBER_EDITOR_TIME       0xFFF6 // time editor
#define SCREENNUMBER_EDITOR_STRING     0xFFF7 // anumeric editor
#define SCREENNUMBER_EDITOR_TIMEUSA    0xFFF8 // usa-time editor
#define SCREENNUMBER_OFFLINEFIRST      0xFFF9 // first-offlinescreennumber
#define SCREENNUMBER_INFO              0xFFFA // setupinfoscreen
#define SCREENNUMBER_TOUCHTEST         0xFFFB // touchtestscreennumber
#define SCREENNUMBER_STARTUP           0xFFFC // startupscreennumber
#define SCREENNUMBER_SETUP             0xFFFD // setupscreennumber
#define SCREENNUMBER_OFFLINE           0xFFFE // offlinescreennumber
#define SCREENNUMBER_DEFAULT           0xFFFF // defaultscreennumber

#define TXT_SPEZIAL                    0xFEFF // textindex to recognize spezialtext
#define TXT_SPEZIAL_CHARACTER          0xFF00 // textindex 'single character'
#define TXT_SPEZIAL_OFFLINETEXTQUITFIRST 0xFFF9 // textindex "Press Screen to hide|message for 10 minutes..."
#define TXT_SPEZIAL_OFFLINETEXTFIRST   0xFFFA // textindex "Wait for connection to PLC"
#define TXT_SPEZIAL_OFFLINETEXTQUIT    0xFFFB // textindex "Press to Quit message for 10 minutes..."
#define TXT_SPEZIAL_OFFLINETEXT        0xFFFC // textindex "PLC - OFFLINE" 
#define TXT_SPEZIAL_EDITOR_DESCRIBINGTEXT 0xFFFD // show describingtext of actual editor
#define TXT_SPEZIAL_EDITOR_UNITTEXT       0xFFFE // show unittext of actual editor

#define FUN_SPEZIAL                    0xFEF0 // index to recognize spezialfunction
#define FUN_SPEZIAL_STARTVISU          0xFEF1 // spezialfunct start visu
#define FUN_SPEZIAL_RETURN             0xFEF2 // spezialfunct return screen
#define FUN_SPEZIAL_QUITOFFLINE        0xFEF3 // spezialfunct quit offlinescreen
#define FUN_SPEZIAL_SCANCODE           0xFF00 // spezialfunct scancode (keypress)

#define KeyT9_0                             1
#define KeyT9_1                             2
#define KeyT9_2                             3
#define KeyT9_3                             4
#define KeyT9_4                             5
#define KeyT9_5                             6
#define KeyT9_6                             7
#define KeyT9_7                             8
#define KeyT9_8                             9
#define KeyT9_9                            10
#define KeyT9_COMMA                        11
#define KeyT9_BIG                          12
#define KeyT9_HEX                          16 
#define KeyENTER                           13 // scancode: ENTER
#define KeyAMPM                            14 // scancode: am/pm
#define KeyCLOSE                           15 // scancode: CLOSE
#define KeyESC                             27 // scancode: ESC

#define BIGBOX_VARLIST                   0x80 // bigboxid: projectentry varlist
#define BIGBOX_TEXTLIST                  0x81 // bigboxid: projectentry textlist
#define BIGBOX_IMAGE                     0x82 // bigboxid: projectentry single image
#define BIGBOX_SCREEN                    0x83 // bigboxid: projectentry single screen
#define BIGBOX_FONT                      0x84 // bigboxid: projectentry single font
#define BIGBOX_FUNCTIONLIST              0x85 // bigboxid: projectentry functionblocklist
#define BIGBOX_SHEMELIST                 0x86 // bigboxid: projectentry shemelist
#define BIGBOX_SETUPLIST                 0x87 // bigboxid: projectentry projectsettings (Keypad, ...)
#define BIGBOX_BOOTIMAGE                 0x88 // bigboxid: projectentry bootimage 
#define BIGBOX_KEYBRD_T9                 0x89 // bigboxid: projectentry t9-keyboard konfiguration

#define BOX_CTRL_NC                      0x00 // boxid: not connected
#define BOX_CTRL_BUTTON                  0x01 // boxid: button
#define BOX_CTRL_IO                      0x02 // boxid: output
#define BOX_CTRL_TEXT                    0x03 // boxid: text
#define BOX_CTRL_TEXTSCM                 0x04 // boxid: textscheme
#define BOX_CTRL_IMAGE                   0x05 // boxid: image
#define BOX_CTRL_IMAGESCM                0x06 // boxid: imagescheme
#define BOX_CTRL_IOBAR                   0x07 // boxid: bar-view (0-100%)
#define BOX_CTRL_POLYLINE                0x08 // boxid: polyline
#define BOX_CTRL_FRAME                   0x09 // boxid: frame
#define BOX_CTRL_PIXMAP                  0x0A // boxid: pixmap
#define BOX_CTRL_BUSY                    0xFC // boxid: busy
#define BOX_CTRL_LIST                    0xFD // boxid: list
#define BOX_CTRL_OSZI                    0xFE // boxid: oszi
#define BOX_CTRL_TOUCHTEST               0xFF // boxid: touchtest

#define IOTYPE_NUMERIC                      0 // iotype: numeric (decimal)
#define IOTYPE_TIME                         1 // iotype: time
#define IOTYPE_DATE                         2 // iotype: date
#define IOTYPE_IP                           3 // iotype: ip-address
#define IOTYPE_STRING                       4 // iotype: string
#define IOTYPE_NUMERIC_HIDE                 5 // iotype: numeric hide (decimal)
#define IOTYPE_CHKBOX                       6 // iotype: chkbox
#define IOTYPE_STRING_HIDE                  7 // iotype: string hide
#define IOTYPE_NUMERIC_HEX                  8 // iotype: numeric (hexadezimal)

#define DATEFORMAT_DDMMYY                   0 // displayformat: DD.MM.YY
#define DATEFORMAT_DDMMYYYY                 1 // displayformat: DD.MM.YYYY
#define DATEFORMAT_DDMM                     2 // displayformat: DD.MM

#define TIMEFORMAT_HHMM                     0 // displayformat: HH:MM
#define TIMEFORMAT_HHMMSS                   1 // displayformat: HH:MM:SS
#define TIMEFORMAT_MMSS                     2 // displayformat: MM:SS

#define DATIM_USA                        0x10 // indicater: american format of date or time

#define mCMD_NOP                         0x00 // command: do nothing
#define mCMD_SCREEN                      0x01 // command: call screen
#define mCMD_ADD                         0x02 // command: add (increment) variable
#define mCMD_SUB                         0x03 // command: sub (decrement) variable
#define mCMD_SET                         0x04 // command: set variable
#define mCMD_RETURN                      0x05 // command: return to previous screen
#define mCMD_KEYPRESS                    0x06 // command: keypress
#define mCMD_TOGGLE                      0x07 // command: toggle
#define mCMD_IFLOW                       0x08 // command: if <
#define mCMD_IFEQ                        0x09 // command: if =
#define mCMD_IFHIGH                      0x0A // command: if >
#define mCMD_IFELSE                      0x0B // command: if else
#define mCMD_IFEND                       0x0C // command: if end
#define mCMD_CFB                         0x0D // command: call functionblock
#define mCMD_USERCALL                    0x0E // command: usercall

#define mSHMOP_SMALLER                   0x00 // shemecommand
#define mSHMOP_SMALLEQUAL                0x01 // shemecommand
#define mSHMOP_EQUAL                     0x02 // shemecommand
#define mSHMOP_BIGGEREQUAL               0x03 // shemecommand
#define mSHMOP_BIGGER                    0x04 // shemecommand
#define mSHMOP_NOTEQUAL                  0x05 // shemecommand

#define SBIT_VISIBLE                     0x01 // visiblebit (0..invisible, 1..visible)
#define SBIT_ACCESS                      0x02 // writeprotectedbit (0..writeprootected, 1..writeenabled)

// ************************************************************************************
// ** commands used for communication 
// ************************************************************************************

#define ComCMD_UPDATE                    0x10 // update 32bit variable
#define ComCMD_UPDATESTRING              0x11 // update unicode-stringvariable
#define ComCMD_UPDATETREND0_SINGLE       0x12 // update single trendvalue
#define ComCMD_UPDATETREND0              0x13 // update multiple trendvalue
#define ComCMD_UPDATETREND1_SINGLE       0x14 // update single trendvalue
#define ComCMD_UPDATETREND1              0x15 // update multiple trendvalue
#define ComCMD_UPDATESTATEBIT            0x16 // update statebit (checkbit, statescheme, access)
#define ComCMD_UPDATEGVAL                0x17 // update g-values (x, y, z) + accelerationvalue
#define ComCMD_UPDATELIST0_CMD           0x18 // update list (command for list)
#define ComCMD_UPDATELIST0_ADD           0x19 // update list0 (add new entry)
#define ComCMD_UPDATELIST1_ADD           0x1A // update list1 (command for list)
#define ComCMD_USERCALL                  0x1B // perform usercall
#define ComCMD_UPDATESTRINGASCII         0x1C // update asciicode-stringvariable
#define ComCMD_UPDATEVARIABLE            0x1D // answer of command ComCMD_ASK_VARIABLE
#define ComCMD_UPDATEPIXMAP              0x1E // update pixmap

#define ComCMD_RESET                     0x21 // reset
#define ComCMD_RUN                       0x22 // run
#define ComCMD_PROGRESSBAR               0x23 // show progressbar
#define ComCMD_SCREEN                    0x24 // switch screen
#define ComCMD_SCREENRETURN              0x25 // goto previous screen
#define ComCMD_BACKLIGHT                 0x26 // backlight on/off
#define ComCMD_RESTARTSETUP              0x27 // restart with setup
#define ComCMD_REBOOT                    0x28 // reboot
#define ComCMD_UPDATESOFTWARE            0x29 // activate bootloader to receive softwareupdate (wait 1000ms afterwards)
#define ComCMD_BACKLIGHTTIME             0x2A // set time to backlight off (screensaver)
#define ComCMD_ACTSCREEN                 0x2B // send actual screennumber from hmi to plc
#define ComCMD_ERROR_TRACEVIEW           0x2C // view errormessage, check traceview for details
#define ComCMD_HMI_INUSE                 0x2D // send that hmi is in use (from hmi to plc)
#define ComCMD_BACKLIGHTDIM              0x30 // backlight on/off
#define ComCMD_SCREENSHOT                0x31 // screenshot (from hmi to plc)

#define ComCMD_FLASHKILL                 0x40 // kill flash                 --> answer: ComCMD_FLASHDATAREADY  + [4] 0xFFFFFFFF
#define ComCMD_FLASHWRITE                0x41 // write data into flash      --> answer: ComCMD_FLASHDATAREADY  + [4] fileid
#define ComCMD_FLASHREAD                 0x42 // read file from flash       --> answer: ComCMD_FLASHWRITE + fileid + _BIGBOX + data

#define ComCMD_ASK_TEMP                  0x50 // ask for temperature        --> answer: ComCMD_TEMP            + [4] akt temperature
#define ComCMD_ASK_HW_VER                0x51 // ask for hardwareversion    --> answer: ComCMD_HW_VER          + [4] hw-versionsnummer
#define ComCMD_ASK_SW_VER                0x52 // ask for softwareversion    --> answer: ComCMD_SW_VER          + [4] sw-versionsnummer
#define ComCMD_ASK_HARDWAREDATA          0x53 // ask for hardwaredata       --> answer: ComCMD_SYSTEMDATA      + [sizeof(_HARDWAREINFO)] 
#define ComCMD_ASK_FILE_CRC              0x54 // ask for filecrc            --> answer: ComCMD_FILE_CRC        + [4] filecrc
#define ComCMD_ASK_PROJECTINFO           0x55 // ask for projectinfo        --> answer: ComCMD_PROJECT         + [] _BOX_PROJECTLIST_EX
#define ComCMD_ASK_ALIVE                 0x56 // ask for alivesignal        --> answer: ComCMD_ALIVE
#define ComCMD_ASK_BACKLIGHTINFO         0x57 // ask for backlightDimOnOff  --> answer: ComCMD_BACKLIGHTDIM    + [1] actual info 1xxxxxxx
#define ComCMD_ASK_SCREENSHOT            0x58 // ask for screenshot         --> answer: ComCMD_SCREENSHOT
#define ComCMD_ASK_ACTSCREEN             0x59 // ask for actual screennumber--> answer: ComCMD_ACTSCREEN       + [2] act.screennumber
#define ComCMD_ASK_VARIABLE              0x5A // ask for variable           --> answer: ComCMD_UPDATE_VARIABLE + [2] varno

#define ComCMD_TEMP                      0x60 // temperature + Humidity (optional)
#define ComCMD_HW_VER                    0x61 // hardwareversion
#define ComCMD_SW_VER                    0x62 // softwareversion
#define ComCMD_HARDWAREDATA              0x63 // hardwaredata
#define ComCMD_FILE_CRC                  0x64 // filecrc
#define ComCMD_PROJECTINFO               0x65 // projectinfo
#define ComCMD_ALIVE                     0x66 // alivetrigger
#define ComCMD_BACKLIGHTINFO             0x67 // backlightstate on/off(hibit) + dim(low7bit)

#define ComCMD_FLASHDATAREADY            0x70 // write data into flash is ready
#define ComCMD_FLASHDATAERROR            0x71 // flash data error (crc is wrong)

#define ComCMD_EXTENTION                 0xFF // extended data, just forwarded to MiniExtention::ExentionComDataIRQ()

// ************************************************************************************
// ** BIGBOX 
// ************************************************************************************

#pragma pack (push, 1)

typedef struct
{
  unsigned long   size;              // boxsize in byte (inclusive size of _BIGBOX_HEADER)
  unsigned long   crc32;             // crc32 of data (exclusive size of _BIGBOX_HEADER)
}
_BIGBOX_HEADER;


// ************************************************************************************
// ** BOX FONT
// ************************************************************************************

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned char   data[1];           // fontdata (arraysize depends on number of enclosed controls) 
}
_BOX_FONTLIST;

// ************************************************************************************
// ** BOX SETUPLIST
// ************************************************************************************
typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned short  color_button;      // color of button
  unsigned short  color_button_text; // color of buttontext
  unsigned short  color_title_text;  // color of titletext
  unsigned short  color_limit_text;  // color of limittext
  unsigned short  color_window;      // backgroundcolor 
	unsigned char   button_frametype;  // frametype button
	unsigned char   window_frametype;  // frametype window
	unsigned short  user_prj_revision; // user-project revision
  unsigned char   font_standard;       // standard font 
  unsigned char   font_standard_small; // standardfont small
}
_BOX_SETUPLIST;

// ************************************************************************************
// ** BOX VARLIST
// ************************************************************************************

#define VARTYPE_STRING   0xFFFE

typedef struct
{
  long           og;
  long           ug;
  unsigned short textunit;           // index to unittext or 0xFFFE if vartype is string 
  unsigned short textdescribing;     // 2 msb's are reserved for variable limits (0x8000..og, 0x4000..ug)
}
_BOX_VARLIST_ENTRY;

typedef struct
{
  _BIGBOX_HEADER     boxhdr;         // boxheader
  unsigned short     no;             // number of valid entries
  _BOX_VARLIST_ENTRY data[1];        // variable (arraysize depends on number of enclosed controls) 
}
_BOX_VARLIST;

// ************************************************************************************
// ** BOX FUNCTIONLIST
// ************************************************************************************

typedef struct
{
  unsigned char      cmd;            // command (0x3F) and bitmask for const or variable op1 (0x80), op2 (0x40)
  long               op1;            // operand1
  long               op2;            // operand2
}
_BOX_FUNCTLINE;

typedef struct
{
  unsigned char      no;
  _BOX_FUNCTLINE     data[1];
}
_BOX_FUNCTBLOCK;

typedef struct
{
  _BIGBOX_HEADER     boxhdr;         // boxheader
  unsigned short     no;             // number of valid entries
  _BOX_FUNCTBLOCK    data[1];        // functionlistdata (arraysize depends on number of enclosed functionblocks) 
}
_BOX_FUNCTLIST;

// ************************************************************************************
// ** BOX SHEMELIST
// ************************************************************************************

typedef struct
{
  unsigned char      cmd;            // operator
  unsigned short     index;          // result
  long               value;          // operand
}
_BOX_SHEMELINE;

typedef struct
{
  unsigned char      no;
  _BOX_SHEMELINE     data[1];
}
_BOX_SHEMEBLOCK;

typedef struct
{
  _BIGBOX_HEADER     boxhdr;         // boxheader
  unsigned short     no;             // number of valid entries
  _BOX_SHEMEBLOCK    data[1];        // functionlistdata (arraysize depends on number of enclosed shemeblocks) 
}
_BOX_SHEMELIST;

// ************************************************************************************
// ** BOX TEXTLIST
// ************************************************************************************

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned short  no;                // number of enclosed unicode-o-strings
  unsigned char   data[1];           // unicodetexte (arraysize depends on number of enclosed strings) 
}
_BOX_TEXTLIST;

// ************************************************************************************
// ** BOX T9Config
// ************************************************************************************

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned short  no_planes;         // number of planes
  unsigned short  no_keys;           // number of keys
  unsigned char   data[72];          // keytab (12keys zu je 6bytes)
}
_BOX_T9CONFIGLIST;

// ************************************************************************************
// ** BOX IMAGE
// ************************************************************************************

typedef struct
{
  unsigned short  mp;                // has to be set to 0x504D
  unsigned long   datano;            // number of entries at data
  unsigned short  width;             // imagewidth in pixel
  unsigned short  height;            // imageheight in pixel
  unsigned short  transparent;       // color used as transparent
  unsigned short  state;             // imageinformation
  unsigned char   data[1];           // image (arraysize depends on number of enclosed controls) 
}
_PIXMAGE;

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  _PIXMAGE        image;
}
_BOX_IMAGE;

// ************************************************************************************
// ** BOX PROJECTLIST
// ************************************************************************************

typedef struct
{
  unsigned short  listid;
  unsigned short  number;
  unsigned short  filename;
}
_BOX_PROJECTLIST_ENTRY;

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned short  start_screen;      // number of startscreen
  unsigned short  timex_backlight;   // time to switch off displaybacklight [seconds]
  unsigned short  timex_sendtemp;    // time to send temperature
  unsigned short  compilerversion;   // compilerversion
  unsigned long   prjcrc;            // projectcrc
  unsigned short  no;                // number of valid entries
  _BOX_PROJECTLIST_ENTRY data[1];    // projectentry (arraysize depends on number of enclosed controls) 
}
_BOX_PROJECTLIST;

typedef struct
{
  unsigned short  listid;
  unsigned short  number;
  unsigned short  filename;
  unsigned long   filecrc;
}
_BOX_PROJECTLIST_ENTRY_EX;

typedef struct
{
  unsigned long   filecrc;           // projectcrc
  unsigned long   flashfrags;        // info about unused fragments in flash
  unsigned short  no;                // number of valid entries
  _BOX_PROJECTLIST_ENTRY_EX data[1]; // projectentry (arraysize depends on number of enclosed controls) 
}
_BOX_PROJECTLIST_EX;

// ************************************************************************************
// ** BOX SCREEN
// ************************************************************************************

typedef struct
{
  _BIGBOX_HEADER  boxhdr;            // boxheader
  unsigned short  screennumber;      // screennumber
  unsigned short  colorback;         // backgroundcolor
  unsigned short  startfunct;        // startfunktionsindex
  unsigned short  endfunct;          // endfunktionsindex
  unsigned short  ctrlno;            // number of enclosed controls
  unsigned char   data[1];           // controldata (arraysize depends on number of enclosed controls) 
}
_BOX_SCREEN;

typedef struct
{
  short           x;                 // horizontal-coordinate in pixel
  short           y;                 // vertical-coordinate in pixel
}
_XY;

typedef struct
{
  unsigned char   size;              // boxsize in byte (inclusive size of boxheader)
  unsigned char   id;                // boxid
}
_CTRLBOX_HEADER;

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  unsigned short  color;             // color of line
  unsigned short  xyno;              // number of enclosed xy-coordinates
  _XY             xy[1];             // coordinatedata (arraysize depends on number of enclosed coordinates)
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_POLYLINE;
#define _SBITOFF_CTRL_POLYLINE   6


#define MASK_DIGITS          0x7F
#define MASK_DIGITS_NK       0x07
#define MASK_WRITEPROTECTED  0x80

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;         // frame
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colortext;         // foregroundcolor
  unsigned char   xdigits;           // formatdata (msb = writeprotected flag)
  unsigned char   iotype;            // iotype (numeric, time, date, ...)
  unsigned char   font;              // fontindex 
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_IO;
#define _SBITOFF_CTRL_IO sizeof(_BOX_CTRL_IO)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;
  unsigned char   state;             // bit0-3 = direction (0..down->up, 1..up->down, 2..left->right, 3..right->left, 4..vertical+-, 5..horizontal+-)
                                     // bit4 = var/const ug (0..constant, 1..variablenumber)
                                     // bit5 = var/const og (0..constant, 1..variablenumber)
                                     // bit7 = writeprotectionflag (0..writeprotected, 1..editable)
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colorfront;        // foregroundcolor
  long            ug;                // lolimit (constant or variable) (erst ab version 1.22)
  long            og;                // hilimit (constant or variable) (erst ab version 1.22)
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_IOBAR;
#define _SBITOFF_CTRL_IOBAR sizeof(_BOX_CTRL_IOBAR)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  momstat;           // variablenumber (0x7FFF) and state (0x8000) of momentary/stationary
  unsigned char   frametype;         // frame
  unsigned char   attrib;            // attribut 
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colortext;         // backgroundcolor
  unsigned short  img[2];            // released and pressed imagenumber
  unsigned short  text[2];           // released and pressed textnumber
  unsigned short  fktno[2];          // command to perform when pressed/released
  unsigned char   font;              // fontindex
  unsigned char   trigger;           // triggertype (tipset)
  // unsigned char  sbit;            // dynamic option
  // short release_value;
  // short press_value;
}
_BOX_CTRL_BUTTON;
#define _SBITOFF_CTRL_BUTTON        sizeof(_BOX_CTRL_BUTTON)
#define _RELEASEVALOFF_CTRL_BUTTON  (_SBITOFF_CTRL_BUTTON + 1)
#define _PRESSVALOFF_CTRL_BUTTON    (_SBITOFF_CTRL_BUTTON + 3)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
}
_BOX_CTRL_TOUCHTEST;

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;         // frametype
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  shemeindex;        // shemeindex
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_IMAGESCM;
#define _SBITOFF_CTRL_IMAGESCM sizeof(_BOX_CTRL_IMAGESCM)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;         // frame
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colortext;         // foregroundcolor
  unsigned char   font;              // fontindex
  unsigned short  shemeindex;        // shemeindex
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_TEXTSCM;
#define _SBITOFF_CTRL_TEXTSCM sizeof(_BOX_CTRL_TEXTSCM)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned char   attrib;            // attribut 
  unsigned short  img;               // imagenumber to view
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_IMAGE;
#define _SBITOFF_CTRL_IMAGE sizeof(_BOX_CTRL_IMAGE)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned char   frametype;         // frametype & frameinvert
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colortext;         // foregroundcolor
  unsigned short  text;              // textno
  unsigned char   font;              // fontindex
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_TEXT;
#define _SBITOFF_CTRL_TEXT sizeof(_BOX_CTRL_TEXT)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned char   frametype;         // frametype & frameinvert
  unsigned short  colorback;         // backgroundcolor
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_FRAME;
#define _SBITOFF_CTRL_FRAME sizeof(_BOX_CTRL_FRAME)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned char   frametype;         // frametype & frameinvert
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colorline;         // foregroundcolor
  unsigned char   index;             // osziindex (0-1)
  unsigned char   mode;              // nc
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_OSZI;
#define _SBITOFF_CTRL_OSZI sizeof(_BOX_CTRL_OSZI)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;         // frametype & frameinvert
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  color;             // foregroundcolor unselected
  unsigned short  colorselect;       // foregroundcolor selected
  unsigned char   index;             // listindex (0)
  unsigned char   font;              // fontindex
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_LIST;
#define _SBITOFF_CTRL_LIST sizeof(_BOX_CTRL_LIST)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  colorback;         // backgroundcolor
  unsigned short  colorfront;        // backgroundcolor
  unsigned char   index;             // pixmapindex (aktuell wird nur 0 verwendet)  
  // unsigned char  sbit;            // dynamic option
}
_BOX_CTRL_PIXMAP;
#define _SBITOFF_CTRL_PIXMAP sizeof(_BOX_CTRL_PIXMAP)

typedef struct
{
  _CTRLBOX_HEADER boxhdr;            // boxheader
  _XY             xy[2];             // canvas on screen
  unsigned short  varno;             // number of variable
  unsigned char   frametype;         // frametype & frameinvert
  unsigned char   attrib;            // attribut
  unsigned short  colorback;         // backgroundcolor
  unsigned short  color;             // foregroundcolor unselected
}
_BOX_CTRL_BUSY;

#pragma pack (pop)
