/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:06:53 by asaber            #+#    #+#             */
/*   Updated: 2023/04/02 22:27:43 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}

int	check(char *line)
{
	if (!ft_memcmp(line, "sa\n", 3) || !ft_memcmp(line, "sb\n", 3))
		return (1);
	else if (!ft_memcmp(line, "ra\n", 3) || !ft_memcmp(line, "rb\n", 3))
		return (1);
	else if (!ft_memcmp(line, "rra\n", 4) || !ft_memcmp(line, "rrb\n", 4))
		return (1);
	else if (!ft_memcmp(line, "pa\n", 3) || !ft_memcmp(line, "pb\n", 3))
		return (1);
	else if (!ft_memcmp(line, "pa\n", 3) || !ft_memcmp(line, "pb\n", 3))
		return (1);
	else if (!ft_memcmp(line, "rr\n", 3) || !ft_memcmp(line, "pb\n", 3))
		return (1);
	write(2, "Error\n", 6);
	return (0);
}

void	sort(t_node **stack_a, t_node **stack_b, char *arr)
{
	if (!ft_memcmp(arr, "sa\n", 3))
		*stack_a = sa_b(*stack_a, 'x');
	else if (!ft_memcmp(arr, "sb\n", 3))
		*stack_b = sa_b(*stack_b, 'x');
	else if (!ft_memcmp(arr, "ra\n", 3))
		ra_b(stack_a, 'x');
	else if (!ft_memcmp(arr, "rb\n", 3))
		ra_b(stack_b, 'x');
	else if (!ft_memcmp(arr, "rra\n", 4))
		*stack_a = rra_b(*stack_a, 'x');
	else if (!ft_memcmp(arr, "rrb\n", 4))
		*stack_b = rra_b(*stack_b, 'x');
	else if (!ft_memcmp(arr, "pa\n", 3))
		pa_b(stack_b, stack_a, 'x');
	else if (!ft_memcmp(arr, "pb\n", 3))
		pa_b(stack_a, stack_b, 'x');
	else if (!ft_memcmp(arr, "ss\n", 3))
		ss(stack_a, stack_b, 'x');
	else if (!ft_memcmp(arr, "rr\n", 3))
		rr(stack_a, stack_b, 'x');
	else
		rrr(stack_a, stack_b, 'x');
}

void	check_stack(t_node *stack_a, int size)
{
	if (if_acending(stack_a) && size == t_nodeline(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_errors(argc, argv);
	fill_stack_a(&stack_a, argc, argv);
	check_sec(stack_a);
	fil_rank(stack_a);
	size = t_nodeline(stack_a);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!check(line))
			return (0);
		sort(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	check_stack(stack_a, size);
}
