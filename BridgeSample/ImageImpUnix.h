
#include <apr_pools.h>
#include "IImageImp.h"


#ifndef IMAGEIMPUNIX_H
#define IMAGEIMPUNIX_H

typedef struct ImageImpUnix_Fld ImageImpUnix_Fld;
typedef struct ImageImpUnix ImageImpUnix;

struct ImageImpUnix
{
    ImageImpUnix_Fld *pFld;

	//ʵ�ֽӿڣ�ͨ���ӿڵ��ã����û�й�������
};

ImageImpUnix *ImageImpUnix_New(apr_pool_t *pSubPool);
IImageImp *ImageImpUnix2IImageImp(ImageImpUnix *pInst);
void ImageImpUnix_Free(ImageImpUnix **ppInst);

#endif // !IMAGEIMPUNIX_H
