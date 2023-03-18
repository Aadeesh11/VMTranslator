#ifndef MAIN
#define MAIN

#include "includes.h"
#include "ctype.h"
#include "codegen.c"
#include "utils.c"

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

FILE *openOutForDir(char *arg)
{
    int n = strlen(arg);
    int i = n - 1;
    while (i >= 0 && arg[i] != '/')
        i--;
    char *dirName = calloc(n + 1 + n - i + 4, sizeof(char));
    int j = 0;
    i++;
    for (int k = 0; k < n; k++, j++)
    {
        dirName[j] = arg[k];
    }
    dirName[j] = '/';
    j++;
    for (; i < n; j++, i++)
    {
        dirName[j] = arg[i];
    }
    dirName[j] = '.';
    dirName[j + 1] = 'a';
    dirName[j + 2] = 's';
    dirName[j + 3] = 'm';
    dirName[j + 4] = '\0';
    FILE *out = fopen(dirName, "w");
    free(dirName);
    return out;
}

void workOnFile(FILE *out, char *pathToFile)
{
    // opening stuff for reading and writing.
    FILE *in;
    in = fopen(pathToFile, "r");
    if (in == NULL)
    {
        printf("error in opening input file");
        return;
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
        char **ap, *arg[3], *inputstring = strdup(tem);
        // stores number of commands.
        int argcnt = 0;
        for (ap = arg; (*ap = strsep(&inputstring, " \t")) != NULL;)
        {
            // for comments after the command
            if (**ap == '/' && (*((*ap) + 1)) == '/')
            {
                break;
            }
            if (**ap != '\0')
            {
                argcnt++;
                if (++ap >= &arg[3])
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
            handleBranching(out, arg[0], arg[1], lineCnt, fileName);
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
    free(fileName);
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./VMTranslator [dir] [file]");
        return 0;
    }
    FILE *out;

    // dir
    if (is_regular_file(argv[1]) == 0)
    {
        out = openOutForDir(argv[1]);
        if (out == NULL)
        {
            printf("error in opening output file");
            return 0;
        }
        init(out);
        struct dirent *de; // Pointer for directory entry
        // opendir() returns a pointer of DIR type.
        DIR *dr = opendir(argv[1]);
        if (dr == NULL) // opendir returns NULL if couldn't open directory
        {
            printf("Could not open current directory");
            return 0;
        }
        while ((de = readdir(dr)) != NULL)
        {
            if (is_regular_file(de->d_name) && is_vm_file(de->d_name))
            {
                printf("reading %s\n", de->d_name);
                // setting fileName
                fileName = strndup(de->d_name, strlen(de->d_name) - 3);
                // getting the filepath to read
                char *pathToFile;
                asprintf(&pathToFile, "%s/%s", argv[1], de->d_name);
                // working on file
                workOnFile(out, /*"./dirName/fileName"*/ pathToFile);
                free(pathToFile);
            }
        }
        closedir(dr);
    }
    else
    {
        // filename is set in the openOut function.
        out = openOut(argv[1]);
        if (out == NULL)
        {
            printf("error in opening output file");
            return 0;
        }
        init(out);
        workOnFile(out, argv[1]);
    }
    fclose(out);

    return 0;
}

#endif