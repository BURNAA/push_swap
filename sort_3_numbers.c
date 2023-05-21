/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:57:45 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/07 21:49:49 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_case_1(t_list **head)
{
	int	flag;

	flag = 0;
	if (((*head)->next->next->data < (*head)->data)
		&& ((*head)->next->data < (*head)->data))
	{
		flag = 1;
		ra(head, 0);
		if (((*head)->next->data < (*head)->next->next->data)
			&& ((*head)->next->data < (*head)->data))
			sa(*head, 0);
	}
	return (flag);
}

int	sort_case_2(t_list **head)
{
	int	flag;

	flag = 0;
	if (sort_case_1(head) == 0)
	{
		if ((*head)->next->data < (*head)->data)
		{
			sa(*head, 0);
			flag = 1;
		}
		if ((*head)->next->next->data < (*head)->data)
		{
			rra(head, 0);
			flag = 1;
		}
	}
	return (flag);
}

void	sort_3_numbers(t_list **head)
{
	if (check_sorted_input(*head) == 0)
		return ;
	if (sort_case_1(head) == 0 && sort_case_2(head) == 0)
	{
		sa(*head, 0);
		ra(head, 0);
	}
}
