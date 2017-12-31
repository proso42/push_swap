/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:58:27 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 02:44:57 by alexandra        ###   ########.fr       */
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
		ft_dprintf(2, "{red}{bold}Error{res}\n");
	else if (err == ERR_KO)
		ft_dprintf(1, "{red}{bold}KO{res}\n");
	return (0);
}
