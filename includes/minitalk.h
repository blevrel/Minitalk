/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:56:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/10 09:46:25 by blevrel          ###   ########.fr       */
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
