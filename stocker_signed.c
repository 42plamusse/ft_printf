/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:05:59 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/12 15:49:25 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_si(ssize_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	int		len;
	int		tlen;
	int		sign;

	if (!(sign = 0) && ((arg < 0 && (fwp->fi | fl_ne)) || (fwp->fi & fl_pl)
			|| (fwp->fi & fl_sp)))
		sign = 1;
	if (fwp->pr > (len = ft_intlen(ft_abs(arg)) + sign))
		tlen = fwp->pr + sign;
	else
		tlen = len;
	//if (fwp->wi > tlen)
	//{
	//	if (fwp->fi & fl_mi)
	//		idt_leftsi(arg, len, sz, fwp, buf);
	//	else if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze))
	//		idt_zerosi(arg, len, sz, fwp, buf);
	//	else
	//		idt_rightsi(arg, len, sz, fwp, buf);
	//}
	//else
		idt_normlsi(arg, len, sz, fwp, buf);
}
