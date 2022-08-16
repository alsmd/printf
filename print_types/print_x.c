/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:47:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 17:12:08 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_format(t_assets *assets, char *buffer, int number)
{
	print_left(assets, 1);
	if (assets->hash_flag && number != 0)
	{
		if (assets->type == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		assets->wrote += 2;
	}
	print_left(assets, 0);
	print_precision(assets);
	ft_putstr_fd(buffer, 1);
	print_right(assets);
}

static void	desabilite_flags(t_assets *assets)
{
	assets->space_flag = 0;
	assets->plus_flag = 0;
}

void	print_x(t_assets *assets)
{
	char	*buffer;
	t_hexa	number;
	int		d;

	number = va_arg(assets->ptr, unsigned int);
	if (number == 0)
	{
		if (assets->precision)
			buffer = ft_strdup("");
		else
			buffer = ft_strdup("0");
	}
	else
		buffer = hexa_to_string(number, assets);
	d = number;
	if (d < 0)
		d = 1;
	assets->wrote += ft_strlen(buffer);
	desabilite_flags(assets);
	set_sizes(assets, buffer, d);
	print_format(assets, buffer, d);
	free(buffer);
}
