/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:00:22 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/04 11:54:49 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_init
	/*verifie que chaque string ne contient que des chiffres
	convertit chaque string de char en int
	verifie qu'il fasse partie des int (entre int max et min)
	verifie que le nbr ne soit pas egal a un autre nbr de la liste
	cree la liste pour le 1er nombre
	ajoute les autres nbr a la fin de la liste chainee*/

int	ft_stack_init(t_list **a, char **argv, int i)
{
	int	nbr;

	while (argv[i])
	{
		if (ft_check_str(argv[i]) == -1)
			return (-1);
		nbr = ft_atoi(argv[i]);
		if (ft_check_nbr(nbr, argv[i], *a) == -1)
			return (-1);
		ft_lstadd_back(a, ft_lstnew_nbr(nbr));
		i++;
	}
	return (0);
}

int	ft_init_push(int argc, char **argv, t_list **a)
{
	int	i;

	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	if (ft_stack_init(a, argv, i) == -1)
		return (-1);
	if (i == 0)
		ft_freetab(argv);
	if (a == NULL)
		return (ft_lstclear(a, free), ft_printf("initialisation failed"), -1);
	return (0);
}
