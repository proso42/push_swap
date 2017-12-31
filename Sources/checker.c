/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:33:18 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 02:47:20 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc == 1)
		return (print_error(ERR_ARG));
	info.list_a = NULL;
	info.list_b = NULL;
	info.cmd_list = NULL;
	info.visu = (!ft_strcmp("-v", argv[1])) ? 1 : 0;
	if (!(check_argv(&info, argv, argc)))
		return (0);
	if (!(check_commands(&info)))
		return (0);
	is_sort(&info, 1);
	if (!info.visu)
		print_db_list_ab(info.list_a, info.list_b);
	ft_dprintf(1, "{bold}{blue}Nombre de coups : [{yellow}%d{blue}]{res}\n",
												ft_list_size(info.cmd_list));
	return (0);
}
