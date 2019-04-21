
#include <stdio.h>
#include "FileWriter.h"

//���ԡ���������

struct FileWriter_Fld
{
    apr_pool_t *m_pPool;
};

static void Write(FileWriter *pInst, const char *pEncryptedText, const char *pFileName)
{
    FILE *pFile = fopen(pFileName, "w");
    if (pFile)
    {
        fprintf(pFile, pEncryptedText);

        fclose(pFile);

        return;
    }
    else
    {
        puts("������ܺ������ʱ�����ļ�ʧ�ܡ�");
        return;
    }
}

FileWriter * FileWriter_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    FileWriter *pInst = apr_palloc(pPool, sizeof(FileWriter));

    pInst->pFld = apr_palloc(pPool, sizeof(FileWriter_Fld));
    pInst->pFld->m_pPool = pPool;

    pInst->Write = Write;

    return pInst;
}

void FileWriter_Free(FileWriter ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
