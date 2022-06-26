# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:48:57 by blevrel           #+#    #+#              #
#    Updated: 2022/06/19 08:31:01 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLIENT = client

NAMESERV = server

NAMECLIENTBON = clientbon

NAMESERVBON = serverbon

SRCSCLIENT =	srcs/client.c srcs/verify_args.c

SRCSCLIENTBON =	srcs/client_bonus.c srcs/verify_args_bonus.c

SRCSSERV = 	srcs/server.c

SRCSSERVBON = 	srcs/server_bonus.c srcs/confirm_signal_bonus.c

OBJSCLIENT = ${SRCSCLIENT:.c=.o}

OBJSCLIENTBON = ${SRCSCLIENTBON:.c=.o}

OBJSSERV = ${SRCSSERV:.c=.o}

OBJSSERVBON = ${SRCSSERVBON:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

HEAD = -I libft -I includes

RM = rm -f

all: ${NAMECLIENT} ${NAMESERV}

bonus: ${NAMECLIENTBON} ${NAMESERVBON}
	
clean:
	make clean -C libft
	${RM} ${OBJSCLIENT} ${OBJSSERV} ${OBJSCLIENTBON} ${OBJSSERVBON}

fclean: clean
	make fclean -C libft
	${RM} ${NAMESERV} ${NAMECLIENT} ${NAMESERVBON} ${NAMECLIENTBON}

re: fclean all

.c.o:
	${CC} ${FLAGS} -c ${HEAD} $< -o ${<:.c=.o}

${NAMECLIENT}: ${OBJSCLIENT}
	make -C libft
	${CC} ${FLAGS} ${OBJSCLIENT} ${HEAD} ${LIB} -o ${NAMECLIENT}

${NAMECLIENTBON}: ${OBJSCLIENTBON}
	make -C libft
	${CC} ${FLAGS} ${OBJSCLIENTBON} ${HEAD} ${LIB} -o ${NAMECLIENT}

${NAMESERV}: ${OBJSSERV}
	${CC} ${FLAGS} ${OBJSSERV} ${HEAD} ${LIB} -o ${NAMESERV}

${NAMESERVBON}: ${OBJSSERVBON}
	${CC} ${FLAGS} ${OBJSSERVBON} ${HEAD} ${LIB} -o ${NAMESERV}

.PHONY: bonus re clean fclean all
