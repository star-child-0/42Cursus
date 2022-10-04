#include <stdlib.h>

char *ft_strdup(const char *s)
{
    int     i;
    char    *dest;

    i = 0;
    dest = malloc(strlen(s));
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
    return(dest);
}
