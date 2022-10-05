#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	int		len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len * sizeof(char));
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		k++;
		i++;
	}	
	return (str);
}