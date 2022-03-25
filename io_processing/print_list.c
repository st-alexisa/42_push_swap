/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:08:04 by skathale          #+#    #+#             */
/*   Updated: 2022/03/11 15:08:07 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_processing.h"

void	print_list(t_list *list)
{
	size_t	i;
	t_node	*p;

	i = 0;
	p = list->tail;
	while (i < list->size)
	{
		put_nbr(p->data);
		put_char('\n');
		p = p->prev;
		i++;
	}
	put_str("--\n");
}

void	print_list_indexes(t_list *list)
{
	size_t	i;
	t_node	*p;

	i = 0;
	p = list->tail;
	while (i < list->size)
	{
		put_nbr(p->index);
		put_char('\n');
		p = p->prev;
		i++;
	}
	put_str("--\n");
}
