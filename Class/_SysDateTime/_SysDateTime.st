//This file was generated by the LASAL2 CodeGenerator  -- 
//Please, do not edit this file (it might be overwritten by the next generator run)
//{{LSL_DECLARATION

(*!
<Class
	Name               = "_SysDateTime"
	Revision           = "0.10"
	GUID               = "{CBF432E1-D3B3-439C-B706-A16641D03D70}"
	RealtimeTask       = "false"
	CyclicTask         = "false"
	BackgroundTask     = "true"
	DefBackground      = "100 ms"
	Sigmatek           = "true"
	OSInterface        = "false"
	HighPriority       = "false"
	Automatic          = "false"
	UpdateMode         = "Prescan"
	SharedCommandTable = "true"
	Objectsize         = "(284,120)"
	Comment            = "provides SystemTime and SystemDate">
	<Channels>
		<Server Name="DayOfWeek" GUID="{9932021F-6C7A-41A0-8E00-CEBE786433C1}" Visualized="true" Initialize="false" WriteProtected="true" Retentive="false"/>
		<Server Name="SysDate" GUID="{0B477768-BD5B-4C0B-BCA5-9E3AA91B2C1D}" Visualized="true" Initialize="false" WriteProtected="false" Retentive="false"/>
		<Server Name="SysTime" GUID="{01AA06EB-72AD-4AE7-ACC7-2A3FF23A3213}" Visualized="true" Initialize="false" WriteProtected="false" Retentive="false"/>
		<Client Name="DoSummerTime" Required="true" Internal="false" DefValue="0" Comment="Summertime: &#13;&#10;0..Off; &#13;&#10;1..Europe&#13;&#10;2..Mexico&#13;&#10;3..USA"/>
		<Client Name="SummerTime" Required="true" Internal="true"/>
		<Client Name="System" Required="false" Internal="false"/>
	</Channels>
	<Dependencies>
		<Files>
			<File Path=".\Class\_SysDateTime\_SysDateTime.h" Include="true"/>
		</Files>
	</Dependencies>
	<RevDoku>
		<Owner Company="sigmatek" Author="kolott"/>
		<Dokumentation Revision="0.10" Date="2022-03-24" Author="kolott" Company="sigmatek" Description="Betterment at DoSummerTime in method Background()"/>
		<Dokumentation Revision="0.10" Date="2021-11-19" Author="kolott" Company="sigmatek" Description="8D-3850: Possibly problem with automatic winter time shift fixed"/>
		<Dokumentation Revision="0.9" Date="2019-03-20" Author="kolott" Company="sigmatek" Description="SA43714: New virtual Method SummerTimeRise() added to get informed when changeover between Summertime and Wintertime"/>
		<Dokumentation Revision="0.8" Date="2019-01-24" Author="kolott" Company="sigmatek" Description="SA42889: Correction: Automatic switch from summer time to winter time did not work properly in version 0.7"/>
		<Dokumentation Revision="0.7" Date="2017-08-09" Author="kolott" Company="sigmatek" Description="SA36711: Support of RC001 module&#13;&#10;SA38243: Change in USA-Summertime"/>
		<Dokumentation Revision="0.6" Date="2016-07-07" Author="HubChr" Company="sigmatek" Description="SA34075: Changed datatypes of servers SysDate and SysTime to achieve easier handling in Lasal Screen Editor."/>
		<Dokumentation Revision="0.5" Date="2011-09-28" Author="kolott" Company="sigmatek" Description="betterment datatypeconversion"/>
	</RevDoku>
	<Network Name="_SysDateTime">
		<!-- List of Components in this network -->
		<Components>
			<Object
				Name       = "SummerTime"
				GUID       = "{8D5F918A-029E-4326-8E46-99E55244583F}"
				Class      = "Ram"
				Position   = "(270,150)"
				Visualized = "false">
				<Channels>
					<Server Name="Data"/>
				</Channels>
			</Object>
		</Components>
		<Comments>
		</Comments>
		<!-- List of Connections in this network -->
		<Connections>
			<Connection Source="this.SummerTime" Destination="SummerTime.Data"/>
		</Connections>
		<!-- Headerfiles -->
		<Options>
		</Options>
	</Network>
</Class>
*)
_SysDateTime : CLASS
  //Servers:
	SysDate 	: SvrChCmd_DATE_LSL;
	SysTime 	: SvrCh_TIME_LSL;
	DayOfWeek 	: SvrCh_DINT;
  //Clients:
	SummerTime 	: CltChCmd_Ram;
	System 	: CltChCmd_System;
	DoSummerTime 	: CltCh_DINT;
  //Variables:
		OldHour 	: UDINT;
  //Functions:
	
	FUNCTION VIRTUAL GLOBAL Init;
	
	FUNCTION VIRTUAL GLOBAL Background
		VAR_INPUT
			EAX 	: UDINT;
		END_VAR
		VAR_OUTPUT
			state (EAX) 	: UDINT;
		END_VAR;
	
	FUNCTION GetDayOfWeek
		VAR_INPUT
			day 	: UINT;
			month 	: UINT;
			year 	: UINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: UINT;
		END_VAR;
	
	FUNCTION GetDayOfMonth
		VAR_INPUT
			month 	: UINT;
			year 	: UINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: UINT;
		END_VAR;
	
	FUNCTION DateSet
		VAR_INPUT
			dte 	: HDINT;
		END_VAR;
	
	FUNCTION TimeSet
		VAR_INPUT
			tme 	: HDINT;
		END_VAR;
	
	FUNCTION DoSetNeeds;
	
	FUNCTION Emboly
		VAR_INPUT
			year 	: UINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION GLOBAL SummerWinterTime
		VAR_INPUT
			xdate 	: HDINT;
			xtime 	: HDINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: HDINT;
		END_VAR;
	
	FUNCTION IncDecDate
		VAR_INPUT
			pdte 	: ^UDINT;
			day 	: DINT;
		END_VAR;
	
	FUNCTION CheckSummerTime
		VAR_INPUT
			dte 	: HDINT;
			tme 	: HDINT;
		END_VAR;
	
	FUNCTION GLOBAL SetDatePart
		VAR_INPUT
			part 	: UINT;
			value 	: UINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION GLOBAL SetTimePart
		VAR_INPUT
			part 	: UINT;
			value 	: UINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION CheckAndCorrectSummerWinterTime
		VAR_INPUT
			dte_pattern 	: HDINT;
			tim_pattern 	: HDINT;
		END_VAR
		VAR_OUTPUT
			retcode 	: BOOL;
		END_VAR;
	
	FUNCTION TimeGet
		VAR_OUTPUT
			retcode 	: HDINT;
		END_VAR;
	
	FUNCTION DateGet
		VAR_OUTPUT
			retcode 	: HDINT;
		END_VAR;
				//! <Function Comment="Method informs when switching between summer and winter time and vice versa.&#13;&#10;Parameter &apos;edge&apos; indicates which of the two switches is currently in progress.&#13;&#10;edge = true .... WinterTime to SummerTime&#13;&#10;edge = false .... SummerTime to WinterTime" Name="SummerTimeRise"/>
	FUNCTION VIRTUAL SummerTimeRise
		VAR_INPUT
			edge 	: BOOL;			//! <Variable Comment="Parameter &apos;edge&apos; indicates which of the two switches is currently in progress.&#13;&#10;edge = true .... WinterTime to SummerTime&#13;&#10;edge = false .... SummerTime to WinterTime" Name="SummerTimeRise.edge"/>
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL SysDate::Write
		VAR_INPUT
			input (EAX) 	: DATE_LSL;
		END_VAR
		VAR_OUTPUT
			result (EAX) 	: DATE_LSL;
		END_VAR;
	
	FUNCTION VIRTUAL GLOBAL SysTime::Write
		VAR_INPUT
			input (EAX) 	: TIME_LSL;
		END_VAR
		VAR_OUTPUT
			result (EAX) 	: TIME_LSL;
		END_VAR;
  //Tables:
	FUNCTION @STD
		VAR_OUTPUT
			ret_code	: CONFSTATES;
		END_VAR;
	FUNCTION GLOBAL TAB @CT_;
END_CLASS;

#pragma using Ram
#pragma usingLtd System


//}}LSL_DECLARATION


FUNCTION GLOBAL TAB _SysDateTime::@CT_
0$UINT,
2#0100000000000000$UINT, //TY__SYSDATETIME
0$UINT, 10$UINT, (SIZEOF(::_SysDateTime))$UINT, 
3$UINT, 3$UINT, 0$UINT, 
TO_UDINT(3931827689), "_SysDateTime", //Class
TO_UDINT(0), 0, 0$UINT, 0$UINT, //Baseclass
//Servers:
(::_SysDateTime.SysDate.pMeth)$UINT, _CH_CMD$UINT, 2#0000000000000000$UINT, TO_UDINT(1714210210), "SysDate", 
(::_SysDateTime.SysTime.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(2737203869), "SysTime", 
(::_SysDateTime.DayOfWeek.pMeth)$UINT, _CH_SVR$UINT, 2#0000000000000000$UINT, TO_UDINT(1396401802), "DayOfWeek", 
//Clients:
(::_SysDateTime.SummerTime.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000010$UINT, TO_UDINT(2066431768), "SummerTime", TO_UDINT(1903583397), "Ram", 1$UINT, 3$UINT, 
(::_SysDateTime.System.pCh)$UINT, _CH_CLT_OBJ$UINT, 2#0000000000000000$UINT, TO_UDINT(968218125), "System", TO_UDINT(968218125), "System", 0$UINT, 1$UINT, 
(::_SysDateTime.DoSummerTime.pCh)$UINT, _CH_CLT_DATA$UINT, 2#0000000000000010$UINT, TO_UDINT(2510418087), "DoSummerTime", 
END_FUNCTION


#define USER_CNT__SysDateTime 2

TYPE
	_LSL_STD_VMETH	: STRUCT
			CmdTable	: CMDMETH;
			UserFcts	: ARRAY[0..USER_CNT__SysDateTime] OF ^Void;
	END_STRUCT;
END_TYPE

FUNCTION _SysDateTime::@STD
	VAR_OUTPUT
		ret_code	: CONFSTATES;
	END_VAR
	VAR
		vmt	: _LSL_STD_VMETH;
	END_VAR

	//Command Methods
	InitCmdTable (nCmd := nSTDCMD + USER_CNT__SysDateTime, pCmd := #vmt.CmdTable);
	vmt.CmdTable.Write		:= #Write();
	vmt.CmdTable.Init		:= #Init();
#pragma warning (disable : 74)
	vmt.UserFcts[0]		:= #Background();

#pragma warning (default : 74)
#pragma warning (disable : 74)
	vmt.UserFcts[1]		:= #SummerTimeRise();

#pragma warning (default : 74)
	SysDate.pMeth		:= StoreCmd (pCmd := #vmt.CmdTable, SHARED);

	IF SysDate.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;
	SysTime.pMeth			:= StoreMethod( #M_RD_DIRECT(), #SysTime::Write() );
	IF SysTime.pMeth THEN
		ret_code	:= C_OK;
	ELSE
		ret_code	:= C_OUTOF_NEAR;
		RETURN;
	END_IF;

END_FUNCTION

//{{LSL_IMPLEMENTATION

#define IS_CLOCK
#define SUMTIM_FALSE 16#7FACEDB0
#define SUMTIM_TRUE  16#0BDECAF7

FUNCTION VIRTUAL GLOBAL _SysDateTime::Init
 #ifdef IS_CLOCK
  var
    dte : SYSDATE;
    tmp : uint; 
  end_var

  if(_firstscan) then
    OldHour := 16#FFFF;
    
    System.GetSysDate(#dte);
    tmp := GetDayOfWeek(dte.wDay, dte.wMonth, dte.wYear); 
    if(tmp <> dte.wDayOfWeek) then // correct day of week
      dte.wDayOfWeek := tmp;
      System.SetSysDate(#dte);
    end_if;
    
    Background(0);
    
  end_if; 
 #endif
 
END_FUNCTION

FUNCTION GLOBAL _SysDateTime::SummerWinterTime
	VAR_INPUT
		xdate 	: HDINT;
		xtime 	: HDINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: HDINT;
	END_VAR
  VAR
    dow : uint;
    day, year : uint;
    bdate, edate : hdint;
    tim0, tim1 : hdint;
  END_VAR
  
  retcode := SUMTIM_FALSE;  // wintertime
  tim0    := 16#FFFFFFFF;
  tim1    := 16#FFFFFFFF;
  year    := to_uint((xdate shr 16) and 16#0000FFFF);
  
  case DoSummerTime of 
    1 : // EUROPE ****************************
      // last sunday in march      02:00 --> 03:00
      // last sunday in october    03:00 --> 02:00
      day := 25; 
      dow := GetDayOfWeek(day, 3, year);
      if(dow > 0) then 
        day := 32 - dow;
      end_if;
      bdate := ((xdate and 16#FFFF0000) or 16#3000) or (day shl 4);

      day := 25; // 
      dow := GetDayOfWeek(day, 10, year);
      if(dow > 0) then 
        day := 32 - dow;
      end_if;
      edate := ((xdate and 16#FFFF0000) or 16#A000) or (day shl 4);
    
      tim0 := 16#02000000;
      tim1 := 16#03000000;
    
    3 : // USA *******************************
      // second sunday in march    02:00 --> 03:00
      // first sunday in november  02:00 --> 01:00
      day := 8;
      dow := GetDayOfWeek(day, 3, year);
      if(dow > 0) then
        day := 15 - dow;
      end_if;
      bdate := ((xdate and 16#FFFF0000) or 16#3000) or (day shl 4);
      
      day := 1;
      dow := GetDayOfWeek(day, 11, year);
      if(dow > 0) then
        day := 8 - dow;
      end_if;
      edate := ((xdate and 16#FFFF0000) or 16#B000) or (day shl 4);

      tim0 := 16#02000000;
      tim1 := 16#02000000;
    
    2 : // MEXICO ****************************
      // first sunday in april     02:00 --> 03:00
      // last sunday in october    02:00 --> 01:00
      day := 1;
      dow := GetDayOfWeek(day, 4, year);
      if(dow > 0) then
        day := 8 - dow;
      end_if;
      bdate := ((xdate and 16#FFFF0000) or 16#4000) or (day shl 4);
    
      day := 25;
      dow := GetDayOfWeek(day, 10, year);
      if(dow > 0) then 
        day := 32 - dow;
      end_if;
      edate := ((xdate and 16#FFFF0000) or 16#A000) or (day shl 4);

      tim0 := 16#02000000;
      tim1 := 16#02000000;
    
  end_case;
  
  if(tim0 <> 16#FFFFFFFF) then
    if((xdate = bdate) & (xtime >= tim0)) then
      retcode := SUMTIM_TRUE;
    elsif(xdate > bdate) then
      retcode := SUMTIM_TRUE;
    end_if;
    
    if((xdate = edate) & (xtime >= tim1)) then
      retcode := SUMTIM_FALSE;
    elsif(xdate > edate) then
      retcode := SUMTIM_FALSE;
    end_if;
  end_if;
  
END_FUNCTION

FUNCTION _SysDateTime::CheckAndCorrectSummerWinterTime
	VAR_INPUT
		dte_pattern 	: HDINT;
		tim_pattern 	: HDINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR
  var
    tmp, val : hdint;
  end_var

  retcode := false;

  tmp := dte_pattern and 16#FFFFFFF0;
  if((tmp <> 0) & (tmp <> 16#07B21010)) then // invalid date and 01.01.1970
    retcode  := true; 
    val$dint := SummerTime.Read();
    if((val <> SUMTIM_TRUE) & (val <> SUMTIM_FALSE)) then
      val := SummerWinterTime(dte_pattern, tim_pattern);
      SummerTime.Write(val$dint);
    else
      CheckSummerTime(dte_pattern, tim_pattern);
    end_if;
  end_if;
  
END_FUNCTION

FUNCTION _SysDateTime::TimeGet
	VAR_OUTPUT
		retcode 	: HDINT;
	END_VAR
 #ifdef IS_CLOCK
  VAR
    tme : SYSTIME;  
  END_VAR

  System.GetSysTime(#tme); 
  retcode := tme.wHour and 16#FF; 
  retcode := (retcode shl 8) or (tme.wMinute and 16#FF); 
  retcode := (retcode shl 8) or (tme.wSecond and 16#FF);
  retcode := (retcode shl 8); 
 #else
  VAR
    tmp, th, tm, ts  : udint;
  END_VAR
  
  tmp := ops.tabsolute / 1000;
  ts  := tmp mod 60; tmp := tmp / 60;
  tm  := tmp mod 60; tmp := tmp / 60;
  th  := tmp mod 24;

  retcode := th; 
  retcode := (retcode shl 8) or (tm); 
  retcode := (retcode shl 8) or (ts);
  retcode := (retcode shl 8);   
 #endif
 
END_FUNCTION

FUNCTION _SysDateTime::DateGet
	VAR_OUTPUT
		retcode 	: HDINT;
	END_VAR
 #ifdef IS_CLOCK
  VAR
    dte : SYSDATE;
  END_VAR

  System.GetSysDate(#dte);

  retcode   := dte.wYear; 
  retcode   := (retcode shl 4) or dte.wMonth; 
  retcode   := (retcode shl 8) or dte.wDay;
  retcode   := (retcode shl 4) or dte.wDayOfWeek; 
  DayOfWeek := dte.wDayOfWeek;
 #else
  retcode   := 16#07B21010; // 01.01.1970
  DayOfWeek := 4; // thursday
 #endif
END_FUNCTION

FUNCTION _SysDateTime::TimeSet
	VAR_INPUT
		tme 	: HDINT;
	END_VAR
 #ifdef IS_CLOCK
  VAR
    t : SYSTIME;
  END_VAR

  t.wHour   := TO_USINT((TO_UDINT(tme) shr 24) and 16#00FF);
  t.wMinute := TO_USINT((TO_UDINT(tme) shr 16) and 16#00FF);
  t.wSecond := TO_USINT((TO_UDINT(tme) shr  8) and 16#00FF); 
  System.SetSysTime(#t); 
 #endif

END_FUNCTION

FUNCTION _SysDateTime::DateSet
	VAR_INPUT
		dte 	: HDINT;
	END_VAR
 #ifdef IS_CLOCK
  VAR
    t : SYSDATE; 
  END_VAR
  
  t.wDay       := TO_USINT((TO_UDINT(dte) shr  4) and 16#00FF);
  t.wMonth     := TO_USINT((TO_UDINT(dte) shr 12) and 16#000F); 
  t.wYear      := TO_UINT((TO_UDINT(dte)  shr 16) and 16#FFFF);  
  t.wDayOfWeek := (TO_USINT(dte) and 16#0F) mod 7;
  t.wDayOfWeek := GetDayOfWeek(t.wDay, t.wMonth, t.wYear); 
  System.SetSysDate(#t);
 #endif

END_FUNCTION

FUNCTION _SysDateTime::DoSetNeeds
  VAR
  	tmp : hdint;
  END_VAR

  if(DoSummerTime) then
    tmp := SummerWinterTime(SysDate, SysTime);
    SummerTime.Write(tmp$dint);
  end_if;

END_FUNCTION

FUNCTION VIRTUAL GLOBAL _SysDateTime::SysDate::Write
	VAR_INPUT
		input (EAX) 	: DATE_LSL;
	END_VAR
	VAR_OUTPUT
		result (EAX) 	: DATE_LSL;
	END_VAR
  
  result := 0;
  
 #ifdef IS_CLOCK
  if(input$dint <> -1) then
    DateSet(input$udint);
    SysDate := DateGet();
    DoSetNeeds();
  else
    result := ACCESS_DENIED;
  end_if;
 #endif
  
END_FUNCTION

FUNCTION VIRTUAL GLOBAL _SysDateTime::SysTime::Write
	VAR_INPUT
		input (EAX) 	: TIME_LSL;
	END_VAR
	VAR_OUTPUT
		result (EAX) 	: TIME_LSL;
	END_VAR
  
  result := 0;
  
 #ifdef IS_CLOCK
  if(input$dint <> -1) then
    TimeSet(input$udint);
    SysTime := TimeGet();
    DoSetNeeds();
  else
    result := ACCESS_DENIED;
  end_if;
 #endif

END_FUNCTION

FUNCTION _SysDateTime::GetDayOfWeek
	VAR_INPUT
		day 	: UINT;
		month 	: UINT;
		year 	: UINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: UINT;
	END_VAR
  VAR
    days : udint; 
    maxs : uint; 
  END_VAR

  year  -= 1;
  maxs  := year / 4;
  maxs  -= year / 100;
  maxs  += year / 400;
  days  := ((TO_UDINT(year)) * 365) + maxs;

  while(month > 1) do
	  month -= 1;
    days  += GetDayOfMonth(month, year+1);
  end_while;
  
  days    += day;
  retcode := TO_UINT(days mod 7);

END_FUNCTION

FUNCTION _SysDateTime::GetDayOfMonth
	VAR_INPUT
		month 	: UINT;
		year 	: UINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: UINT;
	END_VAR

  retcode := 30;
  case month of
    1,3,5,7,8,10,12: retcode := 31;
                  2: retcode := 28;
                     if(Emboly(year) = true) then
                       retcode := 29;
                     end_if;
  end_case;

END_FUNCTION

FUNCTION _SysDateTime::Emboly
	VAR_INPUT
		year 	: UINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR
  
  retcode := false;

  if((year mod 4) = 0) then
    retcode := true; 
    if((year mod 100) = 0) then
      retcode := false; 
      if((year mod 400) = 0) then
        retcode := true; 
      end_if; 
    end_if; 
  end_if; 

END_FUNCTION

FUNCTION _SysDateTime::CheckSummerTime
	VAR_INPUT
		dte 	: HDINT;
		tme 	: HDINT;
	END_VAR
  VAR
    val : hdint;
    mon : udint;
  END_VAR

  val := SummerWinterTime(dte, tme);
  if(val$dint <> SummerTime.Read()) then
    mon := ((dte shr 12) and 16#0F);
    if(val = SUMTIM_TRUE) then
      if(mon < 5) then
        // turn to summertime
       if((tme and 16#FF000000) < 16#17000000) then
           tme += 16#01000000;
        else
          tme := tme and 16#00FFFFFF;
          IncDecDate(#dte, 1);
          DateSet(dte);
        end_if;
        TimeSet(tme);
        SummerTime.Write(SUMTIM_TRUE);
        SummerTimeRise(true);
      end_if;
    else
      // turn to wintertime
      if(mon > 7) then
        if((tme and 16#FF000000) >= 16#01000000) then
          tme -= 16#01000000;
        else
          tme := (tme and 16#00FFFFFF) or 16#17000000;
          IncDecDate(#dte, -1);
          DateSet(dte);
        end_if;
        TimeSet(tme);
        SummerTime.Write(SUMTIM_FALSE);
        SummerTimeRise(false);
      end_if;
    end_if;
  end_if;

END_FUNCTION

FUNCTION _SysDateTime::IncDecDate
	VAR_INPUT
		pdte 	: ^UDINT;
		day 	: DINT;
	END_VAR
  VAR
    t : SYSDATE;
    dte : udint;
    no : uint;
  END_VAR
  
  dte := pdte^;
  
  t.wDay   := TO_USINT((TO_UDINT(dte) shr  4) and 16#00FF);
  t.wMonth := TO_USINT((TO_UDINT(dte) shr 12) and 16#000F); 
  t.wYear  := TO_UINT((TO_UDINT(dte)  shr 16) and 16#FFFF);  

  if(day > 0) then
    no := GetDayOfMonth(t.wMonth, t.wYear);
    if(t.wDay >= no) then
      t.wDay   := 1;
      t.wMonth += 1;
      if(t.wMonth > 12) then
        t.wMonth := 1;
        t.wYear += 1;
      end_if;
    else
      t.wDay += 1;
    end_if;
  elsif(day < 0) then
    if(t.wDay <= 1) then
      t.wMonth -= 1;
      if(t.wMonth = 0) then
        t.wMonth := 12;
        t.wYear  -= 1;
      end_if;
      t.wDay   := GetDayOfMonth(t.wMonth, t.wYear);
    else
      t.wDay -= 1;
    end_if;
  end_if;
  
  dte := t.wYear;
  dte := (dte shl 4) or t.wMonth; 
  dte := (dte shl 8) or t.wDay;
  dte := (dte shl 4) or GetDayOfWeek(t.wDay, t.wMonth, t.wYear); 
  
  pdte^ := dte;

END_FUNCTION

FUNCTION VIRTUAL GLOBAL _SysDateTime::Background
	VAR_INPUT
		EAX 	: UDINT;
	END_VAR
	VAR_OUTPUT
		state (EAX) 	: UDINT;
	END_VAR
  VAR
  	hh : hdint;
  END_VAR

  // YYYYYYYYYYYYYYYYMMMMDDDDDDDDWWWW
  // HHHHHHHHNNNNNNNNSSSSSSSSxxxxxxxx
  
  // y .... year
  // m .... month
  // d .... day
  // w .... day of week
  // h .... hour
  // n .... minutes
  // s .... second
  // x .... initialized with 0

	state   := READY;

  SysTime      := TimeGet();
  SysDate      := DateGet();
  DoSummerTime := DoSummerTime.Read();
  
  if(DoSummerTime <> 0) then
    hh := (SysTime shr 24) and 16#FF;
    if(hh <> OldHour) then
      if(CheckAndCorrectSummerWinterTime(SysDate, SysTime) = true) then
        OldHour := hh;
      end_if;
    end_if;
  end_if;

END_FUNCTION

FUNCTION GLOBAL _SysDateTime::SetDatePart
	VAR_INPUT
		part 	: UINT;
		value 	: UINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR
  VAR
    dte : SYSDATE;
    pattern : hdint;
  END_VAR

  retcode := false;
  System.GetSysDate(#dte);
  
  if(part = 0) then
    dte.wYear := value;
  elsif(part = 1) then
    dte.wMonth := value;
  elsif(part = 2) then
    dte.wDay := value;
  end_if;
  
  if((dte.wYear >= 1990) & (dte.wYear <= 2100)) then
    if((dte.wMonth > 0) & (dte.wMonth < 13)) then
      if((dte.wDay > 0)&(dte.wDay <= GetDayOfMonth(dte.wMonth, dte.wYear))) then
        
        pattern := dte.wYear;
        pattern := (pattern shl 4) or dte.wMonth;
        pattern := (pattern shl 8) or dte.wDay;
        pattern := (pattern shl 4);
        
        SysDate.Write(pattern);
        
        retcode := true;
      end_if;
    end_if;
  end_if;
  
END_FUNCTION

FUNCTION GLOBAL _SysDateTime::SetTimePart
	VAR_INPUT
		part 	: UINT;
		value 	: UINT;
	END_VAR
	VAR_OUTPUT
		retcode 	: BOOL;
	END_VAR
  VAR
    tme : SYSTIME;
    pattern : hdint;
  END_VAR

  retcode := false;
  System.GetSysTime(#tme);

  if(part = 0) then
    tme.wHour := value;
  elsif(part = 1) then
    tme.wMinute := value;
  elsif(part = 2) then
    tme.wSecond := value;
  end_if;
  
  if((tme.wHour >= 0) & (tme.wHour <= 23)) then
    if((tme.wMinute >= 0) & (tme.wMinute <= 59)) then
      if((tme.wSecond >= 0) & (tme.wSecond <= 59)) then
    
        pattern := tme.wHour;
        pattern := (pattern shl 8) or tme.wMinute;
        pattern := (pattern shl 8) or tme.wSecond;
        pattern := (pattern shl 8);
        
        SysTime.Write(pattern);
    
        retcode := true;
      end_if;
    end_if;
  end_if;
  
END_FUNCTION

#pragma warning (disable : 73)
FUNCTION VIRTUAL _SysDateTime::SummerTimeRise
	VAR_INPUT
		edge 	: BOOL;
	END_VAR

END_FUNCTION
#pragma warning (default : 73)
