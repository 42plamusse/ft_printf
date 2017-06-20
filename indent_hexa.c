/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:44:59 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 21:12:37 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_lefthx(size_t arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(arg, df->al, c);
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

void		idt_zerohx(size_t arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
	{
		fill_sp(buf, sz, df->wl);
		if (df->cp)
			put_hex_prfx(buf, sz, c);
		fill_ze(buf, sz, df->pl);
	}
	else
	{
		if (df->cp)
			put_hex_prfx(buf, sz, c);
		fill_ze(buf, sz, df->wl);
	}
	stock = itoa_hexa(arg, df->al, c);
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


void		idt_righthx(size_t arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	fill_sp(buf, sz, df->wl);
	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(arg, df->al, c);
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

void		idt_normlhx(size_t arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa(arg, df->al, c);
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
