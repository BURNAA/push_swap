/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:29:13 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/05 22:45:21 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_node(int data)
{
	t_list	*node;

	node = NULL;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	add_node_in_front(t_list **head, t_list *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		node->next = *head;
		*head = node;
	}
}

int	number_of_nodes(t_list *head)
{
	int	n;

	n = 0;
	if (head == NULL)
		return (n);
	while (head)
	{
		head = head->next;
		n++;
	}
	return (n);
}

t_list	*last_node(t_list *head)
{
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	add_node_in_end(t_list **head, t_list *node)
{
	if (*head == NULL)
		*head = node;
	else
		last_node(*head)->next = node;
}
