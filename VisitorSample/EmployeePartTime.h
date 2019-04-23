
#include <apr_pools.h>
#include "IEmployee.h"


#ifndef EMPLOYEEPARTTIME_H
#define EMPLOYEEPARTTIME_H

typedef struct EmployeePartTime_Fld EmployeePartTime_Fld;
typedef struct EmployeePartTime EmployeePartTime;

struct EmployeePartTime
{
	EmployeePartTime_Fld *pFld;

	//�̳нӿ�IEmployee��
	//��������Ҫ�����ͨ���ӿ�ʵ�������ʵ����
	//���������ӹ�������
	char *(* GetName)(EmployeePartTime *pInst, apr_pool_t *pPool);
	void (* SetName)(EmployeePartTime *pInst, const char *pName);
	double (* GetHourWage)(EmployeePartTime *pInst);
	void (* SetHourWage)(EmployeePartTime *pInst, double dblHourWage);
	int (* GetWorkTime)(EmployeePartTime *pInst);
	void (* SetWorkTime)(EmployeePartTime *pInst, int nWorkTime);
};

EmployeePartTime *EmployeePartTime_New(apr_pool_t *pSupPool, const char *pName, double dblHourWage, int nWorkTime);
IEmployee *EmployeePartTime2IEmployee(EmployeePartTime *pInst);
void EmployeePartTime_Free(EmployeePartTime **ppInst);

#endif // !EMPLOYEEPARTTIME_H
