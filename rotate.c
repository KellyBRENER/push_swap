/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:52:22 by kbrener-          #+#    #+#             */
/*   Updated: 2024/03/04 16:01:50 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	rotate(t_list **lst)
{
	t_list	temp;
	t_list	first;

	temp = NULL;
	first = NULL;
	if (!lst || !*lst || !*lst->next)
		return (-1)
	temp = *lst;
	*lst = *lst->next;
	first = *lst;
	while (lst->next)
		lst = lst->next;
	lst->next = temp;
	lst = &first;
}
