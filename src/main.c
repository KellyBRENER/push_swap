/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:31 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/02 15:23:41 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		init;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	init = ft_init_push(argc, argv, &a);
	if (init == 0)
	{
		if (ft_push_swap(&a, &b) == -1 || ft_check_stack(a) == 1)
		{
			ft_clean(&a, &b);
			ft_printf("push_swap failed");
			return (1);
		}
		ft_clean(&a, &b);
		return (0);
	}
	else if (init == 1)
		return (0);
	write(2, "Error\n", 6);
	return (1);
}

