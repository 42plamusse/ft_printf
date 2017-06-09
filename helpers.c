/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:57:05 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/09 16:27:21 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_size(t_size *sz)
{
	sz->no = 0;
	sz->op = 0;
	sz->uc = 0;
}


char	*ft_strchr(const char *s, int c)
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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
