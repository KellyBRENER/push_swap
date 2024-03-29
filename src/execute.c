/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:09:27 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 09:39:42 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*execute les ra et rb et rr si possible*/
int	ft_rot(t_list **a, t_list **b, t_list *current)
{
	while (current->pos > 0 && current->target->pos > 0)
	{
		rr(a, b);
		current->pos--;
		current->target->pos--;
	}
	while (current->pos-- > 0)
	{
		rb(b);
	}
	while (current->target->pos-- > 0)
		ra(a);
	return (pa(a, b));
}

/*execute les rra et rrb et rrr si possible*/
int	ft_rev(t_list **a, t_list **b, t_list *current)
{
	while (current->nb_rev > 0 && current->target->nb_rev > 0)
	{
		rrr(a, b);
		current->nb_rev--;
		current->target->nb_rev--;
	}
	while (current->nb_rev-- > 0)
		rrb(b);
	while (current->target->nb_rev-- > 0)
		rra(a);
	return (pa(a, b));
}

/*execute les ra et rrb*/
int	ft_rot_rev(t_list **a, t_list **b, t_list *current)
{
	while (current->pos-- > 0)
		rb(b);
	while (current->target->nb_rev-- > 0)
		rra(a);
	return (pa(a, b));
}

/*execute les rra et rb*/
int	ft_rev_rot(t_list **a, t_list **b, t_list *current)
{
	while (current->target->pos-- > 0)
		ra(a);
	while (current->nb_rev-- > 0)
		rrb(b);
	return (pa(a, b));
}
