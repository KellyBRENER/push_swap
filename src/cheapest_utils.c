/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:07:21 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/28 12:16:48 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (target->nb_rev);
	return (current->nb_rev);
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
