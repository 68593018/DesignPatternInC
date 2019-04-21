
#include "DecoratorBlackBorder.h"

//���ԡ���������
static void SetBlackBorder();

struct DecoratorBlackBorder_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IComponent m_component;

    //��Ҫװ�εĹ�������
    IComponent *m_pComponent;
};

static void Free(IComponent **ppComponent)
{
    DecoratorBlackBorder_Free(&(DecoratorBlackBorder *)(*ppComponent)->pImplicit);
    *ppComponent = NULL;
}

static void Display(IComponent *pComponent)
{
    DecoratorBlackBorder *pInst = (DecoratorBlackBorder *)pComponent->pImplicit;

    //��ǿ�����Ĺ���
    SetBlackBorder();

    //���ù�����ԭ�й���
    pInst->pFld->m_pComponent->Display(pInst->pFld->m_pComponent);
}

static void SetBlackBorder()
{
    puts("Ϊ�������Ӻ�ɫ�߿�");
}

DecoratorBlackBorder * DecoratorBlackBorder_New(apr_pool_t * pSupPool, IComponent *pComponent)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    DecoratorBlackBorder *pInst = apr_palloc(pPool, sizeof(DecoratorBlackBorder));

    pInst->pFld = apr_palloc(pPool, sizeof(DecoratorBlackBorder_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_component.pImplicit = pInst;
    pInst->pFld->m_component.Free = Free;

    pInst->pFld->m_component.Display = Display;
    pInst->pFld->m_pComponent = pComponent;

    return pInst;
}

IComponent * DecoratorBlackBorder2IComponent(DecoratorBlackBorder * pInst)
{
    return &(pInst->pFld->m_component);
}

void DecoratorBlackBorder_Free(DecoratorBlackBorder ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
