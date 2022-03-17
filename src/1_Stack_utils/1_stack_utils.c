/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:10 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:17:48 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	function_handler(t_stack **s_a, t_stack **s_b, char **av, t_size *s)
{
	parser(s_a, av, s);
	check_double_input(s_a);
	set_rankloop(*s_a);
	set_index(s_a, s_b);
}

/*
DESCRIPTION
	push_back() adds the new element created (and allocated) by new_element()
	at the end of the list.	Double input is not valid and the function will exit.
*/
void	push_back(t_stack **stack, int data, t_size *s)
{
	t_stack	*current;

	current = *stack;
	if (*stack == NULL)
	{
		*stack = new_element(data);
		s->size_a++;
		s->start_size++;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_element(data);
		s->size_a++;
		s->start_size++;
	}
}

/*
DESCRIPTION
	new_element() allocates (with ft_calloc(3)) and returns a new element.
	The variable ’data’ is initialized with the value of the parameter
	’data’. The variable ’next’ is initialized to NULL.
RETURN VALUES
	new_element() returns the new element.
*/
t_stack	*new_element(int data)
{
	t_stack	*new_element;

	new_element = ft_calloc(1, sizeof(t_stack));
	new_element->data = data;
	new_element->next = NULL;
	new_element->index = 0;
	new_element->rank = 1;
	new_element->flag = 0;
	new_element->counter = 0;
	return (new_element);
}

/*
DESCRIPTION
	stack_size() counts the number of elements in a list.
RETURN VALUES
	stack_size() returns the count.
*/
int	stack_size(t_stack *stack)
{
	int	ct;

	ct = 0;
	while (stack)
	{
		ct++;
		stack = stack->next;
	}
	return (ct);
}

/*
DESCRIPTION
	ft_lstlast() returns the last element of the list.
*/
t_stack	*lst_last(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
