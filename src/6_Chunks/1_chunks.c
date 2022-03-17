/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_chunks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:19:45 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:15 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	increase_1(t_chunk *c);
static void	increase_2(t_chunk *c);
static void	increase_3(t_chunk *c);
static void	increase_4(t_chunk *c);

/*
DESCRIPTION
	Increases chunk and chunk2 4 times so that a total of 10 chunks are pushed
	while following a specific pattern.
	The largest chunks are on the edges of stack_b and the smallest chunks
	are in the middle. Used for stack_sizes > 100.
*/
void	increase_10_chunks(t_chunk *c)
{
	if (c->increase == 0)
		increase_1(c);
	else if (c->increase == 1)
		increase_2(c);
	else if (c->increase == 2)
		increase_3(c);
	else if (c->increase == 3)
		increase_4(c);
	c->increase++;
	if (c->increase == 4)
		c->increase = 3;
}

static void	increase_1(t_chunk *c)
{
	c->i_1_old = c->chunk_size * 3 - c->i_1_old;
	c->i_2_old = c->chunk_size * 2;
	c->chunk = (c->chunk_size * 4);
	c->i_1 = c->chunk_size * 3;
	c->chunk_2 = c->chunk_2 + c->chunk_size;
	c->i_2 = c->chunk_size * 2;
}

static void	increase_2(t_chunk *c)
{
	c->i_1_old = c->chunk_size * 4;
	c->i_2_old = c->chunk;
	c->chunk = c->chunk + c->chunk_size;
	c->i_1 = c->chunk_size * 4;
	c->chunk_2 = c->chunk_2 * 2;
	c->i_2 = c->chunk;
}

static void	increase_3(t_chunk *c)
{
	c->i_1_old = c->chunk_2 + c->chunk_size;
	c->i_2_old = c->chunk_size * 6;
	c->chunk = c->chunk + (c->chunk_size * 3);
	c->i_1 = c->chunk_2 + c->chunk_size;
	c->chunk_2 = c->chunk_2 + c->chunk_size;
	c->i_2 = c->chunk_size * 6;
}

static void	increase_4(t_chunk *c)
{
	c->i_1_old = c->chunk_2 + c->chunk_size;
	c->i_2_old = c->chunk;
	c->chunk = c->chunk + c->chunk_size;
	c->i_1 = c->chunk_2 + c->chunk_size;
	c->chunk_2 = c->chunk_2 + (c->chunk_size * 3);
	c->i_2 = c->chunk;
}
