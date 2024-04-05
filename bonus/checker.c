/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:25:33 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/05 11:46:34 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_exec_line(char *line, t_list **a, t_list **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (swap(a));
	if (ft_strncmp(line, "sb\n", 3) == 0)
		return (swap(b));
	if (ft_strncmp(line, "ss\n", 3) == 0)
		return (swap(a), swap(b));
	if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate(a));
	if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate(b));
	if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rotate(a), rotate(b));
	if (ft_strncmp(line, "rra\n", 4) == 0)
		return (reverse_rotate(a));
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (reverse_rotate(b));
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (reverse_rotate(a), reverse_rotate(b));
	if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push(b, a));
	if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push(a, b));
	return (1);
}

int	ft_check_line(t_list **a, t_list **b)
{
	char	*line;
	int		rtn;

	line = get_next_line(0);
	while (line)
	{
		rtn = ft_exec_line(line, a, b);
		if (rtn != 0)
		{
			free(line);
			return (rtn);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

/*	KO si instruction non executable
		liste A non triée
	Error si nbr non conforme
		instruction qui n'existe pas
		instruction avec des espaces
	rien si aucun parametre
	OK si liste déjà triée
		si instructions fournies trient bien la liste
*/
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		init;
	int		rtn;

	a = NULL;
	b = NULL;
	init = ft_init_push(argc, argv, &a);
	if (init == 1)
		return (0);
	else if (init == -1)
		return (write(2, "Error\n", 6), 1);
	rtn = ft_check_line(&a, &b);
	if (rtn == -1)
		return (ft_clean(&a, &b), write(1, "KO\n", 3), 1);
	else if (rtn == 1)
		return (ft_clean(&a, &b), write(2, "Error\n", 6), 1);
	if (ft_check_stack(a) == 1)
		return (ft_clean(&a, &b), write(1, "KO\n", 3), 1);
	return (ft_clean(&a, &b), write(1, "OK\n", 3), 0);
}
