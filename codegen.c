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
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "local") == 0)
        {
            makeResultLinkedListForPushLCLARGTHISTHAT(head, "LCL", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "argument") == 0)
        {
            makeResultLinkedListForPushLCLARGTHISTHAT(head, "ARG", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "this") == 0)
        {
            makeResultLinkedListForPushLCLARGTHISTHAT(head, "THIS", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "that") == 0)
        {
            makeResultLinkedListForPushLCLARGTHISTHAT(head, "THAT", val);
            writeToFile(out, head);
            if (head != NULL)
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