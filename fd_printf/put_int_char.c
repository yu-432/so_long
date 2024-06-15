/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:48:58 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/12 16:28:04 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

size_t	f_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	put_c(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	put_str(int fd, char *s)
{
	int	len;

	if (!s)
		len = write(fd, "(null)", 6);
	else
	{
		len = f_strlen(s);
		write(fd, s, len);
	}
	return (len);
}

int	put_unsign_int(int fd, unsigned int nb)
{
	char	a;
	int		i;

	i = 0;
	if (nb >= 10)
		i += put_unsign_int(fd, nb / 10);
	a = (nb % 10) + '0';
	i += write (fd, &a, 1);
	return (i);
}

int	put_nbr(int fd, int n)
{
	char	a;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(fd, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i += write(fd, "-", 1);
	}
	if (n >= 10)
	{
		i += put_nbr(fd, n / 10);
	}
	a = (n % 10) + '0';
	i += write (fd, &a, 1);
	return (i);
}
