/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/22 11:25:47 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	temp = NULL;
	last = NULL;
	if (!lst || !*lst || !(*lst)->next)
		return (-1);
	temp = *lst;
	last = ft_lstlast(*lst);
	ft_lstbeforelast(*lst)->next = NULL;
	*lst = last;
	(*lst)->next = temp;
	return (0);
}

int	rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	else if (reverse_rotate(b) == -1)
	{
		if (rotate(a) == -1)
			ft_printf("a move cannot be cancelled");
		return (-1);
	}
	write(1, "rrr\n", 4);
	return (0);
}
