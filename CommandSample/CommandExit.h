
#include <apr_pools.h>
#include "ICommand.h"


#ifndef COMMANDEXIT_H
#define COMMANDEXIT_H

typedef struct CommandExit_Fld CommandExit_Fld;
typedef struct CommandExit CommandExit;

struct CommandExit
{
    CommandExit_Fld *pFld;
    
    //�̳нӿ�
};

CommandExit *CommandExit_New(apr_pool_t *pSupPool);
ICommand *CommandExit2ICommand(CommandExit *pInst);
void CommandExit_Free(CommandExit **ppInst);

#endif // !COMMANDEXIT_H
