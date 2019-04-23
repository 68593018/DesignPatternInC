
#include "IImageImp.h"

#ifndef IIMAGE_H
#define IIMAGE_H

typedef struct IImage IImage;

struct IImage
{
    void *pImplicit;

    //�����ŽӶ��󣬷������һ��ά��(��������У�Ϊ��ͬ��ƽ̨��ͼ�����ؾ���Ļ��Ʒ���)
    //�ⲿ�����ͷ��ŽӶ���
	void (* SetImageImp)(IImage *pImage, IImageImp *pImageImp);

    //���������һ��ά��(��������У�Ϊ��ͬ��ʽͼƬ�ļ��Ľ�������)
	void (* ParseFile)(IImage *pImage, const char *const pFileName);

    void (* Free)(IImage **ppImage);
};

#endif // !IIMAGE_H
