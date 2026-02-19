/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:59:04 by asaber            #+#    #+#             */
/*   Updated: 2023/04/02 22:41:38 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_node **stack, char c)
{
	t_node	*tmp;
	t_node	*to_end;

	if (t_nodeline(*stack) > 1)
	{
		to_end = *stack;
		tmp = (*stack)->next;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = to_end;
		to_end->next = NULL;
		*stack = tmp;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

t_node	*rra_b(t_node *stack, char c)
{
	t_node	*to_first;
	t_node	*pre;

	to_first = stack;
	if (t_nodeline(stack) > 1)
	{
		while (to_first->next)
		{
			pre = to_first;
			to_first = to_first->next;
		}
		pre->next = NULL;
		to_first->next = stack;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (to_first);
}

t_node	*sa_b(t_node *stack, char c)
{
	t_node	*second;
	int		i;

	i = 1;
	second = stack;
	if (t_nodeline(stack) > 1)
	{
		while (i++ < 2)
			second = second->next;
		stack->next = second->next;
		second->next = stack;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (second);
}

void	pa_b(t_node **source_stack, t_node **tostack, char c)
{
	t_node	*tmp;
	t_node	*prev;

	if (*source_stack)
	{
		prev = *source_stack;
		tmp = (*source_stack)->next;
		if (!(*tostack))
		{
			*tostack = prev;
			(*tostack)->next = NULL;
			*source_stack = tmp;
		}
		else
		{
			ft_lstadd_front(tostack, prev);
			*source_stack = tmp;
		}
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

int	t_nodeline(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
