/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:13:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 19:11:50 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*itoa_deci(size_t arg, int len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (len)
	{
		ret[--len] = arg % 10 + '0';
		arg /= 10;
	}
	return (ret);
}

char		*itoa_octa(size_t arg, int len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (len)
	{
		ret[--len] = arg % 8 + '0';
		arg /= 8;
	}
	return (ret);
}

int			get_hex(int nb, int cap)
{
	int		ret;

	if (!cap)
		ret = 49;
	else
		ret = 17;
	if (nb == 10)
		return (ret+= 0);
	else if (nb == 11)
		return (ret+= 1);
	else if (nb == 12)
		return (ret+= 2);
	else if (nb == 13)
		return (ret+= 3);
	else if (nb == 14)
		return (ret+= 4);
	else if (nb == 15)
		return (ret+= 5);
	else
		return (nb);
}

char		*itoa_hexa(size_t arg, int len)
{
	char	*ret;
	int		cap;

	cap = 0;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (len)
	{
		ret[--len] = get_hex((arg % 16), cap) + '0';
		arg /= 16;
	}
	return (ret);
}

char		*itoa_cap_hexa(size_t arg, int len)
{
	char	*ret;
	int		cap;

	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	cap = 1;
	while (len)
	{
		ret[--len] = get_hex((arg % 16), cap) + '0';
		arg /= 16;
	}
	return (ret);
}
