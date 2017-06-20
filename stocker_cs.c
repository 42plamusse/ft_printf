/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:42:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/19 20:24:46 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	init_df_s(t_dif *df, char *arg, t_fwp *fwp)
{
	df->al = ft_strlen(arg);
	if (fwp->pr && df->al)
		df->pl = fwp->pr;
	else
		df->pl = df->al;
	df->wl = fwp->wi - df->pl;
}

int		putnull(char *buf, t_size *sz)
{
	char	ret[6];
	int		i;

	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'u';
	ret[3] = 'l';
	ret[4] = 'l';
	ret[5] = ')';
	i = 0;
	while (i < 6)
	{
		if (sz->no < BS)
			buf[sz->no++] = ret[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	return (1);
}
	
void	stock_s(char *arg, char *buf, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	if (arg == NULL && putnull(buf, sz))
		return ;
	init_df_s(&df, arg, fwp);
	if (df.wl > 0)
	{
		if (fwp->fi & fl_mi)
			idt_lefts(arg, &df, sz, buf);
		else if (fwp->fi & fl_ze)
			idt_zeros(arg, &df, sz, buf);
		else
			idt_rights(arg, &df, sz, buf);
	}
	else
		idt_normls(arg, &df, sz, buf);
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
