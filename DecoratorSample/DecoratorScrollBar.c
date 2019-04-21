
#include <stdio.h>
#include "DecoratorScrollBar.h"

//���ԡ���������
static void SetScrollBar();

struct DecoratorScrollBar_Fld
{
    apr_pool_t *m_pPool;

    IComponent m_component;

    //�ⲿע��ľ��幹��
    IComponent *m_pComponent;
};

//ʵ�ֽӿڷ���
static void Free(IComponent **ppComponent)
{
    DecoratorScrollBar_Free(&((DecoratorScrollBar *)(*ppComponent)->pImplicit));
    *ppComponent = NULL;
}

//ʵ�ֽӿڷ���
static void Display(IComponent *pComponent)
{
    DecoratorScrollBar *pInst = (DecoratorScrollBar *)pComponent->pImplicit;

    //װ����ǿ
    SetScrollBar();
    //���ù����ķ���
    pInst->pFld->m_pComponent->Display(&(pInst->pFld->m_component));
}

//װ�ι���
//����ʵ��͸��װ��
static void SetScrollBar()
{
    puts("Ϊ�������ӽ�����.");
}

DecoratorScrollBar * DecoratorScrollBar_New(apr_pool_t * pSupPool, IComponent * pComponent)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    DecoratorScrollBar *pInst = apr_palloc(pPool, sizeof(DecoratorScrollBar));

    pInst->pFld = apr_palloc(pPool, sizeof(DecoratorScrollBar_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_component.pImplicit = pInst;
    pInst->pFld->m_component.Free = Free;

    pInst->pFld->m_component.Display = Display;
    pInst->pFld->m_pComponent = pComponent;

    return pInst;
}

IComponent * DecoratorScrollBar2IComponent(DecoratorScrollBar * pInst)
{
    return &(pInst->pFld->m_component);
}

void DecoratorScrollBar_Free(DecoratorScrollBar ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
