
#include <apr_pools.h>
#include "IImageImp.h"


#ifndef IMAGEIMPLINUX_H
#define IMAGEIMPLINUX_H

typedef struct ImageImpLinux_Fld ImageImpLinux_Fld;
typedef struct ImageImpLinux ImageImpLinux;

struct ImageImpLinux
{
    ImageImpLinux_Fld *pFld;

	//�̳нӿڣ�ͨ���ӿڵ��ã�
	//��˲����ù�������
};

ImageImpLinux *ImageImpLinux_New(apr_pool_t *pSupPool);
//�̳нӿڣ����ṩת�����ӿڵķ���
IImageImp *ImageImpLinux2IImageImp(ImageImpLinux *pInst);
void ImageImpLinux_Free(ImageImpLinux **ppInst);

#endif // !IMAGEIMPLINUX_H
