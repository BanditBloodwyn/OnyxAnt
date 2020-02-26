//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		OnyxLeg.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		01.10.2019
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "OnyxLeg.h"


OnyxLeg::OnyxLeg()
{

}

OnyxLeg::OnyxLeg(string sName) : LegBase(sName)
{
	m_nJointCount = 4;
}

OnyxLeg::~OnyxLeg()
{

}

void OnyxLeg::Control()
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
