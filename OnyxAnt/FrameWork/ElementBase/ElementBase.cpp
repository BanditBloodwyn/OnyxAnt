//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		ElementBase.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		27.02.2020
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "ElementBase.h"


ElementBase::ElementBase()
{

}

ElementBase::ElementBase(string sName)
{
	m_sName = sName;
	m_bIsInitialized = false;
}

ElementBase::~ElementBase()
{

}

void ElementBase::Control()
{

}

STMRESULT ElementBase::ExecCycle()
{
	m_eStatus = ELEMENTSTATUS_RUNNING;
	return S_READY;
}

STMRESULT ElementBase::ExecInit()
{
	m_eStatus = ELEMENTSTATUS_INITIALIZE;
	return S_READY;
}

STMRESULT ElementBase::ExecShutdown()
{
	m_eStatus = ELEMENTSTATUS_SHUTDOWN;
	return S_READY;
}

Stm* ElementBase::CreateStm(const string& sStmName)
{
	assert(m_oStmMap.find(sStmName) == m_oStmMap.end());

	Stm* pStm = new Stm(sStmName);
	m_oStmMap[sStmName] = pStm;

	return pStm;
}

Stm* ElementBase::FindStm(const string& sStmName)
{
	auto it = m_oStmMap.find(sStmName);

	if (it == m_oStmMap.end())
		return nullptr;

	return it->second;
}
