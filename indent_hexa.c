/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:44:59 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 21:14:16 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		idt_lefthx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if ((fwp->fi & fl_ha) && !(cap = 0))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(ft_abs(arg), df->al);
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

void		idt_zerohx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if (df->pl)
	{
		fill_sp(buf, sz, df->wl);
		if ((fwp->fi & fl_ha) && !(cap = 0))
			put_hex_prfx(buf, sz, cap);
		fill_ze(buf, sz, df->pl);
	}
	else
	{
		if ((fwp->fi & fl_ha) && !(cap = 0))
			put_hex_prfx(buf, sz, cap);
		fill_ze(buf, sz, df->wl);
	}
	stock = itoa_hexa(ft_abs(arg), df->al);
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


void		idt_righthx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	fill_sp(buf, sz, df->wl);
	if ((fwp->fi & fl_ha) && !(cap = 0))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(ft_abs(arg), df->al);
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

void		idt_normlhx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;
	int		cap;

	if ((fwp->fi & fl_ha) && !(cap = 0))
		put_hex_prfx(buf, sz, cap);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(ft_abs(arg), df->al);
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
