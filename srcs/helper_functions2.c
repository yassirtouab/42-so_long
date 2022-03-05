/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:50:56 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/05 13:19:55 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_mp(t_map *mp)
{
	size_t	i;

	i = 0;
	free(mp->mapl);
	free(mp->map_file);
	while (i < mp->height)
		free(mp->map[i++]);
	free(mp->map);
	free(mp);
}

void	ft_pass_map(t_map *mp, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	mlx->map = (char **)malloc((mlx->height) * sizeof(char *));
	while (i < mp->height)
	{
		mlx->map[i] = ft_strdup(mp->map[i]);
		i++;
	}
	mlx->c = mp->c;
	mlx->mheight = mp->height;
	mlx->mwidth = mp->width;
	ft_free_mp(mp);
}

void	ft_end(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < mlx->mheight)
		free(mlx->map[i++]);
	free(mlx->map);
	free(mlx);
	exit(0);
}
