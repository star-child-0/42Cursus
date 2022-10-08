#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>
char *ft_strtrim(char const *s1, char const *set)
{
    char    *str;

    str = malloc(ft_strlen(s1));

    return (str);
}

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