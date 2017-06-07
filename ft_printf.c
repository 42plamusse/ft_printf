/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/07 21:29:42 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		parser(va_list valist, const char *format, char *buf, t_size *sz)
{
//	char		*p;
	int			i;

	i = 1;
	if (format[i] == '%' && (buf[sz->no++] = '%') && i++)
		return (i);
//	while (format[i] && (p = ft_strchr("#0-+", format[i++])))
//		flags_fid(*p, fid);
//	while (format[i] && ft_isdigit(format[i++]))
//		width_fid(*p, fid);
//	if (format[i] && format[i] == '.')
//		prec_fid(format[i++], fid);
//	while (format[i] && ft_isdigit(format[i++]))
//		prec_fid(*p, fid);
//	while (format[i] && (p = ft_strchr("hljz", format[i++])))
//		cflag_fid(*p, fid);
//	if (format[i] && (p = ft_strchr("sSpdDioOuUxXcC", format[i++])))
//	{
//		conv_indent(*p, fid, &oplen);
//		setz_fid(fid);
//		return (i);
//	}
	else
	{
		va_arg(valist, int);
		return (1);
	}
}


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
