/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_cap_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:45:20 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 19:05:36 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		idt_left_cap_hx(size_t arg, t_dif *df, t_size *sz, t_fwp *fwp, char *buf)
{
	char	*stock;
	int		i;

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(ft_abs(arg), df->al);
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

	if (df->pl)
		fill_sp(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	else
		fill_ze(buf, sz, df->wl);
	stock = itoa_cap_hexa(ft_abs(arg), df->al);
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

	fill_sp(buf, sz, df->wl);
	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(ft_abs(arg), df->al);
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

	if (df->pl)
		fill_ze(buf, sz, df->pl);
	stock = itoa_cap_hexa(ft_abs(arg), df->al);
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
