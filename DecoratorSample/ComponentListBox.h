
#include <apr_pools.h>
#include "IComponent.h"


#ifndef COMPONENTLISTBOX_H
#define COMPONENTLISTBOX_H

typedef struct ComponentListBox_Fld ComponentListBox_Fld;
typedef struct ComponentListBox ComponentListBox;

struct ComponentListBox
{
    ComponentListBox_Fld *pFld;

    //��Ϊ�ؼ�ͨ���ӿ����͵��ã�
    //������ﲻ�������̳еõ��Ĺ�������Display
};

ComponentListBox *ComponentListBox_New(apr_pool_t *pSupPool);
IComponent *ComponentListBox2IComponent(ComponentListBox *pInst);
void ComponentListBox_Free(ComponentListBox **ppInst);

#endif // !COMPONENTLISTBOX_H
