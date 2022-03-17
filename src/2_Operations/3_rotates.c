/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rotates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:56:20 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:43 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
ra : rotate a - shift up all elements of stack a by 1.
The first element becomes the last one.
*/
int	ra(t_stack **stack_a, int op)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		last = lst_last(*stack_a);
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last->next = tmp;
		tmp->next = NULL;
		if (op > 0)
			write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

/*
rb : rotate b - shift up all elements of stack b by 1. 
The first element becomes the last one.
*/
int	rb(t_stack **stack_b, int op)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		last = lst_last(*stack_b);
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = tmp;
		tmp->next = NULL;
		if (op > 0)
			write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

/*
rr : ra and rb at the same time.
*/
int	rr(t_stack **stack_a, t_stack **stack_b, int op)
{
	if (stack_a && stack_b)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		if (op > 0)
			write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
