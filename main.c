/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:31 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/22 11:28:00 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (perror("incorrect argument count"), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (stack_init(&a, argv) == -1)
		return (1);
	if (a == NULL)
	{
		ft_lstclear(&a, free);
		return (perror("stack a initialisation failed"), 1);
	}
	if (check_stack(a) == 0)
	{
		ft_lstclear(&a, free);
		ft_printf("numbers already sorted");
		return (0);
	}
	print_lst(a, "a before");
	if (ft_tablen(argv) == 3)
	{
		if (tiny_sort(&a) == -1)
			return (ft_lstclear(&a, free), 1);
		return (ft_lstclear(&a, free), 0);
	}
	if (push_swap(&a, &b) == -1)
	{
		ft_printf("push_swap failed");
		ft_lstclear(&a, free);
		if (b)
			ft_lstclear(&b, free);
		return (1);
	}
	print_lst(a, "a after");
	ft_lstclear(&a, free);
	if (b)
		ft_lstclear(&b, free);
	return (0);
}
