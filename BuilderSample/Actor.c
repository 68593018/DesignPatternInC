
#include <apr_strings.h>
#include "Actor.h"


//��Ҫ�����ԡ���������


struct Actor_Fld
{
    //��ʵ��ר���ڴ��
    apr_pool_t *m_pPool;

    RoleType m_role;
    GenderType m_gender;
    char *pFace;
    char *pCostume;
    char *pHairStyle;
};

//Properties
RoleType GetRole(Actor *pInst)
{
    return pInst->pFld->m_role;
}
static void SetRole(Actor *pInst, RoleType role)
{
    pInst->pFld->m_role = role;
}
static GenderType GetGender(Actor *pInst)
{
    return pInst->pFld->m_gender;
}
static void SetGender(Actor *pInst, GenderType gender)
{
    pInst->pFld->m_gender = gender;
}
static char *GetFace(Actor *pInst, apr_pool_t *pPool)
{
    return apr_pstrdup(pPool, (const char *)pInst->pFld->pFace);
}
static void SetFace(Actor *pInst, const char *const pFace)
{
    if (pFace)//�ǿռ��
    {
        //����Ƶ���������õķ������ڴ˴�������ڴ�ط����µ��ڴ�
        //����������ڴ�ط��䣬���ᵼ���ڴ�ص�ռ����Խ��Խ��
        //��ˣ����Կ���ͨ�������������ڷ����ڴ�ʱ����ǰһ�η�����ڴ��ͷŵ�
        pInst->pFld->pFace = apr_pstrdup(pInst->pFld->m_pPool, pFace);
    }
}
static char * GetCostume(Actor *pInst, apr_pool_t *pPool)
{
    return apr_pstrdup(pPool, (const char *)pInst->pFld->pCostume);
}
static void SetCostume(Actor *pInst, const char *const pCostume)
{
    if (pCostume)//�ǿռ��
    {
        pInst->pFld->pCostume = apr_pstrdup(pInst->pFld->m_pPool, pCostume);
    }
}
static char * GetHairStyle(Actor *pInst, apr_pool_t *pPool)
{
    return apr_pstrdup(pPool, (const char *)pInst->pFld->pHairStyle);
}
static void SetHairStyle(Actor *pInst, const char *const pHairStyle)
{
    if (pHairStyle)//�ǿռ��
    {
        pInst->pFld->pHairStyle = apr_pstrdup(pInst->pFld->m_pPool, pHairStyle);
    }
}

//Private Methods

//Public Methods
static void SayLines()
{
    puts("Oh, Juliet~~\n");
}

static void Act(Actor *pInst)
{
    char *pRole = NULL;
    switch (pInst->pFld->m_role)
    {
    case ROLE_NULL:
    {
		pRole = &"Nothing";
    }
    break;
    case ROLE_ANGLE:
    {
        pRole = &"Angle";
    }
    break;
    case ROLE_DEVIL:
    {
        pRole = &"Devil";
    }
    break;
    case ROLE_HERO:
    {
        pRole = &"Hero";
    }
    break;
    default:
    {
        pRole = &"Nothing";
    }
    break;
    }

    printf("I\'m acting as %s.\n", pRole);
}

Actor * Actor_New(apr_pool_t *pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    Actor *pInst = (Actor *)apr_palloc(pPool, sizeof(Actor));
    
    pInst->pFld = (Actor_Fld *)apr_palloc(pPool, sizeof(Actor_Fld));
    pInst->pFld->m_pPool = pPool;

	pInst->pFld->m_gender = GENDER_MAN;
	pInst->pFld->m_role = ROLE_HERO;
    pInst->pFld->pCostume = apr_pstrdup(pInst->pFld->m_pPool, "Classical");
    pInst->pFld->pFace = apr_pstrdup(pInst->pFld->m_pPool, "handsome");
    pInst->pFld->pHairStyle = apr_pstrdup(pInst->pFld->m_pPool, "short black hair");

    pInst->GetRole = GetRole;
    pInst->SetRole = SetRole;
    pInst->GetGender = GetGender;
    pInst->SetGender = SetGender;
    pInst->GetFace = GetFace;
    pInst->SetFace = SetFace;
    pInst->GetCostume = GetCostume;
    pInst->SetCostume = SetCostume;
    pInst->GetHairStyle = GetHairStyle;
    pInst->SetHairStyle = SetHairStyle;

    pInst->SayLines = SayLines;
    pInst->Act = Act;

    return pInst;
}

void Actor_Free(Actor ** ppInst)
{
    apr_pool_destroy((*ppInst)->pFld->m_pPool);

    *ppInst = NULL;
}
