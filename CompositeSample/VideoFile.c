
#include <stdio.h>
#include <apr_strings.h>
#include "VideoFile.h"

//���ԡ���������
struct VideoFile_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    IFile m_file;

    char *m_pName;
};

//ʵ�ֽӿڷ���
static void Free(IFile **ppFile)
{
    VideoFile_Free(&(VideoFile *)(*ppFile)->pImplicit);
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
    VideoFile *pInst = (VideoFile *)pFile->pImplicit;

    //ģ��ɱ��
    printf("����Ƶ�ļ�%s����ɱ��.\n", pInst->pFld->m_pName);
}

VideoFile * VideoFile_New(apr_pool_t * pSupPool, const char * const pName)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    VideoFile *pInst = apr_palloc(pPool, sizeof(VideoFile));
    
    pInst->pFld = apr_palloc(pPool, sizeof(VideoFile_Fld));
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

IFile * VideoFile2IFile(VideoFile * pInst)
{
    return &(pInst->pFld->m_file);
}

void VideoFile_Free(VideoFile ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
