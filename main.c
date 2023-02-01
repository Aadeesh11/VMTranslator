#include "includes.h"
#include "codegen.c"

char *fileName;

FILE *openOut(char *arg)
{
    int n = strlen(arg);
    while (n > 0)
    {
        n--;
        if (arg[n] == '.')
        {
            break;
        }
    }

    char *s = malloc(sizeof(char) * (n + 4));
    for (int i = 0; i < n; i++)
    {
        s[i] = arg[i];
    }
    s[n] = '.';
    s[n + 1] = 'a';
    s[n + 2] = 's';
    s[n + 3] = 'm';

    // setting the global fileName;
    fileName = strndup(s, n);
    printf("opening: %s\n", s);
    FILE *out = fopen(s, "w");
    free(s);
    return out;
}

char *trim(char *tem)
{
    int n = strlen(tem);
    if (tem[n - 1] == '\n')
    {
        tem[n - 1] = '\0';
        n--;
    }
    while (n - 1 >= 0 && tem[n - 1] == ' ')
        n--;
    tem[n] = '\0';

    while (*tem == ' ')
    {
        tem++;
    }
    return tem;
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
        char *tem = strdup(line);
        tem = trim(tem);
        if (strlen(tem) < 2)
        {
            // some garbage.
            free(tem);
            continue;
        }

        if (tem[0] == '/' && tem[1] == '/')
        {
            // its a comment
            // ignore

            free(tem);
            continue;
        }

        // parsing individual commands, i.e separating on whitespace.
        char **ap, *arg[10], *inputstring = strdup(tem);
        // stores number of commands.
        int argcnt = 0;
        for (ap = arg; (*ap = strsep(&inputstring, " \t")) != NULL;)
        {
            argcnt++;
            if (++ap >= &arg[10])
                break;
        }

        // making decisions based on #of arguments
        if (argcnt == 1)
        {
            continue;
        }
        else if (argcnt == 2)
        {
            continue;
        }
        else if (argcnt == 3)
        {
            // printf("%s %s %d", arg[0], arg[1], atoi(arg[2]));
            spitPushOrPop(out, arg[0], arg[1], atoi(arg[2]), fileName);
        }

        // DEBUG info.
        printf("Parsing Line %d: ", lineCnt);
        for (int i = 0; i < argcnt; i++)
        {
            printf("%s ", arg[i]);
        }
        printf("\n");

        // per iter cleanUP
        free(arg[0]);
        free(tem);
    }

    free(line);
    fclose(in);
    fclose(out);
    free(fileName);

    return 0;
}