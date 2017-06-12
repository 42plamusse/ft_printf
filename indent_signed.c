/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 10:48:57 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/12 15:48:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		idt_normlsi(ssize_t arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		dif;
	char	*stock;

	if ((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne) && len--)
		putsign(sz, fwp, buf);
	if (fwp->pr > len && (dif = fwp->pr - len))
		fill_ze(buf, sz, dif);
	stock = ft_itoa(ft_abs(arg));
	while (stock[i])
	{
		if (sz->no < BS)
			buf[sz->no++] = stock[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
	free(stock);
}
