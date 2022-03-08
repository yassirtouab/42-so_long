/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:37:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/08 20:08:16 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_enemy_left(t_mlx *mlx)
{
	int				x;
	int				y;
	static size_t	time;

	y = 0;
	if (time == 100)
	{
		while (mlx->map[y])
		{
			x = 0;
			while (mlx->map[y][x])
			{
				if (mlx->map[y][x] == 'X' && mlx->map[y][x - 1] == '0')
				{
					mlx->map[y][x] = '0';
					mlx->map[y][x - 1] = 'X';
					mlx_put_image_to_window(mlx->init,
						mlx->win, mlx->bg, x * 50, y * 50);
					mlx_put_image_to_window(mlx->init,
						mlx->win, mlx->enm, (x - 1) * 50, y * 50);
					return (0);

				}
				x++;
			}
			y++;
		}
		time = 0;
	}
	time++;
	return (0);

}

int	ft_enemy_right(t_mlx *mlx)
{
	int			x;
	int			y;
	static size_t	time;

	y = 0;
	if (time == 100)
	{
		while (mlx->map[y] && !mlx->end)
		{
			x = 0;
			while (mlx->map[y][x] && !mlx->end)
			{
				 if (mlx->map[y][x] == 'X' && ((mlx->map[y][x + 1] == '0') || (mlx->y == y && mlx->x == x)))
				{
					if (mlx->y == y && mlx->x == x)
					{
						ft_pdead(mlx);
						return (0);
					}
					mlx->map[y][x + 1] = 'X';
					mlx->map[y][x] = '0';
					mlx_put_image_to_window(mlx->init,
						mlx->win, mlx->bg, x * 50, y * 50);
					mlx_put_image_to_window(mlx->init,
						mlx->win, mlx->enm, (x + 1) * 50, y * 50);
						break ;
				}
				x++;
			}
			y++;
		}
		time = 0;
	}
	time++;
	return (0);
}
