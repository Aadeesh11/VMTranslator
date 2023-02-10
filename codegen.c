#include "includes.h"
#include "makeLinkedListForPushCommands.c"

void handlePushOrPop(FILE *out, char *com, char *memSeg, int val, char *fileName)
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
        else if (strcmp(memSeg, "static") == 0)
        {
            makeResultLinkedListForPushStatic(head, val, fileName);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "temp") == 0)
        {
            makeResultLinkedListForPushTemp(head, val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "pointer") == 0)
        {
            makeResultLinkedListForPushPointer(head, val == 0 ? "THIS" : "THAT");
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else
        {
            printf("ERROR: Wrong memory segment---->");
            return;
        }
    }
    else if (strcmp(com, "pop") == 0)
    {

        return;
    }
    else
    {
        printf("ERROR in parsing: %s was found, expected push or pop!---->", com);
        return;
    }
}