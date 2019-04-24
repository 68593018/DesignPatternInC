
#include <stdio.h>
#include "ImageJpg.h"


struct ImageJpg_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //ʵ�ֽӿ�
    IImage m_image;

    //�Ž���ָ��
    IImageImp *m_pBridge;
};

static void Free(IImage **ppImage)
{
    ImageJpg_Free(&(ImageJpg *)(*ppImage)->pImplicit);
    *ppImage = NULL;
}

static void SetImageImp(IImage *pImage, IImageImp *pImgImp)
{
    //ע���Ž���ʵ��
    ((ImageJpg *)pImage->pImplicit)->pFld->m_pBridge = pImgImp;
}
static void ParseFile(IImage *pImage, const char *const pFileName)
{
    ImageJpg *pInst = (ImageJpg *)pImage->pImplicit;

    //ģ�����ͼƬ����Ϊͼ�����ؾ���
    Matrix *mat = Matrix_New(pInst->pFld->m_pPool);
    puts("����jpg��ʽͼ��Ϊ���ؾ����");

    //�����Ž���ʵ���ķ�����ʵ���ڲ�ͬ��ƽ̨�ϻ���ͼ�����ؾ���
    pInst->pFld->m_pBridge->DoPaint(pInst->pFld->m_pBridge, mat);

    Matrix_Free(&mat);
}

ImageJpg * ImageJpg_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ImageJpg *pInst = apr_palloc(pPool, sizeof(ImageJpg));

    pInst->pFld = apr_palloc(pPool, sizeof(ImageJpg_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_image.pImplicit = pInst;
    pInst->pFld->m_image.Free = Free;

    pInst->pFld->m_image.SetImageImp = SetImageImp;
    pInst->pFld->m_image.ParseFile = ParseFile;
    
    //�Ž���ʵ��ָ������ʼ��Ϊnull
    pInst->pFld->m_pBridge = NULL;

    return pInst;
}

IImage * ImageJpg2IImage(ImageJpg * pInst)
{
    return &(pInst->pFld->m_image);
}

void ImageJpg_Free(ImageJpg ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
