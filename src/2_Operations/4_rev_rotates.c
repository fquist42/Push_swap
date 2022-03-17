/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_rev_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:56:48 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:45 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
rra : reverse rotate a - shift down all elements of stack a by 1.
The last element becomes the first one.
*/
int	rra(t_stack **stack, int op)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = lst_last(*stack);
	if (!*stack || !(*stack)->next)
		return (0);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack;
	*stack = tmp2;
	if (op > 0)
		write(1, "rra\n", 4);
	return (1);
}

/*
rrb : reverse rotate b - shift down all elements of stack b by 1.
The last element becomes the first one.
*/
int	rrb(t_stack **stack, int op)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = lst_last(*stack);
	if (!*stack || !(*stack)->next)
		return (0);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = 0;
	tmp2->next = *stack;
	*stack = tmp2;
	if (op > 0)
		write(1, "rrb\n", 4);
	return (1);
}

/*
rrr : rra and rrb at the same time
*/
int	rrr(t_stack **stack_a, t_stack **stack_b, int op)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (op > 0)
		write(1, "rrr\n", 4);
	return (1);
}
