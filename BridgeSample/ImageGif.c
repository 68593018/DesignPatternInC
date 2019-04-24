
#include <stdio.h>
#include "ImageGif.h"


struct ImageGif_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //ʵ�ֽӿ�
    IImage m_image;

    //�Ž���ʵ��ָ��
    IImageImp *m_pBridge;
};

static void Free(IImage **ppImage)
{
    ImageGif_Free(&(ImageGif *)(*ppImage)->pImplicit);
    *ppImage = NULL;
}

static void SetImageImp(IImage *pImage, IImageImp *pImgImp)
{
    ((ImageGif *)pImage->pImplicit)->pFld->m_pBridge = pImgImp;
}
static void ParseFile(IImage *pImage, const char *const pFileName)
{
    ImageGif *pInst = (ImageGif *)pImage->pImplicit;

    //�����ļ�����Ϊͼ�����ؾ���
    Matrix *mat = Matrix_New(pInst->pFld->m_pPool);
    printf("����Gifͼ���Ϊ���ؾ����");

    //�����Žӷ�������ָ����ƽ̨�ϻ���ͼ�����ؾ���
    pInst->pFld->m_pBridge->DoPaint(pInst->pFld->m_pBridge, mat);

    Matrix_Free(&mat);
}

ImageGif * ImageGif_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    ImageGif *pInst = apr_palloc(pPool, sizeof(ImageGif));

    pInst->pFld = apr_palloc(pPool, sizeof(ImageGif_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_image.pImplicit = pInst;
    pInst->pFld->m_image.Free = Free;

    pInst->pFld->m_image.SetImageImp = SetImageImp;
    pInst->pFld->m_image.ParseFile = ParseFile;

    //�ŽӶ���ָ��
    pInst->pFld->m_pBridge = NULL;

    return pInst;
}

IImage * ImageGif2IImage(ImageGif * pInst)
{
    return &(pInst->pFld->m_image);
}

void ImageGif_Free(ImageGif ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
