# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:12:34 by yooshima          #+#    #+#              #
#    Updated: 2024/06/10 17:42:45 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= test.a
MLX_DDYLIB	= libmlx.dylib

SRCS		=ft_split.c libft.c wasd.c read_file.c checkmap.c back_track.c itoa.c ft_queue.c put_error.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f
MLX_PATH	= minilibx_mms

all:		${NAME} ${MLX_DDYLIB}

${NAME}:	${OBJS}
			${MAKE} -C minilibx_mms
			${AR} ${NAME} ${OBJS}

${MLX_DDYLIB}:	minilibx_mms/${MLX_DDYLIB}
				cp $< $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			$(MAKE) -C $(MLX_PATH) clean

fclean:		clean
			${RM} ${NAME} ${MLX_DDYLIB}
			$(MAKE) -C $(MLX_PATH) clean


re:			fclean all

.PHONY:		all clean fclean re bonus
