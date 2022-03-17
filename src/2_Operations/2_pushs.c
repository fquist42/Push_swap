/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_pushs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:55:44 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:40 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
pa : push a - take the first element at the top of b
and put it at the top of a. Do nothing if b is empty.
*/
int	pa(t_stack **stack_a, t_stack **stack_b, t_size *s, int op)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return (0);
	else
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		if (op > 0)
			write(1, "pa\n", 3);
		s->size_b--;
		s->size_a++;
		return (1);
	}
}

/*
pb : push b - take the first element at the top of a
and put it at the top of b. Do nothing if a is empty.
*/
int	pb(t_stack **stack_a, t_stack **stack_b, t_size *s, int op)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return (0);
	else
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		if (op > 0)
			write(1, "pb\n", 3);
		s->size_a--;
		s->size_b++;
		return (1);
	}
}
