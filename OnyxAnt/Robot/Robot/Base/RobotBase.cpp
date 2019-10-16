#include "RobotBase.h"


RobotBase::RobotBase()
{
}

RobotBase::~RobotBase()
{
}

Stm* RobotBase::CreateStm(const string& sStmName)
{
	assert(m_oStmMap.find(sStmName) == m_oStmMap.end());

	Stm* pStm = new Stm(sStmName);
	m_oStmMap[sStmName] = pStm;

	return pStm;
}

Stm* RobotBase::FindStm(const string& sStmName)
{
	map<string, Stm*>::iterator it = m_oStmMap.find(sStmName);

	if (it == m_oStmMap.end())
		return nullptr;

	return it->second;
}
