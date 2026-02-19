/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:36:01 by asaber            #+#    #+#             */
/*   Updated: 2023/03/30 21:04:18 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range(int check, int i, int curent_range)
{
	int	max;

	if (check)
		max = i + 35;
	else
		max = i + 15;
	if (curent_range >= i && curent_range < max)
		return (0);
	else if (curent_range < i)
		return (-1);
	else
		return (1);
}

void	to_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	check;

	fil_rank(*stack_a);
	if (t_nodeline(*stack_a) >= 500)
		check = 1;
	else
		check = 0;
	i = 1;
	while (*stack_a)
	{
		if (range(check, i, (*stack_a)->rank) == 0)
		{
			pa_b(stack_a, stack_b, 'b');
			i++;
		}
		else if (range(check, i, (*stack_a)->rank) == -1)
		{
			pa_b(stack_a, stack_b, 'b');
			ra_b(stack_b, 'b');
			i++;
		}
		else
			ra_b(stack_a, 'a');
	}
}

void	to_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	rank;

	while (t_nodeline(*stack_b))
	{
		rank = high_ranked(*stack_b);
		if (rank == 1 || rank <= t_nodeline(*stack_b) / 2)
		{
			while (rank-- > 1)
				ra_b(stack_b, 'b');
			pa_b(stack_b, stack_a, 'a');
		}
		else
		{
			while (rank++ <= t_nodeline(*stack_b))
				*stack_b = rra_b(*stack_b, 'b');
			pa_b(stack_b, stack_a, 'a');
		}
	}
}

void	sort_3(t_node **stack_a)
{
	while (!if_acending(*stack_a))
	{
		if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_a)->content < (*stack_a)->next->next->content)
			*stack_a = sa_b(*stack_a, 'a');
		else if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_a)->content > (*stack_a)->next->next->content)
			ra_b(stack_a, 'a');
		else
			*stack_a = rra_b(*stack_a, 'a');
	}
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	rank;
	int	i;
	int	two;

	two = 1;
	while (two++ < 3)
	{
		rank = low_ranked(*stack_a);
		i = rank;
		if (rank <= 3)
		{
			while (i-- > 1)
				ra_b(stack_a, 'a');
			pa_b(stack_a, stack_b, 'b');
		}
		else
		{
			while (i++ <= t_nodeline(*stack_a))
				*stack_a = rra_b(*stack_a, 'a');
			pa_b(stack_a, stack_b, 'b');
		}
	}
	sort_3(stack_a);
	pa_b(stack_b, stack_a, 'a');
	pa_b(stack_b, stack_a, 'a');
}
