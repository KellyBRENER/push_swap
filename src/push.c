/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:02:47 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/22 11:28:54 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	temp = NULL;
	if (!dest)
		return (-1);
	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
