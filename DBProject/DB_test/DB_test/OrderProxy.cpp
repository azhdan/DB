#include "StdAfx.h"
#include "OrderProxy.h"
#include "DBStorage.h"
#include "Order.h"

OrderDBProxy::OrderDBProxy(void)
{
//test1
//test11
}


OrderDBProxy::~OrderDBProxy(void)
{
}

bool OrderDBProxy::Save(DBRecord * responce)
{
	return true;
}

bool OrderDBProxy::Load(DBRecord * responce)
{
		
		m_order = new Order(); 
		m_order->count = atoi(responce->record.at("count").c_str());
		m_order->order_id = atoi(responce->record.at("order_id").c_str());
		m_order->price = atoi(responce->record.at("price").c_str());

		m_productProxy->Load(responce);
		m_providerProxy->Load(responce);
		m_customerProxy->Load(responce);
		
		m_order->m_customer = m_customerProxy->m_customer;
		m_order->m_product = m_productProxy->m_order;
		m_order->m_provider = m_providerProxy->m_provider;
		
	return true;
}

