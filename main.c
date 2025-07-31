/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:55:23 by framiran          #+#    #+#             */
/*   Updated: 2025/07/31 16:47:42 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //to be removed
#include <stdlib.h>
#include <string.h> //to be removed
#include <math.h> //to be removed
#include <ctype.h> //to be removed
#include <unistd.h>

//norminette
//rever pow
//ver duplicates, poderear remover a compared_indexes
//ver edge case max int
//reduzir sort do argv
//isolar a criacao do indexed_argv
//fazer push para o github

int	main(int argc,char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max_number_of_bits;
	int		*indexed_argv;

	if (validate_argv(argc, argv))
	{
		indexed_argv = get_argv_index(argv, argc-1);
		max_number_of_bits = calculate_max_number_of_bits(argc - 2); //argc-2 equivale ao index maximo que os valores podem atingir
		stack_a = stack_init();
		stack_b = stack_init();
		fill_stack_a(stack_a, argv,indexed_argv, argc);
		free(indexed_argv);
		radix_lsd(stack_a, stack_b, max_number_of_bits);
		print_stack(stack_a);
		free_stacks(stack_a, stack_b);
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
int	*get_argv_index(char **argv, int size)
{
	int		i;
	int		j;
	int*	int_argv;
	int*	indexed_argv;

	int_argv = malloc(size *sizeof(int));
	i = 1;
	while(argv[i] != NULL)
	{
		int_argv[i - 1] = atoi(argv[i]);
		i++;
	}
	int_argv = order_argv(int_argv,size);
	indexed_argv = malloc(size *sizeof(int));
	indexed_argv = memset(indexed_argv , 0xFF,size*sizeof(int)); //ver isto melhor
	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		while (j < size)
		{
			if (int_argv[j] ==  atoi(argv[i]) && !compared_indexes_contains(indexed_argv, j, size)) //change to ft_atoi
			{
				indexed_argv[i-1] = j;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(int_argv);
	return (indexed_argv);
}
int	compared_indexes_contains(int *indexed_argv,int j, int size)
{
	int i;
	i = 0;
	while(i < size)
	{
		if(j == indexed_argv[i])
			return (1);
		i++;
	}
	return (0);
}
int	*order_argv(int* int_argv, int size)
{
	int		i;
	int		j;
	int		smaller;
	int		smaller_index;
	int		swap;

	i = 0;
	swap = 0;
	while (i < size -1)
	{
		j = i + 1;
		smaller = int_argv[i];
		while (j < size)
		{
			if (int_argv[j] < smaller) //ver isto com mais atencao
			{
				smaller = int_argv[j];
				smaller_index = j;
				swap = 1;
			}
			j++;
		}
		if (swap)
		{
			int_argv[smaller_index] = int_argv[i];
			int_argv[i] = smaller;
			swap = 0;
		}
		i++;
	}
	return int_argv;
}

t_stack	*stack_init(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return NULL;
	else
	{
		stack -> size = 0;
		stack -> top = NULL;
	}
	return stack;
}
t_node	*node_init(int arg_value,int index_value)
{
	t_node *node;

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
void	fill_stack_a(t_stack *stack_a, char **argv, int *indexed_argv, int argc) //The first argument should be at the top of the stack (be careful about the order).
{
	int i;

	i = argc - 1; //so we dont consider the first arg
	while (i >= 1)
	{
		t_node *node = node_init(atoi(argv[i]),indexed_argv[i-1]); //change to ft_atoi
		initial_push(stack_a, node);
		i--;
	}
}
void	initial_push(t_stack *stack_a,t_node *node)
{
	stack_a -> size = stack_a -> size + 1;
	node -> next = stack_a -> top;
	stack_a -> top = node;
}
void	radix_lsd(t_stack *stack_a,t_stack *stack_b, int max_number_of_bits)
{
	int current_bit; //bit mais a direita
	t_node *current_node;
	int	bit_is_zero;
	int	node_location; //location of the node in the stack, 0 = top.

	current_bit = 0;
	while(current_bit < max_number_of_bits)
	{
		node_location = 0; //sempre que comeco a analizar dado bit comeco pelo top da stack(location = 0)
		current_node = stack_a -> top;
		while (current_node) //enqanto tenho um node diferente de NULL
		{
			bit_is_zero = check_if_bit_is_0(current_node ->index, current_bit);
			if(bit_is_zero)
			{
				if(node_location + 1 <= ((stack_a -> size / 2 ) + stack_a -> size % 2))
					bubble_up_and_push_with_rotate(stack_a,stack_b,node_location);// depois de fazer isso nao altero a node_location pois vou ter um novo node no local do 0 que estava
				else
					bubble_up_and_push_with_reverse_rotate(stack_a,stack_b,node_location);// depois de fazer isso nao altero a node_location pois vou ter um novo node no local do 0 que estava
			}
			else
				node_location++;
			current_node = get_node_with_location(stack_a, node_location);
		}
		push_b_on_top_of_a(stack_b, stack_a);
		current_bit ++;
	}
}
int	calculate_max_number_of_bits(int biggest_number)
{
	int exponent = 0;
	while (ft_pow(2,exponent)*2 <= biggest_number)// implementar a funcao pow
		exponent++;
	return exponent + 1;
}
int	check_if_bit_is_0(int index,int current_bit)//primeiro bit (bit mais a direita) e' 1
{
	int mask;

	mask = 1 << current_bit;
	if ((index & mask)==0)
		return (1);
	else
		return (0);
}

void	push_b_on_top_of_a(t_stack *stack_b,t_stack *stack_a)
{
	int i;
	int stack_b_size;

	stack_b_size = stack_b -> size;
	i = 1;
	while (i <= stack_b_size)
	{
		push(stack_b,stack_a,'a');
		i++;
	}
}
void	push(t_stack *donor,t_stack *receptor, char stack)
{
	t_node *temp;
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
void	bubble_up_and_push_with_rotate(t_stack* stack_a, t_stack* stack_b,int node_location)//tem que rotacionar o node_location vezes para estar no top
{
	int number_of_rotations;

	number_of_rotations = 0;
	while (number_of_rotations < node_location)
	{
		rotate(stack_a);
		number_of_rotations++;
	}
	push(stack_a,stack_b,'b');
	while (number_of_rotations)
	{
		reverse_rotate(stack_a);
		number_of_rotations--;
	}
}

void	bubble_up_and_push_with_reverse_rotate(t_stack* stack_a, t_stack* stack_b,int node_location)//tem que rotacionar o node_location vezes para estar no top
{
	int number_of_rotations;

	number_of_rotations = 0;
	while (number_of_rotations < stack_a -> size - node_location) //numero de vezes a rodar vai ter que ser uma diferenca com o size tem mais uma porque vai ter que dar a volta e ir para o top
	{
		reverse_rotate(stack_a);
		number_of_rotations++;
	}
	push(stack_a, stack_b, 'b');
	while (number_of_rotations -1)
	{
		rotate(stack_a);
		number_of_rotations--;
	}
}

void	rotate(t_stack* stack_a)
{
	t_node*	used_to_be_last_node;
	t_node* used_to_be_top_node;

	used_to_be_top_node = stack_a -> top;
	used_to_be_last_node = get_node_with_location(stack_a, (stack_a->size) - 1);
	stack_a -> top = used_to_be_top_node -> next;
	used_to_be_last_node -> next =  used_to_be_top_node;
	used_to_be_top_node -> next = NULL;
	write(1, "ra\n", 3);
}
void	reverse_rotate(t_stack* stack_a)
{
	t_node*	used_to_be_last;
	t_node*	used_to_be_penultimate;
	t_node*	used_to_be_top;

	used_to_be_top = stack_a -> top;
	used_to_be_last = get_node_with_location(stack_a,(stack_a->size)-1);
	used_to_be_penultimate = get_node_with_location(stack_a,(stack_a -> size) -2);
	stack_a -> top = used_to_be_last;
	stack_a -> top ->next = used_to_be_top;
	used_to_be_penultimate -> next = NULL;
	write(1,"rra\n",4);
}
t_node*	get_node_with_location(t_stack* stack_a, int node_location)
{
	int i = 0;
	t_node*	current_node = stack_a -> top;
	while (i < node_location)
	{
		current_node = current_node ->next;
		i++;
	}
	return (current_node);
}
void	free_stacks(t_stack* stack_a,t_stack* stack_b)
{
	t_node	*current_node;
	t_node	*next_node;

	free(stack_b);
	current_node = stack_a -> top;
	while(current_node)
	{
		next_node = current_node -> next;
		free(current_node);
		current_node = next_node;
	}
	free(stack_a);
}
void	print_stack(t_stack *stack)
{
	t_node *current = stack->top;
    printf("Stack: ");
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int	validate_argv(int argc, char **argv) //falta lidar com o limite de int
{
	int i;
	int j;

	if (!(argc > 1))
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+') //trocar para ft_isdigit
				return (0);
			j++;
		}
		i++;
	}
	return (check_duplicates(argc,argv));
}
int check_duplicates(int argc,char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc -2)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j])) //trocar para ft_atoi
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_pow(int number,int exponent)
{
	if (exponent == 0)
		return 1;
	else
		return (number * ft_pow(number, exponent - 1));
}
