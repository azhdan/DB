#include "StdAfx.h"
#include "ProductDBProxy.h"
#include "Product.h"


ProductDBProxy::ProductDBProxy(void)
{
}


ProductDBProxy::~ProductDBProxy(void)
{
}

bool ProductDBProxy::Save(DBRecord * responce)
{
	return true;
}

bool ProductDBProxy::Load(DBRecord * responce)
{
	
	m_product = new Product();
	m_product->m_id = atoi(responce->record.at("id").c_str());
	m_product->m_is_enable = atoi(responce->record.at("is_enable").c_str());
	m_product->m_name = responce->record.at("name");
	m_product->m_price = atoi(responce->record.at("price").c_str());
	return true;
}