/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:14:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/01/01 02:03:32 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

static int	ft_delimiter(char check, char c)
{
	if (check == c)
		return (1);
	return (0);
}

static int	ft_countwords(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && ft_delimiter(s[i], c))
			i++;
		if (s[i] && !ft_delimiter(s[i], c))
			nb++;
		while (s[i] && !ft_delimiter(s[i], c))
			i++;
	}
	return (nb);
}

static void	str_increment(char const **s, char c, int *a)
{
	*a = 0;
	while (**s && ft_delimiter(**s, c))
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		a[3];

	a[1] = 0;
	if (!s)
		return (0);
	a[0] = ft_countwords(s, c);
	str = (char **)malloc((a[0] + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (*s && a[1] < a[0])
	{
		str_increment(&s, c, &(a[2]));
		while (s[a[2]++] && !ft_delimiter(s[a[2]], c))
			a[2]++;
		str[a[1]] = (char *)malloc((a[2] + 1) * sizeof(char));
		if (!str[a[1]])
			return (0);
		a[2] = 0;
		while (*s && !ft_delimiter(*s, c))
			str[a[1]][a[2]++] = *s++;
		str[a[1]++][a[2]] = 0;
	}
	str[a[1]] = 0;
	return (str);
}
