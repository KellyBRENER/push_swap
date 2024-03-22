/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:42:49 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/22 11:23:16 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tiny_sort => pour 3 nbr
int	tiny_sort(t_list **a)
{
	if ((*a)->nbr == ft_nbmax(*a))
	{
		ra(a);
		if ((*a)->nbr != ft_nbmin(*a))
			sa(a);
	}
	else if ((*a)->nbr == ft_nbmin(*a))
	{
		sa(a);
		ra(a);
	}
	else if ((((*a)->next)->next)->nbr == ft_nbmax(*a))
		sa(a);
	else
		rra(a);
	if (check_stack(*a) == 1)
		return (-1);
	return (0);
}

//fait les rot ou rev et push a vers b
int	ft_src_to_dst(t_list **a, t_list **b, t_list *current, int dir)
{
	if (!current)
		return (-1);
	if (current->best_move == 1)
		return (ft_rot(a, b, current, dir));
	if (current->best_move == 2)
		return (ft_rev(a, b, current, dir));
	if (current->best_move == 3)
		return (ft_rot_rev(a, b, current, dir));
	return (ft_rev_rot(a, b, current, dir));
}

/*principe: la stack b sera remplie petit à petit dans l'ordre décroissant
les lst seront ainsi remise dans a dans l'ordre croissant
1. déplacer 2 lst dans b
2. chercher dans a la lst qui demandera le moins de mouvement
pour être déplacer dans b*/
int	push_swap(t_list **a, t_list **b)
{
	pb(a, b);
	while (ft_lstsize(*a) > 3)
	{
		if (ft_src_to_dst(a, b, ft_cheapest(*a, *b, 0), 0) == -1)
			return (-1);
	}
	if (tiny_sort(a) == -1)
		return (-1);
	while (*b)
	{
		if (ft_src_to_dst(a, b, ft_cheapest(*b, *a, 1), 1) == -1)
			return (-1);
	}
	while ((*a)->nbr != ft_nbmin(*a))
		ra(a);
	if (check_stack(*a) == -1)
		return (-1);
	return (0);
}
