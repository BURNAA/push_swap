/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:23:14 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/07 21:46:52 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_stack_b(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*node_a;

	if (number_of_nodes(*head_a) == 0)
		return ;
	node_a = *head_a;
	*head_a = (*head_a)->next;
	node_a->next = NULL;
	add_node_in_front(head_b, node_a);
	if (flag == 0)
		ft_putstr_fd("pb\n", 1);
}

void	push_to_stack_a(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*node_b;

	if (number_of_nodes(*head_b) == 0)
		return ;
	node_b = *head_b;
	*head_b = (*head_b)->next;
	node_b->next = NULL;
	add_node_in_front(head_a, node_b);
	if (flag == 0)
		ft_putstr_fd("pa\n", 1);
}
