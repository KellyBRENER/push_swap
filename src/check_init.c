/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:13:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 11:15:27 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check si les nbr d'une liste sont dans l'ordre croissant*/
int	check_stack(t_list *a)
{
	int	nbr_max;

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
		return (-1);
	else if (nbr > INT_MAX || nbr < INT_MIN)
		return (-1);
	else if (same_nbr(nbr, a) == 0)
		return (-1);
	return (0);
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	return (0);
}
