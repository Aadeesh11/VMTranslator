#ifdef MAIN
#ifndef POPCOM_H
#define POPCOM_H

#include "includes.h"
#include "resultLinkedList.c"

// pop local/arg/this/that i
void makeResultLinkedListForPopLCLARGTHISTHAT(ResultLinkedList *head, char *memSeg, int val)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//pop %s %d\n", memSeg, val))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "//D = %d\n", val))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%d\n", val))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%s\n", memSeg))
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
    if (0 > asprintf(&s, "D=D+A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "//SP--\n"))
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
    if (0 > asprintf(&s, "D=M+D\n"))
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
    if (0 > asprintf(&s, "A=D-A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=D-A\n"))
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
}

// pop static i
void makeResultLinkedListForPopStatic(ResultLinkedList *head, char *fileName, int val)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//pop static %d\n", val))
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
    if (0 > asprintf(&s, "@%s.%d\n", fileName, val))
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
}

// pop temp i
void makeResultLinkedListPopTemp(ResultLinkedList *head, int val)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//pop temp %d\n", val))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "//D = %d\n", val))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%d\n", val))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@5\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=D+A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "//SP--\n"))
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
    if (0 > asprintf(&s, "D=M+D\n"))
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
    if (0 > asprintf(&s, "A=D-A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=D-A\n"))
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
}

// pop pointer 0/1
void makeResultLinkedListPopPointer(ResultLinkedList *head, char *thisOrThat)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//pop %s %s\n", "pointer", thisOrThat))
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
    if (0 > asprintf(&s, "@%s\n", thisOrThat))
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
}

#endif
#endif