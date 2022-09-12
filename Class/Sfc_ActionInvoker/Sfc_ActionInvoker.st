//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)

//{{LSL_DEFINES
#define MAX_ACTION_CNT 2000
//}}LSL_DEFINES

//{{LSL_DECLARATION

(*!
<Class
	Name               = "Sfc_ActionInvoker"
	Revision           = "2.0"
	GUID               = "{AAEEC08A-F7C9-41A8-8DEC-AD1EED6CA6F8}"
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
	Comment            = "Handles action execution">
	<Channels>
		<Server Name="LogonItf" GUID="{9C4B425A-699D-45F5-904E-002DED0540B0}" Visualized="false" Initialize="false" WriteProtected="false" Retentive="false" Comment="Interface to the actioninvoker class&#13;&#10;&#13;&#10;Actions use this server to register themselves"/>
		<Client Name="To_Sfc_Sort" Required="true" Internal="false"/>
	</Channels>
	<RevDoku>
		<Owner Company="Sigmatek GmdH &amp; Co KG" Author="Lesmax"/>
		<Dokumentation Revision="2.0" Date="2014-05-20" Author="Lesmax" Company="Sigmatek GmdH &amp; Co KG" Description="Introduced new action priority management&#13;&#10;for a defined calling sequence."/>
	</RevDoku>
</Class>
*)
Sfc_ActionInvoker : CLASS
	TYPE
	  ActionPtr : ^Sfc_Action_Base;
	  ActionArray : ARRAY [0..MAX_ACTION_CNT] OF ActionPtr;
	END_TYPE
  //Servers:
	LogonItf 	: SvrChCmd_pVoid;
  //Clients:
	To_Sfc_Sort 	: CltChCmd_SFC_Sort;
  //Variables:
		m_Actions 	: ActionArray;
		m_ActionCnt 	: UDINT;
  //Functions:
	
	FUNCTION Sfc_ActionInvoker
		VAR_OUTPUT
			ret_code 	: ConfStates;
		END_VAR;
	
	FUNCTION GLOBAL Work;
	
	FUNCTION PriorityCompare
		VAR_INPUT
			pActionLeft 	: ^DINT;
			pActionRight 	: ^DINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: DINT;
		END_VAR;
	
	FUNCTION GLOBAL UpdateActionPriorities;
	
	FUNCTION VIRTUAL GLOBAL LogonItf::Write
		VAR_INPUT
			input (EAX) 	: pVoid;
		END_VAR
		VAR_OUTPUT
			result (EAX) 	: pVoid;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

#pragma usingLtd SFC_Sort


//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Sfc_ActionInvoker::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_ACTIONINVOKER
2$UINT, 0$UINT, (SIZEOF(::Sfc_ActionInvoker))$UINT, 
1$UINT, 1$UINT, 0$UINT, 
TO_UDINT(1405604901), "Sfc_ActionInvoker", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::Sfc_ActionInvoker.LogonItf.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(608509347), "LogonItf", 
//Clients:
(::Sfc_ActionInvoker.To_Sfc_Sort.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(3904018932), "To_Sfc_Sort", TO_UDINT(3962211165), "SFC_Sort", 1$UINT, 0$UINT, 
END_FUNCTION


#define USER_CNT_Sfc_ActionInvoker 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Sfc_ActionInvoker] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Sfc_ActionInvoker::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_Sfc_ActionInvoker, pCmd := #vmt.CmdTable);
	vmt.CmdTable.Write		:= #Write();
	LogonItf.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF LogonItf.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;
	ret_code	:= Sfc_ActionInvoker();

END_FUNCTION

#pragma usingLtd Sfc_Action_Base

//{{LSL_IMPLEMENTATION


FUNCTION Sfc_ActionInvoker::Sfc_ActionInvoker
	VAR_OUTPUT
		ret_code 	: ConfStates;
	END_VAR
  VAR
	  index : DINT;
  END_VAR
  
  m_ActionCnt := 0;
  
  for index := 0 to MAX_ACTION_CNT - 1 by 1 do
  
    m_Actions[index] := NIL;
  
  end_for;

	ret_code := C_OK;

END_FUNCTION


FUNCTION VIRTUAL GLOBAL Sfc_ActionInvoker::LogonItf::Write
	VAR_INPUT
		input (EAX) 	: pVoid;
	END_VAR
	VAR_OUTPUT
		result (EAX) 	: pVoid;
	END_VAR

	if m_ActionCnt < (MAX_ACTION_CNT-1) then
  
    m_Actions[m_ActionCnt] := input$ActionPtr;
    
    m_ActionCnt += 1;
  
    result := input;
    
  else
  
    result := NIL;
  
  end_if;
  
END_FUNCTION


FUNCTION GLOBAL Sfc_ActionInvoker::Work
  VAR
	  index     : UDINT;
    pAction   : ^ActionPtr;
  END_VAR

  //////////////////////////////////////////////////////////////
  // Execute actions that have become inactive last cycle
  
  // Initialize Pointer
  pAction := #m_Actions$ActionPtr;
  
  for index := 0 to m_ActionCnt - 1 by 1 do
   
    // Only execute if the action became inactive last cycle
    if pAction^^.Q then
    
      pAction^^.LastWorkPass();
    
    end_if;
    
    // Next Element
    pAction += sizeof(ActionPtr);
  
  end_for;
  
  // Execute actions that have become inactive last cycle
  //////////////////////////////////////////////////////////////
  
  //////////////////////////////////////////////////////////////
  // Handle time delays of delayed actions
  
  // Initialize Pointer
  pAction := #m_Actions$ActionPtr;
  
  for index := 0 to m_ActionCnt - 1 by 1 do
   
    // Only check time delay if delay timer is active for the action
    if pAction^^.DelayActive then
    
      pAction^^.HandleTimeDelay();
    
    end_if;
    
    // Next Element
    pAction += sizeof(ActionPtr);
  
  end_for;
  
  // Handle time delays of delayed actions
  //////////////////////////////////////////////////////////////  
  
  //////////////////////////////////////////////////////////////
  // Execute active actions
  
  // Initialize Pointer
  pAction := #m_Actions$ActionPtr;
  
  for index := 0 to m_ActionCnt - 1 by 1 do

    //Only execute if the action is active and doesn't execute at rising edge pulse         
    if pAction^^.A then
    
      pAction^^.Work();
    
    end_if;
    
    // Next Element
    pAction += sizeof(ActionPtr);
  
  end_for;
  
  // Execute active actions
  //////////////////////////////////////////////////////////////

END_FUNCTION



FUNCTION Sfc_ActionInvoker::PriorityCompare
	VAR_INPUT
		pActionLeft 	: ^DINT;
		pActionRight 	: ^DINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: DINT;
	END_VAR
  
   retcode := pActionLeft^$ActionPtr^.GetPriority() 
            > pActionRight^$ActionPtr^.GetPriority() ;

END_FUNCTION


FUNCTION GLOBAL Sfc_ActionInvoker::UpdateActionPriorities

  To_Sfc_Sort.Sort( src := #m_Actions, 
                    no := m_ActionCnt, 
                    itemsize := sizeof(ActionPtr), 
                    sortfunct := #PriorityCompare(), 
                    stable := TRUE);

END_FUNCTION