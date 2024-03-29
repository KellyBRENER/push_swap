/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:07:21 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 10:07:52 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//renvoie le nb le plus petit parmi les 4
int	ft_movemin(t_list *current, t_list *target)
{
	int	rot;
	int	rev;
	int	rotrev;
	int	revrot;

	if (current->pos < target->pos)
		rot = target->pos;
	else
		rot = current->pos;
	if (current->nb_rev < target->nb_rev)
		rev = target->nb_rev;
	else
		rev = current->nb_rev;
	rotrev = current->pos + target->nb_rev;
	revrot = current->nb_rev + target->pos;
	if (rot < rev && rot < rotrev && rot < revrot)
		return (current->best_move = 1, rot);
	if (rev < rot && rev < rotrev && rev < revrot)
		return (current->best_move = 2, rev);
	if (rotrev < revrot)
		return (current->best_move = 3, rotrev);
	return (current->best_move = 4, revrot);
}

//cherche le nb max dans une liste chainée
int	ft_nbmax(t_list *lst)
{
	int	nb_max;

	nb_max = lst->nbr;
	lst = lst->next;
	while (lst)
	{
		if (lst->nbr > nb_max)
			nb_max = lst->nbr;
		lst = lst->next;
	}
	return (nb_max);
}

//cherche le nb le plus petit d'une liste
int	ft_nbmin(t_list *lst)
{
	int	nb_min;

	nb_min = lst->nbr;
	lst = lst->next;
	while (lst)
	{
		if (lst->nbr < nb_min)
			nb_min = lst->nbr;
		lst = lst->next;
	}
	return (nb_min);
}

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
