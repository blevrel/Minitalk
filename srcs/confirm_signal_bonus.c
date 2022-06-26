/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:44:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/12 11:26:11 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	get_pid(int signal)
{
	static int	client_pid = 0;

	if (signal == SIGUSR1)
	{
		client_pid = client_pid << 1;
		client_pid = client_pid | 0;
	}
	else if (signal == SIGUSR2)
	{
		client_pid = client_pid << 1;
		client_pid = client_pid | 1;
	}
	return (client_pid);
}

void	send_signal_and_reset(int *i, int *size, int *pid, int *trigger)
{
	kill(*pid, SIGUSR2);
	*i = 0;
	*size = 0;
	*pid = 0;
	*trigger = 0;
}
