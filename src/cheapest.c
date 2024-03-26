/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:59:50 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/26 15:09:00 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*renvoie la lst qui coute le moins cher à push dans b*/
t_list	*ft_target_in_a(t_list *a, int nb)
{
	t_list	*target;
	int		target_nbr;

	target = ft_search_lst(a, ft_nbmax(a));
	target_nbr = ft_nbmax(a);
	if (nb < ft_nbmin(a) || nb > ft_nbmax(a))
		return (ft_search_lst(a, ft_nbmin(a)));
	while (a)
	{
		if (a->nbr > nb && a->nbr < target_nbr)
		{
			target = a;
			target_nbr = a->nbr;
		}
		a = a->next;
	}
	return (target);
}

/*renvoie la lst qui coute le moins cher à push dans b*/
t_list	*ft_target_in_b(t_list *b, int nb)
{
	t_list	*target;
	int		target_nbr;

	target = ft_search_lst(b, ft_nbmin(b));
	target_nbr = ft_nbmin(b);
	if (nb < ft_nbmin(b) || nb > ft_nbmax(b))
		return (ft_search_lst(b, ft_nbmax(b)));
	while (b)
	{
		if (b->nbr < nb && b->nbr > target_nbr)
		{
			target = b;
			target_nbr = b->nbr;
		}
		b = b->next;
	}
	return (target);
}

//cherche la lst de a qui sera la - couteuse a déplacer dans b
t_list	*ft_cheapest(t_list *src, t_list *dst, int dir)
{
	int		move;
	int		move_min;
	t_list	*lst_move_min;
	t_list	*current;

	lst_move_min = src;
	current = src;
	move_min = ft_nbmove(src, dst, current, dir);
	current = current->next;
	while (current)
	{
		move = ft_nbmove(src, dst, current, dir);
		if (move == -1)
			return (perror("error in ft_nbmove"), NULL);
		if (move < move_min)
		{
			move_min = move;
			lst_move_min = current;
		}
		current = current->next;
	}
	return (lst_move_min);
}
