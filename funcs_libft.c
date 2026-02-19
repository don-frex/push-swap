/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:10:40 by asaber            #+#    #+#             */
/*   Updated: 2023/04/02 16:27:00 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i + 1] && s[i] != c)
			i++;
		i++;
	}
	return (count);
}

size_t	ft_len(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

size_t	split_part(char **tab, const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		count;

	i = 0;
	count = 0;
	while (i < ft_count(s, c))
	{
		j = 0;
		len = ft_len(&s[count], c);
		tab[i] = malloc((len + 1) * sizeof(char));
		if (!tab[i])
			return (0);
		while (s[count] == c)
			count++;
		while (s[count] != c && s[count])
			tab[i][j++] = s[count++];
		tab[i++][j] = '\0';
	}
	tab[i] = 0;
	return (1337);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (0);
	count = ft_count(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (0);
	split_part(tab, s, c);
	return (tab);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			sgin;
	long long	res;

	i = 0;
	res = 0;
	sgin = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgin = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		if (!(str[i] >= '0' && str[i] <= '9')
			|| (sgin == -1 && res > INT_MIN) || (sgin == 1 && res > INT_MAX))
			return (0);
		i++;
	}
	return (res * sgin);
}
