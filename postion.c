/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:41:33 by asaber            #+#    #+#             */
/*   Updated: 2023/03/29 20:47:03 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_ranked(s_node *stack)
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

int	low_ranked(s_node *stack)
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

int	*to_array(s_node *stack)
{
	int	*arr;
	int	i;

	arr = malloc(s_nodeline(stack) * sizeof(stack));
	i = 0;
	while (stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	*arr_sorted(int n, s_node *stack)
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

void	fil_rank(s_node *stack)
{
	int		*arr;
	int		i;
	int		line;

	arr = arr_sorted(s_nodeline(stack), stack);
	line = s_nodeline(stack);
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
