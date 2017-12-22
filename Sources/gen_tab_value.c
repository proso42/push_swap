/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tab_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 01:22:04 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 04:31:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void		add_value(t_data *info, int value, int i)
{
	int		j;

	j = 0;
	while (info->tab_value[i][j] != info->max + 1)
		j++;
	info->tab_value[i][j] = value;
}

int			get_next_tab(t_data *info)
{
	int		i;

	i = 0;
	while (i < info->size_a)
	{
		if (info->tab_value[i][0] == info->max + 1)
			return (i);
		i++;
	}
	return (i);
}

static void	init_tab(long *tab, int max, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = max + 1;
		i++;
	}
}

void		gen_tab_value(t_data *info)
{
	long	**tab;
	int		i;
	int		j;

	i = db_list_size(info->list_a);
	j = 0;
	if (!(tab = (long**)malloc(sizeof(long*) * i)))
		print_error(ERR_MALLOC);
	while (j < i)
	{
		if (!(tab[j] = (long*)malloc(sizeof(long) * i)))
			print_error(ERR_MALLOC);
		init_tab(tab[j], info->max, info->size_a);
		j++;
	}
	info->tab_value = tab;
}
