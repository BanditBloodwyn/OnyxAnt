//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		OnyxAnt.h
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <Base/RobotBase.h>
#include <Leg/OnyxLeg/OnyxLeg.h>
#include <Connection/SPI/OnyxSPI.h>


class OnyxAnt : public RobotBase
{
////////////////////////////////////////////
// structures
////////////////////////////////////////////
public:


////////////////////////////////////////////
// construction
////////////////////////////////////////////
public:
	OnyxAnt();
	~OnyxAnt();


////////////////////////////////////////////
// methods
////////////////////////////////////////////
public:
	STMRESULT			ExecStart();
	STMRESULT			ExecCycle();
	STMRESULT			ExecInit();
	STMRESULT			ExecShutdown();

private:
	STMRESULT			ExecMoveLegsToSleepPosition();

////////////////////////////////////////////
// attributes
////////////////////////////////////////////
protected:
	OnyxLeg*			m_oLegFL;
	OnyxLeg*			m_oLegFR;
	OnyxLeg*			m_oLegML;
	OnyxLeg*			m_oLegMR;
	OnyxLeg*			m_oLegBL;
	OnyxLeg*			m_oLegBR;

	OnyxSPI				m_oSPIInterface;

////////////////////////////////////////////
// STM
////////////////////////////////////////////
protected:
	STM_DECLARE(ExecCycle);
	STM_DECLARE(ExecShutdown);
	STM_DECLARE(ExecMoveLegsToSleepPosition);
};