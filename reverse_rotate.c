/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/11 14:36:36 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
t_list	*ft_lstbeforelast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next)->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

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

void	rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return;
	write(1, "rra\n", 4);
	return;
}

void	rrb(t_list **b)
{
	if (reverse_rotate(b) == -1)
		return;
	write(1, "rrb\n", 4);
	return;
}

void	rrr(t_list **a, t_list **b)
{
	if (reverse_rotate(a) == -1)
		return;
	else if (reverse_rotate(b) == -1)
	{
		if (rotate(a) == -1)
			ft_printf("a move cannot be cancelled");
		return;
	}
	write(1, "rrr\n", 4);
	return;
}
