/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:30:09 by skathale          #+#    #+#             */
/*   Updated: 2022/03/07 17:30:10 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	put_char(char c)
{
	return ((int) write(1, &c, 1));
}

int	put_str(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ((int) write(1, "(null)", 6));
	while (s[i])
		i++;
	return ((int) write(1, s, i));
}

void	put_str_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
