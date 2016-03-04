#pragma once
#include "DBStorage.h"

class IPersistDB
{
public:
	virtual bool Load(DBRecord * storage)=0;
	virtual bool Save(DBRecord * storage)=0;
};