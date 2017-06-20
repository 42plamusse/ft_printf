/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:39:35 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 13:54:57 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		arglen_hx(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 16;
	return (len);
}

void		init_df_hx(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;

	if (!(df->cp = 0) && (fwp->fi & fl_ha) && arg)
		df->cp = 2;
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0;
	else
		df->al = arglen_hx(arg);
	if (fwp->pr > df->al)
		df->pl = fwp->pr - df->al;
	else
		df->pl = 0;
	totlen = df->al + df->pl + df->cp;
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_hx(size_t arg, char *buf, char c, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_hx(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_lefthx(arg, &df, sz, c, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zerohx(arg, &df, sz, c, buf);
		else
			idt_righthx(arg, &df, sz, c, buf);
	}
	else
		idt_normlhx(arg, &df, sz, c, buf);
}
