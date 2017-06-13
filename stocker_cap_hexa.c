/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_cap_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 20:59:39 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		arglen_cap_hx(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 16;
	return (len);
}

void		init_df_cap_hx(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;
	int		pref;

	if (!(pref = 0) && (fwp->fi & fl_ha))
		pref = 2;
	df->al = arglen_cap_hx(arg) + pref;
	if (fwp->pr > df->al && (totlen = fwp->pr))
		df->pl = fwp->pr - df->al;
	else if ((totlen = df->al))
		df->pl = 0;
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_cap_hx(size_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_cap_hx(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_left_cap_hx(arg, &df, sz, fwp, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zero_cap_hx(arg, &df, sz, fwp, buf);
		else
			idt_right_cap_hx(arg, &df, sz, fwp, buf);
	}
	else
		idt_norml_cap_hx(arg, &df, sz, fwp, buf);
}
