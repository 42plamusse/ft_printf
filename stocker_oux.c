/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:19:48 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 21:11:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		stock_oux(size_t arg, char *buf, char c, t_size *sz, t_fwp *fwp)
{
	if (c == 'o' || c == 'O')
		stock_oc(arg, buf, sz, fwp);
	else if (c == 'u' || c == 'U')
		stock_us(arg, buf, sz, fwp);
	else if (c == 'x' || c == 'X')
		stock_hx(arg, buf, c, sz, fwp);
}
