//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		SPIVar.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		21.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "SPIVar.h"
#include "SPIBase.h"



SPIVar::SPIVar(uint8_t rVar, string sName, SPIBase* oInterface)
{
	m_lVar = rVar;
	m_pParentInterface = oInterface;
}

SPIVar::~SPIVar()
{

}

bool SPIVar::Check()
{
	if (m_lVar != m_lOldValue)
	{
		cout << "Value changed to " << m_lVar;
		m_pParentInterface->spiTranceive(m_lVar);
	}

	return true;
}
