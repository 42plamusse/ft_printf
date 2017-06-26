/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:35:00 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 16:24:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar(wchar_t arg, t_size *sz, char *buf)
{
	unsigned char	oct1;
	unsigned char	oct2;
	unsigned char	oct3;
	unsigned char	oct4;
	unsigned int	msk;
	unsigned int	tmp;

	oct1 = 0;
	oct2 = 0;
	oct3 = 0;
	oct4 = 0;
	tmp = (unsigned int)arg;
	if ((arg < 0 || arg > 0X10FFFF) && (sz->er = -1))
		return ;
	if (!(arg >> 7))
		fillbuffer((unsigned char)arg, sz, buf);
	else if (!(arg >> 11) && (msk = 49280))
	{
		oct2 = (tmp << 26) >> 26;
		oct1 = ((tmp >> 6) << 27) >> 27;
		fillbuffer((unsigned char)((msk >> 8) | oct1), sz, buf);
		fillbuffer((unsigned char)(((msk << 24) >> 24) | oct2), sz, buf);
	}
	else if (!(arg >> 16) && (msk = 14712960))
	{
		oct3 = (tmp << 26) >> 26;
		oct2 = ((tmp >> 6) << 26) >> 26;
		oct1 = ((tmp >> 12) << 28) >> 28;
		fillbuffer((unsigned char)((msk >> 16) | oct1), sz, buf);
		fillbuffer((unsigned char)(((msk << 16) >> 24) | oct2), sz, buf);
		fillbuffer((unsigned char)(((msk << 24) >> 24) | oct3), sz, buf);
	}
	else if ((msk = 4034953344))
	{
		oct4 = (tmp << 26) >> 26;
		oct3 = ((tmp >> 6) << 26) >> 26;
		oct2 = ((tmp >> 12) << 26) >> 26;
		oct1 = ((tmp >> 18) << 29) >> 29;
		fillbuffer((unsigned char)((msk >> 24) | oct1), sz, buf);
		fillbuffer((unsigned char)(((msk << 8) >> 24) | oct2), sz, buf);
		fillbuffer((unsigned char)(((msk << 16) >> 24) | oct3), sz, buf);
		fillbuffer((unsigned char)(((msk << 24) >> 24) | oct4), sz, buf);
	}
}
