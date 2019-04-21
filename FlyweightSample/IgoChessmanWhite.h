
#include <apr_pools.h>
#include "IIgoChessman.h"


#ifndef IGOCHESSMANWHITE_H
#define IGOCHESSMANWHITE_H

typedef struct IgoChessmanWhite_Fld IgoChessmanWhite_Fld;
typedef struct IgoChessmanWhite IgoChessmanWhite;

struct IgoChessmanWhite
{
    IgoChessmanWhite_Fld *pFld;

    //�̳нӿ�
};

IgoChessmanWhite *IgoChessmanWhite_New(apr_pool_t *pSupPool);
IIgoChessman *IgoChessmanWhite2IIgoChessman(IgoChessmanWhite *pInst);
void IgoChessmanWhite_Free(IgoChessmanWhite **ppInst);

#endif // !IGOCHESSMANWHITE_H
