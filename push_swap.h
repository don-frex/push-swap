/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:20:20 by asaber            #+#    #+#             */
/*   Updated: 2023/03/29 15:10:33 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct nodelist
{
	int				content;
	int				rank;
	struct nodelist	*next;
} s_node;

void			fill_stack_a(s_node **s_a, int argc, char **argv);
int				check_errors(int argc, char **argv);
char			**ft_split(char *s, char c);
long long int		ft_atoi(char *str);
int				first_rank(int	*arr);
void			to_stack_b(s_node **stack_a, s_node **stack_b);
int				s_nodeline(s_node *stack);
int				if_acending(s_node *stack);
int				high_ranked(s_node *stack);
int				low_ranked(s_node *stack);
int				if_repetition(s_node *stack);
int				*arr_sorted(int n, s_node *stack);
void			fil_rank(s_node *stack);
s_node			*ft_lstnew(int content);
void			ra_b(s_node **stack, char c);
s_node			*rra_b(s_node *stack, char c);
s_node			*sa_b(s_node *stack, char c);
void			setranking(s_node *stack_a, int *list);
void			sort_3(s_node **stack_a);
void			sort_5(s_node **stack_a, s_node **stack_b);
void			to_stack_a(s_node **stack_a, s_node **stack_b);
void			pa_b(s_node **source_stack, s_node **tostack, char c);
void			ft_lstadd_front(s_node **lst, s_node *new);
void			ft_lstadd_back(s_node *lst, s_node *new);
//bonus
char			*get_next_line(int fd);

#endif