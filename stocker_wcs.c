/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_wcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/21 15:31:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_C(wchar_t arg, char *buf, t_size *sz, t_fwp *fwp)
{
	if (fwp->wi)
	{
		if (fwp->fi & fl_mi)
			idt_leftwc(arg, sz, fwp, buf);
		else if (fwp->fi & fl_ze)
			idt_zerowc(arg, sz, fwp, buf);
		else
			idt_rightwc(arg, sz, fwp, buf);
	}
	else
	idt_normlwc(arg, sz, buf);
}
