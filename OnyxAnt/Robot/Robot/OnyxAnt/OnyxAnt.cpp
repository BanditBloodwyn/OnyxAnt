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
	STM_CREATE(ExecInit);
	STM_CREATE(ExecCycle);
	STM_CREATE(ExecShutdown);
	STM_CREATE(ExecMoveLegsToSleepPosition);

	m_oSetupData = new SETUP_DATA();
	m_oLifeParams = new LIFE_PARAMS();
	m_oWorkParams = new WORK_PARAMS();

	m_pKinematicsModule = new KinematicsModule("KinematicsModule");
	m_pSensoricsModule = new SensoricsModule("SensoricsModule");

	m_eRobotType = TYPE_6_LEGS;

	RegisterSPIVars();

	m_eStatus = ROBOTSTATUS_BOOTING;
}

OnyxAnt::~OnyxAnt()
{
}

STMRESULT OnyxAnt::ExecInit()
{
	enum
	{
		sSTART = S_START,
		sINITSPI,
		sEND,
		sERROR
	};

	Stm* pStm = STM(ExecInit);

	switch (pStm->GetWorkState())
	{
	case sSTART:
	{
		std::cout << "OnyxAnt::ExecInit : Start\n";
		return pStm->ChangeWorkState(RobotBase::ExecInit(), sINITSPI);
	}
	case sINITSPI:
	{
		if (m_oSPIInterface.spiInit())
			return pStm->ChangeWorkState(S_READY, sEND);
		else
			return pStm->ChangeWorkState(S_READY, sERROR);
	}
	case sEND:
	{
		std::cout << "OnyxAnt::ExecInit : End\n";
		return pStm->ChangeWorkState(S_READY);
	}
	case sERROR:
	{
		std::cout << "OnyxAnt::ExecInit : Error!\n";
		return pStm->ChangeWorkState(S_ERROR);
	}
	}

	m_eStatus = ROBOTSTATUS_IDLE;
	m_bIsInitialized = true;

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

	Stm* pStm = STM(ExecStart);

	switch (pStm->GetWorkState())
	{
	case sSTART:
	{
		std::cout << "Hello, I'm the OnyxAnt! :)\n";
		return pStm->ChangeWorkState(RobotBase::ExecStart(), sINIT);
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
		std::cout << "OnyxAnt::ExecStart : End\n";
	}
	case sERROR:
	{
		std::cout << "OnyxAnt::ExecStart : Error!\n";
		return pStm->ChangeWorkState(S_ERROR);
	}
	}

	return S_BUSY;
}

STMRESULT OnyxAnt::ExecCycle()
{
	enum
	{
		sSTART = S_START,
		sPROCESSSPI,
		sTESTCYCLE,
		sEND,
		sERROR
	};

	Stm* pStm = STM(ExecCycle);

	switch (pStm->GetWorkState())
	{
	case sSTART:
	{
		std::cout << "OnyxAnt::ExecCycle : Start\n";		
		return pStm->ChangeWorkState(RobotBase::ExecCycle(), sPROCESSSPI);
	}
	case sPROCESSSPI:
	{
		return pStm->ChangeWorkState(m_oSPIInterface.Control(), sTESTCYCLE);
	}
	case sTESTCYCLE:
	{
		int x;
		cin >> x;

		if (x == 0)
			return pStm->ChangeWorkState(S_READY, sEND);
		if (x == 1)
			m_oLifeParams->m_lTestVar++;
		if (x == 5)
			return pStm->ChangeWorkState(S_READY, sERROR);

		return pStm->ChangeWorkState(S_READY, sPROCESSSPI);
	}
	case sEND:
	{
		std::cout << "OnyxAnt::ExecCycle : End\n";
		return pStm->ChangeWorkState(S_READY);
	}
	case sERROR:
	{
		std::cout << "OnyxAnt::ExecCycle : Error!\n";
		return pStm->ChangeWorkState(S_ERROR);
	}
	}

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

STMRESULT OnyxAnt::CollectSensorData()
{
	return S_READY;
}

STMRESULT OnyxAnt::ProcessSensorData()
{
	return S_READY;
}

STMRESULT OnyxAnt::SelfDiagnosis()
{
	return S_READY;
}

STMRESULT OnyxAnt::SendMoveCommands()
{
	return S_READY;
}

void OnyxAnt::RegisterSPIVars()
{
	m_oSPIInterface.RegisterSPIVar(m_oLifeParams->m_lTestVar, "TestVar");
}
