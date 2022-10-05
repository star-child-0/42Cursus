#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(src) * sizeof(char));
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	return (dest);
}