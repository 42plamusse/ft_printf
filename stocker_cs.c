/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:42:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 13:38:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	stock_s(char *arg, char *buf, t_size *sz, t_fwp *fwp)
{
	int		len;
	int		dif;

	dif = fwp->wi - fwp->pr;
	if ((len = ft_strlen(arg)) && dif < len)
	{
		if (fwp->fi & fl_mi)
			idt_lefts(arg, len, sz, fwp, buf);
		else if (fwp->fi & fl_ze)
			idt_zeros(arg, len, sz, fwp, buf);
		else
			idt_rights(arg, len, sz, fwp, buf);
	}
	else
		idt_normls(arg, len, sz, fwp, buf);
}

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
	idt_normlc(arg, sz, buf);
}

//void	stock_S(wchar_t *arg, char *buf, t_size *sz, t_fwp *fwp)
//{
//	arg = 0;
//	buf = 0;
//	sz = 0;
//	fwp = 0;
//}
//
//void	stock_C(wchar_t arg, char *buf, t_size *sz, t_fwp *fwp)
//{
//	arg = 0;
//	buf = 0;
//	sz = 0;
//	fwp = 0;
//}
