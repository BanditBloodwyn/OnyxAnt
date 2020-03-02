//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		RobotBase.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "RobotBase.h"


RobotBase::RobotBase()
{
}

RobotBase::~RobotBase()
{
}

STMRESULT RobotBase::ExecStart()
{
	return S_READY;
}

STMRESULT RobotBase::ExecCycle()
{
	m_eStatus = ROBOTSTATUS_RUNNING;
	return S_READY;
}

STMRESULT RobotBase::ExecInit()
{
	m_eStatus = ROBOTSTATUS_INITIALIZE;
	return S_READY;
}

STMRESULT RobotBase::ExecShutdown()
{
	m_eStatus = ROBOTSTATUS_SHUTDOWN;
	return S_READY;
}

Stm* RobotBase::CreateStm(const string& sStmName)
{
	assert(m_oStmMap.find(sStmName) == m_oStmMap.end());

	Stm* pStm = new Stm(sStmName);
	m_oStmMap[sStmName] = pStm;

	return pStm;
}

Stm* RobotBase::FindStm(const string& sStmName)
{
	auto it = m_oStmMap.find(sStmName);

	if (it == m_oStmMap.end())
		return nullptr;

	return it->second;
}
