/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:45:31 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:20:56 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	is_digit(char *c);
static int	first_index_digit(char *c);
static int	double_sign(char *res);
// static int	no_input(int argc, char **argv, int i);

/*
DESCRIPTION
	Parses the input from argv into stack.
	A combination of strings and non-string inputs
	are valid. Duplicates as well as non numeric inputs are not
	allowed and the function will exit with errorcode(1);
*/
void	parser(t_stack **stack, char **argv, t_size *s)
{
	char	**res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (argv[++j])
	{
		res = ft_split(argv[j], ' ');
		i = -1;
		if (*res == NULL)
			exit_free(res);
		while (res[++i])
		{
			if ((double_sign(res[i]) == true && is_digit(res[i]) == true
					&& ft_strlen(res[i]) <= 11)
				&& first_index_digit(res[i]) == true)
				push_back(stack, ft_atoi_max_min(res[i]), s);
			else
				exit_free_p(stack, res);
		}
		ft_free_array(res, false, false);
	}
}

static int	double_sign(char *res)
{
	if (ft_is_sign(res[0]) == true && ft_is_sign(res[1]) == true)
		return (0);
	else if (ft_is_sign(res[0]) == true && ft_strlen(res) <= 1)
		return (0);
	else
		return (1);
}

/*
DESCRIPTION
	Decimal-digit character test
	The is_digit() function tests for a decimal digit character (0-9).
RETURN VALUES
	The is_digit() function return zero if the character tests false 
	and return non-zero if the character tests true.
*/
static int	is_digit(char *c)
{
	int	i;

	i = 1;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	first_index_digit(char *c)
{
	if ((*c >= '0' && *c <= '9') || (*c == '-'))
		return (1);
	else
		return (0);
}
