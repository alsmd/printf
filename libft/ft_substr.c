/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:46:03 by flavio            #+#    #+#             */
/*   Updated: 2021/08/05 16:09:46 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	size;
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		size = 0;
	else
	{
		size = ft_strlen(&s[start]);
		if (len < size)
			size = len;
	}
	string = (char *) ft_calloc(size + 1, sizeof(char));
	if (!string)
		return (0);
	while (index < size)
	{
		string[index] = s[start + index];
		index++;
	}
	string[index] = '\0';
	return (string);
}
