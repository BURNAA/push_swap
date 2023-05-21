/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:30:30 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/07 21:46:06 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_stack(t_list **head)
{
	t_list	*node;
	t_list	*tmp;
	int		i;

	if (number_of_nodes(*head) < 2)
		return ;
	i = number_of_nodes(*head);
	node = last_node(*head);
	tmp = *head;
	i -= 2;
	while (i--)
		tmp = tmp->next;
	tmp->next = NULL;
	add_node_in_front(head, node);
}

void	rra(t_list **head, int flag)
{
	reverse_rotate_stack(head);
	if (flag == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **head, int flag)
{
	reverse_rotate_stack(head);
	if (flag == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **head_a, t_list **head_b, int flag)
{
	reverse_rotate_stack(head_a);
	reverse_rotate_stack(head_b);
	if (flag == 0)
		ft_putstr_fd("rrr\n", 1);
}
