#include "includes.h"
#include "resultLinkedList.c"

void makeResultLinkedListForPushConstant(ResultLinkedList *head, int val)
{
    ResultLinkedList *cur = head;

    if (0 > asprintf(&(cur->string), "@%d\n", val))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    char *s;
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "M=M+1\n"))
    {
        printf("asprintf error here!");
        freeList(head);
        return;
    }
    cur = addToList(s, cur);
}