/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:43:55 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 21:48:09 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*flags(char	*string, t_assets *assets)
{
	while (ft_strchr(FLAGS, *string))
	{
		if (*string == '#')
			assets->hash_flag = 1;
		if (*string == '-')
			assets->less_flag = 1;
		if (*string == ' ')
			assets->space_flag = 1;
		if (*string == '+')
			assets->plus_flag = 1;
		if (*string == '0')
			assets->zero_flag = 1;
		string += 1;
	}
	return (string);
}

static char	*size(char	*string, t_assets *assets)
{
	if (*string == '.')
	{
		assets->precision = 1;
		string++;
		while (ft_isdigit(*string))
		{
			assets->size = (assets-> size * 10) +(*string - 48);
			string++;
		}
	}
	return (string);
}

static char	*width(char	*string, t_assets *assets)
{
	while (ft_isdigit(*string))
	{
		assets->width = (assets->width * 10) + (*string - 48);
		string += 1;
	}
	return (string);
}

char	*store_info(t_assets *assets, const char *string)
{
	string = flags((char *)string, assets);
	string = width((char *)string, assets);
	string = size((char *)string, assets);
	assets->type = *string;
	return ((char *)string);
}
