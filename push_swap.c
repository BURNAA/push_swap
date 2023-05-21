/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:27:25 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 22:45:52 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_struggles(t_list *head_a, t_list *head_b)
{
	if (number_of_nodes(head_a) <= 5)
	{
		if (number_of_nodes(head_a) == 2 && head_a->data > head_a->next->data)
			sa(head_a, 0);
		else if (number_of_nodes(head_a) == 3)
			sort_3_numbers(&head_a);
		else if (number_of_nodes(head_a) == 4)
		{
			push_data_to_sb(&head_a, &head_b,
				get_max_min_values(head_a).min, 3);
			sort_3_numbers(&head_a);
			push_to_stack_a(&head_a, &head_b, 0);
		}
		else if (number_of_nodes(head_a) == 5)
			sort_5_numbers(&head_a, &head_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;

	if (ac == 1)
		return (0);
	head_a = link_data(av);
	head_b = NULL;
	indexing_stack(head_a);
	if (check_sorted_input(head_a) == 0)
		exit (EXIT_SUCCESS);
	norm_struggles(head_a, head_b);
	if (number_of_nodes(head_a) > 5 && number_of_nodes(head_a) <= 99)
		sort_100_numbers(&head_a, &head_b, 4);
	else if (number_of_nodes(head_a) >= 100 && number_of_nodes(head_a) <= 499)
		sort_100_numbers(&head_a, &head_b, 5);
	else if (number_of_nodes(head_a) >= 500)
		sort_500_numbers(&head_a, &head_b, 8);
	free_stacks(&head_a, &head_b);
}
