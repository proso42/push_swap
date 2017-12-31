/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:48:51 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 15:02:06 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	suite_apply_commands(t_data *info, t_list *current)
{
	if (!ft_strcmp(current->data, "rr"))
		rotate_up_ab(info->list_a, info->list_b);
	else if (!ft_strcmp(current->data, "rra"))
		rotate_down(info->list_a);
	else if (!ft_strcmp(current->data, "rrb"))
		rotate_down(info->list_b);
	else
		rotate_down_ab(info->list_a, info->list_b);
}

static void	print_visu(t_data *info)
{
	if (info->visu)
	{
		system("clear");
		print_db_list_ab(info->list_a, info->list_b);
		ft_putendl("----------------");
		sleep(1);
	}
}

static void	apply_commands(t_data *info)
{
	t_list	*current;

	current = info->cmd_list;
	while (current)
	{
		if (!ft_strcmp(current->data, "pa"))
			push_a(&info->list_a, &info->list_b);
		else if (!ft_strcmp(current->data, "pb"))
			push_b(&info->list_a, &info->list_b);
		else if (!ft_strcmp(current->data, "sa"))
			swap(info->list_a);
		else if (!ft_strcmp(current->data, "sb"))
			swap(info->list_b);
		else if (!ft_strcmp(current->data, "ss"))
			swap_ab(info->list_a, info->list_b);
		else if (!ft_strcmp(current->data, "ra"))
			rotate_up(info->list_a);
		else if (!ft_strcmp(current->data, "rb"))
			rotate_up(info->list_b);
		else
			suite_apply_commands(info, current);
		current = current->next;
		print_visu(info);
	}
}

static int	is_valid_cmd(char *str)
{
	if (ft_strcmp(str, "pa") && ft_strcmp(str, "pb") && ft_strcmp(str, "sa")
	&& ft_strcmp(str, "sb") && ft_strcmp(str, "ss") && ft_strcmp(str, "ra")
	&& ft_strcmp(str, "rb") && ft_strcmp(str, "rr") && ft_strcmp(str, "rra")
	&& ft_strcmp(str, "rrb") && ft_strcmp(str, "rrr"))
		return (0);
	return (1);
}

int			check_commands(t_data *info)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!(is_valid_cmd(line)))
			return (print_error(ERR_ARG));
		ft_push_back(&info->cmd_list, ft_strdup(line));
	}
	apply_commands(info);
	return (1);
}
