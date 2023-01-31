/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:01:12 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:20:11 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	ft_puterror(void);
int		*ft_check_args(int ac, char **av);
int		*ft_check_ints(int ac, char **av);
t_list	*ft_check_and_create(int ac, char **av);
int		ft_lst_issorted(t_list *lst);
void	ft_pswap(void **p1, void **p2);
void	ft_sab(t_list *top);
void	ft_sa(t_list *ta);
void	ft_sb(t_list *tb);
void	ft_ss(t_list *top_a, t_list *top_b);
void	ft_push(t_list **topfrom, t_list **topto);
void	ft_pa(t_list **tb, t_list **ta);
void	ft_pb(t_list **ta, t_list **tb);
void	ft_rotate(t_list **top);
void	ft_ra(t_list **ta);
void	ft_rb(t_list **tb);
void	ft_rr(t_list **ta, t_list **tb);
void	ft_rrotate(t_list **top);
void	ft_rra(t_list **ta);
void	ft_rrb(t_list **tb);
void	ft_rrr(t_list **ta, t_list **tb);
void	ft_sort3(t_list **ta);
void	ft_lilsort(t_list **ta, t_list **tb);
t_list	*ft_findmin(t_list	*lst);
void	ft_sort(t_list **ta, t_list **tb);

#endif
