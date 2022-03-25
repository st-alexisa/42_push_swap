/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:44:52 by skathale          #+#    #+#             */
/*   Updated: 2021/10/28 12:44:53 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		res_size;
	char	*res;
	char	*temp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)s1;
	res_size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * res_size + 1);
	if (!res)
		return (res);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	free(temp);
	return (res);
}

char	*ft_strdup(char *str)
{
	size_t	size;
	char	*res;
	size_t	i;

	size = ft_strlen(str);
	res = malloc(size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
