/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 16:57:45 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_format(t_assets *assets, t_hexa number, char *buffer)
{
	print_left(assets, 1);
	print_sign(assets);
	if (assets->space_flag)
	{
		write(1, " ", 1);
		assets->wrote += 1;
	}
	if (assets->hash_flag)
	{
		write(1, "0x", 2);
		assets->wrote += 2;
	}
	print_left(assets, 0);
	if (number)
		print_precision(assets);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
}

static void	desabilite_flags(t_assets *assets)
{
	if (assets->plus_flag)
		assets->space_flag = 0;
	assets->hash_flag = 1;
}

void	print_p(t_assets *assets)
{
	char	*buffer;
	t_hexa	number;

	number = (t_hexa) va_arg(assets->ptr, void *);
	desabilite_flags(assets);
	if (number == 0)
	{
		buffer = ft_strdup("0");
		assets->plus_flag = 0;
		assets->space_flag = 0;
	}
	else
		buffer = hexa_to_string(number, assets);
	assets->wrote += ft_strlen(buffer);
	set_sizes(assets, buffer, 1);
	print_format(assets, number, buffer);
	free(buffer);
}
