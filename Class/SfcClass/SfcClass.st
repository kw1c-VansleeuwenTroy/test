//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "SfcClass"
	Revision           = "0.0"
	GUID               = "{C0633FEB-0167-4740-8129-020F548DC299}"
	RealtimeTask       = "true"
	CyclicTask         = "true"
	BackgroundTask     = "true"
	Sigmatek           = "false"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)">
	<Channels>
		<Client Name="Action0" Required="true" Internal="true"/>
		<Client Name="InitStep" Required="true" Internal="true"/>
		<Client Name="InternalVarHolder" Required="true" Internal="true"/>
		<Client Name="Step0" Required="true" Internal="true"/>
		<Client Name="Transition0" Required="true" Internal="true"/>
		<Client Name="Transition1" Required="true" Internal="true"/>
	</Channels>
	<Network Name="SfcClass">
		<!-- List of Components in this network -->
		<Components>
			<Object
				Name       = "_base"
				GUID       = "{951A53DB-30C1-4E1C-BDE7-6303B959F206}"
				Class      = "Sfc_Network_Base"
				Position   = "(218,120)"
				Visualized = "false">
				<Channels>
					<Server Name="ClassSvr"/>
					<Server Name="GetPtrItf"/>
					<Server Name="LogonItf_Action"/>
					<Server Name="LogonItf_Step"/>
					<Client Name="Init_Step_Itf"/>
				</Channels>
			</Object>
			<Object
				Name       = "Action0"
				GUID       = "{9A3DE78C-F1FF-4ECC-A111-BFD1E2F0D81C}"
				Class      = "SfcClass_Action0"
				Position   = "(700,400)"
				Visualized = "true"
				Remotely   = "true">
				<Channels>
					<Server Name="A"/>
					<Server Name="DelayActive"/>
					<Server Name="Itf"/>
					<Server Name="Q"/>
					<Server Name="T"/>
					<Client Name="GetParentPtr"/>
					<Client Name="LogonToInvoker"/>
				</Channels>
			</Object>
			<Object
				Name       = "InitStep"
				GUID       = "{96E6C725-EF39-48C5-80DA-817EE7273C19}"
				Class      = "SfcClass_InitStep"
				Position   = "(400,400)"
				Visualized = "true"
				Remotely   = "true">
				<Channels>
					<Server Name="Itf"/>
					<Server Name="T"/>
					<Server Name="X"/>
					<Client Name="Action0"/>
					<Client Name="CallTransition"/>
					<Client Name="LogonToInvoker"/>
				</Channels>
			</Object>
			<Object
				Name       = "InternalVarHolder"
				GUID       = "{DEDD937B-50DC-42C1-891B-CE6DF4C8DC5B}"
				Class      = "SfcClass_InternalVarHolder"
				Position   = "(100,600)"
				Visualized = "false">
				<Channels>
					<Server Name="ClassSvr"/>
				</Channels>
			</Object>
			<Object
				Name       = "Step0"
				GUID       = "{270105E0-9F52-4011-9C45-15CA81A7F375}"
				Class      = "SfcClass_Step0"
				Position   = "(400,1000)"
				Visualized = "true"
				Remotely   = "true">
				<Channels>
					<Server Name="Itf"/>
					<Server Name="T"/>
					<Server Name="X"/>
					<Client Name="CallTransition"/>
					<Client Name="LogonToInvoker"/>
				</Channels>
			</Object>
			<Object
				Name       = "Transition0"
				GUID       = "{CC445450-648D-4D5C-8F08-ED4E974048FB}"
				Class      = "SfcClass_Transition0"
				Position   = "(400,800)"
				Visualized = "false">
				<Channels>
					<Server Name="TransitionItf"/>
					<Client Name="GetParentPtr"/>
					<Client Name="NextStep"/>
					<Client Name="PrevStep"/>
				</Channels>
			</Object>
			<Object
				Name       = "Transition1"
				GUID       = "{4F26394E-9636-41DC-868A-D5A76B28433E}"
				Class      = "SfcClass_Transition1"
				Position   = "(400,1400)"
				Visualized = "false">
				<Channels>
					<Server Name="TransitionItf"/>
					<Client Name="GetParentPtr"/>
					<Client Name="NextStep"/>
					<Client Name="PrevStep"/>
				</Channels>
			</Object>
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
			<Connection Source="this.ClassSvr" Destination="_base.ClassSvr" Vertices="(1172,210),(744,210),"/>
			<Connection Source="this.InitStep" Destination="InitStep.Itf"/>
			<Connection Source="InitStep.LogonToInvoker" Destination="_base.LogonItf_Step" Vertices="(400,490),(744,270),"/>
			<Connection Source="_base.Init_Step_Itf" Destination="InitStep.X" Vertices="(218,210),(700,550),"/>
			<Connection Source="this.Transition0" Destination="Transition0.TransitionItf"/>
			<Connection Source="Transition0.GetParentPtr" Destination="_base.GetPtrItf" Vertices="(400,1010),(744,390),"/>
			<Connection Source="this.Step0" Destination="Step0.Itf"/>
			<Connection Source="Step0.LogonToInvoker" Destination="_base.LogonItf_Step" Vertices="(400,1090),(744,270),"/>
			<Connection Source="this.Transition1" Destination="Transition1.TransitionItf"/>
			<Connection Source="Transition1.GetParentPtr" Destination="_base.GetPtrItf" Vertices="(400,1610),(744,390),"/>
			<Connection Source="this.InternalVarHolder" Destination="InternalVarHolder.ClassSvr"/>
			<Connection Source="this.Action0" Destination="Action0.Itf"/>
			<Connection Source="Action0.LogonToInvoker" Destination="_base.LogonItf_Action" Vertices="(700,490),(744,330),"/>
			<Connection Source="Action0.GetParentPtr" Destination="_base.GetPtrItf" Vertices="(700,550),(744,390),"/>
			<Connection Source="InitStep.Action0" Destination="Action0.Itf" Vertices="(400,610),(1000,490),"/>
			<Connection Source="InitStep.CallTransition" Destination="Transition0.TransitionItf" Vertices="(400,550),(700,890),"/>
			<Connection Source="Transition0.PrevStep" Destination="InitStep.X" Vertices="(400,890),(700,550),"/>
			<Connection Source="Transition0.NextStep" Destination="Step0.X" Vertices="(400,950),(700,1150),"/>
			<Connection Source="Step0.CallTransition" Destination="Transition1.TransitionItf" Vertices="(400,1150),(700,1490),"/>
			<Connection Source="Transition1.PrevStep" Destination="Step0.X" Vertices="(400,1490),(700,1150),"/>
			<Connection Source="Transition1.NextStep" Destination="InitStep.X" Vertices="(400,1550),(700,550),"/>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
	<SfcImplementation Name="SfcClass">
		<Init Key="InitStep" Class="SfcClass_InitStep" Position="(0,0)">
			<Destination Name="Transition0"/>
			<Action
				Key       = "Action0"
				Class     = "SfcClass_Action0"
				Qualifier = "N  (not stored)"
				ImplType  = "ST">
				<IOInfoList>
				</IOInfoList>
			</Action>
		</Init>
		<Jump Key="SfcClass_Jump0" Position="(0,12)" Destination="InitStep">
			<Destination Name="InitStep"/>
		</Jump>
		<Step Key="Step0" Class="SfcClass_Step0" Position="(0,6)">
			<Destination Name="Transition1"/>
		</Step>
		<Transition
			Key      = "Transition0"
			Class    = "SfcClass_Transition0"
			Position = "(0,4)"
			ImplType = "ST">
			<Destination Name="Step0"/>
			<IOInfoList>
			</IOInfoList>
		</Transition>
		<Transition
			Key      = "Transition1"
			Class    = "SfcClass_Transition1"
			Position = "(0,10)"
			ImplType = "ST">
			<Destination Name="SfcClass_Jump0"/>
			<IOInfoList>
			</IOInfoList>
		</Transition>
	</SfcImplementation>
</Class>
*)
#pragma using Sfc_Network_Base

SfcClass : CLASS
: Sfc_Network_Base
  //Servers:
  //Clients:
	InitStep 	: CltChCmd_SfcClass_InitStep;
	Transition0 	: CltChCmd_SfcClass_Transition0;
	Step0 	: CltChCmd_SfcClass_Step0;
	Transition1 	: CltChCmd_SfcClass_Transition1;
	InternalVarHolder 	: CltChCmd_SfcClass_InternalVarHolder;
	Action0 	: CltChCmd_SfcClass_Action0;
  //Variables:
  //Functions:
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

#pragma using SfcClass_Action0
#pragma using SfcClass_InitStep
#pragma using SfcClass_InternalVarHolder
#pragma using SfcClass_Step0
#pragma using SfcClass_Transition0
#pragma using SfcClass_Transition1


//}}LSL_DECLARATION


FUNCTION GLOBAL TAB SfcClass::@CT_
0$UINT,
2#0100000000000010$UINT, //TY_SFCCLASS
0$UINT, 0$UINT, (SIZEOF(::SfcClass))$UINT, 
0$UINT, 6$UINT, 0$UINT, 
TO_UDINT(3433119743), "SfcClass", //Class
TO_UDINT(1657156943), "Sfc_Network_Base", 2$UINT, 0$UINT, //Baseclass
//Servers:
//Clients:
(::SfcClass.InitStep.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(4134074032), "InitStep", TO_UDINT(1258092639), "SfcClass_InitStep", 0$UINT, 0$UINT, 
(::SfcClass.Transition0.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(3388981324), "Transition0", TO_UDINT(44051902), "SfcClass_Transition0", 0$UINT, 0$UINT, 
(::SfcClass.Step0.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(399374368), "Step0", TO_UDINT(925008227), "SfcClass_Step0", 0$UINT, 0$UINT, 
(::SfcClass.Transition1.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(3203985626), "Transition1", TO_UDINT(1973886248), "SfcClass_Transition1", 0$UINT, 0$UINT, 
(::SfcClass.InternalVarHolder.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(3732915028), "InternalVarHolder", TO_UDINT(1492459133), "SfcClass_InternalVarHolder", 0$UINT, 0$UINT, 
(::SfcClass.Action0.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(4004921111), "Action0", TO_UDINT(473680550), "SfcClass_Action0", 0$UINT, 0$UINT, 
END_FUNCTION


#define USER_CNT_SfcClass 1

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_SfcClass] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION SfcClass::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
		nCmdSize	: UINT;
	END_VAR

	ret_code	:= Sfc_Network_Base::@STD();
	IF ret_code <> C_OK THEN
		RETURN;
	END_IF;
	nCmdSize		:= Sfc_Network_Base::ClassSvr.pMeth^.nCmds$UINT*SIZEOF(pVoid) + CMDMETH.Init;

	_memcpy((#vmt.CmdTable)$^USINT, Sfc_Network_Base::ClassSvr.pMeth, nCmdSize);
	vmt.CmdTable.nCmds		:= nSTDCMD + USER_CNT_SfcClass;
	Sfc_Network_Base::ClassSvr.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Sfc_Network_Base::ClassSvr.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION
