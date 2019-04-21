
#include <apr_ring.h>

#ifndef GENERAL_RING_H
#define GENERAL_RING_H

/*���ͻ�����*/
#define RING(elem_t) elem_t ## _ ## ring
/*��Ԫ�ص�����ָ��*/
#define RING_LINK link
/*����Ԫ������*/
#define RING_ELEM(elem_t) elem_t ## _ ## elem

/*���ͻ�����*/
#define GENERIC_RING(elem_t)							\
typedef struct elem_t ## _ ## elem elem_t ## _ ## elem;	\
struct elem_t ## _ ## elem								\
{														\
	APR_RING_ENTRY(elem_t ## _ ## elem) RING_LINK;		\
	elem_t *pInst;										\
};														\
														\
typedef struct elem_t ## _ ## ring elem_t ## _ ## ring;	\
APR_RING_HEAD(elem_t ## _ ## ring, elem_t ## _ ## elem);\

/* EXTENDED */
/*
 typedef struct MyType_elem MyType_elem;
 struct MyType_elem
 {
	APR_RING_ENTRY(MyType_elem) link;
	MyType *pInst;
 };

 typedef struct MyType_ring MyType_ring;
 APR_RING_HEAD(MyType_ring, MyType_elem);
 */

#endif // !GENERAL_RING_H