/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:13:35 by flavio            #+#    #+#             */
/*   Updated: 2021/08/18 20:48:56 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	get_size(unsigned int n)
{
	size_t	index;

	index = 0;
	while (n)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

static char	*set_string(unsigned int n, size_t size)
{
	char	*string;

	string = (char *) ft_calloc(size + 1, sizeof(char));
	if (!string)
		return (0);
	while (size > 0)
	{
		string[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	return (string);
}

char	*ft_itoa(unsigned int n)
{
	size_t			size;

	size = get_size(n);
	if (n == 0)
		size = 1;
	return (set_string(n, size));
}
