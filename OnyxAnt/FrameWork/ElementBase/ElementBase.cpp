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
	m_sUnitName = sName;
}

ElementBase::~ElementBase()
{

}

void ElementBase::Control()
{

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
