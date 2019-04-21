
#include <apr_pools.h>
#include "IApprover.h"


#ifndef PRESIDENT_H
#define PRESIDENT_H

typedef struct President_Fld President_Fld;
typedef struct President President;

struct President
{
    President_Fld *pFld;

    //�̳нӿ�
};

President *President_New(apr_pool_t *pSupPool, const char *pName);
IApprover *President2IApprover(President *pInst);
void President_Free(President **ppInst);

#endif // !PRESIDENT_H
