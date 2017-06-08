/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/08 13:43:09 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		valist;
	char		buf[BS];
	t_size		sz;

	va_start(valist, format);
	sz.no = 0;
	sz.op = 0;
	while (*format)
	{
		if (*format != '%' && sz.no < BS)
			buf[sz.no++] = *format++;
		else if (sz.no >= BS && (sz.op += sz.no) && !(sz.no = 0))
			write(1, buf, BS);
		else
			format += parser(valist, format, buf, &sz);
	}
	va_end(valist);
	if (write(1, buf, sz.no))
		sz.op += sz.no;
	return (sz.op);
}
