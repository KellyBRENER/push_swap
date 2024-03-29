/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:12:38 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/29 11:13:34 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_clean(t_list	**a, t_list **b)
{
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
}
