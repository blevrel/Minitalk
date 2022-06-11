/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:56:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/11 16:03:05 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	catch_signal(int signal);
void	send_bits(int pid, char *str);
void	fill_char(int signal, int size);
void	fill_str(char c, int size);
void	send_size(int pid, int size, int i);
void	catch_signal_client(int signal);
void	send_client_pid(int server_pid);
int		fill_size(int signal, int size);
int		get_pid(int signal);
void	send_confirmation(int pid);
