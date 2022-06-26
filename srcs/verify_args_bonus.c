/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:40:32 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/13 09:00:30 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	verify_args(char *str, int pid)
{
	size_t	size;
	int		size_nb;
	size_t	i;

	size_nb = 0;
	i = 0;
	size = ft_strlen(str);
	while (pid > 0)
	{
		size_nb = pid / 10;
		pid = size_nb;
		i++;
	}
	if (size != i)
		return (1);
	return (0);
}
