#ifdef MAIN

#ifndef STACKAM_C
#define STACKAM_C

#include "includes.h"
#include "resultLinkedList.c"

void stackArithmeticWithTwo(ResultLinkedList *head, char *op, char *symbol)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//%s\n", op))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M%sD\n", symbol))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M+1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

void stackArithmeticWithOne(ResultLinkedList *head, char *op, char *symbol)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//%s\n", op))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=%sM\n", symbol))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M+1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

void stackLogicalWithTwo(ResultLinkedList *head, int lineNum, char *cond, char *fileName)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//%s\n", cond))
    {
        printf("asprintf error here!");
        return;
    }

    // settting unique labels per cond check
    char *labelTrue;
    char *labelFalse;
    asprintf(&labelTrue, "%s_TRUE_%s_%d", cond, fileName, lineNum);
    asprintf(&labelFalse, "%s_FALSE_%s_%d", cond, fileName, lineNum);

    char *s;
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "AM=M-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "AM=M-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-D\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%s\n", labelTrue))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D;%s\n", cond))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=0\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%s\n", labelFalse))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "0;JMP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "(%s)\n", labelTrue))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=-1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "(%s)\n", labelFalse))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M+1\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

#endif
#endif