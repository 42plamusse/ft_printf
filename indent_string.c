/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/11 22:05:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_lefts(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		i;
	int		nsp;

	if ((fwp->pr && fwp->pr > len) || !(fwp->pr))
		fwp->pr = len;
	nsp = fwp->wi - fwp->pr;
	i = 0;
	while (i < fwp->pr)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	fill_sp(buf, sz, nsp);
}


void		idt_zeros(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		i;
	int		nsp;

	if ((fwp->pr && fwp->pr > len) || !(fwp->pr))
		fwp->pr = len;
	nsp = fwp->wi - fwp->pr;
	fill_ze(buf, sz, nsp);
	i = 0;
	while (i < fwp->pr)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		idt_rights(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		i;
	int		nsp;

	if ((fwp->pr && fwp->pr > len) || !(fwp->pr))
		fwp->pr = len;
	nsp = fwp->wi - fwp->pr;
	fill_sp(buf, sz, nsp);
	i = 0;
	while (i < fwp->pr)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		idt_normls(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		i;

	if ((fwp->pr && fwp->pr > len) || !(fwp->pr))
		fwp->pr = len;
	i = 0;
	while (i < fwp->pr)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}
