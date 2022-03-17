/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_swaps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:54:52 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:37 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
sa : swap a - swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
int	sa(t_stack **stack_a, int op)
{
	t_stack	*tmp;

	if (stack_size(*stack_a) > 1)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
		if (op > 0)
			write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

/*
sb : swap b - swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/
int	sb(t_stack **stack_b, int op)
{
	t_stack	*tmp;

	if (stack_size(*stack_b) > 1)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
		if (op > 0)
			write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

/*
ss : sa and sb at the same time.
*/
int	ss(t_stack **stack_a, t_stack **stack_b, int op)
{
	if ((stack_size(*stack_a) + stack_size(*stack_b)) > 2)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		if (op > 0)
			write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}
