/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:56:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/12 12:00:32 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

//client.c
void	send_bits(int pid, char *str);
void	send_size(int pid, int size, int i);
void	catch_signal_client(int signal);
void	send_client_pid(int server_pid);

//confirm_signal.c
void	send_signal_and_reset(int *i, int *size, int *pid, int *trigger);
int		get_pid(int signal);

//server.c
void	catch_signal(int signal);
void	fill_char(int signal, int size);
void	fill_str(char c, int size);
int		fill_size(int signal, int size, int *i);

//verify_args.c
int		verify_args(char *str, int pid);

#endif
