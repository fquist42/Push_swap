/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:42:25 by rschleic          #+#    #+#             */
/*   Updated: 2022/03/17 20:21:39 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error(t_stack *s_a, t_stack *s_b, char *operation)
{
	write(2, "Error\n", 6);
	free(operation);
	free_stack(&s_a);
	free_stack(&s_b);
	exit(EXIT_FAILURE);
}

void	check_operations(t_stack **s_a, t_stack **s_b, t_size *s, char *ops)
{
	if (ops == NULL)
		return ;
	if (ps_strcmp(ops, "sa\n"))
		sa(s_a, 0);
	else if (ps_strcmp(ops, "sb\n"))
		sb(s_b, 0);
	else if (ps_strcmp(ops, "ss\n"))
		ss(s_a, s_b, 0);
	else if (ps_strcmp(ops, "pa\n"))
		pa(s_a, s_b, s, 0);
	else if (ps_strcmp(ops, "pb\n"))
		pb(s_a, s_b, s, 0);
	else if (ps_strcmp(ops, "ra\n"))
		ra(s_a, 0);
	else
		check_operations_2(s_a, s_b, ops);
}

void	check_operations_2(t_stack **s_a, t_stack **s_b, char *ops)
{
	if (ops == NULL)
		return ;
	if (ps_strcmp(ops, "rb\n"))
		rb(s_b, 0);
	else if (ps_strcmp(ops, "rr\n"))
		rr(s_a, s_b, 0);
	else if (ps_strcmp(ops, "rra\n"))
		rra(s_a, 0);
	else if (ps_strcmp(ops, "rrb\n"))
		rrb(s_b, 0);
	else if (ps_strcmp(ops, "rrr\n"))
		rrr(s_a, s_b, 0);
	else
		error(*s_a, *s_b, ops);
}

void	get_operations(t_stack **s_a, t_stack **s_b, t_size *s)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation != NULL)
	{
		check_operations(s_a, s_b, s, operation);
		free(operation);
		operation = get_next_line(0);
	}
}

int	ps_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (1)
	{
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			return (1);
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (0);
		i++;
	}
}
