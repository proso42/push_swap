/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:12:11 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 00:43:34 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	get_max(t_db_list *list)
{
	t_db_list	*current;
	int			max;

	max = list->data;
	current = list->next;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

void		quick_sort(t_data *info)
{
	info->max = get_max(info->list_a);
	info->size_a = db_list_size(info->list_a);
	gen_tab_value(info);
	median_sort_a(info);
	while (!is_sort(info, 0))
	{
		while (db_list_size(info->list_b) > 3)
			median_sort_b(info);
		if (info->list_b)
			ligth_sort(info);
		re_push_numbers(info);
	}
}
