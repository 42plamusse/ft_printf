/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:05:59 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 17:34:04 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t		arglen_si(ssize_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 10;
	return (len);
}

void		init_df_si(t_dif *df, ssize_t arg, t_fwp *fwp)
{
	int		sign;
	int		totlen;

	df->al = arglen_si(arg);
	if (!(sign = 0) && ((arg < 0 && (fwp->fi |= fl_ne)) || (fwp->fi & fl_pl)
			|| (fwp->fi & fl_sp)))
		sign = 1;
	if (fwp->pr > df->al && (totlen = fwp->pr + sign))
		df->pl = fwp->pr - df->al;
	else if ((totlen = df->al + sign))
		df->pl = 0;
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_si(ssize_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_si(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_leftsi(arg, &df, sz, fwp, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zerosi(arg, &df, sz, fwp, buf);
		else
			idt_rightsi(arg, &df, sz, fwp, buf);
	}
	else
		idt_normlsi(arg, &df, sz, fwp, buf);
}
