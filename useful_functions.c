/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:24:23 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/06 01:59:37 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_current_min(t_list *head)
{
	t_list	*tmp;
	int		current_min;

	tmp = head;
	current_min = head->data;
	while (tmp)
	{
		if (tmp->flag == 0)
		{
			current_min = tmp->data;
			break ;
		}
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->data < current_min && head->flag == 0)
			current_min = head->data;
		head = head->next;
	}
	return (current_min);
}

void	initialize_flag(t_list *head)
{
	while (head)
	{
		head->flag = 0;
		head = head->next;
	}
}

void	indexing_stack(t_list *head)
{
	t_list	*tmp;
	int		index;
	int		size_of_list;

	size_of_list = number_of_nodes(head);
	index = 0;
	tmp = head;
	initialize_flag(tmp);
	while (size_of_list)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->data == get_current_min(head))
			{
				tmp->flag = 1;
				tmp->index = index++;
				size_of_list--;
			}
			tmp = tmp->next;
		}
	}
}

void	set_data_position(t_list *head)
{
	int	position;

	position = 0;
	while (head)
	{
		head->position = position;
		position++;
		head = head->next;
	}
}

t_list	*reverse_stack(t_list *head)
{
	t_list	*tmp;
	t_list	*node;

	tmp = NULL;
	while (head)
	{
		node = add_node(head->data);
		node->index = head->index;
		head = head->next;
		add_node_in_front(&tmp, node);
	}
	return (tmp);
}
