/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_push_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:13:15 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 05:04:36 by proso            ###   ########.fr       */
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

void		re_push_numbers(t_data *info)
{
	int		i;
	int		size_tab;

	i = get_next_tab(info) - 1;
	if (i < 0)
		i = 0;
	size_tab = get_size_tab(info->tab_value[i], info->max);
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
