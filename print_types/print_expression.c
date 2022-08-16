/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:43:46 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 08:32:12 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	set_sizes(t_assets *assets, char *buffer, int number)
{
	if (assets->size > 0 && assets->precision)
	{
		if (buffer[0] == '-')
			assets->size -= ft_strlen(buffer + 1);
		else
			assets->size -= ft_strlen(buffer);
	}
	if (assets->width > 0)
	{
		assets->width -= (ft_strlen(buffer));
		if (assets->size > 0 && assets->precision)
			assets->width -= assets->size;
		if (assets->plus_flag || assets->space_flag || number < 0)
			assets->width -= 1;
		if (assets->hash_flag && number != 0)
			assets->width -= 2;
	}
}

void	print_sign(t_assets *assets)
{
	if (assets->is_negative)
	{
		write(1, "-", 1);
		assets->wrote += 1;
	}
	if (assets->plus_flag)
	{
		write(1, "+", 1);
		assets->wrote += 1;
	}
}

void	print_left(t_assets *assets, int action)
{
	if (!assets->less_flag)
	{
		if ((assets->zero_flag && !assets->precision) && !action)
		{
			while (assets->width > 0)
			{
				write(1, "0", 1);
				assets->wrote += 1;
				assets->width--;
			}
		}
		else if ((!assets->zero_flag || assets->precision) && action)
		{
			while (assets->width > 0)
			{
				write(1, " ", 1);
				assets->wrote += 1;
				assets->width--;
			}
		}
	}
}

void	print_precision(t_assets *assets)
{
	while (assets->size > 0 && assets->precision)
	{
		write(1, "0", 1);
		assets->wrote += 1;
		assets->size--;
	}
}

void	print_right(t_assets *assets)
{
	if (assets->less_flag)
	{
		while (assets->width > 0)
		{
			write(1, " ", 1);
			assets->wrote += 1;
			assets->width--;
		}
	}
}
