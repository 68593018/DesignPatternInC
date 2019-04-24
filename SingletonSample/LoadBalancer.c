
#include <apr_tables.h>
#include <apr_strings.h>
#include "LoadBalancer.h"

//����
static LoadBalancer *pSingleton = NULL;

struct LoadBalancer_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	apr_array_header_t *m_arr;
};

//����

//˽�з���

//���з���
static void AddServer(LoadBalancer *pInst, const char *const pServer)
{
	*(const char **)apr_array_push(pInst->pFld->m_arr) = apr_pstrdup(pInst->pFld->m_pPool, pServer);
}
static void RemoveServer(LoadBalancer *pInst, const char *const pServer)
{
	for (int i = 0; i < pInst->pFld->m_arr->nelts; i++)
	{
		if (!strcmp(((const char **)pInst->pFld->m_arr->elts)[i], pServer))
		{
			//����Ӧ��ɾ�������е�Ԫ�أ�
			//͵�������ʹ�ӡһ�������ˡ�
			printf("Element %s found, and will be removed..\n", ((const char **)pInst->pFld->m_arr->elts)[i]);
			break;
		}
	}
}
static int GetServerIndex(LoadBalancer *pInst, const char* const pServer)
{
	for (int i = 0; i < pInst->pFld->m_arr->nelts; i++)
	{
		if (!strcmp(((const char **)pInst->pFld->m_arr->elts)[i], pServer))
		{
			//printf("Element %s found.\n", ((const char **)pInst->pFld->m_arr->elts)[i]);
			return i;
		}
	}

	return -1;
}

//˽�й��췽��
static LoadBalancer *LoadBalancer_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

    LoadBalancer *pInst = (LoadBalancer *)apr_palloc(pPool, sizeof(LoadBalancer));

    pInst->pFld = (LoadBalancer_Fld *)apr_palloc(pPool, sizeof(LoadBalancer));
	pInst->pFld->m_pPool = pPool;

	//������̬�ַ�������
	pInst->pFld->m_arr = apr_array_make(pInst->pFld->m_pPool, 20/*��ʼ����20*/, sizeof(const char *)/*ÿ��Ԫ�ض����ַ������洢�ַ�����ָ��*/);

    pInst->AddServer = AddServer;
    pInst->RemoveServer = RemoveServer;
    pInst->GetServerIndex = GetServerIndex;

    return pInst;
}

LoadBalancer * GetLoadBalancerInstance(apr_pool_t *pSupPool)
{
    return pSingleton ? pSingleton : (pSingleton = LoadBalancer_New(pSupPool));
}

void LoadBalancer_Free(LoadBalancer ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
