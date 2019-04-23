
#include <apr_pools.h>
#include "IImageImp.h"


#ifndef IMAGEIMPWINDOWS_H
#define IMAGEIMPWINDOWS_H

typedef struct ImageImpWindows_Fld ImageImpWindows_Fld;
typedef struct ImageImpWindows ImageImpWindows;

struct ImageImpWindows
{
    ImageImpWindows_Fld *pFld;

	//ʵ�ֽӿڣ�ͨ���ӿڵ��ã�
	//���ṩ���з���
};

ImageImpWindows *ImageImpWindows_New(apr_pool_t *pSupPool);
IImageImp *ImageImpWindows2IImageImp(ImageImpWindows *pInst);
void ImageImpWindows_Free(ImageImpWindows **ppInst);

#endif // !IMAGEIMPWINDOWS_H

