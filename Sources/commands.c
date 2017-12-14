/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:42:29 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 02:25:07 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push_a(t_db_list **list_a, t_db_list **list_b)
{
	if (*list_b)
	{
		db_push_front(list_a, (*list_b)->data);
		db_remove_first(list_b);
	}
}

void	push_b(t_db_list **list_a, t_db_list **list_b)
{
	if (*list_a)
	{
		db_push_front(list_b, (*list_a)->data);
		db_remove_first(list_a);
	}
}

void	swap(t_db_list *list)
{
	int		save;

	if (list && list->next)
	{
		save = list->data;
		list->data = list->next->data;
		list->next->data = save;
	}
}

void	swap_ab(t_db_list *list_a, t_db_list *list_b)
{
	swap(list_a);
	swap(list_b);
}
