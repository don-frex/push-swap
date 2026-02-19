/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:15:27 by asaber            #+#    #+#             */
/*   Updated: 2023/04/02 21:25:24 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_node **s_a, int argc, char **argv)
{
	char	**numstr;
	int		i;
	int		j;
	int		k ;

	i = 1;
	k = 0;
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
		i++;
	}
}

t_node	*ft_lstnew(int content)
{
	t_node	*begin;

	begin = NULL;
	begin = (t_node *) malloc(sizeof(t_node));
	if (begin == 0)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}

void	ft_lstadd_back(t_node *lst, t_node *new)
{
	t_node	*end;

	end = lst;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	else
		while (end->next)
			end = end->next;
		end->next = new;
		new->next = NULL;
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
