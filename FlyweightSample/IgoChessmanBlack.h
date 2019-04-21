
#include <apr_pools.h>
#include "IIgoChessman.h"


#ifndef IGOCHESSMANBLACK_H
#define IGOCHESSMANBLACK_H

typedef struct IgoChessmanBlack_Fld IgoChessmanBlack_Fld;
typedef struct IgoChessmanBlack IgoChessmanBlack;

struct IgoChessmanBlack
{
    IgoChessmanBlack_Fld *pFld;

    //�̳нӿڣ�ͨ���ӿڵ��ã�
    //��˲������ӿڵķ���
};

IgoChessmanBlack *IgoChessmanBlack_New(apr_pool_t *pSupPool);
IIgoChessman *IgoChessmanBlack2IIgoChessman(IgoChessmanBlack *pInst);
void IgoChessmanBlack_Free(IgoChessmanBlack **ppInst);

#endif // !IGOCHESSMANBLACK_H
