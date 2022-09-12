//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "_HotAlarm"
	Revision           = "0.1"
	GUID               = "{2497BFE2-EFCC-11D6-8BC9-0048545E8899}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "true"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)"
	Comment            = "display a single alarmline with highest priorita">
	<Channels>
		<Server
			Name           = "Server0"
			Initialize     = "false"
			Visualized     = "true"
			WriteProtected = "true">
		</Server>
	</Channels>
	<Network Name="_HotAlarm">
		<!-- List of Components in this network -->
		<Components>
			<Object
				Name       = "_base"
				GUID       = "{2497BFE1-EFCC-11D6-8BC9-0048545E8899}"
				Class      = "_MyIO"
				Position   = "(20,20)"
				Visualized = "true">
				<Channels>
					<Server Name="Refresh"/>
					<Server Name="Server0"/>
					<Client Name="Graphic"/>
					<Client Name="Lse"/>
				</Channels>
			</Object>
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
			<Connection Source="this.Server0" Destination="_base.Server0" Vertices="(492,210),(320,110),"/>
			<Connection Source="_base.Lse" Destination="this.Lse" Vertices="(20,110),(38,210),"/>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
</Class>
*)
#pragma using _MyIO

_HotAlarm : CLASS
: _MyIO
  //Servers:
  //Clients:
  //Variables:
  //Functions:
				//! <Function Comment="[#ENGLISH]&#13;&#10;this method is called everytime when system wants to redraw the io&#13;&#10;&#13;&#10;pio ....... pointer to io information&#13;&#10;pr ........ pointer to result information&#13;&#10;pv ........ pointer to io variableinformation&#13;&#10;input ..... _TRUE it&apos;s an input / _FALSE it&apos;s an output&#13;&#10;&#13;&#10;for the returnstatement there are 3 different possibilities&#13;&#10;_IDLE ..... the system should goon like it is (system goes on)&#13;&#10;_IDIDIT ... i did it (system is ready)&#13;&#10;_IFAILED .. i tried to do my best, but i failed (system is ready)&#13;&#10;&#13;&#10;if you want to draw the io let&apos;s return _IDIDIT&#13;&#10;" Name="Draw"/>
	FUNCTION __CDECL VIRTUAL GLOBAL Draw
		VAR_INPUT
			pio 	: ^_IO;			//! <Variable Comment="pointer to _IO information" Name="Draw.pio"/>
			pr 	: ^_RESULT;			//! <Variable Comment="pointer to _RESULT information" Name="Draw.pr"/>
			pv 	: ^_VARIABLE;			//! <Variable Comment="pointer to io _VARIABLE information" Name="Draw.pv"/>
			input 	: BOOL;			//! <Variable Comment="TRUE it&apos;s an input&#13;&#10;FALSE it&apos;s an output" Name="Draw.input"/>
		END_VAR
		VAR_OUTPUT
			retcode (EAX) 	: _DOIT;			//! <Variable Comment="for the returnstatement there are 3 different possibilities&#13;&#10;  _IDLE ..... the system should goon like it is (system goes on)&#13;&#10;  _IDIDIT ... i did it (system is ready)&#13;&#10;  _IFAILED .. i tried to do my best, but i failed (system is re" Name="Draw.retcode"/>
		END_VAR;
				//! <Function Comment="[#ENGLISH]&#13;&#10;this method is called everytime when system wants to get data for defined io.&#13;&#10;&#13;&#10;pr ........ pointer to result information&#13;&#10;pio ....... pointer to io information&#13;&#10;pv ........ pointer to io variableinformation&#13;&#10;input ..... _TRUE it&apos;s an input / _FALSE it&apos;s an output&#13;&#10;&#13;&#10;for the returnstatement there are 3 different possibilities&#13;&#10;_IDLE ..... the system should goon like it is (system goes on)&#13;&#10;_IDIDIT ... i did it (system is ready)&#13;&#10;_IFAILED .. i tried to do my best, but i failed (system is ready)&#13;&#10;&#13;&#10;if you want to do it let&apos;s return _IDIDIT and initialize the  structure _RESULT&#13;&#10;" Name="GetData"/>
	FUNCTION __CDECL VIRTUAL GLOBAL GetData
		VAR_INPUT
			pr 	: ^_RESULT;			//! <Variable Comment="pointer to _RESULT information" Name="GetData.pr"/>
			pio 	: ^_IO;			//! <Variable Comment="pointer to _IO information" Name="GetData.pio"/>
			pv 	: ^_VARIABLE;			//! <Variable Comment="pointer to _VARIABLE information given by LSE" Name="GetData.pv"/>
			input 	: BOOL;			//! <Variable Comment="TRUE it&apos;s an input&#13;&#10;FALSE it&apos;s an output" Name="GetData.input"/>
		END_VAR
		VAR_OUTPUT
			retcode (EAX) 	: _DOIT;			//! <Variable Comment="for the returnstatement there are 3 different possibilities&#13;&#10;  _IDLE ..... the system should goon like it is (system goes on)&#13;&#10;  _IDIDIT ... i did it (system is ready)&#13;&#10;  _IFAILED .. i tried to do my best, but i failed (system is ready)" Name="GetData.retcode"/>
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB _HotAlarm::@CT_
0$UINT,
2#0100000000000000$UINT, //TY__HOTALARM
0$UINT, 1$UINT, (SIZEOF(::_HotAlarm))$UINT, 
0$UINT, 0$UINT, 0$UINT, 
TO_UDINT(3509550928), "_HotAlarm", //Class
TO_UDINT(2980745877), "_MyIO", 0$UINT, 3$UINT, //Baseclass
//Servers:
//Clients:
END_FUNCTION


#define USER_CNT__HotAlarm 17

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT__HotAlarm] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION _HotAlarm::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
		nCmdSize	: UINT;
	END_VAR

	ret_code	:= _MyIO::@STD();
	IF ret_code <> C_OK THEN
		RETURN;
	END_IF;
	nCmdSize		:= _MyIO::Server0.pMeth^.nCmds$UINT*SIZEOF(pVoid) + CMDMETH.Init;

	_memcpy((#vmt.CmdTable)$^USINT, _MyIO::Server0.pMeth, nCmdSize);
	vmt.CmdTable.nCmds		:= nSTDCMD + USER_CNT__HotAlarm;
#pragma warning (disable : 74)
	vmt.UserFcts[3]		:= #Draw();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[4]		:= #GetData();

#pragma warning (default : 74)
	_MyIO::Server0.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF _MyIO::Server0.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION
#pragma using _Lse


//*********************Inserted from .\_HotAlarm\_HotAlarm_00_00.st*********************



 


#pragma warning (disable: 73)
//[#ENGLISH]
//this method is called everytime when system wants to redraw the io
//
//pio ....... pointer to io information
//pr ........ pointer to result information
//pv ........ pointer to io variableinformation
//input ..... _TRUE it's an input / _FALSE it's an output
//
//for the returnstatement there are 3 different possibilities
//_IDLE ..... the system should goon like it is (system goes on)
//_IDIDIT ... i did it (system is ready)
//_IFAILED .. i tried to do my best, but i failed (system is ready)
//
//if you want to draw the io let's return _IDIDIT

FUNCTION __CDECL VIRTUAL GLOBAL _HotAlarm::Draw
VAR_INPUT
	pio		: ^_IO;
	pr		: ^_RESULT;
	pv		: ^_VARIABLE;
	input		: BOOL;
END_VAR
VAR_OUTPUT
	retcode		: _DOIT;
END_VAR
VAR
    pms   : ^_MEM_SINGLEALARM;
	psa   : ^_SINGLEALARM; 
	txt   : ^_CHAR;  
	st    : BOOL; 
	no    : UDINT; 
END_VAR

  st  := FALSE; 
  pms := get_MEM_SINGLEALARM(FALSE); 
  no  := no_RINGBUFFER(#pms^.ringbuffer); 
  while(no > 0) do
    no -= 1; 
    psa := pms^.ptr + rpos_RINGBUFFER(#pms^.ringbuffer, no) * sizeof(_SINGLEALARM); 
	  if(psa^.state <> 0) then
      txt := create_alarmtext(psa, FALSE, NIL);
	    if(txt <> NIL) then
	    no := 0; 
	    st := TRUE; 
      end_if; 
    end_if; 
  end_while; 

  Graphic.Putimage(#pio^.image, DEFKOORD, DEFKOORD); 
  if(st = TRUE) then
    OutMultiTextAlign(txt, pio^.fillchr, #pio^.space, pio^.font, pio^.attrib, pio^.frametype, pio^.coltxt, pio^.colback, pio^.colframe, sizeof(_CHAR));
  end_if; 

  retcode := _IDIDIT;   

END_FUNCTION //__CDECL VIRTUAL GLOBAL _HotAlarm::Draw
//[#ENGLISH]
//this method is called everytime when system wants to get data for defined io.
//
//pr ........ pointer to result information
//pio ....... pointer to io information
//pv ........ pointer to io variableinformation
//input ..... _TRUE it's an input / _FALSE it's an output
//
//for the returnstatement there are 3 different possibilities
//_IDLE ..... the system should goon like it is (system goes on)
//_IDIDIT ... i did it (system is ready)
//_IFAILED .. i tried to do my best, but i failed (system is ready)
//
//if you want to do it let's return _IDIDIT and initialize the  structure _RESULT

FUNCTION __CDECL VIRTUAL GLOBAL _HotAlarm::GetData
VAR_INPUT
	pr		: ^_RESULT;
	pio		: ^_IO;
	pv		: ^_VARIABLE;
	input		: BOOL;
END_VAR
VAR_OUTPUT
	retcode		: _DOIT;
END_VAR
VAR
    pms : ^_MEM_SINGLEALARM; 
END_VAR

  pms := get_MEM_SINGLEALARM(FALSE);
  pr^.ftype := RES_NUMERIC;
  pr^.rmin  := pms^.xchange;
  pr^.rmax  := pms^.xchange;
  pr^.value := pms^.xchange;
  pr^.ptr   := #pr^.value$void;

  retcode := _IDIDIT;

END_FUNCTION //__CDECL VIRTUAL GLOBAL _HotAlarm::GetData
