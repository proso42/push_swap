/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:38:50 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 01:21:41 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	correct_list_a(t_db_list *list, int median)
{
	t_db_list	*current;

	current = list;
	while (current)
	{
		if (current->data < median)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	correct_list_b(t_db_list *list, int median)
{
	t_db_list	*current;

	current = list;
	while (current)
	{
		if (current->data >= median)
			return (0);
		current = current->next;
	}
	return (1);
}

void		median_sort_a(t_data *info)
{
	t_db_list	*current;

	info->median = get_median(info->list_a);
	while (!correct_list_a(info->list_a, info->median))
	{
		if (info->list_a->data < info->median)
		{
			push_b(&info->list_a, &info->list_b);
			ft_push_back(&info->cmd_list, ft_strdup("pb"));
		}
		else if ((db_list_last(info->list_a)->data) < info->median)
		{
			rotate_down(info->list_a);
			ft_push_back(&info->cmd_list, ft_strdup("rra"));
		}
		else
		{
			rotate_up(info->list_a);
			ft_push_back(&info->cmd_list, ft_strdup("ra"));
		}
	}
	current = info->list_a;
	while (current)
		current = add_value(info, current, 0);
}

void		median_sort_b(t_data *info)
{
	int	i;

	i = get_next_tab(info);
	info->median = get_median(info->list_b);
	while (!correct_list_b(info->list_b, info->median))
	{
		if (info->list_b->data >= info->median)
		{
			add_value(info, info->list_a, i);
			push_a(&info->list_a, &info->list_b);
			ft_push_back(&info->cmd_list, ft_strdup("pa"));
		}
		else if ((db_list_last(info->list_b)->data) >= info->median)
		{
			rotate_down(info->list_b);
			ft_push_back(&info->cmd_list, ft_strdup("rrb"));
		}
		else
		{
			rotate_up(info->list_b);
			ft_push_back(&info->cmd_list, ft_strdup("rb"));
		}
	}
}
