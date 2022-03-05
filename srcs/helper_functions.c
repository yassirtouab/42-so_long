/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 03:42:57 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/05 18:34:31 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_win_size(t_map *mp, t_mlx *mlx)
{
	mlx->h = 50;
	mlx->w = 50;
	mlx->width = 0;
	mlx->height = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->width = mlx->w * mp->width;
	mlx->height = mlx->h * mp->height;
}

void	mlx_start(t_mlx *mlx, t_map *mp)
{
	ft_win_size(mp, mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->height, "SO_LONG");
	mlx->bg = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/bg.xpm", &mlx->w, &mlx->h);
	mlx->player = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/player2nd.xpm", &mlx->w, &mlx->h);
	mlx->player2 = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/player.xpm", &mlx->w, &mlx->h);
	mlx->enm = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/saw.xpm", &mlx->w, &mlx->h);
	mlx->wall = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/box.xpm", &mlx->w, &mlx->h);
	mlx->exit = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/DoorOpen.xpm", &mlx->w, &mlx->h);
	mlx->exitc = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/DoorLocked.xpm", &mlx->w, &mlx->h);
	mlx->col = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/col.xpm", &mlx->w, &mlx->h);
	mlx->pdead = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/dead.xpm", &mlx->w, &mlx->h);
	ft_pass_map(mp, mlx);
}

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
