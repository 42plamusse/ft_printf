/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:12:21 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/08 20:30:09 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"
#include "libft.h"

int	converter(va_list valist, char *buf, t_size *sz, const char c, t_fwp *fwp)
{
	char	*p;

	if ((p = ft_strchr("dDi", c)) && conv_s(valist, buf, sz, *p, fwp))
		return (1);
	else if ((p = ft_strchr("oOuUxX", c))
			&& conv_us(valist, buf, sz, *p, fwp))
		return (1);
	else if ((p = ft_strchr("sScC", c))
			&& conv_cs(valist, buf, sz, *p, fwp))
		return (1);
	else if (c == 'p' && conv_p(valist, buf, sz, *p, fwp))
		return (1);
	return (0);
}
