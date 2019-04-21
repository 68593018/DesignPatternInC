
#include <stdio.h>
#include <apr_pools.h>
#include "IComponent.h"
#include "ComponentWindow.h"
#include "DecoratorScrollBar.h"
#include "DecoratorBlackBorder.h"


int main(int argc, char **argv)
{
    apr_pool_t *pMemPool;
    
    apr_initialize();

    apr_pool_create(&pMemPool, NULL);

    IComponent *pComponent = ComponentWindow2IComponent(ComponentWindow_New(pMemPool));//�������Ͷ��壬���󹹼�����
    IComponent *pDecorator = DecoratorScrollBar2IComponent(DecoratorScrollBar_New(pMemPool, pComponent));//����͸��װ�������Թ�������װ��
    IComponent *pDecorator2 = DecoratorBlackBorder2IComponent(DecoratorBlackBorder_New(pMemPool, pDecorator));//�ٴζԹ�������װ��

    pDecorator2->Display(pDecorator2);
    
    pDecorator2->Free(&pDecorator2);
    pDecorator->Free(&pDecorator);
    pComponent->Free(&pComponent);

    apr_pool_destroy(pMemPool);

    apr_terminate();

    return EXIT_SUCCESS;
}
