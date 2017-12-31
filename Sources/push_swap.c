/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:07:13 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 02:19:00 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	info;

	info.list_a = NULL;
	info.list_b = NULL;
	info.cmd_list = NULL;
	info.visu = 0;
	if (argc == 1 || !(check_argv(&info, argv, argc)))
		return (0);
	if (is_sort(&info, 0))
		return (0);
	if (db_list_size(info.list_a) < 60)
		sort_list(&info);
	else
		quick_sort(&info);
	ft_print_list(info.cmd_list);
	return (0);
}
