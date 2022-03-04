/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/04 20:50:24 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mp_init(t_map *mp)
{
	mp->c = 0;
	mp->p = 0;
	mp->e = 0;
	mp->width = 0;
	mp->height = 0;
	mp->map_file = NULL;
	mp->mapl = NULL;
	mp->map = NULL;
}

void	ft_quit(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	free(mp->mapl);
	free(mp->map_file);
	while (i < mp->height)
		free(mp->map[i++]);
	free(mp->map);
	free(mp);
	free(mlx);
	exit(0);
}

void	ft_error(t_map *mp, t_mlx *mlx)
{
	ft_putstr_fd("Error\n", 2);
	ft_quit(mp, mlx);
}

void	mlx_start(t_mlx *mlx, t_map *mp)
{
	mlx->h = 50;
	mlx->w = 50;
	mlx->width = 0;
	mlx->height = 0;
	mlx->x = 0;
	mlx->y = 0;
	ft_win_size(mp, mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->height, "SO_LONG");
	mlx->bg = mlx_xpm_file_to_image(mlx->init, "./assets/images/bg.xpm", &mlx->w, &mlx->h);
	mlx->player = mlx_xpm_file_to_image(mlx->init, "./assets/images/player2nd.xpm", &mlx->w, &mlx->h);
	mlx->player2 = mlx_xpm_file_to_image(mlx->init, "./assets/images/player.xpm", &mlx->w, &mlx->h);
	mlx->enm = mlx_xpm_file_to_image(mlx->init, "./assets/images/saw.xpm", &mlx->w, &mlx->h);
	mlx->wall = mlx_xpm_file_to_image(mlx->init, "./assets/images/box.xpm", &mlx->w, &mlx->h);
	mlx->exit = mlx_xpm_file_to_image(mlx->init, "./assets/images/DoorOpen.xpm", &mlx->w, &mlx->h);
	mlx->exitc = mlx_xpm_file_to_image(mlx->init, "./assets/images/DoorLocked.xpm", &mlx->w, &mlx->h);
	mlx->col = mlx_xpm_file_to_image(mlx->init, "./assets/images/col.xpm", &mlx->w, &mlx->h);
}

void	ft_background(t_map *mp, t_mlx *mlx)
{
	while (mp->map[mlx->y])
	{
		mlx->x = 0;
		while (mp->map[mlx->y][mlx->x])
		{
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->bg, (mlx->x) * 50, (mlx->y ) * 50);
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

void	ft_player_pos(t_map *mp, t_mlx *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	while (mp->map[mlx->y] && mp->map[mlx->y][mlx->x] != 'P')
	{
		mlx->x = 0;
		while (mp->map[mlx->y][mlx->x] && mp->map[mlx->y][mlx->x] != 'P')
		{
			if (mp->map[mlx->y][mlx->x] == 'P')
				break ;
			mlx->x++;
		}
		if (mp->map[mlx->y][mlx->x] == 'P')
			break ;
		mlx->y++;
	}
}

int	ft_key(int keycode, t_mlx *mlx)
{
	if (keycode == UP)
		printf("UP\n");
	else if (keycode == DOWN)
		printf("DOWN\n");
	else if (keycode == RIGHT)
		printf("RIGHT\n");
	else if (keycode == ESC)
		printf("ESC\n");
	mlx->x = mlx->x;
	return (0);
}

void	ft_win_size(t_map *mp, t_mlx *mlx)
{
	mlx->width = mlx->w * mp->width;
	mlx->height = mlx->h * mp->height;
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
		ft_player_pos(mp, mlx);
		mlx_hook(mlx->win, 17, 0, ft_xpress, mlx);
		mlx_key_hook(mlx->win, ft_key, mlx);
		mlx_loop(mlx);
		ft_quit(mp, mlx);
	}
	return (0);
}
