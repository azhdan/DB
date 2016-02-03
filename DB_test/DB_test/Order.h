#pragma once
#include <string>

class Product;
class Customer;
class Provider;

class Order
{
public:
	Order(void);
	~Order(void);

	int order_id;
	float price;
	int count;
	Product* m_product;
	Customer* m_customer;
	Provider* m_provider;

};

