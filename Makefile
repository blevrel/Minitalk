# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:48:57 by blevrel           #+#    #+#              #
#    Updated: 2022/06/07 18:11:27 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMESERV = server

NAMECLIENT = client

SRCSCLIENT =	srcs/client.c

SRCSSERV = 		srcs/server.c

OBJSCLIENT = ${SRCSCLIENT:.c=.o}

OBJSSERV = ${SRCSSERV:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

HEAD = -I libft -I includes

RM = rm -f

all: ${NAMECLIENT} ${NAMESERV}

clean:
	make clean -C libft
	${RM} ${OBJSCLIENT} ${OBJSSERV}

fclean: clean
	make fclean -C libft
	${RM} ${NAMESERV} ${NAMECLIENT}

re: fclean all

.c.o:
	${CC} -c ${HEAD} $< -o ${<:.c=.o}

${NAMECLIENT}: ${OBJSCLIENT}
	make -C libft
	${CC} ${OBJSCLIENT} ${HEAD} ${LIB} -o ${NAMECLIENT} -g

${NAMESERV}: ${OBJSSERV}
	${CC} ${OBJSSERV} ${HEAD} ${LIB} -o ${NAMESERV} -g
