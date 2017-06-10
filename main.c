/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/10 02:12:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	//ft_printf("age : %6.1s\n", "42");
	//ft_printf("age : %02.2lld, classe : %6s\n");
	//printf("output lenght perso  : %d\n", ft_printf("Hello%% World\n"));
	printf("output lenght perso  : %d\n", ft_printf("age : %012.1sk\n", "KENTIN LAI GENTI"));
	printf("output lenght system : %d\n", printf("age : %012.1sk\n", "KENTIN LAI GENTI"));
	return (0);
}
