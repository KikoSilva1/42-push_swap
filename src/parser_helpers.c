/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:27:47 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 14:37:50 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_str(const char *str, int *analised_vals, int i)
{
	long	val;

	if (!is_valid_integer_string(str))
		return (0);
	val = ft_atoll(str);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	analised_vals[i] = (int)val;
	return (1);
}

int	is_valid_integer_string(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *analised_values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (analised_values[i] == analised_values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
