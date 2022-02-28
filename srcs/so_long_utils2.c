/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 02:04:27 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/28 18:04:37 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_read(int fd, t_map *mp, t_mlx *mlx)
{
	char	*buffer;
	char	*mapline;
	int		rd;

	rd = 1;
	mapline = ft_strdup("");
	buffer = malloc(2);
	mapline[0] = 0;
	buffer[1] = 0;
	while (rd == 1)
	{
		rd = read(fd, &buffer[0], 1);
		if (rd == -1)
		{
			free(buffer);
			free(mapline);
			ft_error(mp, mlx);
		}
		mapline = ft_strjoin(mapline, buffer);
	}
	free(buffer);
	mp->mapl = mapline;
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
		write(fd, &s[i++], 1);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = ft_strlen(str);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
