/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:39:28 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 21:11:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_leftus(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_unsigned(arg, df->al);
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

void		idt_zerous(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_sp(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	else
		fill_ze(buf, sz, df->wl);
	stock = itoa_unsigned(arg, df->al);
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


void		idt_rightus(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	fill_sp(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_unsigned(arg, df->al);
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

void		idt_normlus(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_unsigned(arg, df->al);
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
