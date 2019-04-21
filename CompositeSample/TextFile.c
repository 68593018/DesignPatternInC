
#include <stdio.h>
#include <apr_strings.h>
#include "TextFile.h"

//���ԡ���������

struct TextFile_Fld
{
    apr_pool_t *m_pPool;

    IFile m_file;

    char *m_pName;
};

//ʵ�ֽӿڷ���
static void Free(IFile **ppFile)
{
    TextFile_Free(&(TextFile *)(*ppFile)->pImplicit);
    *ppFile = NULL;
}

//ʵ�ֽӿڷ���
static void Add(IFile *pFile, IFile *pAdd)
{
    puts("�ı��ļ���֧��������ļ�������");
}

//ʵ�ֽӿڷ���
static void Remove(IFile *pFile, IFile *pRmv)
{
    puts("�ı��ļ���֧���Ƴ����ļ�����.");
}

//ʵ�ֽӿڷ���
static IFile *GetChild(IFile *pFile, int nIndex)
{
    puts("�ı��ļ���֧�ֻ�ȡ���ļ�������");
    return NULL;
}

//ʵ�ֽӿڷ���
static void KillVirus(IFile *pFile)
{
    TextFile *pInst = (TextFile *)pFile->pImplicit;

    //ģ��ɱ��
    printf("���ı�%s����ɱ����\n", pInst->pFld->m_pName);
}

TextFile * TextFile_New(apr_pool_t * pSupPool, const char * const pName)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    TextFile *pInst = apr_palloc(pPool, sizeof(TextFile));

    pInst->pFld = apr_palloc(pPool, sizeof(TextFile_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_file.pImplicit = pInst;
    pInst->pFld->m_file.Free = Free;
    pInst->pFld->m_pName = apr_pstrdup(pInst->pFld->m_pPool, pName);

    pInst->pFld->m_file.Add = Add;
    pInst->pFld->m_file.Remove = Remove;
    pInst->pFld->m_file.GetChild = GetChild;
    pInst->pFld->m_file.KillVirus = KillVirus;

    return pInst;
}

IFile * TextFile2IFile(TextFile * pInst)
{
    return &(pInst->pFld->m_file);
}

void TextFile_Free(TextFile ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
