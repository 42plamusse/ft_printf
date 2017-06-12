/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:56:35 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/11 22:26:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		idt_normlc(char arg, t_size *sz, char *buf)
{
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
}
