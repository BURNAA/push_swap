/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightweight_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:50 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 22:14:22 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **output)
{
	int	i;

	i = 0;
	while (output[i])
	{
		free(output[i]);
		i++;
	}
	free(output);
}

void	free_stacks(t_list **head_a, t_list **head_b)
{
	t_list	*node;

	while (head_a && *head_a)
	{
		node = *head_a;
		(*head_a) = (*head_a)->next;
		free(node);
	}
	while (head_b && *head_b)
	{
		node = *head_b;
		(*head_b) = (*head_b)->next;
		free(node);
	}
}
