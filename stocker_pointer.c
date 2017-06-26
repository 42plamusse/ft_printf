/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:07:37 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 20:03:48 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		arglen_pt(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 16;
	return (len);
}

void		init_df_pt(t_dif *df, void *arg, t_fwp *fwp)
{
	int		totlen;

	df->cp = 2;
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0;
	else
		df->al = arglen_pt((size_t)arg);
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

int			stock_pt(void *arg, char *buf, char c, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_pt(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_leftpt(arg, &df, sz, c, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zeropt(arg, &df, sz, c, buf);
		else
			idt_rightpt(arg, &df, sz, c, buf);
	}
	else
		idt_normlpt(arg, &df, sz, c, buf);
	return (1);
}
