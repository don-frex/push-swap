/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:39:55 by asaber            #+#    #+#             */
/*   Updated: 2023/03/27 00:03:47 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_acending(s_node *stack)
{
	s_node	*comp;

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

void	setranking(s_node *stack_a, int *list)
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
