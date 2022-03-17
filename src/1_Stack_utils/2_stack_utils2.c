/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_stack_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:35:51 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:18:05 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	size = stack_size(*stack);
	if (*stack == NULL)
	{
		free(*stack);
		return ;
	}
	while (size)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		size--;
	}
	free(*stack);
	*stack = NULL;
}

/*
DESCRIPTION
	is_sorted() checks if the input is already sorted.
	Returns 0 if the input is NOT sorted and 1 if it is sorted.
*/
int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->rank < stack_a->next->rank)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}
