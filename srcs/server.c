/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:20 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/07 17:52:15 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	catch_signal(int signal)
{
	if (signal == SIGUSR1)
		write (1, "usr1\n", 5);
	if (signal == SIGUSR2)
		write (1, "usr2\n", 5);
}

int	main()
{
	ft_printf("%d\n", getpid());
	if ((signal(SIGUSR1, catch_signal) == SIG_ERR)
			|| signal(SIGUSR2, catch_signal) == SIG_ERR)
		write(1, "error\n", 6);
	while (1)
		continue ;
	return (0);
}
