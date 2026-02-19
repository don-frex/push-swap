/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:43:21 by asaber            #+#    #+#             */
/*   Updated: 2023/04/05 21:54:40 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_first(int argc, char **argv)
{
	int		i;
	char	**av;

	av = ft_split(argv[1], ' ');
	if (!av[0])
		error(1);
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] >= '0' && argv[i][0] <= '9') && !(argv[i][0] == ' ')
			&& !(argv[i][0] == '-' || argv[i][0] == '+'))
			return (0);
		i++;
	}
	return (1);
}

void	error(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	exit(i);
}

int	check_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**arg;

	if (!ft_check_first(argc, argv))
		error(1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		arg = ft_split(argv[i], ' ');
		while (arg[j])
		{
			if (!ft_atoi(arg[j]) && check_zero(arg[j]))
				error(1);
			j++;
		}
		k = 0;
		while (arg[k])
			free(arg[k++]);
		free(arg);
		i++;
	}
}

int	if_repetition(t_node *stack)
{
	t_node	*first;
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
