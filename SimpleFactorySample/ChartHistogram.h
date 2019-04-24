
#include <apr_pools.h>
#include "IChart.h"


#ifndef CHARTHISTOGRAM_H
#define CHARTHISTOGRAM_H

typedef struct ChartHistogram_Fld ChartHistogram_Fld;
typedef struct ChartHistogram ChartHistogram;

struct ChartHistogram
{
	ChartHistogram_Fld *pFld;

	//�̳нӿڣ�����Ҫ��ʽ�����̳��Խӿڵķ�����
	//�����൱�ڹ涨
	//������ü̳��Խӿڵķ������򽫸�ʵ��ת��Ϊ�ӿ�����
	//Ҳ��ֻ�ṩ��һ�ֽӿڷ������÷�ʽ
};

ChartHistogram *ChartHistogram_New(apr_pool_t *pSupPool);
IChart *ChartHistogram2IChart(ChartHistogram *pInst);
void ChartHistogram_Free(ChartHistogram **ppInst);

#endif // !CHARTHISTOGRAM_H
