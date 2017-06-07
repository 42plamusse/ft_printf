/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:51:44 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/07 19:14:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
	printf("output lenght perso  : %d\n", ft_printf("Hello%% World\n"));
	//printf("output lenght system : %d\n", printf("%%%s", "Hello World\n"));
	return (0);
}
