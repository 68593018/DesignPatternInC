
#include "LoggerFile.h"


static void WriteLog();
static void Free(ILogger **ppLogger);

struct LoggerFile_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	ILogger m_logger;
};

static void WriteLog(ILogger *pLogger)
{
	puts("�ļ���־��¼!");
}

static void Free(ILogger **ppLogger)
{
	LoggerFile_Free(&(LoggerFile *)(*ppLogger)->pImplicit);
	*ppLogger = NULL;
}

LoggerFile * LoggerFile_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	LoggerFile *pInst = apr_palloc(pPool, sizeof(LoggerFile));

	pInst->pFld = apr_palloc(pPool, sizeof(LoggerFile_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_logger.pImplicit = pInst;
	pInst->pFld->m_logger.Free = Free;

	pInst->pFld->m_logger.WriteLog = WriteLog;

	//˽�г�Ա��ʼ��

	//���з�����ʼ��

	return pInst;
}

ILogger * LoggerFile2ILogger(LoggerFile * pInst)
{
	return &(pInst->pFld->m_logger);
}

void LoggerFile_Free(LoggerFile ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
