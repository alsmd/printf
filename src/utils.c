/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:55:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/21 09:32:02 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	reset_assets(t_assets *assets)
{
	assets->less_flag = 0;
	assets->zero_flag = 0;
	assets->plus_flag = 0;
	assets->space_flag = 0;
	assets->hash_flag = 0;
	assets->is_negative = 0;
	assets->precision = 0;
	assets->size = 0;
	assets->width = 0;
	assets->type = 0;
}

int	get_hexa_size(t_hexa number)
{
	int	size;

	size = 0;
	while (number)
	{
		number = number / 16;
		size++;
	}
	return (size);
}

char	*hexa_to_string(t_hexa number, t_assets *assets)
{
	char	*buffer;
	char	*hexa;
	int		size;
	int		digit;

	if (assets->type == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	size = get_hexa_size(number);
	buffer = ft_calloc(size + 1, sizeof(char));
	while (size-- > 0)
	{
		digit = number % 16;
		number = number / 16;
		buffer[size] = hexa[digit];
	}
	return (buffer);
}
