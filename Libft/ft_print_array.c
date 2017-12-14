/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:26:50 by proso             #+#    #+#             */
/*   Updated: 2017/11/10 02:28:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_print_array(char **array)
{
		int		i;

		i = 0;
		while (array[i] && array[i][0])
			ft_putendl(array[i++]);
}
