/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:30:30 by proso             #+#    #+#             */
/*   Updated: 2017/12/22 03:22:58 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

# define ERR_MALLOC 32
# define ERR_ARG 	31
# define ERR_KO 	30

typedef struct			s_db_list
{
	struct s_db_list	*prev;
	struct s_db_list	*next;
	int					data;
}						t_db_list;

typedef struct			s_data
{
	t_db_list			*list_a;
	t_db_list			*list_b;
	t_list				*cmd_list;
	int					min;
	int					max;
	int					pos;
	int					median;
	int					size_a;
	long				**tab_value;
}						t_data;

int						print_error(int err);
int						check_argv(t_data *info, char **argv, int argc);
int						check_commands(t_data *info);
int						db_list_size(t_db_list *list);
t_db_list				*db_push_back(t_db_list **begin_list, int nb);
t_db_list				*db_push_front(t_db_list **begin_list, int nb);
t_db_list				*db_list_last(t_db_list *begin_list);
void					db_remove_first(t_db_list **begin_list);
void					rotate_up(t_db_list *begin_list);
void					rotate_down(t_db_list *begin_list);
void					print_db_list(t_db_list *begin_list);
void					print_db_list_ab(t_db_list *list_a, t_db_list *list_b);
void					push_a(t_db_list **list_a, t_db_list **list_b);
void					push_b(t_db_list **list_a, t_db_list **list_b);
void					swap(t_db_list *list);
void					swap_ab(t_db_list *list_a, t_db_list *list_b);
void					rotate_up_ab(t_db_list *list_a, t_db_list *list_b);
void					rotate_down_ab(t_db_list *list_a, t_db_list *list_b);
int						is_sort(t_data *info, int print);
int						sort_list(t_data *info);
void					quick_sort(t_data *info);
void					ligth_sort(t_data *info);
void					median_sort_a(t_data *info);
void					median_sort_b(t_data *info);
void					push_min(t_data *info);
int						get_median(t_db_list *list);
void					gen_tab_value(t_data *info);
int						get_next_tab(t_data *info);
void					add_value(t_data *info, int value, int i);
void					re_push_numbers(t_data *info);
void					print_tab(long *tab, int max);
#endif
