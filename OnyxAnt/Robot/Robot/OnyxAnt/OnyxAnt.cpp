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

	m_oLegFL = new OnyxLeg();
	m_oLegFR = new OnyxLeg();
	m_oLegML = new OnyxLeg();
	m_oLegML = new OnyxLeg();
	m_oLegBL = new OnyxLeg();
	m_oLegBL = new OnyxLeg();
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
		pStm->ChangeWorkState(S_READY, sINIT);
		break;
	}
	case sINIT:
	{
		pStm->ChangeWorkState(ExecInit(), sCYCLE);
		break;
	}
	case sCYCLE:
	{
		pStm->ChangeWorkState(ExecCycle(), sSHUTDOWN);
		break;
	}
	case sSHUTDOWN:
	{
		pStm->ChangeWorkState(ExecShutdown(), sSHUTDOWN);
		break;
	}
	case sEND:
	{

	}
	case sERROR:
	{

	}
	}

	return nResult;
}

STMRESULT OnyxAnt::ExecCycle()
{
	m_eStatus = STATUS_IDLE;

	//int x;
	//cin >> x;

	//if (x == 0)
	//	m_eStatus = STATUS_SHUTDOWN;

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
