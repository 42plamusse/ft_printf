/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:01:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 21:11:09 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_si(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp)
{
	if ((fwp->fc & fl_z))
		stock_si((ssize_t)va_arg(valist, ssize_t), buf, sz, fwp);
	else if ((fwp->fc & fl_j))
		stock_si((intmax_t)va_arg(valist, intmax_t), buf, sz, fwp);
	else if ((fwp->fc & fl_ll))
		stock_si((long long)va_arg(valist, long long), buf, sz, fwp);
	else if (((fwp->fc & fl_l)) || c == 'D')
		stock_si((long)va_arg(valist, long), buf, sz, fwp);
	else if ((fwp->fc & fl_h))
		stock_si((short)va_arg(valist, int), buf, sz, fwp);
	else if ((fwp->fc & fl_hh))
		stock_si((signed char)va_arg(valist, int), buf, sz, fwp);
	else
		stock_si((int)va_arg(valist, int), buf, sz, fwp);
	return (CONV_SUCCEED);
}

int		conv_oux(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp)
{
	if ((fwp->fc & fl_z))
		stock_oux((size_t)va_arg(valist, size_t), buf, c, sz, fwp);
	else if ((fwp->fc & fl_j))
		stock_oux((uintmax_t)va_arg(valist, uintmax_t), buf, c, sz, fwp);
	else if ((fwp->fc & fl_ll))
		stock_oux((unsigned long long)va_arg(valist, unsigned long long)
				, buf, c, sz, fwp);
	else if (((fwp->fc & fl_l)) || ft_strchr("OU", c))
		stock_oux((unsigned long)va_arg(valist, unsigned long)
				, buf, c, sz, fwp);
	else if ((fwp->fc & fl_h))
		stock_oux((unsigned short)va_arg(valist, unsigned int)
				, buf, c, sz, fwp);
	else if ((fwp->fc & fl_hh))
		stock_oux((unsigned char)va_arg(valist, unsigned int)
				, buf, c, sz, fwp);
	else
		stock_oux(va_arg(valist, unsigned int), buf, c, sz, fwp);
	return (CONV_SUCCEED);
}

int		conv_cs(va_list valist, char *buf, t_size *sz, char c, t_fwp *fwp)
{
	if (ft_strchr("sS", c))
	{
		if (c == 'S' || (fwp->fc & fl_l))
		{
			return (1);
		//	stock_S(va_arg(valist, wchar_t*), buf, sz, fwp);
		}
		else
			stock_s(va_arg(valist, char*), buf, sz, fwp);
	}
	else
	{
		if (c == 'C' || (fwp->fc & fl_l))
		{
			return (1);
		//	stock_C(va_arg(valist, wchar_t), buf, sz, fwp);
		}
		else
			stock_c(va_arg(valist, int), buf, sz, fwp);
	}
	return (CONV_SUCCEED);
}
