/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:36:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/02 15:06:04 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*crée une nouvelle lst avec un nbr*/
t_list	*ft_lstnew_nbr(int nbr)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->nbr = nbr;
	lst->content = NULL;
	lst->next = NULL;
	return (lst);
}

/*renvoie l'avant derniere liste*/
t_list	*ft_lstbeforelast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next)->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*renvoie la lst dont le nbr = nb*/
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
