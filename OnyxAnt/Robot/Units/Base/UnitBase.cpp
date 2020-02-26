//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		UnitBase.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		26.02.2020
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "UnitBase.h"


UnitBase::UnitBase()
{

}

UnitBase::UnitBase(string sName)
{
	m_sUnitName = sName;
}

UnitBase::~UnitBase()
{

}

void UnitBase::Control()
{

}

Stm* UnitBase::CreateStm(const string& sStmName)
{
	assert(m_oStmMap.find(sStmName) == m_oStmMap.end());

	Stm* pStm = new Stm(sStmName);
	m_oStmMap[sStmName] = pStm;

	return pStm;
}

Stm* UnitBase::FindStm(const string& sStmName)
{
	auto it = m_oStmMap.find(sStmName);

	if (it == m_oStmMap.end())
		return nullptr;

	return it->second;
}
