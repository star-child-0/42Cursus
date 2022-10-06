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
    int     i;
    int     k;
    char    *str;

    i = 0;
    str = malloc(ft_strlen(s1));
    while (s1[i] != '\0')
    {
        k = 0;
        if (s1[i] == set[k])
        {
            while (set[k] != '\0' && s1[i + k] == set[k])
                k++;
        }
        str[i] = s1[i];
        i++;
    }
    
    return(str);
}

int main()
{
    printf("%s\n", ft_strtrim("Hello \t\tWorld", "\t"));
}