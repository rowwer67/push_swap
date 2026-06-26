/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:16:52 by abrezden          #+#    #+#             */
/*   Updated: 2026/05/11 15:05:01 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}

/*int main()
{
	ft_putstr_fd("Hello 42\n", 1);

	ft_putstr_fd("", 1);

	ft_putstr_fd(NULL, 1);
	return (0);
}*/