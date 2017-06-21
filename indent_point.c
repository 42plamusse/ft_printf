/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 13:01:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/21 13:12:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_leftpt(void *arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa((size_t)arg, df->al, c);
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

void		idt_zeropt(void *arg, t_dif *df, t_size *sz, char c, char *buf)
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
	stock = itoa_hexa((size_t)arg, df->al, c);
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


void		idt_rightpt(void *arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	fill_sp(buf, sz, df->wl);
	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa((size_t)arg, df->al, c);
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

void		idt_normlpt(void *arg, t_dif *df, t_size *sz, char c, char *buf)
{
	char	*stock;
	int		i;

	if (df->cp)
		put_hex_prfx(buf, sz, c);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_hexa((size_t)arg, df->al, c);
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
