#include "includes.h"
#include "makeLinkedListForPushCommands.c"

void spitPushOrPop(FILE *out, char *com, char *memSeg, int val)
{
    ResultLinkedList *head = malloc(sizeof(ResultLinkedList));
    if (strcmp(com, "push") == 0)
    {
        if (strcmp(memSeg, "constant") == 0)
        {
            makeResultLinkedListForPushConstant(head, val);
            writeToFile(out, head);
            freeList(head);
        }
    }
    else if (strcmp(com, "pop") == 0)
    {
        return;
    }
    else
    {
        printf("ERRRO in parsing: %s was found, expected push or pop!", com);
        return;
    }
}