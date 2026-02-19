/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:10:17 by asaber            #+#    #+#             */
/*   Updated: 2023/03/30 21:17:49 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, char c)
{
	ra_b(stack_a, c);
	ra_b(stack_b, c);
}

void	ss(t_node **stack_a, t_node **stack_b, char c)
{
	*stack_a = sa_b(*stack_a, c);
	*stack_b = sa_b(*stack_b, c);
}

void	rrr(t_node **stack_a, t_node **stack_b, char c)
{
	*stack_a = rra_b(*stack_a, c);
	*stack_b = rra_b(*stack_b, c);
}
