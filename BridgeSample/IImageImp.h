
#include "Matrix.h"

#ifndef IMAGEIMP_H
#define IMAGEIMP_H

typedef struct IImageImp IImageImp;

//�ڱ������У���Ϊ�ŽӶ���ӿ�
struct IImageImp
{
    //ʵ���Žӽӿڵ����ʵ��ָ��
	void *pImplicit;

    //��Ϊ�ŽӶ����ҵ�񷽷����Բ�ͬ��ʽͼƬ�������ͼ�����ؾ���Ϊ������
    //ʵ���ڲ�ͬƽ̨�ϻ���ͼ�����ؾ���
	void (* DoPaint)(IImageImp *pImageImp, Matrix *mat);

    //�ͷ��Ž����ʵ��
	void (* Free)(IImageImp **ppImageImp);
};

#endif // !IMAGEIMP_H
