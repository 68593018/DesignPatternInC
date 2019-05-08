
#include <stdio.h>
#include "ImageImpUnix.h"


struct ImageImpUnix_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	//�̳нӿڣ�ֻ�������ɱ������ɣ�����������ָ��
	IImageImp m_imageImp;
};

static void Free(IImageImp **ppImageImp)
{
    ImageImpUnix_Free(&(ImageImpUnix *)(*ppImageImp)->pImplicit);
    *ppImageImp = NULL;
}

//ʵ�ֽӿڵķ���
static void DoPaint(IImageImp *pImageImp, Matrix *pMat)
{
    //UnixImp *pInst = (UnixImp *)pImgImp->pImplicit;
	puts("��Unixƽ̨�ϻ���ͼƬ���ؾ���.");
}

ImageImpUnix * ImageImpUnix_New(apr_pool_t *pSubPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSubPool);

    ImageImpUnix *pInst = apr_palloc(pPool, sizeof(ImageImpUnix));

	pInst->pFld = apr_palloc(pPool, sizeof(ImageImpUnix_Fld));
	pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_imageImp.pImplicit = pInst;
    pInst->pFld->m_imageImp.Free = Free;
	
	pInst->pFld->m_imageImp.DoPaint = DoPaint;

	return pInst;
}

IImageImp * ImageImpUnix2IImageImp(ImageImpUnix * pInst)
{
	return &(pInst->pFld->m_imageImp);
}

void ImageImpUnix_Free(ImageImpUnix ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
