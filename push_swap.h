/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:20:20 by asaber            #+#    #+#             */
/*   Updated: 2023/04/03 00:01:36 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef struct nodelist
{
	int				content;
	int				rank;
	struct nodelist	*next;
}	t_node;

void			fill_stack_a(t_node **s_a, int argc, char **argv);
void			check_errors(int argc, char **argv);
char			**ft_split(char *s, char c);
long long		ft_atoi(char *str);
void			error(int i);
int				first_rank(int	*arr);
void			to_stack_b(t_node **stack_a, t_node **stack_b);
int				t_nodeline(t_node *stack);
int				if_acending(t_node *stack);
int				high_ranked(t_node *stack);
int				low_ranked(t_node *stack);
int				if_repetition(t_node *stack);
int				*arr_sorted(int n, t_node *stack);
void			fil_rank(t_node *stack);
t_node			*ft_lstnew(int content);
void			ra_b(t_node **stack, char c);
t_node			*rra_b(t_node *stack, char c);
t_node			*sa_b(t_node *stack, char c);
void			setranking(t_node *stack_a, int *list);
void			sort_3(t_node **stack_a);
void			sort_5(t_node **stack_a, t_node **stack_b);
void			to_stack_a(t_node **stack_a, t_node **stack_b);
void			pa_b(t_node **source_stack, t_node **tostack, char c);
void			ft_lstadd_front(t_node **lst, t_node *new);
void			ft_lstadd_back(t_node *lst, t_node *new);
void			ft_clear(t_node **stack);
void			check_sec(t_node *stack_a);
//bonus
char			*get_next_line(int fd);
void			rr(t_node **stack_a, t_node **stack_b, char c);
void			ss(t_node **stack_a, t_node **stack_b, char c);
void			rrr(t_node **stack_a, t_node **stack_b, char c);
#endif