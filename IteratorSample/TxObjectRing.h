
#include <apr_ring_ext.h>


#ifndef TXOBJECTRING_H
#define TXOBJECTRING_H

//����void����Ϊobject���ͣ�
//��������ֻ����ʱ�����object���ͣ�
//��ˣ��Ӹ�ǰ׺Tx
typedef void TxObject;

//����ʵ�����õ��ľ������ͻ�������
//���ھۺ��࣬Ҳ����IAggregate�ӿڵ�ʵ���� �ڲ��洢��������
GENERIC_RING(TxObject)

#endif // !TXOBJECTRING_H
