
#include <apr_pools.h>
#include "ILogger.h"

#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

typedef enum FactoryType FactoryType;

enum FactoryType
{
	FACTORY_NULL = 0,
	FACTORY_FILE_LOGGER = 1,
	FACTORY_DATABASE_LOGGER = 2
};

//�������ͱ��ʾ�һ����������ķ�����
//��������ֻ��һ������ָ�������
typedef ILogger *(* LoggerFactory)(apr_pool_t *pSupPool);

//��������
LoggerFactory CreateFactory(FactoryType type);

#endif // !LOGGERFACTORY_H
