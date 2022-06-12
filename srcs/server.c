/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:11:20 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/12 11:26:23 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	catch_signal(int signal)
{
	static int	i = 0;
	static int	size = 0;
	static int	pid = 0;
	static int	trigger = 0;

	if (i < 32 && trigger == 0)
	{
		pid = get_pid(signal);
		i++;
		if (i == 32)
		{
			i = 0;
			trigger = 1;
		}
	}
	else if (i < 32)
		size = fill_size(signal, size, &i);
	else if ((i - 32) < (size * 8))
	{
		fill_char(signal, size);
		i++;
		if ((i - 32) == (size * 8))
			send_signal_and_reset(&i, &size, &pid, &trigger);
	}
}

int	fill_size(int signal, int size, int *i)
{
	(*i)++;
	if (signal == SIGUSR1)
	{
		size = size << 1;
		size = size | 0;
	}
	else if (signal == SIGUSR2)
	{
		size = size << 1;
		size = size | 1;
	}
	return (size);
}

void	fill_char(int signal, int size)
{
	static char	c = '\0';
	static int	i = 0;

	if (i < 8)
	{
		if (signal == SIGUSR1)
		{
			c = c << 1;
			c = c | 0;
		}
		else if (signal == SIGUSR2)
		{
			c = c << 1;
			c = c | 1;
		}
		i++;
	}
	if (i == 8)
	{
		fill_str(c, size);
		i = 0;
		c = '\0';
		return ;
	}
}

void	fill_str(char c, int size)
{
	static int	i = 0;
	static char	*str = NULL;

	if (!str)
		str = ft_calloc(sizeof(char), size + 1);
	if (i < size)
	{		
		str[i] = c;
		i++;
	}
	if (i == size)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		i = 0;
	}
}

int	main(void)
{
	ft_printf ("\033[0;32mPID : %d\033[0m\n", getpid());
	signal(SIGUSR1, catch_signal);
	signal(SIGUSR2, catch_signal);
	while (1)
		continue ;
	return (0);
}
