
#include <stdio.h>
#include "Validator.h"

struct Validator_Fld
{
	apr_pool_t *m_pPool;
};

static bool Validate(Validator *pInst, const char *pUserID)
{
	//ģ����֤
	printf("�����ݿ�����֤�û�%s�Ƿ�Ϸ�\n", pUserID);

	if (!strcmp(pUserID, "���"))
	{
		printf("ͨ����֤��\n");
		return true;
	}
	else
	{
		printf("��֤ʧ�ܡ�\n");
		return false;
	}
}

Validator * Validator_New(apr_pool_t * pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	Validator *pInst = apr_palloc(pPool, sizeof(Validator));

	pInst->pFld = apr_palloc(pPool, sizeof(Validator_Fld));
	pInst->pFld->m_pPool = pPool;

	pInst->Validate = Validate;

	return pInst;
}

void Validator_Free(Validator ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
