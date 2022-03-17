/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:03:40 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:23:19 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Insert stack_a into int array a_stack and returns it.
*/
int	*insert_array(t_stack *stack_a, t_size *s)
{
	int	*a_stack;
	int	i;

	a_stack = (int *)ft_calloc(s->start_size, sizeof(int));
	i = 0;
	while (stack_a)
	{
		a_stack[i] = stack_a->data;
		i++;
		stack_a = stack_a->next;
	}
	return (a_stack);
}

/*
DESCRIPTION
	looks for the best replacement.
*/
int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = ((left + right) / 2);
	while (left <= right)
	{
		mid = ((left + right) / 2);
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

/*
DESCRIPTION
	counts the length of the largest increasing subsequence from int array index.
*/
int	get_lis_length(int *index, int *lis, int *arr, t_size *s)
{
	int	i;

	i = 0;
	s->lis_length = -1;
	lis[0] = arr[0];
	while (++i < s->size_a)
		lis[i] = INT_MAX;
	i = 0;
	while (++i < s->size_a)
	{
		index[i] = search_replace(lis, 0, i, arr[i]);
		if (s->lis_length < index[i])
			s->lis_length = index[i];
	}
	if (s->lis_length == 0)
		s->lis_length = 1;
	free(lis);
	return (s->lis_length);
}

/*
DESCRIPTION
	Finds the largest increasing subsequence in stack_a, calculate its length
	and returns it. Elements within the LIS are marked with a flag.
*/
int	lis(t_stack **s_a, int *arr, int i, t_size *s)
{
	int	tmp;
	int	*answer;
	int	*lis;
	int	*index;

	lis = (int *)ft_calloc(s->start_size, s->size_a * (sizeof(int)));
	index = (int *)ft_calloc(s->size_a, s->size_a * (sizeof(int)));
	tmp = s->start_size;
	s->lis_length = get_lis_length(index, lis, arr, s);
	answer = (int *) malloc((s->lis_length + 1) * sizeof(int));
	i = s->size_a;
	tmp = s->lis_length;
	while (--i >= 0)
	{
		if (index[i] == tmp)
		{
			answer[tmp] = arr[i];
			--tmp;
		}
	}
	free(index);
	mark_lis(s_a, answer, s);
	return (s->lis_length);
}

/*
DESCRIPTION
	Iterates over stack_a and marks every element from the LIS in stack_a
	with a struct variable "flag". Flag is set to 1 if the element is in the LIS.
*/
void	mark_lis(t_stack **stack_a, int *lis, t_size *s)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_stack	*max;

	i = 0;
	j = 0;
	tmp = *stack_a;
	max = get_max_node(stack_a);
	while (tmp)
	{
		while (j < s->lis_length)
		{
			if (lis[i] == tmp->data)
				tmp->flag = 1;
			if (s->lis_length == 1)
				max->flag = 1;
			i++;
			j++;
		}
		i = 0;
		j = 0;
		tmp = tmp->next;
	}
	free(lis);
}
