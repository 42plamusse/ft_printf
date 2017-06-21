/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/21 13:17:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main()
{  
	int		i;

	printf("\noutput len function : %d\n", ft_printf("%p", &i));
	printf("\noutput len system   : %d\n", printf("%p", &i));
	//printf("\noutput len function : %d\n", ft_printf());
	//printf("\noutput len system   : %d\n", printf());
	//printf("%lo, %lo\n", 0, ULONG_MAX);
	//ft_printf("%lo, %lo\n", 0, ULONG_MAX);
	//printf("%lld\n", -9223372036854775808);
	//printf("\noutput len function : %d\n", ft_printf("%lu", "-42"));
	//printf("\noutput len system   : %d\n", printf("%lu", "-42"));
	return (0);
}

