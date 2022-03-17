/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_big_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:21:34 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:28 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	Starter function for dependencies (LIS) and big_sort().
*/
void	big_sort_handler(t_stack **s_a, t_stack **s_b, t_size *s, int argc)
{
	int		*arr;

	arr = insert_array(*s_a, s);
	s->lis_length = lis(s_a, arr, argc, s);
	big_sort(s_a, s_b, s);
	free(arr);
}

/*
	Sorting algorithm for big stack_sizes up to 500* nbrs using 4 chunks and LIS.
	*(and probably more but not tested)
*/
void	big_sort(t_stack **stack_a, t_stack **stack_b, t_size *s)
{
	t_chunk	c;

	c = init_t_chunk(s);
	while (s->size_a > s->lis_length)
	{
		if (c.chunk <= s->start_size && (c.i_1 == c.chunk && c.i_2 == c.chunk_2
				&& c.chunk < c.chunk_2))
			increase_4_chunks(&c, s);
		if (((*stack_a)->rank <= c.chunk && c.chunk < c.chunk_2)
			|| ((*stack_a)->rank <= c.chunk_2 && c.chunk > c.chunk_2))
			push_c1_c4(stack_a, stack_b, s, &c);
		else if (((*stack_a)->rank <= c.chunk_2 && c.chunk < c.chunk_2)
			|| ((*stack_a)->rank <= c.chunk && c.chunk > c.chunk_2))
			push_c2_c3(stack_a, stack_b, s, &c);
		else
			ra(stack_a, 1);
	}
	insert_in_lis(stack_a, stack_b, s);
	rotate_to_min(stack_a, s);
}
