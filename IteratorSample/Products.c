
#include "IteratorProduct.h"
#include "Products.h"

struct Products_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IAggregate m_aggregate;

    //��Ʒ������
    RING(TxObject) *m_pProducts;

    //������
    IIterator *m_pIterator;
};

static void Free(IAggregate **ppAggregate)
{
    Products_Free(&(Products *)(*ppAggregate)->pImplicit);
    *ppAggregate = NULL;
}

static RING(TxObject) *GetTxObjects(IAggregate *pAggregate)
{
    Products *pInst = (Products *)pAggregate->pImplicit;
    return pInst->pFld->m_pProducts;
}

static void SetTxObjects(IAggregate *pAggregate, RING(TxObject) *pTxObjects)
{
    Products *pInst = (Products *)pAggregate->pImplicit;
    pInst->pFld->m_pProducts = pTxObjects;
}

static IIterator *CreateIterator(IAggregate *pAggregate)
{
    Products *pInst = (Products *)pAggregate->pImplicit;
    return pInst->pFld->m_pIterator;
}

Products * Products_New(apr_pool_t * pSupPool, RING(TxObject) *pProducts)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    Products *pInst = apr_palloc(pPool, sizeof(Products));

    pInst->pFld = apr_palloc(pPool, sizeof(Products_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_aggregate.pImplicit = pInst;
    pInst->pFld->m_aggregate.Free = Free;

    pInst->pFld->m_aggregate.GetTxObjects = GetTxObjects;
    pInst->pFld->m_aggregate.SetTxObjects = SetTxObjects;
    pInst->pFld->m_aggregate.CreateIterator = CreateIterator;

    pInst->pFld->m_pProducts = pProducts;
    pInst->pFld->m_pIterator = IteratorProduct2IIterator(IteratorProduct_New(pInst->pFld->m_pPool, pInst->pFld->m_pProducts));

    return pInst;
}

IAggregate * Products2IAggregate(Products * pInst)
{
    return &(pInst->pFld->m_aggregate);
}

void Products_Free(Products ** ppInst)
{
    (*ppInst)->pFld->m_pIterator->Free(&((*ppInst)->pFld->m_pIterator));

    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
