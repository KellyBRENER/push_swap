/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:25:45 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 11:24:53 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*renvoie la lst qui coute le moins cher à push dans b*/
t_list	*ft_target_in_b(t_list *b, int nb)
{
	t_list	*target;
	int		target_nbr;

	target = ft_search_lst(b, ft_nbmin(b));
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
int	ft_checker(t_list *a)
{
	while (a)
	{
		
	}
}
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		init;

	a = NULL;
	b = NULL;
	init = ft_init_push(argc, argv, &a);
	if (init == 1)
		return (0);
	else if (init == -1 || push_swap(&a, &b) == -1)
	{
		ft_clean(&a, &b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!b || ft_checker(a) == 1)
		write(1,"KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_clean(&a, &b);
	return (0);
}
