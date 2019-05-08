
#include "Matrix.h"

struct Matrix_Fld
{
    //��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;
};

Matrix * Matrix_New(apr_pool_t *pSupPool)
{
	//������ǰ��ר�õ��ڴ��
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	//��ʵ��
	Matrix *pInst = apr_palloc(pPool, sizeof(Matrix));

	//���������ʼ��
	pInst->pFld = apr_palloc(pPool, sizeof(Matrix_Fld));
	//��ʵ��ר���ڴ��
	pInst->pFld->m_pPool = pPool;

	return pInst;
}

void Matrix_Free(Matrix ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
