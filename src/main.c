/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:31 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:40 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Rien si pas d'arguments
		si liste déjà triée
		si liste contient un seul nbr
	Error si nbr autre que int
		si nbr en double
	liste d'instructions:
		inf à 4 pour 3 nbr
		inf à 13 pour 5 nbr
		inf à 700 pour 100 nbr
		inf à 5500 pour 500 nbr
	Pas de leak ou segfault
*/
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
	else if (init == -1)
		return (write(2, "Error\n", 6), 1);
	if (ft_lstsize(a) <= 3 || ft_check_stack(a) == 0)
	{
		if (ft_check_stack(a) == 1 && ft_tiny_sort(&a) == -1)
			return (ft_lstclear(&a, free), 1);
		return (ft_lstclear(&a, free), 0);
	}
	else if (ft_push_swap(&a, &b) == -1 || ft_check_stack(a) == 1)
		return (ft_clean(&a, &b), 1);
	return (ft_clean(&a, &b), 0);
}
