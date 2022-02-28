/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:08:36 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/28 18:31:38 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_checker(t_map *mp, t_mlx *mlx)
{
	int	fd;

	ft_map_extension(mp, mlx);
	fd = open(mp->map_file, O_RDONLY);
	ft_read(fd, mp, mlx);
	close(fd);
	ft_map_valid_char(mp, mlx);
	if (!mp->c || mp->e != 1 || mp->p != 1)
		ft_error(mp, mlx);
	ft_split(mp->mapl, mp, mlx);
	ft_check_rect(mp, mlx);
	ft_check_walls(mp, mlx);
}

void	ft_map_extension(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	if (mp->map_file[0] == '.' || ft_strlen(mp->map_file) < 5)
		ft_error(mp, mlx);
	while (mp->map_file[i])
		i++;
	i--;
	if (!(mp->map_file[i] == 'r' && mp->map_file[i - 1] == 'e'
			&& mp->map_file[i - 2] == 'b' && mp->map_file[i - 3] == '.'))
		ft_error(mp, mlx);
}

void	ft_map_valid_char(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (mp->mapl[i])
	{
		if (mp->mapl[i] == '1' || mp->mapl[i] == '0' || mp->mapl[i] == 'C'
			|| mp->mapl[i] == 'E' || mp->mapl[i] == 'P' || mp->mapl[i] == '\n'
			|| mp->mapl[i] == 'X')
		{
			if (mp->mapl[i] == 'E')
				mp->e++;
			else if (mp->mapl[i] == 'C')
				mp->c++;
			else if (mp->mapl[i] == 'P')
				mp->p++;
			else if (mp->mapl[i] == '\n'
				&& mp->mapl[i + 1] == '\n' && mp->mapl[i + 2])
				ft_error(mp, mlx);
		}
		else
			ft_error(mp, mlx);
		i++;
	}
}

void	ft_check_rect(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	mp->width = ft_strlen(mp->map[i]);
	while (mp->map[i])
	{
		if (mp->width != ft_strlen(mp->map[i]))
			ft_error(mp, mlx);
		i++;
	}
}

void	ft_check_walls(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (mp->map[i])
	{
		if (mp->map[i][0] != '1' || mp->map[i][mp->width - 1] != '1')
			ft_error(mp, mlx);
		i++;
	}
	i = 0;
	while (i < mp->width)
	{
		if (mp->map[0][i] != '1' || mp->map[mp->height - 1][i] != '1')
			ft_error(mp, mlx);
		i++;
	}
}
