
#include <stdio.h>
#include "BmpImage.h"


struct BmpImage_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

	//ʵ�ֽӿ�
	Image m_Img;

	//�ŽӶ���ָ��
	ImageImp *m_pImgImp;
};

static void Free(Image **ppImg)
{
    BmpImage_Free(&(BmpImage *)(*ppImg)->pImplicit);
    *ppImg = NULL;
}

//ʵ�ֽӿڷ���
static void SetImageImp(Image *pImg, ImageImp *pImgImp)
{
    ((BmpImage *)pImg->pImplicit)->pFld->m_pImgImp = pImgImp;
}
//ʵ�ֽӿڷ���
static void ParseFile(Image *pImg, const char *const pFileName)
{
    BmpImage *pInst = (BmpImage *)pImg->pImplicit;

	//ģ�����BmpͼƬ��������Matrix����
	Matrix *mat = Matrix_New(pInst->pFld->m_pPool);

	printf("����Bmp��ʽͼƬ��");
	
	//������ɺ�ʹ���ŽӵĶ���ʵ�����д���
	pInst->pFld->m_pImgImp->DoPaint(pInst->pFld->m_pImgImp, mat);
    
    ////�����ͷ�
    //Matrix_Free(&mat);
}

BmpImage * BmpImage_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

	BmpImage *pInst = (BmpImage *)apr_palloc(pPool, sizeof(BmpImage));

	pInst->pFld = (BmpImage_Fld *)apr_palloc(pPool, sizeof(BmpImage_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_Img.pImplicit = pInst;
    pInst->pFld->m_Img.Free = Free;

    //�ŽӶ���ָ��
	pInst->pFld->m_pImgImp = NULL;

	pInst->pFld->m_Img.SetImageImp = SetImageImp;
	pInst->pFld->m_Img.ParseFile = ParseFile;

	return pInst;
}

Image * BmpImage2Image(BmpImage * pInst)
{
	return &(pInst->pFld->m_Img);
}

void BmpImage_Free(BmpImage ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);

	*ppInst = NULL;
}
