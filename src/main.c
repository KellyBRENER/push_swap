/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:31 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/26 15:11:18 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_push(int argc, char **argv, t_list **a)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (perror("incorrect argument count"), -1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (stack_init(a, argv) == -1)
		return (perror("initialisation failed"), -1);
	if (a == NULL)
	{
		ft_lstclear(a, free);
		return (perror("initialisation failed"), -1);
	}
	if (check_stack(*a) == 0)
	{
		ft_lstclear(a, free);
		perror("numbers already sorted");
		return (1);
	}
	if (ft_tablen(argv) == 3)
	{
		if (tiny_sort(a) == -1)
			return (ft_lstclear(a, free), -1);
		return (ft_lstclear(a, free), 1);
	}
	return (0);
}

void	ft_clean(t_list	**a, t_list **b)
{
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		init;

	a = NULL;
	b = NULL;
	init = ft_init_push(argc, argv, &a);
	if (init == 0)
	{
		if (push_swap(&a, &b) == -1 || check_stack(a) == 1)
		{
			ft_clean(&a, &b);
			perror("push_swap failed");
			return (1);
		}
		//print_lst(a, "liste a after sort");
		ft_clean(&a, &b);
		return (0);
	}
	else if (init == 1)
		return (0);
	return (1);
}
