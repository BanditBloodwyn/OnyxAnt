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
#include <KinematicsModule/KinematicsModule.h>
#include <SensoricsModule/SensoricsModule.h>
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

	STMRESULT			CollectSensorData();
	STMRESULT			ProcessSensorData();
	STMRESULT			SelfDiagnosis();
	STMRESULT			SendMoveCommands();


////////////////////////////////////////////
// attributes
////////////////////////////////////////////
protected:
	KinematicsModule*	m_pKinematicsModule;
	SensoricsModule*	m_pSensoricsModule;
	OnyxSPI				m_oSPIInterface;

////////////////////////////////////////////
// STM
////////////////////////////////////////////
protected:
	STM_DECLARE(ExecStart);
	STM_DECLARE(ExecInit);
	STM_DECLARE(ExecCycle);
	STM_DECLARE(ExecShutdown);
	STM_DECLARE(ExecMoveLegsToSleepPosition);
};