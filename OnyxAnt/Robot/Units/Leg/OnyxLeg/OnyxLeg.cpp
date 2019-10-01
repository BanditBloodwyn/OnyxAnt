#include "OnyxLeg.h"


OnyxLeg::OnyxLeg()
{
	m_nJointCount = 4;
}

OnyxLeg::~OnyxLeg()
{
}

void OnyxLeg::MoveJoint(int nJointNumber, int nDegrees)
{
}

void OnyxLeg::MoveLegToCoordinates(int nX, int nY, int nZ)
{
}

int OnyxLeg::getJointAngle(int nJointNumber)
{
	return 0;
}

int OnyxLeg::getJointCurrent(int nJointNumber)
{
	return 0;
}

int OnyxLeg::getJointPulse(int nJointNumber)
{
	return 0;
}
