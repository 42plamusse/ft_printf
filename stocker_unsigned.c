/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:07:01 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 17:51:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		arglen_us(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 10;
	return (len);
}

void		init_df_us(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;

	df->al = arglen_us(arg);
	if (fwp->pr > df->al && (totlen = fwp->pr))
		df->pl = fwp->pr - df->al;
	else if ((totlen = df->al))
		df->pl = 0;
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_us(size_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_us(&df, arg, fwp);
	if (df.wl)
	{
		if (fwp->fi & fl_mi)
			idt_leftus(arg, &df, sz, fwp, buf);
		else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
			idt_zerous(arg, &df, sz, fwp, buf);
		else
			idt_rightus(arg, &df, sz, fwp, buf);
	}
	else
		idt_normlus(arg, &df, sz, fwp, buf);
}
