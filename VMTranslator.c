#ifndef MAIN
#define MAIN

#include "includes.h"
#include "ctype.h"
#include "codegen.c"

char *fileName;

FILE *openOut(char *arg)
{
    int n = strlen(arg);
    // printf("%s %d\n", arg, n);
    while (n > 0)
    {
        n--;
        if (arg[n] == '.')
        {
            break;
        }
    }
    char *s = calloc((n + 5), sizeof(char));
    for (int i = 0; i < n; i++)
    {
        s[i] = arg[i];
    }
    *(s + n) = '.';
    *(s + n + 1) = 'a';
    *(s + n + 2) = 's';
    *(s + n + 3) = 'm';
    *(s + n + 4) = '\0';

    // setting the global fileName;
    char *fileFromPath = calloc((n + 1), sizeof(char));
    for (int i = 0; i < n; i++)
    {
        fileFromPath[i] = s[i];
    }
    *(fileFromPath + n) = '\0';
    char *pfile;
    pfile = fileFromPath + strlen(fileFromPath);
    for (; pfile > fileFromPath; pfile--)
    {
        if ((*pfile == '\\') || (*pfile == '/'))
        {
            pfile++;
            break;
        }
    }
    fileName = strdup(pfile);
    printf("opening: %s, Parsing file with fileName: %s\n", s, fileName);
    FILE *out = fopen(s, "w");
    free(s);
    free(fileFromPath);
    return out;
}

char *trim(char *s)
{
    if (*s == '\0')
        return s;
    while (isspace((unsigned char)*s))
        s++;

    if (*s == '\0')
        return s;

    char *end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end))
        end--;

    end[1] = '\0';
    return s;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./main FileName.asm");
        return 0;
    }

    // opening stuff for reading and writing.
    FILE *in, *out;
    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("error in opening input file");
        return 0;
    }
    out = openOut(argv[1]);
    if (out == NULL)
    {
        printf("error in opening output file");
        return 0;
    }

    // MAINLoop: parsing line by line
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    int lineCnt = 0;
    while ((linelen = getline(&line, &linecap, in)) > 0)
    {
        lineCnt++;
        // getting the trimmed line (no '\n' and ' ' at front or begin)
        char *freeTem = strdup(line);
        char *tem = freeTem;
        if (tem[linelen - 1] == '\n')
            tem[linelen - 1] = '\0';
        tem = trim(freeTem);
        if (tem == NULL || strlen(tem) == 0)
        {
            free(freeTem);
            continue;
        }
        if (strlen(tem) < 2 && strlen(tem) > 0)
        {
            // some garbage.
            free(freeTem);
            continue;
        }

        if (tem[0] == '/' && tem[1] == '/')
        {
            // its a comment
            // ignore
            free(freeTem);
            continue;
        }

        // parsing individual commands, i.e separating on whitespace.
        char **ap, *arg[10], *inputstring = strdup(tem);
        // stores number of commands.
        int argcnt = 0;
        for (ap = arg; (*ap = strsep(&inputstring, " \t")) != NULL;)
        {
            if (**ap != '\0')
            {
                argcnt++;
                if (++ap >= &arg[10])
                    break;
            }
        }

        // making decisions based on #of arguments
        if (argcnt == 1)
        {
            handleArithmetic(out, arg[0], lineCnt, fileName);
        }
        else if (argcnt == 2)
        {
        }
        else if (argcnt == 3)
        {
            // printf("%s %s %d", arg[0], arg[1], atoi(arg[2]));
            handlePushOrPop(out, arg[0], arg[1], atoi(arg[2]), fileName);
        }

        // DEBUG info.
        printf("Parsing Line %d (args: %d) --> ", lineCnt, argcnt);
        for (int i = 0; i < argcnt; i++)
        {
            printf("%s ", arg[i]);
        }
        printf("\n");

        // per iter cleanUP
        free(arg[0]);
        free(freeTem);
    }

    free(line);
    fclose(in);
    fclose(out);
    free(fileName);

    return 0;
}

#endif