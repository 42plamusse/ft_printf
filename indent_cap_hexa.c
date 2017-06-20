/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_cap_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:45:20 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/14 12:28:36 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_left_cap_hx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if (arg && (fwp->fi & fl_ha) && (cap = 1))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(arg, df->al);
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

void		idt_zero_cap_hx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if (df->pl)
	{
		fill_sp(buf, sz, df->wl);
		if (arg && (fwp->fi & fl_ha) && (cap = 1))
			put_hex_prfx(buf, sz, cap);
		fill_ze(buf, sz, df->pl);
	}
	else
	{
		if (arg && (fwp->fi & fl_ha) && (cap = 1))
			put_hex_prfx(buf, sz, cap);
		fill_ze(buf, sz, df->wl);
	}
	stock = itoa_cap_hexa(arg, df->al);
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


void		idt_right_cap_hx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	fill_sp(buf, sz, df->wl);
	if (arg && (fwp->fi & fl_ha) && (cap = 1))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(arg, df->al);
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

void		idt_norml_cap_hx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if (arg && (fwp->fi & fl_ha) && (cap = 1))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(arg, df->al);
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
