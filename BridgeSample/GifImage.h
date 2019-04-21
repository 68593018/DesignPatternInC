
#include <apr_pools.h>
#include "Image.h"


#ifndef GIFIMAGE_H
#define GIFIMAGE_H

typedef struct GifImage_Fld GifImage_Fld;
typedef struct GifImage GifImage;

struct GifImage
{
    GifImage_Fld *pFld;

    //ʵ�ֽӿڣ�ͨ���ӿڵ��ã�
    //���������Ĺ�������
};

GifImage *GifImage_New(apr_pool_t *pSupPool);
Image *GifImage2Image(GifImage *pInst);
void GifImage_Free(GifImage **ppInst);

#endif // !GIFIMAGE_H
