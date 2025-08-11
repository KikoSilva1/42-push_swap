/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:25:28 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 14:25:55 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_argv(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		return (validate_one_arg(argv[1]));
	else
		return (validate_mult_arg(argc, argv));
}

int	validate_one_arg(const char *arg)
{
	char	**split;
	int		split_size;
	int		*analised_vals;
	int		return_value;

	return_value = 1;
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	split_size = get_split_size(split);
	analised_vals = (int *)malloc(sizeof(int) * split_size);
	if (!analised_vals)
		return_value = 0;
	if (return_value && !validate_args_array(split, analised_vals, split_size))
		return_value = 0;
	if (return_value && !check_duplicates(analised_vals, split_size))
		return_value = 0;
	free_resources(split, analised_vals);
	if (return_value != 0)
		return_value = split_size;
	return (return_value);
}

int	validate_mult_arg(int argc, char **argv)
{
	int		*analised_vals;
	int		return_value;

	return_value = 1;
	analised_vals = malloc(sizeof(int) * (argc - 1));
	if (!analised_vals)
		return (0);
	if (!validate_args_array(argv + 1, analised_vals, argc - 1))
		return_value = 0;
	if (return_value && !check_duplicates(analised_vals, argc - 1))
		return_value = 0;
	free(analised_vals);
	if (return_value != 0)
		return_value = argc -1;
	return (return_value);
}

int	validate_args_array(char **split, int *analised_vals, int split_size)
{
	int	i;

	i = 0;
	while (i < split_size)
	{
		if (!is_valid_str(split[i], analised_vals, i))
			return (0);
		i++;
	}
	return (1);
}
