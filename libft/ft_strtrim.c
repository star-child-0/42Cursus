#include <stdlib.h>

// int ft_strlen(const char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//         i++;
//     return (i);
// }

char *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     k;
    int     j;
    int     l;
    char    *str;

    i = 0;
    j = 0;
    l = ft_strlen(s1);
    str = malloc(l);
    while (i < l)
    {
        while(set[j] != '\0')
        {
            
        }
        i++;
    }

    return (str);
}

#include <stdio.h>
int main()
{
    printf("%s\n", ft_strtrim("Hello \tWorld", "\t"));

    // printf("Hello World: "); 
    // printf("%s\n", ft_strtrim("Hello 12World12", "12"));
    // printf("Hello 1World1: "); 
    // printf("%s\n", ft_strtrim("Hello 1World1", "12"));
    // printf("Hello 1World1: "); 
    // printf("%s\n", ft_strtrim("Hel12lo 1Wor12ld1", "12"));
    // printf("Hel21lo 1Wor21ld1: "); 
    // printf("%s\n", ft_strtrim("Hel21lo 1Wor21ld1", "12"));
}