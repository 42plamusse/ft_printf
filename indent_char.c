/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:56:35 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/09 16:00:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void		idt_leftc(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}
//void		idt_zeroc(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}
//void		idt_rightc(char *arg, int len, t_size *sz, t_fwp *fwp, char *buf)
//{
//}

void		idt_normlc(char arg, t_size *sz, char *buf)
{
	if ((sz->op += sz->no) && !(sz->no = 0))
		write(1, buf, BS);
	buf[sz->no++] = arg;
}
