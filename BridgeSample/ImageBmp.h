
#include <apr_pools.h>
#include "IImage.h"


#ifndef IMAGEBMP_H
#define IMAGEBMP_H

typedef struct ImageBmp_Fld ImageBmp_Fld;
typedef struct ImageBmp ImageBmp;

struct ImageBmp
{
    ImageBmp_Fld *pFld;

	//ʵ�ֽӿڣ�ͨ���ӿڵ��ø���ʵ����
	//û�й��з���
};

ImageBmp *ImageBmp_New(apr_pool_t *pSupPool);
IImage *ImageBmp2IImage(ImageBmp *pInst);
void ImageBmp_Free(ImageBmp **ppInst);

#endif // !IMAGEBMP_H
