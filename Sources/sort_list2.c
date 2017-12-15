/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:22:39 by proso             #+#    #+#             */
/*   Updated: 2017/12/15 06:16:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	search_min_b(t_data *info)
{
	int 		pos;
	t_db_list	*current;

	pos = 0;
	current = info->list_b;
	while (current)
	{
		if (current->data < info->min && current->data > info->super_min)
		{
			info->pos_list = 1;
			info->min = current->data;
			info->pos = pos;
		}
		pos++;
		current = current->next;
	}
}

static void	search_min_a(t_data *info)
{
	int 		pos;
	t_db_list	*current;

	ft_init(0, 2, &pos, &info->pos);
	info->min = info->list_a->data;
	current = info->list_a;
	while (current)
	{
		if ((current->data < info->min && current->data > info->super_min) ||
		(current->data < info->min && current->data == info->super_min
															&& !info->start))
		{
			info->pos_list = 0;
			info->min = current->data;
			info->pos = pos;
		}
		pos++;
		current = current->next;
	}
}

static void	put_min_at_end_a(t_data *info)
{
	search_min_a(info);
	info->size_a = db_list_size(info->list_a);
	while ((db_list_last(info->list_a)->data) != info->min)
	{
		if (info->pos <= info->size_a / 2)
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
	info->super_min = info->min;
}

static void	search_max(t_data *info)
{
	t_db_list	*current;

	current = info->list_a;
	info->max = current->data;
	while (current)
	{
		if (info->max < current->data)
			info->max = current->data;
		current = current->next;
	}
	current = info->list_a;
	info->under_max = current->data;
	while (current)
	{
		if (info->under_max < current->data && current->data < info->max)
			info->under_max = current->data;
		current = current->next;
	}
}

int	sort_list2(t_data *info)
{
	int		i;
	search_max(info);
	put_min_at_end_a(info);
	info->start = 1;
	search_min_a(info);
	search_min_b(info);
	while (!is_sort(info, 0))
	{
		if (!info->pos_list)
		{
			info->size_a = db_list_size(info->list_a);
			if (info->pos <= info->size_a / 2)
			{
				while (info->list_a->data != info->min)
				{
					if (info->list_a->next->data == info->min)
					{
						swap(info->list_a);
						ft_push_back(&info->cmd_list, ft_strdup("sa"));
					}
					else
					{
						push_b(&info->list_a, &info->list_b);
						ft_push_back(&info->cmd_list, ft_strdup("pb"));
					}
				}
				rotate_up(info->list_a);
				ft_push_back(&info->cmd_list, ft_strdup("ra"));
			}
			else
			{
				 i = 0;
				while (info->list_a->data != info->min)
				{
					rotate_down(info->list_a);
					ft_push_back(&info->cmd_list, ft_strdup("rra"));
					i++;
				}
				push_b(&info->list_a, &info->list_b);
				ft_push_back(&info->cmd_list, ft_strdup("pb"));
				while (i > 1)
				{
					rotate_up(info->list_a);
					ft_push_back(&info->cmd_list, ft_strdup("ra"));
					i--;
				}
				push_a(&info->list_a, &info->list_b);
				ft_push_back(&info->cmd_list, ft_strdup("pa"));
				rotate_up(info->list_a);
				ft_push_back(&info->cmd_list, ft_strdup("ra"));
			}
		}
		else
		{
			info->size_b = db_list_size(info->list_b);
			if (info->pos <= info->size_b / 2 && info->list_b->next)
			{
				while (info->list_b->data != info->min)
				{
					if (info->list_b->next->data == info->min)
					{
						swap(info->list_b);
						ft_push_back(&info->cmd_list, ft_strdup("sb"));
					}
					else
					{
						rotate_up(info->list_b);
						ft_push_back(&info->cmd_list, ft_strdup("rb"));
					}
				}

			}
			else if (info->list_b->next)
			{
				while (info->list_b->data != info->min)
				{
					rotate_down(info->list_b);
					ft_push_back(&info->cmd_list, ft_strdup("rrb"));
				}
			}
			push_a(&info->list_a, &info->list_b);
			ft_push_back(&info->cmd_list, ft_strdup("pa"));
			rotate_up(info->list_a);
			ft_push_back(&info->cmd_list, ft_strdup("ra"));
		}
		info->super_min = info->min;
		if (info->super_min == info->under_max)
		{
			if (info->list_b)
				info->pos_list = 1;
			else
				info->pos_list = 0;
			info->pos = 0;
			info->min = info->max;
		}
		else
		{
			info->pos_list = 0;
			search_min_a(info);
			search_min_b(info);
		}
	}
	return (1);
}
