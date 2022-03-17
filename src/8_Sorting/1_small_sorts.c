/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_small_sorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:40:38 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:25 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Sorting variants for stack_size = 3.
	5 cases total. Compare top to middle, middle to bottom, and bottom to top.
*/
void	sort_3(t_stack **stack_a, t_size *s)
{
	int	a;
	int	b;
	int	c;

	a = (int)(*stack_a)->data;
	b = (int)(*stack_a)->next->data;
	c = (int)(*stack_a)->next->next->data;
	if (s->size_a < 3 && (*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 1);
	else if (a > b && b < c && c > a)
		sa(stack_a, 1);
	else if (a > b && b < c && c < a)
		ra(stack_a, 1);
	else if (a < b && b > c && c < a)
		rra(stack_a, 1);
	else if (a > b && b > c && c < a)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a < b && b > c && c > a)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}

/*
	Sorting variants for stack_size > 3.
	5 cases total. Compare top to middle, middle to bottom, and bottom to top.
*/
void	sort_5(t_stack **stack_a, t_stack **stack_b, t_size *s)
{
	if (s->start_size > 4)
	{
		rotate_to_min(stack_a, s);
		pb(stack_a, stack_b, s, 1);
		if (s->start_size > 4 && s->start_size <= 15)
		{
			while (s->size_a > 4)
			{
				rotate_to_min(stack_a, s);
				pb(stack_a, stack_b, s, 1);
			}
		}
	}
	rotate_to_min(stack_a, s);
	pb(stack_a, stack_b, s, 1);
	sort_3(stack_a, s);
	if (s->start_size > 3)
	{
		while (s->size_b > 0)
		{
			rotate_to_min(stack_a, s);
			pa(stack_a, stack_b, s, 1);
		}
	}
}
