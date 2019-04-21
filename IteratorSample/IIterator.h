
#include <stdbool.h>
#include "TxObjectRing.h"

#ifndef IITERATOR_H
#define IITERATOR_H

typedef struct IIterator IIterator;

struct IIterator
{
    void *pImplicit;

    //������һ��
    void (* Next)(IIterator *pIterator);
    //�Ƿ�Ϊ���һ��
    bool (* IsLast)(IIterator *pIterator);
    //����ǰһ��
    void (* Previous)(IIterator *pIterator);
    //�Ƿ�Ϊ��һ��
    bool (* IsFirst)(IIterator *pIterator);
    //��ȡ��һ��Ԫ��
    TxObject *(* GetNextItem)(IIterator *pIterator);
    //��ȡǰһ��Ԫ��
    TxObject *(* GetPreviousItem)(IIterator *pIterator);

    void (* Free)(IIterator **ppIterator);
};

#endif // !IITERATOR_H
