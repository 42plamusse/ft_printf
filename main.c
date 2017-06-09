/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/09 17:46:50 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	//ft_printf("age : %02.2lld, classe : %6s\n");
	//printf("output lenght perso  : %d\n", ft_printf("Hello%% World\n"));
	printf("output lenght perso  : %d\n", ft_printf("age : %s\n", "42"));
	printf("output lenght system : %d\n", printf("age : %s\n", "42"));
	return (0);
}
