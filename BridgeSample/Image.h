
#include "ImageImp.h"

#ifndef IMAGE_H
#define IMAGE_H

typedef struct Image Image;

struct Image
{
    void *pImplicit;

    //�����ŽӶ��󣬷������һ��ά��(��������У�Ϊ��ͬ��ƽ̨��ͼ�����ؾ���Ļ��Ʒ���)
    //�ⲿ�����ͷ��ŽӶ���
	void (* SetImageImp)(Image *pInst, ImageImp *pImgImp);

    //���������һ��ά��(��������У�Ϊ��ͬ��ʽͼƬ�ļ��Ľ�������)
	void (* ParseFile)(Image *pInst, const char *const pFileName);

    void (* Free)(Image **ppImg);
};

#endif // !IMAGE_H
