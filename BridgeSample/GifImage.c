
#include <stdio.h>
#include "GifImage.h"


struct GifImage_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //ʵ�ֽӿ�
    Image m_img;

    //�Ž���ʵ��ָ��
    ImageImp *m_pImgImp;
};

static void Free(Image **ppImg)
{
    GifImage_Free(&(GifImage *)(*ppImg)->pImplicit);
    *ppImg = NULL;
}

static void SetImageImp(Image *pImg, ImageImp *pImgImp)
{
    ((GifImage *)pImg->pImplicit)->pFld->m_pImgImp = pImgImp;
}
static void ParseFile(Image *pImg, const char *const pFileName)
{
    GifImage *pInst = (GifImage *)pImg->pImplicit;

    //�����ļ�����Ϊͼ�����ؾ���
    Matrix *mat = Matrix_New(pInst->pFld->m_pPool);
    printf("����Gifͼ���Ϊ���ؾ����");

    //�����Žӷ�������ָ����ƽ̨�ϻ���ͼ�����ؾ���
    pInst->pFld->m_pImgImp->DoPaint(pInst->pFld->m_pImgImp, mat);

    ////Matrix��ʵ����GifImage���ڴ���д�����
    ////��GifImage��ʵ�����ٶ�����
    ////��˿ɲ��������ͷ�
    //Matrix_Free(&mat);
}

GifImage * GifImage_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    GifImage *pInst = (GifImage *)apr_palloc(pPool, sizeof(GifImage));

    pInst->pFld = (GifImage_Fld *)apr_palloc(pPool, sizeof(GifImage_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_img.pImplicit = pInst;
    pInst->pFld->m_img.Free = Free;

    //�ŽӶ���ָ��
    pInst->pFld->m_pImgImp = NULL;

    pInst->pFld->m_img.SetImageImp = SetImageImp;
    pInst->pFld->m_img.ParseFile = ParseFile;

    return pInst;
}

Image * GifImage2Image(GifImage * pInst)
{
    return &(pInst->pFld->m_img);
}

void GifImage_Free(GifImage ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
