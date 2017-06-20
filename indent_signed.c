/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 10:48:57 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 12:58:00 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_leftsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;

	if (((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne)))
		putsign(sz, fwp, buf);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_deci(ft_abs(arg), df->al);
	i = 0;
	while (stock[i])
	{
		if (sz->no < BS)
			buf[sz->no++] = stock[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	free(stock);
	fill_sp(buf, sz, df->wl);
}

void		idt_zerosi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_sp(buf, sz, df->wl);
	if (((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne)))
		putsign(sz, fwp, buf);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	else
		fill_ze(buf, sz, df->wl);
	stock = itoa_deci(ft_abs(arg), df->al);
	i = 0;
	while (stock[i])
	{
		if (sz->no < BS)
			buf[sz->no++] = stock[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	free(stock);
}

void		idt_rightsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;

	fill_sp(buf, sz, df->wl);
	if (((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne)))
		putsign(sz, fwp, buf);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_deci(ft_abs(arg), df->al);
	i = 0;
	while (stock[i])
	{
		if (sz->no < BS)
			buf[sz->no++] = stock[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	free(stock);
}

void		idt_normlsi(ssize_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;

	if (((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne)))
		putsign(sz, fwp, buf);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_deci(ft_abs(arg), df->al);
	i = 0;
	while (stock[i])
	{
		if (sz->no < BS)
			buf[sz->no++] = stock[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	free(stock);
}
