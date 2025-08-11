/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:58:20 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 13:11:30 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node;
	t_node	*next_node;

	free(stack_b);
	current_node = stack_a -> top;
	while (current_node)
	{
		next_node = current_node -> next;
		free(current_node);
		current_node = next_node;
	}
	free(stack_a);
}

void	free_resources(char **split, int *analised_vals)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(analised_vals);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
