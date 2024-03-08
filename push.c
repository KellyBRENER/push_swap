/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:02:47 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/04 15:45:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	temp;
	//t_list	temp_dest;

	temp = NULL;
	//temp_dest = NULL;
	if (!dest)
		return (-1);
	temp = *dest;//stock la 1ere lst de la dest
	*dest = *src;//la 1ere lst de la source, devient la 1ere lst de la dest
	*src = *dest->next;//l'ancienne 2eme lst de le source, devient la 1ere
	*dest->next = temp;//l'ancienne 1ere lst de la dest devient la 2eme
	return (0);
}

void	pa(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return;
	write(1, "pa\n", 3);
	return;
}

void	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return;
	write(1, "pb\n", 3);
	return;
}
