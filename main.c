/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/20 15:31:04 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	ft_printf("%lld\n", -9223372036854775808);
	//printf("%lld\n", -9223372036854775808);
	//printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	//printf("\noutput len system   : %d\n", printf("%lu", "-42"));
	return (0);
}

