/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/11 22:05:29 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_enemy(t_mlx *mlx)
{
	int				x;
	int				y;
	static size_t	time;
	static int		sw;

	y = 0;
	if (time == 10)
	{
		while (mlx->map[y])
		{
			x = 0;
			while (mlx->map[y][x])
			{
				ft_enemy_cond(mlx, &x, &y, &sw);
				x++;
			}
			y++;
		}
		time = 0;
	}
	time++;
	return (0);
}

void	ft_enemy_cond(t_mlx *mlx, int *x, int *y, int *sw)
{
	if (mlx->map[*y][*x] == 'X' && ((mlx->map[*y][*x - 1] == '0')
		|| (mlx->map[*y][*x - 1] == 'P')) && !*sw)
	{
		*sw = 0;
		ft_enemy_left(mlx, &*x, &*y);
		if (mlx->map[*y][*x - 1] == '1' || mlx->map[*y][*x - 1] == 'C')
			*sw = 1;
	}
	if (mlx->map[*y][*x] == 'X' && ((mlx->map[*y][*x + 1] == '0')
		|| (mlx->map[*y][*x + 1] == 'P')))
	{
		*sw = 1;
		ft_enemy_right(mlx, &*x, &*y);
		if (mlx->map[*y][*x + 1] == '1' || mlx->map[*y][*x + 1] == 'C')
			*sw = 0;
	}
}

int	ft_enemy_left(t_mlx *mlx, int *x, int *y)
{
	if (mlx->map[*y][*x - 1] == 'P')
	{
		ft_pdead(mlx);
		ft_hold_end(mlx);
		return (1);
	}
	mlx->map[*y][*x] = '0';
	mlx->map[*y][*x - 1] = 'X';
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->bg, *x * 50, *y * 50);
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->enm, (*x - 1) * 50, *y * 50);
	return (1);
}

int	ft_enemy_right(t_mlx *mlx, int *x, int *y)
{
	if (mlx->map[*y][*x + 1] == 'P')
	{
		ft_pdead(mlx);
		ft_hold_end(mlx);
		return (1);
	}
	mlx->map[*y][*x] = '0';
	mlx->map[*y][*x + 1] = 'X';
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->bg, *x * 50, *y * 50);
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->enm, (*x + 1) * 50, *y * 50);
	*x = *x + 1;
	return (1);
}
