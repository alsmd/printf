/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:43:23 by flavio            #+#    #+#             */
/*   Updated: 2021/08/20 10:03:10 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_controller(t_assets *assets)
{
	if (assets->type == 'd')
		print_d(assets);
	if (assets->type == 'i')
		print_d(assets);
	if (assets->type == 'u')
		print_u(assets);
	if (assets->type == 'c')
		print_c(assets);
	if (assets->type == 's')
		print_s(assets);
	if (assets->type == 'x')
		print_x(assets);
	if (assets->type == 'X')
		print_x(assets);
	if (assets->type == 'p')
		print_p(assets);
	if (assets->type == '%')
		print_per(assets);
}
