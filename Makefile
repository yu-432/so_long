# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:12:34 by yooshima          #+#    #+#              #
#    Updated: 2024/06/15 12:36:31 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= so_long
AR_FILE		= main.a

SRCS		= $(wildcard src/*.c)

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		=  -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f
MLX_PATH	= minilibx_mms
PRINTF_PATH	= ft_fd_printf

all:		 ${NAME}

${NAME}:	${OBJS}
			${MAKE} -C $(MLX_PATH)
			${MAKE} -C $(PRINTF_PATH)
			${AR} ${AR_FILE} ${OBJS}
			cp ${MLX_PATH}/libmlx.dylib .
			$(CC) $(CFLAGS) ${AR_FILE} ${PRINTF_PATH}/ft_fd_printf.a ${MLX_PATH}/libmlx.dylib -o ${NAME}
			${RM} ${AR_FILE}

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			$(MAKE) -C $(MLX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) clean

fclean:		clean
			${RM} ${NAME} libmlx.dylib
			$(MAKE) -C $(MLX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
