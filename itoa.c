/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:13:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 18:30:32 by plamusse         ###   ########.fr       */
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
