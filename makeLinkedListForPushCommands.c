#include "includes.h"
#include "resultLinkedList.c"

// For push constant i
void makeResultLinkedListForPushConstant(ResultLinkedList *head, int val)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//push constant %d\n", val))
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
    if (0 > asprintf(&s, "//RAM[SP] = D\n"))
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
    if (0 > asprintf(&s, "//SP++\n"))
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

// For push local/ARG/This/That i
void makeResultLinkedListForPushLCLARGTHISTHAT(ResultLinkedList *head, char *memSegIdentifier, int val)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//push %s %d\n", memSegIdentifier, val))
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
    if (0 > asprintf(&s, "//A = %s + %d\n", memSegIdentifier, val))
    {
        printf("asprintf error here!");

        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%s\n", memSegIdentifier))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M+D\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "//RAM[SP] = RAM[%s + %d]\n", memSegIdentifier, val))
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
    if (0 > asprintf(&s, "//SP++\n"))
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

//