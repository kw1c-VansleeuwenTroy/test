//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "Sfc_Action_Base"
	Revision           = "2.0"
	GUID               = "{F723722D-6102-478E-A446-E49C25170E61}"
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
		<Server Name="A" GUID="{15979974-9865-4A60-BE86-23FC7214FD1C}" Visualized="true" Initialize="false" WriteProtected="true" Retentive="false" Comment="Active flag&#13;&#10;&#13;&#10;Indicates if the action is active"/>
		<Server Name="DelayActive" GUID="{523C83AA-2BF6-4B49-8BFC-5C58D6EF36C9}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false" Comment="Delay flag&#13;&#10;&#13;&#10;Indicates that the action is&#13;&#10;waiting for a time delay in order&#13;&#10;to become active"/>
		<Server Name="Itf" GUID="{A2E79447-B81E-4A74-B7BD-9A86D18B837E}" Visualized="false" Initialize="false" WriteProtected="true" Retentive="false" Comment="Interface to the action class"/>
		<Server Name="Q" GUID="{B339CFF2-330E-4632-965C-3380979FBE6C}" Visualized="true" Initialize="false" WriteProtected="true" Retentive="false" Comment="Last execution flag&#13;&#10;&#13;&#10;Indicates that the action has become&#13;&#10;inactive and is being executed for the last time."/>
		<Server Name="T" GUID="{AC62CC2F-531C-40BB-809D-EC570F304156}" Visualized="true" Initialize="false" WriteProtected="true" Retentive="false" Comment="Action timer&#13;&#10;&#13;&#10;If the action is active, the value&#13;&#10;of the action timer is the time since&#13;&#10;the activation of the action.&#13;&#10;Otherwise the value of the action timer&#13;&#10;is the duration of the last active phase.&#13;&#10;&#13;&#10;Unit: ms"/>
		<Client Name="GetParentPtr" Required="true" Internal="false" Comment="Helper client for optaining a&#13;&#10;pointer to the parent SFC class."/>
		<Client Name="LogonToInvoker" Required="true" Internal="false" Comment="Helper Client for registration&#13;&#10;at the action invoker."/>
	</Channels>
	<RevDoku>
		<Owner Company="Sigmatek GmbH &amp; Co KG" Author="LesMax"/>
		<Dokumentation Revision="2.0" Date="2014-05-20" Author="LesMax" Company="Sigmatek GmbH &amp; Co KG" Description="Introduced new action priority management&#13;&#10;for a defined calling sequence."/>
		<Dokumentation Revision="1.2" Date="2013-12-04" Author="LesMax" Company="Sigmatek GmbH &amp; Co KG" Description="The Servers &quot;DelayActive&quot; and &quot;AtRisingEdge&quot; are now always reset at the beginning of the &quot;OnStepActive&quot; Method."/>
		<Dokumentation Revision="1.1" Date="2013-10-17" Author="LesMax" Company="Sigmatek GmbH &amp; Co KG" Description="Actions now obtain a pointer to the&#13;&#10;parent Sfc class at initialisation."/>
	</RevDoku>
	<Network Name="Sfc_Action_Base">
		<!-- List of Components in this network -->
		<Components>
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
</Class>
*)
Sfc_Action_Base : CLASS
	TYPE
	  ActionQualifiers :  //! <Type Public="true" Name="ActionQualifiers"/>
	  (
	    N_Qualifier,
	    R_Qualifier,
	    S_Qualifier,
	    L_Qualifier,
	    D_Qualifier,
	    P_Qualifier,
	    P0_Qualifier,
	    P1_Qualifier,
	    SD_Qualifier,
	    DS_Qualifier,
	    SL_Qualifier
	  )$UDINT;
	  PriorityOffset :
	  (
	    OffsetAtRisingEdge:=0,
	    OffsetRegular:=150000,
	    OffsetAtFallingEdge:=300000
	  )$UDINT;
	  PtrTo_Sfc_Network_Base : ^Sfc_Network_Base;
	END_TYPE
  //Servers:
	Itf 	: SvrChCmd_DINT;
	A 	: SvrCh_DINT;
	T 	: SvrCh_UDINT;
	Q 	: SvrCh_DINT;
	DelayActive 	: SvrCh_DINT;
  //Clients:
	LogonToInvoker 	: CltCh_pVoid;
	GetParentPtr 	: CltCh_UDINT;
  //Variables:
		m_ActionQualifier 	: ActionQualifiers;			//! <Variable Comment="Action qualifier&#13;&#10;&#13;&#10;Currently used action qualifier" Name="m_ActionQualifier"/>
		m_TimerSetting 	: UDINT;			//! <Variable Comment="Time setting&#13;&#10;&#13;&#10;Optional time setting for limited or delayed actions" Name="m_TimerSetting"/>
		m_Priority 	: UDINT;
		m_ActiveTimeStamp 	: UDINT;			//! <Variable Comment="Time stamp&#13;&#10;&#13;&#10;Time stamp for active phase duration measuring" Name="m_ActiveTimeStamp"/>
		m_DelayTimeStamp 	: UDINT;			//! <Variable Comment="Delay time stamp&#13;&#10;&#13;&#10;Time stamp for time delayed actions" Name="m_DelayTimeStamp"/>
  //Functions:
	
	FUNCTION Sfc_Action_Base
		VAR_OUTPUT
			ret_code 	: ConfStates;
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL Init;
	
	FUNCTION VIRTUAL GLOBAL Work;
	
	FUNCTION VIRTUAL GLOBAL LastWorkPass;
	
	FUNCTION DoWork;
	
	FUNCTION VIRTUAL OnWork;
	
	FUNCTION VIRTUAL OnActive;
	
	FUNCTION VIRTUAL OnInactive;
	
	FUNCTION DoActive;
	
	FUNCTION DoInactive;
	
	FUNCTION CalculateDelayTime
		VAR_OUTPUT
			DelayTime 	: UDINT;
		END_VAR;
	
	FUNCTION CalculateActiveTime
		VAR_OUTPUT
			ActiveTime 	: UDINT;
		END_VAR;
	
	FUNCTION HandleTimeLimit;
	
	FUNCTION HandlePulse;
	
	FUNCTION GLOBAL OnStepActive
		VAR_INPUT
			ActionQualifier 	: ActionQualifiers;
			TimerSetting 	: UDINT;
		END_VAR;
	
	FUNCTION GLOBAL OnStepInactive;
	
	FUNCTION GLOBAL HandleTimeDelay;
	
	FUNCTION VIRTUAL OnReadInternalVariables;
	
	FUNCTION VIRTUAL OnWriteInternalVariables;
	
	FUNCTION GLOBAL SetPriority
		VAR_INPUT
			Priority 	: UDINT;
		END_VAR;
	
	FUNCTION GLOBAL GetPriority
		VAR_OUTPUT
			Priority 	: UDINT;
		END_VAR;
	
	FUNCTION GLOBAL UpdatePriorities;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Sfc_Action_Base::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_ACTION_BASE
2$UINT, 0$UINT, (SIZEOF(::Sfc_Action_Base))$UINT, 
5$UINT, 2$UINT, 0$UINT, 
TO_UDINT(787759260), "Sfc_Action_Base", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::Sfc_Action_Base.Itf.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(3244430248), "Itf", 
(::Sfc_Action_Base.A.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3554254475), "A", 
(::Sfc_Action_Base.T.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3187964512), "T", 
(::Sfc_Action_Base.Q.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3463352047), "Q", 
(::Sfc_Action_Base.DelayActive.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(343741254), "DelayActive", 
//Clients:
(::Sfc_Action_Base.LogonToInvoker.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000010$UINT, TO_UDINT(2591088628), "LogonToInvoker", 
(::Sfc_Action_Base.GetParentPtr.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000010$UINT, TO_UDINT(3235255086), "GetParentPtr", 
END_FUNCTION


#define USER_CNT_Sfc_Action_Base 7

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Sfc_Action_Base] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Sfc_Action_Base::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_Sfc_Action_Base, pCmd := #vmt.CmdTable);
	vmt.CmdTable.Init		:= #Init();
#pragma warning (disable : 74)
	vmt.UserFcts[0]		:= #Work();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[1]		:= #LastWorkPass();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[2]		:= #OnWork();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[3]		:= #OnActive();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[4]		:= #OnInactive();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[5]		:= #OnReadInternalVariables();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[6]		:= #OnWriteInternalVariables();

#pragma warning (default : 74)
	Itf.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Itf.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;
	ret_code	:= Sfc_Action_Base();

END_FUNCTION

#pragma usingLtd Sfc_Network_Base

//{{LSL_IMPLEMENTATION


// Init method for registering at action invoker
FUNCTION VIRTUAL GLOBAL Sfc_Action_Base::Init
  
  if _FirstScan then
  
    LogonToInvoker.Write(input:=this);
    
    GetParentPtr := GetParentPtr.Read();
  
  end_if;  
  
END_FUNCTION


// Implement Worker Interface
FUNCTION VIRTUAL GLOBAL Sfc_Action_Base::Work

  // Call own work routine if active
  if A = 1 then
  
    // Read all connected internal variable servers
    OnReadInternalVariables();
  
    // Call work routine
    DoWork();
    
    // Write all connected internal variable servers
    OnWriteInternalVariables();
      
    // Handle the limited action qualifiers
    HandleTimeLimit();
    
    // Handle the pulse action qualifiers
    HandlePulse();
  
  end_if;  

END_FUNCTION


// Handles actions wich were deactivated in the last cycle 
// as well as actions that are called at a falling edge
FUNCTION VIRTUAL GLOBAL Sfc_Action_Base::LastWorkPass

  if A = 0 & Q = 1 then
    
    // Read all connected internal variable servers
    OnReadInternalVariables();
    
    // Call work routine one last time
    DoWork();
    
    // Write all connected internal variable servers
    OnWriteInternalVariables();
    
    // Reset Q flag
    Q := 0;
    
    DoInactive();
    
  end_if;

END_FUNCTION


FUNCTION Sfc_Action_Base::DoWork
  
  // Update the execution timer
  T := CalculateActiveTime();

  // Call User Work Handler
  OnWork();
  
END_FUNCTION


FUNCTION Sfc_Action_Base::DoActive

  // Save a timestamp for the activation of the action
  m_ActiveTimeStamp := ops.tAbsolute;
  
  // Reset the execution timer
  T := 0;

  // Call User active Handler
  OnActive();

END_FUNCTION


FUNCTION Sfc_Action_Base::DoInactive

  // Reset the activation timestamp
  m_ActiveTimeStamp := 0;

  // Call User Inactive Handler
  OnInactive();

END_FUNCTION


FUNCTION Sfc_Action_Base::CalculateDelayTime
	VAR_OUTPUT
		DelayTime 	: UDINT;
	END_VAR
    VAR
    curTime : UDINT;
  END_VAR
  
    // Calculate delay time
    curTime := ops.tAbsolute;
    
    // Handle Overflow condition
    if curTime < m_DelayTimeStamp then
    
      DelayTime := curTime + sizeof(UDINT) - m_DelayTimeStamp;
    
    else
    
      DelayTime := curTime - m_DelayTimeStamp;
    
    end_if;

END_FUNCTION


FUNCTION Sfc_Action_Base::CalculateActiveTime
	VAR_OUTPUT
		ActiveTime 	: UDINT;
	END_VAR
  VAR
  	curTime : UDINT;
  END_VAR

  // Update the execution timer
  curTime := ops.tAbsolute;
  
  // Handle Overflow condition
  if curTime < m_ActiveTimeStamp then
  
    ActiveTime := curTime + sizeof(UDINT) - m_ActiveTimeStamp;
  
  else
  
    ActiveTime := curTime - m_ActiveTimeStamp;
  
  end_if;

END_FUNCTION


FUNCTION Sfc_Action_Base::HandleTimeLimit


  case m_ActionQualifier of
  
  L_Qualifier, SL_Qualifier:
    
    // Check if the time limit is reached
    if CalculateActiveTime() >= m_TimerSetting then
    
      A := 0;
      Q := 1;
      
    end_if;
  
  end_case;


END_FUNCTION

FUNCTION Sfc_Action_Base::HandlePulse

  case m_ActionQualifier of
  
  P_Qualifier, P1_Qualifier:
    
    A := 0;
    Q := 0;
  
  end_case;

END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::HandleTimeDelay
  
  case m_ActionQualifier of
  
  D_Qualifier, DS_Qualifier, SD_Qualifier:
    
    if DelayActive = 1 & CalculateDelayTime() >= m_TimerSetting then
    
      A := 1;
      Q := 0;
      
      m_DelayTimeStamp := 0;
      DelayActive := 0;
      
      DoActive();
    
    end_if;
  
  end_case;
  
END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::OnStepActive
	VAR_INPUT
		ActionQualifier 	: ActionQualifiers;
		TimerSetting 	: UDINT;
	END_VAR
  
  m_ActionQualifier := ActionQualifier;
  m_TimerSetting := TimerSetting;
  DelayActive := 0;
  
  case m_ActionQualifier of
  
  R_Qualifier:
    
    A := 0;
    Q := 1; 
    
  D_Qualifier, SD_Qualifier, DS_Qualifier:
  
    A := 0;
    Q := 0; 
      
    m_DelayTimeStamp := ops.tAbsolute;
    DelayActive := 1;
    
  P0_Qualifier:
  
    A := 0;
    Q := 0;
  
  P_Qualifier, P1_Qualifier:
    
    A := 1;
    Q := 0;
    
    DoActive();
  
  else
  
    A := 1;
    Q := 0;
    
    DoActive();
  
  end_case;
  
END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::OnStepInactive

  case m_ActionQualifier of
  
  N_Qualifier, L_Qualifier, D_Qualifier:
    
    if A = 1 then
    
      A := 0;
      Q := 1;   
    
    end_if;   
    
    m_DelayTimeStamp := 0;
    DelayActive := 0;
    
  P_Qualifier, P0_Qualifier:
    
    A := 0;
    Q := 1;     
    
    m_DelayTimeStamp := 0;
    DelayActive := 0;
    
  SD_Qualifier:
  
    // Do nothing (leave the delay timer active)

  else
  
    m_DelayTimeStamp := 0;
    DelayActive := 0;
  
  end_case;


END_FUNCTION


// Constructor
FUNCTION Sfc_Action_Base::Sfc_Action_Base
	VAR_OUTPUT
		ret_code 	: ConfStates;
	END_VAR
  
  m_ActionQualifier     := N_Qualifier;
  m_Priority            := 0;
  m_TimerSetting        := 0;
  m_ActiveTimeStamp     := 0;
  m_DelayTimeStamp      := 0;  
	
  ret_code := C_OK;

END_FUNCTION


// Overrideable for user work handler
FUNCTION VIRTUAL Sfc_Action_Base::OnWork

END_FUNCTION


// Overrideable for user activation handler
FUNCTION VIRTUAL Sfc_Action_Base::OnActive

END_FUNCTION


// Overrideable for user deactivation handler
FUNCTION VIRTUAL Sfc_Action_Base::OnInactive

END_FUNCTION


// Overrideable for reading connected internal variable servers
FUNCTION VIRTUAL Sfc_Action_Base::OnReadInternalVariables

END_FUNCTION


// Overrideable for writing connected internal variable servers
FUNCTION VIRTUAL Sfc_Action_Base::OnWriteInternalVariables

END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::SetPriority
	VAR_INPUT
		Priority 	: UDINT;
	END_VAR
  
  m_Priority := Priority;

END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::GetPriority
	VAR_OUTPUT
		Priority 	: UDINT;
	END_VAR
  
  case m_ActionQualifier of
  
  P_Qualifier:
    
    if (A = 0) & Q then
    
      Priority := m_Priority + OffsetAtFallingEdge$UDINT;
      
    else
    
      Priority := m_Priority + OffsetAtRisingEdge$UDINT;
      
    end_if;

  P0_Qualifier:
  
    Priority := m_Priority + OffsetAtFallingEdge$UDINT;
    
  P1_Qualifier:
    
    Priority := m_Priority + OffsetAtRisingEdge$UDINT;
  
  else
  
    Priority := m_Priority + OffsetRegular$UDINT;
  
  end_case;

END_FUNCTION


FUNCTION GLOBAL Sfc_Action_Base::UpdatePriorities

  if GetParentPtr <> NIL then
  
    GetParentPtr$PtrTo_Sfc_Network_Base^.UpdateActionPriorities();
									
  end_if;

END_FUNCTION
