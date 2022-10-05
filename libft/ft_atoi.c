int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nb = -nb;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}