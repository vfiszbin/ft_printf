# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 11:27:08 by vfiszbin          #+#    #+#              #
#    Updated: 2021/12/16 12:08:47 by vfiszbin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c\

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $ $< -o ${<:.c=.o}


${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a $(NAME)
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean: #rm libft.a aussi ?
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re