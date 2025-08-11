/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:14:48 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 12:50:02 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *donor, t_stack *receptor, char stack)
{
	t_node	*temp;
	char	*msg;

	temp = donor -> top;
	donor -> top = temp -> next;
	temp -> next = receptor -> top;
	receptor -> top = temp;
	donor -> size--;
	receptor -> size++;
	if (stack == 'a')
		msg = "pa\n";
	else
		msg = "pb\n";
	write(1, msg, 3);
}

void	rotate(t_stack *stack_a)
{
	t_node	*used_to_be_last_node;
	t_node	*used_to_be_top_node;

	used_to_be_top_node = stack_a -> top;
	used_to_be_last_node = get_node_with_location(stack_a, (stack_a->size) - 1);
	stack_a -> top = used_to_be_top_node -> next;
	used_to_be_last_node -> next = used_to_be_top_node;
	used_to_be_top_node -> next = NULL;
	write(1, "ra\n", 3);
}

void	sa(t_stack *stack_a)
{
	t_node	*tmp_node;
	t_node	*used_to_be_top;

	tmp_node = stack_a -> top -> next;
	used_to_be_top = stack_a -> top;
	used_to_be_top -> next = tmp_node -> next;
	stack_a -> top = tmp_node;
	tmp_node -> next = used_to_be_top;
	write(1, "sa\n", 3);
}

void	reverse_rotate(t_stack *stack_a)
{
	t_node	*used_to_be_last;
	t_node	*used_to_be_penult;
	t_node	*used_to_be_top;

	used_to_be_top = stack_a -> top;
	used_to_be_last = get_node_with_location(stack_a, stack_a -> size - 1);
	used_to_be_penult = get_node_with_location(stack_a, stack_a -> size - 2);
	stack_a -> top = used_to_be_last;
	stack_a -> top ->next = used_to_be_top;
	used_to_be_penult -> next = NULL;
	write(1, "rra\n", 4);
}
