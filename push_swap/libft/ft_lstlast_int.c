#include "libft.h"

t_intl	*ft_lstlast_int(t_intl *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
