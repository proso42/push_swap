/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 23:43:43 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 01:10:51 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void suite_opti4(t_data *info)
{
  push_b(&info->list_a, &info->list_b);
  ft_push_back(&info->cmd_list, ft_strdup("pb"));
  swap(info->list_a);
  ft_push_back(&info->cmd_list, ft_strdup("sa"));
  loop_ra(info, 2);
  push_a(&info->list_a, &info->list_b);
  ft_push_back(&info->cmd_list, ft_strdup("pa"));
  rotate_up(info->list_a);
  ft_push_back(&info->cmd_list, ft_strdup("ra"));
}

static void suite_opti3(t_data *info)
{
  if (info->list_a->data == info->max2 && info->list_a->next->data == info->min)
  {
    push_b(&info->list_a, &info->list_b);
    ft_push_back(&info->cmd_list, ft_strdup("pb"));
    loop_ra(info, 2);
    push_a(&info->list_a, &info->list_b);
    ft_push_back(&info->cmd_list, ft_strdup("pa"));
    rotate_up(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("ra"));
  }
  else
    suite_opti4(info);
}

static void suite_opti2(t_data *info)
{
  if (info->list_a->next->data == info->min &&
    info->list_a->next->next->data == info->max2)
  {
    swap(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("sa"));
    loop_ra(info, 3);
  }
  else if (info->list_a->next->data == info->max2 &&
    info->list_a->next->next->data == info->min)
  {
    push_b(&info->list_a, &info->list_b);
    ft_push_back(&info->cmd_list, ft_strdup("pb"));
    swap(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("sa"));
    rotate_up(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("ra"));
    push_a(&info->list_a, &info->list_b);
    ft_push_back(&info->cmd_list, ft_strdup("pa"));
    loop_ra(info, 2);
  }
  else
    suite_opti3(info);
}

static void suite_opti(t_data *info)
{
  info->min = find_min(info->list_a);
  info->max2 = find_max(info->list_a);
  if (info->list_a->data == info->min && info->list_a->next->next->data ==
     info->max2)
    loop_ra(info, 3);
  else if (info->list_a->next->data == info->max2 &&
    info->list_a->data == info->min)
  {
    rotate_up(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("ra"));
    swap(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("sa"));
    loop_ra(info, 2);
  }
  else
    suite_opti2(info);
}

void        opti(t_data *info, int i, int size)
{
  if (size == 1)
  {
    rotate_up(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("ra"));
  }
  else if (size == 2)
  {
    if (info->list_a->data > info->list_a->next->data)
    {
      swap(info->list_a);
      ft_push_back(&info->cmd_list, ft_strdup("sa"));
    }
    loop_ra(info, 2);
  }
  else
    suite_opti(info);
  info->tab_value[i][0] = info->max + 1;
  info->tab_value[i][1] = info->max + 1;
  info->tab_value[i][2] = info->max + 1;
}
