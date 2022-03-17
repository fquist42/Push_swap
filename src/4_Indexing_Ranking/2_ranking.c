/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ranking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:55:25 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:06 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Iterates over stack and compares the struct variable "content"
	from the current element from ft_set_rankloop() with the compare_to element
	from ft_set_rank(). The elements will be ranked lowest to highest "content"
	no matter the index of the element itself.
*/
void	set_rank(t_stack **stack_a, t_stack *current)
{
	t_stack	*compare_to;

	compare_to = *stack_a;
	while (compare_to)
	{
		if (current->data > compare_to->data)
			current->rank++;
		compare_to = compare_to->next;
	}
}

/*
	Iterates over stack using the function ft_set_rank on every element.
*/
void	set_rankloop(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		set_rank(&stack_a, current);
		current = current->next;
	}
}

/*
	Iterates over stack looking for the highest rank in stack and returns the rank.
*/
int	find_max_rank(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->rank;
	while (tmp)
	{
		if (tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

/*
	Iterates over stack looking for the lowest rank in stack and returns the rank.
*/
int	find_min_rank(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->rank;
	while (tmp)
	{
		if (tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}
