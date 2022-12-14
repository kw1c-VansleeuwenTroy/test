//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION
#include "..\..\Source\Common\hmi_nuc.h"

(*!
<Class
	Name               = "HmiUnitList"
	Revision           = "0.2"
	GUID               = "{E77C3A37-A59B-454F-895C-90E78C7AE8E4}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "true"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)">
	<Channels>
		<Server Name="ClassSvr" GUID="{1A31C14F-48C5-4980-AA0C-BB1AE9E22230}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Client Name="File" Required="true" Internal="false"/>
	</Channels>
	<Dependencies>
		<Files>
			<File Path=".\Source\Common\hmi_nuc.h" Include="true"/>
		</Files>
	</Dependencies>
	<RevDoku>
		<Owner Company="sigmatek" Author="kolott"/>
		<Dokumentation Revision="0.2" Date="2016-05-20" Author="kolott" Company="sigmatek" Description="sa26785: compilerversion 60, property preceding zero implemented"/>
		<Dokumentation Revision="0.1" Date="2014-01-16" Author="kolott" Company="sigmatek" Description="Trend added"/>
	</RevDoku>
</Class>
*)
HmiUnitList : CLASS
  //Servers:
	ClassSvr 	: SvrChCmd_DINT;
  //Clients:
	File 	: CltChCmd_HmiFile;
  //Variables:
		No 	: UDINT;
		Ptr 	: ^HMI_XUNIT;
  //Functions:
	
	FUNCTION HmiUnitList
		VAR_OUTPUT
			ret_code 	: ConfStates;
		END_VAR;
	
	FUNCTION GLOBAL Load
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION GLOBAL Free;
	
	FUNCTION GLOBAL Get
		VAR_INPUT
			index 	: UDINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: ^HMI_XUNIT;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

#pragma usingLtd HmiFile


//}}LSL_DECLARATION


FUNCTION GLOBAL TAB HmiUnitList::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_HMIUNITLIST
0$UINT, 2$UINT, (SIZEOF(::HmiUnitList))$UINT, 
1$UINT, 1$UINT, 0$UINT, 
TO_UDINT(2706799507), "HmiUnitList", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::HmiUnitList.ClassSvr.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(619352855), "ClassSvr", 
//Clients:
(::HmiUnitList.File.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(3121273764), "File", TO_UDINT(2548286290), "HmiFile", 0$UINT, 4$UINT, 
END_FUNCTION


#define USER_CNT_HmiUnitList 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_HmiUnitList] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION HmiUnitList::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_HmiUnitList, pCmd := #vmt.CmdTable);
	ClassSvr.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF ClassSvr.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;
	ret_code	:= HmiUnitList();

END_FUNCTION

//{{LSL_IMPLEMENTATION

FUNCTION HmiUnitList::HmiUnitList
	VAR_OUTPUT
		ret_code 	: ConfStates;
	END_VAR

  No := 0;
  Ptr := NIL;
	ret_code := C_OK;

END_FUNCTION

FUNCTION GLOBAL HmiUnitList::Free
  var
    tmp : ^HMI_XUNIT; 
  end_var

  tmp := Ptr; 
  while(No) do
    free_HMI_XUNIT(tmp);
    No -= 1;
    tmp += sizeof(HMI_XUNIT);
  end_while;
  
  File.FMemory(#Ptr$^void, 0);

  No  := 0;
  Ptr := NIL;

END_FUNCTION

FUNCTION GLOBAL HmiUnitList::Load
  VAR_OUTPUT
    retcode : bool;
  END_VAR
  var
    anz : udint; 
    tmp : ^HMI_XUNIT;
    tbt : usint;
  end_var; 
  
  // [4] ............. anzahl unitbl?cke
  // +[LME_ANYTHING .. digits
  // +[LME_ANYTHING .. posdezpt
  // +[1] ............ formula
  // +[LME_ANYTHING .. unittext
  // Label
  
  retcode := false;
  
  if(File.FRead(#anz$void, 4) = true) then
    if(File.FMemory(#Ptr$^void, anz * sizeof(HMI_XUNIT)) = true) then
      tmp := Ptr; 
      while(anz) do
        init_HMI_XUNIT(tmp); 
        if(File.GetCompilerVersion() >= 47) then
          File.Read_HMI_ANYTHING(#tmp^.digits);
          File.Read_HMI_ANYTHING(#tmp^.posdezpt);
        else
          File.FRead(#tbt$void, 1); 
          tmp^.digits.ima   := HMI_IMA_DINT_CONSTANT;
          tmp^.digits.value := tbt;
          File.FRead(#tbt$void, 1);
          tmp^.posdezpt.ima   := HMI_IMA_DINT_CONSTANT;
          tmp^.posdezpt.value := tbt;
        end_if;
       
        File.FRead(#tmp^.formula$void, 1); 
        File.Read_HMI_ANYTHING(#tmp^.text); 
        
        if(File.GetCompilerVersion() >= 60) then
          File.FRead(#tbt$void, 1);
          tbt := tbt AND 16#03;
          tmp^.leading0 := tbt$HMI_DTF;
        end_if;
        
        anz -= 1; 
        No  += 1; 
        tmp += sizeof(HMI_XUNIT); 
      end_while; 
      
//     #ifndef CUTOFF_LABEL  
//      Label.Load(); // load unitnamen
//     #endif
    end_if; 
  end_if; 

  retcode  := File.FChkFile();
  ClassSvr := to_dint(No); 

END_FUNCTION

FUNCTION GLOBAL HmiUnitList::Get
	VAR_INPUT
		index 	: udint;
	END_VAR
	VAR_OUTPUT
		retcode 	: ^HMI_XUNIT;
	END_VAR

  retcode := NIL;
  if(index < No) then
    retcode := Ptr + index * sizeof(HMI_XUNIT);
  end_if;

END_FUNCTION
