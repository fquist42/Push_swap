/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:26:23 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:54 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	min_max_check(long long int n);

/*
DESCRIPTION
	Convert ASCII string to integer.
	The ft_atoi_ps() function converts the initial portion of the string 
	pointed to by str to int representation. INT_MAX & INT_MIN are not 
	allowed and the function will exit with exitcode(1).
RETURN VALUES
	Returns the converted string.
*/
int	ft_atoi_max_min(const char *str)
{
	long long int	n;
	int				is_negative;

	n = 0;
	is_negative = 1;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_is_digit(*str))
	{
		n = (n * 10) + (*str - '0');
		if (n < 0 && is_negative == -1)
			return (0);
		else if (n < 0 && is_negative == 1)
			return (-1);
		str++;
	}
	min_max_check(n * is_negative);
	return (n * is_negative);
}

static void	min_max_check(long long int n)
{
	if (n < INT_MIN || n > INT_MAX || ft_get_numlen(n) > 11)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_double_input(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	while (tmp1->next)
	{
		if (tmp2->data == tmp1->data)
			free_list(stack, true, false);
		if (!(tmp2)->next)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp1;
		}
		tmp2 = tmp2->next;
	}
}
