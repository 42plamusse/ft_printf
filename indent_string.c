/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/09 16:00:38 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void		idt_lefts(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}
//void		idt_zeros(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}
//void		idt_rights(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}
void		idt_normls(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
{
	int		i;

	if ((fwp->pr && fwp->pr > len) || !(fwp->pr))
		fwp->pr = len;
	i = 0;
	while (i < fwp->pr)
	{
		if (sz->no < BS)
			buf[sz->no++] = arg[i++];
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}
