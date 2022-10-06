#include <stdlib.h>

char **ft_split(char const *s, char c)
{
    int     i;
    int     w;
    char    **p;
    
    i = 0;
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
    *p = (char **)malloc(w);
}

#include <stdio.h>
int main()
{
    ft_split("Hello  World", ' ');
}