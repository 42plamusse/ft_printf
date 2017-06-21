/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:56:35 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/21 16:28:25 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fillbuffer(unsigned char c, t_size *sz, char *buf)
{
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = c;
}

void		putwchar(wchar_t arg, t_size *sz, char *buf)
{
	int		o2
	if (!(arg >> 7))
		fillbuffer(arg, sz, buf);
	else if (!(arg >> 11))
	{
	}
	else if (!(arg >> 16))
	{
	}
	else
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
}

void		idt_leftc(char arg, t_size *sz, t_fwp *fwp, char *buf)
{
	int		nsp;

	nsp = fwp->wi - 1;
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
	fill_sp(buf, sz, nsp);
}

void		idt_zeroc(char arg, t_size *sz, t_fwp *fwp, char *buf)
{
	int		nsp;

	nsp = fwp->wi - 1;
	fill_ze(buf, sz, nsp);
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
}

void		idt_rightc(char arg, t_size *sz, t_fwp *fwp, char *buf)
{
	int		nsp;

	nsp = fwp->wi - 1;
	fill_sp(buf, sz, nsp);
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
}
