/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:36:40 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/21 14:08:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*imprime les listes*/
void	print_lst(t_list *lst, char *c)
{
	ft_printf("liste %s\n", c);
	while (lst)
	{
		ft_printf("%d / ", lst->nbr);
		lst = lst->next;
	}
}

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

/*renvoie la liste qui précède la target*/
t_list	*ft_lstbeforetarget(t_list *lst, t_list *target)
{
	int	i;
	ft_init_target(lst, target);

	i = 0;
	if (target->pos == 0)
		return (ft_lstlast(lst));
	while (i++ < target->pos - 1)
		lst = lst->next;
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
