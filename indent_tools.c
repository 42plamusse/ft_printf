/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:02:15 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 14:11:05 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_ze(char *buf, t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		if (sz->no < BS)
		{
			buf[sz->no++] = '0';
			i++;
		}
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		fill_sp(char *buf, t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		if (sz->no < BS)
		{
			buf[sz->no++] = ' ';
			i++;
		}
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		putsign(t_size *sz, t_fwp *fwp, char *buf)
{
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	if (fwp->fi & fl_ne)
		buf[sz->no++] = '-';
	else if (fwp->fi & fl_pl)
		buf[sz->no++] = '+';
	else if (fwp->fi & fl_sp)
		buf[sz->no++] = ' ';
}

