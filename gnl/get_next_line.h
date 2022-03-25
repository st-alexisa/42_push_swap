/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:31:15 by skathale          #+#    #+#             */
/*   Updated: 2021/10/28 12:31:16 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# include <stdlib.h>
# include <unistd.h>
# include "../io_processing/io_processing.h"

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
