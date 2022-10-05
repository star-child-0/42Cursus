void ft_bzero(void *s, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
        s[i] = '\0';
        i++;
    }
}