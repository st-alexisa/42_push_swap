/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_processing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:32:09 by skathale          #+#    #+#             */
/*   Updated: 2022/03/07 17:32:10 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_PROCESSING_H
# define IO_PROCESSING_H
# include <unistd.h>
# include "../linked_list/linked_list.h"

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	print_list(t_list *list);
void	print_list_indexes(t_list *list);
int		int_try_parse(const char *str, int	*out);
int		try_parse_args(t_list *list, int argc, char **argv);
int		put_str(const char *s);
void	put_str_fd(char *s, int fd);
int		put_char(char c);
int		put_nbr(int nb);
#endif
