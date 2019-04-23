
#include <apr_pools.h>
#include "IImage.h"


#ifndef IMAGEJPG_H
#define IMAGEJPG_H

typedef struct ImageJpg_Fld ImageJpg_Fld;
typedef struct ImageJpg ImageJpg;

struct ImageJpg
{
    ImageJpg_Fld *pFld;

    //ʵ�ֽӿڣ���˲���Ҫ���幫������
};

ImageJpg *ImageJpg_New(apr_pool_t *pSupPool);
IImage *ImageJpg2IImage(ImageJpg *pInst);
void ImageJpg_Free(ImageJpg **ppInst);

#endif // !IMAGEJPG_H
