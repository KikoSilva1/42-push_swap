/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:55:23 by framiran          #+#    #+#             */
/*   Updated: 2025/08/11 08:50:46 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //to be removed
#include <stdlib.h>
#include <string.h> //to be removed
#include <math.h> //to be removed
#include <ctype.h> //to be removed
#include <unistd.h>
#include <limits.h>
#include <stddef.h>

//norminette
//ver ft_memset se funciona como esperado
//alterei o fill_int_argv

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max_numbr_bits;
	int		*indexed_argv;
	int		nmbr_of_args;

	nmbr_of_args = validate_argv(argc, argv);
	if (nmbr_of_args)
	{
		indexed_argv = get_argv_index(argv, nmbr_of_args, argc);
		max_numbr_bits = calc_max_nmbr_bits(nmbr_of_args - 1);
		if (check_if_sorted(indexed_argv, nmbr_of_args))
			return (1);
		stack_a = stack_init();
		stack_b = stack_init();
		fill_stack_a(stack_a, argv, indexed_argv, argc);
		free(indexed_argv);
		if (nmbr_of_args > 5)
			radix_lsd(stack_a, stack_b, max_numbr_bits);
		else
			simple_sorts(stack_a, stack_b, nmbr_of_args);
		free_stacks(stack_a, stack_b);
	}
	else if (argc >= 2)
		write(1, "Error\n", 6);
}

void	radix_lsd(t_stack *stack_a, t_stack *stack_b, int max_number_of_bits)
{
	int	curr_bit;
	int	bit_is_zero;
	int	stack_a_initial_size;
	int	i;

	curr_bit = 0;
	stack_a_initial_size = stack_a -> size;
	while (curr_bit < max_number_of_bits)
	{
		i = 1;
		while (i <= stack_a_initial_size)
		{
			bit_is_zero = check_if_bit_is_0(stack_a -> top -> index, curr_bit);
			if (bit_is_zero)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a);
			i++;
		}
		push_b_on_top_of_a(stack_b, stack_a);
		curr_bit ++;
	}
}

void	simple_sorts(t_stack *stack_a, t_stack *stack_b, int mumbr_of_args)
{
	if (mumbr_of_args == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (mumbr_of_args == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (mumbr_of_args == 4)
	{
		sort_four(stack_a, stack_b);
		return ;
	}
	if (mumbr_of_args == 5)
		sort_five(stack_a, stack_b);
}

int	check_if_sorted(int *index_argv, int numer_of_args)
{
	int	i;
	int	prev;

	if (index_argv[0] != 0)
		return (0);
	prev = index_argv[0];
	i = 1;
	while (i < numer_of_args)
	{
		if (index_argv[i] != prev + 1)
			return (0);
		prev = index_argv[i];
		i++;
	}
	free(index_argv);
	return (1);
}
