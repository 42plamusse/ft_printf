/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/26 22:44:24 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

int		main()
{  
	char* l = setlocale(LC_ALL, ""); 

	if (l == NULL) 
		    printf("Locale not set\n"); 
	else
		    printf("Locale set to %s\n", l);
	printf("\noutput len function : %d\n", ft_printf("%lX, %lX", 0, ULONG_MAX));
	printf("\noutput len system   : %d\n", printf("%lX, %lX", 0, ULONG_MAX));
	printf("\noutput len function : %d\n", ft_printf("%llx, %llx", 0, ULLONG_MAX));
	printf("\noutput len system   : %d\n", printf("%llx, %llx", 0, ULLONG_MAX));
	//printf("|%-10C|\n", 10000);
	//ft_printf("|%-10C|\n", 10000);
	//printf("%jx, %jx\n", 0, ULLONG_MAX);
	//ft_printf("%jx, %jx\n", 0, ULLONG_MAX);
	//printf("%llx, %llx\n", 0, ULLONG_MAX);
	//ft_printf("%llx, %llx\n", 0, ULLONG_MAX);
	//printf("%lX\n", ULONG_MAX);
	//ft_printf("%lX\n", ULONG_MAX);
	//printf("\noutput len function : %d\n", ft_printf("%C\n", L'α'));
	//printf("\noutput len system   : %d\n", printf("%C\n", L'α'));
	//printf("\noutput len function : %d\n", ft_printf());
	//printf("\noutput len system   : %d\n", printf());
	//printf("%lo, %lo\n", 0, ULONG_MAX);
	//ft_printf("%lo, %lo\n", 0, ULONG_MAX);
	return (0);
}

