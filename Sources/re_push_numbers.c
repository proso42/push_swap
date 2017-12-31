/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_push_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:13:15 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 02:03:53 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	get_size_tab(long *tab, int max)
{
	int		i;

	i = 0;
	if (tab[0] == max + 1)
		return (i);
	while (1)
	{
		if (tab[i] == max + 1)
			return (i);
		i++;
	}
	return (0);
}

static int	tab_sort(int size, t_db_list *list)
{
	t_db_list	*current;

	current = list;
	while (size > 1)
	{
		if (current->data > current->next->data)
			return (0);
		size--;
		current = current->next;
	}
	return (1);
}

static int	full_ra(t_data *info, int size)
{
	while (size)
	{
		rotate_up(info->list_a);
		ft_push_back(&info->cmd_list, ft_strdup("ra"));
		size--;
	}
	return (size);
}

void		re_push_numbers(t_data *info)
{
	int		i;
	int		size_tab;

	if ((i = get_next_tab(info) - 1) < 0)
		i = 0;
	if ((size_tab = get_size_tab(info->tab_value[i], info->max)) <= 3)
	{
		opti(info, i, size_tab);
		return ;
	}
	else if (tab_sort(size_tab, info->list_a))
		size_tab = full_ra(info, size_tab);
	while (size_tab)
	{
		push_b(&info->list_a, &info->list_b);
		ft_push_back(&info->cmd_list, ft_strdup("pb"));
		size_tab--;
	}
	while (info->tab_value[i][size_tab] <= info->max)
	{
		info->tab_value[i][size_tab] = info->max + 1;
		size_tab++;
	}
}
