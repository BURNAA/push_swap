/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:10:00 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/07 21:43:36 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_satck(t_list *head)
{
	int	tmp;

	if (number_of_nodes(head) <= 1)
		return ;
	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
}

void	sa(t_list *head, int flag)
{
	swap_satck(head);
	if (flag == 0)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *head, int flag)
{
	swap_satck(head);
	if (flag == 0)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list *head_a, t_list *head_b, int flag)
{
	swap_satck(head_a);
	swap_satck(head_b);
	if (flag == 0)
		ft_putstr_fd("ss\n", 1);
}
