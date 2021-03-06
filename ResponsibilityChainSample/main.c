
#include <stdio.h>
#include <apr_pools.h>
#include "PurchaseRequest.h"
#include "IApprover.h"
#include "ApproverBoard.h"
#include "ApproverPresident.h"
#include "ApproverVicePresident.h"
#include "ApproverManager.h"
#include "ApproverDirector.h"


int main(int argc, char **argv)
{
    apr_pool_t *pMemPool;

    apr_initialize();

    apr_pool_create(&pMemPool, NULL);

    //��������
    IApprover *pZhangWj = ApproverDirector2IApprover(ApproverDirector_New(pMemPool, "���޼�"));
    IApprover *pHuangR = ApproverManager2IApprover(ApproverManager_New(pMemPool, "����"));
    IApprover *pYangG = ApproverVicePresident2IApprover(ApproverVicePresident_New(pMemPool, "���"));
    IApprover *pGuoJ = ApproverPresident2IApprover(ApproverPresident_New(pMemPool, "����"));
    IApprover *pBoard = ApproverBoard2IApprover(ApproverBoard_New(pMemPool, "���»�"));

    //����������
    pZhangWj->SetSuccessor(pZhangWj, pHuangR);
    pHuangR->SetSuccessor(pHuangR, pYangG);
    pYangG->SetSuccessor(pYangG, pGuoJ);
    pGuoJ->SetSuccessor(pGuoJ, pBoard);

    PurchaseRequest *pReq1 = PurchaseRequest_New(pMemPool, 45000, 1001, "�������콣");
    PurchaseRequest *pReq2 = PurchaseRequest_New(pMemPool, 70000, 1002, "���򡶿������䡷");
    PurchaseRequest *pReq3 = PurchaseRequest_New(pMemPool, 90000, 1003, "�����׽��");
    PurchaseRequest *pReq4 = PurchaseRequest_New(pMemPool, 160000, 1004, "����Ŷ�");
    PurchaseRequest *pReq5 = PurchaseRequest_New(pMemPool, 900000, 1005, "�����һ���");

    pZhangWj->ProcessRequest(pZhangWj, pReq1);
    pZhangWj->ProcessRequest(pZhangWj, pReq2);
    pZhangWj->ProcessRequest(pZhangWj, pReq3);
    pZhangWj->ProcessRequest(pZhangWj, pReq4);
    pZhangWj->ProcessRequest(pZhangWj, pReq5);

    PurchaseRequest_Free(&pReq1);
    PurchaseRequest_Free(&pReq2);
    PurchaseRequest_Free(&pReq3);
    PurchaseRequest_Free(&pReq4);
    PurchaseRequest_Free(&pReq5);

    pZhangWj->Free(&pZhangWj);
    pHuangR->Free(&pHuangR);
    pYangG->Free(&pYangG);
    pGuoJ->Free(&pGuoJ);
    pBoard->Free(&pBoard);

    apr_pool_destroy(pMemPool);

    apr_terminate();

    return EXIT_SUCCESS;
}