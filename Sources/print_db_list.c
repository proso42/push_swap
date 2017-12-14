/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_db_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:42:36 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 02:23:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	print_db_list(t_db_list *begin_list)
{
	t_db_list	*current;

	if (!begin_list)
		return ;
	current = begin_list;
	while (current)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
}

void	print_db_list_ab(t_db_list *list_a, t_db_list *list_b)
{
	t_db_list	*current_a;
	t_db_list	*current_b;

	if (!list_a && !list_b)
	{
		ft_printf("_\t_\n");
		return ;
	}
	current_a = list_a;
	current_b = list_b;
	while (1)
	{
		if (!current_a)
			ft_printf("%13s  %d\n", "_", current_b->data);
		else if (!current_b)
			ft_printf("%13d  _\n", current_a->data);
		else
			ft_printf("%13d  %d\n", current_a->data, current_b->data);
		if (current_a)
			current_a = current_a->next;
		if (current_b)
			current_b = current_b->next;
		if (!current_a && !current_b)
			return ;
	}
}
