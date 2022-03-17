/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:28:53 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:22:48 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_INF 10000

/* ************************************************************************** */
/* STANDARD INCLUDES														  */
/* ************************************************************************** */
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libs/libft/inc/libft.h"

/* ************************************************************************** */
/* PUSH_SWAP STACK UTILS													  */
/* ************************************************************************** */
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*tmp_a_low;
	struct s_stack	*tmp_b_low;
	int				data;
	int				rank;
	int				index;
	int				flag;
	int				counter;
}	t_stack;

typedef struct s_size
{
	int	size_a;
	int	size_b;
	int	start_size;
	int	lis_length;
}	t_size;

typedef struct s_rotate
{
	int	count_a;
	int	count_b;
	int	r_a;
	int	r_b;
	int	r_dir;
	int	lowest_op;
}	t_rotate;

typedef struct s_chunk
{
	int	chunk;
	int	chunk_2;
	int	chunk_size;
	int	i_1;
	int	i_2;
	int	i_1_old;
	int	i_2_old;
	int	increase;
}	t_chunk;

t_stack	*new_element(int data);
t_stack	*lst_last(t_stack *stack);
t_stack	*find_min_node(t_stack **stack);
t_stack	*get_max_node(t_stack **stack);
t_size	init_t_size(void);
void	free_list(t_stack **lst, bool exit, bool exit_status);
void	free_stack(t_stack **stack);
void	push_back(t_stack **stack, int data, t_size *s);
int		find_min(t_stack **stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack_a);

/* ************************************************************************** */
/* PUSH_SWAP OPERATIONS														  */
/* ************************************************************************** */
int		sa(t_stack **stack_a, int op);
int		sb(t_stack **stack_b, int op);
int		ss(t_stack **stack_a, t_stack **stack_b, int op);
int		pa(t_stack **stack_a, t_stack **stack_b, t_size *s, int op);
int		pb(t_stack **stack_a, t_stack **stack_b, t_size *s, int op);
int		ra(t_stack **stack_a, int op);
int		rb(t_stack **stack_b, int op);
int		rr(t_stack **stack_a, t_stack **stack_b, int op);
int		rra(t_stack **stack, int op);
int		rrb(t_stack **stack, int op);
int		rrr(t_stack **stack_a, t_stack **stack_b, int op);

/* ************************************************************************** */
/* PUSH_SWAP PARSING														  */
/* ************************************************************************** */
void	parser(t_stack **stack, char **argv, t_size *s);
int		check_input(char **res);
int		ft_atoi_max_min(const char *str);
void	check_double_input(t_stack **stack);
void	exit_free_p(t_stack **stack, char **res);
void	exit_free(char **res);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/* PUSH_SWAP INDEXING & RANKING												  */
/* ************************************************************************** */
void	set_index(t_stack **stack_a, t_stack **stack_b);
void	set_rank(t_stack **stack_a, t_stack *current);
void	set_rankloop(t_stack *stack_a);
int		get_index(t_stack **stack, int value);
int		find_max_rank(t_stack **stack);
int		find_min_rank(t_stack **stack);

/* ************************************************************************** */
/* PUSH_SWAP LARGEST INCREACING SUBSEQUENCE									  */
/* ************************************************************************** */
int		*insert_array(t_stack *stack_a, t_size *s);
int		lis(t_stack **s_a, int *arr, int i, t_size *s);
int		get_lis_length(int *index, int *LIS, int *arr, t_size *s);
int		search_replace(int *lis, int left, int right, int key);
void	mark_lis(t_stack **stack_a, int *lis, t_size *s);

/* ************************************************************************** */
/* PUSH_SWAP CHUNKS															  */
/* ************************************************************************** */
t_chunk	init_t_chunk(t_size *s);
void	increase_4_chunks(t_chunk *c, t_size *s);
void	increase_10_chunks(t_chunk *c);

/* ************************************************************************** */
/* PUSH_SWAP ROTATIONS														  */
/* ************************************************************************** */
void	rotate_to_min(t_stack **stack, t_size *s);
void	rotate_to_alow(t_stack **stack_a, t_stack **stack_b, t_rotate *vars);
void	count_ops(t_stack **st_a, t_stack **st_b, t_rotate *vars);

/* ************************************************************************** */
/* PUSH_SWAP SORTING														  */
/* ************************************************************************** */
void	sort_3(t_stack **stack_a, t_size *s);
void	sort_5(t_stack **stack_a, t_stack **stack_b, t_size *s);
void	big_sort(t_stack **stack_a, t_stack **stack_b, t_size *s);
void	big_sort_handler(t_stack **s_a, t_stack **s_b, t_size *s, int argc);
void	big_sort_chunks(t_stack **stack_a, t_stack **stack_b, t_size *s);
void	push_c1_c4(t_stack **stack_a, t_stack **stack_b, t_size *s, t_chunk *c);
void	push_c2_c3(t_stack **stack_a, t_stack **stack_b, t_size *s, t_chunk *c);
void	count_op_insert(t_stack **a, t_stack **b, t_stack *tmp, t_rotate *vars);
void	get_best(t_stack **st_a, t_stack **st_b, t_rotate *var);
bool	push_chunks(t_stack **stack_a, t_stack **stack_b, t_size *s);
int		insert_in_lis(t_stack **stack_a, t_stack **stack_b, t_size *s);
int		count_top(t_stack **stack_a, t_stack *element, t_rotate *vars);
t_stack	*find_insert_node(t_stack **stack_a, t_stack *element);

/* ************************************************************************** */
/* PUSH_SWAP BONUS															  */
/* ************************************************************************** */
void	get_operations(t_stack **s_a, t_stack **s_b, t_size *s);
void	check_operations(t_stack **s_a, t_stack **s_b, t_size *s, char *ops);
void	check_operations_2(t_stack **s_a, t_stack **s_b, char *ops);
void	error(t_stack *s_a, t_stack *s_b, char *operation);
void	function_handler(t_stack **s_a, t_stack **s_b, char **av, t_size *s);
int		ps_strcmp(char *s1, char *s2);

#endif