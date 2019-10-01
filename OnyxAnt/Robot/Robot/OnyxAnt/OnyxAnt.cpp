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

	Init();
}

OnyxAnt::~OnyxAnt()
{
}

void OnyxAnt::Init()
{
	m_eStatus = STATUS_IDLE;
}

ROBOTSTATUS OnyxAnt::Start()
{
	std::cout << "Hello, I'm the OnyxAnt! :)\n";

	return m_eStatus;
}
