
#include "DbLogger.h"


static void WriteLog();
static void Free(ILogger **ppLogger);

struct DbLogger_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	ILogger m_logger;
};

static void WriteLog()
{
	puts("���ݿ���־��¼!");
}

static void Free(ILogger **ppLogger)
{
	if (!ppLogger || !(*ppLogger))
	{
		return;
	}

	DbLogger_Free(&(DbLogger *)(*ppLogger)->pImplicit);
	*ppLogger = NULL;
}

DbLogger * DbLogger_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	DbLogger *pInst = (DbLogger *)apr_palloc(pPool, sizeof(DbLogger));

	pInst->pFld = (DbLogger_Fld *)apr_palloc(pPool, sizeof(DbLogger_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_logger.pImplicit = pInst;
	pInst->pFld->m_logger.Free = Free;

	pInst->pFld->m_logger.WriteLog = WriteLog;

	//��ʼ��˽�г�Ա

	//��ʼ�����з���

	return pInst;
}

ILogger * DbLogger2ILogger(DbLogger * pInst)
{
	return &(pInst->pFld->m_logger);
}

void DbLogger_Free(DbLogger ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

	*ppInst = NULL;
}
