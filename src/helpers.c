/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:57:05 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:22:46 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	char	a;
	char	*tmp;
	size_t	i;

	a = (char)c;
	tmp = (char*)s;
	i = 0;
	while (tmp[i] && tmp[i] != a)
		i++;
	if (tmp[i] == a)
		return (&tmp[i]);
	return (0);
}

ssize_t		ft_abs(ssize_t n)
{
	return ((n < 0) ? -n : n);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
