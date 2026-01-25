/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:07 by asaber            #+#    #+#             */
/*   Updated: 2023/03/29 21:52:22 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_clear(s_node **stack)
{
	s_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
}
void	fill_stack_a(s_node **s_a, int argc, char **argv)
{
	char	**numstr;
	int		i;
	int		j;
	int		k = 0;

	i = 1;
	while (i < argc)
	{
		numstr = ft_split(argv[i], ' ');
		j = 0;
		while (numstr[j])
		{
			if (i == 1 && j == 0)
				*s_a = ft_lstnew(ft_atoi(numstr[j]));
			else
				ft_lstadd_back(*s_a, ft_lstnew(ft_atoi(numstr[j])));
			j++;
		}
		k = 0;
		while (numstr[k])
			free(numstr[k++]);
		free(numstr);
		numstr = NULL;
		i++;
	}
}

void	let_sort(s_node **stack_a)
{
	s_node	*stack_b;

	stack_b = NULL;
	if (s_nodeline(*stack_a) == 3)
		sort_3(stack_a);
	else if (s_nodeline(*stack_a) == 5)
		sort_5(stack_a, &stack_b);
	else
	{
		to_stack_b(stack_a, &stack_b);
		to_stack_a(stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	s_node	*stack_a;

	stack_a = NULL;
	if (!(argc > 1))
		return (0);
	if (!check_errors(argc, argv))
		return (0);
	fill_stack_a(&stack_a, argc, argv);
	if (if_repetition(stack_a))
	{
		ft_clear(&stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (if_acending(stack_a))
	{
		ft_clear(&stack_a);
		return (0);
	}
	let_sort(&stack_a);
	ft_clear(&stack_a);
	stack_a = NULL;
	return (0);
}
