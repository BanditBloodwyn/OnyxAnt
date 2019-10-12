#include "OnyxAnt.h"


OnyxAnt::OnyxAnt()
{
	std::cout << "Booting......\n";

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

bool OnyxAnt::Init()
{
	if (!m_oSPIInterface.spiInit())
	{
		std::cout << "OnyxAnt::Init failed!\n";
		return false;
	}

	m_eStatus = STATUS_IDLE;

	return true;
}

void OnyxAnt::Start()
{
	if (!Init())
	{
		return;
	}

	std::cout << "Hello, I'm the OnyxAnt! :)\n";

	while (m_eStatus != STATUS_ERROR && m_eStatus != STATUS_SHUTDOWN)
	{
		Cycle();
	}

	Shutdown();
}

void OnyxAnt::Cycle()
{
	m_eStatus = STATUS_IDLE;
}

void OnyxAnt::Shutdown()
{

}
