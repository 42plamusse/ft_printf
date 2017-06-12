/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:02:15 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/12 15:28:58 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_ze(char *buf, t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		if (sz->no < BS)
		{
			buf[sz->no++] = '0';
			i++;
		}
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}

void		fill_sp(char *buf, t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		if (sz->no < BS)
		{
			buf[sz->no++] = ' ';
			i++;
		}
		else if ((sz->op += sz->no) && !(sz->no = 0))
			write(1, buf, BS);
	}
}
