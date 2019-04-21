
#include <apr_pools.h>
#include "Image.h"


#ifndef JPGIMAGE_H
#define JPGIMAGE_H

typedef struct JpgImage_Fld JpgImage_Fld;
typedef struct JpgImage JpgImage;

struct JpgImage
{
    JpgImage_Fld *pFld;

    //ʵ�ֽӿڣ���˲���Ҫ���幫������
};

JpgImage *JpgImage_New(apr_pool_t *pSupPool);
Image *JpgImage2Image(JpgImage *pInst);
void JpgImage_Free(JpgImage **ppInst);

#endif // !JPGIMAGE_H
