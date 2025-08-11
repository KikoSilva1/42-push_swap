/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:38:16 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 15:10:49 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if ((stack_a -> top -> index) > (stack_a -> top -> next -> index))
		sa(stack_a);
	return ;
}

void	sort_three(t_stack *stack_a)
{
	t_node	*third_node;
	t_node	*scnd_node;

	sort_two(stack_a);
	scnd_node = get_node_with_location(stack_a, 1);
	third_node = scnd_node -> next;
	if (third_node -> index < stack_a -> top -> index)
	{
		third_node -> next = stack_a -> top;
		stack_a -> top = third_node;
		scnd_node -> next = NULL;
		write(1, "rra\n", 4);
	}
	else if (third_node -> index < scnd_node -> index)
	{
		third_node -> next = scnd_node;
		stack_a -> top -> next = third_node;
		scnd_node -> next = NULL;
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	smaller_node_pos;

	smaller_node_pos = get_smaller_node_pos(stack_a);
	push_nd_b(stack_a, stack_b, smaller_node_pos, 4);
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	smaller_node_pos;

	smaller_node_pos = get_smaller_node_pos(stack_a);
	push_nd_b(stack_a, stack_b, smaller_node_pos, 5);
	smaller_node_pos = get_smaller_node_pos(stack_a);
	push_nd_b(stack_a, stack_b, smaller_node_pos, 4);
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}
