/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:13:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/21 11:16:49 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*check si les nbr d'une liste sont dans l'ordre croissant*/
int	check_stack(t_list *a)
{
	int nbr_max;

	nbr_max = a->nbr;
	a = a->next;
	while (a)
	{
		if (a->nbr < nbr_max)
			return (1);
		nbr_max = a->nbr;
		a = a->next;
	}
	return (0);
}

/*vérifie qu'il n'y a pas déjà ce nbr dans la liste*/
int	same_nbr(int nbr, t_list *a)
{
	while (a)
	{
		if (a->nbr == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

/*vérifie si les nbr correspondent aux règles du projet*/
int	check_nbr(int nbr, char *argv, t_list *a)
{
	if (nbr == 0 && argv[0] != '0')
	{
		ft_printf("invalid number");
		return (-1);
	}
	else if (nbr >= INT_MAX || nbr <= INT_MIN)
	{
		ft_printf("invalid number\n");
		return (-1);
	}
	else if (same_nbr(nbr, a) == 0)
	{
		ft_printf("there is two numbers identical");
		return (-1);
	}
	return (nbr);
}

/*calcule le nbr de nbr, la taille de la liste*/
int	ft_tablen(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
			return (i);
		i++;
	}
	return (i - 1);
}

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
		nbr = ft_atoi(argv[i]);
		if (check_nbr(nbr, argv[i], *a) == -1)
			return (-1);
		ft_lstadd_back(a, ft_lstnew_nbr(nbr));
		i++;
	}
	return (0);
}
