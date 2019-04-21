
#include <apr_pools.h>
#include "ISearcher.h"


#ifndef SEARCHER_H
#define SEARCHER_H

typedef struct Searcher_Fld Searcher_Fld;
typedef struct Searcher Searcher;

struct Searcher
{
	Searcher_Fld *pFld;

	//�̳нӿڣ�����Ҫ��ʾ������������
};

Searcher *Searcher_New(apr_pool_t *pSupPool);
ISearcher *Searcher2ISearcher(Searcher *pInst);
void Searcher_Free(Searcher **ppInst);

#endif // !SEARCHER_H
