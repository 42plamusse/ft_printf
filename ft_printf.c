/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 15:22:46 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		valist;
	char		buf[BS];
	t_size		sz;
	static int	error = 0;

	va_start(valist, format);
	init_size(&sz);
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
	if ((sz.er == -1 || error == -1) && (error = -1))
		return (error);
	return (sz.op);
}
