
#include "IIterator.h"
#include "TxObjectRing.h"

#ifndef IAGGREGATE_H
#define IAGGREGATE_H

typedef struct IAggregate IAggregate;

struct IAggregate
{
    void *pImplicit;

    //��ȡ�ڲ��洢����Ļ�
    RING(TxObject) *(* GetTxObjects)(IAggregate *pAggregate);
    //�����ڲ��洢����Ļ�
    void (* SetTxObjects)(IAggregate *pAggregate, RING(TxObject) *pTxObjects);

    //�����������ķ���
    IIterator *(* CreateIterator)(IAggregate *pAggregate);

    void (* Free)(IAggregate **ppAggregate);
};

#endif // !IAGGREGATE_H
