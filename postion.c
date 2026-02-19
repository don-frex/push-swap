/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:41:33 by asaber            #+#    #+#             */
/*   Updated: 2023/03/30 21:04:18 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_ranked(t_node *stack)
{
	int	i;
	int	count;
	int	high;

	i = 1;
	count = 1;
	high = stack->content;
	while (stack)
	{
		if (high < stack->content)
		{
			count = i;
			high = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (count);
}

int	low_ranked(t_node *stack)
{
	int	i;
	int	count;
	int	high;

	i = 1;
	count = 1;
	high = stack->content;
	while (stack)
	{
		if (high > stack->content)
		{
			count = i;
			high = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (count);
}

int	*to_array(t_node *stack)
{
	int	*arr;
	int	i;

	arr = malloc(t_nodeline(stack) * sizeof(stack));
	i = 0;
	while (stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	*arr_sorted(int n, t_node *stack)
{
	int	*arr;
	int	tmp;
	int	i;
	int	j;

	arr = to_array(stack);
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	fil_rank(t_node *stack)
{
	int		*arr;
	int		i;
	int		line;

	arr = arr_sorted(t_nodeline(stack), stack);
	line = t_nodeline(stack);
	while (stack)
	{
		i = 0;
		while (i < line)
		{
			if (arr[i] == stack->content)
				stack->rank = i + 1;
			i++;
		}
		stack = stack->next;
	}
	free(arr);
	arr = NULL;
}
