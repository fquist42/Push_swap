/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:06:57 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:51 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
DESCRIPTION
	Frees an allocated (struct s_list **list) with optional (bool exit) 
	exit function ft_exit_print. The errorcode from exit() can be defined using
	the parameter (bool exit_status). The function will exit with
	errorcode(bool exit_status). See ft_exit_print for further informations
	about parameters.
*/
void	free_list(t_stack **lst, bool exit, bool exit_status)
{
	t_stack	*current;
	t_stack	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
	lst = NULL;
	if (exit == true && exit_status == false)
		ft_exit_print(exit_status, "Error\n", 2);
	else if (exit == true && exit_status == true)
		ft_exit_print(exit_status, "Error\n", 2);
}

void	exit_free_p(t_stack **stack, char **res)
{
	free_list(stack, false, false);
	ft_free_array(res, true, true);
}

void	exit_free(char **res)
{
	free(res);
	ft_exit_print(true, "Error\n", 2);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_list(stack_a, false, false);
	free_list(stack_b, false, false);
	exit(EXIT_SUCCESS);
}
