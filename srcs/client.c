/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:06 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/12 11:43:28 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	size_t	size;
	int		i;

	i = 31;
	pid = ft_atoi(argv[1]);
	if (argc != 3 || pid == 0 || verify_args(argv[1], pid) == 1)
		return (ft_printf("Arguments must be the PID and one string to send\n"));
	str = argv[2];
	if (str[0] == '\0')
		return (ft_printf("Empty string is not a valid argument\n"));
	signal(SIGUSR2, catch_signal_client);
	size = ft_strlen(str);
	send_client_pid(pid);
	while (i >= 0)
	{
		send_size(pid, size, i);
		i--;
	}
	send_bits(pid, str);
	while (1)
		continue ;
}

void	send_size(int pid, int size, int i)
{
	int	bit;

	bit = 1 & (size >> i);
	if (bit == 0)
		kill(pid, SIGUSR1);
	if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(50);
}

void	catch_signal_client(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Bien reçu !\n");
		exit (1);
	}
}

void	send_client_pid(int server_pid)
{
	int	client_pid;
	int	bit;
	int	i;

	i = 31;
	client_pid = getpid();
	while (i >= 0)
	{
		bit = 1 & (client_pid >> i);
		if (bit == 0)
			kill(server_pid, SIGUSR1);
		if (bit == 1)
			kill(server_pid, SIGUSR2);
		usleep(50);
		i--;
	}	
}

void	send_bits(int pid, char *str)
{
	int	i;
	int	byte;
	int	bit;

	i = 0;
	while (str[i])
	{
		byte = 7;
		while (byte >= 0)
		{
			bit = 1 & (str[i] >> byte);
			if (bit == 0)
				kill(pid, SIGUSR1);
			if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(50);
			byte--;
		}
		i++;
	}
}
