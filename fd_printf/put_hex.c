/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/12 16:27:57 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd_printf.h"

int	put_hex(int fd, unsigned long nb, int upper)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count = put_hex(fd, nb / 16, upper);
	if (upper)
		count += write(fd, &"0123456789ABCDEF"[nb % 16], 1);
	else
		count += write(fd, &"0123456789abcdef"[nb % 16], 1);
	return (count);
}

int	put_pointer(int fd, unsigned long p)
{
	int	count;

	count = 0;
	count += write(fd, "0x", 2);
	if (p == 0)
	{
		count += write(fd, "0", 1);
		return (count);
	}
	else
		count += put_hex(fd, p, 0);
	return (count);
}
