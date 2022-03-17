/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_find_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:01:07 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:18:07 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Finds smallest element in a stack and returns the element.
*/
t_stack	*find_min_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = tmp;
	while (tmp)
	{
		if (tmp->rank < min->rank)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

/*
DESCRIPTION
	Finds smallest element in a stack and returns the element.
*/
t_stack	*get_max_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->rank < max->rank)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

/*
DESCRIPTION
	Finds smallest element in a stack and returns its integer value.
*/
int	find_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	if (!*stack)
		return (0);
	tmp = *stack;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
