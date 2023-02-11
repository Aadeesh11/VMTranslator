#ifdef MAIN
#ifndef RESULTLL_C
#define RESULTLL_C

#include "includes.h"

typedef struct ResultLinkedList
{
    char *string;
    struct ResultLinkedList *next;
} ResultLinkedList;

ResultLinkedList *addToList(char *s, ResultLinkedList *cur)
{
    ResultLinkedList *newNode = malloc(sizeof(ResultLinkedList));
    newNode->next = NULL;
    newNode->string = strdup(s);

    cur->next = newNode;
    cur = cur->next;
    free(s);
    return cur;
}

void freeList(ResultLinkedList *head)
{
    ResultLinkedList *cur = head;
    while (head != NULL)
    {
        if (head->string != NULL)
        {
            free(head->string);
        }
        head = cur->next;
        free(cur);
        cur = head;
    }
    return;
}

void writeToFile(FILE *out, ResultLinkedList *head)
{
    ResultLinkedList *cur = head;
    while (cur != NULL && cur->string != NULL)
    {
        fwrite(cur->string, sizeof(char), strlen(cur->string), out);
        cur = cur->next;
    }
    return;
}

#endif
#endif