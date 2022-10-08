#include <stdlib.h>
#include <stdio.h>

char **ft_split(char const *s, char c)
{
    int     i;
    int     l;
    int     j;
    int     w;
    char    **p;
    
    i = 0;
    j = 0;
    w = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            while (s[i] == c)
                i++;
            w++;
        }
        i++;
    }
    printf("%d\n", w + 1);
    *p = malloc(w + 1);
    l = i;
    i = 0;
    while (i  < l)
    {
        if (s[i] == c)
            j++;
        i++;
    }
}

int main()
{
    ft_split("Hello World", ' ');
}