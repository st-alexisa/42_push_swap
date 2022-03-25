/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:18:54 by skathale          #+#    #+#             */
/*   Updated: 2022/03/21 18:18:56 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_processing.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (p && *p && *p != (unsigned char)c)
		p++;
	if (!p || *p != (unsigned char)c)
		return ((char *)0);
	return ((char *)p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize >= 1)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n <= 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
