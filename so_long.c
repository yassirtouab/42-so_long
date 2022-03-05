/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/05 11:08:56 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background(t_map *mp, t_mlx *mlx)
{
	while (mp->map[mlx->y])
	{
		mlx->x = 0;
		while (mp->map[mlx->y][mlx->x])
		{
			mlx_put_image_to_window(mlx->init,
				mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
			mlx->x++;
		}
		mlx->y++;
	}
}

int	ft_put_player(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->player, mlx->x * 50, mlx->y * 50);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, mlx->x * 50, mlx->y * 50);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
	return (0);
}

void	ft_map_start(t_map *mp, t_mlx *mlx)
{
	ft_background(mp, mlx);
	mlx->y = 0;
	while (mp->map[mlx->y])
	{
		mlx->x = 0;
		while (mp->map[mlx->y][mlx->x])
		{
			if (mp->map[mlx->y][mlx->x] == '1')
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->wall, mlx->x * 50, mlx->y * 50);
			else if (mp->map[mlx->y][mlx->x] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->col, mlx->x * 50, mlx->y * 50);
			else if (mp->map[mlx->y][mlx->x] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->exit, mlx->x * 50, mlx->y * 50);
			else if (mp->map[mlx->y][mlx->x] == 'X')
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->enm, mlx->x * 50, mlx->y * 50);
			else if (mp->map[mlx->y][mlx->x] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, mlx->x * 50, mlx->y * 50);
				// mlx_loop_hook(mlx->win, ft_put_player, mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}

void	ft_player_pos(t_mlx *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	while (mlx->map[mlx->y] && mlx->map[mlx->y][mlx->x] != 'P')
	{
		mlx->x = 0;
		while (mlx->map[mlx->y][mlx->x] && mlx->map[mlx->y][mlx->x] != 'P')
		{
			if (mlx->map[mlx->y][mlx->x] == 'P')
				break ;
			mlx->x++;
		}
		if (mlx->map[mlx->y][mlx->x] == 'P')
			break ;
		mlx->y++;
	}
}

int	ft_move(int keycode, t_mlx *mlx)
{
	if (ft_check_movement(keycode, mlx))
	{
		mlx_put_image_to_window(mlx->init,
			mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
		if (keycode == UP)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, mlx->x * 50, --(mlx->y) * 50);
		else if (keycode == DOWN)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, mlx->x * 50, ++(mlx->y) * 50);
		else if (keycode == RIGHT)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, ++(mlx->x) * 50, mlx->y * 50);
		else if (keycode == LEFT)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->player2, --(mlx->x) * 50, mlx->y * 50);
	}
	else if (keycode == ESC)
		exit (0);
	return (0);
}

int	ft_valid_movement(char npos, t_mlx *mlx)
{
	if (npos == '0' || npos == 'C' || npos == 'P' || (npos == 'E' && mlx->c == mlx->collected))
		return (1);
	else if (npos == 'X' )
	{
		mlx_put_image_to_window(mlx->init,
			mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
	}
	return (0);
}

int	ft_check_movement(int keycode, t_mlx *mlx)
{
	if (keycode == UP)
		return (ft_valid_movement(mlx->map[mlx->y - 1][mlx->x], mlx));
	else if (keycode == DOWN)
		return (ft_valid_movement(mlx->map[mlx->y + 1][mlx->x], mlx));
	else if (keycode == RIGHT)
		return (ft_valid_movement(mlx->map[mlx->y][mlx->x + 1], mlx));
	else if (keycode == LEFT)
		return (ft_valid_movement(mlx->map[mlx->y][mlx->x - 1], mlx));
	return (0);
}

int	ft_xpress(t_mlx *mlx)
{
	printf("exiting %d\n", mlx->x);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*mp;
	t_mlx	*mlx;

	if (ac == 2)
	{
		mp = malloc(sizeof(t_map));
		mlx = malloc(sizeof(t_mlx));
		ft_mp_init(mp);
		mp->map_file = ft_strdup(av[1]);
		ft_map_checker(mp, mlx);
		mlx_start(mlx, mp);
		ft_map_start(mp, mlx);
		ft_player_pos(mlx);
		mlx_hook(mlx->win, 17, 0, ft_xpress, mlx);
		mlx_key_hook(mlx->win, ft_move, mlx);
		mlx_loop(mlx);
		ft_quit(mp, mlx);
	}
	return (0);
}
