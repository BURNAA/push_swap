/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:24:21 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 22:02:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"

typedef struct t_list
{
	int				data;
	int				index;
	int				position;
	int				flag;
	struct t_list	*next;
}t_list;

typedef struct t_values
{
	int	max;
	int	min;
}t_values;

t_list		*add_node(int data);
void		add_node_in_front(t_list **lst, t_list *node);
int			number_of_nodes(t_list *lst);
t_list		*last_node(t_list *lst);
void		add_node_in_end(t_list **lst, t_list *node);
int			len_of_input(char **av);
char		*join_input(char **av);
char		**split_input(char **av);
t_list		*link_data(char **av);
void		long_nb_error(char **av);
void		duplicate_nb_error(char **av);
void		not_integer_error(char **av);
int			check_sorted_input(t_list *head);
void		swap_satck(t_list *head);
void		sa(t_list *head, int flag);
void		sb(t_list *head, int flag);
void		ss(t_list *head_a, t_list *head_b, int flag);
void		push_to_stack_b(t_list **head_a, t_list **head_b, int flag);
void		push_to_stack_a(t_list **head_a, t_list **head_b, int flag);
void		rotate_stack(t_list **head);
void		ra(t_list **head, int flag);
void		rb(t_list **head, int flag);
void		rr(t_list **head_a, t_list **head_b, int flag);
void		reverse_rotate_stack(t_list **head);
void		rra(t_list **head, int flag);
void		rrb(t_list **head, int flag);
void		rrr(t_list **head_a, t_list **head_b, int flag);
int			sort_case_1(t_list **head);
int			sort_case_2(t_list **head);
void		sort_3_numbers(t_list **head);
t_values	get_max_min_values(t_list *head);
int			get_data_position(t_list *head, int data);
void		push_data_to_sb(t_list **head_a, t_list **head_b,
				int data, int position);
void		sort_5_numbers(t_list **head_a, t_list **head_b);
int			get_current_min(t_list *head);
void		indexing_stack(t_list *head);
void		set_data_position(t_list *head);
t_list		*data_in_chunk(t_list *head, int chunk_size);
void		shape_chunks(t_list **head_b, int *chunk_size, int division_nb);
t_list		*reverse_stack(t_list *head);
void		push_data_into_chunks(t_list **head_a, t_list **head_b,
				int division_nb);
void		sort_100_numbers(t_list **head_a, t_list **head_b, int division_nb);
void		sort_500_numbers(t_list **head_a, t_list **head_b, int division_nb);
void		free_split(char **output);
void		free_stacks(t_list **head_a, t_list **head_b);
#endif
