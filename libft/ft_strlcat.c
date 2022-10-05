unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	w;

	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	w = i;
	while (src[k] != '\0' && k < size - w -1 && size > 0)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (w + k);
}