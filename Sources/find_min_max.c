/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 00:32:48 by proso             #+#    #+#             */
/*   Updated: 2017/12/27 00:43:42 by alexandra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void  loop_ra(t_data *info, int nb)
{
  while (nb)
  {
    rotate_up(info->list_a);
    ft_push_back(&info->cmd_list, ft_strdup("ra"));
    nb--;
  }
}

int  find_min(t_db_list *list_a)
{
  int a;
  int b;
  int c;

  a = list_a->data;
  b = list_a->next->data;
  c = list_a->next->next->data;
  if (a < b && a < c)
    return (a);
  else if (b < a && b < c)
    return (b);
  else
    return (c);
}

int  find_max(t_db_list *list_a)
{
  int a;
  int b;
  int c;

  a = list_a->data;
  b = list_a->next->data;
  c = list_a->next->next->data;
  if (a > b && a > c)
    return (a);
  else if (b > a && b > c)
    return (b);
  else
    return (c);
}
