
#include <stdio.h>
#include "JpgImage.h"


struct JpgImage_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    //ʵ�ֽӿ�
    Image m_img;

    //�Ž���ָ��
    ImageImp *m_pImgImp;
};

static void Free(Image **ppImg)
{
    JpgImage_Free(&(JpgImage *)(*ppImg)->pImplicit);
    *ppImg = NULL;
}

static void SetImageImp(Image *pImg, ImageImp *pImgImp)
{
    //ע���Ž���ʵ��
    ((JpgImage *)pImg->pImplicit)->pFld->m_pImgImp = pImgImp;
}
static void ParseFile(Image *pImg, const char *const pFileName)
{
    JpgImage *pInst = (JpgImage *)pImg->pImplicit;

    //ģ�����ͼƬ����Ϊͼ�����ؾ���
    Matrix *mat = Matrix_New(pInst->pFld->m_pPool);
    puts("����jpg��ʽͼ��Ϊ���ؾ����");

    //�����Ž���ʵ���ķ�����ʵ���ڲ�ͬ��ƽ̨�ϻ���ͼ�����ؾ���
    pInst->pFld->m_pImgImp->DoPaint(pInst->pFld->m_pImgImp, mat);

    //Matrix_Free(&mat);
}

JpgImage * JpgImage_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    JpgImage *pInst = (JpgImage *)apr_palloc(pPool, sizeof(JpgImage));

    pInst->pFld = (JpgImage_Fld *)apr_palloc(pPool, sizeof(JpgImage_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_img.pImplicit = pInst;
    pInst->pFld->m_img.Free = Free;
    
    //�Ž���ʵ��ָ������ʼ��Ϊnull
    pInst->pFld->m_pImgImp = NULL;

    pInst->pFld->m_img.SetImageImp = SetImageImp;
    pInst->pFld->m_img.ParseFile = ParseFile;

    return pInst;
}

Image * JpgImage2Image(JpgImage * pInst)
{
    return &(pInst->pFld->m_img);
}

void JpgImage_Free(JpgImage ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
