
#include <apr_pools.h>
#include "ImageImp.h"


#ifndef LINUXIMP_H
#define LINUXIMP_H

typedef struct LinuxImp_Fld LinuxImp_Fld;
typedef struct LinuxImp LinuxImp;

struct LinuxImp
{
	LinuxImp_Fld *pFld;

	//�̳нӿڣ�ͨ���ӿڵ��ã�
	//��˲����ù�������
};

LinuxImp *LinuxImp_New(apr_pool_t *pSupPool);
//�̳нӿڣ����ṩת�����ӿڵķ���
ImageImp *LinuxImp2ImageImp(LinuxImp *pInst);
void LinuxImp_Free(LinuxImp **ppInst);

#endif // !LINUXIMP_H
