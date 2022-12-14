//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "SfcClass_Step0"
	Revision           = "0.0"
	GUID               = "{93D48E9E-EFAB-41F4-B726-94F8C5425DA0}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "false"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)">
	<Channels>
	</Channels>
	<Network Name="SfcClass_Step0">
		<!-- List of Components in this network -->
		<Components>
			<Object
				Name       = "_base"
				GUID       = "{6D52107C-C89A-4B01-8602-AF8D9190665D}"
				Class      = "Sfc_Step_Base"
				Position   = "(218,120)"
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
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
			<Connection Source="this.Itf" Destination="_base.Itf" Vertices="(690,210),(518,210),"/>
			<Connection Source="this.X" Destination="_base.X" Vertices="(690,270),(518,270),"/>
			<Connection Source="this.T" Destination="_base.T" Vertices="(690,330),(518,330),"/>
			<Connection Source="_base.LogonToInvoker" Destination="this.LogonToInvoker" Vertices="(230,210),(38,210),"/>
			<Connection Source="_base.CallTransition" Destination="this.CallTransition" Vertices="(230,270),(38,270),"/>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
</Class>
*)
#pragma using Sfc_Step_Base

SfcClass_Step0 : CLASS
: Sfc_Step_Base
  //Servers:
  //Clients:
  //Variables:
  //Functions:
				//! <Function Name="OnActive" Hidden="true"/>
	FUNCTION VIRTUAL OnActive;
				//! <Function Name="OnInactive" Hidden="true"/>
	FUNCTION VIRTUAL OnInactive;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB SfcClass_Step0::@CT_
0$UINT,
2#0100000000000010$UINT, //TY_SFCCLASS_STEP0
0$UINT, 0$UINT, (SIZEOF(::SfcClass_Step0))$UINT, 
0$UINT, 0$UINT, 0$UINT, 
TO_UDINT(925008227), "SfcClass_Step0", //Class
TO_UDINT(2398612339), "Sfc_Step_Base", 1$UINT, 1$UINT, //Baseclass
//Servers:
//Clients:
END_FUNCTION


#define USER_CNT_SfcClass_Step0 3

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_SfcClass_Step0] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION SfcClass_Step0::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
		nCmdSize	: UINT;
	END_VAR

	ret_code	:= Sfc_Step_Base::@STD();
	IF ret_code <> C_OK THEN
		RETURN;
	END_IF;
	nCmdSize		:= Sfc_Step_Base::Itf.pMeth^.nCmds$UINT*SIZEOF(pVoid) + CMDMETH.Init;

	_memcpy((#vmt.CmdTable)$^USINT, Sfc_Step_Base::Itf.pMeth, nCmdSize);
	vmt.CmdTable.nCmds		:= nSTDCMD + USER_CNT_SfcClass_Step0;
#pragma warning (disable : 74)
	vmt.UserFcts[1]		:= #OnActive();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[2]		:= #OnInactive();

#pragma warning (default : 74)
	Sfc_Step_Base::Itf.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Sfc_Step_Base::Itf.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION
//{{LSL_HIDDEN_FUNCTION
FUNCTION VIRTUAL SfcClass_Step0::OnActive

END_FUNCTION
FUNCTION VIRTUAL SfcClass_Step0::OnInactive

END_FUNCTION
//}}LSL_HIDDEN_FUNCTION
