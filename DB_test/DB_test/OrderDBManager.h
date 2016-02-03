#pragma once
#include <vector>
#include <string>
using namespace std;

class Order;
class Product;
class Provider;
class Customer;
class IDBProvider;

class OrderDBManager
{
public:
	OrderDBManager(void);
	~OrderDBManager(void);
	vector<Order*> GetOrders();
	Order* GetOrderById(int id);
	Order* GetOrderByCustomerName(string name);
	vector<Customer*> GetCustomers(); 
	Customer* GetCustomerByName(string name); 
	bool ConnectToDB(string db_name, string db_type); 

	IDBProvider * m_DBProvider;
};

