/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_insertion_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:28:46 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:32 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Insert elements with lowest op-count back into LIS on stack_a.
*/
int	insert_in_lis(t_stack **stack_a, t_stack **stack_b, t_size *s)
{
	t_rotate	vars;

	vars.r_a = 0;
	vars.r_b = 0;
	vars.count_a = 0;
	vars.count_b = 0;
	vars.lowest_op = 0;
	while (*stack_b)
	{
		(*stack_a)->tmp_a_low = NULL;
		(*stack_b)->tmp_b_low = NULL;
		set_index(stack_a, stack_b);
		get_best(stack_a, stack_b, &vars);
		if ((*stack_a)->tmp_a_low == NULL)
			return (0);
		rotate_to_alow(stack_a, stack_b, &vars);
		pa(stack_a, stack_b, s, 1);
	}
	return (0);
}

/*
	Calculates which element-pair (to be inserted from stack_b to a
	& insert into on stack_a) has lowest op-count.
*/
void	get_best(t_stack **stack_a, t_stack **stack_b, t_rotate *vars)
{
	t_stack	*tmp;
	int		tmp_count;

	vars->lowest_op = INT_INF;
	tmp = *stack_b;
	while (tmp)
	{
		count_op_insert(stack_a, stack_b, tmp, vars);
		if (vars->r_a == vars->r_b)
		{
			if (vars->count_a > vars->count_b)
				tmp_count = vars->count_a;
			else
				tmp_count = vars->count_b;
		}
		else
			tmp_count = vars->count_a + vars->count_b;
		if (tmp_count < vars->lowest_op)
		{
			(*stack_a)->tmp_a_low = find_insert_node(stack_a, tmp);
			(*stack_b)->tmp_b_low = tmp;
			vars->lowest_op = tmp_count;
		}
		tmp = tmp->next;
	}
}

/*
	Counts op to get specific element on top of stack_a and stack_b and
	set the variable for the needed rotation direction for later use
	(double rotations).
*/
void	count_op_insert(t_stack **a, t_stack **b, t_stack *tmp, t_rotate *var)
{
	var->count_a = count_top(a, find_insert_node(a, tmp), var);
	var->r_a = var->r_dir;
	var->count_b = count_top(b, tmp, var);
	var->r_b = var->r_dir;
}

/*
	Counts op to get specific element on top of stack and returns the counter
	for that element.
*/
int	count_top(t_stack **stack, t_stack *element, t_rotate *vars)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack;
	size = stack_size(*stack);
	element->counter = 0;
	vars->r_dir = 0;
	while (tmp != NULL && tmp != element)
	{
		element->counter++;
		if (element->index > size / 2)
		{
			vars->r_dir = 1;
			element->counter = (size - element->index) + 1;
		}
		tmp = tmp->next;
	}
	return (element->counter);
}

/*
	Finds the best node on which to insert the best element from stack_b
	and returns it.
*/
t_stack	*find_insert_node(t_stack **stack_a, t_stack *element)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = *stack_a;
	node = NULL;
	while (tmp)
	{
		if (tmp->next && tmp->rank < element->rank
			&& tmp->next->rank > element->rank)
			node = tmp->next;
		else if (tmp->rank < element->rank && tmp->next == NULL
			&& (*stack_a)->rank > element->rank)
			node = *stack_a;
		else if (element->rank > find_max_rank(stack_a)
			|| element->rank < find_min_rank(stack_a))
		{
			node = find_min_node(stack_a);
			break ;
		}
		tmp = tmp->next;
	}
	return (node);
}
