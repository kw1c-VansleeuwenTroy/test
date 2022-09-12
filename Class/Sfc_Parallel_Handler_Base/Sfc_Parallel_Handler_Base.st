//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "Sfc_Parallel_Handler_Base"
	Revision           = "1.0"
	GUID               = "{FB16CEC1-FFAE-4C60-8ABF-A1053E11E7D4}"
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
	Comment            = "Helper class for joining parallel branches.">
	<Channels>
		<Server Name="Itf" GUID="{64F317B6-9AF7-4F97-8D7C-39F8764C5BE5}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Client Name="CallTransition" Required="false" Internal="false"/>
	</Channels>
</Class>
*)
Sfc_Parallel_Handler_Base : CLASS
  //Servers:
	Itf 	: SvrChCmd_DINT;
  //Clients:
	CallTransition 	: CltCh_DINT;
  //Variables:
  //Functions:
	
	FUNCTION VIRTUAL ReadyForTrans
		VAR_OUTPUT
			Result 	: BOOL;
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL Itf::Read
		VAR_OUTPUT
			output (EAX) 	: DINT;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Sfc_Parallel_Handler_Base::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_PARALLEL_HANDLER_BASE
1$UINT, 0$UINT, (SIZEOF(::Sfc_Parallel_Handler_Base))$UINT, 
1$UINT, 1$UINT, 0$UINT, 
TO_UDINT(1849923049), "Sfc_Parallel_Handler_Base", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::Sfc_Parallel_Handler_Base.Itf.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(3244430248), "Itf", 
//Clients:
(::Sfc_Parallel_Handler_Base.CallTransition.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000000$UINT, TO_UDINT(2051227785), "CallTransition", 
END_FUNCTION


#define USER_CNT_Sfc_Parallel_Handler_Base 1

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Sfc_Parallel_Handler_Base] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Sfc_Parallel_Handler_Base::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_Sfc_Parallel_Handler_Base, pCmd := #vmt.CmdTable);
	vmt.CmdTable.Read		:= #Read();
#pragma warning (disable : 74)
	vmt.UserFcts[0]		:= #ReadyForTrans();

#pragma warning (default : 74)
	Itf.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Itf.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION


FUNCTION VIRTUAL GLOBAL Sfc_Parallel_Handler_Base::Itf::Read
	VAR_OUTPUT
		output (EAX) 	: DINT;
	END_VAR
  
  output := 0;
  
  if ReadyForTrans() = true then
  
    output := CallTransition.Read();
  
  end_if;

END_FUNCTION


FUNCTION VIRTUAL Sfc_Parallel_Handler_Base::ReadyForTrans
	VAR_OUTPUT
		Result 	: BOOL;
	END_VAR
  
  Result := FALSE;  
  
END_FUNCTION