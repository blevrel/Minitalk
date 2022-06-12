/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:40:32 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/12 11:51:11 by blevrel          ###   ########.fr       */
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
	ft_printf("%d\n", size);
	while (pid > 0)
	{
		size_nb = pid / 10;
		pid = size_nb;
		i++;
		ft_printf("%d\n", i);
	}
	if (size != i)
		return (1);
	return (0);
}
