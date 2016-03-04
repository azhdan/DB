#pragma once
#include <string>
class Provider
{
public:
	Provider(void);
	~Provider(void);
private:
	int m_id;
	std::string name;
	std::string contact; 
};

