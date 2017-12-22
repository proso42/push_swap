/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:13:28 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 00:25:43 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		get_median(t_db_list *list)
{
	t_db_list	*current;
	int			median;

	median = 0;
	current = list;
	while (current)
	{
		median += current->data;
		current = current->next;
	}
	median /= db_list_size(list);
	return (median);
}
