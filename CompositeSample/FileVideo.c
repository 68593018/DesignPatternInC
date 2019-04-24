
#include <stdio.h>
#include <apr_strings.h>
#include "FileVideo.h"

//���ԡ���������
struct FileVideo_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IFile m_file;

    char *m_pName;
};

//ʵ�ֽӿڷ���
static void Free(IFile **ppFile)
{
	FileVideo_Free(&(FileVideo *)(*ppFile)->pImplicit);
    *ppFile = NULL;
}

//ʵ�ֽӿڷ���
static void Add(IFile *pFile, IFile *pAdd)
{
    puts("��Ƶ�ļ���֧��������ļ�������");
}

//ʵ�ֽӿڷ���
static void Remove(IFile *pFile, IFile *pRmv)
{
    puts("��Ƶ�ļ���֧��ɾ�����ļ�������");
}

//ʵ�ֽӿڷ���
static IFile *GetChild(IFile *pFile, int nIndex)
{
    puts("��Ƶ�ļ���֧�ֻ�ȡ���ļ�������");
    return NULL;
}

//ʵ�ֽӿڷ���
static void KillVirus(IFile *pFile)
{
	FileVideo *pInst = (FileVideo *)pFile->pImplicit;

    //ģ��ɱ��
    printf("����Ƶ�ļ�%s����ɱ��.\n", pInst->pFld->m_pName);
}

FileVideo * FileVideo_New(apr_pool_t * pSupPool, const char * const pName)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

	FileVideo *pInst = apr_palloc(pPool, sizeof(FileVideo));
    
    pInst->pFld = apr_palloc(pPool, sizeof(FileVideo_Fld));
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

IFile * FileVideo2IFile(FileVideo * pInst)
{
    return &(pInst->pFld->m_file);
}

void FileVideo_Free(FileVideo ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
