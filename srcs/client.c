/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:06 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/19 08:30:13 by blevrel          ###   ########.fr       */
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
	if (argc != 3)
		return (ft_printf("Arguments must be the PID and one string to send\n"));
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (ft_printf("PID can't be negative\n"));
	if (argc != 3 || pid == 0 || verify_args(argv[1], pid) == 1)
		return (ft_printf("Arguments must be the PID and one string to send\n"));
	str = argv[2];
	if (str[0] == '\0')
		return (ft_printf("Empty string is not a valid argument\n"));
	size = ft_strlen(str);
	while (i >= 0)
	{
		send_size(pid, size, i);
		i--;
	}
	send_bits(pid, str);
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
