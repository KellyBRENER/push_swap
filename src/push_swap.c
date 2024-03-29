/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:42:49 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 11:16:55 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_init
	/*convertit chaque string de char en int
	verifie qu'il fasse partie des int (entre int max et min)
	verifie que le nbr ne soit pas egal a un autre nbr de la liste
	cree la liste pour le 1er nombre
	ajoute les autres nbr a la fin de la liste chainee*/

int	stack_init(t_list **a, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	while (argv[i])
	{
		if (ft_check_str(argv[i]) == -1)
			return (-1);
		nbr = ft_atoi(argv[i]);
		if (check_nbr(nbr, argv[i], *a) == -1)
			return (-1);
		ft_lstadd_back(a, ft_lstnew_nbr(nbr));
		i++;
	}
	return (0);
}

/*vérifie le nombres d'arguments et initialise la stack*/
int	ft_init_push(int argc, char **argv, t_list **a)
{
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (stack_init(a, argv) == -1)
		return (-1);
	if (a == NULL)
		return (-1);
	if (check_stack(*a) == 0)
	{
		ft_lstclear(a, free);
		return (1);
	}
	if (ft_tablen(argv) == 3)
	{
		if (tiny_sort(a) == -1)
			return (-1);
		return (ft_lstclear(a, free), 1);
	}
	return (0);
}

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
int	ft_src_to_dst(t_list **a, t_list **b, t_list *current)
{
	if (!current)
		return (-1);
	if (current->best_move == 1)
		return (ft_rot(a, b, current));
	if (current->best_move == 2)
		return (ft_rev(a, b, current));
	if (current->best_move == 3)
		return (ft_rot_rev(a, b, current));
	return (ft_rev_rot(a, b, current));
}

/*principe: la stack b sera remplie petit à petit dans l'ordre décroissant
les lst seront ainsi remise dans a dans l'ordre croissant
1. déplacer 2 lst dans b
2. chercher dans a la lst qui demandera le moins de mouvement
pour être déplacer dans b*/
int	push_swap(t_list **a, t_list **b)
{
	pb(a, b);
	ft_presort(a, b);
	if (check_stack(*a) == 1 && tiny_sort(a) == -1)
		return (-1);
	while (*b)
	{
		if (ft_src_to_dst(a, b, ft_cheapest(*b, *a)) == -1)
			return (-1);
	}
	ft_init_target(*a, ft_search_lst(*a, ft_nbmin(*a)));
	while ((*a)->nbr != ft_nbmin(*a))
	{
		if ((ft_search_lst(*a, ft_nbmin(*a))->pos) < (ft_lstsize(*a) / 2))
			ra(a);
		else
			rra(a);
	}
	return (0);
}
