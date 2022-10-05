#include <stdlib.h>

void *ft_memchr(const void *str, int c, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (str[i] == c)
            break;
        i++;
    }
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("%s\n", memchr("Hello World", ' ', 6));

    // printf("%s\n", ft_memchr("Hello World", ' ', 6));
}