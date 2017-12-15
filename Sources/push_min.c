/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:57:25 by proso             #+#    #+#             */
/*   Updated: 2017/12/15 00:26:39 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push_min(t_data *info)
{
	if (info->list_a->next->data == info->min)
	{
		swap(info->list_a);
		ft_push_back(&info->cmd_list, ft_strdup("sa"));
		push_b(&info->list_a, &info->list_b);
		ft_push_back(&info->cmd_list, ft_strdup("pb"));
		return ;
	}
	while (info->list_a->data != info->min)
	{
		if (info->pos > info->size_a / 2)
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
	push_b(&info->list_a, &info->list_b);
	ft_push_back(&info->cmd_list, ft_strdup("pb"));
}
