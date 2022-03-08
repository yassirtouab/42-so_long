/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:39:45 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/08 19:13:09 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move(int keycode, t_mlx *mlx)
{
	if (ft_check_movement(keycode, mlx))
	{
		mlx_put_image_to_window(mlx->init,
			mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
		if (keycode == UP)
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->player2, mlx->x * 50, --(mlx->y) * 50);
		else if (keycode == DOWN)
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->player2, mlx->x * 50, ++(mlx->y) * 50);
		else if (keycode == RIGHT)
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->player2, ++(mlx->x) * 50, mlx->y * 50);
		else if (keycode == LEFT)
			mlx_put_image_to_window(mlx->init, mlx->win,
				mlx->player2, --(mlx->x) * 50, mlx->y * 50);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->wall, 0, 0);
		mlx_string_put(mlx->init, mlx->win, 21, 29, 0x0000FF00,
			ft_itoa(mlx->move));
	}
	else if (keycode == ESC)
		ft_end(mlx);
	return (0);
}

void	ft_open_door(t_mlx *mlx)
{
	ft_exit_pos(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->bg, mlx->eposx * 50, mlx->eposy * 50);
	mlx_put_image_to_window(mlx->init, mlx->win,
		mlx->exit, mlx->eposx * 50, mlx->eposy * 50);
}

void	ft_pdead(t_mlx *mlx)
{
	mlx->move++;
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->bg, mlx->x * 50, mlx->y * 50);
	mlx_put_image_to_window(mlx->init,
		mlx->win, mlx->pdead, mlx->x * 50, mlx->y * 50);
	ft_putstr_fd("GAME OVER!\n", 1);
	mlx->end++;
}

int	ft_valid_movement(char *npos, t_mlx *mlx)
{
	mlx->exit = mlx_xpm_file_to_image(mlx->init,
			"./assets/images/DoorOpen.xpm", &mlx->w, &mlx->h);
	if (*npos == '0' || *npos == 'C' || *npos == 'P')
	{
		if (*npos == 'C')
		{
			*npos = '0';
			mlx->c--;
			if (!mlx->c)
				ft_open_door(mlx);
		}
		mlx->move++;
		return (1);
	}
	else if (*npos == 'E' && !mlx->c)
	{
		mlx->move++;
		ft_putstr_fd("YOU WON!\n", 1);
		mlx->end++;
		return (1);
	}
	else if (*npos == 'X' )
		ft_pdead(mlx);
	return (0);
}

int	ft_check_movement(int keycode, t_mlx *mlx)
{
	if (!mlx->end)
	{
		if (keycode == UP)
			return (ft_valid_movement(&mlx->map[mlx->y - 1][mlx->x], mlx));
		else if (keycode == DOWN)
			return (ft_valid_movement(&mlx->map[mlx->y + 1][mlx->x], mlx));
		else if (keycode == RIGHT)
			return (ft_valid_movement(&mlx->map[mlx->y][mlx->x + 1], mlx));
		else if (keycode == LEFT)
			return (ft_valid_movement(&mlx->map[mlx->y][mlx->x - 1], mlx));
	}
	return (0);
}
