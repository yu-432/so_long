/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:28 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/12 16:29:53 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_PRINTF_H
# define FT_FD_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_fd_printf(int fd, const char *format, ...);
int		if_per(int fd, const char *start, va_list ap, int count);
int		put_hex(int fd, unsigned long nb, int upper);
int		put_pointer(int fd, unsigned long p);
int		put_str(int fd, char *s);
int		put_c(int fd, int c);
int		put_unsign_int(int fd, unsigned int nb);
int		put_nbr(int fd, int n);
#endif