#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] != '\0' && little[0] != '\0' && i < len)
	{
		while (big[i + k] == little[k] && big[i + k] != '\0')
			k++;
		if (little[k] == '\0')
			return (big + i);
		i++;
		k = 0;
	}
	return ('\0');
}

#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n", strstr("Hello", "e"));
    printf("%d\n", strstr("Hello", "d"));
    
    // printf("%d\n", ft_strnstr("Hello", "e", 5));
    // printf("%d\n", ft_strnstr("Hello", "d", 5));
}