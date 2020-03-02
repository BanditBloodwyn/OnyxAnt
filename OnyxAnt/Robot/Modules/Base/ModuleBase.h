//////////////////////////////////////////////////////////////////////////////////////////////////
// Name:		ModuleBase.h
// Project:		OnyxAnt
// Purpose:		
//
// Created:		27.02.2020
// Author:		Kevin Eichenberg
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <ElementBase/ElementBase.h>
#include <Base/UnitBase.h>


class ModuleBase : public ElementBase
{
////////////////////////////////////////////
// structures
////////////////////////////////////////////
public:


////////////////////////////////////////////
// construction
////////////////////////////////////////////
public:
	ModuleBase();
	ModuleBase(string sName);
	~ModuleBase();


////////////////////////////////////////////
// methods
////////////////////////////////////////////
public:


////////////////////////////////////////////
// STM
////////////////////////////////////////////
protected:


////////////////////////////////////////////
// attributes
////////////////////////////////////////////
private:
	vector<UnitBase*>       m_Units;
};