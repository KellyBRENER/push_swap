/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:09:27 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/21 13:48:55 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*execute les ra et rb et rr si possible*/
int	ft_rot(t_list **src, t_list **dst, t_list *current, int dir)
{
	while (current->pos > 0 && current->target->pos > 0)
	{
		rr(src, dst);
		current->pos--;
		current->target->pos--;
	}
	while (dir == 0 && current->pos-- > 0)
		ra(src);
	while (dir == 1 && current->pos-- > 0)
		rb(src);
	while (dir == 0 && current->target->pos-- > 0)
		rb(dst);
	while (dir == 1 && current->target->pos-- > 0)
		ra(dst);
	if (dir == 0)
		return (pb(src, dst));
	return (pa(dst, src));
}

/*execute les rra et rrb et rrr si possible*/
int	ft_rev(t_list **src, t_list **dst, t_list *current, int dir)
{
	while (current->nb_rev > 0 && current->target->nb_rev > 0)
	{
		rrr(src, dst);
		current->nb_rev--;
		current->target->nb_rev--;
	}
	while (dir == 0 && current->nb_rev-- > 0)
		rra(src);
	while (dir == 1 && current->nb_rev-- > 0)
		rrb(src);
	while (dir == 0 && current->target->nb_rev-- > 0)
		rrb(dst);
	while (dir == 1 && current->target->nb_rev-- > 0)
		rra(dst);
	if (dir == 0)
		return (pb(src, dst));
	return (pa(dst, src));
}

/*execute les ra et rrb ou rra et rb*/
int	ft_rot_rev(t_list **src, t_list **dst, t_list *current, int dir, int sens)
{
	//if dir = 0 on va de a vers b
	//if sens = 1 on rot src et rev dst
	while (dir == 0 && sens == 1 && current->pos-- > 0)//rot = a, rev = b
		ra(src);
	while (dir == 1 && sens == 1 && current->pos-- > 0)//rot = b, rev = a
		rb(src);
	while (dir == 0 && sens == 0 && current->target->pos-- > 0)//rev = a, rot = b
		rb(dst);
	while (dir == 1 && sens == 0 && current->target->pos-- > 0)//rev = b, rot = a
		ra(dst);
	while (dir == 0 && sens == 1 && current->target->nb_rev-- > 0)
		rrb(dst);
	while (dir == 1 && sens == 1 && current->target->nb_rev-- > 0)
		rra(dst);
	while (dir == 0 && sens == 0 && current->nb_rev-- > 0)
		rra(src);
	while (dir == 1 && sens == 0 && current->nb_rev-- > 0)
		rrb(src);
	if (dir == 0)
		return (pb(src, dst));
	return (pa(dst, src));
}
