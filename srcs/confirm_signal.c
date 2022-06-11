/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:44:25 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/11 16:07:23 by blevrel          ###   ########.fr       */
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
