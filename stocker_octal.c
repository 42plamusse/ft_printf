/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:11:12 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 19:51:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		arglen_oc(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 8;
	return (len);
}

void		init_df_oc(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;
	int		pref;

	totlen = 0;
	if (!(pref = 0) && (fwp->fi & fl_ha))
		pref = 1;
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0 + pref;
	else if (!arg)
		df->al = 1;
	else
		df->al = arglen_oc(arg) + pref;
	if (fwp->pr > df->al && (totlen = fwp->pr))
		df->pl = fwp->pr - df->al;
	else
	{
		totlen = df->al;
		df->pl = 0;
	}
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_oc(size_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_oc(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_leftoc(arg, &df, sz, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zerooc(arg, &df, sz, buf);
		else
			idt_rightoc(arg, &df, sz, buf);
	}
	else
		idt_normloc(arg, &df, sz, buf);
}
