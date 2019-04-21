
#include <stdio.h>
#include "UnixImp.h"


struct UnixImp_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	//�̳нӿڣ�ֻ�������ɱ������ɣ�����������ָ��
	ImageImp m_ImgImp;
};

static void Free(ImageImp **ppImgImp)
{
    UnixImp_Free(&(UnixImp *)(*ppImgImp)->pImplicit);
    *ppImgImp = NULL;
}

//ʵ�ֽӿڵķ���
static void DoPaint(ImageImp *pImgImp, Matrix *mat)
{
    //UnixImp *pInst = (UnixImp *)pImgImp->pImplicit;
	puts("��Unixƽ̨�ϻ���ͼƬ���ؾ���.");
}

UnixImp * UnixImp_New(apr_pool_t *pSubPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSubPool);

	UnixImp *pInst = (UnixImp *)apr_palloc(pPool, sizeof(UnixImp));

	pInst->pFld = (UnixImp_Fld *)apr_palloc(pPool, sizeof(UnixImp_Fld));
	pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_ImgImp.pImplicit = pInst;
    pInst->pFld->m_ImgImp.Free = Free;
	
	pInst->pFld->m_ImgImp.DoPaint = DoPaint;

	return pInst;
}

ImageImp * UnixImp2ImageImp(UnixImp * pInst)
{
	return &(pInst->pFld->m_ImgImp);
}

void UnixImp_Free(UnixImp ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

	*ppInst = NULL;
}
