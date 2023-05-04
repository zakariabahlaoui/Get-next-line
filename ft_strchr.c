#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    char *v;
    int i;

    i = 0;
    v = (char *)s;

    while (v[i])
    {
        if (v[i] == (char)c)
            return &v[i];
        i++;
    }

    if (c == 0)
        return &v[i];
    return NULL;
}
