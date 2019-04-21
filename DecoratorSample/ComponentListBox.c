
#include <stdio.h>
#include "ComponentListBox.h"

//���ԡ���������

struct ComponentListBox_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IComponent m_component;
};

//ʵ�ֽӿڷ���
static void Free(IComponent **ppComponent)
{
    ComponentListBox_Free(&((ComponentListBox *)(*ppComponent)->pImplicit));
    *ppComponent = NULL;
}
//ʵ�ֽӿڷ���
static void Display(IComponent *pComponent)
{
    //ComponentListBox *pInst = (ComponentListBox *)pComponent->pImplicit;

    puts("��ʾ�б��");
}

ComponentListBox * ComponentListBox_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ComponentListBox *pInst = apr_palloc(pPool, sizeof(ComponentListBox));

    pInst->pFld = apr_palloc(pPool, sizeof(ComponentListBox_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_component.pImplicit = pInst;
    pInst->pFld->m_component.Free = Free;

    pInst->pFld->m_component.Display = Display;

    return pInst;
}

IComponent * ComponentListBox2IComponent(ComponentListBox * pInst)
{
    return &(pInst->pFld->m_component);
}

void ComponentListBox_Free(ComponentListBox **ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
