/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:07:31 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/24 15:34:54 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<fcntl.h>
# include "mlx/mlx.h"

typedef struct s_info
{
	void	*i;
}	t_info;

typedef struct s_map
{
	size_t	col;
	size_t	enm;
	size_t	w;
	size_t	l;
}	t_map;

size_t	ft_strlen(const char *str);
int		ft_map_extension(char *arg);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(int fd);

#endif
