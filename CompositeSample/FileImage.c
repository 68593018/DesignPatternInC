
#include <stdio.h>
#include <apr_strings.h>
#include "FileImage.h"

//��������������

struct FileImage_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IFile m_file;

    //�ļ�����
    char *m_pName;
};

//ʵ�ֽӿڷ���
static void Free(IFile **ppFile)
{
	FileImage_Free(&(FileImage *)(*ppFile)->pImplicit);
    *ppFile = NULL;
}

//ʵ�ֽӿڷ���
static void Add(IFile *pFile, IFile *pAdd)
{
    puts("ͼ���ļ���֧��������ļ�������");
}

//ʵ�ֽӿڷ���
static void Remove(IFile *pFile, IFile *pRmv)
{
    puts("ͼ���ļ���֧��ɾ�����ļ�������");
}

//ʵ�ֽӿڷ���
static IFile *GetChild(IFile *pFile, int nIndex)
{
    puts("ͼ���ļ����������ļ���");
    return NULL;
}

static void KillVirus(IFile *pFile)
{
	FileImage *pInst = (FileImage *)pFile->pImplicit;

    //ģ���ͼƬ�ļ�����ɱ��
    printf("��ͼƬ�ļ�%s����ɱ����\n", pInst->pFld->m_pName);
}

FileImage * FileImage_New(apr_pool_t * pSupPool, const char * const pName)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

	FileImage *pInst = apr_palloc(pPool, sizeof(FileImage));
    
    pInst->pFld = apr_palloc(pPool, sizeof(FileImage_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_file.pImplicit = pInst;
    pInst->pFld->m_file.Free = Free;
    pInst->pFld->m_pName = apr_pstrdup(pPool, pName);

    pInst->pFld->m_file.Add = Add;
    pInst->pFld->m_file.Remove = Remove;
    pInst->pFld->m_file.GetChild = GetChild;
    pInst->pFld->m_file.KillVirus = KillVirus;

    return pInst;
}

IFile * FileImage2IFile(FileImage * pInst)
{
    return &(pInst->pFld->m_file);
}

void FileImage_Free(FileImage ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
