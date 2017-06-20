/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:16:15 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 21:11:41 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_leftoc(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_octa(ft_abs(arg), df->al);
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

void		idt_zerooc(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_sp(buf, sz, df->wl);
	else
		fill_ze(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_octa(ft_abs(arg), df->al);
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


void		idt_rightoc(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	fill_sp(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_octa(ft_abs(arg), df->al);
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

void		idt_normloc(size_t arg, t_dif *df, t_size *sz, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_octa(ft_abs(arg), df->al);
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
