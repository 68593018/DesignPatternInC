
#ifndef ICHART_H
#define ICHART_H

typedef struct IChart IChart;

struct IChart
{
	//ʵ�ֽӿڵ������͵Ķ���ָ�롣ʵ������ָ��
	void *pImplicit;

	//�ӿڵ�ҵ���߼���Լ������Ĳ���
	void (*Display)();

	//�ͷŽӿڶ�Ӧ��ʵ��
	void (* Free)(IChart **ppchart);
};

#endif // !ICHART_H
