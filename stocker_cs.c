/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:42:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 22:16:41 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		init_df_s(t_dif *df, char *arg, t_fwp *fwp)
{
	if (arg)
		df->al = ft_strlen(arg);
	else
		df->al = 0;
	if ((fwp->fi & fl_pr) && fwp->pr < df->al)
		df->pl = fwp->pr;
	else
		df->pl = df->al;
	df->wl = fwp->wi - df->pl;
	return (df->pl);
}

void	stock_s(char *arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;
	int		i;
	
	if (arg == NULL && !fwp->wi && putnull(buf, sz))
		return ;
	i = init_df_s(&df, arg, fwp);
	if (df.wl)
	{
		if ((fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(buf, sz, df.wl);
		else if (!(fwp->fi & fl_mi))
			fill_sp(buf, sz, df.wl);
		while (i--)
			fillbuffer(*arg++, sz, buf);
		if (fwp->fi & fl_mi)
			fill_sp(buf, sz, df.wl);
	}
	else
	{
		while (i--)
			fillbuffer(*arg++, sz, buf);
	}
}
//
//	if (df.wl > 0)
//	{
//		if (fwp->fi & fl_mi)
//			idt_lefts(arg, &df, sz, buf);
//		else if (fwp->fi & fl_ze)
//			idt_zeros(arg, &df, sz, buf);
//		else
//			idt_rights(arg, &df, sz, buf);
//	}
//	else
//		idt_normls(arg, &df, sz, buf);
//}

void	stock_c(unsigned char arg, char *buf, t_size *sz , t_fwp *fwp)
{
	if (fwp->wi)
	{
		if (fwp->fi & fl_mi)
			idt_leftc(arg, sz, fwp, buf);
		else if (fwp->fi & fl_ze)
			idt_zeroc(arg, sz, fwp, buf);
		else
			idt_rightc(arg, sz, fwp, buf);
	}
	else
	fillbuffer(arg, sz, buf);
}
