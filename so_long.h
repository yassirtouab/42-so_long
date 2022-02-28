/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:31 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/28 21:46:39 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	size_t	c;
	size_t	p;
	size_t	e;
	size_t	width;
	size_t	height;
	char	*map_file;
	char	*mapl;
	char	**map;
}				t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*bg;
	void	*player;
	void	*exit;
	void	*wall;
	void	*enm;
	int		height;
	int		width;
	int		h;
	int		w;
}				t_mlx;

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_map_extension(t_map *mp, t_mlx *mlx);
void	ft_split(char *str, t_map *mp, t_mlx *mlx);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
void	ft_mp_init(t_map *mp);
void	ft_read(int fd, t_map *mp, t_mlx *mlx);
void	ft_map_valid_char(t_map *mp, t_mlx *mlx);
void	ft_check_rect(t_map *mp, t_mlx *mlx);
void	ft_check_walls(t_map *mp, t_mlx *mlx);
void	ft_map_checker(t_map *mp, t_mlx *mlx);
void	ft_quit(t_map *mp, t_mlx *mlx);
void	ft_error(t_map *mp, t_mlx *mlx);
void	ft_win_size(t_map *mp, t_mlx *mlx);
void	mlx_start(t_mlx *mlx, t_map *mp);

#endif
