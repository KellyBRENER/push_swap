/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:31 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/21 11:46:50 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))//verifie qu'il y a au moins un arg et qu'il ne soit pas vide
		return(perror("incorrect argument count"), 1);
	else if (argc == 2)//s'il y a 1 argument, on split les nombres pour que chaque no;bre soit une ligne de argv
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
	/* pour tester les fonctions de base:*/
	/*print_lst(a, 'a');
	print_lst(b, 'b');
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pa(&a, &b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	sa(&a);
	sb(&b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	ss(&a, &b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	ra(&a);
	rb(&b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	rr(&a, &b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	rra(&a);
	rrb(&b);
	print_lst(a, 'a');
	print_lst(b, 'b');
	rrr(&a, &b);
	print_lst(a, 'a');
	print_lst(b, 'b');*/

	//sort_stack
	/*trier les nombres :
	=> pour trier + de nbr :
	- on envoie les nbr de a vers b, jusqu'a n'avoir que 3 nbr dans a
	- chaque nbr de b, va viser un nbr dans a :
		- chercher le + petit nbr qui lui est superieur
		- s'il n'existe pas, chercher le + petit nbr
		- faire une fonction qui cherche le + petit nbr
	- pour positionner un nombre avant sa cile (si la cible est le + petit superieur)
		-> rra + pa
	chaque node a une structure qui comprend :
	- sa position dans la stack (current_position)
	- la valeur de nbr (value)
	- l'adresse du noeud du dessus (previous)
	- l'adresse du noeud du dessous (next)
	- l'adresse du noeud vise (target_node)
	- final index
	- push_price
	- above_median
	- cheapest*/
	/*creer une fonction qui supprime tout en cas d'erreur*/
