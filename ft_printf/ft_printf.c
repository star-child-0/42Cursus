#include "../libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(const char *str)
{
    int     i;

    i = 0;
	while (str[i] != '\0')
        write(1, &str[i++], 1);
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
    int         i;
    va_list     ptr;
    va_start    (ptr, str);

    i = 0;
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
int     main()
{
    char a = 'a';
    int n = 10;
    int *p = &n;

    ft_printf("Hello world!\n");
    ft_printf("One percent: %\n");
    ft_printf("Two percent: %%\n");

    // printf("%\n");


    // write(1, &"\n", 1);
    // ft_printf("%c", 'a');
    // write(1, &"\n", 1);

    // printf("%%c: %c\n", a);
    // printf("%%s: %s\n", "Hello World");
    // printf("%%p: %p\n", p);
    // printf("%%d: %d\n", *p);
    // printf("%%i: %i\n", n);
    // printf("%%u: %u\n", n);
    // printf("%%x: %x\n", n);
    // printf("%%X: %X\n", n);
    // printf("%%\n\n");

    // printf("+123: %+d\n", +123);
    // printf(" 123: % d\n", +123);
    // printf("-123: %-d\n", -123);
    // printf("a: %#x\n", 10);
    // printf("A: %#X\n", 10);
}