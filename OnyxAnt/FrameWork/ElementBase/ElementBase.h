//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		ElementBase.h
// Project:		OnyxAnt
// Purpose:		
//
// Created:		27.02.2020
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <iostream>
#include <map>
#include <cassert>

#include <STM/STM.h>


enum ELEMENTSTATUS
{
	ELEMENTSTATUS_INITIALIZE,
	ELEMENTSTATUS_IDLE,
	ELEMENTSTATUS_RUNNING,
	ELEMENTSTATUS_ERROR,
	ELEMENTSTATUS_SHUTDOWN,
};


class ElementBase
{
////////////////////////////////////////////
// structures
////////////////////////////////////////////
public:


////////////////////////////////////////////
// construction
////////////////////////////////////////////
public:
	ElementBase();
	ElementBase(string sName);
	~ElementBase();


////////////////////////////////////////////
// methods
////////////////////////////////////////////
public:
	virtual void			Control();

	virtual STMRESULT		ExecCycle();
	virtual STMRESULT		ExecInit();
	virtual STMRESULT		ExecShutdown();

	virtual bool			IsInitialized()			{ return m_bIsInitialized; }
	bool					IsInitializing()		{ return m_eStatus == ELEMENTSTATUS_INITIALIZE; }
	bool					IsIdle()				{ return m_eStatus == ELEMENTSTATUS_IDLE; }
	bool					IsRunning()				{ return m_eStatus == ELEMENTSTATUS_RUNNING; }
	bool					HasError()				{ return m_eStatus == ELEMENTSTATUS_ERROR; }
	bool					IsShuttingDown()		{ return m_eStatus == ELEMENTSTATUS_SHUTDOWN; }


////////////////////////////////////////////
// STM
////////////////////////////////////////////
public:
	Stm*				CreateStm(const string& sStmName);
	Stm*				FindStm(const string& sStmName);

protected:
	map<string, Stm*>	m_oStmMap;


////////////////////////////////////////////
// attributes
////////////////////////////////////////////
private:
	string				m_sName;
	ELEMENTSTATUS		m_eStatus;
	bool				m_bIsInitialized;
};
