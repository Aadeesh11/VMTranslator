#ifdef MAIN
#ifndef BRN
#define BRN

#include "resultLinkedList.c"
void branchLabel(ResultLinkedList *head, char *to)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "(%s)\n", to))
    {
        printf("asprintf error here!");
    }
    return;
}
void branchIfGoto(ResultLinkedList *head, char *to)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//if-goto %s\n", to))
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
    if (0 > asprintf(&s, "@%s\n", to))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D;JNE\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    return;
}
void branchGoto(ResultLinkedList *head, char *to)
{
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//goto %s\n", to))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "@%s\n", to))
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
    return;
}
#endif
#endif