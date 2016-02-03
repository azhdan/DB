#pragma once
#include <string>
#include "IPersistDB.h"
class Product;
class DBRecord;

class ProductDBProxy : public IPersistDB
{
public:
	ProductDBProxy(void);
	~ProductDBProxy(void);

	Product* m_order;
	bool Load(DBRecord * responce);
	bool Save(DBRecord * responce);
};

