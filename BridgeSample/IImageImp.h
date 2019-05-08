
#include "Matrix.h"

#ifndef IIMAGEIMP_H
#define IIMAGEIMP_H

typedef struct IImageImp IImageImp;

//�ڱ������У���Ϊ�ŽӶ���ӿ�
struct IImageImp
{
    //ʵ���Žӽӿڵ����ʵ��ָ��
	void *pImplicit;

    //��Ϊ�ŽӶ����ҵ�񷽷����Բ�ͬ��ʽͼƬ�������ͼ�����ؾ���Ϊ������
    //ʵ���ڲ�ͬƽ̨�ϻ���ͼ�����ؾ���
	void (* DoPaint)(IImageImp *pImageImp, Matrix *pMat);

    //�ͷ��Ž����ʵ��
	void (* Free)(IImageImp **ppImageImp);
};

#endif // !IIMAGEIMP_H
