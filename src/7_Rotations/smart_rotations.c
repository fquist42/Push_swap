/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:35:20 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:22 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Rotates over stack looking for the lowest->data element in stack while
	taking the shortest route (depending on its position (index).
*/
void	rotate_to_min(t_stack **stack, t_size *s)
{
	int		min;
	int		index;

	min = find_min(stack);
	index = get_index(stack, min);
	while (*stack && (*stack)->data != min)
	{
		if (index > (s->size_a / 2))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}

/*
	Rotates over stack_a and stack_b looking for the shortest route to get
	the desired element-pair on top of stack_a and stack_b using normal
	and double rotates.
*/
void	rotate_to_alow(t_stack **stack_a, t_stack **stack_b, t_rotate *vars)
{
	count_ops(stack_a, stack_b, vars);
	while (vars->count_a > 0 && vars->count_b > 0 && vars->r_a == vars->r_b)
	{
		if (vars->r_a == 1)
			rrr(stack_a, stack_b, 1);
		else
			rr(stack_a, stack_b, 1);
		--vars->count_a;
		--vars->count_b;
	}
	while (vars->count_a-- > 0)
	{
		if (vars->r_a == 1)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	while (vars->count_b-- > 0)
	{
		if (vars->r_b == 1)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}

/*
	Count operations to get elements with the lowest operation count
	on top of both stacks.
*/
void	count_ops(t_stack **st_a, t_stack **st_b, t_rotate *vars)
{
	vars->count_a = count_top(st_a, (*st_a)->tmp_a_low, vars);
	vars->r_a = vars->r_dir;
	vars->count_b = count_top(st_b, (*st_b)->tmp_b_low, vars);
	vars->r_b = vars->r_dir;
}
