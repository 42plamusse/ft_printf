/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 18:38:48 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_lefts(char *arg, t_dif *df, t_size *sz, char *buf)
{
	int		i;

	i = 0;
	while (i < df->pl)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	fill_sp(buf, sz, df->wl);
}


void		idt_zeros(char *arg, t_dif *df, t_size *sz, char *buf)
{
	int		i;

	fill_ze(buf, sz, df->wl);
	i = 0;
	while (i < df->pl)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		idt_rights(char *arg, t_dif *df, t_size *sz, char *buf)
{
	int		i;

	fill_sp(buf, sz, df->wl);
	i = 0;
	while (i < df->pl)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		idt_normls(char *arg, t_dif *df, t_size *sz, char *buf)
{
	int		i;

	i = 0;
	while (i < df->pl)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}
