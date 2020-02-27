//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		KinematicsModule.cpp
// Project:		OnyxAnt
// Purpose:		
//
// Created:		27.02.2020
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "KinematicsModule.h"


KinematicsModule::KinematicsModule()
{
}

KinematicsModule::KinematicsModule(string sName) : ModuleBase(sName)
{
	m_oLegFL = new OnyxLeg("LegFrontLeft");
	m_oLegFR = new OnyxLeg("LegFrontRight");
	m_oLegML = new OnyxLeg("LegMiddleLeft");
	m_oLegMR = new OnyxLeg("LegMiddleRight");
	m_oLegBL = new OnyxLeg("LegBackLeft");
	m_oLegBR = new OnyxLeg("LegBackRight");
}

KinematicsModule::~KinematicsModule()
{
}
