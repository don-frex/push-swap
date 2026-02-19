/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:39:55 by asaber            #+#    #+#             */
/*   Updated: 2023/04/03 00:01:30 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	if_acending(t_node *stack)
{
	t_node	*comp;

	if (!stack)
		return (0);
	comp = stack->next;
	while (comp)
	{
		if (comp->content < stack->content)
		{
			return (0);
		}
		stack = stack->next;
		comp = stack->next;
	}
	return (1);
}

void	setranking(t_node *stack_a, int *list)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->rank = list[i];
		stack_a = stack_a->next;
		i++;
	}
}

void	check_sec(t_node *stack_a)
{
	if (if_repetition(stack_a))
	{
		ft_clear(&stack_a);
		error(1);
	}
}
