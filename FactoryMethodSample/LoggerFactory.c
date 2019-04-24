
#include "LoggerFactory.h"
#include "LoggerFile.h"
#include "LoggerDb.h"


static ILogger *FactoryLoggerFile(apr_pool_t *pSupPool);
static ILogger *FactoryLoggerDb(apr_pool_t *pSupPool);

LoggerFactory CreateFactory(FactoryType type)
{
	switch (type)
	{
	case FACTORY_NULL:
		return NULL;
	case FACTORY_LOGGER_FILE:
		return FactoryLoggerFile;
	case FACTORY_LOGGER_DATABASE:
		return FactoryLoggerDb;
	default:
		return NULL;
	}
}

//�ļ���־����
static ILogger *FactoryLoggerFile(apr_pool_t *pSupPool)
{
	return LoggerFile2ILogger(LoggerFile_New(pSupPool));
}

//���ݿ���־����
static ILogger *FactoryLoggerDb(apr_pool_t *pSupPool)
{
	return LoggerDb2ILogger(LoggerDb_New(pSupPool));
}
