/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:53:41 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 15:10:18 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_with_location(t_stack *stack_a, int node_location)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = stack_a -> top;
	while (i < node_location)
	{
		current_node = current_node ->next;
		i++;
	}
	return (current_node);
}

void	push_nd_b(t_stack *stck_a, t_stack *stck_b, int node_pos, int size)
{
	if (node_pos == 1)
		rotate(stck_a);
	if (node_pos == 2)
	{
		rotate(stck_a);
		rotate (stck_a);
	}
	if (node_pos == 3)
	{
		reverse_rotate(stck_a);
		if (size == 5)
			reverse_rotate(stck_a);
	}
	if (node_pos == 4)
		reverse_rotate(stck_a);
	push(stck_a, stck_b, 'b');
}

int	get_smaller_node_pos(t_stack *stack_a)
{
	t_node	*curr_node;
	int		smaller_node_pos;
	int		smaller_index;
	int		curr_pos;

	smaller_node_pos = 0;
	smaller_index = stack_a -> top -> index;
	curr_node = stack_a -> top -> next;
	curr_pos = 1;
	while (curr_node)
	{
		if (curr_node ->index < smaller_index)
		{
			smaller_node_pos = curr_pos;
			smaller_index = curr_node ->index;
		}
		curr_pos ++;
		curr_node = curr_node -> next;
	}
	return (smaller_node_pos);
}
