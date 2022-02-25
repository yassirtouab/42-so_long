/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/24 15:35:55 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_extension(char *arg)
{
	size_t	i;

	i = 0;
	if (arg[0] == '.' || ft_strlen(arg) < 5)
		return (0);
	while (arg[i])
		i++;
	if (arg[i] != 'r' && arg[i - 1] != 'e'
		&& arg[i - 2] != 'b' && arg[i - 3] != '.')
		return (1);
	return (0);
}

char	*ft_read(int fd)
{
	char buffer[2];
	char	*mapline;
	int	rd;

	rd = 1;
	mapline = malloc(1);
	mapline[0] = 0;
	buffer[1] = 0;
	while (rd == 1)
	{
		rd = read(fd, &buffer[0], 1);
		mapline = ft_strjoin(mapline, buffer);
	}
	return (mapline);
}

int	main(int ac, char **av)
{
	t_info	*st;
	// void	*mlx;
	// void	*mlx_win;
	// void	*player;
	// int		w ;
	int		h;

	// h = 0;
	if (ac > 1)
		h = ft_map_extension(av[1]);
	int fd = open("map.ber", O_RDONLY);
	char *mapline = ft_read(fd);
	close(fd);

	printf("%d\n", h);
	printf("%s\n", mapline);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "SO_LONG");
	// player = mlx_xpm_file_to_image(mlx, "./assets/box.xpm", &w, &h);
	// mlx_put_image_to_window(mlx, mlx_win, player, 150, 150);
	// mlx_loop(mlx);
	return (0);
}
