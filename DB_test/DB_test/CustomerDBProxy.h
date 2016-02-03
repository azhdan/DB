#pragma once
#include <string>
#include "IPersistDB.h"

class Customer;
class DBRecord;

class CustomerDBProxy : public IPersistDB
{
public:
	CustomerDBProxy(void);
	~CustomerDBProxy(void);

	Customer* m_customer;
	bool Load(DBRecord * responce);
	bool Save(DBRecord * responce);
};

