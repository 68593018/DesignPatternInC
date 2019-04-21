
#include "SystemExit.h"
#include "CommandExit.h"

struct CommandExit_Fld
{
    apr_pool_t *m_pPool;

    //�̳нӿ�
    ICommand m_command;

    //������շ�
    SystemExit *m_pReceiver;
};

static void Free(ICommand **ppCommand)
{
    CommandExit_Free(&(CommandExit *)(*ppCommand)->pImplicit);
    *ppCommand = NULL;
}

static void Execute(ICommand *pCommand)
{
    CommandExit *pInst = (CommandExit *)pCommand->pImplicit;
    pInst->pFld->m_pReceiver->Exit(pInst->pFld->m_pReceiver);
}

CommandExit * CommandExit_New(apr_pool_t * pSupPool)
{
    apr_pool_t *pPool;
    apr_pool_create(&pPool, pSupPool);

    CommandExit *pInst = apr_palloc(pPool, sizeof(CommandExit));

    pInst->pFld = apr_palloc(pPool, sizeof(CommandExit_Fld));
    pInst->pFld->m_pPool = pPool;
    pInst->pFld->m_command.pImplicit = pInst;
    pInst->pFld->m_command.Free = Free;

    pInst->pFld->m_command.Execute = Execute;

    pInst->pFld->m_pReceiver = SystemExit_New(pInst->pFld->m_pPool);

    return pInst;
}

ICommand * CommandExit2ICommand(CommandExit * pInst)
{
    return &(pInst->pFld->m_command);
}

void CommandExit_Free(CommandExit ** ppInst)
{
    SystemExit_Free(&((*ppInst)->pFld->m_pReceiver));

    apr_pool_destroy((*ppInst)->pFld->m_pPool);
    *ppInst = NULL;
}
