
#include <apr_pools.h>
#include "IEncryptFacade.h"


#ifndef ENCRYPTFACADEENHANCED_H
#define ENCRYPTFACADEENHANCED_H

typedef struct EncryptFacadeEnhanced_Fld EncryptFacadeEnhanced_Fld;
typedef struct EncryptFacadeEnhanced EncryptFacadeEnhanced;

struct EncryptFacadeEnhanced
{
	EncryptFacadeEnhanced_Fld *pFld;

    //�̳нӿڣ�����ӿڱ��룬
    //��ˣ��ӿڵĹ�����������Ҫ�ڴ�����
};

EncryptFacadeEnhanced *EncryptFacadeEnhanced_New(apr_pool_t *pSupPool);
IEncryptFacade *EncryptFacadeEnhanced2IEncryptFacade(EncryptFacadeEnhanced *pInst);
void EncryptFacadeEnhanced_Free(EncryptFacadeEnhanced **ppInst);

#endif // !ENCRYPTFACADEENHANCED_H
