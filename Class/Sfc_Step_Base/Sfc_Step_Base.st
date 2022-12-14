//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "Sfc_Step_Base"
	Revision           = "1.1"
	GUID               = "{952195A7-CF56-4C74-A94D-AD71ADF4C4C4}"
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
	Comment            = "Base class for SFC steps">
	<Channels>
		<Server
			Name           = "Itf"
			GUID           = "{EE9A8E90-38AD-41EC-8AEC-74B0DA1F84BD}"
			Visualized     = "false"
			Initialize     = "false"
			WriteProtected = "true"
			Retentive      = "false"
			Comment        = "Interface to the step class">
			<NewInst>
				<Function Name="SfcCmd_Reset_T">
				</Function>
			</NewInst>
		</Server>
		<Server Name="T" GUID="{E02297B1-17CA-4875-8D87-B1B7ABD5F467}" Visualized="true" Initialize="false" WriteProtected="true" Retentive="false" Comment="Step timer&#13;&#10;&#13;&#10;If the step is active, the value&#13;&#10;of the step timer is the time since&#13;&#10;the last activation of the step&#13;&#10;Otherwise the value of the step timer&#13;&#10;is the duration of the last active phase.&#13;&#10;&#13;&#10;Unit: ms"/>
		<Server Name="X" GUID="{3E8EBD72-4237-43EC-9C7A-6B72AA14D31F}" Visualized="true" Initialize="false" WriteProtected="false" Retentive="false" Comment="Active Flag&#13;&#10;&#13;&#10;Indicates if the step is active."/>
		<Client Name="CallTransition" Required="false" Internal="false" Comment="Client for calling following transitions."/>
		<Client Name="LogonToInvoker" Required="true" Internal="false" Comment="Helper client for registration&#13;&#10;at the step invoker."/>
	</Channels>
	<RevDoku>
		<Owner Company="Sigmatek" Author="LesMax"/>
		<Dokumentation Revision="1.1" Date="2013-08-20" Author="LesMax" Company="Sigmatek" Description="Rework of the mechanism that sets the T server to 1 ms if a step is only active for one cycle"/>
	</RevDoku>
	<Network Name="Sfc_Step_Base">
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
Sfc_Step_Base : CLASS
	TYPE
	  CmdItf :  //! <Type Public="true" Name="CmdItf"/>
	  (
	    SfcCmd_Reset_T
	  )$UINT;
	END_TYPE
  //Servers:
	Itf 	: SvrChCmd_DINT;
	X 	: SvrCh_DINT;
	T 	: SvrCh_UDINT;
  //Clients:
	LogonToInvoker 	: CltCh_pVoid;
	CallTransition 	: CltCh_DINT;
  //Variables:
		m_TimeStamp 	: UDINT;			//! <Variable Comment="Time stamp&#13;&#10;&#13;&#10;Time stamp for active phase duration measuring" Name="m_TimeStamp"/>
  //Functions:
	
	FUNCTION VIRTUAL GLOBAL Init;
	
	FUNCTION VIRTUAL GLOBAL Work;
	
	FUNCTION DoActive;
	
	FUNCTION DoWork;
	
	FUNCTION DoInactive;
	
	FUNCTION GLOBAL SetActiveFlag
		VAR_INPUT
			NewActive 	: DINT;
		END_VAR;
	
	FUNCTION VIRTUAL OnActive;
	
	FUNCTION VIRTUAL OnInactive;
	
	FUNCTION VIRTUAL GLOBAL Itf::NewInst
		VAR_INPUT
			pPara 	: ^CmdStruct;
			pResult 	: ^results;
		END_VAR
		VAR_OUTPUT
			ret_code 	: iprStates;
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL X::Write
		VAR_INPUT
			input (EAX) 	: DINT;
		END_VAR
		VAR_OUTPUT
			result (EAX) 	: DINT;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Sfc_Step_Base::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_STEP_BASE
1$UINT, 1$UINT, (SIZEOF(::Sfc_Step_Base))$UINT, 
3$UINT, 2$UINT, 0$UINT, 
TO_UDINT(2398612339), "Sfc_Step_Base", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::Sfc_Step_Base.Itf.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(3244430248), "Itf", 
(::Sfc_Step_Base.X.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3081909835), "X", 
(::Sfc_Step_Base.T.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(3187964512), "T", 
//Clients:
(::Sfc_Step_Base.LogonToInvoker.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000010$UINT, TO_UDINT(2591088628), "LogonToInvoker", 
(::Sfc_Step_Base.CallTransition.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000000$UINT, TO_UDINT(2051227785), "CallTransition", 
END_FUNCTION


#define USER_CNT_Sfc_Step_Base 3

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Sfc_Step_Base] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Sfc_Step_Base::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT_Sfc_Step_Base, pCmd := #vmt.CmdTable);
	vmt.CmdTable.NewInstr		:= #NewInst();
	vmt.CmdTable.Init		:= #Init();
#pragma warning (disable : 74)
	vmt.UserFcts[0]		:= #Work();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[1]		:= #OnActive();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[2]		:= #OnInactive();

#pragma warning (default : 74)
	Itf.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Itf.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;
	X.pMeth			:= StoreMethod( #M_RD_DIRECT(), #X::Write() );
	IF X.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION

// Implement Worker Interface
FUNCTION VIRTUAL GLOBAL Sfc_Step_Base::Work

  // Call own Work routine if active
  if X = 1 then
  
    DoWork();
  
  end_if;

END_FUNCTION


FUNCTION VIRTUAL GLOBAL Sfc_Step_Base::X::Write
	VAR_INPUT
		input (EAX) 	: DINT;
	END_VAR
	VAR_OUTPUT
		result (EAX) 	: DINT;
	END_VAR

  // Set the Active Flag of the step.
  SetActiveFlag(NewActive:=input);

 	result := X;

END_FUNCTION


FUNCTION GLOBAL Sfc_Step_Base::SetActiveFlag
	VAR_INPUT
		NewActive 	: DINT;
	END_VAR
  
  // Change the Active Flag according to the passed value
  X := NewActive;
  
  if X = 0 then
 
    // Step is being deactivated
    DoInactive();
 
  else
  
    // Step is being activated
    DoActive();
 
  end_if;
  
END_FUNCTION


FUNCTION Sfc_Step_Base::DoWork
  VAR
	  curTime : UDINT;
  END_VAR
  
  // Update the execution timer
  curTime := ops.tAbsolute;
  
  // Handle overflow condition
  if curTime < m_TimeStamp then
  
    T := curTime + sizeof(UDINT) - m_TimeStamp;
    
  else
  
    T := curTime - m_TimeStamp;
  
  end_if;
  
  // Execute the transition check.  
  CallTransition.Read();
 
END_FUNCTION


FUNCTION Sfc_Step_Base::DoActive

  // Save a timestamp for the activation of the action
  m_TimeStamp := ops.tAbsolute;
  
  // Reset the execution timer
  T := 0;
  
  // Call notification handler
  // This handler will be overwritten by
  // the concrete step in order to notify
  // all associated actions that the step
  // was deactivated
  OnActive();
  
END_FUNCTION


FUNCTION Sfc_Step_Base::DoInactive

  // Reset the activation timestamp
  m_TimeStamp := 0;
  
  // If the Step was active for exactly one cycle (T = 0)
  // then the Timer is set to 1ms so that the user can
  // check if the step was active.
  if T = 0 then
    
    T := 1;
    
  end_if;

  // Call notification handler
  // This handler will be overwritten by
  // the concrete step in order to notify
  // all associated actions that the step
  // was deactivated
  OnInactive();
  
END_FUNCTION


FUNCTION VIRTUAL Sfc_Step_Base::OnActive

END_FUNCTION


FUNCTION VIRTUAL Sfc_Step_Base::OnInactive

END_FUNCTION


FUNCTION VIRTUAL GLOBAL Sfc_Step_Base::Init

  if _FirstScan then
  
    LogonToInvoker.Write(input:=this);
  
  end_if;  
  
END_FUNCTION


FUNCTION VIRTUAL GLOBAL Sfc_Step_Base::Itf::NewInst
	VAR_INPUT
		pPara 	: ^CmdStruct;
		pResult 	: ^Results;
	END_VAR
	VAR_OUTPUT
		ret_code 	: IprStates;
	END_VAR

	CASE pPara^.uiCmd OF
		0 : m_TimeStamp := ops.tAbsolute;
        T := 0;
	END_CASE;

	ret_code := READY;

END_FUNCTION
