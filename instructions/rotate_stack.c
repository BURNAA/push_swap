/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:29:38 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/07 21:44:23 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_list **head)
{
	t_list	*tmp;

	if (number_of_nodes(*head) < 2)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	add_node_in_end(head, tmp);
}

void	ra(t_list **head, int flag)
{
	rotate_stack(head);
	if (flag == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **head, int flag)
{
	rotate_stack(head);
	if (flag == 0)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **head_a, t_list **head_b, int flag)
{
	rotate_stack(head_a);
	rotate_stack(head_b);
	if (flag == 0)
		ft_putstr_fd("rr\n", 1);
}
