/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:44:16 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:18:10 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Initializes the struct t_size s and returns it.
*/
t_size	init_t_size(void)
{
	t_size	s;

	s.size_a = 0;
	s.size_b = 0;
	s.start_size = 0;
	s.lis_length = 0;
	return (s);
}
