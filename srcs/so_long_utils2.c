/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 02:04:27 by ytouab            #+#    #+#             */
/*   Updated: 2022/03/08 15:16:04 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
		write(fd, &s[i++], 1);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = ft_strlen(str);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static size_t	ft_countint(int n, size_t len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static size_t	ft_check_neg(int n)
{
	if (n > 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_check_neg(n);
	if (nb < 0)
		nb = -nb;
	len = ft_countint(n, len);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (!len && !str[1])
		str[len] = '0';
	else if (!len && str[1])
		str[len] = '-';
	return (str);
}
