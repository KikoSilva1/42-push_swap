/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:45:19 by framiran          #+#    #+#             */
/*   Updated: 2025/08/08 13:02:47 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	else
	{
		stack -> size = 0;
		stack -> top = NULL;
	}
	return (stack);
}

t_node	*node_init(int arg_value, int index_value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	else
	{
		node -> value = arg_value;
		node -> index = index_value;
	}
	return (node);
}

void	fill_stack_a(t_stack *stack_a, char **argv, int *indexed_argv, int argc)
{
	int		i;
	t_node	*node;
	char	**split;
	int		split_size;

	i = argc;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		split_size = get_split_size(split);
		i = split_size ;
		while (--i >= 0)
		{
			node = node_init(ft_atoi(split[i]), indexed_argv[i]);
			initial_push(stack_a, node);
		}
		free_split(split);
		return ;
	}
	while (--i >= 1)
	{
		node = node_init(ft_atoi(argv[i]), indexed_argv[i - 1]);
		initial_push(stack_a, node);
	}
}

void	initial_push(t_stack *stack_a, t_node *node)
{
	stack_a -> size = stack_a -> size + 1;
	node -> next = stack_a -> top;
	stack_a -> top = node;
}
