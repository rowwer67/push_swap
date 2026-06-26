/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:19:15 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 16:44:59 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	value;
	char	c;

	value = n;
	if (value < 0)
	{
		write(fd, "-", 1);
		value = -value;
	}
	if (value >= 10)
		ft_putnbr_fd((int)(value / 10), fd);
	c = (value % 10) + '0';
	write(fd, &c, 1);
}
