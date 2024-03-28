/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:15:06 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/28 13:11:49 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//renvoie le nb le plus petit parmi les 4
int	ft_movemin(int rot, int rev, int rotrev, int revrot)
{
	if (rot < rev && rot < rotrev && rot < revrot)
		return (rot);
	if (rev < rot && rev < rotrev && rev < revrot)
		return (rev);
	if (rotrev < revrot)
		return (rotrev);
	return (revrot);
}

//compte le nombre de move pour déblacer lst_a dans b
int	ft_nbmove(t_list *src, t_list *dst, t_list *current, int dir)
{
	int	rot;
	int	rev;
	int	rotrev;
	int	revrot;
	int	movemin;

	ft_init_current(src, dst, current, dir);
	ft_init_target(dst, current->target);
	rot = ft_nb_rot(current, current->target);
	rev = ft_nb_rev(current, current->target);
	rotrev = current->pos + current->target->nb_rev;
	revrot = current->nb_rev + current->target->pos;
	movemin = ft_movemin(rot, rev, rotrev, revrot);
	if (movemin == rot)
		current->best_move = 1;
	else if (movemin == rev)
		current->best_move = 2;
	else if (movemin == rotrev)
		current->best_move = 3;
	else if (movemin == revrot)
		current->best_move = 4;
	return (movemin);
}

/*initialise target, pos et nb_rev des listes de la stack a ou b*/
void	ft_init_current(t_list *src, t_list *dst, t_list *current, int dir)
{
	if (dir == 0)
		current->target = ft_target_in_b(dst, current->nbr);
	else
		current->target = ft_target_in_a(dst, current->nbr);
	current->pos = ft_pos_lst(src, current);
	if (current->pos == 0)
		current->nb_rev = 0;
	else
		current->nb_rev = ft_lstsize(src) - current->pos;
	if (current->target == NULL || current->pos == -1 || current->nb_rev == -1)
		ft_error(1);
}

/*initialise pos et nb_rev des listes de la stack b*/
void	ft_init_target(t_list *lst, t_list *target)
{
	target->pos = ft_pos_lst(lst, target);
	if (target->pos == 0)
		target->nb_rev = 0;
	else
		target->nb_rev = ft_lstsize(lst) - target->pos;
	if (target->pos == -1 || target->nb_rev == -1)
		ft_error(1);
}
