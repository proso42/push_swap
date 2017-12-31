/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligth_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 01:57:51 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 00:58:19 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	get_min(t_db_list *list)
{
	t_db_list	*current;
	int			min;

	min = list->data;
	current = list;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

static void	suite_ligth_sort(t_data *info, int *size)
{
	push_a(&info->list_a, &info->list_b);
	ft_push_back(&info->cmd_list, ft_strdup("pa"));
	rotate_up(info->list_a);
	ft_push_back(&info->cmd_list, ft_strdup("ra"));
	(*size)--;
}

void		ligth_sort(t_data *info)
{
	int		size;
	int		min;

	size = db_list_size(info->list_b);
	if (size)
		min = get_min(info->list_b);
	while (size)
	{
		if (info->list_b->data == min)
		{
			suite_ligth_sort(info, &size);
			if (size)
				min = get_min(info->list_b);
		}
		else if (size == 3 && info->list_b->next->next->data == min)
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
