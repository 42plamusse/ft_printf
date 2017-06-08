/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/08 16:52:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
	ft_printf("age : %#---++ 0243.23llzd, classe : %6s\n");
	//ft_printf("age : %02.2lld, classe : %6s\n");
	//printf("output lenght perso  : %d\n", ft_printf("Hello%% World\n"));
	//printf("output lenght perso  : %d\n", ft_printf("age : %#X\n"));
	//printf("output lenght system : %d\n", printf("%%%s", "Hello World\n"));
	return (0);
}
