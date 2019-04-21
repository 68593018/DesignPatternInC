
#include <apr_pools.h>
#include "IEncryptFacade.h"


#ifndef ENHANCEDENCRYPTFACADE_H
#define ENHANCEDENCRYPTFACADE_H

typedef struct EnhancedEncryptFacade_Fld EnhancedEncryptFacade_Fld;
typedef struct EnhancedEncryptFacade EnhancedEncryptFacade;

struct EnhancedEncryptFacade
{
    EnhancedEncryptFacade_Fld *pFld;

    //�̳нӿڣ�����ӿڱ��룬
    //��ˣ��ӿڵĹ�����������Ҫ�ڴ�����
};

EnhancedEncryptFacade *EnhancedEncryptFacade_New(apr_pool_t *pSupPool);
IEncryptFacade *EnhancedEncryptFacade2IEncryptFacade(EnhancedEncryptFacade *pInst);
void EnhancedEncryptFacade_Free(EnhancedEncryptFacade **ppInst);

#endif // !ENHANCEDENCRYPTFACADE_H
