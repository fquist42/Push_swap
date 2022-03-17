/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:11:38 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:21:36 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_size	s;

	stack_a = NULL;
	stack_b = NULL;
	s = init_t_size();
	if (argc < 2)
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	argc = 0;
	function_handler(&stack_a, &stack_b, argv, &s);
	get_operations(&stack_a, &stack_b, &s);
	if (is_sorted(stack_a) && s.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
