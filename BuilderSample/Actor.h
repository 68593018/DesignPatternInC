
#include <apr_pools.h>
#include "EnumUtil.h"


#ifndef ACTOR_H
#define ACTOR_H

typedef struct Actor_Fld Actor_Fld;
typedef struct Actor Actor;

struct Actor
{
    Actor_Fld *pFld;

    //Properties
    RoleType (* GetRole)(Actor *pInst);
    void (* SetRole)(Actor *pInst, RoleType role);
    GenderType (* GetGender)(Actor *pInst);
    void (* SetGender)(Actor *pInst, GenderType gender);
    /*
      �����ַ�����ʽ�����Ը�����
      �ṩ�ڴ�ز����Դ�ŷ��ص�ֵ
     */
    char *(* GetFace)(Actor *pInst, apr_pool_t *pPool);
    void (* SetFace)(Actor *pInst, const char *const pFace);
    char *(* GetCostume)(Actor *pInst, apr_pool_t *pPool);
    void (* SetCostume)(Actor *pInst, const char *const pCostume);
    char *(* GetHairStyle)(Actor *pInst, apr_pool_t *pPool);
    void (* SetHairStyle)(Actor *pInst, const char *const pHairStyle);

    //Public Methods
    void (* SayLines)();
    void (* Act)(Actor *pInst);
};

Actor *Actor_New(apr_pool_t *pSupPool);
void Actor_Free(Actor **ppInst);

#endif // !ACTOR_H
