
#include <stdio.h>
#include "CipherMachine.h"

//���ԡ���������

struct CipherMachine_Fld
{
    apr_pool_t *m_pPool;
};

static char *Encrypt(CipherMachine *pInst, const char *pPlainText, apr_pool_t *pPool)
{
    puts("���ݼ��ܣ�ת��Ϊ���ġ�");

    size_t szLen = strlen(pPlainText);
    char *pEncrypted = apr_palloc(pPool, szLen - 1/* '\0' */);
    *(pEncrypted + szLen) = '\0';
    int nKey = 10;
    int nIndex = 0;
    for (size_t i = 0; i < szLen; i++)
    {
        int nTmp = (int)*(pPlainText + i);
        //Сд��ĸ��λ
        if (*(pPlainText + i) >= 'a' && *(pPlainText + i) <= 'z')
        {
            nTmp += nKey % 26;
            if (nTmp > 122)
            {
                nTmp -= 26;
            }
            if (nTmp < 97)
            {
                nTmp += 26;
            }
        }
        //��д��ĸ��λ
        if (*(pPlainText + i) >= 'A' && *(pPlainText + i) <= 'Z')
        {
            nTmp += nKey % 26;
            if (nTmp > 90)
            {
                nTmp -= 26;
            }
            if (nTmp < 65)
            {
                nTmp += 26;
            }
        }

        *(pEncrypted + nIndex++) = (char)nTmp;
    }
    fprintf(stdout, "���ܺ�: %s", pEncrypted);

    return pEncrypted;
}

CipherMachine * CipherMachine_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    CipherMachine *pInst = apr_palloc(pPool, sizeof(CipherMachine));

    pInst->pFld = apr_palloc(pPool, sizeof(CipherMachine_Fld));
    pInst->pFld->m_pPool = pPool;

    pInst->Encrypt = Encrypt;

    return pInst;
}

void CipherMachine_Free(CipherMachine ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
