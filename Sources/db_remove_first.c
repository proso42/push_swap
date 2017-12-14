/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_remove_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:14:43 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 01:41:03 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	db_remove_first(t_db_list **begin_list)
{
	t_db_list	*current;

	current = *begin_list;
	if (!*begin_list)
		return ;
	else if (!((*begin_list)->next))
	{
		*begin_list = current->next;
		free(current);
		return ;
	}
	rotate_up(*begin_list);
	current = db_list_last(*begin_list);
	current->prev->next = NULL;
	free(current);
}
