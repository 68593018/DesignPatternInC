
#include "Matrix.h"

#ifndef IMAGEIMP_H
#define IMAGEIMP_H

typedef struct ImageImp ImageImp;

//�ڱ������У���Ϊ�ŽӶ���ӿ�
struct ImageImp
{
    //ʵ���Žӽӿڵ����ʵ��ָ��
	void *pImplicit;

    //��Ϊ�ŽӶ����ҵ�񷽷����Բ�ͬ��ʽͼƬ�������ͼ�����ؾ���Ϊ������
    //ʵ���ڲ�ͬƽ̨�ϻ���ͼ�����ؾ���
	void (* DoPaint)(ImageImp *pInst, Matrix *mat);

    //�ͷ��Ž����ʵ��
	void (* Free)(ImageImp **ppImgImp);
};

#endif // !IMAGEIMP_H
