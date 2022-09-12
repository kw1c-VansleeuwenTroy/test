//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "Sfc_Logic_Or_3"
	Revision           = "1.1"
	GUID               = "{2135B305-48DA-431D-88F8-258167DDE487}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "false"
	Sigmatek           = "true"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	IconPath           = ".\Class\Sfc_Logic_Or_3\Logic_Or_Base.ico"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)"
	Comment            = "V1.1 Logic OR class with 3 operands">
	<Channels>
		<Server
			Name           = "Result"
			Initialize     = "false"
			Visualized     = "false"
			WriteProtected = "true"
			Comment        = "If one client is &lt;&gt; 0 then result = 1">
		</Server>
		<Client Name="Op1" Required="false" Internal="false" Comment="Operand 1"/>
		<Client Name="Op2" Required="false" Internal="false" Comment="Operand 2"/>
		<Client Name="Op3" Required="false" Internal="false" Comment="Operand 3"/>
	</Channels>
	<Network Name="Sfc_Logic_Or_3">
		<!-- List of Components in this network -->
		<Components>
			<Object
				Name       = "_base"
				GUID       = "{913E6D46-DF21-11D5-B925-0010609208D7}"
				Class      = "Sfc_Logic_Or_Base"
				Position   = "(420,750)"
				Visualized = "false">
				<Channels>
					<Server Name="Result"/>
				</Channels>
			</Object>
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
			<Connection Source="this.Result" Destination="_base.Result" Vertices="(892,210),(720,840),"/>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
</Class>
*)
#pragma using Sfc_Logic_Or_Base

Sfc_Logic_Or_3 : CLASS
: Sfc_Logic_Or_Base
  //Servers:
  //Clients:
	Op1 	: CltCh_DINT;
	Op2 	: CltCh_DINT;
	Op3 	: CltCh_DINT;
  //Variables:
  //Functions:
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

//}}LSL_DECLARATION


FUNCTION GLOBAL TAB Sfc_Logic_Or_3::@CT_
0$UINT,
2#0100000000000000$UINT, //TY_SFC_LOGIC_OR_3
1$UINT, 1$UINT, (SIZEOF(::Sfc_Logic_Or_3))$UINT, 
0$UINT, 3$UINT, 0$UINT, 
TO_UDINT(1364719443), "Sfc_Logic_Or_3", //Class
TO_UDINT(179462401), "Sfc_Logic_Or_Base", 1$UINT, 6$UINT, //Baseclass
//Servers:
//Clients:
(::Sfc_Logic_Or_3.Op1.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000000$UINT, TO_UDINT(1877102209), "Op1", 
(::Sfc_Logic_Or_3.Op2.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000000$UINT, TO_UDINT(4142604091), "Op2", 
(::Sfc_Logic_Or_3.Op3.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000000$UINT, TO_UDINT(2179739565), "Op3", 
END_FUNCTION


#define USER_CNT_Sfc_Logic_Or_3 0

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT_Sfc_Logic_Or_3] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION Sfc_Logic_Or_3::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
		nCmdSize	: UINT;
	END_VAR

	ret_code	:= Sfc_Logic_Or_Base::@STD();
	IF ret_code <> C_OK THEN
		RETURN;
	END_IF;
	nCmdSize		:= Sfc_Logic_Or_Base::Result.pMeth^.nCmds$UINT*SIZEOF(pVoid) + CMDMETH.Init;

	_memcpy((#vmt.CmdTable)$^USINT, Sfc_Logic_Or_Base::Result.pMeth, nCmdSize);
	vmt.CmdTable.nCmds		:= nSTDCMD + USER_CNT_Sfc_Logic_Or_3;
	Sfc_Logic_Or_Base::Result.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF Sfc_Logic_Or_Base::Result.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION
