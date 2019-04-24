
#include <stdio.h>
#include "ImageBmp.h"


struct ImageBmp_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

	//ʵ�ֽӿ�
	IImage m_image;

	//�ŽӶ���ָ��
	IImageImp *m_pBridge;
};

static void Free(IImage **ppImage)
{
    ImageBmp_Free(&(ImageBmp *)(*ppImage)->pImplicit);
    *ppImage = NULL;
}

//ʵ�ֽӿڷ���
static void SetImageImp(IImage *pImage, IImageImp *pImgImp)
{
    ((ImageBmp *)pImage->pImplicit)->pFld->m_pBridge = pImgImp;
}
//ʵ�ֽӿڷ���
static void ParseFile(IImage *pImage, const char *const pFileName)
{
    ImageBmp *pInst = (ImageBmp *)pImage->pImplicit;

	//ģ�����BmpͼƬ��������Matrix����
	Matrix *mat = Matrix_New(pInst->pFld->m_pPool);

	printf("����Bmp��ʽͼƬ��");
	
	//������ɺ�ʹ���ŽӵĶ���ʵ�����д���
	pInst->pFld->m_pBridge->DoPaint(pInst->pFld->m_pBridge, mat);
    
    Matrix_Free(&mat);
}

ImageBmp * ImageBmp_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

	ImageBmp *pInst = apr_palloc(pPool, sizeof(ImageBmp));

	pInst->pFld = apr_palloc(pPool, sizeof(ImageBmp_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_image.pImplicit = pInst;
    pInst->pFld->m_image.Free = Free;

	pInst->pFld->m_image.SetImageImp = SetImageImp;
	pInst->pFld->m_image.ParseFile = ParseFile;

    //�ŽӶ���ָ��
	pInst->pFld->m_pBridge = NULL;

	return pInst;
}

IImage * ImageBmp2IImage(ImageBmp * pInst)
{
	return &(pInst->pFld->m_image);
}

void ImageBmp_Free(ImageBmp ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
