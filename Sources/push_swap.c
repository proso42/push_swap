/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:07:13 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 02:35:16 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	info;

	info.list_a = NULL;
	info.list_b = NULL;
	info.cmd_list = NULL;
	if (!(check_argv(&info, argv, argc)))
		return (0);
	if (is_sort(&info, 0))
		return (0);
	quick_sort(&info);
	ft_print_list(info.cmd_list);
	return (0);
}
