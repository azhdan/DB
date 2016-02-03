#pragma once
#include <string>

class DBStorage;
class IDBProvider
{
public:
	virtual bool ExecuteRequest(const std::string, DBStorage *responce)=0;
	virtual bool Connect( std::string db_name)=0;
	virtual bool Disconnect()=0;
};

