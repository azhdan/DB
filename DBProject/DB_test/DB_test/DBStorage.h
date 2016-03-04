#pragma once
#include <map>
#include <string>
#include <vector>


using namespace std;
class IPersistDB;
class DBRecord
{
	public:
	map<string, string> record;

};
class DBStorage
{
public:
	DBStorage(void);
	~DBStorage(void);
		
	vector<DBRecord> records;
	       
};

