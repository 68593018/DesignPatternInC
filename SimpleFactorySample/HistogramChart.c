#include "HistogramChart.h"


static void Display();
static void Free(IChart **ppchart);

struct HistogramChart_Fld
{
	apr_pool_t *m_pPool;

	//�̳нӿڣ��ӿڽṹ���ͱ�������
	IChart m_chart;
};

//�̳нӿڣ�ʵ�ַ���
static void Display()
{
	printf("��ʾ��״ͼ��");
}

//�̳нӿڣ�ʵ�ַ���
static void Free(IChart **ppchart)
{
	if (!ppchart || !(*ppchart))
	{
		return;
	}

	/*����ע����2019��1��д�ģ�˵���������뵱ǰ���뱾����أ�������ֻ��Ϊ�������Լ���Ҫע��һЩ����*/
	//!!!!!!!!!!!!������������
	//HistogramChart_Free(&((HistogramChart *)(pchart->pImplicit)));
	//�����ᵼ�����ͷ�������ռ���ڴ�֮ǰ���ͷ�����ָ�뱻��Ϊ���ա��������޷���ȫ�ͷš�

	HistogramChart_Free(&(HistogramChart *)(*ppchart)->pImplicit);
	*ppchart = NULL;
}

HistogramChart *const HistogramChart_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	HistogramChart *pInst = (HistogramChart *)apr_palloc(pPool, sizeof(HistogramChart));
	
	pInst->pFld = (HistogramChart_Fld *)apr_palloc(pPool, sizeof(HistogramChart_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_chart.pImplicit = pInst;
	pInst->pFld->m_chart.Free = Free;

	pInst->pFld->m_chart.Display = Display;

	return pInst;
}

IChart * const HistogramChart2IChart(HistogramChart * pInst)
{
	return &(pInst->pFld->m_chart);
}

void HistogramChart_Free(HistogramChart ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

	*ppInst = NULL;
}
