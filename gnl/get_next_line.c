/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:30:46 by skathale          #+#    #+#             */
/*   Updated: 2021/10/28 12:30:47 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check_reminder(char **rem, char **line)
{
	char	*p_n;
	char	*temp;

	if (!*rem)
	{
		*line = malloc(1);
		if (*line)
			(*line)[0] = '\0';
		return (NULL);
	}
	p_n = ft_strchr(*rem, '\n');
	temp = *rem;
	if (p_n)
	{
		*rem = ft_strdup(p_n + 1);
		*(p_n + 1) = '\0';
	}
	else
		*rem = NULL;
	*line = ft_strdup(temp);
	free(temp);
	return (p_n);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*p_n;
	static char	*rem;
	int			rd;
	char		*line;

	p_n = ft_check_reminder(&rem, &line);
	while (!p_n)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		p_n = ft_strchr(buffer, '\n');
		if (p_n)
		{
			rem = ft_strdup(p_n + 1);
			*(p_n + 1) = '\0';
		}
		line = ft_strjoin(line, buffer);
	}
	if (rd > 0 || (line && ft_strlen(line) != 0) || rem)
		return (line);
	free(line);
	return (NULL);
}
