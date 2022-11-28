#include "push_swap.h"

void	list_size(int argc, t_list *list)
{
	ft_printf("%d\n", argc);
	if (argc <= 3)
		size_3_algorithm(list);
	else if (argc >= 4 && argc <= 5)
		size_5_algorithm(list);
	else if (argc >= 6 && argc <= 100)
		size_100_algorithm(list);
	else
		size_500_algorithm(list);
}