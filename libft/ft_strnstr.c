char	*ft_strstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && to_find[0] != '\0' && i < len)
	{
		while (str[i + k] == to_find[k] && str[i + k] != '\0')
			k++;
		if (to_find[k] == '\0')
			return (str + i);
		i++;
		k = 0;
	}
	return ('\0');
}