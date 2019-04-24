
#include <stdio.h>
#include <apr_pools.h>
#include "INotifier.h"
#include "NotifierAlly.h"
#include "IObserver.h"
#include "ObserverPlayer.h"


int main(int argc, char **argv)
{
	apr_pool_t *pMemPool;
	
	apr_initialize();

	apr_pool_create(&pMemPool, NULL);

	INotifier *pNotifier = NotifierAlly2INotifier(NotifierAlly_New(pMemPool, "��ӹȺ��"));
	IObserver *pObsrvrYangG = ObserverPlayer2IObserver(ObserverPlayer_New(pMemPool, "���"));
	IObserver *pObsrvrLingHc = ObserverPlayer2IObserver(ObserverPlayer_New(pMemPool, "�����"));
	IObserver *pObsrvrZhangWj = ObserverPlayer2IObserver(ObserverPlayer_New(pMemPool, "���޼�"));
	IObserver *pObsrvrDuanY = ObserverPlayer2IObserver(ObserverPlayer_New(pMemPool, "����"));

	pNotifier->Join(pNotifier, pObsrvrYangG);
	pNotifier->Join(pNotifier, pObsrvrLingHc);
	pNotifier->Join(pNotifier, pObsrvrZhangWj);
	pNotifier->Join(pNotifier, pObsrvrDuanY);

	pObsrvrYangG->BeAttacked(pObsrvrYangG, pNotifier);

	pObsrvrYangG->Free(&pObsrvrYangG);
	pObsrvrLingHc->Free(&pObsrvrLingHc);
	pObsrvrZhangWj->Free(&pObsrvrZhangWj);
	pObsrvrDuanY->Free(&pObsrvrDuanY);
	pNotifier->Free(&pNotifier);

	apr_pool_destroy(pMemPool);

	apr_terminate();

	return EXIT_SUCCESS;
}
