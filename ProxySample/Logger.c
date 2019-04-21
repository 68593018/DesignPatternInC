
#include <stdio.h>
#include "Logger.h"

struct Logger_Fld
{
	apr_pool_t *m_pPool;
};

static void Log(Logger *pInst, const char *pUserID)
{
	printf("�������ݿ⣬�û�%s��ѯ������1.\n", pUserID);
}

Logger * Logger_New(apr_pool_t * pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	Logger *pInst = apr_palloc(pPool, sizeof(Logger));

	pInst->pFld = apr_palloc(pPool, sizeof(Logger_Fld));
	pInst->pFld->m_pPool = pPool;

	pInst->Log = Log;

	return pInst;
}

void Logger_Free(Logger ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
