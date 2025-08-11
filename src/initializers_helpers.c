/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:48:34 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 14:24:05 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_argv_index(char **argv, int nmb_of_args, int argc)
{
	int		*int_argv;
	int		*indx_argv;
	char	**split;

	indx_argv = malloc(nmb_of_args * sizeof(int));
	indx_argv = ft_memset(indx_argv, 0xFF, nmb_of_args * sizeof(int));
	if (argc > 2)
	{
		int_argv = malloc(nmb_of_args * sizeof(int));
		fill_int_argv(int_argv, argv, nmb_of_args, 'a');
		order_argv(int_argv, nmb_of_args);
		indx_argv = get_indexed_argv(argv, int_argv, indx_argv, nmb_of_args);
	}
	else
	{
		split = ft_split(argv[1], ' ');
		int_argv = malloc(nmb_of_args * sizeof(int));
		fill_int_argv(int_argv, split, nmb_of_args, 's');
		order_argv(int_argv, nmb_of_args);
		indx_argv = get_indexed_argv(split, int_argv, indx_argv, nmb_of_args);
		free_split(split);
	}
	free(int_argv);
	return (indx_argv);
}

void	fill_int_argv(int *int_argv, char **argv, int size, char type)
{
	int	i;

	if (type == 'a')
	{
		i = 1;
		while (argv[i] != NULL && i <= size)
		{
			int_argv[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	else if (type == 's')
	{
		i = 0;
		while (argv[i] != NULL && i <= size)
		{
			int_argv[i] = ft_atoi(argv[i]);
			i++;
		}
	}
}

int	*get_indexed_argv(char **argv, int *int_argv, int *indexed_argv, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!is_valid_integer_string(argv[0]))
		i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		while (j < size)
		{
			if (int_argv[j] == ft_atoi(argv[i]))
			{
				if (!is_valid_integer_string(argv[0]))
					indexed_argv[i - 1] = j;
				else
					indexed_argv[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (indexed_argv);
}

void	order_argv(int *int_argv, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	if (size == 1)
		return ;
	i = 0;
	j = 1;
	swapped = 0;
	while (j <= size -1)
	{
		if (int_argv[i] > int_argv[j])
		{
			temp = int_argv[i];
			int_argv[i] = int_argv[j];
			int_argv[j] = temp;
			swapped = 1;
		}
		j++;
		i++;
	}
	if (swapped == 1)
		order_argv(int_argv, --size);
	return ;
}
