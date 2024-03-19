/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:57 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/19 10:54:18 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int	same_nbr(int nbr, t_list *a);
int	check_nbr(int nbr, char *argv, t_list *a);
int	ft_tablen(char **argv);
int	stack_init(t_list **a, char **argv);
int	swap(t_list **lst);
int	sa(t_list **a);
int	sb(t_list **b);
int	ss(t_list **a, t_list **b);
int	rotate(t_list **lst);
int	ra(t_list **a);
int	rb(t_list **b);
int	rr(t_list **a, t_list **b);
int	reverse_rotate(t_list **lst);
int	rra(t_list **a);
int	rrb(t_list **b);
int	rrr(t_list **a, t_list **b);
int	push(t_list **src, t_list **dest);
int	pa(t_list **a, t_list **b);
int	pb(t_list **a, t_list **b);
void	print_lst(t_list *lst, char *c);
t_list	*ft_lstnew_nbr(int nbr);
t_list	*ft_lstbeforelast(t_list *lst);
int	check_stack(t_list *a);
int	tiny_sort(t_list **a);
int	ft_pos_lst(t_list *lst, t_list *current);
t_list	*ft_lstbeforenb(t_list *b, t_list *target);
t_list	*ft_target_in_b(t_list *b, int nb);
int	ft_nb_rot(t_list *current, t_list *target);
int	ft_nb_rev(t_list *current, t_list *target);
int	ft_init_lsta(t_list *a, t_list *b, t_list *current);
int	ft_init_lstb(t_list *b, t_list *target);
int	ft_nbmove(t_list *a, t_list *b, t_list *current);
t_list	*ft_cheapest_in_a(t_list *a, t_list *b);
int	ft_rev(t_list **a, t_list **b, t_list *current);
int	ft_rot(t_list **a, t_list **b, t_list *current);
int	ft_rot_rev(t_list **a, t_list **b, t_list *current, int dir);
int	ft_a_to_b(t_list **a, t_list **b, t_list *current);
int	push_swap(t_list **a, t_list **b);
int	ft_b_to_a(t_list **a, t_list **b);
int	ft_nbmax(t_list *lst);
int	ft_nbmin(t_list *lst);
t_list	*ft_search_lst(t_list *lst, int nb);

#endif
