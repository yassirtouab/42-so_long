/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:50:49 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/08 16:58:34 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit_pos(t_mlx *mlx)
{
	mlx->eposy = 0;
	mlx->eposx = 0;
	while (mlx->map[mlx->eposy] && mlx->map[mlx->eposy][mlx->eposx] != 'E')
	{
		mlx->eposx = 0;
		while (mlx->map[mlx->eposy][mlx->eposx]
			&& mlx->map[mlx->eposy][mlx->eposx] != 'E')
		{
			if (mlx->map[mlx->eposy][mlx->eposx] == 'E')
				break ;
			mlx->eposx++;
		}
		if (mlx->map[mlx->eposy][mlx->eposx] == 'E')
			break ;
		mlx->eposy++;
	}
}

int	ft_hold_end(t_mlx *mlx)
{
	if (mlx->end)
	{
		if (mlx->map[mlx->y][mlx->x] == 'E' && mlx->end == 5000)
			mlx_put_image_to_window(mlx->init,
				mlx->win, mlx->exit, mlx->x * 50, mlx->y * 50);
		if (mlx->end == 15000)
			ft_end(mlx);
		mlx->end++;
	}
	return (0);
}

int	ft_xpress(t_mlx *mlx)
{
	ft_end(mlx);
	return (0);
}
