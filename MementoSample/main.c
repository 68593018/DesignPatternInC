
#include <stdio.h>
#include <apr_pools.h>
#include "Caretaker.h"
#include "Memento.h"
#include "Chessman.h"


void output(Chessman *pChessman, apr_pool_t *pPool)
{
    printf("����%s�ĵ�ǰ��λ��Ϊ����%d�У���%d�С�\n", pChessman->GetLabel(pChessman, pPool), pChessman->GetX(pChessman), pChessman->GetY(pChessman));
}

int main(int argc, char **argv)
{
    apr_pool_t *pMemPool;

    apr_initialize();

    apr_pool_create(&pMemPool, NULL);

    Caretaker *pCaretaker = Caretaker_New(pMemPool);
    Chessman *pChessman = Chessman_New(pMemPool, "��", 1, 1);
    output(pChessman, pMemPool);

    Memento *pOut = Memento_New(pMemPool, "-", 0, 0);
    pCaretaker->SetMemento(pCaretaker, pChessman->Save(pChessman, pMemPool, pOut));//����״̬
    pChessman->SetY(pChessman, 4);
    output(pChessman, pMemPool);

    pCaretaker->SetMemento(pCaretaker, pChessman->Save(pChessman, pMemPool, pOut));//����״̬
    output(pChessman, pMemPool);

    pChessman->SetY(pChessman, 5);
    output(pChessman, pMemPool);

    puts("����---------");
    pChessman->Restore(pChessman, pCaretaker->GetMemento(pCaretaker));//�ָ�״̬
    output(pChessman, pMemPool);

	Memento_Free(&pOut);
	Chessman_Free(&pChessman);
	Caretaker_Free(&pCaretaker);

    apr_pool_destroy(pMemPool);

    apr_terminate();

    return EXIT_SUCCESS;
}