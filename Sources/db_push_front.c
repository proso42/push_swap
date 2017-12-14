/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:10:35 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 00:26:26 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_db_list	*db_push_front(t_db_list **begin_list, int nb)
{
	t_db_list	*elem;

	if (!(elem = (t_db_list*)malloc(sizeof(t_db_list))))
		print_error(ERR_MALLOC);
	elem->data = nb;
	if (!*begin_list)
		elem->next = NULL;
	else
	{
		elem->next = *begin_list;
		elem->next->prev = elem;
	}
	elem->prev = NULL;
	*begin_list = elem;
	return (elem);
}
