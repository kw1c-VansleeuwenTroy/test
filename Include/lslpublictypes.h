//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
#RE_IN_DE
#pragma define (store)
#if _LSL_COMPILERVERSION >= 42
HwcLogging : CLASS;
Sfc_Network_Base : CLASS;
SigCLib : CLASS;
#endif
_SerLib : CLASS_PUBLIC
	TYPE
	  CmdCommand :
	  (
	    StartUserIPR,
	    StopUserIPR,
	    SerCloseIPR,
	    SerSendIPR,
	    RecvCharIPR,
	    SetOnlineIPR,
	    GetRecvStateIPR,
	    GetSendStateIPR,
	    GetErrorIPR,
	    IsInitializedIPR,
	    ClearRecBufferIPR,
	    RtsOnOffIPR,
	    rdRtsIPR,
	    rdCtsIPR,
	    DtrOnOffIPR,
	    rdDtrIPR,
	    rdDcdIPR,
	    rdDsrIPR,
	    rdRiIPR,
	    SetRSModeIPR,
	    GetRSModeIPR,
	    GetInterfaceTypeIPR
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
LseEasy : CLASS_PUBLIC
#include "..\Source\Common\hmi_nuc.h"
	TYPE
	  TErrorSvr :
	  (
	    ErrNone,
	    ErrCreateHmiProject,
	    ErrLseCompilerVersion,
	    ErrLoadLseProject,
	    ErrSizeLseProject,
	    ErrUploadHmiProject,
	    ErrHmiCommunication
	  )$UDINT;
	  TStateSvr :
	  (
	    TStart,
	    TUpLoad,
	    TRun,
	    TError,
	    TFirmwareUpdate,
	    TSleep,
	    TChkCrc,
	    TGetScreenShot,
	    TReboot,
	    TBootLoaderUpdate,
	    TCheckUpdateBootloader,
	    TCheckUpdateFirmware
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
MerkerEx : CLASS_PUBLIC
#include <.\lsl_st_mt.h>
	TYPE
	  Cmdm_udLength :
	  (
	    GET_DATA_PTR,
	    EXCHANGE_DATA_PTR,
	    SAVE_DATA_TO_RAMEXFILE
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
SafetyBaseFSoE : CLASS_PUBLIC
#include "..\Source\interfaces\lsl_st_safety.h"
#include "..\Class\SafetyManager\SafetyManager.h"
#include "..\Source\BusInterface.h"
#include "..\Class\SafetyBaseFSoE\SafetyBaseFSoE.h"
#include "..\Source\interfaces\lsl_st_hardwaretree.h"
	TYPE
#pragma pack(push, 1)
	  SDOHeader : STRUCT
	    StdHeader : t_SDOStdHeader;
	    SrcAdr : HDINT;
	    DstAdr : HDINT;
	    SessId : UDINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
SafetyCDIAS_Base : CLASS_PUBLIC
#include "..\Class\SafetyCDIAS_Base\SafetyCDIAS_Base.h"
#include "..\Source\interfaces\lsl_st_safety.h"
#include "..\Class\SafetyManager\SafetyManager.h"
	TYPE
	  FrameTypeType : BSINT
	  [
	    1 Cfg,
	    2 ToP,
	    3 Standard,
	    4 PDO,
	    5 TDO,
	    6 Reserved1,
	    7 Reserved2,
	    8 Response,
	  ];
#pragma pack(push, 1)
	  SDOStdHeader : STRUCT
	    CRC : UDINT;
	    Cmd : USINT;
	    Typ : FrameTypeType;
	    SeqNr : USINT;
	    Len : USINT;
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  SDOHeader : STRUCT
	    StdHeader : SDOStdHeader;
	    SrcAdr : HDINT;
	    DstAdr : HDINT;
	    SessId : UDINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
SafetyUDP : CLASS_PUBLIC
	TYPE
	  _FSM_UDP_ERROR :
	  (
	    _NO_ERROR_UDP_ERROR:=0,
	    _INIT_TCP_USER_UDP_ERROR:=4294967295,
	    _NO_IP_ADDRESS_UDP_ERROR:=4294967294,
	    _NO_MEMORY_SOCKET_UDP_ERROR:=4294967293,
	    _NO_MEMORY_SENDBUFFER_UDP_ERROR:=4294967292,
	    _INVALID_HANDLE_UDP_ERROR:=4294967291,
	    _SHUTDOWN_UDP_ERROR:=4294967290,
	    _CLOSESOCKET_UDP_ERROR:=4294967289,
	    _ALLOCATE_SOCKET_UDP_ERROR:=4294967288,
	    _SET_BIND_UDP_ERROR:=4294967287,
	    _RECV_UDP_ERROR:=4294967286,
	    _SEND_UDP_ERROR:=4294967285,
	    _NO_LOCAL_IP_UDP_ERROR:=4294967284,
	    _NO_DESTINATION_IP_UDP_ERROR:=4294967283,
	    _INVALID_UDP_PORT_UDP_ERROR,
	    _INVALID_INTERFACE_NUMBER_UDP_ERROR,
	    _NO_MEMORY_RECEIVE_BUFFER_UDP_ERROR,
	    _NO_MEMORY_CONNECTION_BUFFER_UDP_ERROR
	  )$DINT;
	  _FSM_UDP_USER :
	  (
	    _STATE_INIT_UDP,
	    _STATE_IDLE_UDP,
	    _STATE_SOCK_UDP,
	    _STATE_CONNECT_UDP,
	    _STATE_ONLY_SEND_UDP,
	    _STATE_RECV_UDP,
	    _STATE_SEND_UDP,
	    _STATE_SHUTDOWN_UDP,
	    _STATE_CLOSE_SOCK_UDP,
	    _STATE_ERROR_UDP
	  )$UDINT;
	  _INITSTEPS :
	  (
	    _NO_OPERATION,
	    _ADD_SOCKET,
	    _CHECK_IF_SOCKET_OPEN,
	    _BIND_SOCKET,
	    _CLOSE_CON
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
SDCIDevice : CLASS_PUBLIC
#include "..\Class\SdiasBase\SdiasBase.h"
#include "..\Class\SdiasSDCIMaster\SdiasSDCIMaster.h"
	TYPE
#pragma pack(push, 1)
	  t_AdditionalInfo : STRUCT
	    PortNo : USINT;
	    TotalReadSize : USINT;
	    TotalWriteSize : USINT;
	  END_STRUCT;
#pragma pack(pop)
	  t_FaultFlagSvr :
	  (
	    _NoFault,
	    _ComLost,
	    _RevisionFault,
	    _CompatibilityFault,
	    _SerialNumFault,
	    _DataStorageFault
	  )$UDINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk SdiasBase
SdiasBase : CLASS_PUBLIC
#include "..\Class\SdiasManager\SdiasManager.h"
#include "..\Class\SdiasBase\SdiasBase.h"
#include "..\Class\HwControl\HwControl.h"
#include "..\Source\interfaces\lsl_st_hardwaretree.h"
#include "..\Source\interfaces\lsl_st_mt.h"
	TYPE
	  t_b_SdiasFWState : BINT
	  [
	    1 VoltageNotOk,
	    2 NoSync,
	    3 FlashDataCRCError,
	    4 RAMDataCRCError,
	    5 FlashUnsafe,
	    6 BusTimeNotSupported,
	    7 ToggleBit,
	  ];
#pragma pack(push, 1)
	  t_s_SdiasFWStateStandard : STRUCT
	    ErrorBits : t_b_SdiasFWState;
	    Reserved : UINT;
	  END_STRUCT;
#pragma pack(pop)
#pragma pack(push, 1)
	  t_s_SPI_AccessControl : STRUCT
	    udAccessHandle : UDINT;
	    usAccessLength : USINT;
	    usAccessOffset : USINT;
	    pControlByte : t_SDIAS_pControlByte;
	    pStateByte : t_SDIAS_pStateByte;
	  END_STRUCT;
#pragma pack(pop)
	  t_SPI_PDO_DataWrite : ARRAY [0..SDIAS_MAX_PDO_SIZE-1] OF USINT;
	  t_SPI_PDO_DataRead : ARRAY [0..SDIAS_MAX_PDO_SIZE-1] OF USINT;
	  t_e_SPIWriteSSW :
	  (
	    _SPIWrite_Idle,
	    _AllocateMemory,
	    _SetRequest,
	    _ReadGrant,
	    _ReadSectorData_SetPageAddress,
	    _ReadSectorData_Wait4SetPageAddress,
	    _ReadSectorData_SetReadPageCommand,
	    _ReadSectorData_Wait4SetReadPageCommand,
	    _ReadSectorData_ReadReceiveBufferPart1,
	    _ReadSectorData_ReadReceiveBufferPart2,
	    _EraseSector_SetPageAddress,
	    _EraseSector_Wait4SetPageAddress,
	    _EraseSector_SetEraseSectorCommand,
	    _EraseSector_Wait4SetEraseSectorCommand,
	    _WriteSectorData_SetPageAddress,
	    _WriteSectorData_Wait4SetPageAddress,
	    _WriteSectorData_WriteTransmitBufferPart1,
	    _WriteSectorData_WriteTransmitBufferPart2,
	    _WriteSectorData_SetWritePageCommand,
	    _WriteSectorData_Wait4SetWritePageCommand,
	    _VerifySectorData_SetPageAddress,
	    _VerifySectorData_Wait4SetPageAddress,
	    _VerifySectorData_SetReadPageCommand,
	    _VerifySectorData_Wait4SetReadPageCommand,
	    _VerifySectorData_ReadReceiveBufferPart1,
	    _VerifySectorData_ReadReceiveBufferPart2,
	    _VerifySectorData_CompareData,
	    _ClearRequest,
	    _DisableDataObjects,
	    _FreeMemory,
	    _FinishSPIWrite
	  )$UDINT;
	  usWriteModes : USINT;
#pragma pack(push, 1)
	  t_s_SPIWriteVars : STRUCT
	    sWriteAccess : t_s_SPI_AccessControl;
	    pWriteData : ^t_SPI_PDO_DataWrite;
	    sReadAccess : t_s_SPI_AccessControl;
	    pReadData : ^t_SPI_PDO_DataRead;
	    sReadStateAccess : t_s_SPI_AccessControl;
	    pReadStateData : ^USINT;
	    pSectorMemoryRead : ^USINT;
	    pSectorMemoryWrite : ^USINT;
	    pSectorMemoryVerify : ^USINT;
	    pUserWriteData : ^USINT;
	    udUserWriteLength : UDINT;
	    usUserSectorNumber : USINT;
	    usUserPageNumber : USINT;
	    usUserPageOffset : USINT;
	    eSPIWriteSSW : t_e_SPIWriteSSW;
	    eSPIWriteSSWError : t_e_SPIWriteSSW;
	    uiCurrentPage : UINT;
	    udCurrentSectorMemoryOffset : UDINT;
	    usRetryCnt : USINT;
	    bsFinished : BSINT
	    [
	      1 Finished,
	      2 Error,
	      3 Bit3,
	      4 Bit4,
	      5 Bit5,
	      6 Bit6,
	      7 Bit7,
	      8 Bit8,
	    ];
	    usCycleWaitCnt : USINT;
	    udTimeout : UDINT;
	    NotReadyCnt : DINT;
	    usFinishedWriteLog : USINT;
	    usWriteMode : usWriteModes;
	    udMemoryToAllocate : UDINT;
	    uiLastPage : UINT;
	    udUserDataOffset : DINT;
	  END_STRUCT;
#pragma pack(pop)
	END_TYPE
END_CLASS;
#pragma define (restore)
#pragma InclDefBlk SdiasSDCIMaster
SdiasSDCIMaster : CLASS_PUBLIC
: SdiasBase
#include "..\Source\BusInterface.h"
#include "..\Class\SdiasSDCIMaster\SdiasSDCIMaster.h"
	TYPE
	  t_EventInfo : BINT
	  [
	    1 InstanceBit0,
	    2 InstanceBit1,
	    3 InstanceBit2,
	    4 InstanceBit3,
	    5 ModeBit0,
	    6 ModeBit1,
	    7 ModeBit2,
	    8 ModeBit3,
	    9 TypeBit0,
	    10 TypeBit1,
	    11 TypeBit2,
	    12 TypeBit3,
	    13 OriginBit0,
	    14 OriginBit1,
	    15 OriginBit2,
	    16 OriginBit3,
	  ];
	  t_EventCodes :
	  (
	    E_EVENT_NO_MALFUNCTION:=0,
	    E_EVENT_GENERAL_MALFUNCTION:=4096,
	    E_EVENT_EXCESS_AMBIENT_TEMPERATURE:=16656,
	    E_EVENT_TOO_LOW_AMBIENT_TEMPERATURE:=16672,
	    E_EVENT_EXCESS_DEVICE_TEMPERATURE:=16912,
	    E_EVENT_TOO_LOW_DEVICE_TEMPERATURE:=16928,
	    E_EVENT_EXCESS_PERIPHERY_TEMPERATURE:=17168,
	    E_EVENT_TOO_LOW_PERIPHERY_TEMPERATURE:=17184,
	    E_EVENT_HW_COMPONENT_MALFUNCTION:=20496,
	    E_EVENT_LOW_SUPPLY_VOLTAGE_15V:=20753,
	    E_EVENT_LOW_SUPPLY_VOLTAGE_24V:=20754,
	    E_EVENT_LOW_SUPPLY_VOLTAGE_5V:=20755,
	    E_EVENT_SHORT_CIRCUIT:=20817,
	    E_EVENT_OUTPUT_STAGE:=21520,
	    E_EVENT_FUSE_S1:=21585,
	    E_EVENT_FUSE_S2:=21586,
	    E_EVENT_FUSE_S3:=21587,
	    E_EVENT_SW_RESET_WATCHDOG:=24592,
	    E_EVENT_LOSS_OF_PARAMETER:=25360,
	    E_EVENT_PARAMETER_ERROR:=25376,
	    E_EVENT_PARAMETER_NOT_INITIALIZED:=25392,
	    E_EVENT_PARAMETER_NON_SPECIFIC:=25408,
	    E_EVENT_PARAMETER_CHANGED:=25424,
	    E_EVENT_PROCESS_DATA_MONITORING:=33040,
	    E_EVENT_EXCESS_PROCESS_VARIABLE_RANGE:=35856,
	    E_EVENT_EXCESS_MEASUREMENT_RANGE:=35872,
	    E_EVENT_TOO_LOW_PROCESS_VARIABLE_RANGE:=35888,
	    E_EVENT_ADVANCE_WARNING:=35904,
	    E_EVENT_EXTERNAL_MALFUNCTION:=36864,
	    E_EVENT_UV33UNDERVOLTAGE:=49409,
	    E_EVENT_OVERTEMPERATURE:=49410,
	    E_EVENT_UV24UNDERVOLTAGE:=49411,
	    E_EVENT_CQSHORTCUT:=49412,
	    E_EVENT_DSACCESSERROR:=49665,
	    E_EVENT_NEW_SLAVE:=65313,
	    E_EVENT_DEV_COM_LOST:=65314,
	    E_EVENT_DS_IDENT_MISMATCH:=65315,
	    E_EVENT_DS_BUFFER_OVERFLOW:=65316,
	    E_EVENT_DS_ACCESS_DENIED:=65317,
	    E_EVENT_DS_INCORRECT_EVENT:=65329,
	    E_EVENT_DS_UPLOAD_REQ:=65425
	  )$UINT;
#pragma pack(push, 1)
	  t_SDCIEventDetails : STRUCT
	    EventInfo : SdiasSDCIMaster::t_EventInfo;
	    EventCode : SdiasSDCIMaster::t_EventCodes;
	  END_STRUCT;
#pragma pack(pop)
	  t_SDCIPortMode :
	  (
	    _Inactive,
	    _DigitalInput,
	    _DigitalOutput,
	    _SDCI
	  )$UDINT;
	  t_SDCIPortStateBits : BDINT
	  [
	    1 Operating,
	    2 ReadyToOperate,
	    3 InputProcessDataValid,
	    4 EventAvailable,
	    5 OdeState,
	    6 PdeState,
	    7 DuState,
	    8 DsUploaded,
	  ];
#pragma pack(push, 1)
	  t_SDCIEventBuffer : STRUCT
	    EventWrIndex : USINT;
	    EventRdIndex : USINT;
	    aEvents : ARRAY [0..SIOL_EVENT_BUFFER_SIZE-1] OF SdiasSDCIMaster::t_SDCIEventDetails;
	  END_STRUCT;
#pragma pack(pop)
	  t_SDCIRetCode :
	  (
	    SDCI_Busy:=1,
	    SDCI_Ready_Ok:=0,
	    SDCI_InvalidPointer:=4294967295,
	    SDCI_InvalidLength:=4294967294,
	    SDCI_InvalidLengthOffsetCombination:=4294967293,
	    SDCI_NoReadDataAtModule:=4294967292,
	    SDCI_NoWriteDataAtModule:=4294967291,
	    SDCI_NotAvailableAtThisPort:=4294967290,
	    SDCI_ModuleNotAvailable:=4294967289,
	    SDCI_ReadDataCurrentlyNotValid:=4294967288,
	    SDCI_PortNbrNotSupported:=4294967287,
	    SDCI_UnspecifiedError:=4294967286,
	    SDCI_TimeoutInComToMicroCtrl:=4294967285,
	    SDCI_InvalidChecksumFromMicroCtrl:=4294967284,
	    SDCI_MicroCtrl_ApplicationError:=4294967283,
	    SDCI_MicroCtrl_InvalidChkSum:=4294967282,
	    SDCI_MicroCtrl_FunctionIdNotSupported:=4294967281,
	    SDCI_MicroCtrl_InvalidParamUsage:=4294967280,
	    SDCI_MicroCtrl_ServiceNotAvailable:=4294967279,
	    SDCI_MicroCtrl_RspLengthTooBig:=4294967278,
	    SDCI_MicroCtrl_UnexpectedRspLength:=4294967277,
	    SDCI_MicroCtrl_UnexpectedRspData:=4294967276
	  )$DINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
Sfc_Action_Base : CLASS_PUBLIC
	TYPE
	  ActionQualifiers :
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
	END_TYPE
END_CLASS;
#pragma define (restore)
Sfc_Step_Base : CLASS_PUBLIC
	TYPE
	  CmdItf :
	  (
	    SfcCmd_Reset_T
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)
VirtualBaseInit : CLASS_PUBLIC
	TYPE
	  CmdData :
	  (
	    GET_ADD_INFO,
	    READ_DATA,
	    WRITE_DATA,
	    READ_DATA_OFF,
	    WRITE_DATA_OFF
	  )$UINT;
	END_TYPE
END_CLASS;
#pragma define (restore)

#RE_IN_DE