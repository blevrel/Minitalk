/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:06 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/10 11:22:07 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	size_t	size;
	int		i;
	int		bit;

	i = 31;
	if (argc != 3)
		return (ft_printf("Arguments must be the PID and a string to send\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (str[0] == '\0')
	{
		ft_printf("Empty string is not a valid argument\n");
		return (1);
	}
	size = ft_strlen(str);
	while (i >= 0)
	{
		bit = 1 & (size >> i);
		if (bit == 0)
			kill(pid, SIGUSR1);
		if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(1);
		i--;
	}
	send_bits(pid, str);
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
			usleep(100);
			byte--;
		}
	i++;
	}
}
