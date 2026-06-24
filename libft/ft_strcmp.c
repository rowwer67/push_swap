/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:35:42 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/24 14:13:32 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
size_t	ft_strlen(const char *str);

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s2))
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

