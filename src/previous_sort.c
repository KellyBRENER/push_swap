/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:08:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/26 13:48:44 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorttab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	if (tab[size / 2] == -1)
		return tab[(size / 2) + 1];
	return (tab[size / 2]);
}

int	ft_getmedian(t_list *a, int size)
{
	int	tab[2000];
	int	i;
	int median;

	i = 0;
	median = 0;
	while (a)
	{
		tab[i++] = a->nbr;
		a = a->next;
	}
	median = ft_sorttab(tab, size);
	return (median);
}

int	ft_presort(t_list **a, t_list **b)
{
	int	median;

	median = ft_getmedian(*a, ft_lstsize(*a));
	if (median == -1)
		return (perror("error in median calculation"), -1);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nbr > median)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	return (0);
}
