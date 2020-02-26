//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		OnyxAnt.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "OnyxAnt.h"


OnyxAnt::OnyxAnt()
{
	std::cout << "Booting......\n";

	STM_CREATE(ExecStart);
	STM_CREATE(ExecCycle);
	STM_CREATE(ExecShutdown);
	STM_CREATE(ExecMoveLegsToSleepPosition);


	m_eRobotType = TYPE_6_LEGS;
	m_eStatus = STATUS_BOOTING;

	m_oLegFL = new OnyxLeg("LegFrontLeft");
	m_oLegFR = new OnyxLeg("LegFrontRight");
	m_oLegML = new OnyxLeg("LegMiddleLeft");
	m_oLegMR = new OnyxLeg("LegMiddleRight");
	m_oLegBL = new OnyxLeg("LegBackLeft");
	m_oLegBR = new OnyxLeg("LegBackRight");
}

OnyxAnt::~OnyxAnt()
{
}

STMRESULT OnyxAnt::ExecInit()
{
	if (!m_oSPIInterface.spiInit())
	{
		std::cout << "OnyxAnt::Init failed!\n";
		return S_ERROR;
	}

	m_eStatus = STATUS_IDLE;

	return S_READY;
}

STMRESULT OnyxAnt::ExecStart()
{
	enum
	{
		sSTART = S_START,
		sINIT,
		sCYCLE,
		sSHUTDOWN,
		sEND,
		sERROR
	};

	STMRESULT nResult = S_BUSY;

	Stm* pStm = STM(ExecStart);

	switch (pStm->GetWorkState())
	{
	case sSTART:
	{
		std::cout << "Hello, I'm the OnyxAnt! :)\n";
		return pStm->ChangeWorkState(S_READY, sINIT);
	}
	case sINIT:
	{
		return pStm->ChangeWorkState(ExecInit(), sCYCLE);
	}
	case sCYCLE:
	{
		return pStm->ChangeWorkState(ExecCycle(), sSHUTDOWN);
	}
	case sSHUTDOWN:
	{
		return pStm->ChangeWorkState(ExecShutdown(), sEND);
	}
	case sEND:
	{
		return pStm->ChangeWorkState(S_READY);
	}
	case sERROR:
	{
		return pStm->ChangeWorkState(S_ERROR);
	}
	}

	return nResult;
}

STMRESULT OnyxAnt::ExecCycle()
{
	m_eStatus = STATUS_IDLE;

	int x;
	cin >> x;

	if (x == 0)
		return S_READY;

	return S_BUSY;
}

STMRESULT OnyxAnt::ExecShutdown()
{
	std::cout << "OnyxAnt::ExecShutdown started\n";
	return ExecMoveLegsToSleepPosition();
}

STMRESULT OnyxAnt::ExecMoveLegsToSleepPosition()
{
	return S_READY;
}
