/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:53:25 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 01:57:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate_down(t_db_list *begin_list)
{
	t_db_list	*current;
	int			save;
	int			save2;

	current = begin_list;
	if (!current || !current->next)
		return ;
	save = current->next->data;
	current->next->data = current->data;
	current->data = (db_list_last(begin_list))->data;
	current = current->next;
	if (!current->next)
		current->prev->data = save;
	while (current->next)
	{
		save2 = current->next->data;
		current->next->data = save;
		save = save2;
		current = current->next;
	}
}

void	rotate_up(t_db_list *begin_list)
{
	t_db_list	*current;
	int			save;
	int			save2;

	current = begin_list;
	if (!current || !current->next)
		return ;
	while (current->next)
		current = current->next;
	save = current->prev->data;
	current->prev->data = current->data;
	current->data = begin_list->data;
	current = current->prev;
	if (!current->prev)
		current->next->data = save;
	while (current->prev)
	{
		save2 = current->prev->data;
		current->prev->data = save;
		save = save2;
		current = current->prev;
	}
}

void	rotate_up_ab(t_db_list *list_a, t_db_list *list_b)
{
	rotate_up(list_a);
	rotate_up(list_b);
}

void	rotate_down_ab(t_db_list *list_a, t_db_list *list_b)
{
	rotate_down(list_a);
	rotate_down(list_b);
}
