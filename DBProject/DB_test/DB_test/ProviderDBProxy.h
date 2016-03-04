#pragma once
#include <string>
#include "IPersistDB.h"

class Provider;

class ProviderDBProxy : private IPersistDB
{
public:
	ProviderDBProxy(void);
	~ProviderDBProxy(void);

	Provider* m_provider;
	bool Load(DBRecord * responce);
	bool Save(DBRecord * responce);
};

