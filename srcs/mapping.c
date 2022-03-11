/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:46:37 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/12 00:45:54 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_background(t_mlx *mlx)
{
	while (mlx->map[mlx->y])
	{
		mlx->x = 0;
		while (mlx->map[mlx->y][mlx->x])
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
	static size_t	i;

	if (!mlx->end)
	{
		if (i < 20)
		{
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->bg, mlx->x * 50, mlx->y * 50);
			mlx_put_image_to_window(mlx->init,
				mlx->win, mlx->player2, mlx->x * 50, mlx->y * 50);
		}
		else
		{
			mlx_put_image_to_window(mlx->init,
				mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->player, mlx->x * 50, mlx->y * 50);
		}
		if (++i == 40)
			i = 0;
		ft_enemy(mlx);
	}
	else
		ft_hold_end(mlx);
	return (0);
}

void	ft_map_start(t_mlx *mlx)
{
	ft_background(mlx);
	mlx->y = 0;
	while (mlx->map[mlx->y])
	{
		mlx->x = 0;
		while (mlx->map[mlx->y][mlx->x])
			ft_map_content(mlx);
		mlx->y++;
	}
}

void	ft_map_content(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x] == '1')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->wall, mlx->x * 50, mlx->y * 50);
	else if (mlx->map[mlx->y][mlx->x] == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->col, mlx->x * 50, mlx->y * 50);
	else if (mlx->map[mlx->y][mlx->x] == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->exitc, mlx->x * 50, mlx->y * 50);
	else if (mlx->map[mlx->y][mlx->x] == 'X')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->enm, mlx->x * 50, mlx->y * 50);
	else if (mlx->map[mlx->y][mlx->x] == 'P')
		mlx_put_image_to_window(mlx->init, mlx->win,
			mlx->player2, mlx->x * 50, mlx->y * 50);
	mlx->x++;
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
