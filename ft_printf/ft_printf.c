#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
    int     i;

    i = 0;
	while (str[i] != '\0')
        	ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	ft_putunsign_nbr(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strev(char *str)
{
	int	i;
	int	len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len/2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

void	ft_putnbr_hex(int nb)
{
	int	i;
	int	temp;
	char	hex[20];
	
	i = 0;
	while(nb > 9)
	{
		temp = nb % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;
		hex[i++] = temp;
		nb /= 16;
	}
	hex[i++] = nb + 48;
	hex[i] = '\0';
	ft_putstr(hex);
	write(1, &"\n", 1);
	ft_putstr(ft_strev(hex));
}

void    ft_conversions_check(char c, void *var)
{
    if (c == 'c')
        write(1, &var, 1);
    // else if (c == 's')
    // else if (c == 'p')
    // else if (c == 'd')
    // else if (c == 'i')
    // else if (c == 'u')
    // else if (c == 'x')
    // else if (c == 'X')
}

int    ft_check_perc(const char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
            return (1);
        i++;
    }
    return (0);
}

void    ft_printf(const char *str, ...)
{
	int	i;
	va_list	ptr;

	i = 0;
	va_start(ptr, str);
	if (ft_check_perc(str) == 1)
	{
		while (str[i])
		{
			if(str[i] == '%' && str[i + 1] == '%')
				i++;
			// else if (str[i] == '%' && str[i + 1] != '%')
			//     ft_conversions_check(str[i++], va_arg(ptr, void));
			write(1, &str[i], 1);
			i++;
		}        
	}
	else
	ft_putstr(str);
}

#include <stdio.h>
void	variadic_test(const char* str, ...)
{
	int	c;
    	va_list ptr;

	va_start(ptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				ft_putnbr(va_arg(ptr, int));
			else if (*str == 'u')
				ft_putunsign_nbr(va_arg(ptr, unsigned int));
			else if (*str == 'c')
				ft_putchar(va_arg(ptr, int));
			else if(*str == 's')
				ft_putstr(va_arg(ptr, char*));
			//else if (*str == 'p')
			//else if (*str == 'X')
			else if (*str == 'x')
				ft_putnbr_hex(va_arg(ptr, int));
			else
				str--;
		}
		else
			write(1, &str, 1);
		str++;
	}
	va_end(ptr);
}

int     main()
{
    int n = 10;
    int *p = &n;

    // ft_printf("Hello world!\n");
    // ft_printf("One percent: %\n");
    // ft_printf("Two percent: %%\n");

    variadic_test("%d", 42);
    write(1, &"\n", 1);
    variadic_test("%s", "Hello World\n");
    variadic_test("%c", 'F');
    write(1, &"\n", 1);
    variadic_test("%u", 4294967295);
    write(1, &"\n", 1);
    variadic_test("%x", 1234);
    write(1, &"\n", 1);
    
    // printf("%%c: %c\n", a);
    // printf("%%s: %s\n", "Hello World");
    // printf("%%p: %p\n", p);
    // printf("%%d: %d\n", *p);
    // printf("%%i: %i\n", n);
    // printf("%%u: %u\n", n);
    // printf("%%x: %x\n", n);
    // printf("%%X: %X\n", n);
    // printf("%%\n\n");
}
