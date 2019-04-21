
#include <stdio.h>
#include "ComponentWindow.h"

//���ԡ���������

struct ComponentWindow_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IComponent m_component;
};

static void Free(IComponent **ppComponent)
{
    ComponentWindow_Free(&(ComponentWindow *)(*ppComponent)->pImplicit);
    *ppComponent = NULL;
}

static void Display(IComponent *pComponent)
{
    //ComponentWindow *pInst = (ComponentWindow *)pComponent->pImplicit;

    puts("��ʾ����.");
}

ComponentWindow * ComponentWindow_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ComponentWindow *pInst = apr_palloc(pPool, sizeof(ComponentWindow));

    pInst->pFld = apr_palloc(pPool, sizeof(ComponentWindow_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_component.pImplicit = pInst;
    pInst->pFld->m_component.Free = Free;

    pInst->pFld->m_component.Display = Display;

    return pInst;
}

IComponent * ComponentWindow2IComponent(ComponentWindow * pInst)
{
    return &(pInst->pFld->m_component);
}

void ComponentWindow_Free(ComponentWindow ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
