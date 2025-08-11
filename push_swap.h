/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:12:45 by framiran          #+#    #+#             */
/*   Updated: 2025/08/11 08:40:14 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// push_swap_lib.h

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int			compared_indexes_contains(int *compared_indexes, int j, int size);
void		order_argv(int *int_argv, int size);
int			*get_argv_index(char **argv, int nmb_of_args, int argc);
t_node		*node_init(int arg_value, int index_value);
void		initial_push(t_stack *stack, t_node *node);
void		fill_stack_a(t_stack *stck_a, char **argv, int *idx_argv, int size);
int			ft_atoi(const char *str);
t_stack		*stack_init(void);
int			calc_max_nmbr_bits(int biggest_number);
void		radix_lsd(t_stack *stck_a, t_stack *stck_b, int max_nmbr_of_bits);
int			check_if_bit_is_0(int index, int bit);
t_node		*get_node_with_location(t_stack *stack, int location);
void		push_b_on_top_of_a(t_stack *stack_b, t_stack *stack_a);
void		push(t_stack *donor, t_stack *receptor, char stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		print_stack(t_stack *stack);
int			validate_argv(int argc, char **argv);
int			ft_pow(int number, int exponent);
int			*get_indexed_argv(char **argv, int *inargv, int *idargv, int size);
int			validate_one_arg(const char *arg);
int			validate_mult_arg(int argc, char **argv);
int			validate_args_array(char **split, int *anlised_vals, int splt_sze);
int			is_valid_str(const char *str, int *analised_vals, int i);
int			is_valid_integer_string(const char *str);
int			check_duplicates(int *analised_values, int size);
int			get_split_size(char **split);
void		free_resources(char **split, int *analised_vals);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(const char *str, const char delim);
void		free_split(char **split);
void		fill_int_argv(int *int_argv, char **argv, int size, char type);
void		simple_sorts(t_stack *stck_a, t_stack *stck_b, int nmbr_of_args);
void		sort_two(t_stack *stack_a);
void		sort_three(t_stack *stack_a);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sa(t_stack *stack_a);
int			get_smaller_node_pos(t_stack *stack);
void		push_nd_b(t_stack *sk_a, t_stack *sk_b, int nde_pos, int stcksize);
long long	ft_atoll(const char *str);
int			check_if_sorted(int *index_argv, int numer_of_args);
#endif
