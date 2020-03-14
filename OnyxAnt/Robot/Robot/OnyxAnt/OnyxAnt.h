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
	//! Setup Parameters. To be load from IniFile and Recipe
	class SETUP_DATA
	{
	public:
		SETUP_DATA()
		{
			Reset();
		}
		void	Reset()
		{

		}

	};

	//! Life Params. Reset on Construction
	class LIFE_PARAMS
	{
	public:
		LIFE_PARAMS()
		{
			Reset();
		}
		void Reset()
		{
			m_lTestVar = 0;
		}

		uint8_t	m_lTestVar;
	};

	//! Work Params. Reset on Init
	class WORK_PARAMS
	{
	public:
		WORK_PARAMS()
		{
			Reset();
		}
		void Reset()
		{

		}

	};


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

	void				RegisterSPIVars();

////////////////////////////////////////////
// attributes
////////////////////////////////////////////
protected:
	KinematicsModule*	m_pKinematicsModule;
	SensoricsModule*	m_pSensoricsModule;
	OnyxSPI				m_oSPIInterface;

	SETUP_DATA*			m_oSetupData;
	LIFE_PARAMS*		m_oLifeParams;
	WORK_PARAMS*		m_oWorkParams;


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