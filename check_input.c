/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:27 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 23:00:13 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	long_nb_error(char **av)
{
	char	**output;
	long	data;
	int		i;

	i = 0;
	output = split_input(av);
	while (output[i])
	{
		data = ft_atoi(output[i]);
		if (!(data >= -2147483648 && data <= 2147483647))
		{
			ft_putstr_fd("Error\n", 2);
			free_split(output);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free_split(output);
}

void	duplicate_nb_error(char **av)
{
	char	**output;
	int		i;
	int		j;

	i = 0;
	output = split_input(av);
	while (output[i])
	{
		j = i + 1;
		while (output[j])
		{
			if (ft_atoi(output[i]) == ft_atoi(output[j]))
			{
				ft_putstr_fd("Error\n", 2);
				free_split(output);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	free_split(output);
}

void	not_integer_error(char **av)
{
	char	**output;
	int		i;
	int		j;

	i = 0;
	output = split_input(av);
	while (output[i])
	{
		j = 0;
		if (output[i][j] == '-' || output[i][j] == '+')
			j++;
		while (output[i][j])
		{
			if (ft_isdigit(output[i][j]) == 0)
			{	
				ft_putstr_fd("Error\n", 2);
				free_split(output);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	free_split(output);
}

int	check_sorted_input(t_list *head)
{
	while (head && head->next)
	{
		if (head->data < head->next->data)
			head = head->next;
		else
			return (1);
	}
	return (0);
}
