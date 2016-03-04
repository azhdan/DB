#pragma once
#include <string>

class Product
{
public:
	Product(void);
	~Product(void);
private:
	int m_id;
	std::string m_name;
	float m_price;
	bool m_is_enable;
};

