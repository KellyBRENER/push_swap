/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:29:50 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/20 17:19:13 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*renvoie la position d'une liste dans la liste chainée*/
int	ft_pos_lst(t_list *lst, t_list *current)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nbr == current->nbr)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

t_list	*ft_lstbeforenb(t_list *b, t_list *target)
{
	int	i;
	int	j;
	ft_init_lstb(b, target);
	t_list	*lst;

	lst = NULL;
	i = target->pos;
	j = 0;
	if (i == 0)
		lst = ft_lstlast(b);
	while (j++ < i)
	{
		lst = b;
		b = b->next;
	}
	return (lst);
}

/*renvoie la lst qui coute le moins cher à positionner en 1er
dans la liste chainée*/
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

//compte le nombre de rotation totale (ra, rb et rr)
int	ft_nb_rot(t_list *current, t_list *target)
{
	if (current->pos < target->pos)
		return (target->pos);
	return (current->pos);
}

//compte le nombre de reverse totale (rra, rrb et rrr)
int	ft_nb_rev(t_list *current, t_list *target)
{
	if (current->nb_rev < target->nb_rev)
		return (target->nbr);
	return (current->nb_rev);
}

int	ft_init_lsta(t_list *a, t_list *b, t_list *current)
{
	current->target = ft_target_in_b(b, current->nbr);
	current->pos = ft_pos_lst(a, current);
	current->nb_rev = ft_lstsize(a) - ft_pos_lst(a, current);
	if (current->target == NULL || current->pos == -1 || current->nb_rev == -1)
		return (-1);
	return (0);
}

int	ft_init_lstb(t_list *b, t_list *target)
{
	target->pos = ft_pos_lst(b, target);
	target->nb_rev = ft_lstsize(b) - target->pos;
	if (target->pos == -1 || target->nb_rev == -1)
		return (-1);
	return (0);
}

//compte le nombre de move pour déblacer lst_a dans b
int	ft_nbmove(t_list *a, t_list *b, t_list *current)
{
	int	rot;
	int	rev;
	int	rota_revb;
	int	reva_rotb;

	if (ft_init_lsta(a, b, current) == -1 ||
			ft_init_lstb(b, current->target) == -1)
			return (-1);
	rot = ft_nb_rot(current, current->target);
	rev = ft_nb_rev(current, current->target);
	rota_revb = current->pos + current->target->nb_rev;
	reva_rotb = current->nb_rev + current->target->pos;
	if (rot < rev && rot < rota_revb && rot < reva_rotb)
	{
		current->best_move = 1;
		return (rot);
	}
	if (rev < rot && rev < rota_revb && rev < reva_rotb)
	{
		current->best_move = 2;
		return (rev);
	}
	if (rota_revb < reva_rotb)
	{
		current->best_move = 3;
		return (rota_revb);
	}
	current->best_move = 4;
	return (reva_rotb);
}

//cherche la lst de a qui sera la - couteuse a déplacer dans b
t_list	*ft_cheapest_in_a(t_list *a, t_list *b)
{
	int	move;
	int	move_min;
	t_list	*lst_move_min;
	t_list	*current;

	lst_move_min = a;
	current = a;
	move_min = ft_nbmove(a, b, current);
	current = current->next;
	while (current)
	{
		move = ft_nbmove(a, b, current);
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

int	ft_rev(t_list **a, t_list **b, t_list *current)
{
	int	nb_rev_a;
	int	nb_rev_b;
	int	i;

	if (current->nb_rev < current->target->nb_rev)
	{
		i = current->nb_rev;
		nb_rev_b = current->target->nb_rev - i;
		nb_rev_a = 0;
	}
	else
	{
		i = current->target->nb_rev;
		nb_rev_b = 0;
		nb_rev_a = current->nb_rev - i;
	}
	while (i-- > 0)
		rrr(a, b);
	while (nb_rev_a-- > 0)
		rra(a);
	while (nb_rev_b-- > 0)
		rrb(b);
	return (pb(a, b));
}

int	ft_rot(t_list **a, t_list **b, t_list *current)
{
	int	nb_rot_a;
	int	nb_rot_b;
	int	i;

	if (current->pos < current->target->pos)
	{
		i = current->pos;
		nb_rot_b = current->target->pos - i;
		nb_rot_a = 0;
	}
	else
	{
		i = current->target->pos;
		nb_rot_b = 0;
		nb_rot_a = current->pos - i;
	}
	while (i-- > 0)
		rr(a, b);
	while (nb_rot_a-- > 0)
		ra(a);
	while (nb_rot_b-- > 0)
		rb(b);
	return (pb(a, b));
}

int	ft_rot_rev(t_list **a, t_list **b, t_list *current, int dir)
{
	int	rot;
	int	rev;

	if (dir == 1)
	{
		rot = current->pos;
		rev = current->target->nb_rev;
		while (rot-- > 0)
			ra(a);
		while (rev-- > 0)
			rrb(b);
		return (pb(a, b));
	}
	rot = current->target->pos;
	rev = current->nb_rev;
	while (rot-- >0)
		rb(b);
	while (rev-- > 0)
		rra(a);
	return (pb(a, b));
}

//fait les rot ou rev et push a vers b
int	ft_a_to_b(t_list **a, t_list **b, t_list *current)
{
	if (!current)
		return (-1);
	if (current->best_move == 1)
		return (ft_rot(a, b, current));
	if (current->best_move == 2)
		return (ft_rev(a, b, current));
	if (current->best_move == 3)
		return (ft_rot_rev(a, b, current, 1));
	return (ft_rot_rev(a, b, current, 0));

}
int	push_swap(t_list **a, t_list **b)
{
	pb(a, b);
	while (ft_lstsize(*a) > 3)
	{
		if (ft_a_to_b(a, b, ft_cheapest_in_a(*a, *b)) == -1)
			return (-1);
	}
	if (tiny_sort(a) == -1)
		return (-1);
	if (ft_b_to_a(a, b) == -1)
		return (-1);
	if (check_stack(*a) == -1)
		return (-1);
	return (0);
}
/*il faut trouver le nbr le plus proche de nba dans b
comme les nbr sont dans l'ordre décroissant dans b
si on trouve un nbr inf à nba, le nbb d'apres sera forcément
le nbb sup le plus proche
ensuite il faut chercher a déplacer nbb inf en haut*/
