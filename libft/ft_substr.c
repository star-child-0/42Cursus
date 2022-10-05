#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int     i;
    char    *sub;

    i = 0;
    sub = (char *)malloc(len);
    while (i < start)
        i++;
    
    while (i < len)
    {
        sub[i] = s[i];
        i++;
    }
    return (sub);    
}