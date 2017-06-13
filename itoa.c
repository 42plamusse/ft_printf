/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:13:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 17:14:14 by plamusse         ###   ########.fr       */
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
