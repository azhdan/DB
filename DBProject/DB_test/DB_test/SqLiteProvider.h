#pragma once
#include "idbprovider.h"
class sqlite3;
class SqLiteProvider :
	public IDBProvider
{
public:
	SqLiteProvider(void);
	~SqLiteProvider(void);

	bool ExecuteRequest(const std::string, DBStorage *responce);
	bool Connect( std::string db_name);
	bool Disconnect();

	sqlite3 *m_db;
};

