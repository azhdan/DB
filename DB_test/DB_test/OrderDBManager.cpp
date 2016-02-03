#include "StdAfx.h"
#include "OrderDBManager.h"
#include "DBProviderFactory.h"
#include "DBStorage.h"
#include "OrderProxy.h"


OrderDBManager::OrderDBManager(void)
{
}


OrderDBManager::~OrderDBManager(void)
{
}

bool OrderDBManager::ConnectToDB(string db_name, string db_type)
{
	m_DBProvider = DBProviderFactory::GetDBProvider(db_type);
	bool res = m_DBProvider->Connect(db_name);
	return res;
}

vector<Order*> OrderDBManager::GetOrders()
{
	vector<Order*> orders;
	char *sql;
	sql = "SELECT order_id,\
			   order_date,\
			   count,\
			   Customer.name,\
			   Customer.mail,\
			   Customer.phone_number,\
			   Commodity.name,\
			   Commodity.price,\
			   Commodity.is_enable,\
			   Provider.name,\
			   Provider.contact\
		   FROM Orders o\
			   LEFT JOIN\
			   Customer ON o.customer_id = Customer.id\
			   LEFT JOIN\
			   Commodity ON o.commodity_id = Commodity.id\
			   LEFT JOIN\
			   Provider ON o.provider_id = Provider.id";

	string sql_requestsql(sql);
	DBStorage responce;
	m_DBProvider->ExecuteRequest(sql_requestsql, &responce);

	vector<DBRecord>::iterator it;
	vector<DBRecord> records = responce.records;
	for(it = records.begin(); it!=records.end(); ++it)
	{
		DBRecord  record = *it;
		
		OrderDBProxy order_proxy;
		order_proxy.Load(&record);
		orders.push_back(order_proxy.m_order);

	}
	return orders;
}
Order* OrderDBManager::GetOrderById(int id)
{
	return 0; 
}
Order* OrderDBManager::GetOrderByCustomerName(string name)
{
	return 0; 
}

vector<Customer*> OrderDBManager::GetCustomers()
{
	vector<Customer*> customer;
	return customer;
}
Customer* OrderDBManager::GetCustomerByName(string name)
{
	return 0;
}