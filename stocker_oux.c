/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:19:48 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 17:33:57 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		stock_oux(ssize_t arg, char *buf, char c, t_size *sz, t_fwp *fwp)
{
	//if (c == 'o' || c == 'O')
	//	stock_oc(arg, buf, sz, fwp);
	//else if (c == 'u' || c == 'U')
		stock_us(arg, buf, sz, fwp);
	//else if (c == 'x')
	//	stock_hx(arg, buf, sz, fwp);
	//else if (c == 'X')
	//	stock_cap_hx(arg, buf, sz, fwp);
}
