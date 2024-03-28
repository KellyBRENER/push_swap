/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:57 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/28 13:11:21 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*swap.c : fonctions pour swap*/
int		swap(t_list **lst);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
/*rotate.c : fonctions pour rotate*/
int		rotate(t_list **lst);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
/*reverse_rotate.c : fonctions pour reverse rotate*/
int		reverse_rotate(t_list **lst);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);
/*push.c : fonctions pour push*/
int		push(t_list **src, t_list **dest);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

/*lst.c : fonctions pour manipuler les listes*/
void	print_lst(t_list *lst, char *c);
t_list	*ft_lstnew_nbr(int nbr);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstbeforetarget(t_list *lst, t_list *target);
t_list	*ft_search_lst(t_list *lst, int nb);

/*push_swap.c : contient les algorythms*/
int		ft_src_to_dst(t_list **a, t_list **b, t_list *current, int dir);
int		push_swap(t_list **a, t_list **b);
int		tiny_sort(t_list **a);

/*cheapest.c : fonctions permettant de trouver
la liste nécessitant le moins d'opérations pour la déplacer*/
t_list	*ft_target_in_a(t_list *a, int nb);
t_list	*ft_target_in_b(t_list *b, int nb);
t_list	*ft_cheapest(t_list *src, t_list *dst, int dir);

/*cheapest_utils.c*/
int		ft_nb_rot(t_list *current, t_list *target);
int		ft_nb_rev(t_list *current, t_list *target);
int		ft_nbmax(t_list *lst);
int		ft_nbmin(t_list *lst);
int		ft_pos_lst(t_list *lst, t_list *current);

/*cheapest_utils_2.c*/
int		ft_movemin(int rot, int rev, int rotrev, int revrot);
int		ft_nbmove(t_list *src, t_list *dst, t_list *current, int dir);
void	ft_init_current(t_list *src, t_list *dst, t_list *current, int dir);
void	ft_init_target(t_list *lst, t_list *target);

/*execute.c : fonctions executant les opérations resultant de cheapest*/
int		ft_rev(t_list **a, t_list **b, t_list *current, int dir);
int		ft_rot(t_list **a, t_list **b, t_list *current, int dir);
int		ft_rot_rev(t_list **a, t_list **b, t_list *current, int dir);
int		ft_rev_rot(t_list **a, t_list **b, t_list *current, int dir);

/*check_init.c : vérifie que les conditions de l'exos sont respectées*/
int		check_stack(t_list *a);
int		same_nbr(int nbr, t_list *a);
int		check_nbr(int nbr, char *argv, t_list *a);
int		ft_tablen(char **argv);
int		stack_init(t_list **a, char **argv);

/*previous_sort.c*/
int		ft_sorttab(int *tab, int size);
int		ft_getmedian(t_list *a, int size);
void	ft_presort(t_list **a, t_list **b);

/*main.c : contient le main*/
int		ft_init_push(int argc, char **argv, t_list **a);
void	ft_error(int i);
void	ft_clean(t_list	**a, t_list **b);

#endif
