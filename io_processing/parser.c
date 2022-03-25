/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:50:23 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 14:50:24 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_processing.h"

int	int_try_parse(const char *str, int	*out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
		return (0);
	*out = (int)res * sign;
	return (1);
}

int	try_parse_splitted_string(t_list *list, char **args)
{
	int	i;
	int	value;

	i = 0;
	while (args[i])
	{
		if (!int_try_parse(args[i], &value) || is_contains(list, value))
			return (0);
		list_add_front(list, create_node(value));
		free(args[i]);
		i++;
	}
	free(args);
	return (1);
}

int	try_parse_args(t_list *list, int argc, char **argv)
{
	int	value;
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!try_parse_splitted_string(list, ft_split(argv[i], ' ')))
				return (0);
		}
		else if (ft_strlen(argv[i]) > 0 && (!int_try_parse(argv[i], &value)
				|| is_contains(list, value)))
			return (0);
		else if (ft_strlen(argv[i]) > 0)
			list_add_front(list, create_node(value));
		i++;
	}
	list->med = list->size / 2;
	get_indexes(list);
	return (1);
}
