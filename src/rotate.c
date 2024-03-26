/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:52:22 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/26 15:12:10 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (!lst || !*lst || !(*lst)->next)
		return (-1);
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
	return (0);
}

int	ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **b)
{
	if (rotate(b) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if (rotate(a) == -1)
		return (-1);
	else if (rotate(b) == -1)
	{
		if (reverse_rotate(a) == -1)
			perror("a move cannot be cancelled");
		return (-1);
	}
	write(1, "rr\n", 3);
	return (0);
}
