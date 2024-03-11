/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:42:49 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/11 16:25:15 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_list	*ft_lstnew_nbr(int nbr)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->nbr = nbr;
	lst->next = NULL;
	return (lst);
}

void	print_lst(t_list *lst, char c)
{
	ft_printf("liste %c\n", c);
	while (lst)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

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
int	tiny_sort(t_list **a)
{
	int	nbr1;
	int	nbr2;
	int	nbr3;

	nbr1 = (*a)->nbr;
	nbr2 = ((*a)->next)->nbr;
	nbr3 = (((*a)->next)->next)->nbr;
	if (nbr1 > nbr2 && nbr1 > nbr3)
	{
		if (nbr2 > nbr3)
		{
			ra(a);
			sa(a);
		}
		else
			ra(a);
	}
	else if (nbr1 < nbr2 && nbr1 < nbr3)
	{
		sa(a);
		ra(a);
	}
	else
	{
		if (nbr2 < nbr3)
			sa(a);
		else
			rra(a);
	}
	if (check_stack(*a) == 1)
		return (-1);
	return (0);
}

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
		return (ft_lstclear(&a, free),
			ft_printf("numbers already sorted"), 0);
	if (ft_tablen(argv) == 3)
	{
		if (tiny_sort(&a) == -1)
			return (ft_lstclear(&a, free), 1);
		return (ft_lstclear(&a, free), 0);
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
	ft_lstclear(&a, free);
	if (b)
		ft_lstclear(&b, free);
	return (0);
	//check_stack
	/*faire une fonction qui check si les nbr sont dans le bon ordre*/
	//sort_stack
	/*trier les nombres :
	=> pour 3 nbr : tiny_sort
	- faire une fonction qui cherche le + grand nombre
	- s'il est au sommet -> rotate
	- si c'est le 2eme -> rra
	- si le 1er nbr est + grand que le 2eme -> sa
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
}
