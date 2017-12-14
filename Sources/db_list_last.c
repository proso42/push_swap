/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:23:20 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 01:11:41 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_db_list	*db_list_last(t_db_list *begin_list)
{
	t_db_list	*current;

	if (!(current = begin_list))
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
