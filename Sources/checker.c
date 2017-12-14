/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:33:18 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 04:14:19 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	is_sort(t_data *info)
{
	t_db_list	*current;

	if (info->list_b)
		return (print_error(ERR_KO));
	current = info->list_a;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (print_error(ERR_KO));
		current = current->next;
	}
	ft_putstr_fd("OK\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc == 1)
		return (print_error(ERR_ARG));
	info.list_a = NULL;
	info.list_b = NULL;
	info.cmd_list = NULL;
	if (!(check_argv(&info, argv, argc)))
		return (0);
	if (!(check_commands(&info)))
		return (0);
	is_sort(&info);
	print_db_list_ab(info.list_a, info.list_b);
	return (0);
}
