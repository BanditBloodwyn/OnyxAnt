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
	TYPE_DIFFERENTIAL,
	TYPE_ACKERMANN,
	TYPE_2_LEGS,
	TYPE_4_LEGS,
	TYPE_6_LEGS
};

enum ROBOTSTATUS
{
	ROBOTSTATUS_SLEEPING,
	ROBOTSTATUS_BOOTING,
	ROBOTSTATUS_INITIALIZE,
	ROBOTSTATUS_IDLE,
	ROBOTSTATUS_RUNNING,
	ROBOTSTATUS_ERROR,
	ROBOTSTATUS_SHUTDOWN
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
	virtual STMRESULT			ExecStart();
	virtual STMRESULT			ExecCycle();
	virtual STMRESULT			ExecInit();
	virtual STMRESULT			ExecShutdown();

	virtual bool				IsInitialized() { return m_bIsInitialized; }
	bool						IsInitializing() { return m_eStatus == ROBOTSTATUS_INITIALIZE; }
	bool						IsIdle() { return m_eStatus == ROBOTSTATUS_IDLE; }
	bool						IsRunning() { return m_eStatus == ROBOTSTATUS_RUNNING; }
	bool						HasError() { return m_eStatus == ROBOTSTATUS_ERROR; }
	bool						IsShuttingDown() { return m_eStatus == ROBOTSTATUS_SHUTDOWN; }


////////////////////////////////////////////
// attributes
////////////////////////////////////////////
protected:
	ROBOTTYPE			m_eRobotType;
	ROBOTSTATUS			m_eStatus;
	bool				m_bIsInitialized;


////////////////////////////////////////////
// STM
////////////////////////////////////////////
public:
	Stm*				CreateStm(const string& sStmName);
	Stm*				FindStm(const string& sStmName);

protected:
	map<string, Stm*>	m_oStmMap;
};