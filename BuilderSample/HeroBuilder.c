
#include "ActorBuilderDetail.h"

static Actor *pInst = NULL;

static void BuildRoleType()
{
    pInst->SetRole(pInst, ROLE_HERO);
}

static void BuildGenderType()
{
    pInst->SetGender(pInst, GENDER_MAN);
}

static void BuildFace()
{
    pInst->SetFace(pInst, "Maybe ugly.");
}

static void BuildCostume()
{
    pInst->SetCostume(pInst, "Fashion");
}

static void BuildHairStyle()
{
    pInst->SetHairStyle(pInst, "Long classical");
}

static Actor *CreatActor()
{
    Actor *pTmp = pInst;
    pInst = NULL;//ȡ�ú���Ϊnull���´�ʹ�ü����´���
    return pTmp;
}

ActorBuilder *GetHeroBuilder(apr_pool_t *pPool, ActorBuilder *pMemIn)
{
    if (pInst != NULL)
    {
        //��Ϊnull��ζ���ϴδ�����δʹ�ã�
        //��˷���
        return NULL;
    }

    pInst = Actor_New(pPool);

    pMemIn->BuildRoleType = BuildRoleType;
    pMemIn->BuildGenderType = BuildGenderType;
    pMemIn->BuildFace = BuildFace;
    pMemIn->BuildCostume = BuildCostume;
    pMemIn->BuildHairStyle = BuildHairStyle;

    pMemIn->CreateActor = CreatActor;

    return pMemIn;
}