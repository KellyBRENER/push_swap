/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:57 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/11 16:19:55 by kbrener-         ###   ########.fr       */
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
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
int	rotate(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
int	reverse_rotate(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int	push(t_list **src, t_list **dest);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	print_lst(t_list *lst, char c);
t_list	*ft_lstnew_nbr(int nbr);
t_list	*ft_lstbeforelast(t_list *lst);
int	check_stack(t_list *a);

#endif
