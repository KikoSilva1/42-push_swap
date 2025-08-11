/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:50:04 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 13:14:17 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_max_nmbr_bits(int biggest_number)
{
	int	exponent;

	exponent = 0;
	while (ft_pow(2, exponent) * 2 <= biggest_number)
		exponent++;
	return (exponent + 1);
}

int	check_if_bit_is_0(int index, int current_bit)
{
	int	mask;

	mask = 1 << current_bit;
	if ((index & mask) == 0)
		return (1);
	else
		return (0);
}

void	push_b_on_top_of_a(t_stack *stack_b, t_stack *stack_a)
{
	int	i;
	int	stack_b_size;

	stack_b_size = stack_b -> size;
	i = 1;
	while (i <= stack_b_size)
	{
		push(stack_b, stack_a, 'a');
		i++;
	}
}

int	ft_pow(int number, int exponent)
{
	if (exponent == 0)
		return (1);
	else
		return (number * ft_pow(number, exponent - 1));
}
