
#include <stdio.h>
#include <apr_strings.h>
#include "ImageFile.h"

//��������������

struct ImageFile_Fld
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
    ImageFile_Free(&(ImageFile *)(*ppFile)->pImplicit);
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
    ImageFile *pInst = (ImageFile *)pFile->pImplicit;

    //ģ���ͼƬ�ļ�����ɱ��
    printf("��ͼƬ�ļ�%s����ɱ����\n", pInst->pFld->m_pName);
}

ImageFile * ImageFile_New(apr_pool_t * pSupPool, const char * const pName)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ImageFile *pInst = apr_palloc(pPool, sizeof(ImageFile));
    
    pInst->pFld = apr_palloc(pPool, sizeof(ImageFile_Fld));
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

IFile * ImageFile2IFile(ImageFile * pInst)
{
    return &(pInst->pFld->m_file);
}

void ImageFile_Free(ImageFile ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
