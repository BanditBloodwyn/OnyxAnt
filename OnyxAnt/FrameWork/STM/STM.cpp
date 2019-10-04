////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////


#include "STM.h"


Stm::Stm(string sStmName)
{
	m_sStmName = sStmName;
	m_nWorkState = S_START;
}

Stm::~Stm()
{

}

string Stm::GetName()
{
	return m_sStmName;
}

bool Stm::IsEmpty()
{
	return m_BatchSequence.size() == 0;
}

void Stm::Empty()
{
	// remove all StmFuncs from BatchSequence
	m_BatchSequence.resize(0);

	// (re)set initial run state always to S_START
	Reset();
}

void Stm::Reset()
{
	m_nBatchResult = S_START;

	for (auto& it : m_BatchSequence)
	{
		it.m_nExecState = STM_START;
		it.m_nExecResult = S_READY;
	}

	m_nWorkResult = S_READY;
	m_nWorkState = S_START;
	m_bWorkErrorDetected = false;
}

STMRESULT Stm::ChangeWorkState(STMRESULT nResult, long nNextWorkState /*= START*/, int nWorkErrorCode /*= 0*/, bool bIsCriticalError /*= false*/)
{
	switch (nResult)
	{
	case S_READY:
		break;

	case S_BUSY:
		return S_BUSY;

	case S_ERROR:
	default:
		m_bWorkErrorDetected = true;
		break;
	}

	if (m_bWorkErrorDetected)
	{
		m_nWorkState = S_START;
		m_nWorkResult = S_ERROR;
	}
	else if (nNextWorkState == S_START)
	{
		m_nWorkState = S_START;
		m_nWorkResult = S_READY;
	}
	else
	{
		m_nWorkResult = S_BUSY;
		m_nWorkState = nNextWorkState;
	}

	return m_nWorkResult;
}

STMRESULT Stm::ChangeWorkStateError(int nWorkErrorCode /*= 0*/, bool bIsCriticalError /*= false*/)
{
	return ChangeWorkState(S_ERROR, S_START);
}

long Stm::GetWorkState()
{
	return m_nWorkState;
}

bool Stm::IsWorking()
{
	return m_nWorkState != S_START && m_nWorkResult == S_BUSY;
}

bool Stm::IsIdle()
{
	return m_nBatchResult != S_BUSY && m_nWorkResult != S_BUSY;
}

bool Stm::IsBusy()
{
	return m_nBatchResult == S_BUSY || m_nWorkResult == S_BUSY;
}

bool Stm::AddBatchFunc(STMFUNC pStmFunc, string sLogName)
{
	return true;
}

STMRESULT Stm::ExecBatch()
{
	return S_READY;
}

STMRESULT Stm::ExecWait(double nTimeout)
{
	return S_READY;
}