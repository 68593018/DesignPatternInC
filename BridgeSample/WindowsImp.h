
#include <apr_pools.h>
#include "ImageImp.h"


#ifndef WINDOWSIMP_H
#define WINDOWSIMP_H

typedef struct WindowsImp_Fld WindowsImp_Fld;
typedef struct WindowsImp WindowsImp;

struct WindowsImp
{
	WindowsImp_Fld *pFld;

	//ʵ�ֽӿڣ�ͨ���ӿڵ��ã�
	//���ṩ���з���
};

WindowsImp *WindowsImp_New(apr_pool_t *pSupPool);
ImageImp *WindowsImp2ImageImp(WindowsImp *pInst);
void WindowsImp_Free(WindowsImp **ppInst);

#endif // !WINDOWSIMP_H

