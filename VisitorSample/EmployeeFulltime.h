
#include <apr_pools.h>
#include "IEmployee.h"


#ifndef EMPLOYEEFULLTIME_H
#define EMPLOYEEFULLTIME_H

typedef struct EmployeeFulltime_Fld EmployeeFulltime_Fld;
typedef struct EmployeeFulltime EmployeeFulltime;

struct EmployeeFulltime
{
	EmployeeFulltime_Fld *pFld;

	//�̳нӿ�IEmployee��
	//��������Ҫ����Բ�ͨ���ӿڷ��ʣ���ͨ���ӿ�ʵ����Ҳ���Է���ʵ����
	//��ˣ�������ʵ���������ӹ�������
	char *(* GetName)(EmployeeFulltime *pInst, apr_pool_t *pPool);
	void (* SetName)(EmployeeFulltime *pInst, const char *pName);
	double (* GetWeeklyWage)(EmployeeFulltime *pInst);
	void (* SetWeeklyWage)(EmployeeFulltime *pInst, double dblWeeklyWage);
	int (* GetWorkTime)(EmployeeFulltime *pInst);
	void (* SetWorkTime)(EmployeeFulltime *pInst, int nWorkTime);
};

EmployeeFulltime *EmployeeFulltime_New(apr_pool_t *pSupPool, const char *pName, double dblWeeklyWage, int nWorkTime);
IEmployee *EmployeeFulltime2IEmployee(EmployeeFulltime *pInst);
void EmployeeFulltime_Free(EmployeeFulltime **ppInst);

#endif // !EMPLOYEEFULLTIME_H
