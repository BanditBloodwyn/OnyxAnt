////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <iostream>
#include <vector>

using namespace std;


class BaseObject;


typedef enum
{
	S_START = 0,
	S_BUSY = 3,
	S_READY = 5,
	S_ERROR = -1
} STMRESULT;

typedef STMRESULT(BaseObject::* STMFUNC)();	// Function pointer to function in Organ


////////////////////////////////////////////////////////////////////////////////


class Stm
{
	friend class Organ;

public:
	typedef enum
	{
		STM_START = 0,		// == START
		STM_BUSY = 3,		// == BUSY
		STM_DONE = 5,		// == READY
	} STM_STATE;

	// types
public:
	class FUNC_FRAME
	{
	public:
		FUNC_FRAME()
		{
			m_pBaseObject = NULL;
			m_pStmFunc = NULL;
			m_sLogName = "FuncName";
			m_nExecState = STM_START;
			m_nExecResult = S_READY;
		}
		BaseObject*		m_pBaseObject;
		STMFUNC			m_pStmFunc;
		string			m_sLogName;
		STM_STATE		m_nExecState;
		STMRESULT		m_nExecResult;
	};

	typedef vector<FUNC_FRAME> BATCH_SEQUENCE;

	// construction
public:
	Stm(string sStmName);
	~Stm();

	// methods
public:
	string			GetName();

	bool			IsEmpty();
	void			Empty();
	void			Reset();

	STMRESULT		ChangeWorkState(STMRESULT nResult, long nNextWorkState = S_START, int nWorkErrorCode = 0, bool bIsCriticalError = false);
	STMRESULT		ChangeWorkStateError(int nWorkErrorCode = 0, bool bIsCriticalError = false);
	long			GetWorkState();

	bool			IsWorking();
	bool			IsIdle();
	bool			IsBusy();

	bool			AddBatchFunc(STMFUNC pStmFunc, string sLogName);
	STMRESULT		ExecBatch();

	STMRESULT		ExecWait(double nTimeout);

	// attributes
protected:
	string			m_sStmName;

	long			m_nBatchState;			//Batch processing state
	STMRESULT		m_nBatchResult;			//The most recent batch processing result
	BATCH_SEQUENCE	m_BatchSequence;		//Sequential queue of stmfuncs

	STMRESULT		m_nWorkResult;			//The most recent working result
	long			m_nWorkState;			//My state if working as a state machine
	bool			m_bWorkErrorDetected;

private:
	BaseObject* m_pBaseObject;

	long			m_nTimerState;
};