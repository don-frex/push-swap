/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:07 by asaber            #+#    #+#             */
/*   Updated: 2023/04/05 20:07:53 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	let_sort(t_node *stack_a, t_node *stack_b)
{
	if (t_nodeline(stack_a) == 2)
		stack_a = sa_b(stack_a, 'a');
	else if (t_nodeline(stack_a) == 3)
		sort_3(&stack_a);
	else if (t_nodeline(stack_a) == 5)
		sort_5(&stack_a, &stack_b);
	else
	{
		to_stack_b(&stack_a, &stack_b);
		to_stack_a(&stack_a, &stack_b);
	}
	ft_clear(&stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	check_errors(argc, argv);
	fill_stack_a(&stack_a, argc, argv);
	check_sec(stack_a);
	if (if_acending(stack_a))
	{
		ft_clear(&stack_a);
		error(0);
	}
	let_sort(stack_a, stack_b);
	return (0);
}
