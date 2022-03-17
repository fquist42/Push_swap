/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_small_chunks_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:35:16 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:18 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Increases chunk and chunk2 4 times so that a total of 4 chunks are pushed
	while following a specific pattern.
	The largest chunks are on the edges of stack_b and the smallest chunks
	are in the middle. Used for medium stack_sizes.
*/
void	increase_4_chunks(t_chunk *c, t_size *s)
{
	c->chunk = s->start_size;
	c->i_2 = c->chunk_size * 3;
	c->chunk_2 = c->chunk_size * 3;
}

/*
DESCRIPTION
	Initializes struct t_chunk c.
*/
t_chunk	init_t_chunk(t_size *s)
{
	t_chunk	c;

	if (s->start_size > 15)
		c.chunk = s->start_size / 4;
	c.increase = 0;
	c.i_1_old = 0;
	c.i_2_old = 0;
	c.i_1 = 0;
	c.i_2 = c.chunk;
	c.chunk_size = c.chunk;
	c.chunk_2 = c.chunk + c.chunk_size;
	return (c);
}
