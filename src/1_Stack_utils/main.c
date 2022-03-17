/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:45:53 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:18:12 by fquist           ###   ########.fr       */
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
		free_stacks(&stack_a, &stack_b);
	argc = 0;
	function_handler(&stack_a, &stack_b, argv, &s);
	if (s.start_size <= 1 || is_sorted(stack_a))
		free_list(&stack_a, false, false);
	else if (!is_sorted(stack_a) && s.start_size == 2)
		sa(&stack_a, 1);
	else if (s.start_size > 2 && s.start_size < 4)
		sort_3(&stack_a, &s);
	else if (s.start_size > 3 && s.start_size <= 15)
		sort_5(&stack_a, &stack_b, &s);
	else
		big_sort_handler(&stack_a, &stack_b, &s, argc);
	free_stacks(&stack_a, &stack_b);
}
