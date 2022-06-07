# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:48:57 by blevrel           #+#    #+#              #
#    Updated: 2022/06/07 13:49:23 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minitalk

SRCS =	

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

HEAD = -I libft -I includes

RM = rm -f

all: ${NAME}

clean:
	make clean -C libft
${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.c.o:
	${CC} ${FLAGS} -c ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	${CC} ${FLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME} -g
