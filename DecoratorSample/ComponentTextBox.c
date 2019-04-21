
#include <stdio.h>
#include "ComponentTextBox.h"

//���ԡ���������

struct ComponentTextBox_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IComponent m_component;
};

//ʵ�ֽӿڷ���
static void Free(IComponent **ppComponent)
{
    ComponentTextBox_Free(&(ComponentTextBox *)(*ppComponent)->pImplicit);
    *ppComponent = NULL;
}

static void Display(IComponent *pComponent)
{
    //ComponentTextBox *pInst = (ComponentTextBox *)pComponent->pImplicit;

    puts("��ʾ�ı���");
}

ComponentTextBox * ComponentTextBox_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ComponentTextBox *pInst = apr_palloc(pPool, sizeof(ComponentTextBox));
    
    pInst->pFld = apr_palloc(pPool, sizeof(ComponentTextBox_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_component.pImplicit = pInst;
    pInst->pFld->m_component.Free = Free;

    pInst->pFld->m_component.Display = Display;

    return pInst;
}

IComponent * ComponentTextBox2IComponent(ComponentTextBox * pInst)
{
    return &(pInst->pFld->m_component);
}

void ComponentTextBox_Free(ComponentTextBox ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
