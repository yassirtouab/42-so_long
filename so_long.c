/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/26 12:44:28 by ytouab           ###   ########.fr       */
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

void	ft_quit(t_map *mp)
{
	size_t	i;

	i = 0;
	free(mp->mapl);
	free(mp->map_file);
	while (i < mp->height)
		free(mp->map[i++]);
	free(mp->map);
	free(mp);
	exit(0);
}

void	ft_error(t_map *mp)
{
		ft_putstr_fd("Error\n", 2);
		ft_quit(mp);
}

int	main(int ac, char **av)
{
	t_map	*mp;
	// void	*mlx;
	// void	*mlx_win;
	// void	*player;
	// int		w ;
	if (ac == 2)
	{
	mp = malloc(sizeof(t_map));
	ft_mp_init(mp);
	int		h;

	h = 0;
	mp->map_file = ft_strdup(av[1]);
	ft_map_checker(mp);
	// printf("valid charachters: %d\n", ft_map_valid_char(mp));
	//  printf("map extension: %d\n", ft_map_extension(mp->map_file));
	// printf("%s\n", mp->mapl);

	// printf("%s\n", mp->map[0]);
	// printf("%s\n", mp->map[1]);
	// printf("%s\n", mp->map[2]);
	// printf("%s\n", mp->map[3]);
	// printf("%s\n", mp->map[4]);
	// printf("%s\n", mp->map[5]);

	// printf("height: %zu\n", mp->height);
	// printf("rectangular check: %d\n", ft_check_rect(mp));
	// printf("walls check: %d\n", ft_check_walls(mp));
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "SO_LONG");
	// player = mlx_xpm_file_to_image(mlx, "./assets/box.xpm", &w, &h);
	// mlx_put_image_to_window(mlx, mlx_win, player, 150, 150);
	// mlx_loop(mlx);
	ft_quit(mp);
	}
	return (0);
}
