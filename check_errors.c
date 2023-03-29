/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:43:21 by asaber            #+#    #+#             */
/*   Updated: 2023/03/29 01:54:20 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_first(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] >= '0' && argv[i][0] <= '9')
			&& !(argv[i][0] == '-' || argv[i][0] == '+'))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			sgin;
	long long	res;

	i = 0;
	res = 0;
	sgin = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgin = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - 48;
		}
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == 32))
			return (0);
		i++;
	}
	return (res * sgin);
}

int	check_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	if (!ft_check_first(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) && check_zero(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	if_repetition(s_node *stack)
{
	s_node	*first;
	int		data;

	while (stack)
	{
		data = stack->content;
		first = stack->next;
		while (first)
		{
			if (data == first->content)
				return (1);
			first = first->next;
		}
		stack = stack->next;
	}
	return (0);
}
