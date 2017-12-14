/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:39:23 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 03:45:39 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int		is_valid_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i)
			return (0);
		else if (str[i] != ' ' && !ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!ft_is_whitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int		is_doublon(t_db_list *list_a, long nb)
{
	t_db_list	*current;

	if (!(current = list_a))
		return (0);
	while (current)
	{
		if (current->data == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

int				check_argv(t_data *info, char **argv, int argc)
{
	long		nb;
	int			i;
	int			j;
	char		**tab;

	i = 1;
	while (i < argc)
	{
		tab = ft_strsplit(argv[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (!is_valid_arg(tab[j]))
				return (print_error(ERR_ARG));
			nb = ft_atol(tab[j]);
			if (nb > 2147483647 || nb < -2147483648 ||
												is_doublon(info->list_a, nb))
				return (print_error(ERR_ARG));
			db_push_back(&info->list_a, (int)nb);
			j++;
		}
		ft_del_tab(tab);
		i++;
	}
	return (1);
}
