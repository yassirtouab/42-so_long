/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:31 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/11 22:04:30 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# define ESC 53
# define DOWN 1
# define UP 13
# define RIGHT 2
# define LEFT 0

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
	void	*player2;
	void	*pdead;
	void	*exitc;
	void	*exit;
	void	*wall;
	void	*col;
	void	*enm;
	int		height;
	int		width;
	int		h;
	int		w;
	int		x;
	int		y;
	int		eposx;
	int		eposy;
	int		end;
	char	**map;
	size_t	c;
	size_t	mwidth;
	size_t	mheight;
	size_t	move;
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
void	ft_background(t_mlx *mlx);
void	ft_map_start(t_mlx *mlx);
int		ft_put_player(t_mlx *mlx);
void	ft_player_pos(t_mlx *mlx);
int		ft_move(int keycode, t_mlx *mlx);
int		ft_valid_movement(char *npos, t_mlx *mlx);
int		ft_check_movement(int keycode, t_mlx *mlx);
void	ft_pass_map(t_map *mp, t_mlx *mlx);
void	ft_free_mp(t_map *mp);
void	ft_end(t_mlx *mlx);
int		ft_hold_end(t_mlx *mlx);
char	*ft_itoa(int n);
void	ft_open_door(t_mlx *mlx);
void	ft_pdead(t_mlx *mlx);
void	ft_map_content(t_mlx *mlx);
int		ft_xpress(t_mlx *mlx);
void	ft_exit_pos(t_mlx *mlx);
int		ft_enemy_left(t_mlx *mlx, int *x, int *y);
int		ft_enemy_right(t_mlx *mlx, int *x, int *y);
int		ft_enemy(t_mlx *mlx);
void	ft_enemy_cond(t_mlx *mlx, int *x, int *y, int *sw);
void	ft_check_map(t_mlx *mlx);

#endif
