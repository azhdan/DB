#include "StdAfx.h"
#include "SqLiteProvider.h"
#include "sqlite3.h"
#include "DBStorage.h"

SqLiteProvider::SqLiteProvider(void)
{
}


SqLiteProvider::~SqLiteProvider(void)
{
}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   DBStorage *pDBResponce = (DBStorage*)data;
   DBRecord map_record;   
   for(i=0; i<argc; i++)
   {
	   std::string col_name(azColName[i]);
	   std::string row_value(argv[i]);
	   map_record.record[col_name]=row_value;
   }
   pDBResponce->records.push_back(map_record);
   return 0;
}

bool SqLiteProvider::ExecuteRequest(const std::string sql, DBStorage *responce)
{

	int rc;	
	char *zErrMsg = 0;
     
	rc = sqlite3_exec(m_db, sql.data(), callback, (void*)responce, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		sqlite3_free(zErrMsg);
		return false;
	}
	return true;
}

bool SqLiteProvider::Connect(std::string db_name)
{
	int rc = sqlite3_open("b:\\SQLiteStudio\\Demo_DB.db", &m_db);
	if( rc )
		return false;

	return true;
}

bool SqLiteProvider::Disconnect()
{
	if(m_db)
		sqlite3_close(m_db);

	return true;
}
