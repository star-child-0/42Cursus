#include <stdlib.h>

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if(str2[i] > str1[i])
            return (1);
        else if(str1[i] > str2[i])
            return (-1);
        i++;
    }
    return(0);
}

#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n", memcmp("Hello", "Hello", 5));
    printf("%d\n", memcmp("Hello", "World", 5));
    printf("%d\n", memcmp("World", "Hello", 5));
    
    // printf("%d\n", ft_memcmp("Hello", "Hello", 5));
    // printf("%d\n", ft_memcmp("Hello", "World", 5));
    // printf("%d\n", ft_memcmp("World", "Hello", 5));
}