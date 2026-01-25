/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:15:27 by asaber            #+#    #+#             */
/*   Updated: 2023/03/26 18:15:28 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*ft_lstnew(int content)
{
	s_node	*begin;

	begin = NULL;
	begin = (s_node *) malloc(sizeof(s_node));
	if (begin == 0)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}

void	ft_lstadd_back(s_node *lst, s_node *new)
{
	s_node	*end;

	end = lst;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	else
	{
		while (end->next)
			end = end->next;
		end->next = new;
	}
	new->next = NULL;
}

void	ft_lstadd_front(s_node **lst, s_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
