#pragma once
#include <string>
#include "SqLiteProvider.h"

class IDBProvider;
class DBProviderFactory
{
public:
	DBProviderFactory(void);
	~DBProviderFactory(void);

	static IDBProvider *GetDBProvider(std::string provider)
	{
		if(provider.compare("SqLite") ==0 )
			return new SqLiteProvider();

		return NULL;
	}

};

