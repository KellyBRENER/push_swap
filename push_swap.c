/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:42:49 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/01 13:44:22 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc == 1 || argc == 2 && !argv[1][0])//verifie qu'il y a au moins un arg et qu'il ne soit pas vide
		return(perror("incorrect argument count"), 1);
	else if (argc == 2)//s'il y a 1 argument, on split les nombres pour que chaque no;bre soit une ligne de argv
		argv = ft_split(argv[1], " ");
	stack_init
	/*convertit chaque string de char en int
	verifie qu'il fasse partie des int (entre int max et min)
	verifie que le nbr ne soit pas egal a un autre nbr de la liste
	cree la liste pour le 1er nombre
	ajoute les autres nbr a la fin de la liste chainee*/
	sort_stack
	/*trier les nombres :
	=>creer une fonction pour chaque type de mouvement
	(swap(sa, sb, ss)/ push(pa, pb)/ rotate(ra, rb, rr)/
	reverse rotate(rra, rrb, rrr))
	chaque fonction finit par un write pour ecrire l'action effectue dans stdin
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
	- cheapest
	/*creer une fonction qui supprime tout en cas d'erreur*/

}
