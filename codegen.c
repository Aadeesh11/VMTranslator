#ifdef MAIN
#ifndef CODEGEN_H
#define CODEGEN_H

#include "includes.h"
#include "makeLinkedListForPushCommands.c"
#include "makeLinkedListForPopCommands.c"
#include "stackArithmetic.c"
#include "makeLinkedListForBranching.c"
#include "makeLinkedListForFunctions.c"

void init(FILE *out)
{
    ResultLinkedList *head = malloc(sizeof(ResultLinkedList));
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//init\n"))
    {
        printf("asprintf error here!");
        goto retur;
    }
    char *s;
    if (0 > asprintf(&s, "@256\n"))
    {
        printf("asprintf error here!");
        goto retur;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("asprintf error here!");
        goto retur;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        goto retur;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("asprintf error here!");
        goto retur;
    }
    cur = addToList(s, cur);
    ResultLinkedList *head2 = malloc(sizeof(ResultLinkedList));
    functionCall(head2, "Sys.init", 0);
    cur->next = head2;
    writeToFile(out, head);

retur:
    freeList(head);
    return;
}

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
            if (head != NULL)
                freeList(head);
        }
    }
    else if (strcmp(com, "pop") == 0)
    {
        if (strcmp(memSeg, "local") == 0)
        {
            makeResultLinkedListForPopLCLARGTHISTHAT(head, "LCL", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "argument") == 0)
        {
            makeResultLinkedListForPopLCLARGTHISTHAT(head, "ARG", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "this") == 0)
        {
            makeResultLinkedListForPopLCLARGTHISTHAT(head, "THIS", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "that") == 0)
        {
            makeResultLinkedListForPopLCLARGTHISTHAT(head, "THAT", val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "static") == 0)
        {
            makeResultLinkedListForPopStatic(head, fileName, val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "temp") == 0)
        {
            makeResultLinkedListPopTemp(head, val);
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else if (strcmp(memSeg, "pointer") == 0)
        {
            makeResultLinkedListPopPointer(head, val == 0 ? "THIS" : "THAT");
            writeToFile(out, head);
            if (head != NULL)
                freeList(head);
        }
        else
        {
            printf("ERROR: Wrong memory segment---->");
            if (head != NULL)
                freeList(head);
        }
    }
    else
    {
        printf("ERROR in parsing: %s was found, expected push or pop!---->", com);
        if (head != NULL)
            freeList(head);
    }
}

void handleArithmetic(FILE *out, char *com, int lineNum, char *fileName)
{
    // printf("%s\n", com);
    ResultLinkedList *head = malloc(sizeof(ResultLinkedList));
    if (strcmp(com, "add") == 0)
    {
        stackArithmeticWithTwo(head, com, "+");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "sub") == 0)
    {
        stackArithmeticWithTwo(head, com, "-");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "neg") == 0)
    {
        stackArithmeticWithOne(head, com, "-");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "and") == 0)
    {
        stackArithmeticWithTwo(head, com, "&");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "or") == 0)
    {
        stackArithmeticWithTwo(head, com, "|");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "not") == 0)
    {
        stackArithmeticWithOne(head, com, "!");
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "eq") == 0)
    {
        stackLogicalWithTwo(head, lineNum, "JEQ", fileName);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "lt") == 0)
    {
        stackLogicalWithTwo(head, lineNum, "JLT", fileName);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "gt") == 0)
    {
        stackLogicalWithTwo(head, lineNum, "JGT", fileName);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else
    {
        printf("ERROR in parsing: %s was found, expected an arithemtic op!----->", com);
        if (head != NULL)
            freeList(head);
    }
}

void handleBranching(FILE *out, char *com, char *to, int lineNum, char *fileName)
{
    ResultLinkedList *head = malloc(sizeof(ResultLinkedList));
    if (strcmp(com, "label") == 0)
    {
        branchLabel(head, to);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "if-goto") == 0)
    {
        branchIfGoto(head, to);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "goto") == 0)
    {
        branchGoto(head, to);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else
    {
        printf("ERROR in parsing: %s %s was found, expected an branching op!----->", com, to);
        if (head != NULL)
            freeList(head);
    }
}

void handleFunction(FILE *out, char *com, char *name, int numArgs, int lineNum, char *fileName)
{
    ResultLinkedList *head = malloc(sizeof(ResultLinkedList));
    if (strcmp(com, "function") == 0)
    {
        functionWrite(head, name, numArgs);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "call") == 0)
    {
        functionCall(head, name, numArgs);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else if (strcmp(com, "return") == 0)
    {
        functionReturn(head);
        writeToFile(out, head);
        if (head != NULL)
            freeList(head);
    }
    else
    {
        printf("ERROR in parsing: %s was found, expected an function op!----->", com);
        if (head != NULL)
            freeList(head);
    }
}

#endif
#endif