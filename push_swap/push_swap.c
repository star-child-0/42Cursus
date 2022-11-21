#include "push_swap.h"

int     stackify(t_list *list, int argc, char *argv[])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    list = ft_lstnew(argv[i]);
    if (!list)
        return (0);
    while (++i < argc)
        ft_lstadd_front(&list, ft_lstnew(argv[i]));
    return (1);
}

int     argv_check(int argc, char *argv[])
{
    int     i;
    int     j;

    i = 0;
    while (++i < argc)
    {
        j = -1;
        while (argv[i][++j] != '\0')
            if (!ft_isdigit(argv[i][j]))
                return (0);
    }
    return (1);
}

int     main(int argc, char *argv[])
{
    t_list  *list;

    if (argv_check(argc, argv) && stackify(list, argc, argv) && argc > 1)
    {
        ft_printf("Success\n");
    }
    else
        ft_printf("Error\n");    
    ft_lstclear(list, del);
    return(0);
}