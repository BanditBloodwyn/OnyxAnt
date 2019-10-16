#include "OnyxAnt.h"


OnyxAnt::OnyxAnt()
{
	std::cout << "Booting......\n";

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

	if (!ExecInit())
	{
		return S_ERROR;
	}

	std::cout << "Hello, I'm the OnyxAnt! :)\n";

	while (ExecCycle() != S_ERROR || ExecCycle() != S_READY)
	{
	}

	ExecShutdown();

	return S_READY;
}

STMRESULT OnyxAnt::ExecCycle()
{
	m_eStatus = STATUS_IDLE;

	return S_BUSY;
}

STMRESULT OnyxAnt::ExecShutdown()
{
	return ExecMoveLegsToSleepPosition();
}

STMRESULT OnyxAnt::ExecMoveLegsToSleepPosition()
{
	return S_READY;
}
