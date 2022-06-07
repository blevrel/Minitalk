/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:06 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/07 18:05:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Arguments must be the PID and a string to send\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	kill(pid, SIGUSR1);
}
