
#include "LoggerFactory.h"
#include "FileLogger.h"
#include "DbLogger.h"


static ILogger *FileLoggerFactory(apr_pool_t *pSupPool);
static ILogger *DbLoggerFactory(apr_pool_t *pSupPool);

LoggerFactory CreateFactory(FactoryType type)
{
	switch (type)
	{
	case FACTORY_NULL:
		return NULL;
	case FACTORY_FILE_LOGGER:
		return FileLoggerFactory;
	case FACTORY_DATABASE_LOGGER:
		return DbLoggerFactory;
	default:
		return NULL;
	}
}

//�ļ���־����
static ILogger *FileLoggerFactory(apr_pool_t *pSupPool)
{
	return FileLogger2ILogger(FileLogger_New(pSupPool));
}

//���ݿ���־����
static ILogger *DbLoggerFactory(apr_pool_t *pSupPool)
{
	return DbLogger2ILogger(DbLogger_New(pSupPool));
}
