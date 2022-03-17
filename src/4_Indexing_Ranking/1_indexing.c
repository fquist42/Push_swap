/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_indexing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:27:57 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:02 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Iterates over 2 lists and sets the struct variable "index" for each element
	in the lists according to its position.
*/
void	set_index(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = 1;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

/*
DESCRIPTION
	Compares the struct variable "data" with parameter "value" and returns
	the index of the matching element.
	Returns 0 if stack is empty or the list length if nothing matched.
*/
int	get_index(t_stack **stack, int value)
{
	t_stack	*tmp;
	int		i;

	if (!*stack)
		return (0);
	tmp = *stack;
	i = 1;
	while (tmp->data != value)
	{
		tmp = (tmp)->next;
		i++;
	}
	return (i);
}
