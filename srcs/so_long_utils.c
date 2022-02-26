/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:14:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/26 13:17:47 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

size_t	ft_delimiter(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

size_t	ft_wordcount(char *str, t_map *mp)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_delimiter(str[i]))
			i++;
		if (str[i] && !ft_delimiter(str[i]))
			nb++;
		while (str[i] && !ft_delimiter(str[i]))
			i++;
	}
	mp->height = nb;
	return (nb);
}

void	ft_split(char *str, t_map *mp)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str, mp);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		ft_error(mp);
	i = 0;
	while (i < wordc)
	{
		while (*str && ft_delimiter(*str))
			str++;
		x = 0;
		while (str[x] && !ft_delimiter(str[x]))
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && !ft_delimiter(*str))
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = 0;
	mp->map = ret;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a[4];

	a[0] = 0;
	a[1] = 0;
	if (!s1 || !s2)
		return (0);
	a[2] = ft_strlen(s1);
	a[3] = ft_strlen(s2);
	ret = (char *)malloc((a[2] + a[3] + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (a[0] < a[2])
	{
		ret[a[0]] = s1[a[0]];
		a[0]++;
	}
	while (a[1] < a[3])
		ret[a[0]++] = s2[a[1]++];
	ret[a[0]] = 0;
	free(s1);
	return (ret);
}
