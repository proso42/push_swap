/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:07:59 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 04:32:12 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int			is_sort(t_data *info, int print)
{
	t_db_list	*current;

	if (info->list_b && print)
		return (print_error(ERR_KO));
	else if (info->list_b)
		return (0);
	current = info->list_a;
	while (current->next)
	{
		if (current->data > current->next->data && print)
			return (print_error(ERR_KO));
		else if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	if (print)
		ft_putstr_fd("OK\n", 1);
	return (1);
}

void		search_min(t_data *info)
{
	int			min;
	int			pos;
	t_db_list	*current;

	current = info->list_a->next;
	min = info->list_a->data;
	ft_init(1, 2, &info->pos, &pos);
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			info->pos = pos;
		}
		current = current->next;
		pos++;
	}
	info->min = min;
}

static int	is_croissant(t_db_list *list_a)
{
	t_db_list	*current;
	int			save;

	current = list_a;
	save = current->data;
	current = current->next;
	while (current)
	{
		if (current->data < save)
			return (0);
		save = current->data;
		current = current->next;
	}
	return (1);
}

int			sort_list(t_data *info)
{
	info->size_a = db_list_size(info->list_a);
	while (info->size_a > 1 || !is_croissant(info->list_a))
	{
		search_min(info);
		push_min(info);
		info->size_a = db_list_size(info->list_a);
	}
	while (info->list_b)
	{
		push_a(&info->list_a, &info->list_b);
		ft_push_back(&info->cmd_list, ft_strdup("pa"));
	}
	return (1);
}
