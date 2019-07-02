
#include <stdio.h>
#include "Emperor.h"

//����
static Emperor *pSingleton = NULL;

struct Emperor_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;
};

//����

//˽�з���

//���з���
static void Say(Emperor *pInst)
{
    printf("I\'m the great emperor!\n");
}

//˽�й��췽��
static Emperor *Emperor_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

    Emperor *pInst = apr_palloc(pPool, sizeof(Emperor));

    pInst->pFld = apr_palloc(pPool, sizeof(Emperor_Fld));
	pInst->pFld->m_pPool = pPool;

    pInst->Say = Say;

    return pInst;
}

Emperor * GetEmperorInstance(apr_pool_t *pSupPool)
{
    //�߲���ʱ�������ʵ�����ͳ�ʼ��������
    //������ܳ��ֶ�������������
    //��Ϊ���󴴽�����һ�����̣���Ҫ����һ��ʱ��
    return pSingleton ? pSingleton : (pSingleton = Emperor_New(pSupPool));
}

void Emperor_Free(Emperor ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
