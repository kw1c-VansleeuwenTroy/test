//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
TYPE
  SvrCh_DINT : STRUCT
    pMeth : ^CHMETH;
    dData : DINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_DINT : STRUCT
    pCh : ^SvrCh_DINT;
    dData : DINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_FeSetup : STRUCT
    pMeth : ^CHMETH;
    dData : FeSetup;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_FeSetup : STRUCT
    pCh : ^SvrCh_FeSetup;
    dData : FeSetup;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_HDINT : STRUCT
    pMeth : ^CHMETH;
    dData : HDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_HDINT : STRUCT
    pCh : ^SvrCh_HDINT;
    dData : HDINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_IO_State : STRUCT
    pMeth : ^CHMETH;
    dData : IO_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_IO_State : STRUCT
    pCh : ^SvrCh_IO_State;
    dData : IO_State;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_pVoid : STRUCT
    pMeth : ^CHMETH;
    dData : pVoid;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_pVoid : STRUCT
    pCh : ^SvrCh_pVoid;
    dData : pVoid;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_t_SDCIPortMode_PTofCls_SdiasSDCIMaster : STRUCT
    pMeth : ^CHMETH;
    dData : SdiasSDCIMaster::t_SDCIPortMode;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_t_SDCIPortMode_PTofCls_SdiasSDCIMaster : STRUCT
    pCh : ^SvrCh_t_SDCIPortMode_PTofCls_SdiasSDCIMaster;
    dData : SdiasSDCIMaster::t_SDCIPortMode;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrCh_UDINT : STRUCT
    pMeth : ^CHMETH;
    dData : UDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltCh_UDINT : STRUCT
    pCh : ^SvrCh_UDINT;
    dData : UDINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  SvrChCmd_DINT : STRUCT
    pMeth : ^CMDMETH;
    dData : DINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd__Can : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_Can;
  END_STRUCT;
  CltChCmd__CanLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_CanLib;
  END_STRUCT;
  CltChCmd__FileSys : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_FileSys;
  END_STRUCT;
  CltChCmd__Lse : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_Lse;
  END_STRUCT;
  CltChCmd__MultiTask : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_MultiTask;
  END_STRUCT;
  CltChCmd__OSKernel : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_OSKernel;
  END_STRUCT;
  CltChCmd__OsziLSEBackground : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_OsziLSEBackground;
  END_STRUCT;
  CltChCmd__SerLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_SerLib;
  END_STRUCT;
  CltChCmd__StdLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_StdLib;
  END_STRUCT;
  CltChCmd__TaskObjectControl : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^_TaskObjectControl;
  END_STRUCT;
  CltChCmd_ASCII_BIN : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^ASCII_BIN;
  END_STRUCT;
  SvrChCmd_UDINT : STRUCT
    pMeth : ^CMDMETH;
    dData : UDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_CriticalSection : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^CriticalSection;
  END_STRUCT;
  CltChCmd_DataServiceClient : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DataServiceClient;
  END_STRUCT;
  CltChCmd_DiasMaster : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMaster;
  END_STRUCT;
  CltChCmd_DiasMasterC : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMasterC;
  END_STRUCT;
  CltChCmd_DiasMasterPostScan : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^DiasMasterPostScan;
  END_STRUCT;
  CltChCmd_DINT : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  CltChCmd_EEPROM : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^EEPROM;
  END_STRUCT;
  CltChCmd_GetBroadCastData : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^GetBroadCastData;
  END_STRUCT;
  CltChCmd_Graphic : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Graphic;
  END_STRUCT;
  CltChCmd_HmiAsciiBuffer : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiAsciiBuffer;
  END_STRUCT;
  CltChCmd_HmiCanSendReceive : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiCanSendReceive;
  END_STRUCT;
  CltChCmd_HmiChkBitList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiChkBitList;
  END_STRUCT;
  CltChCmd_HmiColorMap : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiColorMap;
  END_STRUCT;
  CltChCmd_HmiComPort : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiComPort;
  END_STRUCT;
  CltChCmd_HmiFile : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiFile;
  END_STRUCT;
  CltChCmd_HmiFont35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiFont35;
  END_STRUCT;
  CltChCmd_HmiFontList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiFontList;
  END_STRUCT;
  CltChCmd_HmiFunctionList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiFunctionList;
  END_STRUCT;
  CltChCmd_HmiFunctionList35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiFunctionList35;
  END_STRUCT;
  CltChCmd_HmiImage35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiImage35;
  END_STRUCT;
  CltChCmd_HmiImageList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiImageList;
  END_STRUCT;
  CltChCmd_HmiMapFile : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMapFile;
  END_STRUCT;
  CltChCmd_HmiMemCircle : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemCircle;
  END_STRUCT;
  CltChCmd_HmiMemImage : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemImage;
  END_STRUCT;
  CltChCmd_HmiMemIO : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemIO;
  END_STRUCT;
  CltChCmd_HmiMemLine : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemLine;
  END_STRUCT;
  CltChCmd_HmiMemRectangle : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemRectangle;
  END_STRUCT;
  CltChCmd_HmiMemText : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemText;
  END_STRUCT;
  CltChCmd_HmiMemZorder : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiMemZorder;
  END_STRUCT;
  CltChCmd_HmiProject35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiProject35;
  END_STRUCT;
  CltChCmd_HmiProjectList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiProjectList;
  END_STRUCT;
  CltChCmd_HmiScreen : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiScreen;
  END_STRUCT;
  CltChCmd_HmiSetUpList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiSetUpList;
  END_STRUCT;
  CltChCmd_HmiSetupList35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiSetupList35;
  END_STRUCT;
  CltChCmd_HmiShemeList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiShemeList;
  END_STRUCT;
  CltChCmd_HmiShemeList35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiShemeList35;
  END_STRUCT;
  CltChCmd_HmiStateBit35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiStateBit35;
  END_STRUCT;
  CltChCmd_HmiStrLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiStrLib;
  END_STRUCT;
  CltChCmd_HmiT9Config35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiT9Config35;
  END_STRUCT;
  CltChCmd_HmiTextList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiTextList;
  END_STRUCT;
  CltChCmd_HmiTextList35 : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^HmiTextList35;
  END_STRUCT;
  CltChCmd_HmiTextList35Manager : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiTextList35Manager;
  END_STRUCT;
  CltChCmd_HmiUniBuffer : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiUniBuffer;
  END_STRUCT;
  CltChCmd_HmiUnitList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiUnitList;
  END_STRUCT;
  CltChCmd_HmiUtils : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiUtils;
  END_STRUCT;
  CltChCmd_HmiVarInfoList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiVarInfoList;
  END_STRUCT;
  CltChCmd_HmiVarList : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiVarList;
  END_STRUCT;
  CltChCmd_HmiVarList35 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HmiVarList35;
  END_STRUCT;
  CltChCmd_Hub_Base : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Hub_Base;
  END_STRUCT;
  CltChCmd_Hub_Base_Root : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Hub_Base_Root;
  END_STRUCT;
  CltChCmd_HwcLogging : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HwcLogging;
  END_STRUCT;
  CltChCmd_HwControl : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HwControl;
  END_STRUCT;
  CltChCmd_HwControlBase : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HwControlBase;
  END_STRUCT;
  CltChCmd_HWKVarSizeFIFO : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HWKVarSizeFIFO;
  END_STRUCT;
  CltChCmd_HWRtPostScan : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^HWRtPostScan;
  END_STRUCT;
  CltChCmd_I2CCDIAS : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^I2CCDIAS;
  END_STRUCT;
  CltChCmd_MerkerEx : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^MerkerEx;
  END_STRUCT;
  CltChCmd_Ram : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Ram;
  END_STRUCT;
  CltChCmd_RamFile : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^RamFile;
  END_STRUCT;
  CltChCmd_SafetyManager : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SafetyManager;
  END_STRUCT;
  CltChCmd_SdiasHubBase : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SdiasHubBase;
  END_STRUCT;
  SvrChCmd_t_e_VaranErrors : STRUCT
    pMeth : ^CMDMETH;
    dData : t_e_VaranErrors;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_SdiasManager : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^SdiasManager;
  END_STRUCT;
  CltChCmd_SdiasSafetyManagerFSoE : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SdiasSafetyManagerFSoE;
  END_STRUCT;
  CltChCmd_Sfc_Action_Base : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^Sfc_Action_Base;
  END_STRUCT;
  SvrChCmd_pVoid : STRUCT
    pMeth : ^CMDMETH;
    dData : pVoid;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_Sfc_ActionInvoker : STRUCT
    pCh : ^SvrChCmd_pVoid;
    dData : pVoid;
    pCmd : ^Sfc_ActionInvoker;
  END_STRUCT;
  CltChCmd_SFC_Sort : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SFC_Sort;
  END_STRUCT;
  CltChCmd_Sfc_StepInvoker : STRUCT
    pCh : ^SvrChCmd_pVoid;
    dData : pVoid;
    pCmd : ^Sfc_StepInvoker;
  END_STRUCT;
  CltChCmd_SfcClass_Action0 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_Action0;
  END_STRUCT;
  CltChCmd_SfcClass_InitStep : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_InitStep;
  END_STRUCT;
  CltChCmd_SfcClass_InternalVarHolder : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_InternalVarHolder;
  END_STRUCT;
  CltChCmd_SfcClass_Step0 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_Step0;
  END_STRUCT;
  CltChCmd_SfcClass_Transition0 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_Transition0;
  END_STRUCT;
  CltChCmd_SfcClass_Transition1 : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SfcClass_Transition1;
  END_STRUCT;
  CltChCmd_SigCLib : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^SigCLib;
  END_STRUCT;
  CltChCmd_String : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^String;
  END_STRUCT;
  CltChCmd_StringInternal : STRUCT
    pCh : ^SvrChCmd_UDINT;
    dData : UDINT;
    pCmd : ^StringInternal;
  END_STRUCT;
  SvrChCmd_IO_State : STRUCT
    pMeth : ^CMDMETH;
    dData : IO_State;
    pDsc : ^SVRDSC;
  END_STRUCT;
  CltChCmd_SyncCall : STRUCT
    pCh : ^SvrChCmd_IO_State;
    dData : IO_State;
    pCmd : ^SyncCall;
  END_STRUCT;
  CltChCmd_System : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^System;
  END_STRUCT;
  CltChCmd_t_e_VaranErrors : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^SVRCHCMD;
  END_STRUCT;
  CltChCmd_Varan_Base : STRUCT
    pCh : ^SvrChCmd_t_e_VaranErrors;
    dData : t_e_VaranErrors;
    pCmd : ^Varan_Base;
  END_STRUCT;
  CltChCmd_VaranManager_Base : STRUCT
    pCh : ^SvrChCmd_DINT;
    dData : DINT;
    pCmd : ^VaranManager_Base;
  END_STRUCT;
  CltChCmd_WatchdogDias : STRUCT
    pCh : ^SvrChCmd_IO_State;
    dData : IO_State;
    pCmd : ^WatchdogDias;
  END_STRUCT;
  SvrCh__FSM_UDP_ERROR_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_FSM_UDP_ERROR;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__FSM_UDP_USER_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_FSM_UDP_USER;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh__INITSTEPS_PTofCls_SafetyUDP : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyUDP::_INITSTEPS;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_BDINT : STRUCT
    pMeth : ^CHMETH;
    dData : BDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_SafetyConfigStateType : STRUCT
    pMeth : ^CHMETH;
    dData : SafetyConfigStateType;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_e_VaranErrors : STRUCT
    pMeth : ^CHMETH;
    dData : t_e_VaranErrors;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_FaultFlagSvr_PTofCls_SDCIDevice : STRUCT
    pMeth : ^CHMETH;
    dData : SDCIDevice::t_FaultFlagSvr;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_s_SdiasFWStateStandard_PTofCls_SdiasBase : STRUCT
    pMeth : ^CHMETH;
    dData : SdiasBase::t_s_SdiasFWStateStandard;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_t_SDCIPortStateBits_PTofCls_SdiasSDCIMaster : STRUCT
    pMeth : ^CHMETH;
    dData : SdiasSDCIMaster::t_SDCIPortStateBits;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_TErrorSvr_PTofCls_LseEasy : STRUCT
    pMeth : ^CHMETH;
    dData : LseEasy::TErrorSvr;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_TIME_LSL : STRUCT
    pMeth : ^CHMETH;
    dData : TIME_LSL;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrCh_TStateSvr_PTofCls_LseEasy : STRUCT
    pMeth : ^CHMETH;
    dData : LseEasy::TStateSvr;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrChCmd_BDINT : STRUCT
    pMeth : ^CMDMETH;
    dData : BDINT;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrChCmd_DATE_LSL : STRUCT
    pMeth : ^CMDMETH;
    dData : DATE_LSL;
    pDsc : ^SVRDSC;
  END_STRUCT;
  SvrChCmd_iprStates : STRUCT
    pMeth : ^CMDMETH;
    dData : iprStates;
    pDsc : ^SVRDSC;
  END_STRUCT;
END_TYPE