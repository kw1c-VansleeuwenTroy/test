//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "SFC_Sort"
	Revision           = "1.0"
	GUID               = "{81C68AC0-7B16-4318-BEAC-955B46E15466}"
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
	Comment            = "supports functionality to sort arbitrary list in userdefined or alphabetical manner">
	<Channels>
		<Server Name="ClassSvr" GUID="{9FE37BE7-BB4A-4D6D-8333-2E499E9B5856}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
	</Channels>
	<RevDoku>
		<Owner Company="Sigmatek GmbH &amp; Co KG" Author="LesMax"/>
		<Dokumentation Revision="1.0" Date="2014-05-20" Author="LesMax" Company="Sigmatek GmbH &amp; Co KG" Description="Introduced new action priority management&#13;&#10;for a defined calling sequence."/>
		<Dokumentation Revision="0.2" Date="2013-04-11" Author="kolott" Company="sigmatek" Description="arm-ready"/>
	</RevDoku>
</Class>
*)
SFC_Sort : CLASS
  //Servers:
	ClassSvr 	: SvrChCmd_DINT;
  //Clients:
  //Variables:
  //Functions:
	
	FUNCTION MySort
		VAR_INPUT
			src 	: ^USINT;
			no 	: UDINT;
			itemsize 	: UDINT;
			sortfunct 	: ^void;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
				//! <Function Comment="sort arbitrary list where each element has same size.&#13;&#10;src ....... pointer to list of elements&#13;&#10;no ........ number of elements in list&#13;&#10;itemsize .. size of one element in bytes&#13;&#10;sortfunct . pointer to sortfunct&#13;&#10;stable .... use stable (true) or instable (false) sortalgorithm&#13;&#10;&#13;&#10;note: take care of sortmethod and thispointer in sortmethod&#13;&#10;FUNCTION GLOBAL SortFunct VAR_INPUT p1:^void; p2:^void; END_VAR VAR_OUTPUT retcode : dint; END_VAR;&#13;&#10;" Name="Sort"/>
	FUNCTION GLOBAL Sort
		VAR_INPUT
			src 	: ^void;
			no 	: UDINT;
			itemsize 	: UDINT;
			sortfunct 	: ^void;
			stable 	: BOOL;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION GnomeSort
		VAR_INPUT
			src 	: ^void;
			no 	: UDINT;
			itemsize 	: UDINT;
			sortfunct 	: ^void;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB SFC_Sort::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_SORT
1$UINT, 0$UINT, (SIZEOF(::SFC_Sort))$UINT, 
1$UINT, 0$UINT, 0$UINT, 
TO_UDINT(3962211165), "SFC_Sort", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::SFC_Sort.ClassSvr.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(619352855), "ClassSvr", 
//Clients:
END_FUNCTION


#define USER_CNT_SFC_Sort 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_SFC_Sort] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION SFC_Sort::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR

	ret_code := C_OK;

END_FUNCTION

//{{LSL_IMPLEMENTATION


FUNCTION GLOBAL MyXSort VAR_INPUT p1:^void; p2:^void; END_VAR VAR_OUTPUT retcode : dint; END_VAR;


FUNCTION SFC_Sort::MySort
	VAR_INPUT
		src 	: ^USINT;
		no 	: UDINT;
		itemsize 	: UDINT;
		sortfunct 	: ^void;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR
  var
    tmp, hp : ^usint;
    mx, nx, wx, parent, child, max, i : dint;
    spuf : array[0..511] of usint;
  end_var

  retcode := false;
  
  if(itemsize <= sizeof(spuf)) then
  
    nx      := to_dint(no);
    mx      := (nx + 6) / 8;
    src     := src;
    tmp     := #spuf[0];
    retcode := true;

    while(1) do
      if(mx) then
        mx     -= 1;
        parent := mx;
        _memcpy(tmp, src + (parent$udint*itemsize), itemsize);
      else
        nx -= 1;
        if(nx) then
          hp := src + (nx$udint*itemsize);
          _memcpy(tmp, hp, itemsize);
          _memmove(hp, src, itemsize);
          parent := 0;
        else
          exit;
        end_if;
      end_if;

      child := parent * 8 + 1;
      while(child < nx) do
        wx := nx - child;
        if(wx > 8) then
          wx := 8;
        end_if;
        
        max := 0;
        if(wx > 1) then
          for i:=1 to wx-1 do 
            if(sortfunct$MyXSort(src+(to_udint(child+i)*itemsize), src+to_udint(child+max)*itemsize) > 0) then
              max := i;
            end_if;
          end_for;
        end_if;

        child += max;

        if(sortfunct$MyXSort(src+(child$udint*itemsize), tmp) <= 0) then
          exit;
        end_if;
        
        _memcpy(src+(parent$udint*itemsize), src+(child$udint*itemsize), itemsize);
        parent := child;
        child  := parent * 8 + 1;
      end_while;

      _memcpy(src+(parent$udint*itemsize), tmp, itemsize);
    end_while;
  end_if;
  
END_FUNCTION


FUNCTION SFC_Sort::GnomeSort
	VAR_INPUT
		src 	: ^void;
		no 	: UDINT;
		itemsize 	: UDINT;
		sortfunct 	: ^void;
	END_VAR
  var
    tmp : array [0..511] of usint;
    p0, p1  : ^usint;
    i : udint;
  end_var

  i  := 1;
  p0 := src$^usint;
  p1 := p0 + itemsize;

  while(i < no) do
    if(sortfunct$MyXSort(p0, p1) > 0) then
      _memcpy(#tmp[0], p0, itemsize);
      _memmove(p0, p1, itemsize);
      _memcpy(p1, #tmp[0], itemsize);
      if(i > 1) then
        i  -= 1;
        p1 := p0;
        p0 -= itemsize;
      end_if;
    else
      i  += 1;
      p0 := p1;
      p1 += itemsize;
    end_if;
  end_while;

END_FUNCTION


FUNCTION GLOBAL SFC_Sort::Sort
	VAR_INPUT
		src 	: ^void;
		no 	: UDINT;
		itemsize 	: UDINT;
		sortfunct 	: ^void;
		stable 	: BOOL;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR

  retcode := true;

  if (no > 1) then
  
    retcode := false;
    
    if((itemsize > 0) & (sortfunct <> NIL) & (src <> NIL)) then
    
      if(stable = false) then
      
        // reihenfolge bei gleichen elementen ?ndert sich --> instabil, vorteil: schnell
        retcode := MySort(src$^usint, no, itemsize, sortfunct);
        
      else
      
        // reihenfolge bei gleichen elementen bleibt gleich --> stabil, nachteil: langsam
        GnomeSort(src, no, itemsize, sortfunct);
        retcode := true;
        
      end_if;
      
    end_if;
    
  end_if;

END_FUNCTION

