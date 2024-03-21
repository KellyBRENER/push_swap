/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:59:50 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/21 14:07:40 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*renvoie la lst qui coute le moins cher à push dans b*/
t_list	*ft_target_in_a(t_list *a, int nb)
{
	t_list	*target;
	int	target_nbr;

	target = ft_search_lst(a, ft_nbmax(a));
	if (!a)
		return (a);
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
	int	target_nbr;

	target = ft_search_lst(b, ft_nbmin(b));
	if (!b)
		return (b);
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

/*initialise target, pos et nb_rev des listes de la stack a ou b*/
int	ft_init_current(t_list *src, t_list *dst, t_list *current, int dir)
{
	if (dir == 0)
		current->target = ft_target_in_b(dst, current->nbr);
	else
		current->target = ft_target_in_a(dst, current->nbr);
	current->pos = ft_pos_lst(src, current);
	current->nb_rev = ft_lstsize(src) - ft_pos_lst(src, current);
	if (current->target == NULL || current->pos == -1 || current->nb_rev == -1)
		return (-1);
	return (0);
}

/*initialise pos et nb_rev des listes de la stack b*/
int	ft_init_target(t_list *lst, t_list *target)
{
	target->pos = ft_pos_lst(lst, target);
	target->nb_rev = ft_lstsize(lst) - target->pos;
	if (target->pos == -1 || target->nb_rev == -1)
		return (-1);
	return (0);
}

//compte le nombre de move pour déblacer lst_a dans b
int	ft_nbmove(t_list *src, t_list *dst, t_list *current, int dir)
{
	int	rot;
	int	rev;
	int	rotsrc_revdst;
	int	revsrc_rotdst;
	if (ft_init_current(src, dst, current, dir) == -1 ||
			ft_init_target(dst, current->target) == -1)
		return (-1);
	rot = ft_nb_rot(current, current->target);
	rev = ft_nb_rev(current, current->target);
	rotsrc_revdst = current->pos + current->target->nb_rev;
	revsrc_rotdst = current->nb_rev + current->target->pos;
	if (rot < rev && rot < rotsrc_revdst && rot < revsrc_rotdst)
	{
		current->best_move = 1;
		return (rot);
	}
	if (rev < rot && rev < rotsrc_revdst && rev < revsrc_rotdst)
	{
		current->best_move = 2;
		return (rev);
	}
	if (rotsrc_revdst < revsrc_rotdst)
	{
		current->best_move = 3;
		return (rotsrc_revdst);
	}
	current->best_move = 4;
	return (revsrc_rotdst);
}

//cherche la lst de a qui sera la - couteuse a déplacer dans b
t_list	*ft_cheapest(t_list *src, t_list *dst, int dir)
{
	int	move;
	int	move_min;
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
			return (ft_printf("error in ft_nbmove"), NULL);
		if (move < move_min)
		{
			move_min = move;
			lst_move_min = current;
		}
		current = current->next;
	}
	return (lst_move_min);
}
