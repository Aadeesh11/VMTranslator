#ifdef MAIN
#ifndef FUNC
#define FUNC

#include "resultLinkedList.c"
int retNum = 0;
int callNum = 0;
int funcNum = 0;
void functionCall(ResultLinkedList *head, char *name, int args)
{
    callNum++;
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//call %s %d \n", name, args))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "@returnAddress%d\n", callNum))
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

    if (0 > asprintf(&s, "@LCL\n"))
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

    if (0 > asprintf(&s, "@ARG\n"))
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

    if (0 > asprintf(&s, "@THIS\n"))
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

    if (0 > asprintf(&s, "@THAT\n"))
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

    if (0 > asprintf(&s, "@SP\n"))
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
    if (0 > asprintf(&s, "@ARG\n"))
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
    if (0 > asprintf(&s, "@%d\n", args))
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
    if (0 > asprintf(&s, "@ARG\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-D\n"))
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
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@ARG\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-D\n"))
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
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@LCL\n"))
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

    if (0 > asprintf(&s, "@%s\n", name))
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
    if (0 > asprintf(&s, "(returnAddress%d)\n", callNum))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

void functionWrite(ResultLinkedList *head, char *name, int args)
{
    funcNum++;
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//funcSignature %s %d \n", name, args))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "(%s)\n", name))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@%d\n", args))
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
    if (0 > asprintf(&s, "@FUNCTEMP%d\n", funcNum))
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
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@FUNCEND%d\n", funcNum))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D;JEQ\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "(FUNCLOOP%d)\n", funcNum))
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
    if (0 > asprintf(&s, "M=0\n"))
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
    if (0 > asprintf(&s, "@FUNCTEMP%d\n", funcNum))
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
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@FUNCLOOP%d\n", funcNum))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D;JGT\n"))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "(FUNCEND%d)\n", funcNum))
    {
        printf("asprintf error here!");
        return;
    }
    cur = addToList(s, cur);
}

void functionReturn(ResultLinkedList *head)
{
    retNum++;
    ResultLinkedList *cur = head;
    if (0 > asprintf(&(cur->string), "//Return\n"))
    {
        printf("asprintf error here!");
        return;
    }
    char *s;
    if (0 > asprintf(&s, "@LCL\n"))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@5\n"))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@returnAddr%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M-1\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@ARG\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=M-1\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@ARG\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M+1\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@SP\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-1\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@THAT\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@2\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@THIS\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@3\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@ARG\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@4\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=A\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@endFrame%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M-D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "D=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "@LCL\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "M=D\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);

    if (0 > asprintf(&s, "@returnAddr%d\n", retNum))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "A=M\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
    if (0 > asprintf(&s, "0;JMP\n"))
    {
        printf("error in return statement!");
        return;
    }
    cur = addToList(s, cur);
}

#endif
#endif