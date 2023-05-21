/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:32:57 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/09 17:46:31 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_of_input(char **av)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	return (len + i - 1);
}

char	*join_input(char **av)
{
	char	*output;
	int		len;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	len = len_of_input(av);
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			output[k++] = av[i][j];
		output[k++] = ' ';
	}
	output[k] = '\0';
	return (output);
}

char	**split_input(char **av)
{
	char	*input;
	char	**output;

	input = join_input(av);
	output = ft_split(input, ' ');
	free(input);
	return (output);
}

t_list	*link_data(char **av)
{
	t_list	*head;
	t_list	*node;
	int		data;
	int		i;
	char	**output;

	long_nb_error(av);
	duplicate_nb_error(av);
	not_integer_error(av);
	i = 0;
	output = split_input(av);
	head = NULL;
	while (output[i])
	{
		data = ft_atoi(output[i]);
		node = add_node(data);
		add_node_in_end(&head, node);
		i++;
	}
	free_split(output);
	return (head);
}
