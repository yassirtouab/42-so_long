/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/16 12:07:19 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < mlx->mheight)
		printf("%s\n", mlx->map[i++]);
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
		ft_map_start(mlx);
		ft_player_pos(mlx);
		mlx_loop_hook(mlx->init, ft_put_player, mlx);
		mlx_hook(mlx->win, 17, 0, ft_xpress, mlx);
		mlx_key_hook(mlx->win, ft_move, mlx);
		mlx_loop(mlx);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
