/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:33:14 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/08 21:12:01 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_values	get_max_min_values(t_list *head)
{
	t_values	value;

	value.max = head->data;
	value.min = head->data;
	while (head && head->next)
	{
		if (value.max < head->next->data)
			value.max = head->next->data;
		if (head->next->data < value.min)
			value.min = head->next->data;
		head = head->next;
	}
	return (value);
}

int	get_data_position(t_list *head, int data)
{
	int	position;

	position = 0;
	while (head->data != data)
	{
		head = head->next;
		position++;
	}
	return (position);
}

void	push_data_to_sb(t_list **head_a, t_list **head_b,
						int data, int position)
{
	int	data_position;

	data_position = get_data_position(*head_a, data);
	while ((*head_a)->data != data)
	{
		if (data_position > position)
			rra(head_a, 0);
		else
			ra(head_a, 0);
	}
	push_to_stack_b(head_a, head_b, 0);
}

void	sort_5_numbers(t_list **head_a, t_list **head_b)
{
	t_values	value;

	value = get_max_min_values(*head_a);
	push_data_to_sb(head_a, head_b, value.max, 2);
	push_data_to_sb(head_a, head_b, value.min, 3);
	sort_3_numbers(head_a);
	push_to_stack_a(head_a, head_b, 0);
	push_to_stack_a(head_a, head_b, 0);
	ra(head_a, 0);
}
