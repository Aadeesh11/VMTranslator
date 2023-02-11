#ifndef STACKAM_C
#define STACKAM_C

#include "includes.h"
#include "resultLinkedList.c"

void stackAdd(ResultLinkedList *head)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//add\n"))
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
    if (0 > asprintf(&s, "M=D+M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

void stackSubtract(ResultLinkedList *head)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//add\n"))
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
    if (0 > asprintf(&s, "M=D-M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

#endif