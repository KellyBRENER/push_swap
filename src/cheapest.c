/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:59:50 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 10:10:00 by kbrener-         ###   ########.fr       */
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

/*initialise target, pos et nb_rev des listes de la stack a ou b*/
void	ft_init_current(t_list *src, t_list *dst, t_list *current)
{
	current->target = ft_target_in_a(dst, current->nbr);
	current->pos = ft_pos_lst(src, current);
	if (current->pos == 0)
		current->nb_rev = 0;
	else
		current->nb_rev = ft_lstsize(src) - current->pos;
}

/*initialise pos et nb_rev des listes de la stack b*/
void	ft_init_target(t_list *lst, t_list *target)
{
	target->pos = ft_pos_lst(lst, target);
	if (target->pos == 0)
		target->nb_rev = 0;
	else
		target->nb_rev = ft_lstsize(lst) - target->pos;
}

//compte le nombre de move pour déblacer lst_a dans b
int	ft_nbmove(t_list *src, t_list *dst, t_list *current)
{
	ft_init_current(src, dst, current);
	ft_init_target(dst, current->target);
	return (ft_movemin(current, current->target));
}

//cherche la lst de a qui sera la - couteuse a déplacer dans b
t_list	*ft_cheapest(t_list *src, t_list *dst)
{
	int		move;
	int		move_min;
	t_list	*lst_move_min;
	t_list	*current;

	lst_move_min = src;
	current = src;
	move_min = ft_nbmove(src, dst, current);
	current = current->next;
	while (current)
	{
		move = ft_nbmove(src, dst, current);
		if (move == -1)
			return (NULL);
		if (move < move_min)
		{
			move_min = move;
			lst_move_min = current;
		}
		current = current->next;
	}
	return (lst_move_min);
}
