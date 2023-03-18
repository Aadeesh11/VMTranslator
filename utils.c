#ifdef MAIN
#ifndef UTILS_C
#define UTILS_C

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
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
int is_vm_file(char *arg)
{
    int n = strlen(arg);
    if (n < 3)
        return 0;
    return (arg[n - 1] == 'm' && arg[n - 2] == 'v' && arg[n - 3] == '.');
}

#endif
#endif
