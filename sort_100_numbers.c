/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:36:51 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 22:09:17 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*data_in_chunk(t_list *head, int chunk_size)
{	
	while (head)
	{
		if (head->index <= chunk_size)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	shape_chunks(t_list **head_b, int *chunk_size, int fixed_size)
{
	if ((*head_b)->index > (*chunk_size - fixed_size / 2))
		rb(head_b, 0);
	if (number_of_nodes(*head_b) == *chunk_size + 1)
		*chunk_size = *chunk_size + fixed_size;
}

void	push_data_into_chunks(t_list **head_a, t_list **head_b, int division_nb)
{
	t_list	*stack;
	int		chunk_size;
	int		fixed_size;

	chunk_size = number_of_nodes(*head_a) / division_nb;
	fixed_size = chunk_size;
	while (number_of_nodes(*head_a))
	{
		stack = reverse_stack(*head_a);
		set_data_position(stack);
		while ((*head_a)->index != data_in_chunk(*head_a, chunk_size)->index
			&& (*head_a)->index != data_in_chunk(stack, chunk_size)->index)
		{
			if (data_in_chunk(*head_a, chunk_size)->position
				<= data_in_chunk(stack, chunk_size)->position)
				ra(head_a, 0);
			else
				rra(head_a, 0);
		}
		push_to_stack_b(head_a, head_b, 0);
		set_data_position(*head_a);
		shape_chunks(head_b, &chunk_size, fixed_size);
		free_stacks(&stack, NULL);
	}
}

void	sort_100_numbers(t_list **head_a, t_list **head_b, int division_nb)
{
	t_values	value;
	int			max_position;

	push_data_into_chunks(head_a, head_b, division_nb);
	while (number_of_nodes(*head_b))
	{
		value = get_max_min_values(*head_b);
		max_position = get_data_position(*head_b, value.max);
		while ((*head_b)->data != value.max)
		{
			if (max_position < number_of_nodes(*head_b) / 2)
				rb(head_b, 0);
			else
				rrb(head_b, 0);
		}
		push_to_stack_a(head_a, head_b, 0);
	}
}
