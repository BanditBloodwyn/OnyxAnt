//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		RobotBase.h
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <iostream>
#include <map>
#include <cassert>

#include <Connection/SPI/SPIBase.h>
#include <STM/STM.h>


#define STM_DECLARE(p)		Stm* m_pStm_##p
#define STM_CREATE(p)		m_pStm_##p = CreateStm(#p)
#define STM(p)				FindStm(#p)


enum ROBOTTYPE
{
	  TYPE_DIFFERENTIAL
	, TYPE_ACKERMANN
	, TYPE_2_LEGS
	, TYPE_4_LEGS
	, TYPE_6_LEGS
};

enum ROBOTSTATUS
{
	  STATUS_SLEEPING
	, STATUS_BOOTING
	, STATUS_IDLE
	, STATUS_ERROR
	, STATUS_SHUTDOWN
};

class RobotBase
{
////////////////////////////////////////////
// structures
////////////////////////////////////////////
public:


////////////////////////////////////////////
// construction
////////////////////////////////////////////
public:
	RobotBase();
	~RobotBase();


////////////////////////////////////////////
// methods
////////////////////////////////////////////
public:
	virtual STMRESULT			ExecStart() = 0;
	virtual STMRESULT			ExecCycle() = 0;
	virtual STMRESULT			ExecInit() = 0;
	virtual STMRESULT			ExecShutdown() = 0;

////////////////////////////////////////////
// attributes
////////////////////////////////////////////
protected:
	ROBOTTYPE			m_eRobotType;
	ROBOTSTATUS			m_eStatus;

////////////////////////////////////////////
// STM
////////////////////////////////////////////
public:
	Stm*				CreateStm(const string& sStmName);
	Stm*				FindStm(const string& sStmName);

protected:
	map<string, Stm*>	m_oStmMap;
};