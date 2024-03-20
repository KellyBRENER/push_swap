/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:38:09 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:01 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
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

//renvoie la lst dont le nbr = nbr_max
t_list	*ft_search_lst(t_list *lst, int nb)
{
	while (lst)
	{
		if (lst->nbr == nb)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
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
//remet tous les nbr de b dans a, dans le bon ordre
int	ft_b_to_a(t_list **a, t_list **b)
{
	int	bmax;
	int	amax;
	int	amin;
	t_list	*lst_extrem;
	int	i;


	while (*b)
	{
		amin = ft_nbmin(*a);
		bmax = ft_nbmax(*b);
		amax = ft_nbmax(*a);
		if (bmax > amax && (*b)->nbr == bmax)//mettre amax en dernier dans a
		{
			lst_extrem = ft_search_lst(*a, amax);
			lst_extrem->pos = ft_pos_lst(*a, lst_extrem);
			lst_extrem->nb_rev = ft_lstsize(*a) - lst_extrem->pos;
			if (lst_extrem->nb_rev < lst_extrem->pos)
			{
				i = lst_extrem->nb_rev - 1;
				while (i-- > 0)
					rra(a);
			}
			else
			{
				i = lst_extrem->pos + 1;
				while (i-- > 0)
					ra(a);
			}
			pa(a, b);
		}
		else if ((*b)->nbr < amin)//mettre amin en 1er
		{
			lst_extrem = ft_search_lst(*a, amin);
			lst_extrem->pos = ft_pos_lst(*a, lst_extrem);
			lst_extrem->nb_rev = ft_lstsize(*a) - lst_extrem->pos;
			if (lst_extrem->nb_rev < lst_extrem->pos)
			{
				i = lst_extrem->nb_rev;
				while (i-- > 0)
					rra(a);
			}
			else
			{
				i = lst_extrem->pos;
				while (i-- > 0)
					ra(a);
			}
			pa(a, b);
		}
		else if ((*a)->nbr < (*b)->nbr)
		{
			if (ra(a) == -1)
				return (-1);
		}
		else if ((*a)->nbr > (*b)->nbr)
		{
			if (ft_lstlast(*a)->nbr < (*b)->nbr)
			{
				if (pa(a, b) == -1)
					return (-1);
			}
			else
			{
				if (rra(a) == -1)
					return (-1);
			}
		}
	}
	amin = ft_nbmin(*a);
	lst_extrem = ft_search_lst(*a, amin);
	lst_extrem->pos = ft_pos_lst(*a, lst_extrem);
	lst_extrem->nb_rev = ft_lstsize(*a) - lst_extrem->pos;
	if (lst_extrem->pos < lst_extrem->nb_rev)
	{
		while ((*a)->nbr != amin)
			ra(a);
		return (0);
	}
	while ((*a)->nbr != amin)
		rra(a);
	return (0);
}
