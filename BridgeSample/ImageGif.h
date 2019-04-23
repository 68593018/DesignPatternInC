
#include <apr_pools.h>
#include "IImage.h"


#ifndef IMAGEGIF_H
#define IMAGEGIF_H

typedef struct ImageGif_Fld ImageGif_Fld;
typedef struct ImageGif ImageGif;

struct ImageGif
{
    ImageGif_Fld *pFld;

    //ʵ�ֽӿڣ�ͨ���ӿڵ��ã�
    //���������Ĺ�������
};

ImageGif *ImageGif_New(apr_pool_t *pSupPool);
IImage *ImageGif2IImage(ImageGif *pInst);
void ImageGif_Free(ImageGif **ppInst);

#endif // !IMAGEGIF_H
