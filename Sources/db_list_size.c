/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:38:48 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 23:40:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		db_list_size(t_db_list *list)
{
	int			size;
	t_db_list	*current;

	current = list;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
