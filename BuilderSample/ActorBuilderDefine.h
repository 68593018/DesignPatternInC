
#include <apr_pools.h>
#include "Actor.h"

#ifndef ACTORBUILDER_H
#define ACTORBUILDER_H


typedef enum BuilderType BuilderType;

enum BuilderType
{
	BUILDER_NULL = 0,
	BUILDER_ANGLE = 1,
	BUILDER_DEVIL = 2,
	BUILDER_HERO = 3
};


typedef struct ActorBuilder ActorBuilder;

struct ActorBuilder
{
    //���츴�Ӷ���ĸ������ֵķ���
    void (* BuildRoleType)();
    void (* BuildGenderType)();
    void (* BuildFace)();
    void (* BuildCostume)();
    void (* BuildHairStyle)();

    //��ȡ����Ķ���
    Actor *(* CreateActor)();
};

//�ṩ�ڴ����Σ�����Ҫ����ĸ��Ӷ����ڲ�ʹ��
ActorBuilder *GetBuilder(apr_pool_t *pPool, BuilderType type, ActorBuilder *pMemIn);

#endif // !ACTORBUILDER_H
