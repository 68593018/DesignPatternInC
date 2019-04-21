
#include <apr_pools.h>
#include "IChart.h"


#ifndef HISTOGRAMCHART_H
#define HISTOGRAMCHART_H

typedef struct HistogramChart_Fld HistogramChart_Fld;
typedef struct HistogramChart HistogramChart;

struct HistogramChart
{
	HistogramChart_Fld *pFld;

	//�̳нӿڣ�����Ҫ��ʽ�����̳��Խӿڵķ�����
	//�����൱�ڹ涨
	//������ü̳��Խӿڵķ������򽫸�ʵ��ת��Ϊ�ӿ�����
	//Ҳ��ֻ�ṩ��һ�ֽӿڷ������÷�ʽ
};

HistogramChart *const HistogramChart_New(apr_pool_t *pSupPool);
IChart *const HistogramChart2IChart(HistogramChart *pInst);
void HistogramChart_Free(HistogramChart **ppInst);

#endif // !HISTOGRAMCHART_H
