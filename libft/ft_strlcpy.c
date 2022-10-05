unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	int	i;

	i = 0;
	if (src[0] != '\0' && size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	return ((unsigned int)i);
}