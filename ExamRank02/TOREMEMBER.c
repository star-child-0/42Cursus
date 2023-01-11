// man operator (bit operations)
	unsigned char	swap_bits(unsigned char octet)
	{
		return ((octet >> 4) | (octet << 4));
	}
	
	void	print_bits(unsigned char octet)
	{
		unsigned char	n;
		int			i = 8;
		while (i--)
		{
			n = (octet >> i & 1) + '0';
			write(1, &n, 1);
		}
	}

	unsigned char	reverse_bits(unsigned char octet)
	{
		unsigned char	n;
		int			i = 8;
		while (i--)
		{
			// print_bits(n);
			// write(1, "\n", 1);
			n = n * 2 + (octet % 2);
			octet = octet / 2;
		}
		return (n);	
	}

// man limits.h

mx = (char **)malloc(word_count(str) * sizeof(char *));
while (++w < word_count(str))
{
	wl = 0;
	while (is_space(str[i]))
		i++;
	while (!is_space(str[i]))
	{
		wl++;		
		i++;
	}
	mx[w] = (char *)malloc((wl - 1) * sizeof(char));
}
