/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:08:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/28 16:32:41 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*tri les nombres et renvoie le nombre median*/
int	ft_sorttab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
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
	return (tab[size / 2]);
}

int	ft_getmedian(t_list *a, int size)
{
	int	tab[2000];
	int	i;

	i = 0;
	while (a)
	{
		tab[i++] = a->nbr;
		a = a->next;
	}
	return (ft_sorttab(tab, size));
}

void	ft_presort(t_list **a, t_list **b)
{
	int	median;

	median = ft_getmedian(*a, ft_lstsize(*a));
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
}
