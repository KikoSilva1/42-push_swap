/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:12:45 by framiran          #+#    #+#             */
/*   Updated: 2025/07/31 16:24:37 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// push_swap_lib.h

#ifndef PUSH_SWAP_LIB_H
#define PUSH_SWAP_LIB_H

typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
}t_stack;

int compared_indexes_contains(int *compared_indexes, int j, int size);
int* order_argv(int* int_argv, int size);
int *get_argv_index(char **argv, int size);
t_node *node_init(int arg_value, int index_value);
void initial_push(t_stack *stack, t_node *node);
void fill_stack_a(t_stack *stack_a, char **argv, int *indexed_argv, int size);
int ft_atoi(const char *str);
t_stack *stack_init(void);
int calculate_max_number_of_bits(int biggest_number);
void radix_lsd(t_stack *stack_a, t_stack *stack_b, int max_number_of_bits);
int check_if_bit_is_0(int index, int bit);
void bubble_up_and_push_with_rotate(t_stack *stack_a, t_stack *stack_b, int node_location);
void bubble_up_and_push_with_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int node_location);
t_node *get_node_with_location(t_stack *stack, int location);
void push_b_on_top_of_a(t_stack *stack_b, t_stack *stack_a);
void push(t_stack *donor, t_stack *receptor, char stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void	free_stacks(t_stack *stack_a,t_stack *stack_b);
void print_stack(t_stack *stack);
int validate_argv(int argc, char **argv);
int check_duplicates(int argc,char **argv);
int	ft_pow(int number, int exponent);

#endif
