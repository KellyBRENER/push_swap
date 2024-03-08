/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:39:00 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/04 15:01:35 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	swap(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (!lst || !*lst || !*lst->next)
		return (-1);
	temp = *lst;
	*lst = *lst->next;
	temp->next = *lst->next;
	*lst->next = temp;
	return (0);
}
void	sa(t_list **a)
{
	if (swap(a) == -1)
		return;
	write(1, "sa\n", 3);
	return;
}

void	sb(t_list **b)
{
	if (swap(b) == -1)
		return;
	write(1, "sb\n", 3);
	return;
}

void	ss(t_list **a, t_list **b)
{
	if (swap(a) == -1 || swap(b) == -1)
		return;
	write(1, "ss\n", 3);
	return;
}
