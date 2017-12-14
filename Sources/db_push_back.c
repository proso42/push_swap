/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:53:12 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 00:09:26 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_db_list	*db_push_back(t_db_list **begin_list, int nb)
{
	t_db_list	*elem;
	t_db_list	*current;
	t_db_list	*prev;

	elem = *begin_list;
	current = *begin_list;
	prev = NULL;
	if (!(elem = (t_db_list*)malloc(sizeof(t_db_list))))
		print_error(ERR_MALLOC);
	if (!*begin_list)
		*begin_list = elem;
	else
	{
		while (current->next)
			current = current->next;
		prev = current;
		current->next = elem;
	}
	elem->data = nb;
	elem->next = NULL;
	elem->prev = prev;
	return (elem);
}
