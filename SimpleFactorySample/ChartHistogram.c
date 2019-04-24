
#include "ChartHistogram.h"

struct ChartHistogram_Fld
{
	apr_pool_t *m_pPool;

	//�̳нӿڣ��ӿڽṹ���ͱ�������
	IChart m_chart;
};

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

	ChartHistogram_Free(&(ChartHistogram *)(*ppchart)->pImplicit);
	*ppchart = NULL;
}

//�̳нӿڣ�ʵ�ַ���
static void Display()
{
	printf("��ʾ��״ͼ��");
}

ChartHistogram *ChartHistogram_New(apr_pool_t *pSupPool)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	ChartHistogram *pInst = apr_palloc(pPool, sizeof(ChartHistogram));
	
	pInst->pFld = apr_palloc(pPool, sizeof(ChartHistogram_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_chart.pImplicit = pInst;
	pInst->pFld->m_chart.Free = Free;

	pInst->pFld->m_chart.Display = Display;

	return pInst;
}

IChart *ChartHistogram2IChart(ChartHistogram * pInst)
{
	return &(pInst->pFld->m_chart);
}

void ChartHistogram_Free(ChartHistogram ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);
	*ppInst = NULL;
}
