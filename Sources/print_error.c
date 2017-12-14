/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:58:27 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 04:12:44 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		print_error(int err)
{
	if (err == ERR_MALLOC)
	{
		ft_dprintf(2,
			"{red}{bold}Fail to allocate memory with malloc function !{res}\n");
		exit(EXIT_FAILURE);
	}
	else if (err == ERR_ARG)
		ft_putstr_fd("Error\n", 2);
	else if (err == ERR_KO)
		ft_putstr_fd("KO\n", 1);
	return (0);
}
