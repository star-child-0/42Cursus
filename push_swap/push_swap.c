#include "push_swap.h"

void list_clear(t_list *list)
{
}

int stackify(t_list *list, int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	list = ft_lstnew(argv[i]);
	if (!list)
		return (0);
	while (++i < argc)
		ft_lstadd_front(&list, ft_lstnew(argv[i]));
	return (1);
}

int check_repetition(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
	}
	return (1);
}

int argv_check(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	if (!check_repetition(argc, argv))
		return (0);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			if (!ft_isdigit(argv[i][j]))
				return (0);
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_list *list;

	if (argv_check(argc, argv) && stackify(list, argc, argv) && argc > 1)
	{
		ft_printf("Success\n");
		// stack_size();
	}
	else
		ft_printf("Error\n");
	return (0);
}