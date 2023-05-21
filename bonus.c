/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:27:25 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 22:34:59 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_checker(t_list **head_a, t_list **head_b, char *gnl_return)
{
	if (!ft_strncmp(gnl_return, "sa\n", 3))
		sa(*head_a, 1);
	else if (!ft_strncmp(gnl_return, "sb\n", 3))
		sb(*head_b, 1);
	else if (!ft_strncmp(gnl_return, "ss\n", 3))
		ss(*head_a, *head_b, 1);
	else if (!ft_strncmp(gnl_return, "ra\n", 3))
		ra(head_a, 1);
	else if (!ft_strncmp(gnl_return, "rb\n", 3))
		rb(head_b, 1);
	else if (!ft_strncmp(gnl_return, "rr\n", 3))
		rr(head_a, head_b, 1);
	else if (!ft_strncmp(gnl_return, "rra\n", 4))
		rra(head_a, 1);
	else if (!ft_strncmp(gnl_return, "rrb\n", 4))
		rrb(head_b, 1);
	else if (!ft_strncmp(gnl_return, "rrr\n", 4))
		rrr(head_a, head_b, 1);
	else if (!ft_strncmp(gnl_return, "pb\n", 3))
		push_to_stack_b(head_a, head_b, 1);
	else if (!ft_strncmp(gnl_return, "pa\n", 3))
		push_to_stack_a(head_a, head_b, 1);
	else
		return (1);
	return (0);
}

void	ko_ok(t_list **head_a, t_list **head_b)
{
	if (check_sorted_input(*head_a) == 0 && *head_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	char	*gnl_return;

	if (ac == 1)
		return (0);
	head_a = link_data(av);
	head_b = NULL;
	gnl_return = get_next_line(0);
	while (gnl_return)
	{	
		if (push_swap_checker(&head_a, &head_b, gnl_return) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			free(gnl_return);
			exit(EXIT_FAILURE);
		}
		else
		{
			free(gnl_return);
			gnl_return = get_next_line(0);
		}
	}
	ko_ok(&head_a, &head_b);
	free_stacks(&head_a, &head_b);
}
