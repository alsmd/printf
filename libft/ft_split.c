/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:27 by flavio            #+#    #+#             */
/*   Updated: 2021/08/04 09:05:20 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_size(char *s, char c)
{
	size_t		size;
	short int	str_found;

	str_found = 0;
	size = 0;
	if (!s[0])
		return (0);
	while (1)
	{
		if ((*s == c || *s == '\0') && str_found)
		{
			size++;
			str_found = 0;
		}
		else if (*s != c)
			str_found = 1;
		if (*s == '\0')
			break ;
		s++;
	}
	return (size);
}

static size_t	get_length(char *s, char c)
{
	size_t		index;

	index = 0;
	while (*s && *s != c)
	{
		index++;
		s++;
	}
	return (index);
}

static void	malloc_error(char **array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if (array[index])
			free(array[index]);
		index++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	index;
	char	**array;

	index = 0;
	if (!s)
		return (0);
	size = get_size((char *)s, c);
	array = (char **) ft_calloc(size + 1, sizeof(char *));
	if (!array)
		return (0);
	while (size--)
	{
		while (*s == c)
			s++;
		array[index] = ft_substr((char *)s, 0, get_length((char *)s, c));
		if (!array[index])
		{
			malloc_error(array, index);
			return (0);
		}
		s += get_length((char *)s, c);
		index++;
	}
	return (array);
}
