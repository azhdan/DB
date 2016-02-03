#pragma once

#include "IPersistDB.h"
#include <map>
#include <vector>
#include <string>
#include "CustomerDBProxy.h"
#include "ProductDBProxy.h"
#include "ProviderDBProxy.h"
using namespace std;

class Order;
class DBStorage;
class OrderDBProxy : public IPersistDB
{
public:
	OrderDBProxy(void);
	~OrderDBProxy(void);

	Order* m_order;
	CustomerDBProxy * m_customerProxy;
	ProductDBProxy * m_productProxy;
	ProviderDBProxy * m_providerProxy;

	bool Load(DBRecord * responce);
	bool Save(DBRecord * responce);
	
};

