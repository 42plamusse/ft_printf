/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/19 20:26:29 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("output len function : %d\n", ft_printf("% Zoooo\n"));
	printf("output len system   : %d\n",  printf("% Zoooo\n"));
	return (0);
}

