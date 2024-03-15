/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:38:09 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/15 16:18:31 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//remet tous les nbr de b dans a, dans le bon ordre
int	ft_b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		if ((*a)->nbr < (*b)->nbr)
			if (ra(a) == -1)
				return (-1);
		else
			if (ft_lstlast(*a)->nbr < (*b)->nbr)
				if (pa(a, b) == -1)
					return (-1);
			if (rra(a) == -1)
				return (-1);
	}
	return (0);
}
