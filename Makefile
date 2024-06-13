# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:12:34 by yooshima          #+#    #+#              #
#    Updated: 2024/06/13 13:00:29 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= test.a
MLX_DDYLIB	= libmlx.dylib

SRCS		= main.c read.c queue.c mapping.c checkmap.c back_track.c keyhook.c ft_split.c ft_libft.c ft_itoa.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		=  -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f
MLX_PATH	= minilibx_mms
PRINTF_PATH	= ft_fd_printf

all:		${NAME} $(MLX_DDYLIB)

${NAME}:	${OBJS}
			${MAKE} -C $(MLX_PATH)
			${MAKE} -C $(PRINTF_PATH)
			cp $(PRINTF_PATH)/ft_fd_printf.a ${NAME}
			${AR} ${NAME} ${OBJS}

${MLX_DDYLIB}:	$(MLX_PATH)/$(MLX_DDYLIB)
				cp $< $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			$(MAKE) -C $(MLX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) clean

fclean:		clean
			${RM} ${NAME} $(MLX_DDYLIB)
			$(MAKE) -C $(MLX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
