
#include "Validator.h"
#include "Searcher.h"
#include "Logger.h"
#include "SearcherProxy.h"

struct SearcherProxy_Fld
{
	apr_pool_t *m_pPool;

	//�̳нӿ�
	ISearcher m_searcher;

	//ҵ����ص�˽�г�Ա
	Validator *m_pValidator;
	Searcher *m_pSearcher;//��������Ϊ�����ͣ�����Ϊ������Ҳ����
	Logger *m_pLogger;
};

static void Free(ISearcher **ppSearcher)
{
	SearcherProxy_Free(&(SearcherProxy *)(*ppSearcher)->pImplicit);
	*ppSearcher = NULL;
}

static char *DoSearch(ISearcher *pSearcher, const char *pUserID, const char *pKeyword, apr_pool_t *pPool)
{
	SearcherProxy *pInst = (SearcherProxy *)pSearcher->pImplicit;

	if (pInst->pFld->m_pValidator->Validate(pInst->pFld->m_pValidator, pUserID))
	{
		ISearcher *pTmpSearcher = Searcher2ISearcher(pInst->pFld->m_pSearcher);//ת��Ϊ������
		char *pRet = pTmpSearcher->DoSearch(pTmpSearcher, pUserID, pKeyword, pPool);
		pInst->pFld->m_pLogger->Log(pInst->pFld->m_pLogger, pUserID);

		return pRet;
	}
	else
	{
		return NULL;
	}
}

SearcherProxy * SearcherProxy_New(apr_pool_t * pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	SearcherProxy *pInst = apr_palloc(pPool, sizeof(SearcherProxy));

	pInst->pFld = apr_palloc(pPool, sizeof(SearcherProxy_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_searcher.pImplicit = pInst;
	pInst->pFld->m_searcher.Free = Free;

	pInst->pFld->m_searcher.DoSearch = DoSearch;

	pInst->pFld->m_pValidator = Validator_New(pInst->pFld->m_pPool);
	pInst->pFld->m_pSearcher = Searcher_New(pInst->pFld->m_pPool);
	pInst->pFld->m_pLogger = Logger_New(pInst->pFld->m_pPool);

	return pInst;
}

ISearcher *SearcherProxy2ISearcher(SearcherProxy * pInst)
{
	return &(pInst->pFld->m_searcher);
}

void SearcherProxy_Free(SearcherProxy ** ppInst)
{
	Validator_Free(&((*ppInst)->pFld->m_pValidator));
	Searcher_Free(&((*ppInst)->pFld->m_pSearcher));
	Logger_Free(&((*ppInst)->pFld->m_pLogger));

	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
