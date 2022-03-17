/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_big_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:44:11 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:30 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Pushes from stack_a to stack_b leaving LIS-marked elements on stack_a.
	Rotation (rb) is handled by big_sort().
*/
bool	push_chunks(t_stack **stack_a, t_stack **stack_b, t_size *s)
{
	if ((*stack_a)->flag == false)
	{
		pb(stack_a, stack_b, s, 1);
		return (true);
	}
	else if ((*stack_a)->flag == true)
		ra(stack_a, 1);
	return (false);
}

/*
	Pushes from stack_a to stack_b leaving LIS-marked elements on stack_a.
	Rotate after push only when element was from smaller chunk.
*/
void	push_c1_c4(t_stack **stack_a, t_stack **stack_b, t_size *s, t_chunk *c)
{
	if ((*stack_a)->flag == false)
	{
		pb(stack_a, stack_b, s, 1);
		if (s->size_b > 1)
			rb(stack_b, 1);
	}
	else if ((*stack_a)->flag == true)
		ra(stack_a, 1);
	c->i_1++;
}

/*
	Pushes from stack_a to stack_b leaving LIS-marked elements on stack_a.
*/
void	push_c2_c3(t_stack **stack_a, t_stack **stack_b, t_size *s, t_chunk *c)
{
	if ((*stack_a)->flag == false)
		pb(stack_a, stack_b, s, 1);
	else if ((*stack_a)->flag == true)
		ra(stack_a, 1);
	c->i_2++;
}
